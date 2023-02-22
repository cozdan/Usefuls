#include "request_queue.h"

RequestQueue::RequestQueue(const SearchServer& search_server)
    : inner_server_(search_server),
    current_time_(0),
    empties_(0)
{
}

std::vector<Document> RequestQueue::AddFindRequest(const std::string& raw_query, DocumentStatus status) {
    const auto result = inner_server_.FindTopDocuments(raw_query, status);
    AddRequest(static_cast<int>(result.size()));
    return result;
}
std::vector<Document> RequestQueue::AddFindRequest(const std::string& raw_query) {
    const auto result = inner_server_.FindTopDocuments(raw_query);
    AddRequest(static_cast<int>(result.size()));
    return result;
}
int RequestQueue::GetNoResultRequests() const {
    return empties_;
}

void RequestQueue::AddRequest(int results) {
    ++current_time_;
    while (!requests_.empty() && min_in_day_ <= current_time_ - requests_.front().timestamp) {
        if (requests_.front().results == 0) {
            --empties_;
        }
        requests_.pop_front();
    }
    if (results == 0) {
        ++empties_;
    }
    requests_.push_back({ current_time_, results });
}