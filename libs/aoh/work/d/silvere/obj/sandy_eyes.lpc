// Object that hinders you to see the room or examine something.
// Created by Taurec [22-DEC-97]

// TODO:  SIGHT OF PLAYER SHOULD BE CHANGED, SO THAT HE GETS NOSEE-MSGS ONLY.

#include <properties.h>
#include <macros.h>
#include <moving.h>
inherit "std/thing";

void create() {
  ::create();
  seteuid(getuid());
  Set(P_SHORT,""); // invisible
  Set(P_WEIGHT,0);
  Set(P_NOGIVE,1); 
  Set(P_NODROP,1); 
  Set(P_NOSELL,1);
  AddId("blinder");
}

void init()
{
  ::init();
  add_action("look_around","l");
  add_action("look_around","examine");
  add_action("look_around","exa");
  add_action("look_around","look");
  add_action("rub_eyes","rub");
}

int look_around(string str)
{
  if (!TP) return 0;
  write("You see nothing. There's too much sand in your eyes. Perhaps "
        "you should rub your eyes to see again.\n");
  return 1;
}

int rub_eyes(string str)
{
  notify_fail("What exactly do you want to rub?\n",NOTIFY_ILL_ARG);
  if (!str) return 0;
  if (!TP) return 0;
  if (strstr(lower_case(str),"eyes")!=-1)
  {
    write("You rub your eyes and are happy to see again.\n");
    show_room(environment(TP),NAME(TP)+" rubs "+HISHER(TP)+
            " eyes and blinks carefully.\n",({TP}));
    remove();
    return 1;
  }
  return 0;
}
  
  

