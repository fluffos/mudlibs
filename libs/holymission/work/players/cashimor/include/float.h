string floats;

float_down() {
object all;
int i;

  if(!floats) return;
  all=all_inventory(this_object());
  for(i=0; i<sizeof(all); i=i+1) {
    if((all[i]->get())&&(all[i]->query_weight())) {
      move_object(all[i],floats);
      if(!all[i]->short()) return;
      tell_room(this_object(),
        all[i]->short()+" floats down.\n");
      tell_room(environment(all[i]),
        "Something comes floating down.\n");
    }
  }
}
