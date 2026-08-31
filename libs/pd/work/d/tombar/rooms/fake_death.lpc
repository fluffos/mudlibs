#include <locations.h>
#include <locations.h>
// Slightly added altered by Whit
#include <std.h>
#include <tombar.h>
inherit ROOM;
mapping visitors;
void init() {
  ::init();
  if(!wizardp(this_player()))
    add_action("filter_act", "", 1);
  call_out("dieing", 0, this_player());
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
    if(query_verb() == "say" || query_verb() == "tell" || query_verb() ==
"shout") {
        write("You let out a haunting wail.\n");
        tell_room("d/standard/sewer_ent", "You hear a haunting wail.\n");
    }
    else {
        write("The dead are incapable of such acts.\n");
    }
    return 1;
}

void dieing() {
   write("The red water burns at your skin.  There is no escape!  You slowly feel your life leave your body.\n");
   this_player()->move(ROOMS"fountain");
   this_player()->force_player("drop all");
   this_player()->move(ROOMS"fake_death");
   call_out("pre_death", 0, this_object());
}

void pre_death(object tp) {
remove_call_out("pre_death");
tell_object(tp, "\n "
"                                _,.-----.,_                            \n"
"                             ,-~           ~-.                         \n"
"                           ,^___           ___^.                       \n"
"                         ,'~'   ~'   .   '~   '~'.                     \n"
"                         Y  ,--._    I    _.--.  Y                     \n"
"                         | Y   ,'~-. | ,-~',   Y |                     \n"
"                         | |  |     }:{      |  | |                    \n"
"                         j l  (    ,'| ',    )  ! l                    \n"
"                      .-~  (__,.--' .^. '--.,__)  ~-.                  \n"
"                     (           ,','| ',',          )                 \n"
"                     ',.____,   ~   '''   ~   .____.,'                 \n"
"                       ^.____                 ____.^                   \n"
"                         |  |T ~', !   ! ,'~ T|  |                     \n"
"                         |  |l   _ _ _ _ _   !|  |                     \n"
"                         |  l','V V V V V V','j  |                     \n"
"                         l  | ',|_|_|_|_|_|,' |  !                     \n"
"                          ', ',[T T T T T TI,'  ,'                     \n"
"                           ',  `^-^-^-^-^-^'  ,'                       \n"
"                            ',               ,'                        \n"
"                              ',           ,,'                         \n"
"                                '^-.___,-^'                            \n"
"\n"
"You die.\n"
"You feel the sensations of nothingness as you rise above your corpse. \n"
"You arrive at a destination in a reality not like your own.");
call_out("begin_death", 2, tp);
}
void begin_death(object tp) {
  string nom;
  nom = (string)tp->query_name();
  visitors[nom] = 1;
  tell_object(tp, ""
     "A blue, almost black mist swirls around you. A floating sensation "
     "floods your senses. You can feel that you no longer have a physical "
     "body, be that for the better or worse. Your ghost sores high above "
     "your dead body. You feel yourself falling...");
  call_out("continue_death", 5, tp);
}
void continue_death(object tp) {
  string nom;
  mapping map;
  int beat, deaths;
  nom = (string)tp->query_name();
  map = this_player()->query_deaths();
  deaths = sizeof(tp->query_deaths());
  visitors[nom]++;
  beat = visitors[nom];
  if (environment(tp) != this_object())
    {
     map_delete(visitors, nom); 
     return;
    }
  switch(beat) {
    case 2:
      tell_object( tp,
        "The hazy mist fades away from you, leaving you in a "
        "strange place.\n\n");
      break;
    case 3:
      tell_object(tp, ""
        "You look around, and find yourself in an endless black void. "
        "Spirits fly past you in greenish streaks across the black sky.\n");
      break;
    case 4:
      tell_object(tp,
        "As you try to leave, you notice a huge, dark "
        "figure hovering before you. The figure seems to be an old and "
        "powerful spirit. The spirit has two firey pin points for eyes, "
        "but is otherwise undiscernable besides a long shadowy robe.\n");
      break;
    case 5:
     if (this_player()->query_deaths())
      tell_object(tp,
        "The Spirit says: "+tp->query_cap_name()+
        ".. You fell into a fountain?");
     else
      tell_object(tp,
        "The Spirit says: You have been struck down..");
      tell_object(tp,
        "The Spirit shakes his head.");
    if (deaths < 2)
      tell_object(tp,
        "The Spirit says: Since you're new here, "
        "I am the Grim Reaper. You know damn well who you are, so I "
        "won't bother saying your name again.");
    else
      tell_object(tp,
        "The Spirit says: You know who I am, right? "
        "Of course you do. "+tp->query_cap_name()+
        ", I've been keeping track of your deaths...");
      break;
    case 6:
     if (deaths < 2)
      tell_object(tp, "The Spirit says: "
        "This is the first time you have died, and I feel for ya. I "
        "remember when I first died..");
     else
      tell_object(tp,
        "The Spirit says: You have died a total "
        "of "+(string)deaths+" times.. That's a lot more than most of "
        "these ghosts around here.");
      break;
    case 7:
      tell_object(tp,
        "The Spirit says: Okay, listen. I know "
        "how you feel and I'm the type of guy who understands that sort "
        "of thing, and I'm sorry for you, but there's not much I can do.");
      break;
    case 8:
      if(deaths<2) 
        tell_object(tp,
          "You feel confused and a bit scared.\n");
      else {
        tell_object(tp,
          "The Spirit says: You really should be "
          "more careful before charging into battle, but hey, we all "
          "make mistakes, right?");
        if(deaths>10) 
          tell_object(tp,
            "The Spirit says: You've died quite "
            "a bit for your age.. Why I'm twenty million years old and "
            "I've only died about seven times.\nThe Reaper grins proudly.");
       if(deaths>25)
         tell_object(tp,
           "The Reaper looks you over and whistles.\n"
           "The Spirit says: You're a regular here, ya know?\n"
           "The Reaper pins a frequent ghost's badge on you.");
      }
      break;
    case 9:
      tell_object(tp,
        "The Reaper looks up at you and says: I know you want to get "
        "back to the mortal world to get revenge..\n"
        "The Spirit says: But knowing you, I don't think it'll "
        "be that long before I see you back here again.");
      break;
    case 10:
      tell_object(tp, ""
        "You frown disapprovingly.\nThe Spirit says: "
        "I know, it must be depressing.");
      break;
    case 11:
      tell_object(tp,
        "The Spirit says: Just to make you feel "
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
        "The Spirit says: Oh! Too bad.. Your time "
        "here has run out.. Time for you to go back.");
      tell_object(tp,
        "The Grim Reaper's Spirit waves to you.");
      break;
    case 14:
      tell_object(tp,
        "You feel yourself falling, then suddenly you find yourself in "
        "a familiar place.");
    case 15:
      tell_object(tp,
         "When you wake up you realize that it was just a dream.  You "
         "are floating in the fountain.");
        this_player()->move_player(SQUARE_LOC);
      break;
      return;
      map_delete(visitors, nom);
      break;
    
}
  call_out("continue_death", 9, tp);
  return;
}
