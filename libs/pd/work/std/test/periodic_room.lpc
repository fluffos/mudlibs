
#include <teststd.h>
#include <daemons.h>

inherit ROOM;

int period_len = 1;

void set_period(int x);
int query_period();
void do_periodic();
int periodic();

void create() {
  room::create();
  period_len = 1;
  do_periodic();
}

void init() {
  room::init();
  do_periodic();
}

void set_period(int x) { period_len = (x >= 0 ? x : 0); }
int query_period() { return period_len; }

void do_periodic() {
  if (file_name(previous_object()) != DELAY_D &&
      DELAY_D->query_delay_time(this_object(), "do_periodic"))
        return;
  if (query_period() && this_object()->periodic())
    DELAY_D->add_delay(2*query_period(), this_object(), "do_periodic", ({}), 0);
}

// by default don't do anything, this must be overridden in the rooms
int periodic() { return 0; }
