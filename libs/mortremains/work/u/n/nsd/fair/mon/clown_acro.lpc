/*
** File: clown_acro.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "A street clown");

    set ("long", @EndText
A silly clown dressed in oversized clown suit, half stripes
and half dots. He's got a painted white-and-red big smile.
He's wearing a stupid conic hat that ends in a puffed
yellow ball, and a ridiculous green wig.
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
    set("chat_chance", 10);
    set("chat_output", ({
      "The clown does his silly act of walking on his hands.\n",
      "The clown smiles a dorky way, and welcomes you.\n",
      "The clown says [to you]: Hi little friend!!!... \n"+
      "You feel like a moron.\n",
      "The clown brags to you about the way he can manage the\n"+
      "bottles he throws and catch in the air.\n",
      "The clown gives you an unsolicited smile, turning you\n"+
      "into the center of attenttion. How embarassing!\n",
      "You wonder if there's someone who can bare so much stupidity.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("patrol", ({"north", "south", "east", "west"}) );
    set_level(10);
    arm("?", "?");
    wear("?", "?");
    set("wealth", 250);
}

void die() {
    say(wrap(
	"Congratulations!!!!! You have no Idea of how many kids\n"+
	"will be smiling after this death!!!!  :D\n"));
    ::die() ;
    return ;
}
/* End of File */
