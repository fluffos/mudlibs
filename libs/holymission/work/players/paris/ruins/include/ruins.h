#pragma strict-types
inherit "/room/room";
#define path "/players/paris/ruins/"
int i,j;

void reset(int arg) {
#ifdef MONSTER
    i=7-random(MONSTER);
    j=3-random(MONSTER);
    clone_list = ({ 
    1, i, "skeleton", path+"monster/skeleton", 0,
    2, j, "skeleton warrior", path+"monster/skel_war", 0,
    });
#endif
  ::reset(arg);
  if (arg) 
    return;
  short_desc="The ruined city";
  set_light(1);
  long_desc=
    "Tall buildings lie about you, some appear to be teetering on the "+
    "brink of falling down, the once impressive facades crumbling and worn "+
    "now look the the face of a scarred and pocked man.\n";
#ifdef LONG_DESC
  long_desc+=LONG_DESC;
#endif
  dest_dir=DEST_DIR;
  items = ({
    "buildings", "Most of the entrances look too unstable to use",
    "facades", "You're sure they would have been inspiring when new",
  });
#ifdef EXTRA_ITEM
  items += EXTRA_ITEM;
#endif
#ifdef EXTRA_CODE
  EXTRA_CODE
#endif 
    replace_program("/room/room");
}






