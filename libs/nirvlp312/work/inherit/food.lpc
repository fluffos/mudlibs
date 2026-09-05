inherit "inherit/base/consume";

string query_object_type() { return "Food"; }
status query_food()        { return 1;      }

void reset(status arg) {
  if (arg) return;

  set_sell_destruct(1);
  set_name("bread");
  set_short("A stale loaf of bread");
  set_long("It looks a little moldy.\n");
  set_room_msg(
   "@@query_name:$this_player()$@@ munches on some " +
   "@@query_name:$this_object()$@@.\n");
  set_consumer_msg("Yum yum!!\n");
  set_strength(2);
}

void init() {
  ::init();
  if (environment() != this_player()) return;
  add_action("eat", "eat");
}

status eat(string str) {
  object tp, ob;

  tp = this_player();

  if (!str) {
    write("Eat what?\n");
    return 1;
  }
  if (!(ob = present(str,tp))) {
    if (!str) str = "food";
    write("You don't have any " + str + " to eat.\n");
    return 1;
  }

  if (ob != this_object()) return 0;

  if ((int)tp->query_constitution() * 8 < strength) {
    write("You realize even before trying that you'll never be able to eat" +
          " all this.\n");
    return 1;
  }
  if (!tp->eat_food(strength)) return 1;
  ::consume(str);
  destruct(this_object());
  return 1;
}

void set_eater_mess(string str) { set_consumer_msg(str); }
void set_eating_mess(string str) { set_room_msg(str);    }

