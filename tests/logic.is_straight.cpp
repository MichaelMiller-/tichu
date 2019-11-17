#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/logic.h>
#include <tichu/card.h>

// view::sliding

TEST_CASE("is_straight", "[logic]")
{
   using namespace tichu;

   SECTION("with one cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
      };
      REQUIRE(is_straight(result) == false);
   }
   SECTION("with random two cards")
   {
      tichu::stash_t result = {
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_straight(result) == false);
   }
   SECTION("with random three cards")
   {
      tichu::stash_t result = {
         card_t{ 5, color_t::jade },
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_straight(result) == false);
   }
   SECTION("straight up to A")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 7, color_t::pagoda },
         card_t{10, color_t::pagoda },
         card_t{ J, color_t::pagoda },
         card_t{ Q, color_t::pagoda },
         card_t{ K, color_t::pagoda },
         card_t{ A, color_t::pagoda },
      };
      REQUIRE(is_straight(result) == true);
   }
   SECTION("straight from Mahjong")
   {
	   tichu::stash_t result = {
		   card_t{ Mahjong, color_t::special },
		   card_t{ 2, color_t::jade },
		   card_t{ 3, color_t::jade },
		   card_t{ 4, color_t::jade },
         card_t{ 4, color_t::sword },
         card_t{ 5, color_t::jade },
         card_t{ 8, color_t::sword },
         card_t{ 8, color_t::jade },
      };
	   REQUIRE(is_straight(result) == true);
   }
   SECTION("straight up to J")
   {
      tichu::stash_t result = {
         card_t{ 5, color_t::pagoda },
         card_t{ 7, color_t::jade },
         card_t{ 8, color_t::pagoda },
         card_t{ 9, color_t::jade },
         card_t{ 10, color_t::pagoda },
         card_t{ J, color_t::jade },
         card_t{ K, color_t::pagoda },
      };
      REQUIRE(is_straight(result) == true);
   }
}

