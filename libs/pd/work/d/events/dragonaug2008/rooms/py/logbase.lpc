#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/base";

object player;
int printStatus;

void create() {
  ::create();
  set_heart_beat(1);
}

void init() {
  ::init();
  if(!player) {
    player = this_player();
    printStatus = 0;
  }
  if(present(player)) set_heart_beat(1);
}

int accept_player_into_instance(object play) {
  if(!player) player = play;
  write("The log trembles uneasily in the breeze.");
  return 1;
}

void set_print_status(int i) { printStatus = i; }
int query_print_status() { return printStatus; }

void print_status() {
  int i;
  string out = "%^BOLD%^%^GREEN%^The log is ";
  if(!player) return;
  i = DRAG_D->query_data("cavelogsway:"+player->query_name());
  if((i>0?i:-i) < 2) out += "relatively centered.";
  else {
    out += "leaning";
    if((i>0?i:-i) < 4) out += " slightly";
    else if((i>0?i:-i) < 6) out += "";
    else if((i>0?i:-i) < 8) out += " extremely";
    else out += " nearly entirely";
    out += " to the %^RESET%^%^YELLOW%^";
    if(i < 0) out += "west";
    else out += "east";
    out += "%^RESET%^%^BOLD%^%^GREEN%^.";
  }
  SAY(out);
  set_print_status(0);
}

void heart_beat() {
  int i;
  if(!player || !present(player)) {
    set_heart_beat(0);
    return;
  }

  i = DRAG_D->query_data("cavelogsway:"+player->query_name());
  if(random(1000) > 750) {
    SAY("%^BOLD%^%^BLUE%^The log sways gently in the %^WHITE%^wind%^BLUE%^.");
    printStatus = 1;
    i += random(7)-3;
    DRAG_D->set_data("cavelogsway:"+player->query_name(), i);
  }

  if(i < -10 || i > 10) {
    SAY("The log becomes unstable and begins to plummet!");
    player->move(DRAG_ROOMS"py/fall4");
    all_inventory(this_object())->move(environment(player));
    return;
  }
  //inheriting files should print_status at the end of heart_beat()
}
