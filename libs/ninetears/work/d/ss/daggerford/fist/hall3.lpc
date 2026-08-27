inherit "/std/room";
#include "path.h";
#include "money.h";

void setup()
{
  set_short("Healers of the Band");
  set_long("These healers offer thier curatives to the members of the band "+
   "at a reduced cost.  Many mighty, injured Members lounge about, "+
   "discussing thier battle scars and past victories.\n");
   
   set_light(85);
   add_exit("north", ROOM+"hall1", "door");
   
    add_sign("This is a large, tasteful sign.  You might like to read it for more "+
 "information on the clinic's services...er, okay, just the one service.  ", 
 "The sign is emblazoned in large letters:\n\n"+
 "Adventurers:  Been had by one too many bandits?  Being massacred to "+
 "small fragments got you down?  Are rampaging dragons just _ruining_ your "+
 "day?  Well, WE are the solution for YOU.  All it costs is a measley 1/4 gold "+
 "coin for each hit point you need restored, and we swear that once we "+
 "get through with you, you won't even remember that "+
 "you were hurting before you walked through our doors!!!  Really!\n\n"+
 "We do regret, however, that because we are SO good at our work, we must "+
 "heal you back to your old, fully-healthy self.  Nothing less will do!\n"+
 "Oh, yes...to apply for treatment, just type \"heal\".  Simple, huh?\n");
add_alias("sign 2", "small sign");
add_item("sign 2", "The small, hand-written sign reads:\n\n"+
"Please do not ask for credit, as a punch in the mouth often offends....\n");
}

void init()
{
   ::init();
   add_action("heal", "heal");
}

heal() 
/* Please use some spaces .......PLEEEEASE */

  {
  object ob;
  int i, mhp, hp, chp;
  mhp=this_player()->query_max_hp();
  hp=this_player()->query_hp();
  chp=mhp-hp;
  i=chp*25;
  if((this_player()->query_value() >=i) && (this_player()->query_max_hp() 
                                           > this_player()->query_hp())) 
    {
    notify_fail("You approach the nurse and are whisked away into a back room.  "+
"Moments after you enter, a large burly man grabs you and bangs your head "+
"into the wall until you cry out for mercy.  He then puts you down, hands "+
"you a bill, and carries you back out to the main room.\n\nAdmittedly, you "+
"feel pretty lousy, but you have forgotten about your previous injuries, "+
"so you really can't say that their motto is false advertising....\n");

    say(this_player()->query_cap_name()+" walks over to one of the nurses.  "+
"Apparently, this is an unwise thing to do, because he is immediately "+
"seized and carried away, only to be dumped back in the room a few minutes "+
"later by a large, brawny man.  He seems to have forgotten all about his "+
"previous injuries.\n");
    this_player()->adjust_hp(chp);
    this_player()->pay_money(({"copper", i}));
    } /* if (!this_player... */
  else 
    {
    if(this_player()->query_hp() == this_player()->query_max_hp()) 
     {
     notify_fail("You approach one of the nurses, who looks at you rather oddly..."+
           "She continues to stare at you, in fact, until you ask her what is "+
           "wrong.  The sound of your voice apparently startles her, but she "+
           "finally recovers enough to point out to you that there is nothing "+
           "physically wrong with you....if you seek spiritual guidance, "+
          "she suggests that you visit the monk's shrine just off of Farmer's "+
           "Way in the northwest sector of the city.\n");
     say(this_player()->query_cap_name()+"approaches one of the nurses, who "+
         "looks him up and down with a rather odd expression, before finally "+
         "pointing out that he does not need treatment.  At least, not "+
         "treatment for any *physical* injuries.  =)\n");
     } 
  else 
    {
    notify_fail("You approach one of the nurses, hoping for some sympathy since you "+
"don't have the proper change for the clinic.  Surely they will accept "+
"something other than gold....The nurse presses a button and you wake up "+
"in the street.  Hmm...guess not.\n");
    say("Uh-oh.  "+this_player()->query_cap_name()+" tries to sweet-talk the "+
"nurse into giving him treatment without the proper form of payment.  You "+
"watch in amazement as she presses a button and he melts into the floor.  Ick!\n");
    this_player()->move(ROOM+"entrance");
    } /* else..*/
  return 0;
  }
  }

