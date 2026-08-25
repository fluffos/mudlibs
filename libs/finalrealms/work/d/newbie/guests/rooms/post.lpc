#include "path.h"
#include "mail.h"
inherit "/std/room";
 
object sign;
 
void init()
   {::init();
    add_action("do_mail", "mail");
    add_action("do_mail", "read");
   }
 
void setup()
  {set_short("City of Daggerford:  Scribe's Office");
  set_long("\nCity of Daggerford:  Scribe's Office\n\n"
	 "     You are standing inside the Daggerford Scribe's Office, a "
             "cramped and cluttered building, from which letters can be "
             "dictated and eventually delivered to lovers, enemies, men "
             "and women at arms, EVEN Immortals.  Several gnomes lounge "
             "around in boredom behind the protection of a sturdy, metal "
             "mesh fence secured to the counter between you both.  To "
             "both your south and west, exits lead back onto Wall "
             "Street.\n\n");
    add_item(({"gnome", "gnomes", "scribe", "scribes"}), "The scribes "
             "all appear to be overworked and underpaid, evident by their "
             "bored posture and blank facial expressions.  They are seated "
             "behind the counter 'anxiously' awaiting someone or "
             "something to disturb their daydreams and occasional cat-naps "
             "by stepping up to the privacy booth each is responsible "
             "for.\n\n");
    add_item(({"counter", "countertop"}), "The counter has been built "
             "using large blocks of stone, worn smooth by the tremendous " 
             "number of patrons who've rested their elbows on its surface "
             "while attempting to come up with the right words to say.  A "
             "mesh fence rising from countertop to ceiling prevents "
             "customers from strangling the scribes who are well known "
             "for their sarcastic and often rude unsought comments.\n\n");
    add_item(({"mesh", "fence", "mesh fence"}), "It must have been a "
             "tedious chore to fashion this fence which extends from "
             "the countertop to the ceiling.  The links themselves "
             "seem to have been made with a dark metal, deceptively "
             "delicate in appearance.  The space between each link "
             "prevents anything larger than a field mouse to pass, yet "
             "large enough not to inhibit your view of the other side "
             "of the counter.\n\n");
    add_item(({"booth", "booths", "privacy booth"}), "The privacy booths "
             "are actually just thin partitions along the face of the "
             "counter, allowing patrons to dictate their messages "
             "privately, without having to worry about the curious ears "
             "of others who may be present.\n\n");
    sign=add_sign("If you are interested in dictating a letter to one of "
             "our resident scribe's, please use the following syntax:\n"
             "   mail <To Whom>          is used to send a message\n"
             "   read                    is used to read a message\n\n"
             "We are proud of the enthusiasm of the employees in our "
             "office and hope we get the chance to serve you in a most "
             "polite and speedy manner.\n\nThe Management\n");
 
    set_light(85);
    
    add_exit("south", HERE+"raiseroom", "door"); 
   }
 
int do_mail(string TO_WHOM)
   {object ob;
    write("You step forward into one of the privacy booths, meekly "
          "informing the gnome of your intentions.  The gnome grumbles "
          "something about hating to translate your rotten dialect.\n\n");
    say(this_player()->query_cap_name()+" steps into one of the privacy "
          "booths.  A sleepy gnome grudgingly acknowledges the presence "
          "of a customer with a loud yawn.\n\n");
    ob=clone_object("/obj/handlers/post");
    ob->move(this_player());
    ob->start_mail(TO_WHOM);
    return 1;
   }
 
void send_message(string TO_WHOM)
   {write("The gnome in front of you adds a flowery signature to the "
          "text, grabs a fairy from beneath the counter, and slams "
          "the poor fellow onto the paper.  Groggily, the fairy scans "
          "the address before scampering through the fence, off to "
          "deliver the message.\n\n");
    say(this_player()->query_cap_name()+" fumbles backwards, swatting "
          "the air, as a fairy sleepily speeds off to deliver a "
          "message.\n\n");
    if(find_living(TO_WHOM))
       call_out("after_call", 5, TO_WHOM);
  }
 
void after_call(string TO_WHOM)
   {object TARGET;
    TARGET=find_living(TO_WHOM);
    if(!TARGET)
       return ;
    if(environment(TARGET)==this_object())
       {say("The fairy returns through the door and whispers something "
            "to "+TARGET->query_cap_name()+".\n\n");
       }
    else
       {tell_room(environment(TARGET), "A small fairy flies over to "+
           TARGET->query_cap_name()+", whispers something, and then "
           "quickly flies off again.\n", ({TARGET}));
        call_out("come_back", 5);
       }
    tell_object(TARGET, "A small fairy flies over to your ear, and though "
       "it is difficult to deciper the whisper amidst the buzzing of "
       "fairy wings, you realize that a letter awaits you in the scribe's "
       "office.\n\n");
   }
 
void come_back()
   {tell_room(this_object(), "A tired and weary fairy returns from "
       "delivering its message, squeezes its way through the mesh fencing, "
       "growls menacingly at one of the gnomes in a high pitched voice, " 
       "and returns to sleep beneath the counter.\n\n");
   }
 
 
   
