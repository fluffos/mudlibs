#include <properties.h>
#include "path.h"
#include <money.h>
#include <search.h>
#include <config.h>
#include <rooms.h>

#define LOG "cadra/PIRATE.LOG"
#define QUESTNAME "pirates_cave"

inherit "/std/room";
inherit "/lib/money";

quest() {
  QUESTMASTER->SetPlayerQuest(QUESTNAME,this_player());
  log_file(LOG,this_player()->QueryRealName()+
      " solved the quest at "+ctime(time())+"\n");
}

public int reduce_money(int amount)
{
  mixed paying;
  paying = PayValue2(this_player(),amount,({"copper"}));
  if (intp(paying))
  switch(paying)
    {
     case MONEY_NEGATIVE:
      return (int)notify_fail("Your money has a negative value!\n",
        NOTIFY_NOT_VALID)&&0;
     case MONEY_NO_MONEY:
      return (int)notify_fail("You have no money.\n",
        NOTIFY_NOT_VALID)&&0;
     case MONEY_CANT_PAY:
      return (int)notify_fail("You haven't enough copper coins.\n",
        NOTIFY_NOT_VALID)&&0;
     case MONEY_WRONG_RESULT:
      return (int)notify_fail("Something is wrong with your money.\n",
        NOTIFY_NOT_VALID)&&0;
     default:
      return (int) notify_fail("An error occured.\n") && 0;
    }
  return 1;
}

change(string str) {
  if (!this_player()) return 0;
  if (!Locate("old sorcerer",SM_OBJECT|SM_IGNLIGHT)) return (int)
    notify_fail("To whom do you speak? No one is here !\n") && 0;
  if ((str!="male") && (str!="female") && (str!="neuter")) return (int)
    notify_fail("You cannot change your gender to this!\n") && 0;
  if (!reduce_money(7000)) return 0;
  if (str=="male") this_player()->SetMale();
  if (str=="female") this_player()->SetFemale();
  if (str=="neuter") this_player()->SetNeuter();
  write("The sorcerer mumbles a few words ...\n"
"You feel, that some parts of your body change ....\n"
"New parts grow, other vanish ...\n"
"You feel strange.\n");
  show(this_player()->QueryName()+" looks surprised. "+
  capitalize(this_player()->QueryPossessive())+" body changes.\n",
    this_player());
  return 1;
}

tit(string str) {
  if (!this_player()) return 0;
  if (!present("old sorcerer"))
    return (int) notify_fail("Who should do that?\n") && 0;
  if (!str) return (int) notify_fail("No title isn't possible for you.\n") && 0;
  if (!reduce_money(2000)) return (int) notify_fail(
    "But you don't have that much copper coins with you.\n") && 0;
  this_player()->cmd_title(str);
  write("The sorcerer mumbles a spell ...\n"
"Your title changes magically !\n");
  say("A title in the world has changed.\n");
  return 1;
}

int do_give(string str) {
  object ob;
  if ((str!="staff") && (str!="staff to sorcerer") &&
      (str!="ancient staff") && (str!="long staff") &&
      (str!="ancient staff to sorcerer") && (str!="long staff to sorcerer"))
    return (int) notify_fail(
    "You see no sense in giving this away.\n") && 0;
  if (!present("old sorcerer",this_object())) return (int) notify_fail(
    "Noone is here to accept the staff.\n") && 0;
  if (!ob=present("pirstaff", this_player() )) {
    if (present("staff",this_player())) {
      see("The sorcerer shows you a sign:\n");
      see("He brought me the wrong staff !!!, can be read on a sign.\n");
      see("'FOOL', the sign reads, 'this is the wrong staff ! "
"Bring me the right one !'\n");
      return 1;
      }
    return (int) notify_fail("You don't have a staff.\n") && 0;
    }
  write("The sorcerer shows you a sign:\n"
"'You really have done it !', the sign reads.\n"
"'You brought back my long lost staff !'\n"
"'You have solved this quest !'\n"
"' Great job. '\n");
  if (!QUESTMASTER->QueryQuestSolved(QUESTNAME,this_player())) {
  quest();
  QUESTMASTER->qshout("You see clouds forming some letters in the sky:\n"+
this_player()->QueryName()+" has solved my quest.\n"
"        (signed: the old sorcerer)\n");
  }
  ob->remove();
  if (ob) destruct(ob);
  return 1;
}

create() {
  ::create();
  SetIntShort("a small hut");
  SetIntLong(
"You're in a small dusty cave. On the wall a sign is mounted.\n");
  AddDetail(({"sign"}),"There is something written on it.\n");
  SetIndoors(1);
  SetBright(0);
  AddReadMsg(({"sign"}),
"Hello traveller. This is the place where you can change your gender and "
"your title. If I, the old sorcerer, am here, then I can perhaps help you. "
"If not, then, well, a lost and damned creature killed me. "
"Sorry, but i've lost my speech, 'cause of a wrong working spell. "
"Please 'change' now, to what you want:\n"
" - change to 'male', 'female' or 'neuter'.\n"
" One of the above will cost you 7000 coins.\n"
" Or do you want to change your title?\n"
" But your new title will only stay changed until you advance your level.\n"
" This will cost you 2000 coins. 'title new_title' to do so.\n");
  AddRoomCmd(({"give","return","offer"}),#'do_give);
  AddRoomCmd("title",#'tit);
  AddRoomCmd("change",#'change);
  AddExit("north",TOWER("first/backtower"));
  AddItem("std/npc",REFRESH_HOME,
    ([P_NAME:"the old sorcerer",
      P_LEVEL:16,
      P_HP:320,
      P_HANDS:({({"his left hand",0,14}),({"a lightning bolt",0,30})}),
      P_AC:7,
      P_ALIGN:250,
      P_GENDER:1,
      P_IDS:({"sorcerer","human"}),
      P_ADS:({"old"}),
      P_QUESTIONS:({
        ({"quest","problem","staff"}),
        "The old sorcerer holds up a sign:\n"
"Please return my old staff to me. Some pirates stole it long time "
"ago. It should be somewhere in their caves... probably well "
"secured.\n",
        ({"cave","caves"}),
"The old sorcerer holds up a sign:\n"
"The caves? I am told they are somewhere near the ocean.\n",
        ({"pirate","pirates"}),
"The old sorcerer holds up a sign:\n"
"They should be dead. It is very long time since they make every merchant "
"shiver.\n",
      }),
      P_LONG:
"This is an old looking sorcerer. He looks weak. (Well, but this is "
"a sorcerer, so take care!)\n"]));
}
