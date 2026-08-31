#define MASTER "players/ambrose/master"
inherit "room/room";


void reset(int arg)
{
  if(random(3)  && !present("forest_creature"))
    MASTER->make_creatures();
  if(arg)
    return;
  switch(random(3))
    {
    case 0:
      long_desc=
"You are deep in the magical woods of Avalon.  All around you see\n"
+"dense undergrowth making your way through the forest diffucult at\n"
+"best.  Strangely you feel no fear in this wood.\n";
      set_light(1);
     property=({"no_teleport"});
      break;
    case 1:
      long_desc="You are in a small wooded clearing in this dense forest.  It looks very\n"
	+"peaceful here and feel like resting.  All around you here the sounds of the forest.\n";
      set_light(1);
     property=({"no_teleport"});
      break;
    case 2:
      long_desc="You cross a small game trail here.  The forest seems to abound with all\n"
	+"kinds of animal life.  You feel content.\n";
      set_light(1);
     property=({"no_teleport"});
      break;
    }
  dest_dir=DEST_DIR;
  smell="You smell fagrant pines mixed with rare herbal spices.";
  items=({"trees","Great towering pines, untouched by man",
	    "pines","The pines are the largest you haveever seen",
	    "trail","If you look carefully you can see a small game trail",
	    "clearing","It looks good enough to camp at"});
}








