//
// File:   tuple_ops.cpp
// Author: <Your Glorious Instructor>
// Purpose:
// Demo building a list structure using C++ tuples.
//
// Reference: https://gist.github.com/mattbierner/6145505
//
//    Function list operations for std::tuple.
//
//    Operations are performed on tuple values. Unless noted, these operations
//    result in regular flat tuples and not recursive data structures.

// Implementation helper data and functions
template<std::size_t... XS>
struct Seq
{
    template<std::size_t X>
    using cons = Seq<X, XS...>;
};

template<std::size_t start, std::size_t end>
struct Range
{
    static_assert(start < end, "Range: start > end");
    typedef
        typename Range<start + 1, end>::type::template cons<start>
        type;
};

template<std::size_t start>
struct Range<start, start>
{
    typedef Seq<> type;
};

template<typename T, std::size_t... N>
std::tuple<typename std::tuple_element<N, T>::type...> Select(const T& t, Seq<N...>)
{
    return std::make_tuple(std::get<N>(t)...);
}

//
//
// Empty list.
//
constexpr const std::tuple<> empty;

//
// Get the first element of a tuple.
//
// Not valid for empty tuples.
//
template<typename T>
typename std::tuple_element<0, T>::type Head(const T& t)
{
    return std::get<0>(t);
}

//
// Not valid for empty tuples.
//
template<typename T,
    typename R = typename Range<1, std::tuple_size<T>::value>::type>
auto Tail(const T& t) -> decltype(Select(t, R()))
{
    return Select(t, R());
}

//
//  Create a new tuple from a head value and existing tuple.
//
template<typename X, typename... XS>
std::tuple<X, XS...> Combine(X x, const std::tuple<XS...>& t)
{
    return std::tuple_cat(std::make_tuple(x), t);
}