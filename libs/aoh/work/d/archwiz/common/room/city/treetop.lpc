/* the egg is an item for the collector quest. Do not change its path nor
   the path of this file without a mail to Loco and Cadra
*/
inherit "std/room";
#include "path.h"
#include <rooms.h>
#include <moving.h>

int scroll,egg;

int search(string str) {
  object ob;
  if (!str) return notify_fail(
  "What do you want to search?\n"),0;
  if (!this_player()) return 0;
  if (!this_player()->CanSee()) return notify_fail(
  "You cannot see, how do you think to search then?\n"),0;
  if (lower_case(str)!="nest") return notify_fail(
  "What do you want to search?\n"),0;
  if ((egg) && (scroll)) return notify_fail(
  "You find nothing. Perhaps someone else was faster?\n"),0;
  /* BEGONE: Code for magic scroll creation
  if (!scroll) {
    ob=clone_object(SCROLLS("elemental"));
    if (ob->move(this_player(),M_GET)!=ME_OK) {
      write("You find a magical looking scroll.\n"); 
      write("You cannot carry it.\n");
      ob->move(this_object(),M_DROP);
      }
    see(({"You find a magical scroll and take it.\n",
          "You find something. You take it with you.\n"}));
    show_room(this_object(),
      this_player()->QueryName()+" takes something from the nest.\n",
      ({this_player()}));
    scroll=1;
    }
    */
  if (!egg) {
    ob=clone_object(OBJ("goldegg"));
    if (ob->move(this_player(),M_GET)!=ME_OK) {
      write("You find a golden egg. What a surprise.\n");
      write("You cannot carry that egg.\n");
      ob->move(this_object(),M_DROP);
      }
    see(({"You find a egg and take it.\n",
          "You find something and take it with you.\n"}));
    show_room(this_object(),
      this_player()->QueryName()+" takes something from the nest.\n",
      ({this_player()}));
    egg=1;
    }
  return 1;
}

create()
{
    ::create();
    SetIntShort("At the tree's top");
    SetIntLong("You are at the top of the tree. There is a nest here.\n");
    SetIndoors(0);
    AddDetail("nest","Sometimes you can find some eggs here.\n");
    AddDetail("tree","You see a nest at the top of the tree.\n");
    AddExit("down","./clearing2");
    AddItem(OBJ("stonefrog"),REFRESH_REMOVE);
    AddRoomCmd("search",#'search);
    reset();
}

reset() {
  if (!present("scroll",this_object())) scroll=0;
  if (!present("egg",this_object())) egg=0;
  ::reset();
}
