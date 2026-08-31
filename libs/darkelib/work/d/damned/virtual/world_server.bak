//    This is a server which handles the Darkemud world...it supports a variety of
//    terrains as well as things like mineral mining and dropping areas and
//    stuff on the filed.

#define HIGH_COLUMN 39
#define HIGH_ROW 79
#define EXITS ({ "north", "south", "east", "west" })
#define TERRAIN_FILE "/d/damned/data/world_terrain.db"

#include <daemons.h>
#include <std.h>

inherit ROOM;
inherit "/std/virtual/compile";

mapping minerals;
string terrain_type;
int brook;

string get_night_long(string terrain, int z);
string get_day_long(string terrain, int z);
mapping get_items(string terrain);
int query_mineral(string what);
void clone_monster(string type);
string query_terrain();
string get_xtra_long(int *x, int *y);
string terrain_name(string letter);

void virtual_setup(string room) {
  int item_x, item_y, i, x, y, *exits_y, *exits_x;
  string *line, type;
  string *items_file, *words;
  string min_type;

  if(sscanf(room, "room_%d_%d", x, y) != 2) {
    write("BUG!  The room you tried to enter doesn't exist!\n" +
	  "Error in virtual world server.");
    return;
  }
/*
if(x == 12 && y == 12) 
add_exit("/d/damned/arena/booths_room", "arena");
*/
  exits_x = allocate(4);
  exits_y = allocate(4);
  exits_x[0] = x; exits_x[1] = x;
  exits_x[2] = (x >= HIGH_COLUMN)?0:(x + 1);
  exits_x[3] = (x == 0)?HIGH_COLUMN:(x - 1);
  exits_y[0] = (y == 0)?HIGH_ROW:(y - 1);
  exits_y[1] = (y >= HIGH_ROW)?0:(y + 1);
  exits_y[2] = y; exits_y[3] = y;
  for(i = 0; i < sizeof(EXITS); i++)
    add_exit(sprintf("/d/damned/virtual/room_%d_%d.world",
		     exits_x[i], exits_y[i]), EXITS[i]);
  line = explode(read_file(TERRAIN_FILE, y+1, 1), ":");
  type = line[x];
  terrain_type = type;
  if(random(10) == 3 && memory_info() < 5000000)
    clone_monster(terrain_type);
  brook = (type == lower_case(type));
  set("day long", get_day_long(capitalize(type),x+y) + 
	get_xtra_long(exits_x,exits_y));
  set("night long", get_night_long(capitalize(type),x+y) + 
	get_xtra_long(exits_x,exits_y));
  set_items(get_items(capitalize(type)));
  switch(capitalize(type)) {
  case "S":
    set("short", "A murky swamp");
    set_smell("default", "The air is heavy with the stench of decay.");
    set_smell("gas", (: call_other, this_object(), "gas_func" :));
    break;
  case "T":
    set("short", "A freezing tundra");
    break;
  case "P":
    set("short", "Beautiful plains");
    break;
  case "M":
    set("short", "Tall, stately mountains");
    break;
  case "H":
    set("short", "Rolling hills");
    break;
  case "W":
    set("short", "The high seas");
    break;
  case "F":
    set("short", "A darke and eerie forest");
    if(!random(2)) {
      set_smell("default", "The smell of evergreens pervades your nostrils.");
      set_smell(({ "evergreen" , "evergreens" }), "The evergreens smell very pleasant.");
    }
    break;
  case "J":
    set("short", "A humid jungle");
    break;
  case "D":
    set("short", "An arid desert");
    break;
  case "C":
    set("short", "The beautiful coast");
    set_listen("default", "You hear the gentle crashing of waves against the coast.");
    break;
  }
  if(brook) {
    set("day long", (string)query("day long") + "%^BOLD%^There is a serene brook here.\n");
    set("night long", (string)query("night long") + "\nThere is a serene brook here.\n");
    set_listen("brook", "You hear the quiet babbling of the brook.");
    add_item("brook", "It is a beautiful brook with stones at the bottom");
  }
  items_file = explode(read_file("/d/damned/data/world_items.db"), "\n");
  i = sizeof(items_file);
  while(i--) {
    words = explode(items_file[i], ":");
    if(sizeof(words) > 4)
      words = ({ words[0], (words[1]+":"+words[2]), words[3], words[4] });
    if(sscanf(words[0], "%d_%d", item_x, item_y) != 2) continue;
    if(item_x == x) {
      if(item_y == y) {
	add_exit(words[1], words[2]);
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is here.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is here.\n");
	add_item(words[2], "You can enter it by typing '" + words[2] + ".'");
      }
      else if((item_y == y - 1) || (y == 0 && item_y == HIGH_ROW)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the north.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the north.\n");
      }
      else if((item_y == y + 1) || (y == HIGH_ROW && item_y == 0)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the south.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the south.\n");
      }
    }
    else if(item_y == y) {
      if((item_x == x - 1) || (x == 0 && item_x = HIGH_COLUMN)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the west.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the west.\n");
      }
      else if((item_x == x + 1) || (x == HIGH_COLUMN && item_x == 0)) {
	set("night long", (string)query("night long") + "%^BOLD%^" + words[3] + " is seen to the east.\n");
	set("day long", (string)query("day long") + "%^BOLD%^" + words[3] + " is seen to the east.\n");
      }
    }
  }
if(x == 12 && y == 12) {
set("night long", (string)query("night long") + "%^BOLD%^A large "
"arena can be seen in the distance.%^RESET%^");
set("day long", (string)query("day long") + "%^BOLD%^A large "
"arena can be seen in the distance.%^RESET%^");
}
  items_file = get_dir("/d/damned/data/");
  i = sizeof(items_file);
  minerals = ([]);
#if 1 
  while(i--) {
    if(!sscanf(items_file[i], "mineral_%s.db", min_type)) continue;
    words = explode(read_file("/d/damned/data/"+items_file[i], y + 1, 1), ":");
    minerals[min_type] =  atoi(words[x]);
  }
#endif
}

