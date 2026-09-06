#include <areas.h>
/* obj/mirror.c
 * Mirror of self-knowledge
*/

#define TP this_player()

reset(arg) { }

init() {
//    add_action("enter", "enter");
}

short() { return "Large, shining silver mirror"; }

id(str) { return str == "mirror" || str == "large mirror"; }

long()
{
    if (TP->query_ghost())
    {
	write("You do see a reflection, but not yourself in it!\n");
	return 1;
    }
    if (TP->query_name() != "Someone")
	environment(TP)->tell_here(
	  TP->query_name() + " looks at the mirror.",
	  ({ TP }));
    TP->tell_me("You see only swirling mist...\nA hollow voice whispers:\n");
    TP->tell_me("''Your armour is " + arm_adj(TP->query_ac()) +
      "\n and your weapon is " + weap_adj(TP->query_wc()) +
      ".''\n");
    TP->tell_me("You see other worlds inside the mirror...\n");
}

query_weight() { return 0; }
query_value() { return 0; }
get() { return 0; }
drop() { return 0; } /* Can be dropped if someone has acquired it... :-) */

/* The ranks are not revealed - they will have to experiment.
 * Players will not automatically know which rank is the best here.
 */
weap_adj(str) {
    int val;

    val = str;
    if (val <= 0) return "very bad";
    if (val > 0 && val < 6) return "poor";
    if (val > 5 && val < 9) return "average";
    if (val > 8 && val < 12) return "quite good";
    if (val > 11 && val < 16) return "good";
    if (val > 15 && val < 19) return "very good";
    if (val == 19) return "excellent";
    if (val == 20) return "superb";
    if (val < 22) return "a Highly Magical one";
    if (val < 24) return "a Legendary one";
    if (val < 25) return "An Artifact";

    return "An *Artifact* !!!";
}

arm_adj(str) {
    int val;

    val = str;
    if (val <= 2) return "very bad";
    if (val < 4) return "bad";
    if (val < 6) return "poor";
    if (val < 8) return "below average";
    if (val < 10) return "average";
    if (val < 12) return "above average";
    if (val < 14) return "quite good";
    if (val < 15) return "good";
    if (val < 16) return "very good";
    if (val < 17) return "excellent";
    if (val < 18) return "superb";
    if (val < 19) return "Legendary";
    return "Invincible";
}

enter(str) {
    string *places;

    if (!id(str)) return 0;

    write("Ok. You step into the mirror...\n");
    say(TP->query_name() + " enters the mirror.\n");

    places = ({
#ifdef AREA_ORCTOWN
      AREA_ORCTOWN+"lvl3/pit_cave",
      AREA_ORCTOWN+"lvl3/pit_cave",
      AREA_ORCTOWN + "lvl2/mine1",
#endif
#ifdef AREA_SEWERS
      AREA_SEWERS + "lvl2/wide9",
#endif
#ifdef AREA_FARAWAY
      AREA_FARAWAY+"mountain/glacier6"
#endif
    });

    TP->move_player("X#" + places[random(sizeof(places))]);
    return 1;
}
