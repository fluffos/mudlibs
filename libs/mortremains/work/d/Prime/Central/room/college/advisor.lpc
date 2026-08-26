// Cyanide - 31 June 1999

inherit ROOM;

#include "central.h"

string suggest_skill(object);
string suggest_class(object);

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set("short", "Academic Advising");
    set("long", wrap(
	"You are in the Academic Advising office. If you aren't quite "+
	"sure what you should do with your skills, or aren't certain "+
	"what kind of career would best suit you, just type <advise>, "+
	"and a counselor will see you."
      ) );
    set("exits", ([
      "south" : COLLEGE("campus"),
    ]) );
    set("item_desc", ([
    ]) );
}

void init() {
    add_action("advise", "advise");
}

int advise() {
    string str = "";

    if (wizardp(TP)) {
	write("You're an immortal! Go code something!\n");
	return 1;
    }

    if(!TP->query_level()) {
	str = suggest_class(TP);
    } else {
	if (TP->query("nwp_free")) {
	    str = suggest_skill(TP);
	}
    }

    if (!str ||!strlen(str)) str = "The advisor says: I have no "+
	"advice for you at this time.";

    write( wrap(str) );

    return 1;
}

string suggest_class( object player ) {
    return("The advisor is currently not able to make suggestions "+
      "regarding class. You may wish to ask Cyanide or Chronos if "+
      "you are truly stumped.");
}

string suggest_skill( object player ) {
    string klass, str, *key_skills;
    mapping best_skills, min_levels;
    int *val_skills, sz, i, best_num, lvl;

    min_levels = ([ "All Around Attack":15 , "Death Blow":20, 
    "Iron Will" : 15, "Smite" : 20, "Eminance" : 15, "Evasion" : 15,
    "Nondetection" : 20, "Talisman" : 5, "Signature Spell" : 30,
    "Signature Item" : 27
  ]);

    klass = player->query_class();

    // Best_skills is a mapping, where the value is the subjective 
    // practical value of the skill to the average player.

    best_skills = ([ "Monster Lore" : 90, "Awareness" : 40 ]);

    lvl = player->query_level(klass);

    switch(klass) {
    case "wizard" :
	best_skills += ([ 
	"Arcanology" : 50, 
	"Thaumaturgy" : 65, 
	"Thaumaturgy" : 70 
      ]); break;
    case "warrior" :
	best_skills += ([
	"Ambidexterity" : 99, 
	"Iron Will" : 80, 
      ]); break;
    case "priest" :
	best_skills += ([
	"Healing":2, 
	"Iron Will":2,
	"Eminence":1 ,
	"Loan Health":1,
	"Talisman":2 , 
	"Smite":2 
      ]); break;
    case "rogue" :
	best_skills += ([
	"Ambidexterity": 70,
	"Ventriloquism":10 , 
	"Evasion":99 ,
	"Nondetection":90
      ]); break;
    }

    // A very simple, brute-force method.

    key_skills = keys(best_skills);
    val_skills = values(best_skills);
    best_num = 0;
    sz = sizeof(val_skills);

    for (i = 0; i<sz; i++) {
	if (min_levels[key_skills[i]] > lvl) continue;
	if (player->query_skill(key_skills[i])) continue;

	if (val_skills[i] > best_num) {
	    str = key_skills[i];
	    best_num = val_skills[i];
	}
    }

    if (str && strlen(str))
	str = "As a non-weapon skill, you are advised to learn the \""+str+
	"\" skill. \nThe advisor cannot suggest weapon skills at this time.";

    return str;
}

/* EOF */
