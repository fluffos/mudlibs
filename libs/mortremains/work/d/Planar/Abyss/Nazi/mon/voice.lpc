/*
**File: voice.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "NSD");
    set("short", " ");
    set ("long", @EndText
EndText
    );
    set("id", ({ "child", "girl" }) );
    set_size(4);
    set_name("girl");
    set("gender", "female");
    set("race", "ghost");
    set("undead", 1);
    set("damage", ({0, 0}) );
    set("damage_type", "cold");
    set("weapon_name", "?");
    set("natt", 2);
    set_verbs( ({"?"}) );
    set("chat_chance", 30);
    set ("chat_output", ({
      "I can see the light!!!\n",
      "I'm so emotioned, I want to cry!!!\n",
      "Thank you very much, I knew you could do it!!!\n",
      "I'm free, I'm free.. WOO WOO!!!\n",
      "Because you liberated me, I must reward you...\n",
      "This is the best gift I have had in centuries...\n",
      "Your nightmare has ended.\n",
      "Now you can 'wake up'.\n",
      "Come on, 'wake up'.\n",
      "I free you too. 'wake up'...\n",
    }) );

    // These are the monsters chats when in combat.
    set ("att_chat_output", ({
    }) );
    set_level(0);
    set("no_attack", 1);
    set("prevent_summon", 1);

}

/* End of File */
