/* A dustbin to toss things */

#include <properties.h>

inherit "/std/container";

create()
{
  ::create();
  AddId("bin");
  AddId("dustbin");
  AddAdjective("dust");
  SetShort("a dustbin");
  SetLong("This is a dustbin. You can put things into it and empty the\n\
dustbin, if it's full.\n");
  SetWeight(1000);
  SetMaxWeight(11000);
  SetValue(433);
  SetTransparency(1000);
  Set(P_NOGET,
    "You won't take the dustbin away. It's built to the litter shack.\n");
}

init()
{
  ::init();
  add_action("empty_bin","empty");
}

remove_thing(object ob)
{
  ob->remove();
  if(ob) destruct(ob);
}

empty_bin(string str)
{
  if(!str) {
    notify_fail("Usage: empty dustbin.\n");
    return 0;
  }
  if(present(str) != this_object()) {
    notify_fail("You can't empty this.\n");
    return 0;
  }
  write("\
You are going to empty the dustbin. All things in it will get lost.\n");
  filter(all_inventory(),#'remove_thing);
  say(capitalize(this_player()->QueryName()||"Someone") +
      " throws the contents of a dustbin away. They vanish.\n");
  return 1;
}

