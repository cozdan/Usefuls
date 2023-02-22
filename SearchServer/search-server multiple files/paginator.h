#pragma once

template <typename Iterator>
struct IteratorRange {

    IteratorRange(Iterator start, Iterator fin)
        : begin_(start), end_(fin)
    {
    }
    auto begin() {
        return begin_;
    }
    auto end() {
        return end_;
    }
    size_t size_() {
        return distance(end_, begin_);
    }
    Iterator begin_;
    Iterator end_;
};

template <typename Iterator>
class Paginator {
public:
    Paginator(const Iterator& results_start, const Iterator& results_fin, size_t page_size) {
        for (auto page_start = results_start; page_start != results_fin; advance(page_start, page_size)) {
            if (static_cast<size_t>(distance(page_start, results_fin)) >= page_size) {
                auto page_end = page_start + page_size;
                pages_.push_back({ page_start, page_end });
            }
            else {
                pages_.push_back({ page_start, results_fin });
                break;
            }
        }
    }
    auto begin() const {
        return pages_.begin();
    }
    auto end() const {
        return pages_.end();
    }
    size_t size() {
        return distance(pages_.end(), pages_.begin());
    }

private:
    std::vector<IteratorRange<Iterator>> pages_;
};

template <typename Iterator>
std::ostream& operator<<(std::ostream& out, IteratorRange<Iterator> IR) {
    for (auto& i : IR) {
        out << i;
    }

    return out;
}

template <typename Container>
auto Paginate(const Container& c, size_t page_size) {
    return Paginator(begin(c), end(c), page_size);
}