// carrier demon for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-

#include <std.h>
#include <daemons.h>
inherit MONSTER;

static string owner;
static object ob, pl;
int knife_wielded=0;
void create() {
    ::create();
    ob = this_object();
    set_name("carrier");
    set_id( ({ "abyss demon", "carrier", "demon", "carrier demon" , "gremlin" }) 
    );
    set_gender("female");
    set_short("a gremlin");
    set("aggressive", 0);
    set_heart_beat(1);
    set_level(16);
    set_exp(0);
    set_long("This demon's long black wings and evil looking horns "
      "seem out of place on this small gremlin. Her wicked eyes "
      "glow with evil. Despite her fearsome looks, though, "
      "the demon backs away from you, waiting for something.");
    set_body_type("imp");
    set_alignment(-100);
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    set_sp(query_max_sp());
    set("race", "gremlin");
    set_class("mage");
    set_spell_chance(90);
    set_spells( ({ "missile" }) );
    set_stats("dexterity", 35);
    set_property("carrier" , 1);
}

void init() {
    ::init();
    add_action("command", "command");
}

int command(string str) {
    string order, tm,  victim, val, mess;
    int x;
    object oi, give;
    if ((string)this_player() != owner) return 0;
    if (random(65) > (int)this_player()->query_skill("faith")) {
	x=random(20);
	switch (x) {
	case 1:
	    write("Gremlin ignores your command!");
	    return 1;
	    break;
	case 4:
	    write("Gremlin ignores your command!");
	    return 1;
	    break;
	case 10:
	    write("Gremlin breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	case 15:
	    write("Gremlin ignores your command!");
	    return 1;
	    break;
	case 19:
	    write("Gremlin breaks out of your control!");
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
	return 1;
    }
    oi = present(tm, environment(this_player()));
    if (oi != this_object()) return 0;
    if (present("gagger12345",this_player()) &&
        member_array(order[0..strsrch(order," ")-1],
        ({"say","yell","whisper","shout","tell","emote","emoteto","speak","reply"})) != -1 ||
        (int)sizeof(load_object(SOUL_D)->query_atmos(order[0..strsrch(order," ")-1])) >= 1) return 1;
    if (order == "reveal powers") {
	ob->force_me("say I know the following spells:");
	ob->force_me("say   missile");
	ob->force_me("say I have the following special abilities:");
	ob->force_me("say   <reveal powers>, <carry>");
	ob->force_me("say   <carry [item] to [player]>, when the item is in");
	ob->force_me("say   your inventory");
	ob->force_me("say I am level 16");
	return 1;
    }
    if (order == "die" || order == "suicide") {
	tell_room(environment(ob), "%^BOLD%^%^BLACK%^ Carrier turns a pale grey "+
	  "and slumps down dead before you.\n", ({ ob }));
	ob->die();
	return 1;
    }
    if (sscanf(order, "carry %s to %s", mess, victim)==2) {
	give = present(mess, this_player());
	if (!give) {
	    write("You cannot give "+mess+" to carrier!");
	    return 1;
	}
	val = sprintf("give %s to %s", (string)give->query_name(),(string)this_object()->query_name());
	this_player()->force_me(val);
	if (present(victim, environment(this_object()))) {
	    val = sprintf("give %s to %s", mess, victim);
	    ob->force_me(val);
	    tell_room(environment(ob), "%^BOLD%^%^GREEN%^Gremlin departs.\n", ({ ob }));
	    destruct(ob);
	    return 1;
	} else {
	    if (!(oi=find_living(victim = lower_case(victim)))) {
		write("<carry [item] to [player]>");
		return 1;
	    }
	    owner = "blah";
	    pl = (object)"";
	    tell_room(environment(ob), "%^BOLD%^%^GREEN%^Gremlin departs.%^RESET%^\n", ({ ob }));
	    this_object()->move(environment(oi));
	    tell_room(environment(ob), "%^BOLD%^%^GREEN%^A gremlin lands.%^RESET%^", ({ ob }));
	    val = sprintf("give %s to %s", mess, victim);
	    this_object()->force_me(val);
	    tell_room(environment(ob), "%^BOLD%^%^GREEN%^Gremlin departs.\n", ({ ob }));
	    destruct(ob);
	    return 1;
	}
    }
    ob->force_me(order);
    return 1;
}

void set_owner(string str) {
    owner = str;
    pl = present(str, environment(this_object()));
    set_exp_share(pl, to_float(1/2));
}

void heart_beat() {
    object *shade;
    ::heart_beat();
    if (!this_object() || !environment() || !pl) return;
    if (owner == "blah") return;
    if (environment(this_object()) != environment(pl)) {
	if(file_name(environment(pl))[0..8] == "/d/arena/") {
	    message("", "The gremlin turns to dust.\n", environment(this_object()));
	    this_object()->remove();
	    return;
	}        

	message("info", "%^BOLD%^%^BLACK%^Gremlin follows its master.%^RESET%^\n", environment(ob));
	this_object()->move(environment(pl));
	message("info", "%^BOLD%^%^BLACK%^Gremlin enters, waiting for something...%^RESET%^\n",environment((object)owner));
    }
    shade = all_inventory(environment(this_object()));
    if(pl != (object)"")
	for(int i=0;i<sizeof(shade);i++)
	    if((shade[i]->id("abyss demon")) && (shade[i] != this_object())) {
		message("info", "The gremlin gets confused and attacks it's master!",environment(ob));
		this_object()->kill_ob(pl, 0);
		pl = (object)"";
		owner = "blah";
	    }
}

