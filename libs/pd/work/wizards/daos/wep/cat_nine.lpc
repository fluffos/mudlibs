#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
void create() {
    ::create();
    set_name("cat-o-nine");
    set_id( ({ "cat", "cat-o-nine" }) );
    set_type("flail");
    set_short("cat-o-nine tails");
    set_long("This weapon is constructed of a rope that has been attached to "
      "three knots of corded string.  The knots are attached to three small ropes "
      "designed to inflict serious pain to the victim.");
    set_weight(15);
    set_wc(10);
    set_hit( (: weapon_hit :) );	
}

int weapon_hit(object atk) {
    int result = 0;
    object tp = environment(this_object());
    for (int i = random(9); i > 0; i--) {
	message("combat", "%^BOLD%^YELLOW%^Your cat-o-nine bursts open on your opponent%^RESET%^.", tp);
	message("combat", tp->query_cap_name()+ "'s cat-o-nine "
	  "bursts open tearing the flesh from "+tp->query_possessive()+ " opponent.",
	  environment(tp), tp);
	result += (random(20)+this_player()->query_skill("flail")/5);
    }
    return result;
}
