/*
** File: faceless.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid() );
    enable_commands();
    set("author", "nsd");
    set("short", "a faceless boy");
    set("long", @EndText
This boy was a genetic experiment that resulted in a living
depressing thing. He has no face at all. No eyes, no nose,
no mouth... just a blank space where there should be a face.
EndText);
    set("id", ({"boy", "faceless", "faceless boy"}) );
    set_size(5);
    set_name("the boy");
    set("gender", "male");
    set("race", "human");
    set("undead", 0);
    set("damage", ({ 8, 15 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "fist", "slash", "swing at", "attack" }) );
    set_verbs2( ({ "fists", "slashes", "swings at", "attacks" }) );
    set("natt", 2);
    set("chat_chance", 15);
    set("chat_output", ({
      "faceless boy . o O (This is just unfair...)\n",
      "faceless boy . o O (Why am I here in the first place?)\n",
      "faceless boy . o O (*sigh* can't even complain normally...) \n",
      "faceless boy . o O (Wonder what I seem to others...)\n",
      "faceless boy . o O (experiments are simply a living hell!)\n",
      "faceless boy . o O (Guess my destiny is to be odd forever and ever.)\n",
    }) );
    set_level(10);
    set("prevent_summon", 1);
}
/* EOF */
