/*
File: spider.c
Author: Feldegast
Date: 2-24-02
Description:
  A little bugger, no xp worth, summoned by the spiderlady
in the spider caves in Caladon.
*/
#include "defs.h"

inherit "/obj/monster";

object master;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("spider");
  set_short("Small Spider");
  set_long(
    "This is a small, hairy spider.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(1);
  set_wc(12);
  set_ac(6);
  set_hp(50);
  set_al(-50);
  set_a_chat_chance(4);
  load_a_chat("The spider bites!\n");
}

heart_beat()
{
  ::heart_beat();
  if(!master || !attacker_ob || !random(30))
  {
    say("The spider skitters off.\n");
    destruct(this_object());
  }
}

set_master(ob) { master=ob; }

calculate_worth() { return 1; }
