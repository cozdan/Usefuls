#pragma once
#include "search_server.h"
#include <vector>
#include <string>
#include <deque>

class RequestQueue {
public:
    explicit RequestQueue(const SearchServer& search_server);

    template <typename DocumentPredicate>
    std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentPredicate document_predicate); 

    std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentStatus status);

    std::vector<Document> AddFindRequest(const std::string& raw_query);

    int GetNoResultRequests() const;

private:
    struct QueryResult {
        uint64_t timestamp;
        int results;
    };
    const SearchServer& inner_server_;
    std::deque<QueryResult> requests_;
    uint64_t current_time_;
    const static int min_in_day_ = 1440;
    int empties_;

    void AddRequest(int results);
};

template <typename DocumentPredicate>
std::vector<Document> AddFindRequest(const std::string& raw_query, DocumentPredicate document_predicate) {
    const auto result = RequestQueue::inner_server_.FindTopDocuments(raw_query, document_predicate);
    AddRequest(result.size());
    return result;
}