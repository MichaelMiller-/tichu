#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/logic.h>
#include <tichu/card.h>

TEST_CASE("is_bomb", "[logic]")
{
   using namespace tichu;

   SECTION("with random three cards")
   {
      tichu::stash_t result = {
         card_t{ 5, color_t::jade },
         card_t{ A, color_t::jade },
         card_t{ A, color_t::sword },
      };
      REQUIRE(is_bomb(result) == false);
   }
   SECTION("bomb four of a kind")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 2, color_t::sword },
         card_t{ 3, color_t::sword },
         card_t{ 4, color_t::jade },
         card_t{ 4, color_t::pagoda },
         card_t{ 4, color_t::star },
         card_t{ 4, color_t::sword },
      };
      REQUIRE(is_bomb(result) == true);
   }
   SECTION("straight bomb")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 3, color_t::pagoda },
         card_t{ 4, color_t::pagoda },
         card_t{ 5, color_t::pagoda },
         card_t{ 6, color_t::pagoda },
         card_t{ 7, color_t::pagoda },
      };
      REQUIRE(is_bomb(result) == true);
   }
   SECTION("straight bomb and four of a kind")
   {
      tichu::stash_t result = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 3, color_t::pagoda },
         card_t{ 4, color_t::pagoda },
         card_t{ 5, color_t::pagoda },
         card_t{ 5, color_t::sword },
         card_t{ 5, color_t::star },
         card_t{ 5, color_t::jade },
         card_t{ 6, color_t::pagoda },
         card_t{ 7, color_t::pagoda },
      };
      REQUIRE(is_bomb(result) == true);
   }
}
