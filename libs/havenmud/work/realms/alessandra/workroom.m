#include <lib.h>
#include <std.h>
#include <dirs.h>

inherit LIB_ROOM;

int Allowed(object ob);
int shield(string args);
private int Shielded = 1;
private string *WhoAllowed = ({ 
  "duuk",
  "alessandra",
  "melchezidek",
     "mahkefel",
  });

static void create() {
  room::create();
  SetClimate("indoors");
  SetAmbientLight(40);
  SetShort("not at all a spider web");

  SetLong(
     "Nothing can exist here. Except Spiders, Driders and Mayonnaise."
     );
  SetItems( ([
     ({ "wall", "walls", "floor", "ground", "ceiling" }) :
        "The walls, floor and ceiling are a light grey marble with delicate "
        "swirls of charcoal grey.",
     ({ "marble" }) :
        "The marble is highly polished and quite expensive looking.",
     ({ "pilar", "pilars", "column", "columns" }) :
        "The pilars are great columns of charcoal grey marble. They run "
        "east and west in two rows, as far as the eye can see.",
     ({ "space", "room", "workroom" }) :
        (:GetLong:),
     ({ "portal", "portals" }) :
        "The portals shimmer and waver with distorted images. All you "
        "have to do is walk through them.",
     ({ "cushion", "satin", "tassle" }) :
        "This small cushion is a deep red satin. Black, flowing embroidery "
        "decorates the front and each corner ends in a black tassel.",
     ]) );
 "/realms/mahkefel/npc/vampony" : 1,
  SetItemAdjectives( ([
     "wall" : ({ "marble", "grey" }),
     "marble" : ({ "grey", "light", "charcoal", "polished", "expensive" }),
     "pilar" : ({ "great", "marble", "charcoal", "darker" }),
     "space" : ({ "open", "large" }),
     "cushion" : ({ "small", "dark red", "satin", "deep red", "red" }),
     ]) );
  SetInventory( ([
  "/realms/mahkefel/npc/moustache" : 1,
     "/realms/mahkefel/obj/fridge" : 1,
  ]) );
  SetExits( ([
    "north" : DIR_STANDARD_DOMAIN "/staffroom",
     "east" : "/realms/alessandra/work2",
     "south" : "/realms/alessandra/projects/vampire/room/forest1",
  ]) );
  Shielded = 0;
  SetSmell( ([
    ]) );
}

void init() {
  ::init();
  add_action("shield", "shield");
  add_action("Check", ({
       "ed", "rm", "update", "quit", "dest", "duc",
       "home", "goto", "call", "eval",
        }) );
  }

int CanReceive(object ob) {
  if (!Allowed(ob)) {
        message("system",
   "%^RED%^BOLD%^Vampire pony%^RESET%^RED%^ kicks you right in your jerk face!%^RESET%^", ob);
  if (userp(ob))
  message("system", 
      "%^RED%^" + capitalize(ob->GetKeyName()) + " just tried "
      "to visit uninvited but %^BOLD%^Vampire Pony%^RESET%^RED%^ kicked them right in their jerk face!%^RESET%^", this_object() );
    }
  else return Allowed(ob);
  }

int CanRelease(object ob) {
  if (Shielded) return 0;
  return 1;
   }

int shield(string args) {
  if (this_player()->GetKeyName() != "alessandra" &&
      this_player()->GetKeyName() != "duuk") {
  message("system",
    (Shielded ? "The shield is up." : "The shield is down."),
     this_player() );
  return 1;
  }

  if (args == "up") {
     send_messages("raise",
        "$agent_name $agent_verb the shield.",
          this_player(), 0, this_object() );
       return (Shielded = 1);
     }
  if (args == "down") {
     send_messages("lower",
        "$agent_name $agent_verb the shield.",
          this_player(), 0, this_object() );
       Shielded = 0;
        return 1;
      }
  if (!args) {
      message("system",
         (Shielded ? "The shield is up." : "The shield is down."),
         this_player() );
       return 1;
      }
  return 0;
  }

int Allowed(object ob) {
  if (!ob) ob = this_player();
  if (!Shielded) return 1;
  if (member_array(ob->GetKeyName(), WhoAllowed) != -1) 
     return 1;
  else return 0;
  }

int Check(string args) {
   if (Allowed(this_player())) { return 0; }
  else {
      message("system", "You are prevented by the shield.",
              this_player() );
         return 1;
       }
  }

varargs int eventDig(object who, object what) {
  if (!who) {
  	debug("Woot No Who! " + identify(what));
  	return 1;
  	}
  debug(identify(who) + " " + identify(what));
  return 1;
}
