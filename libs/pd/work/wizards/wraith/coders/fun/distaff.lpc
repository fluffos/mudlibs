inherit "/std/weapon";

create() {
        ::create();

        set_short ("distaff");
        set_name ("Clotho's Distaff");
        set_id (({"Distaff", "staff","distaff"}));
        set_long ("Clotho's Distaff\n"
"This weapon is one of the most powerful creative forces when in the right hands.  "
"Clotho uses the distaff to hold the spun thread of life.  It is a staff with two forks "
"on one end.");
        set_weight (3);
        set_curr_value ("gold" , (25));
        set_wc (2+random(3));
        set_ac (2);
        set_type ("blunt");
        set_wield ("You feel pain as you begin wielding a weapon meant to start life.");
        set_unwield ("Your pain lessens and fades as you unwield the distaff.");


set_heart_beat(1);

}
int query_auto_load () {if (this_player()->query_gender() == "female") return 1;}
void heart_beat() {
if(this_object()->query_wielded())
if(this_object()->query_wielded()->query_gender() == "male")
this_object()->query_wielded()->add_hp(-200);
}

