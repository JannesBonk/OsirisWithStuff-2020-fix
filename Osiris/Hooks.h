#pragma once

#include <d3d9.h>
#include <memory>
#include <type_traits>
#include <unordered_map>
#include <Windows.h>

#include "Hooks/MinHook.h"
#include "Hooks/VmtSwap.h"

struct SoundInfo;

using HookType = MinHook;

class Hooks {
public:
    Hooks(HMODULE module) noexcept;

    void install() noexcept;
    void uninstall() noexcept;

    WNDPROC originalWndProc;
    std::add_pointer_t<HRESULT __stdcall(IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*)> originalPresent;
    std::add_pointer_t<HRESULT __stdcall(IDirect3DDevice9*, D3DPRESENT_PARAMETERS*)> originalReset;
    std::add_pointer_t<int __fastcall(SoundInfo&)> originalDispatchSound;

    unsigned long tahomaBoldAA;
    unsigned long smallFonts;
    unsigned long tahomaAA;
    unsigned long tahomaNoShadowAA;
    unsigned long verdanaExtraBoldAA;

    HookType bspQuery;
    HookType client;
    HookType clientMode;
    HookType engine;
    HookType gameEventManager;
    HookType modelRender;
    HookType panel;
    HookType prediction;
    HookType sound;
    HookType surface;
    HookType viewRender;
    VmtSwap networkChannel;

    HookType svCheats;
private:
    HMODULE module;
    HWND window;
};

inline std::unique_ptr<Hooks> hooks;
