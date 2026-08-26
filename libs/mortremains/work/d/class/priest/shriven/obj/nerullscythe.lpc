/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

#define GENERAL_PRIEST_PATH "/d/class/priest/std/cmds:/d/class/priest/shriven/cmds"

#include <daemons.h>

inherit ARMOR;

string path;

void create() {
    seteuid(getuid());
    set("id", ({ "#CLASS_OBJECT#", "robes" }) );
    set ("short", "robes of Nerull") ;
    set ("long", "The Symbol of the Shriven Scythes.\n"+
      "Blood drops are embroidered into the fabric\n") ;
    set ("bulk", 1) ;
    set ("mass", 2) ;
    set_armor_type("robes");
    set ("armor", 0);
    set("armor_object", 1);
    set("major", ({ "all", "astral", "chaos", "combat", "charm", "guardian", "healing", "necromantic", "summoning", "sun" }) );
    set("minor", ({  "divination", "time" }) );	 
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
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
