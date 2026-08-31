//	_gate.c
//	Mage ability
//	-- Seeker

#include <std.h>
inherit DAEMON;
inherit OBJECT;
//string *casters = ({});
object portal, portal2;

void create() {
 object::create();
   set_name("rune");
   set_short("%^BOLD%^%^CYAN%^a gla%^WHITE%^ss ru%^RESET%^n%^BOLD%^e%^RESET%^");
   set_long("A glass rune with many arcane symbols carved upon it.");
   set_weight(30);
   set_value(0);
   set_id(({ "rune", "glass rune", "glass" }));
   set_property("no steal", 1);
}

void init() {
 object::init();
   add_action("gate", "gate");
}

int query_auto_load() { return 1; }

int gate(string str) {
    object ob, tp;
    int i, skip, which, conjure, b, fail;
    string what, class, wh, *key, loc;
    mixed *arr;
    mapping gat;

    if (this_player()->query_name() != "chromium" && !wizardp(this_player()))
	return 0;
    if(!str) {
	notify_fail("Gate to who?\n");
	return 0;
    }
//    if (this_player()->query_disable()) return 1;
    if (str=="list")
    {
	gat = this_player()->query_gate();
	if (!gat) { write("You have not marked any locations to gate to."); return 1; }
	i = sizeof(gat);
	key = keys(gat);
	write("You have the following locations marked in your mind:");
	while(i--)
	{
	    write("%^CYAN%^[\""+key[i]+"\"] %^YELLOW%^: "
		"%^BOLD%^%^WHITE%^"+gat[key[i]]->query_short());
	}
	return 1;
    }
    sscanf(str, "%s %s", wh, loc);
    if (wh=="unmark"||str=="unmark")
    {
     if (!gat = this_player()->query_gate()) 
       { write("Theres nothing to unmark!"); return 1; }
     if (str=="unmark") { write("Unmark what?"); return 1; }
     if (!gat[loc]) { write("That location doesnt exist in your mind."); return 1; }     
     map_delete(gat, loc);
     this_player()->set_gate(gat);
     write("You have removed location, "+str+" from your memory.");
     return 1;
    }
    if (wh=="mark" || str=="mark")
    {
	gat = this_player()->query_gate();
/*	if (sizeof(gat) >= 5)
	{ 
	    write("Your mind can only remember so many places.");
	    return 1; 
	}*/
	if (sscanf(str, "%s %s", wh, loc)!=2)
	{ 
	    write("You need to specify a key to remember this location."); 
	    return 1;
	}
	if (gat[loc])
	{
	    write("You already have something marked at \""+loc+"\"");
	    return 1;
	} 
//	if (environment(this_player())->query_property("no teleport"))
//	    return notify_fail("You cannot mark this spot.\n");
	gat[loc] = file_name(environment(this_player()));
	this_player()->set_gate(gat);
	write("You remember \""+loc+"\" for "+environment(this_player())->query_short());

	return 1;
    }

    if (sscanf(str, "to %s", wh) != 1)
	wh = str;

    tp = find_player(wh);
    if (tp) if (tp->query_invis()) tp = 0;

/*    if((int)this_player()->query_mp() < 700) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }*/
    gat = this_player()->query_gate();
/*    if (tp)
    {
	if (environment(tp)->query_property("no teleport")) fail = 1;
	if (wizardp(tp)) fail = 1;
    }*/
    if (environment(this_player())->query_property("no teleport")) 
	write("%^CYAN%^With a wave of your hands, you negate a strong magical "
	  "interference.");

    if ((!tp && !gat[wh]) || (fail && !wizardp(this_player())))    
    {
	write("The powers of the spell fail you.");
	this_player()->add_mp(-699);
	return 1;
    }
    if (tp) tp = environment(tp);
    if (!tp && gat[wh]) tp = get_object(gat[wh]);
    if(!tp) { write("That location is not in existance."); return 1; }

    if (present("portal", environment(this_player())))   
      return notify_fail("There is too much magical interference to open a portal.\n");
/*
    if (member_array(this_player()->query_name(), casters)!=-1)
      return notify_fail("You cannot control more than one portal at once.\n");
    casters += ({ this_player()->query_name() });
*/
/*    this_player()->set_magic_round();
    this_player()->add_mp(-700);
    this_player()->add_skill_points("conjuring", random(40));*/
    write("You mutter a few words and wave your hand in an arcane way.");
    say(this_player()->query_cap_name()+" mutters a few words and waves "
	+this_player()->query_title_gender()+
	" hands in an arcane fasion.");
    call_out("openPortal", 6, this_player(), tp);
    this_player()->set_disable(1);
    return 1;
}

int openPortal(object ob, object tp)
{

    if (!ob || !tp) return 1;
//    casters -= ({ this_player()->query_name() });    
    message("info", "%^BOLD%^Reality is stretched until a mighty tearing and "
	"ripping sound is heard.", tp); 
    message("info", "%^BOLD%^Reality is stretched until a mighty tearing and "
        "ripping sound is heard.", environment(ob));  
    message("info", "%^YELLOW%^A flickering wormhole portal takes formation.",
	tp);
    message("info", "%^YELLOW%^A flickering wormhole portal takes formation.",
        environment(ob));
    portal = new("/wizards/inferno/portal");
    portal2 = new("/wizards/inferno/portal");
    portal->set_destination(file_name(tp));
    portal2->set_destination(file_name(environment(ob)));
    portal->move(environment(ob));
    portal2->move(tp);
    return 1;
}
