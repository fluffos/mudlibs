#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 3, "night light" : 3, "indoors" : 1]));
    set_short("Princess Luti's Bed Chamber");
    set_smell("default", "Fresh flowers, sweet perfume, and the scent of a woman.");
    set_listen("default", "The noise of talking women is ever present here.");
    set_long("Eloquently decorated with beautiful objects and colours, Princess Luti's bed chamber is a sight to behold. Objects kind to the eye and touch are here, either breathing or not. Seldom leaving this room, Princess Luti can always be found here, being fawned over by servants, and praised widely for her beauty by other mermaids who come here to simply praise her beauty. There are no windows, only lamps lit this room.");
    set_items((["objects" : "They are treasurers princes have collected for Luti over the years, showing their effection for her.", "bed" : "This is the bed largely used by Princess Luti, usually when she is sleeping, or just whenever she feels like taking to bed.", "colours" : "The colours here are not as bright as the few lower rooms, but surprising calming and refreshing for the mind.", "lamps" : "Magically lit, they burn with a non-extinguishable light, controlled by the Princess' will."]));
    set_exits( (["down" : ROOMS"princesstower9"]) );
}

void reset() {
  ::reset();
    if(!present("knight")) {
      new(MOB"merknight")->move(this_object()); }
    if(!present("servant")) {
      new(MOB"mmerserv")->move(this_object());
      new(MOB"mmerserv")->move(this_object());
      new(MOB"merserv")->move(this_object());
      new(MOB"merserv")->move(this_object()); }
    if(!present("mermaid")) {
      new(MOB"mermaid")->move(this_object());
      new(MOB"mermaid")->move(this_object());
      new(MOB"mermaid")->move(this_object()); }
    if(!present("luti")) {
      new(MOB"luti")->move(this_object());
  }
}
