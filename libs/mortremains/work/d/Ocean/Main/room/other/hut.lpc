/*
* FILE: hut.c
* DESC: The home of Master Kyrnad
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

int timer = 0;
int start_kill();
int train_player();

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "Kyrnad's hut" );
  set( "long", @EndText
You stand in the home of Kyrnad. The hut is set up much like
a dojo. Ancient scrolls line the walls.
EndText
  );

 set("item_desc", ([
      "scrolls" : "Ancient scrolls written in some unknown language.\n",
 ]));

 set( "exits", ([
      "out" : O_ROOM+"path1",
 ]));

 set("objects", ([
     "kyrnad" : O_MON+"kyrnad",
 ]));
 reset();
}

void init()
{
  add_action("start_kill", "kill");
  add_action("train_player", "train");
}

int start_kill()
{
  object mon;
  string gender;

  if(this_player()->query("gender") == "male") gender = "him";
  if(this_player()->query("gender") == "female") gender = "her";
  if(this_player()->query("gender") == "neuter") gender = "it";

  if(present("kyrnad"), this_object())
  {
    switch(timer)
    {
      case 0 :
	write("Kyrnad says: I don't think you want to push me.\nI'm a better friend than an enemy.\n");
	timer++;
	return 1;
      break;
      case 1 :
        write("Kyrnad grabs you by the throat and begins to squeeze. . .\n\n");
	write("Kyrnad says: I'm warning you. Even I have my limits\n");
	this_player()->receive_damage(this_player()->query("hit_points") /  2, "crushing");
	timer++;
        return 1;
      break;
      case 2 :
       write("Kyrnad becomes enraged floors you with a massive thrust kick.\n");
       say("Kyrnad becomes enraged with "+this_player()->query("cap_name")+" and floors "+gender+" with a massive thrust kick.\n");
       this_player()->receive_damage(this_player()->query("hit_points") -  1, "crushing");
       timer = 0;
        return 1;
      break;
    }
  }
  else
  {
    return 0;
  }
}

int train_player()
{
  object mon, tp;
  int pexp, dif;

  mon = present("kyrnad", this_object());
  tp = this_player();
  pexp = (int)tp->query("experience");

  if(pexp < 200000) 
  {
     dif = 200000 - pexp;
     write("You are far too inexperienced.\n Come back once you've gained "+dif+" more experience.\n"); 
     return 1;
  }
  if(tp->query("killed_gzhall"))
  {
    write("Ok...I'll train you.\n");  
    write("A trap door opens and you fall through.\n\n\n");
    tp->move_player(O_ROOM+"training", "SNEAK", "down");
  }
  else
  {
    write("Before I train you, you must kill Gzhall!\n");
  }
  return 1;

}
