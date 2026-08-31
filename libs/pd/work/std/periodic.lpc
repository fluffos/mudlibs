
#include <std.h>
#include <daemons.h>

int period_len = 1;
int immediate = 0;

void set_period(int x);
int query_period();
void set_immediate(int x);
int query_immediate();
void do_periodic();
int periodic();

void create() {
  period_len = 1;
  immediate = 0;
}

void init() {
  if (immediate)
    do_periodic();
  else
    DELAY_D->add_delay(2*query_period(), this_object(), "do_periodic", ({}), 0);
}

void set_period(int x) { period_len = (x >= 0 ? x : 0); }
int query_period() { return period_len; }
void set_immediate(int x) { immediate = (x ? 1 : 0); }
int query_immediate() { return immediate; }

void do_periodic() {
  if (file_name(previous_object()) != DELAY_D &&
      DELAY_D->query_delay_time(this_object(), "do_periodic"))
        return;
  if (query_period() && this_object()->periodic())
    DELAY_D->add_delay(2*query_period(), this_object(), "do_periodic", ({}), 0);
}

// by default don't do anything, this must be overridden by inheriting objects
int periodic() { return 0; }
