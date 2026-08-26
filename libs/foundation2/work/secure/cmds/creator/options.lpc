// Another wonderful product brought to you by Beek

#include <std.h>

inherit LIB_DAEMON;

int cmd(string str) {
#ifdef __SYSMALLOC__
    write("Using system malloc.\n");
#endif
#ifdef __SMALLOC__
    write("Using smalloc.\n");
#endif
#ifdef __BSDMALLOC__
    write("Using BSDmalloc.\n");
#endif
#ifdef __WRAPPEDMALLOC__
    write("       wrapped with wrappedmalloc.\n");
#endif
#ifdef __DEBUGMALLOC__
    write("       wrapped with debugmalloc.\n");
#endif
#ifndef __SYSMALLOC__
#ifndef __SBRK_OK__
    write("       sbrk() disabled.\n");
#endif
#endif
#ifdef __DO_MSTATS__
    write("       malloc_status() available.\n");
#endif
#ifdef __DEBUGMALLOC_EXTENSIONS__
    write("       debugmalloc extensions available.\n");
#ifdef __CHECK_MEMORY__
    write("       check_memory() available.\n");
#endif
#endif
    write("\n");
#ifdef __HAS_STATUS_TYPE__
    write("status type exists.\n");
#else
    write("status type does not exist.\n");
#endif
#ifdef __OLD_COMMAND__
    write("OLD_COMMAND defined.\n");
#endif
#ifdef __SANE_EXPLODE_STRING__
  write("SANE_EXPLODE_STRING defined.\n");
#endif
#ifdef __CAST_CALL_OTHERS__
    write("call_others must be casted.\n");
#endif
#ifdef __NONINTERACTIVE_STDERR_WRITE__
    write("write() with this_player() == 0 goes to stdout.\n");
#endif
#ifdef __NO_LIGHT__
    write("set_light() disabled.\n");
#endif
#ifdef __NO_MUDLIB_STATS__
    write("mudlib stats disabled.\n");
#endif
#ifdef __NO_ADD_ACTION__
    write("add_action() disabled.\n");
#endif
#ifdef __NO_WIZARDS__
    write("wizardp() disabled.\n");
#endif
#ifdef __NEW_FUNCTIONS__
    write("new function pointers enabled.\n");
#endif
#ifdef __OLD_TYPE_BEHAVIOR__
    write("old type behavior on.\n");
#endif
#ifdef __OLD_RANGE_BEHAVIOR__
    write("old range behavior on.\n");
#endif
#ifdef __OLD_ED__
    write("old ed() enabled.\n");
#endif
#ifdef __LOG_CATCHES__
    write("LOG_CATCHES defined.\n");
#endif
#ifdef __MUDLIB_ERROR_HANDLER__
    write("MUDLIB_ERROR_HANDLER defined.\n");
#endif
#ifdef __SOCKET_EFUNS__
    write("Socket efuns enabled.\n");
#endif
#ifdef __OPTIMIZE_FUNCTION_TABLE_SEARCH__
    write("OPTIMIZE_FUNCTION_TABLE_SEARCH defined.\n");
#endif
    return 1;
}
