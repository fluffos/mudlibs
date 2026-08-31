#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS+"py/base";

int messaged;

void create() {
  ::create();
  set_long("%^BOLD%^%^BLACK%^A dark cave... It is nearly impossible to see in any direction.");
  set_exits( ([
    "west" : DRAG_ROOMS"py/8",
  ]) );
  messaged = 0;
}

int add_east_exit(object tp) {
  if(!tp) return 0;
  DRAG_D->set_data("cavestage:"+tp->query_name(), 8);
  write("%^RED%^The eastern wall of the cave turns red and begins to melt, covering the floor with blood and leaving a tremendous hole in the wall.");
  set_long("%^BOLD%^%^BLACK%^A dark cave... It is nearly impossible to see in any direction. The entire eastern wall has dissolved into a tremendous jagged hole. The floor is soaked in a deep red %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^.");
  add_item("blood", "%^RED%^The floor is soaked in it.");
  add_exit(DRAG_ROOMS"py/final", "east");
  return 1;
}

int give_player_stone(object tp) {
  if(!tp) return 0;
  foreach(object ob in all_inventory(tp)) {
    if(file_name(ob)[0..sizeof(DRAG_ITEMS"caveob")-1] == DRAG_ITEMS"caveob") {
      message("info", "%^BOLD%^The stone you are holding pulses brightly.", tp);
      return 1;
    }
  }
  new(DRAG_ITEMS"caveob")->move(tp);
  message("info", "A shining stone appears in your hand.", tp);
  return 1;
}

int heal_player(object tp) {
  if(!tp) return 0;
  if(tp->query_hp() < tp->query_max_hp() || tp->query_sp() < tp->query_max_sp() || tp->query_mp() < tp->query_max_mp()) {
    tp->set_hp(tp->query_max_hp());
    tp->set_sp(tp->query_max_sp());
    tp->set_mp(tp->query_max_mp());
    message("info", "%^BOLD%^Your wounds have been healed.", tp);
  }
  else {
    message("info", "%^CYAN%^You hear:%^RESET%^ Incredible... There is not a scratch on "+tp->query_objective()+".", tp);
  }
  return 1;
}

void init() {
  ::init();
  if(!messaged) {
    messaged = 1;
    remove_exit("west");
    do_conversation(this_player(), ({
      "%^BOLD%^The wall to the west congeals and seals itself off, and you find yourself left in darkness.", 7,
      "%^CYAN%^Daroq says:%^RESET%^ It is time.", 6,
      "%^CYAN%^Daroq says:%^RESET%^ You have made it incredibly far. Your task is nearly over.", 7,
      "You feel the familiar feeling of an unknown something examining you.", 6,
      "FUNC:heal_player", 5,
      "%^CYAN%^Daroq says:%^RESET%^ You may be the one we need...", 5,
      "%^CYAN%^Daroq says:%^RESET%^ Despite what you may bring yourself to believe, you weren't just brought here for fun and games.", 7,
      "You hear pacing.", 4,
      "%^CYAN%^Daroq says:%^RESET%^ No, you were brought here for a distinct purpose.", 6,
      "%^CYAN%^Daroq says:%^RESET%^ We... The world... Are in dire need of assistance.", 4,
      "You hear a deep sigh.", 4,
      "%^CYAN%^Daroq says:%^RESET%^ As much as it pains me to say it...", 8,
      "%^CYAN%^Daroq says:%^RESET%^ We are in dire need... of you.", 6,
      "The sound of pacing stops.", 3,
      "You hear footsteps echo through the chamber.", 5,
      "Your shoulder grows heavy, as if somebody is resting their hand upon it.", 5,
      "%^CYAN%^Daroq says:%^RESET%^ There is a terrible power brewing. A power much greater than you could ever have imagined.", 8,
      "%^CYAN%^Daroq says:%^RESET%^ You will not be asked to face this power, for now, as this power is so great that its mere presense may be enough to rip your ever so cherished face straight from your head.", 12,
      "%^CYAN%^Daroq says:%^RESET%^ What you will be asked to face, is something which has been created as a result of this power...", 6,
      "%^CYAN%^Daroq says:%^RESET%^ Or, to be more specific, something which has been created by this power.", 6,
      "Your shoulder feels light once again.", 3,
      "%^CYAN%^Daroq says:%^RESET%^ Do not forget the stone that you carry.", 5,
      "%^CYAN%^Daroq says:%^RESET%^ There will be no opportunities to start over. This is the real deal.", 6,
      "%^CYAN%^Daroq says:%^RESET%^ If you engage this thing and lose...", 5,
      "%^CYAN%^Daroq says:%^RESET%^ Or, god forbid, run...", 5,
      "%^CYAN%^Daroq says:%^RESET%^ Well then...", 2,
      "%^CYAN%^Daroq says:%^RESET%^ You will have simply provoked it...", 4,
      "%^CYAN%^Daroq says:%^RESET%^ And the world will be beyond saving.", 6,
      "%^CYAN%^Daroq says:%^RESET%^ Simply poking it once and running is not an option here.", 5,
      "%^CYAN%^Daroq says:%^RESET%^ Should you enter that room and find that you will not be able to destroy it your first chance...", 6,
      "FUNC:give_player_stone", 5,
      "%^CYAN%^Daroq says:%^RESET%^ Use it. Use it and come back when you are ready.", 6,
      "%^CYAN%^Daroq says:%^RESET%^ Just in case you forgot how, you can use it with: <escape>", 5,
      "%^CYAN%^Daroq says:%^RESET%^ This is the big "+(this_player()->query_gender()=="male"?"boy":"girl")+"'s game now.", 7,
      "%^CYAN%^Daroq says:%^RESET%^ Good luck.", 4,
      "FUNC:add_east_exit", 4,
    }) );
  }
}
