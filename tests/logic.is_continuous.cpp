#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/logic.h>
#include <tichu/card.h>

TEST_CASE("is_continuios", "[logic]")
{
   using namespace tichu;

   SECTION("with one cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
      };
      REQUIRE(is_continuios(result) == false);
   }
   SECTION("with random two cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_continuios(result) == false);
   }
   SECTION("with random three cards")
   {
      tichu::stash_t result = {
         card_t{ 5, color_t::jade },
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_continuios(result) == false);
   }
   SECTION("straight up to A")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 7, color_t::pagoda },
         card_t{ 10, color_t::pagoda },
         card_t{ J, color_t::pagoda },
         card_t{ Q, color_t::pagoda },
         card_t{ K, color_t::pagoda },
         card_t{ A, color_t::pagoda },
      };
      REQUIRE(is_continuios(result) == false);
   }
   SECTION("continuios 10 and Jack's")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 10, color_t::jade },
         card_t{ 10, color_t::pagoda },
         card_t{ J, color_t::pagoda },
         card_t{ J, color_t::jade },
         card_t{ A, color_t::pagoda },
      };
      REQUIRE(is_continuios(result) == true);
   }
   SECTION("two pairs")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 10, color_t::jade },
         card_t{ 10, color_t::pagoda },
         card_t{ Q, color_t::pagoda },
         card_t{ Q, color_t::jade },
         card_t{ A, color_t::pagoda },
      };
      REQUIRE(is_continuios(result) == false);
   }
   SECTION("full house")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 10, color_t::jade },
         card_t{ 10, color_t::pagoda },
         card_t{ Q, color_t::pagoda },
         card_t{ Q, color_t::jade },
         card_t{ Q, color_t::sword },
      };
      REQUIRE(is_continuios(result) == false);
   }
   SECTION("continuios 10 and bomb of Jack's")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 10, color_t::jade },
         card_t{ 10, color_t::pagoda },
         card_t{ J, color_t::pagoda },
         card_t{ J, color_t::jade },
         card_t{ J, color_t::sword },
         card_t{ J, color_t::star },
         card_t{ A, color_t::pagoda },
      };
      REQUIRE(is_continuios(result) == true);
   }

}