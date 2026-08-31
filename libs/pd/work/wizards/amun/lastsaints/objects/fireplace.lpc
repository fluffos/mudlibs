#include <std.h>
inherit OBJECT;
int lit, fuel, light_time;
void light(int time);
void init() {
    ::init();
    add_action("get_it", "get");
    add_action("goWarm", "warm");
    add_action("extinguish","extinguish");
}
void create() {
    ::create();
    set_name("fire");
    set_id( ({ "fire", "a fire", "the fire", "campfire" }) );
    set_short("%^BOLD%^%^MAGENTA%^A %^BLACK%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^c%^e");
    set_long("%^BOLD%^%^WHITE%^This cobblestone %^BLACK%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^ is placed at the foot of the king-sized bed.  It stretches 8 feet wide and about 20 feet high the wall allowing the %^RESET%^%^RED%^fl%^BOLD%^%^RED%^a%^RESET%^%^RED%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^ to stretch far and wide.  Laid in front of the %^BLACK%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^  is a white bear skin rug that was made by Carina. The crackling %^RESET%^%^RED%^f%^BOLD%^%^RED%^i%^RESET%^%^RED%^r%^BOLD%^%^RED%^e%^WHITE%^ looks romantic as it dances across the walls.  You should warm yourself beside it.");
    set_property("no get all", 1);
    set_prevent_get( "%^RED%^The fire is to hot!%^RESET%^\n" );
    fuel = 3000;
    lit = 1;
    //    call_out("go_dark", fuel);
}
void light(int time)
{
    light_time = time;
    environment(this_object())->set_property("light", 2);
    call_out("go_dark", 5);
}
int get_it(string str) {
    if (present(str, environment(this_player())) != this_object())
	return 0;
    write("The fire %^BOLD%^%^RED%^burns%^RESET%^ you!\n");
    say(this_player()->query_cap_name()+" burns "+this_player()->query_possessive()+" hand in the fire!",this_player());
    this_player()->add_hp(-(random(20)));
    return 1;
}
int goWarm(string str) {
    string gen;
    if ((string)this_player()->query_gender() == "male") gen = "him";
    else
	gen = "her";
    if (this_player()->query_disable())
    {
	write("You can not get closer to the fire.");
	return 1;
    }

    this_player()->set_disable();
    this_player()->heal(10);

    write("%^RED%^%^BOLD%^The warmth from the fire makes you feel better.");
    say(this_player()->query_cap_name()+" warms "+gen+"self by the fire.", this_player());
    return 1;
}
int extinguish(string str) {
    if(!id(str)) {
	notify_fail("Extinguish what?\n");
	return 0;
    }
    if(!lit) {
	notify_fail("The fire is not lit!\n");
	return 0;
    }
    write("You extinguish the fire.\n");
    say(this_player()->query_cap_name()+" extinguishes the fire.\n",
      this_player());
    environment(this_object())->set_property("light", -2);
    fuel -= (light_time - time());
    remove_call_out("go_dark");
    lit = 0;
    this_object()->remove();
    return 1;
}

void go_dark() {
    //    environment(this_object())->set_property("light", -2);
    fuel = 0;

    tell_room(environment(this_object()), "The fire burns out.");
    lit = 0;
    this_object()->remove();
}
int query_lit() { return lit; }
int query_fuel() { return fuel; }
