#include <mudlib.h>
inherit WEAPON;

void create() {
    seteuid(getuid());
    set("short", "an elven sword");
    set("long", @Endtext
A beautifully made elven sword, seeming to have some sort of dark magic
about it.
Endtext
    );
    set("id", ({ "sword", "elven sword", "elvensword" }) );
    set_weapon_type("sword/long");
    set_bonus(1);
    set("name", "sword");
    set_verbs( ({ "attack" , "swing at" , "slice at" }) );
    set("nosecond",0);
    set("value", 150);
    set("wield_func" , "glow");
    set("unwield_func" , "noglow");
}   
void glow() {
    if(environment(TO) && environment(environment(TO))) {
	write("The sword begins to grow a soft green in your hand.\n");
	say("The sword begins to glow a soft green in
"+possessive(this_player()->query("gender"))+" hand.\n") ;
        set ("light", 1) ;
}
}

void noglow() {
        write ("The sword stops glowing.\n") ;
        say ("It ceases to glow.\n") ;
        set("light", 0) ;
}
