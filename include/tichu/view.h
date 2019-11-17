#pragma once

// disable warnings under windows (msvc compiler)
#ifdef WIN32
#pragma warning(push)
#pragma warning(disable : 4503)
#endif

#include <range/v3/all.hpp>

#ifdef WIN32
#pragma warning(pop)
#endif

#include <tichu/card.h>

namespace tichu::view
{

//! \brief group cards by value
inline auto by_card_value() noexcept
{
   return ranges::view::group_by([](card_t a, card_t b) { return a.value == b.value; });
}

//! \brief group cards by color
inline auto by_card_color() noexcept
{
   return ranges::view::group_by([](card_t a, card_t b) { return a.color == b.color; });
}

//! \brief remove than N cards from range
inline auto remove_eq(int n) noexcept
{
   return ranges::view::remove_if([n](/*Range<card>*/ auto cards) { return ranges::distance(cards) != n; });
}

//! \brief remove less than N cards from a range of cards
inline auto remove_less(int n) noexcept
{
   return ranges::view::remove_if([n](/*Range<card>*/ auto cards) { return ranges::distance(cards) < n; });
}

template <size_t N>
constexpr auto remove_less() noexcept
{
   return ranges::view::remove_if([](/*Range<card>*/ auto cards) { return ranges::distance(cards) < N; });
}

//! \brief
inline auto remove_special_cards() noexcept
{
   return ranges::view::remove_if([](auto c) { return c.color == color_t::special; });
}

//! \todo only works with a sorted range
inline auto remove_duplicates() noexcept
{
   return ranges::view::adjacent_remove_if([](auto c1, auto c2) { return c1.value == c2.value; });
}

//! \todo rename continuous
inline auto remove_non_continuios() noexcept
{
   return ranges::view::adjacent_remove_if([](auto c1, auto c2) {
      return (c2.value - c1.value) != 1;
   });
}

//! \todo only works with a sorted range
inline auto remove_continuios() noexcept
{
   return ranges::view::adjacent_remove_if([](auto c1, auto c2) {
      return (c2.value - c1.value) == 1;
   });
}
} // namespace tichu::view
