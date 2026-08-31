
#include <std.h>
#include <saahr.h>

inherit VAULT;

int hook;

string look_hook();
int get_hook(string str);

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "A well made bed takes up the back wall of the house, with a "
    "wood stove sitting against the eastern wall. Shelves of spices "
    "line the rest of the wall around the stove. A large rocking chair "
    "sits opposite the stove. A few balls of yarn lie around the foot "
    "of the chair. Two large windows in the front are covered by curtains "
    "with yellow flower designs."
  );
  set_items(([
    "bed" : "A fine bed with a sturdy wooden frame and a thick blanket "
      "spread over the top.",
    "stove" : "The heavy metal stove is made for burning wood. "
      "It serves both to cook food and to keep the house warm.",
    "shelves" : "Basic wooden shelves with nicely rounded edges. "
      "They hold spices for cooking.",
    "spices" : "Salt, pepper, rosemary, sage, and a variety of other "
      "ingredients to make dull foods more appetizing.",
    ({ "windows", "curtains" }) : "The windows are covered "
      "with large curtains. The curtains have big yellow flowers "
      "all over them.",
    "chair" : "A very finely crafted chair with curly designs on the "
      "arms and feet.",
    "yarn" : "Several different colors of yarn sit around, some with "
      "crochet hooks sticking out of them.",
    ({ "hooks", "crochet hooks" }) : (: look_hook :),
  ]));
  set_exits(([
    "out":VPROOMS"town10_9"
  ]));
  load_object(query_exit("out"));
  hook = 1;
}

void reset() {
  ::reset();
  if (!present("nymph"))
    new(MOBS"nymph")->move(this_object());
  hook = 1;
}

void init() {
  ::init();
  if (hook)
    add_action("get_hook", ({ "get", "take" }) );
}

string look_hook() {
  if (hook)
    return "You see one crochet hook that looks a bit sharp.";
  else
    return "Normal crochet hooks. They aren't very sharp.";
}

int get_hook(string str) {
  object tp = this_player();
  object env = environment(tp);
  object h;

  if ((str == "hook" || str == "crochet hook") && h = new(WEP"hook")) {
    message("info", "You grab the sharpest looking crochet hook.", tp);
    message("info", tp->query_cap_name()+" grabs a sharp looking crochet hook "
      "from the yarn.", env, tp);
    if (h->move(tp)) {
      h->move(env);
      message("info", "You are overburdened, and drop it.", tp);
      message("info", tp->query_cap_name()+" drops the hook.", env, tp);
    }
    hook = 0;
    remove_action("get_hook", "get");
    remove_action("get_hook", "take");
    return 1;
  }
  
  return 0;
}
