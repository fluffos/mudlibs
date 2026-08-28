//  Incomplete creation.

inherit "/std/Object";

void create() {
  ::create();
  set_name("creation");
  set_short("creation");
  set_id(({ "creation" }));
  set_long("This is an incomplete magical creation.");
  set_weight(100);
  set_value(10000);
  return;
}

int restore_me(string file) {
  int res;
  
  res = ::restore_me(file);
  if(query_property("type")) this_object()->set_type((string)query_property("type"));
  return res;
}

void set_type(string type) {
  set_property("type", type);
  set_id(({ "incomplete "+type, "creation", type }));
  set_short("An incomplete "+query_property("material_name")+" "+type);
  return;
}

int id(string str) {
  if(::id(str)) return 1;
  return ::id(replace_string(str, query_property("material_name")+" ", ""));
}

