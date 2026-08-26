#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

set("author", "sophia");
set("short", "a shady character");

set( "long", wrap(
"This guy looks like a weak beanpole but the comfort "+
"he displays in his grimy clothes makes you think there may "+
"be more to him than first glance reveals. "
) );

set("id", ({"shady character", "monster" }) );

set_size(6);

set_name("shadyguy") ;

set("gender", "male");

set("race", "human");

set("undead", 0);

set("damage", ({1,4 }) );

set("weapon_name", "fists") ;

set_verbs( ({ "attack", "punch", "swing at" }) );

set_verbs2( ({ "punches at", "swings at", "attacks" }) );

    set("natt", 1);

    set ("chat_chance", 10);

    set ("chat_output", ({
"This guy thinks your boots would fit him nicely.\n",
    }) );

    set ("att_chat_output", ({
"Die already will ya? My train is leaving.\n",
    }) );

    set_level(1);

arm("/doc/examples/knife") ;
}
