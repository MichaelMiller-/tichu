#pragma once

// disable warnings under windows (msvc compiler)
#ifdef WIN32
   #pragma warning(push)
   #pragma warning(disable: 4503)
#endif

#include <range/v3/all.hpp>

#ifdef WIN32
   #pragma warning(pop)
#endif

#include "tichu/card.h"
#include "tichu/view.h"
//! \todo: inline saves stack-space

namespace tichu {

   using points_t = int;
   
   constexpr points_t      points_to_win{ 1000 };
   constexpr std::uint8_t  great_tichu{ 8 };
   constexpr std::uint8_t  hand_cards{ 14 };

   inline constexpr auto is_overall_score_valid(points_t points) noexcept {
      return (points % 10) == 0;
   }

   inline constexpr auto has_won(points_t points) noexcept {
      return points >= points_to_win;
   }

   //! \brief check if there is at least one pair in a range of cards
   //! \param rng sorted range of cards
   template <typename Range>
   constexpr bool is_pair(Range && rng) noexcept {
      return ranges::distance(rng | view::by_card_value() | view::remove_less(2)) > 0;
   };
   
   //! \brief check if there is at least a "three of a kind" in a range of cards
   //! \param rng sorted range of cards
   //! \todo rename
   template <typename Range>
   constexpr bool is_trio(Range && rng) noexcept {
      return ranges::distance(rng | view::by_card_value() | view::remove_eq(3)) > 0;
   };

   //! \brief check if there is a "full house" in a range of cards
   //! \param rng sorted range of cards
   template <typename Range>
   constexpr bool is_full_house(Range && rng) noexcept {
      return is_pair(rng) && is_trio(rng) && ranges::distance(rng) >= 5;
   };
   
   //! \brief check if there is a "straight" in a range of cards
   //! \param rng sorted range of cards
   const auto is_straight = [](auto rng) noexcept {
      return ranges::distance(rng | view::remove_duplicates() | view::remove_non_continuios()) >= 5;
   };

   //! \todo function-name
   //! \brief return number of cards in the straight 
   //! \param rng sorted range of cards
   const auto straight_length = [](auto rng) noexcept {
      //! \todo check if rng is_straight or ignore this check
      return ranges::distance(rng | view::remove_duplicates() | view::remove_non_continuios());
   };

   const auto is_bomb = [](auto rng) noexcept 
   {
      return 
         (ranges::distance(rng | view::by_card_value() | view::remove_eq(4)) > 0) ||  // four of a kind
         (ranges::distance(rng | view::by_card_color() | ranges::view::remove_if([](auto cards) { return !is_straight(cards); })) > 0);
   };

   //! \brief check if there is a "continuios" in a range of cards
   //! \param rng sorted range of cards
   const auto is_continuios = [](auto rng) noexcept {
      // get all pairs in the sequence
      decltype(rng) pairs = rng | view::by_card_value() | view::remove_less(2) | ranges::action::join;
      // check if there at least 2 continuous
      return ranges::distance(pairs | view::remove_non_continuios()) >= 2;
   };

  //! \param rng sorted range of cards
   const auto continuios_length = [](auto rng) noexcept {
      // get all pairs in the sequence
      decltype(rng) pairs = rng | view::by_card_value() | view::remove_less(2) | ranges::action::join;
      // check if there at least 2 continuous
      return ranges::distance(pairs | view::remove_non_continuios());
   };


   //! \brief check if there is the Mahjong-Card in the range
   //! \param rng range of cards
   const auto has_mahjong = [](auto rng) noexcept {
      return ranges::distance(rng | ranges::view::remove_if([](auto card) { return card.value != Mahjong; })) == 1;
   };

   //! \brief check if
   //! \param rng sorted range of cards
	//const auto valid_combination = [](auto rng) noexcept {
	//   return true;
	//};

   enum class kind_t
   {
      single,
      pair,
      trio,
      continous,
      straight,
      fullHouse,
      bomb,
      straightBomb,
      invalid = -1
   };

   //! \brief check if
   //! \param rng sorted range of cards
   //! \return pair of kind and length; 
   // const auto kind = [&](auto rng) noexcept 
   // {
   //    if (is_bomb(rng) && is_straight(rng)) {

   //       // get the max ranges::distance from any range<card>
   //       //return std::make_pair(kind_t::straightBomb, straight_length(rng));
   //       return std::make_pair(kind_t::single, 1);
   //    }
   //    else if (is_bomb(rng))
   //       return std::make_pair(kind_t::bomb, 4);
   //    else if (is_straight(rng))
   //       return std::make_pair(kind_t::straight, straight_length(rng));
   //    else if (is_full_house(rng))
   //       return std::make_pair(kind_t::fullHouse, 5);
   //    else if (is_continuios(rng))
   //       return std::make_pair(kind_t::continous, continuios_length(rng));
   //    else if (is_trio(rng))
   //       return std::make_pair(kind_t::trio, 3);
   //    else if (is_pair(rng))
   //       return std::make_pair(kind_t::pair, 2);
   //    else if (ranges::distance(rng) == 1)
   //       return std::make_pair(kind_t::single, 1);
      
	//    return std::make_pair(kind_t::invalid, -1); // kind_t::invalid);
   // };
}
