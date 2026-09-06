/*
  March 31, 1998 - Kieve

  Created for Shaka -- from Minerva

GIFT       100,000
EMOTES      40,000
FEELINGS    20,000
	  ~~~~~~~~
Total      160,000  -- Paid by Minerva
*/
#include <treasure.h>

#define TP      this_player()
#define ENV(x)  environment(x)
#define TN          TP->query_name()
#define HIS         TP->query_possessive()

void create_treasure() {
    set_name("GI Joe doll");
    set_id( ({ "doll", "gi joe", "joe" }) );
    set_short("GI Joe with Kung Foo Grip");
    set_long("This is a little man doll in fatigues. It has a small plastic "+
      "gun in its holster. His face looks very molded, and has even got "+
      "a plastic seam through his ears. The doll is 6 inches of pure man."+
      "\nHe is a loving gift from his Auntie Minerva.");
    set_weight(0);
    set_value(0);
}

void init_treasure() {
    add_action("do_chop", "chop");
    add_action("do_dress", "dress");
}

status do_chop(string args) {
    object plr;
    if(!args) args = "";
    if(!plr = present(args, ENV(TP)) ) {
	TP->tell_me("You hold up your GI Joe, and make karate choping "+
	  "motions at everyone.");
	ENV(TP)->tell_here(TN+" holds up "+HIS+" GI Joe, and starts "+
	  "making choping motions at everyone.", TP);
	return 1;
    }
    if(random(2)) {
	TP->tell_me("You hold up your GI Joe, and make karate choping "+
	  "motions at "+plr->query_name()+".");
	plr->tell_me(TN+" holds up "+HIS+" GI Joe, and makes karate "+
	  "choping motions at you.");
	ENV(TP)->tell_here(TN+" holds up "+HIS+" GI Joe, and makes karate "+
	  "choping motions at "+plr->query_name()+".", ({ TP, plr }) );
    }
    else {
	TP->tell_me("You chop "+plr->query_name()+" to pieces with your GI "+
	  "Joe's Kung Fu chopping action!");
	plr->tell_me(TN+" chops you to pieces with "+HIS+" GI Joe's Kung "+
	  "Fu chopping action!");
	ENV(TP)->tell_here(TN+" chops "+plr->query_name()+" to pieces with "+
	  HIS+" GI Joe's Kung Fu chopping action!", ({ TP, plr }));
    }
    return 1;
}

status do_dress(string args) {
    if(!args || !id(args))
	return notify_fail("Do you mean 'dress doll'?\n"), 0;

    TP->tell_me("You skillfully undress your GI Joe, and dress it in "+
      "manly combat gear.");
    ENV(TP)->tell_here(TN+" skillfully undresses "+HIS+" GI Joe, and "+
      "dresses it in Barbie's ball gown.", TP);
    return 1;
}

void catch_show(object plr, object showed) {
    showed->tell_me(query_long());
}

int catch_feeling(string verb, string arg) {
    return 1;
}

int get() { return 1; }
int drop() { return 1; }
int query_prevent_steal() { return 1; }

string query_auto_load() {
    string fname;
    sscanf(object_name(this_object()), "%s#%~d", fname);
    return fname+":";
}
