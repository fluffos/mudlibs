#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Sword of the Void");
    set("long", @Endtext
This sword has a simple hilt made of interlocking strands of steel. The
blade however, has no visible substance, as your hand passes through it, a
distinct chill can be felt throughout your body.
Endtext
    );
    set("id", ({ "sword", "sword of the void" }) );
    set_weapon_type("sword/long");
    set("name", "sword");
    set_verbs( ({ "attack" , "swing at" , "thrust at" }) );
    set("nosecond",1);         
    set_bonus(1);
    set("value", 1000);

}   
