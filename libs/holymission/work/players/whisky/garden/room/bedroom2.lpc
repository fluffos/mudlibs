

/* -----------------------------------------------------------------------
   This is my famous witchbed. I build it up with the idea-help of lots of
   people as Tamarin, Taliana, Cashimor ect.. There where male and female
   characters who helped so this bed is NOT influenced by sexism it's just
   for fun and has no gender-limits or restriction on races and pairs who
   use it. Althought some actions supported may be against the Paulus
   addicts they are legal in the sight of ethnic and social law. For ideas
   and better code please consult me    .....    (c) Whisky
   note: This bed is privacy ! but well can be copied by wizards :*)
   ----------------------------------------------------------------------- */


/* defines */
#define aa add_action
#define TP this_player()
#define TPN TP->query_name()
#define TPG TP->query_gender() 
#define TPP TP->query_possessive()
#define OPN ob->query_name()
#define OPG ob->query_gender()
#define OPP ob->query_possessive()

inherit "/room/room"; 
#include "../garden.h"

string *s1,*s2,*s3,*s4,*s5,*s6,*s7,*s8,*s9,*s10;

int wanimate(); 
void tell_all_but(object who,string str); 
int do_read(string arg);

void reset(int flag)
{
   ::reset(flag);
  
   if (flag == 0)
   { 
     short_desc = ("In the hot Witch bed");
     long_desc =(
     "You have entered the bed of the witch. It's filled\n"+
     "with soft pillows and carpets. There is a small sign fixed to\n"+
     "the wall. It looks like this bed is only for a single use.\n");

     items = ({"bed","You are just in the bed, have a look",
               "pillows","They are soft and red pillows",
               "carpet","A red satin carpet",
               "carpets","Soft red satiny carpets",
               "wall","A red coloured wall with a sign on it",
               "campfire","Well, its a campfire ** laugh **",
               "sign","You can see some letters written on it"
                                                              });
    dest_dir =({ ROOM+"/bedroom","out" });
    
    set_light(1);
   }

     s1 = ({ " pussy"," finger"," pussy"});
     s2=({" pussy"," penis"," pussy"});
     s3=({" wet open pussy"," dick"," wet open pussy"});
     s4=({" in"," on"," in"});
     s5=({" pussy"," penis"," pussy"});
     s6=({" tits"," hairs"," tits"});
     s7=({" wet pussy"," mouth"," wet pussy"});
     s8=({" clit"," penis"," clit"});
     s9=({" slippery pussy"," hard on"," slippery pussy"});
     s10=({" tits"," hairs"," hairs"});
}

   

int do_read(string arg) 
{
  if (arg!="sign") return ( 0 ); 
  write(
    "This is 'private' bedroom: \n"+
    "Extra commands are: sleep, love, lick, animate, kissall \n"+
    "orgasm, fuck, assfuck, sit, spread, suck, back, breastfuck,\n"+
    "finger. I can be used for partysex too. It's absolute private\n"+
    "so it's usage is at your own risk ! (or fun) \n\n"+
    "                       Whisky the gnome :*)\n\n");
   return ( 1 );
  }

  
int do_sleep()
{
  write("You're sleeping....\n");
  say(TPN+" is sleeping....ZZZzzzzz\n");
  return 1;
}

void tell_all_but(object who,string str) 
{
object *o;
int i;

  o=all_inventory();
  for(i=0; i<sizeof(o); i=i+1) 
  {
    if((living(o[i]))&&(o[i]!=TP)&&(o[i]!=who)) 
    {
      tell_object(o[i],str);
    }
  }
}

