//
// Created by loki on 24-9-4.
//

#pragma once

#include <config.hpp>
#include <array>
#include <vector>

namespace leya::ecs {
template<typename T, size_t PageSize>
struct flex_array_chunk {
	using type = flex_array_chunk;

	[[nodiscard]] static consteval size_t max_item_capacity() {
		auto max_size = PageSize / sizeof(T);;
		return max_size;
	}

	std::array<T, max_item_capacity()> data_;
};

template<typename T, size_t PageSize>
struct flex_array {
	using chunk_type = flex_array_chunk<T, PageSize>;

	std::vector<chunk_type> chunks_;
	size_t size_;
	size_t capacity_;

	[[nodiscard]] T &operator[](size_t index) {
		return chunks_[index / chunk_type::max_item_capacity()].data_[index % chunk_type::max_item_capacity()];
	}

	[[nodiscard]] const T &operator[](size_t index) const {
		return chunks_[index / chunk_type::max_item_capacity()].data_[index % chunk_type::max_item_capacity()];
	}
};
}
