/*
** The general mages' class object.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
*/

#define BSD_PATH "/d/class/warrior/BSD/cmds/"

#include <daemons.h>

inherit ARMOR;

string path;

void create() {
    seteuid(getuid());
    set("short", "a feather talisman");
    set("long", @EYE
This is a small feather talisman handed down from generations long
past. It is your fetish, your law, your chaos, your life. The word
bsdhelp comes to your primative mind. 
EYE
    );
   set("id", ({ "#CLASS_OBJECT#", "feather", "talisman", "amulet" }) );
    set("prevent_sell", 1);
    set("prevent_get", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
    set_armor_type("amulet");
}

void init() {
    set("armor",(this_player()->query_level("bsd")/5 + 1));
    add_action("cmd_hook", "", 1);
    if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
    string file, verb;
    int blah;

    path = BSD_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
	blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 