int do_assfuck(string arg) 
{
object ob;

  if(!arg) return 0;

  if(!(ob=present(arg)) || (!living(ob))) return 0;
   write("You turn "+OPN+" on "+OPP+" back and slowly stick your"+s1[TPG]+
        " into\n"+OPN+"'s ass.\n"+OPN+" makes a short shout and then cries: "
      + "Uhhhhh "+TPN+" give\nme more of that, I love that Ahhhhhhh!\n");
  tell_object(ob,TPN+" turns you on your back and slowly sticks "+TPP+s1[TPG]
            + "\ninto your ass. First it hurts a bit but then you get a "+
              "wonderful\nfeeling Ahhhhhhhh!\n"+TPN+" fondles your"+s2[OPG]+
              " while moving slowly in your ass and\ncries in full erection:"
            + " I love you "+OPN+"!\n");
  tell_all_but(ob,TPN+" turns "+OPN+" on "+OPP+" back and slowly sticks\n"+
               TPP+s1[TPG]+" into "+OPN+"'s ass.\n"+OPN+" makes a short "+
               "shout and then cries: Uhhhhhh "+TPN+" give\nme more, I love"+

               " that, Ahhhhhhhh!\n");
  return 1;
}


int do_love(string arg) 
{
object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You're making love with "+OPN+".\n");
  tell_object(ob,TPN+" says: OOOOOOHHH! Make love to me "+OPN+"!\n"+TPN+
              " says: Uhhhhhhhhh! give me hot sex, fuck me.\n");
  tell_all_but(ob,TPN+" is making love with "+OPN+"\n"+TPN+" shouts: make "+
               "love to me "+OPN+". Ohhhhhhh, give me hot\nsex!\n");
  return 1;
}

int do_fuck(string arg) 
{
object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You're making love with "+OPN+".\n");
  tell_object(ob,TPN+" says: OOOOHHHHH! Make love to me "+OPN+"!\n"+TPN+
              " cries: Fuck me Ahhhhhhhhhhh. Give me your hot body.\n");
  tell_all_but(ob,TPN+" says: OHHHHHHHHHH, make love to me "+OPN+"\n"+
                 "Ahhhhhhhhhhhh! Give me your hot body.\n");
  return 1;
}
 
int do_sit(string arg) 
{
object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You slide down on "+OPN+"'s mighty"+s3[OPG]+".\n"+OPN+" says: "+
        "OOHHH! Please don't stop now, "+TPN+"!\n");
  tell_object(ob,TPN+" jumps up and down on your"+s3[OPG]+".\n"+TPN+" says: "
            + "OOHH! I just can't let it be, "+OPN+"!\n");
  tell_all_but(ob,TPN+" slides down on "+OPN+"'s mighty"+s3[OPG]+".\n"+OPN+
               " says: OHHHHHHH! Please don't stop now!\n"+TPN+" jumps up "+
               "and down on "+OPN+"'s"+s3[OPG]+" and shouts:\nOhhhhhh! I "+
               "just can't let it be!\n");
   return 1;
}
 
int do_spread(string arg) 
{
object ob;


  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You spread your legs wider wanting "+OPN+" to thrust"+s4[TPG]+
        " you, deep.\n"+OPN+" says: OOHHH, "+TPN+"!\n");
  tell_object(ob,TPN+" spreads "+TPP+" legs wider wanting you to thrust"+
              s4[TPG]+", deep.\n"+TPN+" says: "+OPN+", fuck me! now!\n");
  tell_all_but(ob,TPN+" spreads "+TPP+" legs wider wanting "+OPN+"\n"+
               "to thrust"+s4[TPG]+"!\n"+TPN+" shouts: OHHHHHHH! Fuck me "+
               "now!\n");
  return 1;
}
 
int do_suck(string arg) 
{
object ob;


  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You take "+OPN+"'s"+s5[OPG]+" in your mouth\nand start to suck "+
        ob->query_objective()+" faster and faster.\n"+OPN+" moans: Give me "+
        "more, UHHHHHHHHHHHHHHH!\n");
  tell_object(ob,TPN+" takes your"+s5[OPG]+" in "+TPP+" mouth\nand sucks you"
            + " faster and faster.\nYou feel like you are going to explode, "
            + "Uhhhhhhhhhhhhhhh!\n");
  tell_all_but(ob,TPN+" takes "+OPN+"'s"+s5[OPG]+" into "+TPP+" mouth\nand "+
               "starts to suck "+ob->query_objective()+" faster and "+
               "faster!\n"+OPN+" moans: Give me more, UHHHHHHHHHHHHHHH!\n");
  return 1; 
}
 
