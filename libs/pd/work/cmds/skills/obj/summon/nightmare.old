// nightmare for the summon spell
// a dungeonware.net collaboration
#include <std.h>
#include <daemons.h>
inherit MOUNT;
static string owner;
static object ob, pl;
void create() {
    ::create();
    ob = this_object();
    set_name("nightmare");
    set_id( ({ "abyss demon","nightmare" }) );
    set_short("a nightmare");
    set_gender("female");
    set("aggressive", 0);
    set_heart_beat(1);
    set_level(12);
    set_exp(1);
    set_long("The nightmare is a huge jet black mount. She seems "
      "to absorb all the light around her. Evil eminates "
      "from her powerful form.");
    set_body_type("horse");
    set_alignment(-700);
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    set_sp(query_max_sp());
    set_race("nightmare");
    set_class("fighter");
    set_subclass("antipaladin");
    set_spell_chance(10);
    set_spells( ({ "rush" }) );
    set_property("nightmare" , 1);
}
void init() {
    ::init();
    add_action("command", "command");
}
int command(string str) {
    string order, tm;
    object oi;
    int x;
    if ((string)this_player() != owner) return 0;
    if (random(50) > (int)this_player()->query_skill("faith")) {
	x=random(20);
	switch (x) {
	case 1:
	    write("Nightmare ignores your command!");
	    return 1;
	    break;
	case 4:
	    write("Nightmare ignores your command!");
	    return 1;
	    break;
	case 10:
	    write("Nightmare breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	case 15:
	    write("Nightmare ignores your command!");
	    return 1;
	    break;
	case 19:
	    write("Nightmare breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	default:
	    break;
	}
    }
    if (!str || sscanf(str, "%s to %s", tm, order)!=2) {
	write("Syntax: <command [monster] to [command]>\n");
	return 0;
    }
    oi = present(tm, environment(this_player()));
    if (oi != this_object()) return 0;
    if (present("gagger12345",this_player()) &&
        member_array(order[0..strsrch(order," ")-1],
        ({"say","yell","whisper","shout","tell","emote","emoteto","speak","reply"})) != -1 ||
        (int)sizeof(load_object(SOUL_D)->query_atmos(order[0..strsrch(order," ")-1])) >= 1) return 1;
    if (order == "reveal powers") {
	ob->force_me("say I know the following spells:");
	ob->force_me("say   rush");
	ob->force_me("say I have the following special abilities:");
	ob->force_me("say   <reveal powers>, I can be ridden");
	ob->force_me("say I am level 12");
	return 1;
    }
    if (order == "die" || order == "suicide") {
	tell_room(environment(ob), "%^BOLD%^%^BLACK%^Nightmare turns a pale grey "+
	  "and slumps down dead before you.\n", ({ ob }));
	ob->die();
	return 1;
    }
    ob->force_me(order);
    return 1;
}
void set_owner(string str) {
    owner = str;
    pl = present(str, environment(this_object()));
    set_exp_share(pl, to_float(1/2));
    set_exp(0);
}
void heart_beat() {
    object *shade;
    ::heart_beat();
    if (!this_object() || !environment() || !pl) return;
    if (owner == "blah") return;
    if(!this_object() || !pl) return;
    if(!environment(this_object())) return;
    if (environment(this_object()) != environment(pl)) {
	if(file_name(environment(pl))[0..8] == "/d/arena/") {
	    message("", "The Nightmare turns to dust.\n", environment(this_object()));
	    this_object()->remove();
	    return;
	}        
	if(present("pillow", this_object()))
	    this_object()->force_me("wake");
	message("info", "%^BOLD%^%^BLACK%^Nightmare bounds out.%^RESET%^\n", environment(ob));
	this_object()->move(environment(pl));
	message("info", "%^BOLD%^%^BLACK%^Nightmare bounds in.%^RESET%^\n",environment((object)owner));
    }
    shade = all_inventory(environment(this_object()));
    if(pl != (object)"")
	for(int i=0;i<sizeof(shade);i++)
	    if((shade[i]->id("abyss demon")) && (shade[i] != this_object())) {
		message("info", "The nightmare snorts loudly and attacks it's owner!",environment(ob));
		this_object()->kill_ob(pl, 0);
		pl = (object)"";
		owner = "blah";
	    }
}
