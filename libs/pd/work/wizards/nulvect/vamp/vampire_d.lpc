
#include <std.h>

#define VAMPSAVE DIR_DAEMONS_SAVE+"/vampire"

inherit DAEMON;

int num_vamps = 0;

void create() {
  num_vamps = 0;
  restore_object(VAMPSAVE);
}

int query_num_vamps() { return num_vamps; }
void set_num_vamps(int n) {
  num_vamps = n;
  save_object(VAMPSAVE);
}

void check_vamp_sub(object who) {
  if (!tp || tp->query_race() != "vampire") return;

}

