#include <ansi.h>

#define TOX_LEVEL 5
#define HEAL_LEVEL 5

inherit "/obj/armor";

int charges;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("amulet of healing");
  set_type("amulet");
  set_ac(1);
  set_short("Amulet of Healing");
  set_long("\
  The fabled... Amulet of Healing!\n\
  *trumpet noises*.\n");
  set_weight(1);
  charges=5;
}

string short()
{
  return (::short()+
    (charges ? 
     " "+HIC+"["+charges+"]"+NORM :
     ""));
}

void init()
{
  ::init();
  add_action("cmd_touch","touch");
}

int is_heal() { return 1; }

int cmd_touch(string str)
{
  if(!str)
  {
    notify_fail("Touch what ?\n");
    return 0;
  }
  if(!id(str))
  {
    notify_fail("You can only touch the \""+query_name()+"\".\n");
    return 0;
  }
  
  if(!charges)
  {
    notify_fail("The amulet is dead.\n");
    return 0;
  }
  
  if((int)this_player()->query_stuffed() + TOX_LEVEL >
     (int)this_player()->query_max_stuff())
  {
    notify_fail("\
Your stomach will explode if you touch this amulet one more time.\n");
    return 0;
  }
  if((int)this_player()->query_soaked() + TOX_LEVEL >
     (int)this_player()->query_max_soak())
  {
    notify_fail("\
Your bladder will explode if you touch this amulet one more time.\n");
    return 0;
  }

  this_player()->drink_soft(TOX_LEVEL);
  this_player()->eat_food(TOX_LEVEL);
  
  this_player()->add_hit_point(HEAL_LEVEL);
  
  write("You touch the amulet. Woot.\n");
  say((string)this_player()->query_name()
    +" touches the amulet. Woot.\n");
    
  if(--charges == 0)
  {
    write("The amulet is empty. :~(\n");
  }
  
  return 1;
}

void add_charges(int x)
{
  charges += x;
}

int query_charges()
{
  return charges;
}