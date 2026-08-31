#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2 ]));
   set_short("Bilbo's shop of smoke");
   set_long("This small, one room has been transformed into a shop. "
     "Rings of smoke drift lazily towards the ceiling. A counter and "
     "a chair lie against the wall, on the far side of the room away "
     "from the door.");
   set_items(([
     ({ "rings", "smoke" }) : "The smoke floast upwards.",
     "ceiling" : "It is begining to become clouded with smoke.",
     "counter" : "There are shoe-prints on the counter.",
     "chair" : "It has been arranged so that a rather short person "
               "could put their feet on the counter from it.",
     ({ "shoe-prints", "prints", "shoeprints" }) :
               "They mysteriously rest on the top side of counter."
   ]));
   set_exits(([ "west" : ROOMS"stown2" ]));
}

void reset() {
 ::reset();
   if (!present("bilbo"))
     make(MOB"bilbo");
}

int list() {
write(@ENDTEXT
Item                                         Price
--------------------------------------------------------
a pipe                                    350 gold pieces
tobacco                                   170 gold pieces
pipe-weed                                 207 gold pieces
ENDTEXT);
   return 1;
}

int buy(string str) {
   int price;
   object bag;

   if (!str) return 0;
   switch (str) {
     case "pipe":
       price = 350;
       break;
     case "tobacco":
       price = 170;
       break;
     case "pipe-weed":
       price = 207;
       break;
     default:
       return notify_fail("You cannot buy that here.\n");
   }
   if (!present("bilbo", this_object()))
     return notify_fail("The shop owner cannot be found.\n");
   if (this_player()->query_money("gold") < price)
     return notify_fail("You cannot afford that.\n");
   this_player()->add_money("gold", -(price));
   write("You buy "+capitalize(str)+".");
   say(this_player()->query_cap_name()+" buys something.", this_player());
   if (str == "pipe") {
     new(OBJ"wpipe")->move(this_player());
     return 1;
   }
   bag = new(OBJ"pouch");
   switch (str) {
      case "pipe-weed":
        new(OBJ"weed")->move(bag);
        new(OBJ"weed")->move(bag);
        new(OBJ"weed")->move(bag);
        break;
      case "tobacco":
        new(OBJ"tobacco")->move(bag);
        new(OBJ"tobacco")->move(bag);
        new(OBJ"tobacco")->move(bag);
        break;
      default:
        return 1;
   }
   bag->move(this_player());
   return 1;
}

void init() {
 ::init();
   add_action("list", "list");
   add_action("list", "read");
   add_action("buy", "buy");
}
