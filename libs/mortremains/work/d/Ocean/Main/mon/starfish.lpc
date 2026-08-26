
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a starfish");
    set("prevent_summon" , 1);
    set ("long", @EndText
This is a small starfish. As it's name suggests, it looks 
like a star. 
EndText
    );
    set("id" , ({"starfish" , "fish"}) );
    set("stat/constitution", 12);
    set("wealth" , 300);
    set_size(1);
    set_name("starfish");
    set("gender", "neuter");
    set("race" , "shellfish");
    set("damage" , ({1, 2}) );
    set("weapon_name" , "suction cups");
    set_verbs( ({"suck on" , "leach on" }) );
    set_verbs2( ({"sucks on" , "leaches on" }) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(10);
}
