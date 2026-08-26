/*
** The class object for the Dragon guild.
** Now mages can have class.   ;)
** Cyanide worked all the bugs out, 23 July 1997.
** Cyanide made the dragon's guild object, 30 Nov 98
*/

#define DRAGON_PATH "/d/class/dragon/cmds"

#include <daemons.h>

inherit OBJECT;

string path;

void create() {
    seteuid(getuid());
    set("short", "a Dragonheart Pendant");
    set("long", wrap("A small pendant which serves as a focus of your "+
      "draconic existance.\n Etched onto the pendant, fiery "+
      "letters spell the word \"dragonhelp\"."));
    set("id", ({ "#CLASS_OBJECT#", "pendant", "dragon pendant" }) );
    set("prevent_get", 1);
    set("prevent_sell", 1);
    set("prevent_drop", 1);
    set("prevent_insert", 1);
    set("prevent_clean", 1);
    set("banned_armor", ({ "suit", "shield", "helmet", "glove", 
      "boot", "bracers" }) );
}

void init() {
    add_action("cmd_hook", "", 1);
     if (!living(environment())) remove();
}

int cmd_hook(string cmd) {
    string file, verb;
    int blah;

    path = DRAGON_PATH;
    verb = query_verb();

    if (verb == "clean") return 0;
    file = (string)CMD_D->find_cmd(verb, explode(path, ":"));
    if (file && (file!=""))
        blah = (int)call_other(file, "cmd_"+verb, cmd);

    return blah;
}

int query_auto_load() { return 1; } 

/* EOF */