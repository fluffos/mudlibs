
#include <mudlib.h>

inherit WEAPON ;

void create() {
    seteuid(getuid());
    set("id",({"sword","sword of sin"}));
    set("short", "Sword of Sin");
    set("long","This is a special sword created for the Sinner Guild by \n" +
      "their fearless leader Retsam! It looks very powerful.\n");
    set_weapon_type("sword/two-handed");
    set ("nosecond",1) ;
    set_bonus(4);
    set("damage",({6,14}));
    set("light",1);
    set("name","sword");
    set("value",1450);
    set_verbs(({"impale","slice","attack","dice"}));
}
