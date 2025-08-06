#pragma once

// ===== UTILITY MACROS ===== //

#define COUNT_ARGS_IMPL( _1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,  _9, _10,\
                        _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,\
                        _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,\
                        _31, _32, _33, _34, _35, _36, _37, _38, _39, _40,\
                        _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, N, ... ) N

#define XCOUNT_ARGS(...) COUNT_ARGS_IMPL( __VA_ARGS__,\
                        50, 49, 48, 47, 46, 45, 44, 43, 42, 41,\
                        40, 39, 38, 37, 36, 35, 34, 33, 32, 31,\
                        30, 29, 28, 27, 26, 25, 24, 23, 22, 21,\
                        20, 19, 18, 17, 16, 15, 14, 13, 12, 11,\
                        10,  9,  8,  7,  6,  5,  4,  3,  2,  1 )

#define STRINGIFY(s) #s
#define XSTRINGIFY(s) STRINGIFY(s)
#define CONCAT2(a,b) a##b
#define XCONCAT2(a,b) CONCAT2(a,b)
#define CONCAT3(a,b,c) a##b##c
#define XCONCAT3(a,b,c) CONCAT3(a,b,c)
#define CONCAT4(a,b,c,d) a##b##c##d
#define XCONCAT4(a,b,c,d) CONCAT4(a,b,c,d)
#define CONCAT5(a,b,c,d,e) a##b##c##d##e
#define XCONCAT5(a,b,c,d,e) CONCAT5(a,b,c,d,e)
#define CONCAT_IMPL(a,b) a##b
#define XCONCAT_IMPL(a,b) CONCAT_IMPL(a,b)
#define XCONCAT(...) XCONCAT_IMPL( CONCAT, XCOUNT_ARGS( __VA_ARGS__ ) )( __VA_ARGS__ )

// ===== DEFAULT TYPES USINGS ===== //

using ubyte = unsigned __int8;

using char8 = char;
using char16 = wchar_t;

using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;

using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

using float32 = float;
using float64 = double;

using cstr = char8 const*;
using cwstr = char16 const*;

// ===== DEBUG SPECIFIC MACROS ===== //
//include log.h
#ifndef _DEBUG
#define RES_PATH "../../"
#define WRES_PATH L"../../"
#define ASSERT(condition,message,logType) if(!(condition)){ }
#else
#define RES_PATH ""
#define WRES_PATH L""
#define ASSERT(condition, message)
#endif

// ===== OTHER ===== //

#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <functional>
#include <string_view>
#include <string>
#include <sstream>

template <class T>
using List = std::list<T>;

template <class Key, class Value>
using UnorderedMap = std::unordered_map<Key, Value>;

template<class Key, class Value>
using Map = std::map<Key, Value>;

using String = std::string;

using WStringView = std::wstring_view;
using StringView = std::string_view;

using RuntimeError = std::runtime_error;

using WOStringStream = std::wostringstream;

using IFStream = std::ifstream;