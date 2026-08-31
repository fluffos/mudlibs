#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/base";

void create() {
  ::create();
  set_short("a strange dead end");
  set_long("%^BOLD%^%^BLACK%^The cave walls seem to be pressing in on all sides. There is nothing of distinction on the walls, they seem to be made out of bare rock. To the south, the tunnel opens up and expands greatly. A faint %^RESET%^%^ORANGE%^orange glow%^BOLD%^%^BLACK%^ can be seen covering the southern exit of the cave.");
  set_exits( ([
    "south" : DRAG_ROOMS"py/entrance",
  ]) );
}

//calls the event functions in the instanced version of the room
void do_start_event(object tp) {
  int stage = DRAG_D->query_data("cavestage:"+this_player()->query_name());
  stage = stage?stage:0;
  call_other(environment(tp), "stage_"+stage, tp);
}

int accept_player_into_instance(object tp) {
  if(!tp) return 0;
  if(!tp->is_player()) return 0;
  if(!DRAG_D->query_data("canProveCourage")) {
    write("The mortals have already proven themselves. The orange barrier will not allow passage.");
    return 0;
  }
  call_out("do_start_event", 0, tp);
  return 1;
}

void stage_0(object tp) {
  if(!tp) return;
  DRAG_D->set_data("cavestage:"+tp->query_name(), 0);
  call_out("do_conversation", 3, tp, ({
     "You feel a chill run up your spine.", 2,
     "%^CYAN%^You hear:%^RESET%^ You are weak.", 4,
     "%^CYAN%^You hear:%^RESET%^ No, I'm not talking about your physical strength.", 5,
     "%^CYAN%^You hear:%^RESET%^ Your spirit is weak. Your soul is weak. You are pitiful.", 4,
     "You hear a deep sigh.", 5,
     "%^CYAN%^You hear:%^RESET%^ You are here however, so that must count for something.", 6,
     "%^CYAN%^You hear:%^RESET%^ Very well. You shall be tested.", 3,
     "%^CYAN%^You hear:%^RESET%^ Have no illusions of security here, mortal.", 3,
     "%^CYAN%^You hear:%^RESET%^ Simply because you are being tested does NOT mean that you are safe.", 6,
     "FUNC:set_to_stage_1", 0,
     "%^CYAN%^You hear:%^RESET%^ In fact, because you are being tested, you should feel more unsafe than you have ever felt before.", 6,
     "%^CYAN%^You hear:%^RESET%^ If you wish to leave, do so now.", 20,
     "%^CYAN%^You hear:%^RESET%^ Your time is running out and my tolerance for failure is thin. If you're going to leave, do so now.", 12,
     "It feels like somebody is examining you.", 6,
     "%^CYAN%^You hear:%^RESET%^ I can see that you haven't left yet. You've got guts, that's for sure. Fine, let's get on with this.", 5,
     "FUNC:stage_2", 0,
  }) );
}

int set_to_stage_1(object tp) {
  if(!tp) return 0;
  DRAG_D->set_data("cavestage:"+tp->query_name(), 1);
  return 1;
}

int stage_1(object tp) {
  string name = capitalize(this_player()->query_name());
  if(!tp) return 0;
  DRAG_D->set_data("cavePlayerWhimpedOut:"+tp->query_name(), 1);
  call_out("do_conversation", 10, tp, ({
     "You hear a deep, rasping sigh.", 4,
     "%^CYAN%^You hear:%^RESET%^ "+name+", "+name+", "+name+"... I would say that you disappointed me by leaving, but honestly, I wasn't expecting anything from you anyway.", 6,
    "%^CYAN%^You hear:%^RESET%^ You know the drill. I'm not wasting my breath.. or... whatever.. this time. If you're planning on leaving, get out of here. If you stick around, you won't be leaving.", 20,
     "The walls of the cavern seem to reverberate into a deep low humm.", 20,
     "%^CYAN%^You hear:%^RESET%^ What's this? You're still here? You haven't left yet?", 5,
     "%^CYAN%^You hear:%^RESET%^ Hmmm... Must be AFK or something... I wasn't expecting you to stick around...", 7,
     "%^CYAN%^You hear:%^RESET%^ Very well. It looks like you're here for good this time.", 6,
     "%^CYAN%^You hear:%^RESET%^ Let's get started, shall we?", 6,
     "FUNC:stage_2", 0,
  }) );
  return 1;
}

int stage_2(object tp) {
  if(!tp) return 0;
  DRAG_D->set_data("cavestage:"+tp->query_name(), 2);
  this_object()->block_exit();
  call_out("do_conversation", 10, tp, ({
     "%^CYAN%^You hear:%^RESET%^ My name is Daroq. Your name is "+capitalize(tp->query_name())+". You may have seen the mountain range that I discovered. Or not, I don't really care to be honest.", 11,
     "%^CYAN%^Daroq says:%^RESET%^ Now that the formalities are dispensed with...", 4,
     "%^CYAN%^Daroq says:%^RESET%^ In this cave, true strength comes from within, and not from others.", 6,
     "%^CYAN%^Daroq says:%^RESET%^ If that wasn't quite perfectly clear enough for you, let me help to clarify.", 6,
     "%^CYAN%^Daroq says:%^RESET%^ I am watching you. I am watching your every step and your every thought, and I will absolutely not tolerate cheating.", 12,
     "%^CYAN%^Daroq says:%^RESET%^ You got that?", 2,
     "%^CYAN%^Daroq says:%^RESET%^ Good.", 3,
     "%^CYAN%^Daroq says:%^RESET%^ Alright, I'm going to start you off with an easy one.", 7,
     "%^CYAN%^Daroq says:%^RESET%^ But don't you get lazy on me. If you die it will be your own @#$^ fault.", 5,
     "FUNC:stage_4", 5,
     "%^CYAN%^Daroq says:%^RESET%^ Well? What are you waiting for? Are you going through or not?", 15,
     "It feels like something is poking you.", 18,
    "You hear snoring.", 25,
    "%^CYAN%^Daroq says:%^RESET%^ Look, if you're waiting around just to see if I'm going to keep talking, don't hold your breath. I'm not going to say anything else after this.", 45,
     "%^CYAN%^Daroq screams:%^RESET%^ GET THE HELL THROUGH THAT HOLE!", 60,
     "%^CYAN%^Daroq says:%^RESET%^ Fine. Stay here as long as you want. I'm leaving.", 2,
    "You suddenly feel very lonely.", 0,
  }) );
  return 1;
}

