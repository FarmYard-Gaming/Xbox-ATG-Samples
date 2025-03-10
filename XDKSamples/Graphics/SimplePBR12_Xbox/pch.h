﻿//--------------------------------------------------------------------------------------
// pch.h
//
// Header for standard system include files.
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

// Use the C++ standard templated min/max
#define NOMINMAX

#include <wrl.h>

#if defined(_XBOX_ONE) && defined(_TITLE)

#include <xdk.h>

#if _XDK_VER < 0x38390403 /* XDK Edition 160800 */
#error This sample requires the August 2016 XDK or later
#endif

#include <d3d12_x.h>
#include <d3dx12_x.h>

#else

#include <d3d12.h>
#include "d3dx12.h"
#include <dxgi1_6.h>

#ifdef _DEBUG
#include <dxgidebug.h>
#endif

#endif

#include <DirectXMath.h>
#include <DirectXColors.h>


#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <exception>
#include <memory>
#include <system_error>

#include <pix.h>

#include <ATGColors.h>
#include <CommonStates.h>
#include <DescriptorHeap.h>
#include <DirectXHelpers.h>
#include <Effects.h>
#include <GamePad.h>
#include <Keyboard.h>
#include <Model.h>
#include <Mouse.h>
#include <OrbitCamera.h>
#include <PostProcess.h>
#include <PrimitiveBatch.h>
#include <ResourceUploadBatch.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <VertexTypes.h>
#include <WICTextureLoader.h>
#include <DDSTextureLoader.h>

namespace DX
{
    // Helper class for COM exceptions
    class com_exception : public std::exception
    {
    public:
        com_exception(HRESULT hr) noexcept : result(hr) {}

        const char* what() const override
        {
            static char s_str[64] = {};
            sprintf_s(s_str, "Failure with HRESULT of %08X", result);
            return s_str;
        }

    private:
        HRESULT result;
    };

    // Helper utility converts D3D API failures into exceptions.
    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            throw com_exception(hr);
        }
    }
}