#include <std.h>

inherit ARMOUR;

int query_arrows();
int query_max_arrows();
int is_quiver();
int use_arrow();
void set_arrows(int x);
void set_max_arrows(int x);

int arrows, max_arrows;

void create() {
  ::create();
  ::set_type("quiver");
  arrows = 12;
  max_arrows = 24;
}

int query_arrows() {
  return arrows;
}

int query_max_arrows() {
  return max_arrows;
}

string query_long() {
  string ret;
  ret = ::query_long();
  ret += "\n\n  The quiver has "+arrows;
  if(arrows == 1)
    ret += " arrow left.";
  else
    ret += " arrows left.";
  return ret;
}

void set_type(string str) { return; }

int is_quiver() { return 1; }

int use_arrow() {
  if(arrows <= 0)
    return 0;
  arrows--;
  return 1;
}

void set_arrows(int x) {
  if (x < 0)
    arrows = 0;
  else if (x > max_arrows)
    arrows = max_arrows;
  else
    arrows = x;
}

void set_max_arrows(int x) {
  if (x < 1)
    max_arrows = 1;
  else
    max_arrows = x;
}

