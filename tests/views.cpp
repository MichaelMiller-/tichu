#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <tichu/card.h>
#include <tichu/view.h>

//! \todo 
//TEST_CASE("group by color", "[view]")
//TEST_CASE("group by value", "[view]")
//TEST_CASE("remove equal cards", "[view]")
//TEST_CASE("remove less cards", "[view]")


TEST_CASE("remove special cards", "[view]")
{
   using namespace tichu;

   SECTION("the first eight cards")
   {
      tichu::stash_t cards = {
         card_t{ Mahjong, color_t::special },
         card_t{ Dragon, color_t::special },
         card_t{ Phonix, color_t::special },
         card_t{ Dog, color_t::special },
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::jade },
         card_t{ 4, color_t::jade },
         card_t{ 5, color_t::jade }
      };
      tichu::stash_t result = cards | view::remove_special_cards();

      REQUIRE(tichu::values(result) == (2 + 3 + 4 + 5));
   }
   SECTION("random cards")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
         card_t{ Phonix, color_t::special },
         card_t{ 3, color_t::sword },
         card_t{ 3, color_t::sword },
         card_t{ Dragon, color_t::special },
         card_t{ Dog, color_t::special }
      };
      tichu::stash_t result = cards | view::remove_special_cards();

      REQUIRE(tichu::values(result) == (2 + 3 + 3));
   }
}

TEST_CASE("remove duplicate cards", "[view]")
{
   using namespace tichu;

   SECTION("with one cards")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
      };
      tichu::stash_t result = cards | view::remove_duplicates();
      
      REQUIRE(tichu::values(result) == 2);
   }
   SECTION("with two cards")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::jade },
      };
      tichu::stash_t result = cards | view::remove_duplicates();

      //REQUIRE(points(x) == 0);
      REQUIRE(tichu::values(result) == (2 + 3));
   }
   SECTION("remove pair of two's")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 3, color_t::sword },
      };
      tichu::stash_t result = cards | view::remove_duplicates();

      REQUIRE(tichu::values(result) == (2 + 3));
   }
   SECTION("remove triple of two's")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::pagoda },
         card_t{ 2, color_t::sword },
         card_t{ 2, color_t::jade },
         card_t{ 4, color_t::sword },
         card_t{ 3, color_t::sword },
      };
      tichu::stash_t result = cards | view::remove_duplicates();

      REQUIRE(tichu::values(result) == (2 + 3 + 4));
   }
}

TEST_CASE("remove non continuios", "[view]")
{
   using namespace tichu;

   SECTION("with one cards")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
      };
      tichu::stash_t result = cards | view::remove_non_continuios();

      REQUIRE(tichu::values(result) == 2);
   }
   SECTION("with two cards")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::jade },
      };
      tichu::stash_t result = cards | view::remove_non_continuios();

      REQUIRE(tichu::values(result) == (2 + 3));
   }
   SECTION("remove pair of two's")
   {
      tichu::stash_t cards = {
         card_t{ 2, color_t::jade },
         card_t{ 2, color_t::pagoda },
         card_t{ 3, color_t::sword },
      };
      tichu::stash_t result = cards | view::remove_non_continuios();

      REQUIRE(tichu::values(result) == (2 + 3));
   }
   SECTION("remove triple of two's")
   {
      using namespace tichu;

      tichu::stash_t cards = {
         card_t{ 2, color_t::pagoda },
         card_t{ 2, color_t::sword },
         card_t{ 2, color_t::jade },
         card_t{ 3, color_t::sword },
         card_t{ 4, color_t::sword },
      };
      tichu::stash_t result = cards | view::remove_non_continuios();

      REQUIRE(tichu::values(result) == (2 + 3 + 4));
   }
}
