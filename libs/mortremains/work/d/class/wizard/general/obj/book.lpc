/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

#define GENERAL_MAGE_PATH "/d/class/wizard/std/cmds:/d/class/wizard/general/cmds"

#include <daemons.h>

inherit OBJECT;

string path;

void create() {
    seteuid(getuid());
    set("author", "cyanide");
    set("short", "a black bound spell book");
    set("long", "It is bound in an unidentifiable reptilian hide.\n"+
      "The cover states, in gold lettering, the word \"mhelp\".\n");
    set("id", ({ "#CLASS_OBJECT#", "book", "spell book" }) );
    set("prevent_get", 1);
    set("prevent_sell", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
    set("banned_armor", ({ "suit", "shield", "helmet" }) );
}

void init() {
    add_action("cmd_hook", "", 1);
    if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
    string file, verb;
    int blah;

    path = GENERAL_MAGE_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 
