#ifndef ESL_ARRAY_H_
#define ESL_ARRAY_H_

#include <cstddef>

namespace esl
{

    template<typename T, size_t N>
    class Array
    {
    public:
        Array() = default;

        /**
         * Returns a reference to the element at specified location pos. No bounds checking is performed.
         *
         * @param[in] i index of the element to return
         * @return Reference to the requested element.
         */
        constexpr T& operator[](size_t i) noexcept
        {
            return data_[i];
        }

        /**
         * Returns a reference to the element at specified location pos. No bounds checking is performed.
         *
         * @param[in] i index of the element to return
         * @return Const reference to the requested element.
         */
        constexpr const T& operator[](size_t i) const noexcept
        {
            return data_[i];
        }

        /**
         * Checks if the container has no elements, i.e. whether begin() == end().
         *
         * @return true if the container is empty, false otherwise
         */
        constexpr bool empty() const noexcept
        {
            return size() == 0;
        }

        /**
         * Returns the number of elements in the container, i.e. std::distance(begin(), end()).
         *
         * @return The number of elements in the container.
         */
        constexpr size_t size() const noexcept
        {
            return SIZE_;
        }

        /**
         * Returns the maximum number of elements the container is able to hold due to system or library
         * implementation limitations, i.e. std::distance(begin(), end()) for the largest container.
         *
         * @return Maximum number of elements.
         */
        constexpr size_t max_size() const noexcept
        {
            return SIZE_;
        }

        /**
         * Assigns the value to all elements in the container.
         *
         * @param[in] value the value to assign to the elements
         * @return
         */
        constexpr void fill(const T& value) noexcept
        {
            for (auto& e : data_)
                e = value;
        }

    private:
        /// Actual data array
        T data_[N] { };

        /// Size of this array
        static constexpr size_t SIZE_ { N };
    };

}  // namespace esl

#endif  // ESL_ARRAY_H_
