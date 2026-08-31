#include <std.h>
inherit ROOM;

object ob, igor;
string *files, path, file;
string *paths = ({
"/d/standard/",
"/d/lodos/",
"/d/arlon/room/",
"/wizards/powerman/room/",
"/wizards/inferno/room/",
"/wizards/inferno/"
});

void create() {
 ::create();
   set_short("The eye of a storm");
   set_long("This is the source of all magic. Reality was split and torn "
	"long ago by the strong supernatural forces present here. You "
	"have wandered into the eye of a magical storm. If you <hop "
	"storm>, the magic here will fling you through reality to a "
	"random place.");
}

int hop(string str) {
   if (!str || str == "" || str != "storm") return 0;
   igor = new("/wizards/inferno/igor");
   ob = igor;
   while (!ob->is_room()) {
     path = paths[random(6)];
     files = get_dir(path);
     file = files[random(sizeof(files))];
     if (!igor->move(path+file)) ob = environment(igor);
   }
   igor->remove();
   write("You hop into the midst of chaos!");
   this_player()->move_player(ob, "into the mists of time and space");
   return 1;
}

void init() {
 ::init();
   add_action("hop", "hop");
}
