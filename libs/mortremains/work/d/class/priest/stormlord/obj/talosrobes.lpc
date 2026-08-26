/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

#define GENERAL_PRIEST_PATH "/d/class/priest/std/cmds:/d/class/priest/stormlord/cmds"

#include <daemons.h>

inherit ARMOR;

string path;

void create() {
    seteuid(getuid());
    set("id", ({ "#CLASS_OBJECT#", "robes" }) );
    set ("short", "robes of Talos") ;
    set ("long", "The Symbol of the Stormlords.\n"+
      "Jagged yellow bolts of lightning are embroidered into the "+
      "purple fabric.\nA small tag inside the robes reads \"phelp\".\n");
    set_armor_type("robes");
    set_armor_type("robes");
    set("major", ({ "all", "astral", "chaos", "combat", "earth", "air", "fire", "water", "healing", "necromantic", "summoning", "war", "weather" }) );
    set("minor", ({ "creation", "divination", "protection", "time" }) );	 
    set("prevent_get", 1);
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

    path = GENERAL_PRIEST_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 
