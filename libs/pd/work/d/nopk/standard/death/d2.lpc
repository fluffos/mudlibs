#include <std.h>
#include <tirun.h>
inherit ROOM;

mapping visitors;


void init() {
  ::init();
  if(!wizardp(this_player()))
    add_action("filter_act", "", 1);
  call_out("begin_death", 4, this_player());
}

void create() {
  ::create();
  set_property("light", 1);
    set_property("no teleport", 1);
  set("short", "The void between life and death");
    set("long", " ");
    skip_obvious();
  visitors = ([]);
}

int filter_act(string str) {
    if(query_verb() == "say" || query_verb() == "tell" || query_verb() == "shout") {
        write("You let out a haunting wail.\n");
        tell_room("d/standard/sewer_ent", "You hear a haunting wail.\n");
    }
    else {
        write("The dead are incapable of such acts.\n");
    }
    return 1;
}

void begin_death(object tp) {
  string nom;
  if(visitors[tp->query_name()]) return;
  nom = (string)tp->query_name();
  visitors[nom] = ([]);
  visitors[tp->query_name()]["deaths"] = sizeof(tp->query_deaths());
  visitors[tp->query_name()]["align"] = (tp->query_alignment() < 0?"e":"g");
  visitors[tp->query_name()]["beat"] = 1;
  tell_object(tp, "%^RESET%^%^BLUE%^"
	"Your mind becomes foggy as you lose consciousness.  You have the sensation of floating in mid air with no concept of "
	"time of reality.  You feel as if you have slipped into a black hole, devoid of life and feeling.  Sounds of "
	"distant wailing and moaning flutter your mind.");
  call_out("continue_death", 5, tp);
}

