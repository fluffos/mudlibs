/* The faucet for to refill empty bottles with water */

#include <properties.h>
inherit "/std/thing";

int open;

varargs void create()
{
  ::create();
  SetShort("a faucet");
  SetLong("This is a faucet. If you want to 'refill' empty bottles with water "
"you can 'open' it. Please don't forget to 'close' it after refilling.\n");
  SetNoGet("You try to pull the faucet out of the wand, but failed.\n");
  SetValue(333);
  AddId("faucet");
  AddAdjective("water");
}

void init()
{
  ::init();
  add_action("open","open");
  add_action("close","close");
  add_action("refill","refill");
}

int refill(string s)              /* We only set an error message for the fail */
{
  notify_fail("You don't have anything for to refill.\n");
  return 0;
}

int open(string str)
{
  if( !str || present(str) != this_object()) {
    notify_fail("What do you want to open?\n");
    return 0;
  }
  if(open) {
    notify_fail("The faucet is already open.\n");
    return 0;
  }
  if(!environment()) return 0;
  environment()->Set(P_REFILL,"water");
  write("You open the faucet.\n");
  say(capitalize(({string})this_player()->QueryName()) + " opened the faucet.\n");
  set_heart_beat(1);
  open = 1;
  return 1;
}

int close(string str)
{
  if( !str || present(str) != this_object() ) {
    notify_fail("What do you want to close?\n");
    return 0;
  }
  if(!open) {
    notify_fail("The faucet is already closed.\n");
    return 0;
  }
  if(!environment()) return 0;
  environment()->Set(P_REFILL,0);
  write("You closed the faucet.\n");
  say(capitalize(({string})this_player()->QueryName()) + " closed the faucet.\n");
  set_heart_beat(0);
  open = 0;
  return 1;
}

void heart_beat()
{
  tell_room(environment(),"Water runs out of the faucet.\n");
}

string install(object new_env)
{
  if(present("faucet",new_env)) return "There is already a faucet.\n";
  return 0;
}
