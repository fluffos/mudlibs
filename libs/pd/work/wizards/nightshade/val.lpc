#include <std.h>

#define TYPES ({ "The valentine is in the shape of a heart, bound in a smooth red silk.  The outside edge is bordered in a beautiful white lace.  It looks like you can open it and <read valentine>.", \
                 "This valentine looks like a rose at first, with large, deep red petals.  Upon closer inspection, the petals open up to reveal a message.  You can <read valentine> to see what it says.", \
                 "The valentine is a small card with a flowing calligraphy on the cover that says \"Every time you smile at someone, it is an action of love, a gift to that person, a beautiful thing.\".  You can open the card and <read valentine>.", \
                 "This valentine is a cute stuffed teddy bear with small black eyes and a smile on it's face.  It's holding its belly where a message has been written.  Perhaps you could read it." })

inherit OBJECT;

string who, from;
int type;

void create() {
  ::create();
  set_name("a valentine");
  set_id( ({ "valentine", "card" }) );
  set_long("This valentine card is blank!");
  set_short("a valentine from error");
  set_weight(1);
  set_curr_value("gold", 0);
  set_property("no steal", 1);
  set("no store", 1);
}

void set_to(string str) { who = str; }

void set_from(string str) { from = str; set_id(query_id()+({"valentine from "+from})); }

void set_type(int i) { type = i; }

void init_arg(mixed *stuff) {
  who = stuff[0];
  from = stuff[1];
  set_id(query_id()+({"valentine from "+from}));
  set_short("a valentine from "+capitalize(from));
  set("read", stuff[2]);
  type = stuff[3];
  set_long(TYPES[type]);
}

mixed *query_auto_load() {
  if(this_player()->query_name() == who ||
     this_player()->query_name() == from)
    return ({ base_name(this_object()), ({ who, from, query("read"), type }) });
  return 0;
}
