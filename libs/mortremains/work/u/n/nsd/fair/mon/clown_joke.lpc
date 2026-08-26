/*
** File: clown_joke.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "a joker clown");

    set ("long", @EndText
A fat clown. This guy is wearing a violet wig of short
straight hair. He's got a rubber-blue nose, oversized
shoes, oversized red shorts with a green belt, and a
blue shirt. He's got a noisy bugler in his hand, and
a plastic flower on his shirt.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"clown"}) );
    set_size(6);
    set_name("clown");
    set("gender", "male");
    set("race", "human");
    set("prevent_summon",1);
    set("alive", 0 );
    set("damage", ({5,8}) );
    set("weapon_name", "annoying smile");
    set_verbs( ({ " sicken", "madden" }) ) ;
    set("natt",1);
    set("chat_chance", 30);
    set("chat_output", ({
      "The clown smiles a dorky way, and welcomes you.\n",
      "The clown points at the sky and says there's a pig flying.\n",
      "The clown gets a bugler from his red pocket.\n",
      "The clown makes you look at a plastic flower on his shirt,\n"+
      "and wets your face with it. This is so embarassing!\n",
      "The clown sounds his bugler loudly in your ear, causing you\n"+
      "to jump nervously. You're humilliated...\n",
      "The clown has the audacity of smiling at you.\n",
      "You wonder if there's someone who can bare so much stupidity.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("patrol", ({"north", "south", "east", "west"}) );
    set("wealth", 200);
    set_level(12);
    arm("?", "?");
    wear("?", "?");
}

void die() {
    say(wrap(
	"Congratulations!!!!! You have no Idea of how many kids\n"+
	"will be smiling after this death!!!!  :D\n"));
    ::die() ;
    return ;
}
/* End of File */
