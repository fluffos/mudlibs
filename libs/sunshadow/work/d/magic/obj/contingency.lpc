#include <std.h>
#include <daemons.h>
inherit OBJECT;

string spell, spell_type, args;
int prof;
int level;

void create() {
    ::create();
    set_name("contingency");
    set("id", ({ "remotexoli"}) );
    set("short", "");
    set("long", "");
    set_property("no animate", 1);
    set_weight(0);
}

int clean_up()
{
    if(!objectp(TO)) { return 1; }
    if(objectp(ETO)) { return 1; }
    destruct(TO);
    return 1;
}

void init() {
    ::init();
    add_action("now","now");
}

void set_clevel(int i) {
    level = i;
}

int get_prof() {
    return prof;
}

void set_spell(string xxx) {
    spell = xxx;
}

void set_spell_type (string type) {
    spell_type = type;
}

void set_args(string arg) {
    args = arg;
}


int save_me(string str) {
    return 1;
}
int flag =0;
int now() {
    object spellobj;
    object *armor;

    if(!spell) return 0;
    if(flag) return 0;
    flag = 1;

    if(!deep_present("statue of "+capitalize(TP->query_name()),TP)){
	write("The image of yourself is missing, the contingency fails.\n");
       remove();
       return 1;
    }

    call_out("remove",1);

    if(!stringp(args)) args = "";
    new(spell)->use_spell(TP,args,level,100, spell_type);

    return 1;
}

int drop() {
   return 1;
}

int is_detectable() { return 0; }
int query_invis() { return 1; }
