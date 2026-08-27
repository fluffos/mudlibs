inherit "/std/object";

void setup()
{
  set_weight(0);
  set_value(0);
  reset_drop();
}

int query_auto_load() { return 1; }

init()
{
  ::init();
   this_player()->add_timed_property("atacar_puerta",1,9999999999);
   this_player()->add_timed_property("guardias_anduar",1,9999999999);
   this_player()->add_timed_property("guardias_camino",1,9999999999);
   this_player()->add_timed_property("castillo_takome",1,9999999999);
   this_player()->add_timed_property("odiado_ARBRE",1,9999999999);
  add_action("voy_matar","equip");
  add_action("voy_matar","wear");
}

voy_matar(string arg)
{
   this_player()->add_timed_property("atacar_puerta",1,9999999999);
   this_player()->add_timed_property("guardias_anduar",1,9999999999);
   this_player()->add_timed_property("guardias_camino",1,9999999999);
   this_player()->add_timed_property("castillo_takome",1,9999999999);
   this_player()->add_timed_property("odiado_ARBRE",1,9999999999);
  return 0;
}
