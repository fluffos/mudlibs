/*
 * bin/tools/soul_fakeitem
 *
 * A helper item for the soul to handle fakeitems better.
 * Coogan, 14-Jul-01
 *
 */
 
#pragma strong_types

inherit "basic/description";
inherit "basic/plural";
inherit "basic/id";

void set_name(string n) {
  description::set_name(n);
  set_short(n);
  set_id(n);
}

int query_no_article() {
  return 1;
}

void selfdestruct() {
  destruct(this_object());
}

void reset(status arg) {
  if (arg)
    return;
  call_out("selfdestruct", 0);
}

