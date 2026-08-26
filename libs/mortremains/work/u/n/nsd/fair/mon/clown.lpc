/*
** File: clown.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "a park clown");

    set ("long", @EndText
A boring looking clown, with the classic top bald and
few strands of orange hair. He's wearing a rubber-red
nose, oversized shoes, and a clown suit of pink and
yellow dots on a blue background. He has a balloon
in his hand.
EndText
    );   // EndText should be on a line all by itself, with NO SPACES
    set("id", ({"clown"}) );
    set_size(6);
    set_name("clown");
    set("gender", "male");
    set("race", "human");
    set("prevent_summon",1);
    set("undead", 0);
    set("damage", ({5,8}) );
    set("weapon_name", "annoying smile");
    set_verbs( ({ " sicken", "madden" }) ) ;
    set("natt",1);
    set("chat_chance", 30);
    set("chat_output", ({
      "The clown does his silly act of walking on his hands.\n",
      "The clown squeezes his rubber nose, making an annoying sound.\n",
      "The clown smiles a dorky way, and welcomes you.\n",
      "The clown says [to you]: Hi little friend!!!... \n"+
      "You feel like a moron.\n",
      "The clown offers you a pink balloon.\n",
      "The clown pats you on the head, and attempts to paste a\n"+
      "golden star on your forehead... Geez, how humilliating!\n",
      "You wonder if there's someone who can bare so much stupidity.\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set("patrol", ({"north", "south", "east", "west"}) );
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
