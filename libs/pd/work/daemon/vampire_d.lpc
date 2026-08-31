
#include <std.h>
#include <dirs.h>
#include <daemons.h>

#define VAMPSAVE DIR_DAEMONS_SAVE+"/vampire"

inherit DAEMON;

int num_vamps = 0;

void create() {
  num_vamps = 0;
  set_heart_beat(2);
  restore_object(VAMPSAVE);
}

int query_num_vamps() { return num_vamps; }
void set_num_vamps(int n) {
  num_vamps = n;
  save_object(VAMPSAVE);
}

void check_vamp_sub(object who) {
  if (!who || who->query_race() != "vampire") return;

}

int query_sunlight(object who) {
  if (!who || !environment(who)) return 0;
  if (environment(who)->query_property("indoors")) return 0;
  if (query_night()) return 0;
  return 1;
}

void heart_beat() {
  object *vamps;
  int div;

  vamps = filter(users(), (: $1->query_race() == "vampire" :) );

  if (regexp(EVENTS_D->query_time_of_day(), "dawn|twilight")) div = 14;
  else div = 12;

  foreach (object v in vamps) {
    if (query_sunlight(v) && !v->query("vaporform_abil")) {
      v->add_hp(-random(v->query_max_hp()/div));
      message("info", "The %^YELLOW%^sun%^RESET%^ burns your %^BOLD%^%^RED%^flesh%^RESET%^.", v);
      message("info", v->query_cap_name()+" is %^BOLD%^%^RED%^burned%^RESET%^ by the %^YELLOW%^sun%^RESET%^.", environment(v), v);
    }
  }

  if (random(1000) < 275) {
    switch (query_heart_beat()) {
      case 3: set_heart_beat(2); break;
      case 2:
      default: set_heart_beat(3); break;
    }
  }
}
