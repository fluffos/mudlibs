//      _gate.c
//      Mage ability
//      -- Seeker

#include <std.h>

#define GATE_PROP "gate_spell_data"

inherit DAEMON;

int spell();

string type() { return "conjuring"; }

object portal, portal2;

int cmd_gate(string str) {
    object tp;
    int i, fail;
    string tmpwhit;
    string wh, *key, loc;
    mapping gat, oldgat;

    if (!spell()) {
	write("What?\n");
	return 1;
    }
    if(!str) {
	notify_fail("Gate to who?\n");
	return 0;
    }

    gat = this_player()->query_property(GATE_PROP) || ([]);

    if (!sizeof(gat) && sizeof(oldgat = this_player()->query_gate())) {
      gat = oldgat;
      this_player()->set_property(GATE_PROP, gat);
      this_player()->set_gate( ([]) );
    }

    if (str=="list")
    {
	if (!sizeof(gat)) { write("You have not marked any locations to gate to."); return 1; }
	i = sizeof(gat);
	key = keys(gat);
	write("You have the following locations marked in your mind:");
	while(i--)
	{
	    write("[\""+key[i]+"\"] : "+gat[key[i]]->query_short());
	}
	return 1;
    }
    sscanf(str, "%s %s", wh, loc);
    if (wh=="mark" || str=="mark")
    {
	if (sizeof(gat) >= 5)
	{ 
	    write("Your mind can only remember so many places.");
	    return 1; 
	}
	if (sscanf(str, "%s %s", wh, loc) != 2)
	{ 
	    write("You need to specify a key to remember this location."); 
	    return 1;
	}
	if (gat[loc])
	{
	    write("You already have something marked at \""+loc+"\"");
	    return 1;
	} 
	if (environment(this_player())->query_property("no teleport"))
	    return notify_fail("You cannot mark this spot.\n");
	gat[loc] = file_name(environment(this_player()));
	this_player()->set_property(GATE_PROP, gat);
	write("You remember \""+loc+"\" for "+environment(this_player())->query_short());

	return 1;
    }
    if (wh == "unmark" || str == "unmark") {
	if (sscanf(str, "%s %s", wh, loc) != 2) { 
	    write("You need to specify the name of the location you want to unmark."); 
	    return 1;
	}
	if (gat[loc]) {
	    map_delete(gat, loc);
	    this_player()->set_property(GATE_PROP, gat);
	    write("You have forgotten "+loc+".");
	    return 1;
	} else {
	    write("You do not know of such a place.");
	    return 1;
	}
    }

    if (sscanf(str, "to %s", wh) != 1)
	wh = str;

    tp = find_player(wh);


    if((int)this_player()->query_mp() < 700) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }

    if (tp)
    {
	if (environment(tp)->query_property("no teleport")) fail = 1;
	if (wizardp(tp)) fail = 1;
	if(sscanf(file_name(environment(tp)),  "/d/guilds/%s", tmpwhit)==1) fail = 1;
    }
    if (environment(this_player())->query_property("no teleport")) fail = 1;   

    if ((!tp && !gat[wh]) || (fail && !wizardp(this_player())))    
    {
	write("The powers of the spell fail you.");
	this_player()->add_mp(-700);
	return 1;
    }

    if (tp) tp = environment(tp);

    if (!tp && gat[wh]) tp = get_object(gat[wh]);
    if(!tp) { write("That location is not in existance."); return 1; }

    if (tp->query_property("no teleport")) {
      message("info", "Your spell fails.", this_player());
      return 1;
    }
    this_player()->set_magic_round(2);
    this_player()->add_mp(-(600 + random(250)));
    this_player()->add_skill_points("conjuring", random(40));
    write("You mutter a few words in an effort to open a portal to another place.");
    say(this_player()->query_cap_name()+" closes "+this_player()->query_possessive()+" eyes and mutters a few words.");
    message("info", "%^MAGENTA%^%^BOLD%^A swirling mist of colours appear out of nowhere.%^RESET%^", environment(this_player()));
    message("info", "%^MAGENTA%^%^BOLD%^A swirling mist of colours appear out of nowhere.%^RESET%^", tp);
    call_out("openPortal", 4, this_player(), tp);

    return 1;
}

int openPortal(object ob, object tp)
{

    if (!ob || !tp) return 1;
    message("info", "%^BOLD%^%^BLUE%^A big boom is heard as a portal is formed in the room.%^RESET%^", environment(ob));
    message("info", "%^BOLD%^%^BLUE%^A big boom is heard as a portal is formed in the room.%^RESET%^", tp); 
    portal = new("/std/obj/portal");
    portal2 = new("/std/obj/portal");
    portal->set_destination(file_name(tp));
    portal2->set_destination(file_name(environment(ob)));
    portal->move(environment(ob));
    portal2->move(tp);
    return 1;
}
void help() {
    message("help",
      "Syntax: <gate [player]>\n"
      "        <gate [location]>\n"
      "        <gate mark [name]>\n"
      "        <gate unmark [name]>\n"
      "        <gate list>\n\n"
      "Allows the caster to open a portal between himself and another player, "
      "or to a specific location.",
      this_player());
}

int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_subclass() != "necromancer" && tp->query_subclass() != "wizard") return 0;
    if (tp->query_skill("conjuring") < 150) return 0;
    return 1;
}
