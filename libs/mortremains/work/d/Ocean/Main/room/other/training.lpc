/*
* FILE: trans.c
* DESC: This room is where kyrnad takes his pupils to train
*
*/
#include <mudlib.h>
#include "ocean.h"
#include "../obj/karate.h"

inherit ROOM;

#define CFILE                   O_DATA+"kungfu0"+KLEVEL+".txt"
#define DELAY                   3 

int timer, first = 0;
string *train_messages;

int enter_scene();

void init() 
{
 // add_action("com_block", "", 1);
  write("\n");
  call_out("enter_scene", 3);
}

void create()
{
  ::create();
  seteuid( getuid() );
  set("author", "gasman");

  set("short", "Kyrnad's training room");
  set("long", wrap(
"You are in Kyrnad's training room here you will be taught "+
"Kung Fu by one of the most diciplined masters to ever live."
  ));
  set("light", 1);

}

int com_block(string arg){
	write("You are powerless to do anything at this time!\n");
	return 1;
}

int enter_scene() 
{
  string txt;
  object brand, nbrand;
  int i, s;
  mixed obs;

  txt = read_bytes(CFILE, 0, file_size(CFILE));
  train_messages = explode(txt, "#");  
  tell_object(this_player(), train_messages[timer]);
  timer++;
  if(timer == 5) 
  {
    remove_call_out("enter_scene");

    if(!KLEVEL) 
    {
      this_player()->set("kungfu_level", 1);
      brand = clone_object(O_OBJ+"kungfu");
      brand->move(this_player()); 
    }
    else
    {
      this_player()->set("kungfu_level", KLEVEL + 1);
      obs = all_inventory(this_player());
      s = sizeof(obs);
      for(i = 0; i < s; i++)
      {
        if(obs[i]->query("short") == "The brand of Kyrnad")
        {
	  brand = obs[i];
	}
      }
      brand->remove();
      nbrand = clone_object(O_OBJ+"kungfu");
      nbrand->move(this_player()); 

    }
    write("\nYou are now a "+ KARR[KLEVEL]+ " in Isshinryu Karate.\n");
    this_player()->move_player(O_ROOM+"hut", "SNEAK", "down");
    timer = 0;
    return;
  }
  else 
  {
    call_out("enter_scene", 3);
  }
}
