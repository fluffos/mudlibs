#include <daemons.h>

int query_gagged() {
  mixed x;
  string pri = IDENTITY_D->search_primary(this_object());

  if (!pri) {
    if (x = this_object()->query_property("gagged")) return x;
    return 0;
  }
  else {
    x = IDENTITY_D->query_setting(pri, "gag");
    if (stringp(x) && x == "on") return -1;
    if (intp(x)) return x;
    return 0;
  }
  return 0;
}

void set_gagged(mixed x) {
  string pri = IDENTITY_D->search_primary(this_object());

  if (intp(x) && x == 1) x = -1;
  if (stringp(x)) {
    if (x == "on") x = -1;
    else x = 0;
  }

  if (!pri) {
    this_object()->remove_property("gagged");
    this_object()->set_property("gagged", x);
  }
  else {
    IDENTITY_D->add_setting(pri, "gag", x);
  }
}
