// Copyright (C) 2017 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#ifndef CPPAST_CPP_ARRAY_TYPE_HPP_INCLUDED
#define CPPAST_CPP_ARRAY_TYPE_HPP_INCLUDED

#include <cppast/cpp_expression.hpp>
#include <cppast/cpp_type.hpp>

namespace cppast
{
    /// An array of a [cppast::cpp_type]().
    class cpp_array_type final : public cpp_type
    {
    public:
        /// \returns A newly created array.
        static std::unique_ptr<cpp_array_type> build(std::unique_ptr<cpp_type>       type,
                                                     std::unique_ptr<cpp_expression> size)
        {
            return std::unique_ptr<cpp_array_type>(
                new cpp_array_type(std::move(type), std::move(size)));
        }

        /// \returns A reference to the value [cppast::cpp_type]().
        const cpp_type& value_type() const noexcept
        {
            return *type_;
        }

        /// \returns A [cppast::cpp_expression]() that is the size of the array.
        const cpp_expression& size() const noexcept
        {
            return *size_;
        }

    private:
        cpp_array_type(std::unique_ptr<cpp_type> type, std::unique_ptr<cpp_expression> size)
        : type_(std::move(type)), size_(std::move(size))
        {
        }

        cpp_type_kind do_get_kind() const noexcept override
        {
            return cpp_type_kind::array;
        }

        std::unique_ptr<cpp_type>       type_;
        std::unique_ptr<cpp_expression> size_;
    };
} // namespace cppast

#endif // CPPAST_CPP_ARRAY_TYPE_HPP_INCLUDED