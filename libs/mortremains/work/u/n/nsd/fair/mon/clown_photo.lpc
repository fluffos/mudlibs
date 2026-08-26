/*
** File: clown_photo.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "a photographer clown");

    set ("long", @EndText
This guy is pathethic. He's got a toy camera from
a vending machine. He's wearing a black short wig
and a yellow hat with an oversized red flower on it.
He's got yellow pants, stripped shirt and socks,
and red shoes.
in his hand.
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
      "The clown annoys the hell out of you with his toy camera.\n"+
      "Your instant wish is to put the camera up his ass!!\n",
      "The clown says [to you]: Stop there please, and smile!\n",
      "The clown takes a toy camera from his polka-dots pocket.\n",
      "The clown says [to you]: Smile when you see the birdie!\n",
      "The clown pretends he takes a picture of you, making you\n"+
      "feel like a moron.\n",
      "You wonder if there's someone who can bare so much stupidity.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("wealth", 200);
    set_level(10);
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
