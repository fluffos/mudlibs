see(str) {            /* You can see in the dark */
  object room,obj;
  int count;
 
  if(!str) {
    room=ENV(TP);
    if(set_light(0)<1) {
      write("You concentrate the Force.\nIn your mind you can see:\n\n");
    }
    set_light(5);
    room->long();
    set_light(-5);
    count=0;
    obj=first_inventory(room);
    while(obj) {
      if(obj!=TP && obj->short())
        write(obj->short()+".\n");
      if((obj->query_invis() || !obj->short()) && living(obj) && obj!=TP
          && !obj->query_wizard())
        count++;
      obj=next_inventory(obj);
    }
    if(count>0)
      write("You feel the presence of something you can't see.\n");
    return 1;
  }
  if(set_light(0)<1) {
    write("You close your eyes and see:\n");
  }
  set_light(5);
  TP->look(str);
  set_light(-5);
  return 1;
}
 
inv() {                   /* you can see your inventory */
  object obj;
  if(set_light(0)<1) {
    write("You can feel the items you carry.\nYou carry:\n");
  }
  obj=first_inventory(TP);
  while(obj) {
    if(obj->short())
      write(obj->short()+".\n");
    obj=next_inventory(obj);
  }
  return 1;
}
 
find(str) {
  string where;
  object obj;
  if(!str) return ;
 
  obj=find_living(str);
  if(!obj) {
    write("You concentrate hard, but you fail to find "+CAP(str)+".\n");
    return 1;
  }
  else
  {
    write("You close your eyes and let the Force search for "+CAP(str)+
      ".\n"+CAP(obj->PRO)+" is at :\n");
    where=environment(obj);
    if(!where) {
      write("You don't see anything.\n");
      return 1;
    }
 
    where->long();
    if(!obj->query_npc()) write(obj->NAME+" is a Player.\n");
    return 1;
  }
}
 
take(str) {
  set_light(5);
  TP->pick_up(str);
  set_light(-5);
  return 1;
}
 
putting(str) {
  set_light(5);
  TP->put(str);
  set_light(-5);
  return 1;
}
 
giving(str) {
  set_light(5);
  TP->give_object(str);
  set_light(-5);
  return 1;
}
