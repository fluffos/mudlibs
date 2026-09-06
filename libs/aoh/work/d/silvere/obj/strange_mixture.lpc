// A strange mixture, which when drunk at the healer's, will produce very
// strange effects indeed...

#include <msgclass.h>

inherit "/std/thing";

void create()
{
  ::create();
  SetShort(0);
  
}

void init()
{
   add_action("cmd_override", "", 1);
}

void start_babbling()
{
    call_out("do_babble", random(35)+25);
    call_out("stop_babbling", random(100)+200);
}

void do_babble()
{
    string *arr;
  
    arr = ({ "\nThe world seems to be spinning.\n\n",
             "\nYou feel a little dizzy.\n\n",
             "\nYou feel a bit strange.\n\n"
             "\nYou smile very, very brightly at all the pretty things.\n\n",
             "\nYou wonder why pink elephants are dancing around here.\n\n",
             "\nAll the colors seems sooo much brighter.\n\n",
             "\nYou bounce around like an idiot.\n\n",
             "\nStrange...everything seems to be moving so slowly.\n\n",
             "\nMy my...blue suddenly seems like such a sticky color.\n\n",
             "\nOdd; you could swear that you had only 10 fingers this morning.\n\n"
	  });

    msg_write( CMSG_GENERIC, random_select(arr));
    call_out("do_babble", random(35)+25);
}

int cmd_override()
{
   int i;
   string *arr;
   
   i = random(3);
   arr = ({ "Oh, not now, it's just too difficult to concentrate.\n",
            "Maybe later.\n",
            "You feel too dizzy to do that.\n",
            "You swagger and sway, struggling to tell which way is up.\n",
            "The world seems like it's swimming through honey.\n"
         });
   
   if(i == 2)
   {
      write(random_select(arr));
      return 1;
   }
   return 0;
}

void stop_babbling()
{
    while(find_call_out("do_babble") != -1)
        remove_call_out("do_babble");

    msg_write( CMSG_GENERIC,
     "Finally, finally your head stops spinning so much and the world "
     "settles back into its accustomed, stable position. Which might be "
     "a great relief if you weren't so incredibly thirsty, if your head "
     "weren't pounding like a cheap tin drum and your mouth didn't happen "
     "to resemble a wad of used sandpaper. Not exactly a stunning recovery.\n");
    this_player()->SetDrink(10);

    remove();
    if(this_object())
       destruct(this_object());
}
