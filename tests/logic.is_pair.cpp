#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/logic.h>
#include <tichu/card.h>

TEST_CASE("is_pair", "[logic]")
{
   using namespace tichu;

   SECTION("with one cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
      };
      REQUIRE(is_pair(result) == false);
   }
   SECTION("with random two cards")
   {
      tichu::stash_t result = {
         card_t{ K, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_pair(result) == false);
   }
   SECTION("is pair of five's")
   {
      tichu::stash_t result = {
         card_t{ 5, color_t::jade },
         card_t{ 5, color_t::pagoda },
      };
      REQUIRE(is_pair(result) == true);
   }
   SECTION("is pair of two's and a single three card")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 3, color_t::sword },
      };
      REQUIRE(is_pair(result) == true);
   }
   SECTION("trio of two's")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 2, color_t::star },
         card_t{ 3, color_t::sword },
         card_t{ 4, color_t::sword },
         card_t{ 5, color_t::sword },
         card_t{ 6, color_t::sword },
      };
      REQUIRE(is_pair(result) == true);
   }
   SECTION("trio of King's")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::sword },
         card_t{ 4, color_t::jade },
         card_t{ 5, color_t::jade },
         card_t{ K, color_t::pagoda },
         card_t{ K, color_t::jade },
         card_t{ K, color_t::star },
         card_t{ A, color_t::star },
      };
      REQUIRE(is_pair(result) == true);
   }
}
