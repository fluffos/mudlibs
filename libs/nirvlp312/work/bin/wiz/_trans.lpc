#include "/bin/wiz/cmd_defs.h"

int cmd_trans(string str)
{
 object targ;
 if(!str)
 {
  write("Usage: 'trans <player>'\n");
  return 1;
 }
/*
Um., no. -Bp
  if (str == "earwax") {
    write("No.\n");
    say((string)this_player()->query_name()+" tries to trans Earwax, but stutters during the incantation and self-destructs!\n");
    destruct(this_player());
    return 1;
  }
*/
 if(!(targ = find_living(str)))
 {
  write("Target is not in game.\n");
  return 1;
 }

 if(ENV(targ))
 {
  if(ENV(targ) == ENVTP)
  {
   write("Um.  "+capitalize(subjective(targ))+" is already here.\n");
   return 1;
  }
  else
   TR(ENV(targ),
    CAP(str)+" has been summoned by a higher power.\n",
    ({targ}));
 }
 
 MO(targ, ENVTP);
 write("You have transed "+CAP(str)+" to you.\n");
 TL(targ, "You have been summoned.\n");
 return 1;
}

