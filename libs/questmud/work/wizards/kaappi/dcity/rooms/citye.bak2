inherit "room/room";
object map,monster,monster2;

reset(arg) {
  if(!monster) {
     monster = clone_object("/wizards/kaappi/dcity/mobs/gateguard.c");
    move_object(monster, this_object()); }
  if(!monster2) {
     monster2 = clone_object("/wizards/kaappi/dcity/mobs/gateguard.c");
     move_object(monster2, this_object()); }
if(arg) return;

  add_exit("north", "t1.c");
  add_exit("enter", "katu5.c");

  short_desc = "Entrance to city of Amaranthgard";
  long_desc = "Huge closed gates, made of steel, are standing in\n"+
              "front of you. The gates are decorated with some golden,\n"+
              "beautiful runes and pictues. These gorgeous pictures \n"+
              "describe dwarves who are fighting with horrible looking\n"+
              "demons. There is a text engraved above the gates.\n";
items = allocate(2);
   items[0] = "text";
   items[1] = "The City of Amaranthgard";

property = allocate(3);
  property[0] = "no_kill";
  property[1] = "no_spell";
  property[2] = "no_skill";
}
init() {
 ::init();
  add_action("enter", "enter"); }

enter() {
  
  if(!present("map", this_player())) {
  tell_object(this_player(), "Guard opens the gate, gives a map to you and says: 'Welcome to Amaranthgard.'\n");
  say("Guard opens the gate for "+this_player()->query_name()+" and says: 'Welcome to Amaranthgard'\n");
  move_object(this_player(), "/wizards/kaappi/dcity/rooms/katu5.c");
  move_object(clone_object("/wizards/kaappi/dcity/items/map.c"), this_player());
  command("look", this_player());

return 1;

  }
  
  tell_object(this_player(), "Guard opens the gate and says: 'Welcome to Amaranthgard.'\n");
  say("Guard opens the gate for "+this_player()->query_name()+" and says: 'Welcome to Amaranthgard'\n");
  move_object(this_player(), "/wizards/kaappi/dcity/rooms/katu5.c");
  command("look", this_player());

return 1;

 }
