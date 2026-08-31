#include <std.h>

#define UNHOLY_MAIN_HALL "/d/guilds/unholy/hall"

inherit ROOM;
int do_scry(string str);
string query_room_description(object where);

void create() {
  ::create();
  set_properties((["indoors":1, "light":2]));
  set_short("An endless pool of black");
  set_long("The only ground here is the enormous index finger of the demon. "
           "It is dipped into an inky black pool, which seems to spread endlessly "
           "in all directions. Only a vaulted ceiling of rock can be seen above. "
           "The pool itself is completely still and dark. The finger leads back to "
           "the main hall.");
  set_items(([
              ({"ground","finger","index finger"}) : "Solid demon flesh underfoot.",
              ({"pool","black pool","inky black pool"}) : "Not a ripple stirs on its "
                                                          "surface, and nothing - not "
                                                          "even the demon's finger - "
                                                          "can be seen in its depths.",
              ({"ceiling","rock","above"}) : "The rocky ceiling is far overhead and soon "
                                             "fades into darkness in all directions.",
              "hall" : "The main meeting area of the guild."
            ]));
  set_listen("default","Silence and stillness.");
  set_exits((["southwest": UNHOLY_MAIN_HALL]));
}

void init() {
  ::init();
  add_action("do_scry", "scry");
}

int do_scry(string str) {
  object tp=this_player();
  object tgt;
  object env;
  string msg;

  if (!str || str=="") return notify_fail("Scry who?");

  if (!(tgt=find_player(str)) || !(env=environment(tgt)) ||
      env->query_property("no scry") ||
      env->query_property("no teleport")) msg="You see nothing.";

  else msg=query_room_description(env);

  message("scry","You gaze into the black pool and concentrate on "+tgt->query_cap_name()+"...\n\n",tp);
  message("scry",msg,tp);

  return 1;
}

string query_room_description(object where) {
  object *inv;
  string *livings=({}), *items=({});
  string desc;
  int i;

  if (!where) where=this_object();

  inv=all_inventory(where);

  for (i=sizeof(inv)-1;i>=0;i--) {
    if (inv[i]->query_short() != "0") {
      if (inv[i]->is_living()) livings+=({"%^BOLD%^%^RED%^"+inv[i]->query_short()+"%^RESET%^"});
      else items+=({"%^BOLD%^%^MAGENTA%^"+inv[i]->query_short()+"%^RESET%^"});
    }
  }

  desc=where->query_short()+"\n";
  desc+=where->query_long()+"\n\n";
  desc+=implode(livings, ", ")+"\n\n";
  desc+=implode(items, ", ")+"\n\n";

  return desc;
}