void continue_death(object tp) {
  string nom;
  mapping map;
  int beat, deaths;
  
  nom = (string)tp->query_name();
  map = this_player()->query_deaths();
  deaths = sizeof(tp->query_deaths());
  beat = visitors[nom]["beat"];
  visitors[nom]["beat"] ++;
  if (environment(tp) != this_object())
    {
     map_delete(visitors, nom); 
     return;
    }
  switch(beat) {
    case 2:
      tell_object( tp,
        "%^BLUE%^The hazy mist fades away from you, leaving you in a "
        "strange place.\n\n");
      break;
    case 3:
      tell_object(tp, "%^BOLD%^%^WHITE%^"
        "You eyes move around, and find yourself in an endless black void. "
        "Spirits fly past you in greenish streaks across the black sky.\n");
      break;
    case 4:
      tell_object(tp,
        "%^BOLD%^%^BLACK%^Having no sense of feeling, all attempts at controlling your body fail.  "
	"Only your head can move allowing you to look around the black expanse.  "
	"Your floating endlessly in the black void.  Suddenly, you feel your feet touch ground.  Still "
	"unable to move, you float there in the middle of the air with your feet barely touching the "
	"ground.  A tall black figure walks over to you sending shivers down your spine.\n");
      break;
    case 5:
     if (this_player()->query_deaths())
      tell_object(tp,
        "%^CYAN%^The Figure says:%^RESET%^ Welcome "+tp->query_cap_name()+
        ".  It seems that "+(string)capitalize(map[sizeof(map)-1][0])+" has struck you down?");
     else
      tell_object(tp,
        "%^CYAN%^The Figure says:%^RESET%^ You have been struck down..");
      tell_object(tp,
        "%^RESET%^The Figure shakes his head.");
    if (deaths < 2)
      tell_object(tp,
        "%^CYAN%^The Figure says:%^RESET%^ Since you're new here, "
        "I am the Grim Reaper. You know damn well who you are, so I "
        "won't bother saying your name again.");
    else
      tell_object(tp,
        "%^CYAN%^The Figure says:%^RESET%^ You know who I am, right? "
        "Of course you do. "+tp->query_cap_name()+
        ", I've been keeping track of your life...");
      break;
    case 6:
     if (deaths < 2)
      tell_object(tp, "%^CYAN%^Grim says:%^RESET%^ "
        "This is the first time you have died, and I feel for ya. I "
        "remember when I first died..");
     else
     if(visitors[nom]["align"] == "e") 
      tell_object(tp,
        "%^CYAN%^Grim says:%^RESET%^ Your evil deeds have caused you to die "
        ""+(string)deaths+" times.  If your going to be evil, you need to learn to "
        "take what you give out."); else
      tell_object(tp,
        "%^CYAN%^Grim says:%^RESET%^ You evil deeds have caused you to die "
        ""+(string)deaths+" times.  Even though you are pure heart, it seems you must have terrible luck.");
      break;
    case 7:
     if(visitors[nom]["bypass"]) {
      tell_object(tp,
        "%^CYAN%^Grim says:%^RESET%^ Since you have passed the test of death, you may leave now.");
       visitors[nom]["beat"]=14;
     } else
      tell_object(tp,
        "%^CYAN%^Grim says:%^RESET%^ Okay, listen. I know "
        "how you feel and I'm the type of guy who understands that sort "
        "of thing, and I'm sorry for you, but there's not much I can do.");
      break;
    case 8:
      if(deaths<2) 
        tell_object(tp,
          "%^RESET%^You feel confused and a bit scared.\n");
      else {
        tell_object(tp,
          "%^CYAN%^Grim says:%^RESET%^ You really should be "
          "more careful before charging into battle, but hey, we all "
          "make mistakes, right?");
        if(deaths>5 && deaths < 14) 
          tell_object(tp,
            "%^CYAN%^Grim says:%^RESET%^ You've died quite "
            "a bit for your age.  I know you must be getting tired of dieing and visiting me for so long.  "
	    "Thats why I'm going to tell you a secret.");
       if(deaths>15)      
         tell_object(tp,
           "The Reaper looks you over and whistles.\n%^CYAN%^"
           "Grim says:%^RESET%^ You're a regular here, ya know?\n"
           "The Reaper pins a frequent ghost's badge on you.");
      }
      break;
    case 9:
	if(deaths>5 && deaths < 14) {
          tell_object(tp,
            "%^CYAN%^Grim says:%^RESET%^ There is a quest that if you solve I will allow you "
	    "to pass quickly from the underworld.  But, thats all im going to tell you.");
	} else
      tell_object(tp,
        "%^CYAN%^Grim says:%^RESET%^ I know you want to get "
        "back to the mortal world to get revenge..\n%^CYAN%^"
        "Grim says:%^RESET%^ But knowing you, I don't think it'll "
        "be that long before I see you back here again.");
      break;
    case 10:
      tell_object(tp, "%^RESET%^"
        "You frown disapprovingly.\n%^CYAN%^Grim says:%^RESET%^ "
        "I know, it must be depressing.");
      break;
    case 11:
      tell_object(tp,
        "%^CYAN%^Grim says:%^RESET%^ Just to make you feel "
        "a little better, I'm going to tell you the secret of life..");
      tell_object(tp,
        "The Reaper clears his throat and opens his mouth to talk.");
      break;
    case 12:
      tell_object(tp,
        "A voice in your head says: "+mud_name()+" calls for you..");
      break;
    case 13:
      tell_object(tp,
        "%^BOLD%^%^RED%^The Spirit says:%^RESET%^ Oh! Too bad.. Your time "
        "here has run out.. Time for you to go back.");
      tell_object(tp,
        "The Grim Reaper's Spirit waves to you.");
      break;
    case 14:
      tell_object(tp,
        "You feel yourself falling, then suddenly you find yourself in "
        "a familiar place.");
        tp->move(ROOMS"monastery");
      map_delete(visitors, nom);
      return;
      break;
    }
  call_out("continue_death", 9, tp);
  return;
}
