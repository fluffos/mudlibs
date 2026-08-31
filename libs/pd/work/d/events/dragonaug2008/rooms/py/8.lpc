
#include <std.h>
#include <dragonevent.h>
#include <daemons.h>
#include <dirs.h>

inherit DRAG_ROOMS+"py/base";

int tp_here(object);

int check_collapse();
int check_rolled(object);
int check_covered(object);

int allow_roll(object);
int allow_cover(object);

int cant_fly(string);
int do_roll(string);
int do_cover(string);

int can_leave = 0;
int can_roll = 0;
int can_cover = 0;

int collapsed = 0;
int rolled = 0;
int covered = 0;
int falling = 0;

mixed *scene = ({
  "As you begin to crawl, the walls and ground begin to shake violently!\n\n"
  "A large pile of rocks falls behind you, blocking the way to the outside!\n",
  8,
  "Small bits of rock begin to break off of the ceiling and fall on your head!\n",
  8,
  "A large crack starts to form in the ceiling!\n",
  4,
  "The earth shakes, the crack spreads and larger pieces of rock pelt you!\n",
  4,
  "FUNC:allow_roll",
  4,
  "The chunk of rock falls straight towards you!\n",
  4,
  "FUNC:check_rolled",
  8,
  "Larger shockwaves jolt through the tunnel, dislodging more of the sides.\n",
  4,
  "FUNC:allow_cover",
  6,
  "FUNC:check_covered",
  6,
  "A few more aftershocks shake you around.\n",
  8,
  "The earthquakes begin to taper off.\n",
  4,
  "FUNC:check_blind1",
  4,
  "FUNC:check_blind2",
  4,
  "FUNC:start_fall",
  6,
  "FUNC:end_fall",
  0,
});

void create() {
  ::create();
  set_properties(([ "indoors" : 1, "mountain" : 1, "light" : 1, "no teleport" : 1, "no scry" : 1 ]));
  set_short("crawling in a narrow tunnel");
  set_long(
    "This is a narrow tunnel that leads down through the rock. "
    "All around is nothing but rock. A bit of light shines in from outside, "
    "but further ahead it gets darker."
  );
  set_items( ([
    "rock" : "Plain old rock. Some bits are a little rough and some are brownish, "
      "but there's nothing very remarkable about it.",
    ({ "light", "outside" }) : "The western exit leads back outside, and the light "
      "shines from out that way.",
    "ahead" : "Deeper into the tunnel, to the east, the light doesn't penetrate.",
  ]) );
  set_exits( ([
    "west" : DRAG_ROOMS+"py/6",
    "east" : DRAG_ROOMS+"py/9",
  ]) );
  add_pre_exit_function("east", "check_collapse");
}

void init() {
  ::init();
  add_action("do_roll", ({ "slide", "roll", "crawl", "dodge", "scurry", "avoid" }) );
  add_action("do_cover", ({ "cover", "protect", "hide", "wrap" }) );
  add_action("cant_fly", "fly");
}

int cant_fly(string str) {
  if (load_object(DIR_CLASS_CMDS+"/_fly")->abil()) {
    message("info", "There is not enough room here "
        "to spread your wings!", this_player());
    return 1;
  }
  return 0;
}

int do_roll(string str) {
  object tp = this_player();
  string verb = query_verb();

  if (!can_roll) return 0;

  else if (rolled) {
    message("info", "You are already trying to avoid the rocks!", tp);
  }

  else if (member_array(verb, ({ "dodge", "avoid" }) )!= -1 && str && member_array(str, ({
      "away", "east", "aside", "sideways", "out of the way", "rocks", "rock", "ceiling",
      "west", "north", "south", "e", "w", "n", "s",
      }) ) == -1) {
        
        message("info", "You can't dodge that way!\n", tp);

  }

  else if (str && member_array(str, ({
      "away", "east", "aside", "sideways", "out of the way", 
      }) ) == -1) {

        message("info", "You can't "+verb+" that way here!\n", tp);
  }

  else if (!str && member_array(verb, ({ "crawl", "scurry", "slide" })) != -1) {
    message("info", capitalize(verb)+" where?", tp);
  }

  else {
    rolled = 1;
    message("info", "You "+verb+" "+(str?str+" ":"")+"quickly to avoid the rocks!", tp);
  }
  return 1;
}

