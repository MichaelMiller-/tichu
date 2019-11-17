#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/card.h>

TEST_CASE("values", "[cards]")
{
   SECTION("first eight cards") 
   {
      using namespace tichu;

      auto cards = {
         card_t{ Mahjong, color_t::special },
         card_t{ Dragon, color_t::special },
         card_t{ Phonix, color_t::special },
         card_t{ Dog, color_t::special },
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::jade },
         card_t{ 4, color_t::jade },
         card_t{ 5, color_t::jade }
      };
      REQUIRE(values(cards) == (1 + 16 + 15 + 0 + 2 + 3 + 4 + 5));
   }
}

TEST_CASE("points", "[cards]")
{
   using namespace tichu;

   REQUIRE(point(card_t{ Dog }) == 0);
   REQUIRE(point(card_t{ Mahjong }) == 0);
   REQUIRE(point(card_t{ Dragon }) == 25);
   REQUIRE(point(card_t{ Phonix }) == -25);

   REQUIRE(point(card_t{ 2 }) == 0);
   REQUIRE(point(card_t{ 3 }) == 0);
   REQUIRE(point(card_t{ 4 }) == 0);
   REQUIRE(point(card_t{ 5 }) == 5);
   REQUIRE(point(card_t{ 6 }) == 0);
   REQUIRE(point(card_t{ 7 }) == 0);
   REQUIRE(point(card_t{ 8 }) == 0);
   REQUIRE(point(card_t{ 9 }) == 0);
   REQUIRE(point(card_t{ 10 }) == 10);
   REQUIRE(point(card_t{ J }) == 0);
   REQUIRE(point(card_t{ Q }) == 0);
   REQUIRE(point(card_t{ K }) == 10);
   REQUIRE(point(card_t{ A }) == 0);

   SECTION("first eight cards")
   {
      auto cards = {
         card_t{ Mahjong, color_t::special },
         card_t{ Dragon, color_t::special },
         card_t{ Phonix, color_t::special },
         card_t{ Dog, color_t::special },
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::jade },
         card_t{ 4, color_t::jade },
         card_t{ 5, color_t::jade }
      };
      REQUIRE(points(cards) == 5);
   }
}
