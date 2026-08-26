
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a piranha");
    set("prevent_summon" , 1);
    set ("long", @EndText
A small fish, with a viscious bite. It's mouth is 
filled with tons of tiny, razor-sharp teeth.
EndText
    );
    set("id" , ({"piranha" , "fish"}) );
    set("stat/constitution", 12);
    set_size(2);
    set_name("piranha");
    set("gender", "neuter");
    set("race" , "fish");
    set("damage" , ({3,6}) );
    set("weapon_name" , "teeth");
    set_verbs( ({"rip" , "bite" , "tear at"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(16);
}
