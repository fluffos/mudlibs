#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/fallbase";

int stopTime;

void init() {
  ::init();
  add_action("stop_fall", ({"press", "grab", "push", "dig", "force", "smash", "expand", "reach"}));
  add_action("be_specific", ({"stop", "slow", "inhibit"}));
  add_action("grab_tree", "grab");
}

void new_player(object ob) {
  stopTime = -1;
  set_long("You are flying at an angle through a tree.");
}

void heart_beat() {
  string limb;
  ::heart_beat();
  if(!player()) return;

  //time triggers
  switch(beats()) {
    case 3:
      SAY("You fly through a large opening at the end of a hollow log.");
      set_long("Sliding down the inside of a long, hollowed-out log.");
      break;
    case 8:
      SAY("You can see the open end of the hollowed-out log before you.");
      set_long("Sliding down the inside of a long, hollowed-out log. Light shines through the end of the log just before you.");
      break;
    case 13:
      if(stopTime != -1 && stopTime <= 10) {
        //players successfuly stopped fall
        SAY("You have succeeded with your efforts to slow your descent, and come to a complete stop within the log.");
        player()->set_paralyzed(2, "You are slightly frazzled.", "You drag yourself to your feet.");
        player()->move(DRAG_ROOMS"py/fall3");
        all_inventory(this_object())->move(environment(player()));
        return;
      }
      if(player()->query_paralyzed())
        player()->remove_paralyzed();
      SAY("You sail through the open end of the log.");
      set_long("You are deep in a forest, sailing through the air. Trees surround you in all directions. The ground below, which you are rapidly approaching, is littered with small objects.");
      break;
    case 20:
      SAY("A tree wizzes past you to the left.");
      break;
    case 24:
      SAY("Another tree wizzes past you on the right, it barely misses you.");
      break;
    case 26:
      SAY("You %^YELLOW%^slam%^RESET%^ headfirst into a sturdy low-hanging branch, sending you spiraling out of control.");
      if(!harm_player(player(), player()->query_max_hp()*0.7)) return;
      set_long("You are spinning wildly through the air. The world is twisting and turning so fast that you can't make anything out of it.");
      break;
    case 30:
      SAY("%^RED%^The ground is fast approaching!!");
    case 33:
      limb = player()->return_limb();
      SAY("You land hard on your "+limb+"!");
      player()->heal_limb(limb, -1*(player()->query_max_dam(limb)));
      player()->do_damage(limb, 2000);
      SAY("%^RED%^You slam into the ground at an angle so hard that your momentum causes your body to bounce wildly back into the air.");
      if(!harm_player(player(), player->query_max_hp()*12)) return;
      break;
    case 35:
      SAY("You slam headfirst into a tree!");
      if(!harm_player(player(), player->query_max_hp()*50)) return;
  }
}

int stop_fall(string str) {
  object ob;
  string noun, obStr;
  if(sscanf(str, "%s onto %s", obStr, noun) != 2 && sscanf(str, "%s on %s", ob, noun) != 2
    && sscanf(str, "%s in %s", obStr, noun) != 2 && sscanf(str, "%s into %s", ob, noun) != 2
    && sscanf(str, "onto %s", noun) != 1 && sscanf(str, "on %s", noun) != 1)
    noun = str;

  if(noun != "wall" && noun != "walls" && noun != "tube" && noun != "log" && noun != "side" && noun != "sides")
    return 0;

  if(beats() < 3 || beats() > 16) return 0;

  if(obStr) {
    if(!(ob = present(obStr, this_player())) || !(ob = present(obStr, environment(this_player())))) {
      if(member_array(obStr, this_player()->query_limbs()) == -1) {
        SAY("You do not have "+obStr); return 1;
        return 1;
      }
    }
    SAY("You slam your "+obStr+" into the "+noun+".");
  }

  if(obStr) SAY("You slam your "+obStr+" into the sides of the log and try to stop yourself.");
  else SAY("You press yourself against the sides of the log and try to stop yourself.");

  this_player()->set_paralyzed(30, 
    "You are trying your best to slow your descent.",
    "Despite your best efforts, you are unable to slow your descent enough.");
  if(stopTime != -1) return 0;
  stopTime = beats();
  return 1;
}

int be_specific(string str) {
  if(str && str != "fall" && str != "me" && str != "myself" && str != "sliding" && str != "riding")
    return 0;
  SAY("How exactly do you plan to do that?");
  return 1;
}

int grab_tree(string str) {
  if(str != "branch" && str != "tree" && str != "branches") return 0;
  if(beats() >= 20) {
    SAY("The trees are falling past you too quickly for you to do that!");
  }
  else if(beats() < 3) {
    SAY("There are none of those close enough to you for you to do that.");
  }
  else if (beats() <= 16) {
    SAY("You cannot see that from inside of the log.");
  }
  else return 0;
  return 1;
}
