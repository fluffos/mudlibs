#pragma strict-types
#define path "/players/paris/waste/"
inherit "/room/room";

void reset(int arg) {
  ::reset(arg);
  if (arg) 
    return;
  set_light(0);
  short_desc="Under the hill";
  long_desc=
    "A dark narrow passageway leads off into the darkness, the walls seem to "+
    "be made of large rectangular blocks almost grown together somehow. You "+
    "can feel something strange in the air.\n";
#ifdef LONG_DESC
  long_desc+=LONG_DESC;
#endif
  dest_dir=DEST_DIR;
  items = ({
    "blocks", "They almost look like they've been grown together",
    "walls", "Made from large sandstone blocks",
  });
  smell = "It smells strange in here.\n";
#ifdef EXTRA_ITEM
  items += EXTRA_ITEM;
#endif
#ifdef MONSTER
  clone_list = ({ 
    1, 
    random(MONSTER), 
    "cultist", 	
    path+"monster/cultist", 
    0
  });
#endif
  replace_program("room/room");
}


