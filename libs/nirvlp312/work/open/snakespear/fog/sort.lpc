object *sort_array(object *obs,string func) {
  object *new_list;
  int size;
  object highest;
  mixed max_value;
  mixed value;
  int ticks;
  int i;

  new_list=allocate(0);
  while(sizeof(obs) > 0 && ticks < 100) {
    size=sizeof(obs);
    for(i=0; i < size; i++) {
      value=(mixed)call_other(obs[i],func);
      if(value > max_value) {
        max_value=value;
        highest=obs[i];
      }
    }
    new_list+=({ highest });
    obs-=({ highest });
    max_value=0;

    ticks++;
  }
  return new_list;
}
