#pragma once 

#include <array>
#include <vector>
#include <numeric>
#include <algorithm>

namespace tichu 
{
	//! \todo rename to "color"
	enum class color_t {
		jade,
		sword,
		pagoda,
		star,
		special // dragon, phonix, mahjong, dog
	};

	// n = 52 
	//! \todo 2019-11-17: could be a constexpr int<0...52> or <2...A>
	template <typename T>
	struct card 
	{
		using value_t = T;

      value_t  value;
      color_t  color;
	};

	using card_t = card<char>;

	constexpr auto less  = [](card_t const& a, card_t const& b) noexcept {
		return a.value < b.value;
	};

	constexpr card_t::value_t Mahjong{ 1 };
	constexpr card_t::value_t Phonix{ 15 };
	constexpr card_t::value_t Dragon{ 16 };
	constexpr card_t::value_t Dog{ 0 };
	constexpr card_t::value_t J{ 11 };
	constexpr card_t::value_t Q{ 12 };
	constexpr card_t::value_t K{ 13 };
	constexpr card_t::value_t A{ 14 };

	constexpr card_t mahjong{ Mahjong, color_t::special };

	using deck_t   = std::array<card_t, 56>;
   using grand_tichu_t = std::array<card_t, 8>;
   using hand_cards_t = std::array<card_t, 14>;
   using stash_t  = std::vector<card_t>;

	template <typename Stash>
	void sort_cards(Stash && stash) noexcept {
		std::sort(std::begin(stash), std::end(stash), less);
	}

	// clang-format off
	constexpr deck_t deck() noexcept {
		return { {
			mahjong,
			{ Dragon, color_t::special },
			{ Phonix, color_t::special },
			{ Dog, color_t::special },
			{ 2, color_t::jade },
			{ 3, color_t::jade },
			{ 4, color_t::jade },
			{ 5, color_t::jade },
			{ 6, color_t::jade },
			{ 7, color_t::jade },
			{ 8, color_t::jade },
			{ 9, color_t::jade },
			{ 10,color_t::jade },
			{ J, color_t::jade },
			{ Q, color_t::jade },
			{ K, color_t::jade },
			{ A, color_t::jade },
			{ 2, color_t::sword },
			{ 3, color_t::sword },
			{ 4, color_t::sword },
			{ 5, color_t::sword },
			{ 6, color_t::sword },
			{ 7, color_t::sword },
			{ 8, color_t::sword },
			{ 9, color_t::sword },
			{ 10,color_t::sword },
			{ J, color_t::sword },
			{ Q, color_t::sword },
			{ K, color_t::sword },
			{ A, color_t::sword },
			{ 2, color_t::pagoda },
			{ 3, color_t::pagoda },
			{ 4, color_t::pagoda },
			{ 5, color_t::pagoda },
			{ 6, color_t::pagoda },
			{ 7, color_t::pagoda },
			{ 8, color_t::pagoda },
			{ 9, color_t::pagoda },
			{ 10,color_t::pagoda },
			{ J, color_t::pagoda },
			{ Q, color_t::pagoda },
			{ K, color_t::pagoda },
			{ A, color_t::pagoda },
			{ 2, color_t::star },
			{ 3, color_t::star },
			{ 4, color_t::star },
			{ 5, color_t::star },
			{ 6, color_t::star },
			{ 7, color_t::star },
			{ 8, color_t::star },
			{ 9, color_t::star },
			{ 10,color_t::star },
			{ J, color_t::star },
			{ Q, color_t::star },
			{ K, color_t::star },
			{ A, color_t::star }
			} };
	}
	// clang-format on

   //! \brief accumulate the values of the cards in a range
	template <typename Cards>
   [[nodiscard]] auto values(Cards const& cards) noexcept {
      return std::accumulate(std::begin(cards), std::end(cards), 0, [](auto accumulator, card_t const& c) { 
         return accumulator + c.value; 
      });
   }

   //
   constexpr auto point(card_t c) noexcept
   {
      if (c.value == 5)
         return 5;
      if (c.value == 10 || c.value == K)
         return 10;
      if (c.value == Dragon)
         return 25;
      if (c.value == Phonix)
         return -25;
      // 
      return 0;
   }

   //! \brief accumulate the points of the cards in a range
	template <typename Cards>
   [[nodiscard]] auto points(Cards const& cards) noexcept {
      return std::accumulate(std::begin(cards), std::end(cards), 0, [](auto accumulator, card_t const& c) {
         return accumulator + point(c);
      });
   }
}

constexpr bool operator < (tichu::card_t const& a, tichu::card_t const& b) noexcept {
	return a.value < b.value;
}

constexpr bool operator == (tichu::card_t const& a, tichu::card_t const& b) noexcept {
	return a.value == b.value;
}

constexpr bool operator != (tichu::card_t const& a, tichu::card_t const& b) noexcept {
	return !(a == b);
}