int do_back(string arg) 
{

object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You go on fucking "+OPN+" from this rear point.\nYou squeeze "+OPP+
        " buttocks harder for every push you give "+ob->query_objective()+
        ".\n");
  tell_object(ob,TPN+" goes on fucking you from the rear.\n"+
              capitalize(this_player()->query_pronoun())+" squeezes your "+
              "buttocks for every push "+this_player()->query_pronoun()+
              " gives you.\n");
  tell_all_but(ob,TPN+" fucks "+OPN+" from "+OPP+" rear point.\n"+
               capitalize(this_player()->query_pronoun())+" squeezes "+OPP+
               " buttocks harder for every push "+
               this_player()->query_pronoun()+" gives "+ob->query_objective() 
             + ".\n"+OPN+" shouts: UIHHHHHHHHHH! I love that!\n");
  return 1;
}

int do_breastfuck(string arg) 
{
object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You turn "+OPN+" around so that "+ob->query_pronoun()+" lies on "+
        OPP+" back.\nAfter that you place yourself on "+OPN+"'s stomach.\n"+
        "You put your"+s3[TPG]+" between "+OPP+s6[OPG]+" and squeeze them "+
        "together.\nThen you start to move your"+s3[TPG]+" between "+OPP+
        s6[OPG]+".\n");  
  tell_object(ob,TPN+" places "+this_player()->query_objective()+"self upon"+ 
              " you and puts "+TPP+s3[TPG]+" between your\n"+s6[OPG]+". You"+
              " can feel "+TPP+s3[TPG]+" pulsate as it ramages between your"+
              s6[OPG]+".\nAll you can think of is what it would be like to "+
              "suck it...\n");
  tell_all_but(ob,TPN+" turns "+OPN+" around so that "+ob->query_pronoun()+
               " lies on "+OPP+" back.\nAfter that "+
               this_player()->query_pronoun()+" places "+
               this_player()->query_objective()+"self on "+OPN+"'s "+
               "stomach\nand puts "+TPP+s3[TPG]+" between "+OPP+s6[OPG]+
               " and squeezes them together.\n"+TPN+" moans: UHHHHHHHHH! I "+
               "love that kind of fuck!\n");
  return 1;
}

int do_finger(string arg) 
{
 object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You put your finger into "+OPN+"'s wet"+s7[OPG]+".\nYou slowly "+
        "start to move the finger in and out.\nYou softly rub "+OPN+"'s"+
        s8[OPG]+" till "+ob->query_pronoun()+" moans.\nAs you do that "+OPN+
        " starts to moan loudly.\n");
  tell_object(ob,TPN+" puts "+TPP+" finger into your wet"+s7[OPG]+"\nand "+
              "rubs softly over your hot"+s8[OPG]+"!\nA wonderful feeling "+
  
            "spreads in your abdomen as "+this_player()->query_pronoun()+
              " starts\nto move the finger in and out... You start to moan "+
              "loudly.\n");
  tell_all_but(ob,TPN+" puts "+TPP+" finger slowly into "+OPN+"'s wet"+
               s7[OPG]+"\nand starts to move "+TPP+" finger slowly in and "+ 
               "out.\nThen he rubs softly over "+OPP+s8[OPG]+"!\n"+OPN+
               " begins to moan loudly: UHHHHHHIIIIIII, give me more, fuck\n"
             + "me!\n");
  return 1;
}
 
int do_lick(string arg) 
{
object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You lick "+OPN+"'s"+s9[OPG]+" like a tiger!\n"+OPN+" shouts: "+
        "IHHHHHHHHHHH, I get it, fuck me now!\n");
  tell_object(ob,TPN+" licks your"+s5[OPG]+" teasing you with "+TPP+
              " tongue!\n"+TPN+" makes circles with "+TPP+" tongue around"+
              " your"+s8[OPG]+" and\nlicks all of your hot liquid!\n");
  tell_all_but(ob,TPN+" licks "+OPN+"'s"+s9[OPG]+" like a tiger teasing\n"+
               ob->query_objective()+" with "+TPP+" tongue and circling "+
               "around "+OPP+s8[OPG]+"!\n"+OPN+" shouts: IHHHHHHHHHH, I get"+
               " it, fuck me now!\n");
  return 1;
}