void block_exit() {
  remove_exit("south");
  message("info", "%^ORANGE%^The orange portal to the south condenses and becomes a solid wall, indistinguishable from the surrounding cave walls.%^RESET%^", this_object());
    set_long("%^BOLD%^%^BLACK%^The cave walls seem to be pressing in on all sides. There is nothing of distinction on the walls, they seem to be made out of bare rock. The cave is closed off on all sides, making this room a small, cramped dome, surrounded in rock.");
}

int stage_3(object tp) {
  if(!tp) return 0;
  this_object()->block_exit();
  call_out("do_conversation", 12, tp, ({
     "%^CYAN%^Daroq says:%^RESET%^ Well well, look who's back.", 6,
     "%^CYAN%^Daroq says:%^RESET%^ Now how'd you get out?", 3,
     "You feel as if somebody is examining you closely.", 5,
     "%^CYAN%^Daroq says:%^RESET%^ I can see that I'm dealing with a slippery rascal here...", 6,
     "%^CYAN%^Daroq says:%^RESET%^ No matter. I remember exactly what we were doing.", 4,
     "FUNC:stage_4", 6,
     "%^CYAN%^Daroq says:%^RESET%^ Step on through.", 0,
  }) );
  return 1;
}

int stage_4(object tp) {
  if(!tp) return 0;
  DRAG_D->set_data("cavestage:"+tp->query_name(), 3);
  message("info", "%^RED%^A small circle on the ground becames red hot and then explodes into a great pile of flaming rubble, leaving a great hole in its place.", this_object());
  add_exit(DRAG_ROOMS"py/2", "down");
  return 1;
}

int give_player_stone(object tp) {
  if(!tp) return 0;
  foreach(object ob in all_inventory(tp)) {
    if(file_name(ob)[0..sizeof(DRAG_ITEMS"caveob")-1] == DRAG_ITEMS"caveob") return 1;
  }
  new(DRAG_ITEMS"caveob")->move(tp);
  message("info", "%^BOLD%^A shining stone appears in your hand.%^RESET%^", tp);
  return 1;
}

int open_ice_portal(object tp) {
  if(!tp) return 0;
  message("info", "%^BOLD%^%^CYAN%^The western wall slowly freezes over, then shatters, revealing a great hole.", tp);
  add_exit(DRAG_ROOMS"py/maze/0"+(random(4)+1), "west");
  return 1;
}

int stage_5(object tp) {
  if(!tp) return 0;
  this_object()->block_exit();
  call_out("do_conversation", 12, tp, ({
    "%^CYAN%^Daroq says:%^RESET%^ I see that you have returned.", 5,
    "FUNC:give_player_stone", 6,
    "%^CYAN%^Daroq says:%^RESET%^ Step forward when you are ready.", 7,
    "FUNC:open_ice_portal", 0,
     "%^CYAN%^Daroq says:%^RESET%^ Step on through.", 0,
  }) );
  return 1;
}

int open_wind_portal(object tp) {
  if(!tp) return 0;
  message("info", "%^BOLD%^%^MAGENTA%^A cool breeze blows through the room, and the eastern wall slowly crumbles apart.", tp);
  add_exit(DRAG_ROOMS"py/fall1", "east");
  return 1;
}

int stage_6(object tp) {
  if(!tp) return 0;
  this_object()->block_exit();
  call_out("do_conversation", 5, tp, ({
    "%^CYAN%^Daroq says:%^RESET%^ Ah. You are back.", 4,
    "FUNC:give_player_stone", 6,
    "FUNC:open_wind_portal", 8,
    "%^CYAN%^Daroq says:%^RESET%^ You know what to do.", 0,
  }) );
  return 1;
}

int open_forest_portal(object tp) {
  if(!tp) return 0;
  message("info", "%^GREEN%^Vines creep in through cracks in the northern cave wall. As more creep in, they push the rocks aside, leaving a great hole in the northern wall.", tp);
  add_exit(DRAG_ROOMS"py/3", "north");
  return 1;
}

int stage_7(object tp) {
  if(!tp) return 0;
  this_object()->block_exit();
  call_out("do_conversation", 5, tp, ({
    "%^CYAN%^Daroq says:%^RESET%^ You've made it far.", 2,
    "%^CYAN%^Daroq says:%^RESET%^ No doubt the last thing you want right now is to hear me speak.", 4,
    "FUNC:give_player_stone", 6,
    "FUNC:open_forest_portal", 8,
    "You feel a presence leave you.", 4,
  }) );
  return 1;
}

void move_to_final_room(object tp) {
  if(!tp) return;
  tp->move(DRAG_ROOMS"py/10");
  message("info", "%^BOLD%^%^BLACK%^You find yourself back in the cave with the %^RESET%^%^RED%^bloody%^BOLD%^%^BLACK%^ wall.", tp);
}

int stage_8(object tp) {
  if(!tp) return 0;
  message("info", "%^BOLD%^%^BLACK%^The walls of the cave begin to melt.", tp);
  call_out("move_to_final_room", 3, tp);
  return 1;
}