string get_xtra_long(int *x, int *y) {
  string *line, desc;
  mapping dirs;
  int i, j;

  desc = "";
  dirs = ([]);
  for(i=0; i<4; i++) {
    line = explode(read_file(TERRAIN_FILE, y[i]+1, 1), ":");
    if(capitalize(line[x[i]]) != capitalize(terrain_type)) {
      if(undefinedp(dirs[terrain_name(line[x[i]])]))
	dirs[terrain_name(line[x[i]])] = ({});
      dirs[terrain_name(line[x[i]])] += ({ EXITS[i] });
    }
  }
  line = keys(dirs);
  i = sizeof(line);
  while(i--) {
    desc += "To the ";
    for(j = 0;j < sizeof(dirs[line[i]]); j++) {
      if(j == (sizeof(dirs[line[i]]) - 1)
	&& sizeof(dirs[line[i]]) > 1) desc += "and ";
      desc += dirs[line[i]][j];
      if(j == (sizeof(dirs[line[i]]) - 1) || 
	 sizeof(dirs[line[i]]) > 2) desc += ", ";
      else desc += " ";
    }
    desc += "you see " + line[i] + ".\n";
  }
  return desc;
}

string terrain_name(string letter) {
  letter = capitalize(letter);
  switch(letter) {
  case "F":
    return "a stately forest";
  case "J":
    return "a mysterious jungle";
  case "P":
    return "a beautiful plain";
  case "W":
    return "the sea";
  case "M":
    return "a towering mountain range";
  case "H":
    return "rolling hills";
  case "C":
    return "the coast";
  case "D":
    return "a barren desert";
  case "S":
    return "a murky swamp";
  case "T":
    return "a freezing tundra";
  default:
    return "TERRAIN BUG!!!";
  }
}

int query_mineral(string what) {
  if(!minerals || undefinedp(minerals[what])) return 0;
  return minerals[what];
}

string gas_func() {
  this_player()->add_hp(-2);
  return "%^YELLOW%^The gas burns your lungs!";
}

int query_brook() { return brook; }

int query_water() {
  if(capitalize(terrain_type) == "W")
    return 1;
  else return 0;
}

void init() {
  ::init();
  if(capitalize(terrain_type) == "W")
    this_object()->damage_all();
  return;
}

int receive_objects() {
  object who;

  who = previous_object();
   if(!who || !living(who) || who->is_player() ||
      capitalize((string)this_object()->query_terrain()) != "W")
    return ::receive_objects();
  if((int)who->query_skill("swimming") > random(100)) return 1;
  if(who->query_flying()) return 1;
  return 0;
}

int living_filter(object who) {
  return who->is_player();
}

void damage_all() {
  object *who_here;
  int i, j;
  string *limbs;
  int flag;

  who_here = filter_array(all_inventory(this_object()), 
			  "living_filter", this_object());
  if(!who_here || !sizeof(who_here)) return;
  i = sizeof(who_here);
  while(i--) {
    limbs = (string *)who_here[i]->query_limbs();
    j = sizeof(limbs);
    flag = 0;
    while(j--)
      if(member_array("wing", explode(limbs[i], " "), 4) >= 0)
	flag = 1;
    if(flag) continue;
    if(who_here[i]->query_boat()) continue;
    if(who_here[i]->query_flying()) continue;
    if(random(100) >= (int)who_here[i]->query_skill("swimming")) {
      who_here[i]->add_hp(-(int)who_here[i]->query_max_hp() / 20);
      message("info", "%^BLUE%^You are drowning!", who_here[i]);
    }
  }
  remove_call_out("damage_all");
  call_out("damage_all", 5);
  return;
}

