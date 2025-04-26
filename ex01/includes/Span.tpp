template <typename Iter> void Span::addMultNumbers(Iter first, Iter last)
{
    if (this->_numbers.size() + std::distance(first, last) > this->_size)
        throw NotEnoughPlaceScopeInsertException();
    else
        this->_numbers.insert(this->_numbers.end(), first, last);
    return ;
}