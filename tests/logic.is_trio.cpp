#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/logic.h>
#include <tichu/card.h>

using namespace tichu;

TEST_CASE("is_trio", "[logic]")
{
   SECTION("with one cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
      };
      REQUIRE(is_trio(result) == false);
   }
   SECTION("with random two cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_trio(result) == false);
   }
   SECTION("with random three cards")
   {
      tichu::stash_t result = {
         card_t{ 5, color_t::jade },
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_trio(result) == false);
   }
   SECTION("is trio of two")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 2, color_t::sword },
      };
      REQUIRE(is_trio(result) == true);
   }
   SECTION("trio of King's (unsorted)")
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
      REQUIRE(is_trio(result) == true);
   }
}
