/*
This file is a part of: LinaVG
https://github.com/inanevin/LinaVG

Author: Inan Evin
http://www.inanevin.com

Copyright (c) [2022-] [Inan Evin]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
Class: Text

Timestamp: 12/29/2018 10:43:46 PM
*/

#pragma once
#ifndef LinaVGText_HPP
#define LinaVGText_HPP

#include "Common.hpp"
#include <unordered_map>
#include <functional>
#include <ft2build.h>
#include FT_FREETYPE_H

namespace LinaVG
{
    struct TextCharacter
    {
        BackendHandle m_texture = 0;
        Vec2          m_size    = Vec2(0.0f, 0.0f);
        Vec2          m_bearing = Vec2(0.0f, 0.0f);
        signed int    m_advance = 0;
    };

    /// <summary>
    /// Management for text rendering.
    /// </summary>
    struct TextData
    {
        FT_Library                                                               m_ftlib = nullptr;
        std::unordered_map<std::string, std::unordered_map<char, TextCharacter>> m_loadedFonts;
    };

    namespace Internal
    {
        extern LINAVG_API TextData g_textData;
    }

    namespace Text
    {
        LINAVG_API bool Initialize();
        LINAVG_API void Terminate();
    } // namespace Text
    LINAVG_API bool LoadFont(const std::string& file, int height = 48);

}; // namespace LinaVG

#endif
