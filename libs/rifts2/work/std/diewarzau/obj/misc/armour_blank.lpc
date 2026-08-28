//    A weapon blank

inherit "/std/Object";

void create() {
  ::create();
  set_name("blank");
  set_id(({ "armour blank", "blank" }));
  set_long("This armour blank may be forged into armour.  Of course.");
  set_weight(70);
  return;
}

int id(string str) {
  if(::id(str)) return 1;
  if(::id(replace_string(str, query_property("material_name")+" ", ""))) return 1;
  return 0;
}

int query_value() {
  if(this_object()->prop("value")) return 2*(int)this_object()->prop("value");
  else return ::query_value();
}

float query_float_value() {
  if(this_object()->prop("value")) return to_float(2*(int)this_object()->prop("value"));
  else return ::query_float_value();
}

string query_short() {
  return capitalize(article(query_property("material_name") + " armour blank"));
}

