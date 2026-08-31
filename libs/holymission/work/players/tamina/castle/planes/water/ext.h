extinguish() {
object everything;
int i;

  if(!present("lighted_torch",this_player())) return;
  everything=all_inventory(this_player());
  for(i=0; i<sizeof(everything); i=i+1) {
    if(everything[i]->id("lighted_torch")) everything[i]->out();
  }
}