int do_cover(string str) {
  object tp = this_player();
  string verb = query_verb();
  string what, thing;
  object ob;

  if (!can_cover) return 0;

  if (covered) {
    message("info", "You are already trying to keep the dust out.", tp);
  }

  else if (!str) {
    message("info", "Wrap what?", tp);
  }

  else if (verb == "wrap" || verb == "cover") {
    if (str == "face")
      return notify_fail(capitalize(verb)+" it with what?\n");
    if (sscanf(str, "%s with %s", what, thing) != 2)
      return notify_fail(capitalize(verb)+" what with what?\n");
    if (!(ob = present(thing, tp)))
      return notify_fail("You don't have "+indefinite_article(thing)+"!\n");
    if (!ob->is_armour())
      return notify_fail("That would not be suitable for the task!\n");
    message("info", "You wrap your face with "+indefinite_article(thing)+".", tp);
    covered = 1;
  }

  else if (str != "face")
    message("info","That wouldn't help you much right now!", tp);

  else {
    message("info", "You "+verb+" your face to keep the dust out.", tp);
    covered = 1;
  }
  return 1;
}

int check_collapse() {
  object tp = this_player();
  if (!collapsed) {
    collapsed = 1;
    do_conversation(tp, scene);
    set_long(
      "This is a narrow tunnel that leads down through the rock. "
      "All around is nothing but rock. The ground and walls are shaking."
    );
    remove_property("light");
    set_property("light", 0);
    // to remove the down exit that leads here
    find_object(query_exit("west"))->clean_up();
    remove_exit("west");
    return 0;
  }
  else if (can_leave)
    return 1;
  else if (!falling) {
    message("info", "The ground shakes violently as you try to leave, knocking your head "
        "against the jagged ceiling!", tp);
    harm_player(tp, 40+random(30));
    return 0;
  }
  else
    return 0;
}

int allow_roll(object tp) {
  if (!tp_here(tp)) return 0;
  can_roll = 1;
  message("info",
    "Suddenly a huge chunk of the ceiling breaks loose!\n",
  tp);
  set_item("ceiling", "A huge chunk of it is falling right at you!");
  return 1;
}

int check_rolled(object tp) {
  if (!tp_here(tp)) return 0;
  if (!rolled) {
    message("info", "Your body is crushed horribly as the rocks smash into you!\n", tp);
    set_player_hp(tp, -(12000+random(500)));
    return 0;
  }
  message("info", "The rocks smash into the floor just beside you!\n", tp);
  remove_item("ceiling");
  set_item("rocks", "Some rocks that have fallen from the walls and ceiling.");
  can_roll = 0;
  rolled = 0;
  return 1;
}

int allow_cover(object tp) {
  if (!tp_here(tp)) return 0;
  can_cover = 1;
  message("info",
    "A flurry of dust sprays towards your face from every direction!\n",
  tp);
  return 1;
}

int check_covered(object tp) {
  if (!tp_here(tp)) return 0;
  if (!covered) {
    message("info", "The thick dust puffs into your face, "
        "blinding you and making it hard to breathe!", tp);
    if (!harm_player(tp, 80+random(25)))
      return 0;
    tp->set_blind(1);
    DELAY_D->add_delay(16+random(16), tp, "set_blind", 0, 0);
  }
  else
    message("info", "The thick dust puffs around your head, "
      "but doesn't cause any problems.", tp);

  set_item("dust", "A greyish fog of dust which floats in the air.");
  set_smell("default", "Thick dust fills the air with a dry, dirty smell.");
  can_cover = 0;
  covered = 0;
  return 1;
}

int check_blind1(object tp) {
  if (!tp_here(tp)) return 0;
  if (tp->query_blind())
    message("listen", "A cracking noise can be heard.", tp);
  else
    message("info", "The ground beneath you begins to crack.", tp);
  can_leave = 1;
  return 1;
}

int check_blind2(object tp) {
  if (!tp_here(tp)) return 0;
  if (tp->query_blind())
    message("touch", "The ground beneath your hand crumbles away.", tp);
  else
    message("info", "The floor begins to give way!", tp);
  return 1;
}

int start_fall(object tp) {
  if (!tp_here(tp)) return 0;
  message("info", "The entire floor cracks apart and falls away beneath you!", tp);
  set_long(
    "You are falling down through a rocky cave, with small bits of debris flying by. "
    "A pit full of sharp stalagmites is rushing up to impale you."
  );
  set_short("falling");
  set_items( ([
    "cave" : "An enclosed space within the rock.",
    "debris" : "Rocks and dust falling through the air.",
    "pit" : "The pit is below and is full of sharp stalagmites.",
    "stalagmites" : "They are needle sharp and about to impale you.",
  ]) );
  remove_smell("default");
  remove_exit("east");
  can_leave = 0;
  falling = 1;
  return 1;
}

int end_fall(object tp) {
  if (!tp_here(tp)) return 0;
  message("info", "You land directly on a stalagmite which stabs "
      "through your heart, killing you instantly.", tp);
  set_player_hp(tp, -(9000+random(800)));
  falling = 0;
  return 0;
}

int tp_here(object tp) {
  if (!tp || !environment(tp) || environment(tp) != this_object()) return 0;
  return 1;
}