int do_animate() 
{
  if(TPG==1) {
    return wanimate();
  }
  write("You lie yourself down on the soft pillows.\nYou take your penis in"+
        " in your one hand and with\nthe other hand you begin to softly wank"
      + " your penis.\nYou move your hands all over your body, to show in "+
 

        "which\nerection you are!\n");
  say(TPN+" lies himself down on the soft pillows, puts one hand at\nhis "+
      "penis and wanks himself softly. With the other hand he plays with\n"+
      "his hot balls. Some sperm is running out the top of his\nhard "+
      "penis. He softly moves his hands all over his body\nto return to his "
    + "hot place: his stiff penis and to wank him\nslowly. You feel like he "
    + "is in full erection and you see\nhis beautiful penis getting bigger "+
      "and bigger.\n");
  return 1;
}


int wanimate() 
{
  write("You lie yourself down on the soft pillows.\nYou spread your hot"+
        " legs and begin to softly rub your\nwhole body. You play with your "+
       "nable and your beautiful tits\nand then you put one hand at your "+
        "hot pussy and one finger\ninto your fantastic ass. You begin to "+
        "softly fondle your\nmagnificent pussy. You spread it with two "+
        "fingers and with the\nother fingers you rub your clitoris softly. "+
        "You get wetter and\nwetter. An erotic feeling warms your body. "+
        "You turn back to your\ntits and to fondle your beautiful pussy "+
        "and to show the others what\nkind of erection you have!\n");
  say(TPN+" lies herself down and spreads her hot legs. Then she begins\n"+
      "to softly rub her entire body. She plays with her nable,\nher "+
      "beautiful tits and then she puts one finger into her hot ass\nand "+
      "with the other hand she spreads her pussy and rubs her hot\n"+
      "clitoris. You see sweat and hot liquid running down over her legs "+
      "and you\n see that her muscles shake full of erection. Her mouth is "+
      "wide open\nwaiting for something. You know: she wants it all and "+
      "you can see\nher hot body with the fingers in both her hot holes "+
      "moving up and\ndown!\n");
  return 1;
}

int do_kissall(string arg) 
{
object ob;

  if(!arg) return 0;
  if(!(ob=present(arg))||(!living(ob))) return 0;
  write("You kiss all over "+OPN+"'s body.\n"+OPN+" moans: IHHHH, I want "+
        "more, fuck me please!\n");
  tell_object(ob,TPN+" kisses you all over your body!\n"+TPN+" says: I "+
       "love your wonderful"+s7[OPG]+"\nand your beautiful"+s10[OPG]+", "+
       OPN+".\n");
  tell_all_but(ob,TPN+" kisses and licks "+OPN+" all over her body.\n"+OPN+
 " moans: UHHHHH! I want more!\n"+TPN+" says: I love your "+
               "wonderful"+s7[OPG]+" and your beautiful"+s10[OPG]+"!\n");
  return 1;
}

int do_orgasm() 
{
  write("UHHHHHHHIIIIIIIIIIIIIIIIIII! your under-muscles jerk wildly!\nYou "+
            "nearly fall into a coma. Ahhhhhhhhhhhhh!\nYou burst into a "+
            "wonderful orgasm. It seems to last forever.\n");
  say(TPN+" bursts into a wonderful orgasm!\n"+TPN+" cries full of "+
      "erection: Ihhhhhhhhhhhhhhhhhhh!\nand gets wet all over.\n"+TPN+
      " cries: Uhhhhhhhhhhhhhh, you are wonderful!\n");
  return 1;
}


void init()
{
   aa("do_sleep","sleep");
   aa("do_love","love");
   aa("do_lick","lick");
   aa("do_kissall","kissall");
   aa("do_animate","animate");
   aa("do_orgasm","orgasm");
   aa("do_fuck","fuck");
   aa("do_assfuck","assfuck");
   aa("do_sit","sit");
   aa("do_spread","spread");
   aa("do_suck","suck");
   aa("do_back","back");
   aa("do_breastfuck","breastfuck");
   aa("do_finger","finger");
   aa("do_read","read");
   ::init();
}

