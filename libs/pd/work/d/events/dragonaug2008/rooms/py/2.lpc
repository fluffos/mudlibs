#include <std.h>
#include <move.h>
#include <rest.h>
#include <dragonevent.h>

#define BEGINNING 0
#define ICICLE_FALLING 1
#define ICICLE_KNOCKED_LOOSE 2
#define ICICLE_IN_GROUND 3
#define ICICLE_MELTED 4
#define ICICLE_EVENT 5
#define STONE_RELEASED 6

inherit DRAG_ROOMS"py/base";

int impale_icicle_in_ground(string noun, string itemStr);
int do_look(string);

int stoneProgress;
int playerWarned;

void create() {
  ::create();
  set_short("%^BOLD%^%^CYAN%^An icy cave");
  set_long("%^BOLD%^%^CYAN%^The cave walls, ceiling, and floor are covered in %^WHITE%^ice%^CYAN%^ and %^RESET%^snow%^BOLD%^%^CYAN%^. The ground is made mostly out of slick impure ice which has frozen over unevenly, creating a firm grip and making passage easier. The cave is fairly large size, but not tremendously so. The cave roof high above is covered in %^WHITE%^icicles%^CYAN%^ which stretch towards the ground.");
  set_items( ([
    "walls" : "A thick layer of impure ice covers the cave walls. The ice is clear enough to see through in most places, but white impurities in the water it was formed from obscure your view in some places.",
    "wall" : "It is covered in a thick layer of ice.",
    "ice" : "It is mostly clear enough to see through, but white impurities in the water it was formed from obscure your view in some places.",
    "water" : "That does not exist in that form here.",
    "snow" : "It covers the walls in small patches.",
    "ceiling" : "It is fairly far above you, out of your reach. It is covered with icicles.",
    ({"ground","surface","glow","rocks","rock"}) : (:do_look:),
    ({"icicles", "icicle", "fracture"}) : (:do_look:),
    "fissure" : (:do_look:),
  ]) );
  stoneProgress = BEGINNING;
  playerWarned = 0;
}

void init() {
  ::init();
  add_action("throw_item_at_icicle", "throw");

  add_action("slam_icicle_into_ground", "slam");
  add_action("slam_icicle_into_ground", "jam");
  add_action("slam_icicle_into_ground", "force");
  add_action("slam_icicle_into_ground", "push");
  add_action("slam_icicle_into_ground", "insert");
  add_action("slam_icicle_into_ground", "thrust");
  add_action("slam_icicle_into_ground", "stab");

  add_action("break_ice_with_icicle", "break");
  add_action("break_ice_with_icicle", "smash");
  add_action("break_ice_with_icicle", "split");
  add_action("break_ice_with_icicle", "stab");
  add_action("break_ice_with_icicle", "pry");

  add_action("melt_icicle", "breathe");
  add_action("melt_icicle", "huff");
  add_action("melt_icicle", "hug");
  add_action("melt_icicle", "piss");
  add_action("melt_icicle", "wiz");
  add_action("melt_icicle", "urinate");
  add_action("melt_icicle", "rub");
  add_action("melt_icicle", "polish");
  add_action("melt_icicle", "melt");

  add_action("use_stone_on_wall", ({ "use", "release" }) );

  add_action("break_wall_with_stone", ({ "break", "smash", "destroy", "obliterate", "open" }) );

  add_action("stop_stupid_gets", "get");

  add_action("jump_does_nothing", "jump");
}

