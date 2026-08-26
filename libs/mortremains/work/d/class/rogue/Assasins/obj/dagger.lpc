#include <mudlib.h>

inherit OBJECT;

void create() {
    set("short","a Ceremonial Dagger");
    set("name","dagger");
    set("id",({"dagger","ceremonial dagger"}));
    set("long",@EndLong
    The dagger's small blade seems to draw in all light
which passes near it, though it faintly glows red.  The
handle is crafted of smooth bone, and a miniature skull
adorns its end.  This dagger is used by assassins to 
behead their unfortunate victims, although it looks
like it wouldn't work as a weapon.
EndLong
    );
    set("prevent_drop",1);
    set("prevent_get",1);
    set("prevent_give",1);
    set("prevent_clean",1);
    set("prevent_insert",1);
    set("mass",0);
    set("bulk",0);
    set("invisible",1);
}

void init() {
    add_action("_conceal","conceal");
    add_action("_reveal","reveal");
    add_action("_behead","behead");
}

int _conceal(string str) {
    if(str != "dagger") return notify_fail("Conceal what?\n");
    if(this_object()->query("invisible") == 1) return notify_fail("Your dagger is already concealed.\n");
    this_object()->set("invisible",1);
    write("You conceal your dagger.\n");
    return 1;
}

int _reveal(string str) {
    if(str != "dagger") return notify_fail("Reveal what?\n");
    if(this_object()->query("invisible") == 0) return notify_fail("Your dagger is already revealed.\n");
    this_object()->set("invisible",0);
    write("You reveal your dagger.\n");
    return 1;
}

int _behead(string arg) {
    object target, env, head;
    string name, tmp1, tmp2, cname;
    if(arg != "corpse") return notify_fail("You can only behead corpses.\n");
    env=environment(this_object());
    if(!present(arg,env)) {
	write("There's no corpse here.\n");
	return 1;
    }
    target=present(arg, env);
    name=target->query("cap_name");
    if(living(target)) return notify_fail("They need to be dead first.\n");
    sscanf(name,"%s %s %s", tmp1, tmp2, cname);
    int query_auto_load() { return 1; }
