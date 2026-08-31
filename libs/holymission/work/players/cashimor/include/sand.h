#define MAX_SAND_LEVEL 4

int sand_level;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    sand_level=MAX_SAND_LEVEL;
    smell="There is a lot of sanddust in the air.";
  }
  else {
    add_sand();
  }
}

id(str) {
  if(str=="sand") return 1;
  return ::id(str);
}

add_sand() {
object who;
int i;

  if(query_full()) return 1;
  if(sand_level==MAX_SAND_LEVEL-1) {
    who=all_inventory(this_object());
    for(i=0;i<sizeof(who);i++) if(living(who[i])) return 1;
  }
  sand_level++;
  tell_room(this_object(),"Some sand settles.\n");
  return 0;
}

find_dir(str) {
int i;

  for(i=1;i<sizeof(dest_dir);i+=2) if(str==dest_dir[i]) return i;
  return 0;
}

move(str) {
int i;

  if(!str) str=query_verb();
  i=find_dir(str);
  if(!i) {
    notify_fail("Where ?\n");
    return 0;
  }
  if(dest_dir[i-1]->query_full()) {
    notify_fail("There is too much sand in that direction!\n");
    return 0;
  }
  this_player()->move_player(dest_dir[i]+"#"+dest_dir[i-1]);
  return 1;
}

query_full() {
  return (sand_level==MAX_SAND_LEVEL);
}

long(str) {
  if(str=="sand") {
    write("Just ordinary sand, only more annoying.\n");
    return 1;
  }
  ::long(str);
  if(!str) {
    if(!sand_level) return;
    if(sand_level==1) {
      write("There is some sand here.\n");
      return;
    }
    if(sand_level==MAX_SAND_LEVEL-1) {
      write("There is a lot of sand here.\n");
      return;
    }
    write("There is sand here.\n");
  }
}

init() {
  ::init();
  add_action("dig_it","dig");
  add_action("take_it","take");
  add_action("take_it","get");
}

dig_it(str) {
int i;

  i=find_dir(str);
  if(!i) {
    notify_fail("Dig where?\n");
    return 0;
  }
  
  if(dest_dir[i-1]->subtract_sand()) {
    notify_fail("There is no sand in that direction!\n");
    return 0;
  }
  if(add_sand()) {
    dest_dir[i-1]->add_sand();
    notify_fail("There is no room for more sand here!\n");
    return 0;
  }
  write("You dig a way "+str+".\n");
  say(this_player()->query_name()+" digs "+str+".\n");
  return 1;
}

subtract_sand() {
  if(!sand_level) return 1;
  sand_level--;
  tell_room(this_object(),"The amount of sand decreases.\n");
  return 0;
}

take_it(str) {
  if((!str)||(str!="sand")) {
    notify_fail("Take what?\n");
    return 0;
  }
  write("The sand slips through your fingers!\n");
  say(this_player()->query_name()+" fails to take some sand.\n");
  return 1;
}
