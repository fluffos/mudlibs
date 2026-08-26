
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author" , "herself");
    set("short" , "a gandarewa");
    set("prevent_summon" , 1);
    set ("long", @EndText
An evil looking demon. His face is twisted and scarred.
Protruding from his head are hideous looking horns. 
EndText
    );
    set("id" , ({"gandarewa" , "ganderewa" , "gand"}) );
    set_size(7);
    set_name("gandarewa");
    set("gender", "neuter");
    set("race" , "demon");
    set("lore_type" , "demon");
    set("damage" , ({3,5}) );
    set("weapon_name" , "claws");
    set_verbs( ({"slash at" , "claw at" , "rip" , "tear into"}) );
    set_verbs2( ({"slashes at" , "claws at" , "rips" , "tears into"}) );
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(random(20)+5);
}