int do_real_look(string str) {
  if(str == "icicles") {
    if(stoneProgress < ICICLE_FALLING)
      write("They litter the ceiling. One icicle in particular is much larger than the other ones.");
    else
      write("They litter the ceiling.");
  } else if(str == "icicle") {
    if(stoneProgress < ICICLE_FALLING)
      write("There is a hairline fracture on the base of the icicle. It is far away from you, too far to reach with your hands.");
    else if(stoneProgress == ICICLE_FALLING)
      write("It is falling through the air!");
    else return write("You do not see that here.");
  } else if(str == "fracture") {
    if(stoneProgress < ICICLE_FALLING)
      write("It is large enough to make the icicle unstable.");
    else return write("You do not see that here.");
  } else if(str == "ground") {
    if(stoneProgress < ICICLE_IN_GROUND)
      write("The ice below has frozen over rocks that seem to glisten softly in the light, creating an uneven surface and making walking easier.");
    else if(stoneProgress == ICICLE_IN_GROUND)
      write("There is a large icicle jammed into it. Beneath the tip of the icicle, a large fissure has opened beneath the ice. Small drops of water roll off the icicle and puddle into the fissure beneath it.");
    else if(stoneProgress == ICICLE_MELTED)
      write("Beneath the icy ground, a large pool of water has collected in a deep fissue between the sheet of ice and the rocks below.");
    else
      write("The ground below is rocky, and scattered with few pieces of ice here and there.");
  } else if(str == "surface") {
    if(stoneProgress < STONE_RELEASED)
      write("The surface of the ice seems to glow softly.");
    else
      write("The surface of the ice is very uneven and covered with small ice shards. In one part of the ground, the surface has been blown completely away, exposing the rocks below.");
  } else if(str == "glow") {
    if(stoneProgress < STONE_RELEASED)
      write("The glow coming from the floor seems to originate from a small pile of rocks frozen beneath the ice.");
    else return write("You do not see that here.");
  } else if(str == "rocks" || str == "stones") {
    if(stoneProgress < STONE_RELEASED)
      write("Upon closer inspection, only one rock amidst the pile of rocks beneath the floor seems to be emitting the glow.");
    else
      write("They litter the ground beneath the ice below. In one part of the ground, the surface of the ice has been blown away, exposing the stones below.");
  } else if(str == "rock") {
    if(stoneProgress < STONE_RELEASED)
      write("It is frozen beneath the ice.");
    else return write("You do not see that here.");
  } else if(str == "fissure") {
    if(stoneProgress != ICICLE_IN_GROUND) return write("You do not see that here.");
    write("A moderately sized fissure, large but not large enough for you to fit in, that has opened up beneath the surface of the ice below. There is an icicle jammed into the ice directly above the fissure, which drips water slowly into the fissure. It is not, however, melting nearly fast enough to fill the fissure with water any time soon.");
  }
  return 1;
}

int do_look(string str) {
  if(do_real_look(str))
    message("info", this_player()->query_cap_name()+" looks over "+str+".", this_object(), this_player());
  else message("info", this_player()->query_cap_name()+" looks in vain for "+str+".", this_object(), this_player());
  return 1;
}

void impale_player(object player) {
  if(!player || stoneProgress != ICICLE_FALLING) return;
  message("info", "The icicle %^RED%^S%^BOLD%^L%^YELLOW%^A%^RED%^M%^RESET%^%^RED%^S%^RESET%^ through you, %^YELLOW%^impaling%^RESET%^ you on the floor!", player);
  player->set_rest_type( REST );
  message("info", "%^CYAN%^You hear:%^RESET%^ You have been critically injured, the icicle impaling you in place is restraining bleeding and is the only thing saving your life. Do not move until you have healed, or you will die.", player);
  if(!set_player_hp(player, player->query_max_hp() * 0.3)) return;
  stoneProgress = ICICLE_KNOCKED_LOOSE;
  new(DRAG_ITEMS"icicle")->move(this_object());
}

void save_impalement(string str) {
  if(stoneProgress != ICICLE_FALLING) {
    if(!playerWarned && this_player()->query_hp()<=this_player()->query_max_hp()*0.5) {
      write("As you attempt to move, the %^BOLD%^%^CYAN%^icicle%^RESET%^ slides slightly out of you, causing you %^BOLD%^%^RED%^tremendous pain%^RESET%^.");
      message("info", this_player()->query_cap_name()+" attempts to move and is damaged.", this_object(), this_player());
      if(!set_player_hp(this_player(), this_player()->query_max_hp()*0.1)) return;
      playerWarned = 1;
      input_to("save_impalement");
      return;
    }
    message("info", this_player()->query_cap_name()+" attempts to stand up.", this_object(), this_player());
    this_player()->set_rest_type(0);
    write("As you lift yourself off the floor, the %^BOLD%^%^CYAN%^icicle%^RESET%^ pops loose and you %^RED%^bleed out%^RESET%^ onto the floor.");
    if(!harm_player(this_player(), this_player()->query_max_hp()*0.5)) {
      foreach(object ob in all_inventory(this_object())) {
        if(file_name(ob)[0..sizeof(DRAG_ITEMS"icicle")-1] != DRAG_ITEMS"icicle") {
          ob->move(this_player());
        }
      }
      return;
    }
    present("icicle")->set_short("a %^BOLD%^%^RED%^bloody%^CYAN%^ icicle");
    present("icicle")->set_long(present("icicle")->query_long()+"%^BOLD%^%^CYAN%^ Its tip is covered in %^RED%^blood%^CYAN%^.");
    return;
  }
  if(str) str = explode(str, " ")[0];
  if( str != "west" && str != "east" && str != "north" && str != "south" && str != "southeast" && str != "southwest" && str != "northwest" && str != "northeast"
    && str != "e" && str != "w" && str != "n" && str != "s" && str != "ne" && str != "nw" && str != "se" && str != "sw"
    && str != "dodge"
    && str != "dive"
    && str != "avoid"
    && str != "jump"
    && str != "run"
    && str != "escape"
    && str != "hide"
    && str != "move"
  ) {
    write("%^RED%^You can "+str+" all you want after you've saved yourself from the plummeting icicle!!");
    input_to("save_impalement");
    return;
  }
  message("info", this_player()->query_cap_name()+" saves themself from the falling icicle.", this_object(), this_player());
  write("You manage to clamber to safety\nThe icicle slams firmly into the ground.");
  stoneProgress = ICICLE_KNOCKED_LOOSE;
  new(DRAG_ITEMS"icicle")->move(this_object());
}

