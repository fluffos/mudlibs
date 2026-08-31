#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/logbase";

int count;

void create() {
  ::create();
  set_long("The eastern edge of the log. The center of the hollowed out log lays to the west. To the east, you can see a great many trees with strange objects hanging from their branches. There are vines on the trees close by. The bushes on the ground far below the log rustle slowly. The log appears to be balancing precariously on the large, thick branch of a tree nestled against the log to the north.");
  set_items( ([
    "log" : "You are standing within it.",
    ({"trees","tree"}) : "The trees are covered with strange markings.",
    ({"markings","marking"}) : "The trees are covered with strange markings. You can't make out what they mean.",
    ({"object", "objects"}) : "Dark objects litter the tree tops.",
    "branch" : "A thick branch that the log you are standing in teeters on top of like a fulcrum.",
    "vines" : "They cover the trees.",
  ]) );
  set_exits( ([
    "west" : DRAG_ROOMS"py/fall5",
  ]) );
  count = 0;
}

void init() {
  ::init();
  add_action("do_jump", "jump");
}

void heart_beat() {
  ::heart_beat();
  if(!player || !present(player)) return;

  count ++;

  if(count >= 1+random(4)) {
    int i = DRAG_D->query_data("cavelogsway:"+player->query_name());
    i += 1+random(2);
    DRAG_D->set_data("cavelogsway:"+player->query_name(), i);
    SAY("%^ORANGE%^Your weight pushes the log down slightly.");
    set_print_status(1);
    count = 0;
  }

  if (query_print_status())
    print_status();
}

int do_jump(string str) {
  if(!str) {
    write("Jump where?");
    return 1;
  }
  if(str != "out" && str != "east" && str != "down") return 0;

  write("You leap into the air!");
  this_player()->move(DRAG_ROOMS"py/fall8", "out of the log");
  return 1;
}
