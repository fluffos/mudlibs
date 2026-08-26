
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a turtle");
    set("prevent_summon" , 1);
    set ("long", @EndText
A huge sea turtle. His shell is about the size of a manhole
cover. His huge feet move about slowly.
EndText
    );
    set("id" , ({"turtle"}) );
    set("stat/constitution", 12);
    set_size(3);
    set_name("turtle");
    set("gender", "neuter");
    set("race" , "amphibian");
    set("wealth" , 320);
    set("damage" , ({2,5}) );
    set("weapon_name" , "feet");
    set_verbs( ({"swipe at" , "slash at" , "hit"}) );
    set ("chat_chance", 10);
    "The turtle stares at you blankly. \n",
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(18);
}