void create() {
  ::create();
    set_property("light", 2);
    minerals = ([]);
    return;
}

void reset() {
    if(random(28) == 4 && stringp(terrain_type) && memory_info() < 5000000)
      clone_monster(terrain_type);
  return;
}

string get_day_long(string terrain, int z) {
  string *descs;
  descs = allocate(3);
  switch(terrain) {
  case "S":
    descs[0] = "You find yourself in the middle of a murky swamp.  The swamp gas is so thick that at times "+
      "you swear you are actually swimming in it.  You wade through the cloudy water.\n";
    descs[1] = "The swamp is interrupted by an occasional outgrowth of trees which can barely be seen "+
      "through the swamp gas.  You wade cautiously so as not to upset the many creatures which lurk "+
	"beneath the murky waters.\n";
    descs[2] = "You push some vines aside as you wade through the swamp.  You proceed at a cautious pace "+
      "since the gas is so thick, you can hardly see your hand in front of your face.\n";
    break;
  case "T":
    descs[0] = "You feel you should have packed an extra jacket as you trudge through the deep snow here.  "+
      "Your breath forms ice crystals as you exhale.  In the distance, you see huge mountains of ice "+
	"which part the clouds.\n";
    descs[1] = "You walk carefully along the patch of ice, taking care to avoid thin patches.  "+
      "You pause to wipe some ice crystals from your eyebrows and continue into the vast frozen "+
	"wasteland.\n";
    descs[2] = "You find it hard to breathe the freezing air as you scale the snow dune before you.  "+
      "As you reach the top, the view of the frozen wasteland is impressive.  Without pausing too "+
	"long to admire the awesome view, you continue.\n";
    break;
  case "P":
    descs[0] = "You are in the middle of a beautiful grassy plain.  The cool wind blows through "+
      "the dark purple grass, making a comforting rustling sound.  The sun is bright, and you "
	+ "can see various critters scampering through the grass.\n";
    descs[1] = "The sky is slightly overcast and shadows move quickly over the plains, giving " +
      "the odd sensation of motion.  The wind picks up, and you feel as though rain might be "+
	"in the future.\n";
    descs[2] = "The grass of the peaceful, dark plain is punctuated by a few large rocks lying about. " +
      " A few large insects and small, black reptiles scamper about.\n";
    break;
  case "F":
    descs[0] = "The sun is mostly obscured by the stately trees of this forest.  " +
      "Small animals regard you cautiously as you walk through the dense foliage.\n";
    descs[1] = "Small animals hang about from the trees and squeak at you as you " +
      "pass by.  A bed of dead leaves lies about on the forest floor, and it crunches softly "
	"as you walk about.\n";
    descs[2] = "You have reached a small clearing in the forest surrounded by tall trees " +
      "and dense foliage.  The grass is VERY tall here, and you have trouble walking through it.\n";
    break;
  case "J":
    descs[0] = "The jungle is oppressively hot and humid.  Vines hang from the tall trees, " +
      "and small insects scamper about below.\n";
    descs[1] = "Drops of water fall from the leaves of trees high above.  An eerie mist collects " +
      "on the jungle floor, and you are unable to see your feet.\n";
    descs[2] = "The heat here is stifling.  You see a rather large grey and red snake watching "+
      "you with irridescent yellow eyes from a nearby tree.  The sensation of movement is all "+
	"around, and you know you are far from alone.\n";
    break;
  case "M":
    descs[0] = "Climbing these mountains is no small task.  Sprouts of grass peek out through "+
      "cracks in the rock.  You can see that the peaks of some nearby mountains are covered with "+
	"snow.\n";
    descs[1] = "You stand at the base of a tall, imposing mountain.  You can see others in the "+
      "distance against a dark purple sky.\n";
    descs[2] = "Walking through a mountain pass, you marvel at the beauty and size of the rock " +
      "formations which tower above you.\n";
    break;
  case "D":
    descs[0] = "The desert seems to stretch on for miles.  Several exotic cacti puntuate the area, "+
      "and desert flowers can be seen growing sparsely.\n";
    descs[1] = "Exotic plants and cacti are all about.  The wind picks up, and sand scratches against "+
      "your face as you try not to inhale any.\n";
    descs[2] = "You are in the middle of a small patch of cacti.  As you look up, you see rolling dunes.  "+
      "The wind causes sand to blow over them in the distance.\n";
    break;
  case "H":
    descs[1] = "The rolling hills are covered by the dark purple grass indigenous to Darkemud.  "+
      "In some places, the grass is bare, indicating poor rainfall.  Small prarie creatures "+
	"scamper about.\n";
    descs[0] = "Rocks jut out through the hills here, giving them the appearance of small mountains.  "+
      "The sun is warm here.\n";
    descs[2] = "You are walking in between two large hills.  The rest of the terrain is obscured by "+
      "their presence.  The hills are covered by dark purple grass and weeds with occasional "+
	"patches of bare rock.\n";
    break;
  case "C":
    descs[0] = "You are walking along the peaceful coast.  Shells have washed up on shore, and some "+
      "have been ground to fine particles by the beating waves of the deep blue water.\n";
    descs[1] = "Walking along the Darkemud coast, the site of red-orange sand against deep blue water "+
      "is an awesome sight.  Your feet sink into the wet sand as you walk.\n";
    descs[2] = "The coast is very beautiful.  You can see the sun reflecting brilliantly "+
      "off the water.  The coarse red-orange sand meets deep blue water here.\n";
    break;
  case "W":
    return "You are in the middle of a beautiful and serene body of water.  The water stretches out "+
      "in all directions.\n";
    break;
  }
  return descs[z%3];
}

