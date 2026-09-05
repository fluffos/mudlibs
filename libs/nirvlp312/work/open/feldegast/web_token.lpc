/*
File: webtoken.c
Author: Feldegast
Date: 2-24-02
Description:
  A counter for a web spell cast by the spiders in the
spider cave in Caladon.  It will reduce the player's
weapon class, and hinder their movement.  Eventually,
it will wear off.
*/
#include "/players/feldegast/defines.h"

int untangled;

void reset(int arg)
{
  if(arg) return;
  call_out("struggle", 10+random(20));
  call_out("untangle", 20);
  call_out("end", 300 + random(300));
}

string extra_look()
{
  return (string)environment()->query_name()+" is stuck in a web";
}

int id(string str)
{
  return str == "generic_wc_bonus" || str == "web_token";
}

int gen_wc_bonus()
{
  if(!random(5))
  {
    if(environment()->query_weapon())
      tell_object(environment(), "You tangle your weapon in the sticky webbing.\n");
    else
      tell_object(environment(), "You tangle yourself in the sticky webbing.\n");
  }
  return -3;
}

void init()
{
  add_action("cmd_block", "north");
  add_action("cmd_block", "west");
  add_action("cmd_block", "east");
  add_action("cmd_block", "south");
  add_action("cmd_block", "northwest");
  add_action("cmd_block", "northeast");
  add_action("cmd_block", "southwest");
  add_action("cmd_block", "southeast");
  add_action("cmd_block", "up");
  add_action("cmd_block", "down");
}

int cmd_block(string str)
{
  if(!untangled)
  {
    write(BOLD+"YOU ARE TANGLED IN WEBS!\n"+NORM);
    return 1;
  }
  else
    return 0;
}

void untangle()
{
  tell_object(environment(), BOLD+"\nYou manage to untangle your legs from the webs so that you can move.\n\n"+NORM);
  untangled=1;
}

void struggle()
{
  tell_object(environment(), "You struggle with the webbing that entangles you.\n");
  call_out("struggle", 10+random(20));
}

void end()
{
  tell_object(environment(), BOLD+"\nYou free yourself from the spider webs.\n\n"+NORM);
  destruct(this_object());
}

query_auto_load() { return "/players/feldegast/obj/webtoken.c:"; }

drop() {
  if(environment()->is_dieing()) destruct(this_object());
  else return 1;
}
