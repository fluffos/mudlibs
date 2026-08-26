
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
A small turtle. He crawls around slowly.
Careful, he might bite you.
EndText
    );
    set("id" , ({"turtle"}) );
    set("stat/constitution", 12);
    set("wealth" , 250);
    set_size(1);
    set_name("turtle");
    set("gender", "neuter");
    set("race" , "amphibian");
    set("damage" , ({1,3}) );
    set("weapon_name" , "mouth");
    set_verbs( ({"bite at" , "chew on" , "snap at"}) );
    set ("chat_chance", 10);
    "The turtle stares at you blankly. \n",
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(10);
}
