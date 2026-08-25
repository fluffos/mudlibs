// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#ifdef nomask
#undef nomask
#endif

// private so they don't become simuls
private inherit __DIR__ "check_config";

// these first since others might use them.
inherit __DIR__ "simul_efun/overrides";

inherit __DIR__"simul_efun/chinese";

inherit __DIR__ "simul_efun/security";
inherit __DIR__ "simul_efun/objcalls";
inherit __DIR__ "simul_efun/userfuncs";
inherit __DIR__ "simul_efun/path";
inherit __DIR__ "simul_efun/string";
inherit __DIR__ "simul_efun/misc";
inherit __DIR__ "simul_efun/more";
inherit __DIR__ "simul_efun/tell";

void create()
{
    debug_message(ctime() + " loaded " __FILE__);
}
