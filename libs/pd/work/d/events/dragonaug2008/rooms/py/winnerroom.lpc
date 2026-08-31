#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/convo";
inherit ROOM;

void create() {
  room::create();
  convo::create();
  set_properties( ([ "light" : 1, "no teleport" : 1, "mountain" : 1, "indoors" : 1 ]) );
  set_short("empty room");
  set_long("An empty room.");
  set_exits( ([
  ]) );
}

void init() {
  ::init();
  if(this_player() && this_player()->is_player())
    this_object()->give_winner_speech(this_player());
}

void give_winner_speech(object winner) {
  winner->set_paralyzed(205+30,
    "Everything is moving in slow motion.",
    "The world around you slowly grinds to a halt. Time appears to be standing still, balancing on a hairpin."
  );
  do_conversation(winner, ({
    "%^BOLD%^%^BLACK%^Time suddenly seems to slow down.", 4,
//    "%^RED%^You charge towards the great hound!%^RESET%^\n%^BOLD%^%^BLACK%^Time suddenly seems to slow down.", 4,
    "%^RED%^The great hound bounds off the platform to meet your attack.", 4,
    "You meet the hound in the center of the room and slam your "+this_player()->query_limbs()[random(sizeof(this_player()->query_limbs()))]+" firmly into the hound's chest.", 5,
    "%^RED%^The great hound raises a giant paw and smashes you to the ground.", 0,
    "FUNC:dog_swipe", 5,
    "You look up to see the great hound's teeth barreling down upon you.", 3,
    "FUNC:stop_time", 8,
    "You hear a low applaud.", 3,
    "%^CYAN%^Daroq says:%^RESET%^ Bravo, bravo.", 2,
    "%^CYAN%^Daroq says:%^RESET%^ I must admit, I had my doubts about you...", 3,
    "%^CYAN%^Daroq says:%^RESET%^ But you have allayed them.", 3,
    "You see a shadowy figure materialize behind the great hound's head.", 4,
    "The figure approaches you.", 2,
    "The figure looks carefully at the great hound, then carefully at you.", 5,
    "%^CYAN%^Daroq says:%^RESET%^ Of course, you had no chance against this beast. He is far stronger than you ever could have hoped to be.", 7,
    "%^CYAN%^Daroq says:%^RESET%^ But you surely must have known that before attacking him..", 4,
    "%^CYAN%^Daroq says:%^RESET%^ You must have decided that his destruction was more important than your own safety.", 6,
    "%^CYAN%^Daroq says:%^RESET%^ I must say, I was not expecting this from you.", 4,
    "The figure makes strange motions in the air.", 2,
    "%^YELLOW%^Suddenly, the great hound explodes in a large combustion of incredible magic power.", 4,
    "You find yourself once again on your feet.", 2,
    "The figure wanders slowly over to the destroyed remains of the great hound, then kneels down before it and starts flaying its skin", 5,
    "%^CYAN%^Daroq says:%^RESET%^ Make no mistake, this creature was every bit as dangerous and its destruction every bit as important as you were led to believe.", 8,
    "You hear a deep chuckle.", 8,
    "%^CYAN%^Daroq says:%^RESET%^ Your intervention, however, was far less needed than you seem to think.", 5,
    "The figure finishes its work and stands up, then turns around to face you.", 4,
    "The cloak of shadow falls from the figure's shape, revealing an old man who, despite his age, appears to be in top physical and mental shape.", 6,
    "%^CYAN%^Daroq says:%^RESET%^ In fact, you were not needed at all.", 5,
    "Daroq walks over to you and holds up a thick bag, made of the skin of the great hound.", 5,
    "%^CYAN%^Daroq says:%^RESET%^ Doubtless you were expecting a reward... I would say that you have earned one.", 2,
    "A few drops of blood roll off of the bag", 3,
    "%^CYAN%^Daroq says:%^RESET%^ This should do for you. You should find it has a much greater capacity than those diamonds you mortals seem so fond of bandying about.", 6,
    "Daroq emits another low chuckle as he hands you the bag.", 4,
    "%^CYAN%^Daroq says:%^RESET%^ In getting this far, you have revealed many things about yourself.", 4,
    "%^CYAN%^Daroq says:%^RESET%^ You have displayed a wit and attention to detail like none other.", 5,
    "%^CYAN%^Daroq says:%^RESET%^ You seem to be able to distinguish between situations when haste is required, and others when slow, deliberate action would do best.", 7,
    "%^CYAN%^Daroq says:%^RESET%^ And regardless of whether it was born of evil, of good, or of something else entirely, you have shown that you are willing to put your physical well being at risk, should it be required of you.", 7,
    "%^BOLD%^%^GREEN%^Daroq claps and a dagger materializes in the air above him, falling into his hands.", 5,
    "%^CYAN%^Daroq says:%^RESET%^ I have no interest in mortal politics, and dragons are nothing more than mere mortals to me, although they may not like to hear that through the ridiculous pride that clouds their heads...", 8,
    "%^CYAN%^Daroq says:%^RESET%^ However, you have passed my tests today, and so you have earned this. Do with it as you will.", 5,
    "Daroq hands you the dagger.", 4,
    "%^CYAN%^Daroq says:%^RESET%^ You will find that to be incredibly vital in the near future, should you continue on your current path.", 6,
    "%^RED%^A great mass of flames engulfs Daroq, leaving nothing but a small pile of ash behind.", 7,
    "%^CYAN%^You hear a faint echo:%^RESET%^ Do try not to lose it.", 3,
    "%^ORANGE%^The room begins to swirl around you.", 5,
    "FUNC:move_winner_to_dumproom", 0,
  }) );
}

int dog_swipe(object tp) {
  if(!tp) return 0;
  tp->set_hp(1);
  tp->show_status_line();
  return 1;
}

int stop_time(object tp) {
  if(!tp) return 0;
  tp->remove_paralyzed();
  tp->set_paralyzed(186+25,
    "Time seems to have stopped", "The world winds back to life and the flow of time seems to return to normal.");
  return 1;
}

int move_winner_to_dumproom(object tp) {
  if(!tp) return 0;
  message("info", "You find yourself in a familiar place.\n"
    "%^BOLD%^You feel wiser, more intelligent, more charismatic, and incredibly more experienced.", tp);
  //rewards, exp, and stats given in DRAG_D
  tp->remove_paralyzed();
  tp->move(DRAG_ROOMS"py/dump");
  message("info", tp->query_cap_name()+" materializes out of thin air.", environment(tp), tp);
  return 1;
}
