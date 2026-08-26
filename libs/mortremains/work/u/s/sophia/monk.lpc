#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

set("author", "sophia");
set ("short", "Poker Playing Monk");

set( "long", wrap(
"This guy is a monk? Sheesh, poker playing instead of "+
"praying; perhaps he should be taught a lesson? "
) );

set("id", ({"monk", "monster" }) );

set_size(6);

set_name("brother aries");

set("gender", "male");

set("race", "human");

set("undead", 0);

set("damage", ({8,15 }) );

set("weapon_name", "fists") ;

set_verbs( ({ "attack", "punch", "swing at" }) );

set_verbs2( ({ "punches at", "swings at", "attacks" }) );

    set("natt", 1);

set ("chat_chance", 3);

    set ("chat_output", ({
"Monk shouts: Umm let's not fight. Just ante up.\n"
"Monk shouts: let's teach him a lesson brothers!\n",
    }) );

    set ("att_chat_output", ({
"Monk asks : Some help here brothers?.\n",
    }) );

    set_level(1);

}
