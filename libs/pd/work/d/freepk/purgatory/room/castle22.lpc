#include <std.h>
#include <purgatory.h>

inherit ROOM;

void create() {
    ::create();
     set_name("castle22");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^Northeast Subhall\n%^RESET%^"
"%^CYAN%^This is a small room off to the side for weary travelers to "
"%^CYAN%^sit and rest before they take another long journey. Plates of "
"%^CYAN%^dried fruit and mulled wine sit on a table in the center. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["southeast" : ROOMS"castle13", 
              "west" : ROOMS"castle9",
              "north" : ROOMS"castle23"]) );

    set_items( ([
        "fruit" : "Dried pearapples, apples, and other various fruits sit on a platter",
        "table" : "slightly dented and worn from years of hungry travelers, the table stands firmly in the center of the room."
      ]) );


}
void reset() {
    ::reset();
     if (children(MOBS"petitioner")==({})||
         sizeof(children(MOBS"petitioner"))<5)
            new(MOBS"petitioner")->move(this_object());
        
}

