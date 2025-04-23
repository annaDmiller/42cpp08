template <typename T>
typename T::iterator easyfind(T& container, int num)
{
    typename T::iterator ret = std::find(container.begin(), container.end(), num);

    if (ret == container.end())
        throw ValueNotFoundException();
    return (ret);
}