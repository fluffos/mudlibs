// file: globals.h
#ifndef __GLOBALS_H
#define __GLOBALS_H

//other includes that should be associated with global defs
// tests.h (ASSERT/ASSERT2/SAVETP/RESTORETP -- see its own header comment)
// genuinely exists in this archive at core/include/tests.h, but its own
// #include here was left commented out, so the entire
// /core/sefun/tests/ self-test suite (~113 efun tests plus tests.lpc's
// own fixture runner) failed to compile with "Undefined function
// ASSERT[2]"/"Undefined variable SAVETP" -- fixed by uncommenting this.
// See NOTES.md.
#include "tests.h"

#ifdef __SENSIBLE_MODIFIERS__
#define staticf protected
#define staticv nosave
#else
#define staticf nosave
#define staticv nosave
#endif

//Root directories for public and secure libs
#define PUBLIC_DIR          "/public"
#define SECURE_DIR          "/secure"
#define CORE_DIR            "/core"

#define PUBLIC_LIB_DIR      PUBLIC_DIR"/lib"
#define SECURE_LIB_DIR      SECURE_DIR"/lib"
#define CORE_LIB_DIR        CORE_DIR"/lib"


//directories for root libs
#define PUBLIC_COMPONENT_DIR    PUBLIC_LIB_DIR"/component"
#define PUBLIC_DAEMON_DIR       PUBLIC_LIB_DIR"/daemon"
#define PUBLIC_INHERIT_DIR      PUBLIC_LIB_DIR"/inherit"
#define PUBLIC_OBJ_DIR          PUBLIC_LIB_DIR"/obj"
#define PUBLIC_SINGLETON_DIR    PUBLIC_LIB_DIR"/single"
#define PUBLIC_CONFIG_DIR       PUBLIC_DIR"/cfg"
#define PUBLIC_CMDS_DIR         PUBLIC_DIR"/cmds"
#define PUBLIC_VERBS_DIR        PUBLIC_CMDS_DIR"/verbs"
#define PUBLIC_LOG_DIR          PUBLIC_DIR"/log"
#define PUBLIC_ETC_DIR          PUBLIC_DIR"/etc"
#define PUBLIC_TMP_DIR          PUBLIC_DIR"/tmp"
#define DOMAINS_DIR             PUBLIC_DIR"/domains"
#define USER_DIR                PUBLIC_DIR"/user"
#define DOC_DIR                 PUBLIC_DIR"/doc"


//directories for root secure libs
#define SECURE_COMPONENT_DIR    SECURE_LIB_DIR"/component"
#define SECURE_DAEMON_DIR       SECURE_LIB_DIR"/daemon"
#define SECURE_INHERIT_DIR      SECURE_LIB_DIR"/inherit"
#define SECURE_OBJ_DIR          SECURE_LIB_DIR"/obj"
#define SECURE_SINGLETON_DIR    SECURE_LIB_DIR"/single"
#define SECURE_CONFIG_DIR       SECURE_DIR"/cfg"
#define SECURE_CMDS_DIR         SECURE_DIR"/cmds"
#define SECURE_VERBS_DIR        SECURE_CMDS_DIR"/verbs" 
#define SECURE_LOG_DIR          SECURE_DIR"/log"
#define SECURE_ETC_DIR          SECURE_DIR"/etc"
#define SECURE_TMP_DIR          SECURE_DIR"/tmp"



//directories for root secure libs
#define CORE_COMPONENT_DIR    CORE_LIB_DIR"/component"
#define CORE_DAEMON_DIR       CORE_LIB_DIR"/daemon"
#define CORE_INHERIT_DIR      CORE_LIB_DIR"/inherit"
#define CORE_OBJ_DIR          CORE_LIB_DIR"/obj"
#define CORE_SINGLETON_DIR    CORE_LIB_DIR"/single"
#define CORE_CONFIG_DIR       CORE_DIR"/cfg"
#define CORE_CMDS_DIR         CORE_DIR"/cmds"
#define CORE_VERBS_DIR        CORE_CMDS_DIR"/verbs" 
#define CORE_LOG_DIR          CORE_DIR"/log"
#define CORE_ETC_DIR          CORE_DIR"/etc"
#define CORE_TMP_DIR          CORE_DIR"/tmp"
#define MASTER_DIR            CORE_LIB_DIR"/master"
#define SEFUNS_DIR            CORE_DIR"/sefun"
// trailing slash required: /public/cmds/tests.lpc's recurse() always
// concatenates "dir + <name>" assuming dir already ends in "/" -- without
// it, every get_dir()/recursion path below the top level resolves against
// a nonexistent squashed-together directory name (e.g. "testscompiler/"
// instead of "tests/compiler/") and get_dir() returns 0 instead of an
// array, crashing the very first `tests` command with "Bad argument 2 to
// foreach". See NOTES.md.
#define SEFUNTESTS_DIR        SEFUNS_DIR"/tests/"


//save directories
#define SAVE_DIR            CORE_DIR"/save"
#define SAVE_ACCOUNTS       SAVE_DIR"/accounts"
#define SAVE_DATA_DIR       SAVE_DIR"/data"
#define SAVE_BIN_DIR        SAVE_DIR"/binaries"


//public common objects and files
#define DEBUG_LOG           PUBLIC_LOG_DIR"/debug.log"
#define ERROR_LOG           PUBLIC_LOG_DIR"/log"
#define COMPILE_LOG         PUBLIC_LOG_DIR"/compile"
#define CMDS_TESTS          PUBLIC_CMDS_DIR"/tests"
#define TMP_EVAL_FILE       PUBLIC_TMP_DIR"/tmp_eval_file"
#define CODE_TMP_FILE       PUBLIC_TMP_DIR"/CODE_TMP_FILE"

//secure common objects and files
#define SWAP_FILE           CORE_TMP_DIR"/swapfile"
#define SECURE_DEBUG_LOG    SECURE_LOG_DIR"/debug.log"
#define OVERRIDES_FILE      SEFUNS_DIR"/sefun"
#define WELCOME_TEXT_FILE   CORE_ETC_DIR"/motd"

#define SEFUN_OBJ       SEFUNS_DIR"/sefun"
#define MASTER_OBJ      MASTER_DIR"/master"
#define VALID_OBJ       MASTER_DIR"/valid"
#define LOGIN_OBJ       CORE_OBJ_DIR"/login"
#define USER_OBJ        CORE_OBJ_DIR"/user"
#define VOID_OBJ        CORE_SINGLETON_DIR"/void"
#define INH_OBJ         CORE_SINGLETON_DIR"/inh"


//commonly inherited objects
#define CLEAN_UP        CORE_INHERIT_DIR"/clean_up"
#define BASE_OBJ        CORE_INHERIT_DIR"/base"


//core daemons daemons
#define VIRTUAL_D  CORE_DAEMON_DIR"/virtual"


//etc
#define ROOT_UID     "Root"
#define BACKBONE_UID "Backbone"
//#define COMMAND_PREFIX "/command/"


// classes for message() efun.
#define M_STATUS "status"
#define M_SAY    "say"



#endif
