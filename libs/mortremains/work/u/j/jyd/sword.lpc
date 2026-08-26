#include <mudlib.h>
inherit WEAPON;

void create() {
    set("short", "An elven sword");
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
    set("value", 150);
    set("wield_func" , "glow");
    set("unwield_func" , "noglow");
}   
void glow() {
    write("The sword begins to glow in your hand.\n");
    say ("The sword begins to glow in
"+possessive(this_player()->query("gender"))+" hand.\n") ;
        set ("light", 1) ;
}

void noglow() {
        write ("The sword stops glowing.\n") ;
        say ("It ceases to glow.\n") ;
        set("light", 0) ;
}
