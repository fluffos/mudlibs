#pragma strict-types
inherit "/room/room";
#define path "/players/paris/waste/"

void reset(int arg) {
  ::reset(arg);
  if (arg) 
    return;
  short_desc="The waste";
  set_light(1);
  long_desc=
    "You are standing in the Great Waste, all around you lies the "+
    "shattered remenants of a once great civilisation, weather worn "+
    "blocks measuring meters across litter the land in a seemingly "+
    "random pattern, some small tracks lead off through the twisting "+
    "maze of decay.\n";
#ifdef LONG_DESC
  long_desc+=LONG_DESC;
#endif
  dest_dir=DEST_DIR;
  items = ({
    "blocks", "Weather worn blocks of what looks like sandstone",
    "tracks", "The tracks lead off through the jumbled remains",
  });
#ifdef EXTRA_ITEM
  items += EXTRA_ITEM;
#endif
#ifdef EXTRA_CODE
  EXTRA_CODE
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
}












