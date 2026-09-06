inherit "/std/thing";
#include <properties.h>
#define NAME capitalize(getuid(this_player()))
#define STR capitalize(str)

varargs void create() {
  ::create();

  AddId("pool");
  Set(P_NOGET,1);
  SetShort("a large above ground swimming pool");
  SetLong(
"This is a genuine Captain Grave's(TM) Pleasure Pool. How the owner could ever "
"afford it, you'll never know! The cool, clear blue water tantalizes you! "
"Read instructions to learn how to use the pool.\n");
  Set(P_NOGET,"How do you want to take this???\n");
  SetValue(6665);
  Set(P_HELP_MSG,"Read the instructions.\n");
}

void init() {
  ::init();
  add_action("dive","dive");
  add_action("suit","suit");
  add_action("splash","splash");
  add_action("swim","swim");
  add_action("dunk","dunk");
  add_action("dunk","push");
  add_action("xfloat","float");
  add_action("read","read");
}

int dive(string str)
  {
  if (!str)
    {
     write("You dive into the refreshing crystal clear pool!\n");
      say(capitalize(({string})this_player()->QueryName())+" dives into the pool!\n");
      return 1;
    }
  if (str)
    {
      write("You do a spectacular "+str+" into the pool!\n");
      say(capitalize(({string})this_player()->QueryName())+" does a spectacular\n"+
      str+" into the pool!\n");
      return 1;
    }
  }

int suit(string str)
  {
    if (!str)
    {
      write("You take all your clothes off, then remember you didn't bring\n"+
      "your bathing suit! You quickly put your clothes back on!\n");
      say(capitalize(({string})this_player()->QueryName())+" stips naked then\n"+
      "quickly gets dressed again. Looks like they forgot their swimsuit!\n"+
      "*SNIKER*\n");
  return 1;
    }
    write("You step into the changing room and emerge wearing a\n"+
    str+".\n");
  say(capitalize(({string})this_player()->QueryName())+" steps into the changing room\n"+
    "and emerges wearing a "+str+".\n");
    return 1;
  }

int splash(string str)
  {
  if (!str)
    {
      write("Whom do you want to splash?");
      return 1;
    }
  write("You splash "+STR+" with water!\n");
  say(NAME+" splashes "+STR+" with water!\n");
  return 1;
  }

int swim(string str)
  {
    write("You swim a few laps in the pool. AHHHHHHH!\n");
    say(capitalize(({string})this_player()->QueryName())+" swims a few laps in the pool.\n");
    return 1;
  }

int dunk(string str)
  {
    if (!str)
      {
        write("Dunk who?\n");
        return 1;
      }
    if (str)
    {
  write("You dunk "+STR+" into the pool!\n");
        say(NAME+" dunks "+STR+" into the swimming pool!\n");
    return 1;
    }
  }

int xfloat(string str)
  {
    write("You float on a rubber raft in the pool! AHHHHH!\n");
    say(NAME+" floats comfortably on a rubber raft in the pool!\n");
    return 1;
  }

int read(string str)
  {
    if(str!="instructions") return 1;
    write (NAME+", you can do the following in the pool:\n\
  float\n\
  swim\n\
  dive <dive description>\n\
  dunk <player>\n\
  push <player>\n\
  suit <suit description>\n\
  \n");
  return 1;
  }
