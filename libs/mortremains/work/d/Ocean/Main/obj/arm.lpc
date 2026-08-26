/*
*
*/

#include <mudlib.h>

inherit OBJECT;
int count_down(int dmg);

void create() 
{
  set("author", "gasman");
  set("mass", 0);
  set("short", "@@query_short");
  set("long", "@@query_long");
  set("extra_look" , "$N is soaked in blood!\n");
  set("prevent_get", 1);
  set("prevent_drop", 0);
  set("prevent_clean", 1);
  set("prevent_sell", 1);  
  set("id", ({ "arm", "severed arm" }) );
}

void init()
{
  object target;

  target = environment(this_object());

  if (!living(target)) return 1;

  add_action("no_kill", "kill");
  add_action("no_kill", "cast");
  add_action("no_kill", "kround");
  add_action("no_kill", "kkick");
  add_action("no_drop", "drop");

  call_out("count_down", 3);
  return 1;
}

string query_short()
{
  string str;
  str = this_player()->query("cap_name")+"'s severed arm!";
  return(wrap(str));
}
int count_down(int dmg)
{
  object target;
  dmg = random(10) + 9;

  //write("DEBUG: "+dmg+"\n");
  target = environment(this_object());

  if (!living(target)) return 1;

  switch(random(10))
  {
   case 1 .. 3 :
     write("You are loosing blood at an astounding rate!\n");
   break;
   case 4 :
     write("Warm blood is soaking your cloths.\n");
   break;
   case 5 .. 6 :
     write("You feel dizzy.\n");
   case 7 .. 10 :
     write("You stumble due to lack of blood.\n");
   break;
  }
  target->receive_damage(dmg, "bleeding");

  if (target->query("hit_points") <= 5) this_object()->remove();
  dmg /= 2;
  call_out("count_down", 3, dmg);
  return 1;
}

int no_kill(string arg)
{
  if(!arg) return 0;
  switch(random(10))
  {
    case 1 .. 3 :
      write("In your shape I wouldn't do that!\n");
    break;
    case 4 .. 6 :
      write("You collaps to the ground due to lack of blood!\n");
    break;
    case 7 .. 10 :
      write("You attempt to kill "+capitalize(arg)+" but are too weak.\n");
    break;
  }
  return 1;
}

int no_drop(string arg)
{
  if(!arg) return 0;
  if(lower_case(arg) == "arm")
  {
    write("You don't want to do that!\nWhat you really want to do is go to the hospital!\n");
    return 1;
  }
  else
  {
    return 0;
  }
}