int throw_item_at_icicle(string str) {
  string item;
  object itemOb;
  if(!str || sscanf(str, "%s at icicle", item) != 1)
    return 0;
  if(!(itemOb = present(item, this_player())))
    return notify_fail("You do not have "+item+".\n");
  if(stoneProgress >= ICICLE_FALLING)
    return notify_fail("There is no suitable icicle here.\n");
  if(itemOb->move(this_object()) != MOVE_OK) {
    write("You cannot throw that.");
    return 1;
  }
  message("info", this_player()->query_cap_name()+" throws an "+item+" towards the ceiling.", this_object(), this_player());
  if(random(350) > this_player()->query_stats("dexterity")) {
    write("You throw the "+item+" but miss the icicle completely.");
    return 1;
  }
  message("info", "The "+item+" strikes an icicle on the ceiling, knocking it loose.", this_object(), this_player());
  write("Your "+item+" connects firmly with the icicle.");
  write("%^YELLOW%^the icicle begins to fall towards you!!");
  stoneProgress = ICICLE_FALLING;
  call_out("impale_player", 6, this_player());
  input_to("save_impalement");
  return 1;
}

int break_ice_with_icicle(string str) {
  string itemStr;
  object itemObj;
  if(stoneProgress != ICICLE_IN_GROUND - 1) return 0;
  sscanf(str, "%s with %s", str, itemStr);
  return impale_icicle_in_ground(str, itemStr);
}

int slam_icicle_into_ground(string str) {
  string itemStr;
  object itemObj;
  if(stoneProgress != ICICLE_IN_GROUND - 1) return 0;
  sscanf(str, "%s into %s", itemStr, str);
  return impale_icicle_in_ground(str, itemStr);
}

int impale_icicle_in_ground(string noun, string itemStr) {
  object itemObj;

  //make sure the player entered the command
  //correctly, and that they have the icicle.
  if(noun != "ice" && noun != "ground" && noun != "floor" && noun != "stone" && noun != "stones" && noun != "rock" && noun != "rocks")
    return notify_fail("You can't bring yourself to do that to the "+noun+"\n");
  if(itemStr) itemObj = present(itemStr, this_player());
  if(!itemStr)
    return notify_fail("You would need something with which to do that.\n");
  if(!itemObj)
    return notify_fail("You do not have "+itemStr+".\n");
  if(file_name(itemObj)[0..sizeof(DRAG_ITEMS"icicle")-1] != DRAG_ITEMS"icicle")
    return notify_fail("The ice resists your efforts.\n");

  stoneProgress = ICICLE_IN_GROUND;
  message("info", this_player()->query_cap_name()+" slams an icicle into the floor.", this_object(), this_player());
  write("You collect your strength and jam the icicle into the floor.");
  itemObj->move(this_object());
  itemObj->set_prevent_get("It is planted firmly into the ground.");
  itemObj->set_short(itemObj->query_short()+" sticking out of the ground");
  itemObj->set_long(itemObj->query_long()+" It is stuck firmly into the ground.\n%^RESET%^A large fissure seems to have opened within the ice below it.");
  return 1;
}

int melt_icicle(string str) {
  object icicle = present("icicle", this_object());
    if(!icicle || stoneProgress != ICICLE_IN_GROUND)
    return 0;
  if(query_verb() == "melt") { write("How are you planning on doing that?"); return 1; }
  if(str != "on icicle" && str != "icicle" && str != "ice" && str != "in fissure" && str != "fissure" && str != "on ice")
    return 0;

  write("As you "+query_verb()+" on the icicle, it begins to melt.");
  message("info", this_player()->query_cap_name()+" "+query_verb()+"s on the icicle.", this_object(), this_player());
  call_out("finish_melting", 8, icicle);
  stoneProgress = ICICLE_EVENT;
  return 1;
}

void finish_melting(object icicle) {
  message("info", "The icicle melts completely, filling the fissure beneath the ice with water.", this_object());
  icicle->set_short("%^BLUE%^a puddle of water");
  icicle->set_long("%^BLUE%^It is slowly freezing beneath the ice.");
  icicle->set_id( ({ "water", "puddle", "puddle of water" }) );
  icicle->set_prevent_get("It is beneath the ice below, you cannot reach it.");
  call_out("freeze_water_slightly", 20, icicle);
}