string query_terrain() { return terrain_type; }

string get_night_long(string terrain, int z) {
  string *descs;

  descs = allocate(3);
  switch(terrain) {
  case "S":
    return "The swamp is not the best place to be at night.  The swamp gas floats over the murky waters almost "+
      "as if it were alive.  Your only companion in this dark morass is the sound of the water as it is "+
	"parted by your stride.\n";
  case "T":
    return "If you thought this place was cold during the day, you had another thing coming.  As far as you "+
      "can see, which isn't very, the snow is cold, flat, and unrelenting.  Your shivers of cold are surpassed "+
	"only by the loneliness you feel.\n";
  case "P":
    return "At night, you can barely see that dark grass in the moonlight, giving you the sensation of "+
      "floating in space.  Your only idea that you are on solid ground is given by the faint rustling of "+
	"the wind through the vegetation.\n";
    break;
  case "F":
    return "The forest is truly an intimidating place at night.  Sounds echo out from near and far, "+
      "filling you with the sensation of being watched.  You step gingerly, careful not to upset the "+
	"many deadly creatures known to lurk about at night.\n";
    break;
  case "J":
    return "You are filled with the sensation that this is not a good place to be at night as you "+
      "observe irridescent eyes bobbing around in the dark air.\n";
    break;
  case "H":
    return "The faint glint of the moonlight off the rolling hills is an impressive sight.  You are "+
      "filled with a profound sense of lonliness as you look off into the distance.\n";
  case "M":
    return "The mountains are an eerie and beautiful sight at night.  "+
      "They tower into the starry sky, filling you with awe.\n";
  case "D":
    return "The stark desert moons are reflected by the sand, revealing "+
      "cacti and other sparse vegetation.\n";
  case "C":
    return "In the darkness, you can barely make out a reflection "+
      "of the moon on the water.  The slow crashing of waves is the "+
	"only indication that water is nearby.\n";
  case "W":
    return "The dark loneliness you experience on the quiet water is "+
      "profound.  Your only companions are the three moons hovering "+
	"in the night sky.\n";
  }
  return "oopsee, no long desc for nitew";
}

mapping get_items(string terrain) {
  switch(terrain) {
  case "F":
    return ([ ({ "tree", "trees" }) : "The trees are tall and beautiful" ]);
  case "D":
    return ([ ({ "cactus", "cacti" }) : "The cacti are exotically colored" ]);
  case "T":
    return ([ "snow" : "The snow is finely powdered and seems infinitely deep." ]);
  case "C":
    return ([ ({ "shell", "shells" }) : "None of them look terribly valuable." ]);
  default:
    return ([]);
  }
}

void clone_monster(string terrain) {
  object mon;

  terrain = capitalize(terrain);
  seteuid(geteuid(this_object()));
  switch(terrain) {
  case "S":
    mon = new("/d/damned/world/obj/mon/will_o_wisp");
    break;
  case "J":
    if(random(2)) mon = new("/d/damned/world/obj/mon/python");
    else mon = new("/d/damned/world/obj/mon/panther");
    break;
  case "D":
    mon = new("/d/damned/world/obj/mon/lizard");
    break;
  case "M":
  case "H":
    mon = new("/d/damned/world/obj/mon/mountain_lion");
    break;
  case "T":
    mon = new("/d/damned/world/obj/mon/wolf");
    break;
  case "P":
    mon = new("/d/damned/world/obj/mon/jackrabbit");
    break;
  default:
    return;
  }
  if(objectp(mon))
    mon->move(this_object());
  return;
}













