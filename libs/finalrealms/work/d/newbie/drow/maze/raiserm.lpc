inherit "/std/raiseroom";
#include "path.h";

object helper;

int query_underground() { return 1; }

void setup() {
    set_short("Realm of the Drow:  Priestess Quarters");
    set_long("\n   Realm of the Drow:  Priestess Quarters.\n\n"
      "     These are the quarters that the "
      "priestess of Cyrcia keeps in the great maze, to aid the young "
      "followers of Cyrcia in their time of need.  It is here that "
      "you can come to get raised after getting your self carelessly killed "
      "or otherwise dead.  The room has no furnishings and no "
      "decorations of any kind, mainly because there is no reason "
      "attempting to impress someone who is dead."
      "\n\n");
    set_light(10);
    add_sign("________________________________________\n"
      "|                                      |\n"
      "|     Priestess of Cyrcia Raiseroom    |\n"
      "|                                      |\n"
      "|  Type raise <ghost> to raise someone |\n"
      "|______________________________________|\n\n");

    add_exit("north", MAZE+"maze", "corridor");
    add_exit("south",MAZE+"maze10","corridor");
    add_exit("northeast", MAZE+"guild", "corridor");
}

void reset() {
    if(!helper) {
	helper = clone_object("/baseobs/monsters/healer");
	helper->move(this_object());
    }
    helper->set_name("Drow Priestess");
    helper->set_max_hp(600);
    helper->set_gender(2);
    helper->set_race("drow");
    helper->set_level(45+random(10));
    helper->set_kill_xp(5);
    helper->set_short("Priestess");
    helper->add_alias("priestess");
    helper->set_long("The Drow female that stands before you is a "
      "priestess of the Drow god Cyrcia.  She oversees all that "
      "come here seeking aid, and even brings those back from beyond who "
      "are beyond all other help.\n");
    ::reset();
}

void dest_me() {
    if (helper) helper->dest_me();
    ::dest_me();
}

