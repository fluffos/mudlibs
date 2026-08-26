/*
** File: snakegirl.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid() );
    enable_commands();
    set("author", "nsd");
    set("short", "the snake woman");
    set("long", @EndText
Only a misserable woman that had the disgrace of being born
with reptile skin. She's been rejected all her life because
of it. Finally she got this job as an oddity of the freak show.
She doesn't look conformed with it...
EndText);
    set("id", ({"woman", "snake", "snake woman"}) );
    set_size(6);
    set_name("snake woman");
    set("gender", "female");
    set("race", "'human'");
    set("undead", 0);
    set("damage", ({ 8, 15 }) );
    set_verbs( ({ "fist", "slash", "swing at", "attack" }) );
    set_verbs2( ({ "fists", "slashes", "swings at", "attacks" }) );
    set("natt", 2);
    set("chat_chance", 15);
    set("chat_output", ({
      "The woman complains...\n",
      "The woman starts to whine about her rejection.\n",
      "The woman says [to you]: I wish I was as normal as you are..\n",
      "The woman sobs uncontrolably...\n",
      "The woman says [to you]: being a freak is not exciting at all.\n",
      "The woman damns scientific experiments a thousand times!\n",
      "The woman stares at you with deep sadness.\n",
      "The woman turns her back on you, and starts to cry...\n",
    }) );
    set_level(10);
    set("prevent_summon", 1);
}
/* EOF */
