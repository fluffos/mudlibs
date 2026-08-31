#define MASTER "players/moonchild/forest/master"
#define TREE   "players/moonchild/forest/tree"

inherit "room/room";

void reset(int arg) {
  if(random(3) && !present("forest_creature"))
    MASTER->make_creatures();
  if(arg)
    return;
  short_desc="Forest";
  switch(random(3)) {
    case 0:
      long_desc="You are walking about in the deep forest. It is dark here and there are trees\n"
	+ "all around you. The smell of the forest makes you feel tired and sleepy.\n";
      set_light(1);
      break;
    case 1:
      long_desc="The trees are slightly less dense in this part of the forest than in other\n"
	+ "parts, and a little more sunlight filters down through the trees here.\n";
      set_light(1);
      break;
    case 2:
      long_desc="The trees are bunched about incredibly closely around you here, you can\n"
	+ "barely see where you are trying to go as you struggle between intertwining\n"
	+ "branches. You can hear the sounds of the woodland animals running about\n"
	+ "through the undergrowth, apparently unbothered by your presence here.\n";
      break;
  }
  if(!random(4)) {
    object t;
    move_object(t=clone_object(TREE), this_object());
    long_desc+="One particular " + (string)t->query_name()
	+ " attracts your attention.\n";
  }
  dest_dir=DEST_DIR;
  smell="You smell the distinctive smell of a rich deciduous forest.";
  items=({ "trees", "There are trees all around you",
	"tree", "Any tree in particular?",
	"sunlight", "The sunlight barely filters through the trees",
	"undergrowth", "It's very thick here",
	"animals", "Various animals run about here happily" });
}
