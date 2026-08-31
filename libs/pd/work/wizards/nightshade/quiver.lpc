#include <std.h>

inherit ARMOUR;

int query_arrows();
int is_quiver();
int use_arrow();
void set_arrows(int x);

int arrows;

void create() {
  ::create();
  ::set_type("quiver");
  arrows = 12;
}

int query_arrows() {
  return arrows;
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
  if(x > 12 || x < 0)
    x = 12;
  arrows = 12;
}
