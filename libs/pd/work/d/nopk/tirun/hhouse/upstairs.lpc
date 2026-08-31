#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "The stairs creak from the weight of an invisible force.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "%^GREEN%^It feels like this hall is being watched.%^RESET%^\n"
        "This narrow hallway leads east and west, with a staircase to the first story in "
        "the middle.  To the east, the hallway opens up to a balcony, while a small room is "
        "west.  The walls are bare, with a few holes where different animals probably have "
        "made shelter.  The floor is weak and bends under the slightest pressure.");
    set_items(
        (["staircase" : "It's surprising that the stairs are able to stay standing, let alone hold up anyone.",
          ({"wall","walls"}) : "The walls lack any decoration, unless you count the large holes in it.",
          "holes" : "The holes are hard to see into.",
          "floor" : "The floor is weak and rotted."]) );
    set_exits( ([ "stairs" : ROOMS"hhouse/3",
                  "east" : ROOMS"hhouse/balcony",
                  "west" : ROOMS"hhouse/bedroom" ]) );
}

void init() {
  ::init();
  add_action("search", "search");
}

int search(string str) {
  if(!str)
    return 0;

  if(str != "holes")
    return 0;

  write("You stick your arm into one of the holes and begin to feel around.");

  call_out("second", 4, this_player());

  this_player()->set_paralyzed(4, "You have your arm down the hole right now.");

  return 1;
}

void second(object tp) {
  message("info",
"  %^BOLD%^%^WHITE%^         _..._     ___     ___     ___     ___     _..._\n"
"         ,'   `::. ,~  `:. ,~  `:. ,~  `:. ,~  `:. ,'   `::.\n"
"        :      `:::     `::     `::     `::     `::      `:::\n"
"        :      .:::     .::     .::     .::     .::      .:::\n"
"        :      .:::`.  .;' `.  .;' `.  .;'.`.  .;':      .:::\n"
"        :      .:::  `.'    .`.'.:   `.'   ::`.'  :.     .:::\n"
"        :.     .::'          :::            :     `:     .:::\n"
"        `:     .::            :                    :     .::'\n"
"         :     .::            .                    :.    .::\n"
"          :    ::'                                 `:   .::.\n"
"          .\\   `:      ,:                   :.      :  .::.:\n"
"          :.\\   :.    :.:                   :`:    .' .::.:\n"
"           ::`.  :   :'::                   : `:   : .;'.:\n"
"            :  `.;  :'.::                   :  ::  ;:' ::\n"
"                .  :' .::.                 .:  .::     :\n"
"                : :'   :::                 :'   .::    .\n"
"                  :    `::                 :    .::\n"
"                 :'    .::.               .:    .:::\n"
"                 :     .:::  ,:.     .:.  :'    .:::\n"
"                 :     .:::,'  `:. ,'  `:.:     .:::\n"
"                 :     .:::     :::     :::     .:::\n"
"                 :     .:::     :::     :::     .:::\n"
"                  `._ .::'.`._.::' `._.::'.`._ .::'\n"
"\n  Something bites your hand!", tp);

  tp->add_hp(-30 - random(20));
}
