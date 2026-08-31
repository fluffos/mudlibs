int clean_up(int arg)
{
  object o;
  if(this_object()->query_property("no_clean_up")) return 0; // don't try again
  o=first_inventory(this_object());
  while(o)
  {
    if(!query_once_interactive(o) // is a player
        || o->query_property("no_clean_up")
        || ((int)o->query_hp() != (int)o->query_max_hp())) // injured monster
        return 1;
    o=next_inventory(o);
  }
  map_array(deep_inventory(this_object()), #'destruct);
  destruct(this_object());
  return 1;
}
