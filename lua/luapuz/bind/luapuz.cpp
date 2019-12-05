// ---------------------------------------------------------------------------
// luapuz.cpp was generated by puzbind.lua
//
// Any changes made to this file will be lost when the file is regenerated.
// ---------------------------------------------------------------------------

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include "../luapuz_functions.hpp"
#include "../luapuz_tracking.hpp"

// ---------------------------------------------------------------------------
// luapuz
// ---------------------------------------------------------------------------

#include "luapuz_puz.hpp"
#include "luapuz_std.hpp"

// This needs to be extern "C" because of C++ name mangling
extern "C" {

LUAPUZ_API int luaopen_luapuz (lua_State *L) {
    // For tracking userdata objects
    luapuz_registerWeakTable(L, luapuz_tracked_objects_key);
    // For registering enumerations
    luapuz_registerTable(L, luapuz_enumerations_key);
    // For tracking load/save functions
    luapuz_registerTable(L, luapuz_loadsave_key);

    // Register (sub)tables
    luapuz_openpuzlib(L);

    // Return the library
    lua_getglobal(L, "puz");
    return 1;
}

} // extern "C"