void freeze_water_slightly(object icicle) {
  message("info", "%^BOLD%^%^CYAN%^The water beneath the floor begins to freeze.", this_object());
  icicle->set_short(icicle->query_short()+" %^BOLD%^%^CYAN%^with small pieces of ice floating in it.");
  icicle->set_long(icicle->query_long()+" %^BOLD%^%^CYAN%^It is begining to freeze over.");
  call_out("stress_floor", 12, icicle);
}

void stress_floor(object icicle) {
  message("info", "The floor beneath your feet begins to crack and shudder as the freezing water beneath it exerts more pressure on it from below.", this_object());
  icicle->set_short("%^BOLD%^%^CYAN%^a nearly frozen %^RESET%^%^BLUE%^puddle of water");
  icicle->set_long("%^BOLD%^%^CYAN%^It is freezing and expanding beneath the surface of the ice, causing the ice to buckle and crack.");
  call_out("shatter_floor", 8, icicle);
}

void shatter_floor(object icicle) {
  message("info", "The %^BOLD%^%^CYAN%^ice%^RESET%^ covering the %^BOLD%^%^CYAN%^freezing %^RESET%^%^BLUE%^puddle of water%^RESET%^ %^YELLOW%^EXPLODES%^RESET%^ with tremendous force, sending %^BOLD%^%^CYAN%^ice shards%^RESET%^ everywhere.", this_object());
  icicle->remove();
  new(DRAG_ITEMS"caveob")->move(this_object());
  stoneProgress = STONE_RELEASED;
  call_out("do_conversation", 14, this_player(), ({
    "%^CYAN%^Daroq says:%^RESET%^ Very good.", 5,
    "%^CYAN%^Daroq says:%^RESET%^ That stone will prove more useful to you than you know.", 7,
    "%^CYAN%^Daroq says:%^RESET%^ If, at any point, you feel that it would be in your best interest to <escape> from the cave, you should find the stone to be your best friend.", 12,
    "%^CYAN%^Daroq says:%^RESET%^ Let's continue.", 4,
    "%^CYAN%^Daroq says:%^RESET%^ That stone contains within it a great power.", 6,
    "%^CYAN%^Daroq says:%^RESET%^ Your next challenge lays before you.", 5,
    "%^CYAN%^Daroq says:%^RESET%^ Take up the stone and release its power upon the northern cave wall.", 8,
  }) );
}

int stop_stupid_gets(string str) {
  if(present(str, this_object()) || member_array(' ', str)!=-1) return 0;
  if(str == "stone" && stoneProgress < STONE_RELEASED) {
    write("The stone is beyond your reach, as it is covered by the ice.");
    return 1;
  }
  if(str == "icicle" && stoneProgress < ICICLE_FALLING) {
    write("The icicle is beyond your reach, it is too high above you.");
    return 1;
  }
  return 0;
}

int jump_does_nothing(string str) {
  if((str == "icicle" || str == "on icicle") && stoneProgress == ICICLE_IN_GROUND) {
    write("You jump up and down on the icicle, but it doesn't budge.");
    return 1;
  }
  if(stoneProgress < ICICLE_FALLING && (!str || str == "")) {
    write("You cannot jump high enough to reach the icicle above you.");
    return 1;
  }
  return 0;
}

int use_stone_on_wall(string str) {
  object stone;
  string stoneName;
  if(str == "stone") return notify_fail("You need a target for that.\n");
  if(str && sscanf(str, "%s on %s", stoneName, str) != 2) return 0;
  stone = present(stoneName, this_player());
  if(!stone) return notify_fail("What "+stoneName+"?\n");
  if(file_name(stone)[0..sizeof(DRAG_ITEMS"caveob")-1] != DRAG_ITEMS"caveob")
    return notify_fail(query_verb()+"ing a "+stoneName+" would do no good.\n");
  if(str != "wall" && str != "north wall" && str != "north cave wall" && str != "cave wall")
    return notify_fail(query_verb()+"ing the stone on "+str+" would not help.\n");

  DRAG_D->set_data("cavestage:"+this_player()->query_name(), 5);
  message("info", "%^BOLD%^%^YELLOW%^A bright light shoots forth from the stone, obliterating the northern cave wall!%^RESET%^", this_object());
  message("info", "A strong, cold wind blows in through the gaping hole in the wall, knocking you to the floor and obscuring your vision.", this_object());
  this_player()->move(DRAG_ROOMS"py/maze/01");
  all_inventory(this_object())->move(environment(this_player()));
  foreach(object ob in all_inventory(environment(this_player()))) {
    if(!ob->is_player()) continue;
    ob->set_rest_type(SIT);
    harm_player(ob, 100);
  }
  return 1;
}

int break_wall_with_stone(string str) {
  string stoneName;
  if(str && sscanf(str, "%s with %s", str, stoneName) == 2);
  return use_stone_on_wall(stoneName+" on "+str);
}
