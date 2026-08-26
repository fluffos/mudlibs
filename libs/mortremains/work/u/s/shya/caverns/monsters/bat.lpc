

#include <mudlib.h>
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set("author", "shya");
    set ("short", "giant bat");
    set ("long", "A giant bat with huge fangs.\n");
    set ("id", ({"bat"}) );
    set_name("bat");
    set ("gender", "male") ;
    set ("race", "bat");
    enable_commands() ;
    set_living_name("bat");
    set ("stat/constitution", 10);
    set ("stat/strength", 3);
    set ("base_ac", -1);
    set ("armor_class", -2);
    set ("CLASS", "");
    set ("damage", ({ 2,4 }) ) ;
    set ("weapon_name", "fangs");
    set_verbs( ({ "bites at" }) ) ;
    set ("weap_resist", 9);
    set("resist_type", ([  ]));
    set("magic_resist", 0);
    set_size(3);
    set_level(4);
    set ("moving", 1);
    set ("speed", 10);
    set ("chat_chance", 5);
    set ("chat_output", ({
         "A bat lets out a loud screech.\n",
       }) );
    set ("att_chat_output", ({
         "A bat swoops at your head and misses.\n",
       }) );
}
