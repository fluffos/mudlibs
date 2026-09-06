// for now only female and male genders...

#include <living.h>
#include <properties.h>
#include <ansi.h>
#include <rooms.h>

#define AB(x)   ANSI_BOLD + x + ANSI_NORMAL

inherit "/std/room";

varargs void create()
{
  ::create();
  SetIntShort("Gender Selection");
  SetIntLong(
   "The fog has thinned here to a light mist, and the light is definitely "
   "shining from the north. If you look down now, you'll see that there "
   "is ground beneath you, though you see no feet which touch it.\n"
   "\n"
   "Now we'll give you a body, as every good adventurer known to the world "
   "thus far has had a solid shape. (Ghosts are great for scaring people, "
   "but have a slight disadvantage when it comes to carrying things "
   "around).\n "
   " \n"
   "First, you should choose whether you wish to be " +
    AB("male or female")+". Type for example "+AB("select gender female")
    +". You can come back to "
   "this room and change it anytime before you leave the "
   "newbie area.\n\n");

  AddExit("north","./room05");
  AddExit("south", "./room03");
  CheckExit("north", DACT_CHECK);

  AddRoomCmd("select","do_gender_select");

  SetIndoors(1);

}

int do_gender_select(string str)
{
  string *args;
  int gender;

  if(!str)
  {
    write("Try either 'select gender female' or 'select gender male'.\n");
    return 1;
  }

  args = norm_id(str, 1);

  if(sizeof(args) < 2 || args[0] != "gender" ||
     member(({"male","female"}),args[1]) == -1)
  {
     write("Try either 'select gender female' or 'select gender male'.\n");
     return 1;
  }

  if(args[1] == "female")
    gender = GENDER_FEMALE;
  else gender = GENDER_MALE;

  this_player()->Set(P_GENDER, gender);

  write("You are now " + args[1] + ".\n");

  return 1;
}



int CheckAction( string action, string verb, string arg, int method )
{

  if("exit" == action && "north" == verb
      && (({int})this_player()->Query(P_GENDER) == GENDER_UNSET) )
  {
    notify_fail("You must select a gender before you may continue.\n",1000);
    return 0;
  }
  return ::CheckAction(action, verb, arg, method);
}

