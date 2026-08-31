#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("detached");
    set_short("A sneaky bastard");
    set_long("you will die if, you tell anyone.");
    set_id(({"bastard", "detached"}));
    set_level(1);
    set_race("human");
    set_body_type("human");
    set_gender("male");
}

void catch_tell(string str) {
   string you, junk, crap;
   if (sscanf(str, "%s tells you: %s", you, junk)!=2 &&
       sscanf(str, "%s replies: %s", you, junk)!=2) return;
   if (sscanf(junk, "%s?", crap)) {
      call_out("make_mess", 1, "?", "?");
      return;
   }
   if (sscanf(junk, "%s!", crap)) {
      call_out("make_mess", 1, "!", you);
      return;
   }
   call_out("make_mess", 1, "norm", "norm");
   return;
}
void make_mess(string str, string you) {
   if (str == "?" && you == "?") {
   switch (random(15)) {
     case 1: force_me("reply I'm sorry, I don't understand.");
             break;
     case 2: force_me("reply There you go, asking me questions..");
             break;
     case 3:
             force_me("reply Uhhh, you're confusing me.");
             break;
     case 4:
             force_me("reply I was just wondering that myself.");
             break;
     case 5: force_me("reply I know the answer, I just don't want to tell you.");
             break;
     case 6:
             force_me("reply Go ask someone else.");
             break;
     case 7: force_me("reply You think I know the answer? It's not like I'm an ADMIN or anything..");
             break;
     case 8: force_me("reply Stranger knows the answer to that..");
             break;
     case 9: force_me("reply Stormbringer knows the answer to that..");
             break;
     case 10:force_me("reply Inferno knows the answer to that..");
             break;
     case 11:force_me("reply Seeker knows the answer to that..");
             break;
     case 12:force_me("reply What's with you and questions?");
             break;
     case 13:force_me("reply Huh? How am I supposed to know?");
             break;
     case 14:force_me("reply You know the answer to that!");
             break;
     default: force_me("reply What kind of a question is that??");
   }
     return;
   }
   if (str == "!") {
   switch(random(20)) {
     case 1: force_me("reply "+you+".. Please don't yell at me.");
             break;
     case 2: force_me("reply I have feelings, too.");
             break;
     case 3: force_me("reply Sheesh, do you have to yell?");
             break;
     case 4: force_me("reply Keep it down.");
             break;
     case 5: force_me("reply Yell at me again and I will be forced into action.");
             break;
     case 6: force_me("reply I'm calling the cops if you don't keep it down.");
             break;
     case 7: force_me("reply What are you yelling about?");
             break;
     case 8: force_me("reply I'm not yelling at you...");
             break;
     case 9: force_me("reply How many times did I tell you to stop yelling?");
             break;
     case 10:force_me("reply WHAT DO YOU WANT??!");
             break;
     case 11:force_me("reply Do you want me to start screaming?");
             break;
     case 12:force_me("reply That's it, lets fight!!");
             break;
     case 13:force_me("reply Hey, "+you+", I know where ya live.");
             break;
     case 14:force_me("reply If you can't stop screaming, don't talk to me.");
             break;
     case 15:force_me("reply Do you think you're funny? I can dest..");
             break;
     case 16:force_me("reply Oooh, tough guy, 'eh?");
             break;
     case 17:force_me("reply You will force me to silence you..");
             break;
     case 18:force_me("reply I have a gag, bub.");
             break;
     case 19:force_me("reply So you wanna fight or what?");
             break;
     default:force_me("reply Don't make me hurt you.");
   }
     return;
   }
   switch(random(40)) {
      case 1: force_me("reply Jerk.."); return;
      case 2: force_me("reply I don't think so..."); return;
      case 3: force_me("reply I'm busy, please don't bother me."); return;
      case 4: force_me("reply Didn't I tell you not to bother me?"); return;
      case 5: force_me("reply I am busy coding, go away."); return;
      case 6: force_me("reply Detached is not here, please leave a message at the beep.. BEEP!"); return;
      case 7: force_me("reply You'll be seeing my lawyer!"); return;
      case 8: force_me("reply Man, wait 'till my mom finds out.."); return;
      case 9: force_me("reply Screw off, pal.."); return;
      case 10: force_me("reply Talk to Seeker, leave me alone."); return;
      case 11: force_me("reply Oh, Inferno said he would take care of that.."); return;
      case 12: force_me("reply Can't you take a joke, lay off."); return;
      case 13: force_me("reply Do you love me?"); return;
      case 14: force_me("reply I gather you like to talk.."); return;
      case 15: force_me("reply What are you wearing? It better be from Roston, punk."); return;
      case 16: force_me("reply I have a dest alias and I know how to use it.. I think."); return;
      case 17: force_me("reply I think you need a shower, you stink."); return;
      case 20: force_me("reply You'll never be as cool as me."); return;
      case 21: force_me("reply I'm coding.. Something to kill you."); return;
      case 22: force_me("reply Just use the newbie line.."); return;
      case 23: force_me("reply I have a comment for everything."); return;
      case 24: force_me("reply You shall be assimilated."); return;
      case 25: force_me("reply Would you just stop talking to me now?"); return;
      case 26: force_me("reply So are you paying for dinner or not?"); return;
      case 27: force_me("reply Stop delaying, you know you want me."); return;
      case 28: force_me("reply Do you have a death wish?"); return;
      case 29: force_me("reply The longer you talk, the more ways I come up with to kill you."); return;
      case 30: force_me("reply Listen.. Well, actually, don't."); return;
      case 31: force_me("reply You're not too bright are you?"); return;
      case 32: force_me("reply Have you noticed anything strange about me?"); return;
      case 33: force_me("reply Lets fight."); return;
      case 34: force_me("reply The last mortal I fought was named Sigma."); return;
      case 35: force_me("reply Ok, I'm ready to .. ignore you."); return;
      case 36: force_me("reply Have you no life?"); return;
      case 37: force_me("reply Hmm, lemme think.. Ok, done."); return;
      case 38: force_me("reply Your wish is my joke."); return;
      case 39: force_me("reply Don't you just love me?"); return;
      case 40: force_me("reply This sounds familiar.. Do I know you from somewhere?"); return;
     default: force_me("reply I love you, man.."); return;
   }
   return;
}
