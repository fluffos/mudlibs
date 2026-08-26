/*
** File: clown_jack.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "Jack-in-the-box");

    set ("long", @EndText
Jack in the box is a toy.  But a clown finally!
This one is possessed by the devil.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"jack"}) );
    set_size(3);
    set_name("jack");
    set("gender", "neuter");
    set("race", "toy");
    set("lore_type", "arcanology");
    set("damage", ({8,16}) );
    set("weapon_name", "hard wooden head");
    set("damage_type", "bludgeoning");
    set_verbs( ({ "hit", "smack", "hurt", "swing at" }) ) ;
    set("chat_chance", 0);
    set("chat_output", ({
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
      "Jack smashes your eye with it's hard wooden head...\n",
      "Jack brutally smacks you on the forehead!\n",
      "Jack is evil.....\n",
    }) );
    set("stat/strength", 16);
    set("aggressive", 1);
    set("wealth", 200);
    set_level(20);
    arm("?", "?");
    wear("?", "?");
}
void die() {
    say(wrap(
	"The springs get exposed out of Jack's body, and the head\n"+
	"smashes on the floor. Jack's a broken toy now... :-(\n"));
    ::die() ;
    return 1;
}
/* End of File */
