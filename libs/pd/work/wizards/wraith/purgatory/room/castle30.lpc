#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("move_throne", "move");
}
void create() {
    ::create();
     set_name("castle30");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^RED%^The Throne Room\n%^RESET%^"
"%^RESET%^%^RED%^Welcome to the Purgatory Throne Room. From this room, the "
"%^RESET%^%^RED%^King makes his judgements and decisions. The King's court "
"%^RESET%^%^RED%^stands ready to record his wisdom. The walls are adorned with "
"%^RESET%^%^RED%^tapestries depicting great battles.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["southeast" : ROOMS"castle23", 
              "southwest" : ROOMS"castle24"]) );


    set_items( ([
        "tapestry" : "4 Different tapestries hang from the walls, each of them ornately captivating great battles the king has lead.",
        "throne" : "%^BOLD%^%^YELLOW%^Fit for a king, this throne has a high back with a plush seat. Small scratches on the legs show the throne has been moved from room to room."
      ]) );

}

int move_throne(string str) {
    if(!str) {
        notify_fail("Move what?\n");
        return 0;

    }
    if(str != "throne") {
        notify_fail("You can't move that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" pushes the throne to one side. ", this_object(), ({ this_player() }));
    message("info", "You find a the secret entrance to the Kings Harem.", this_player());
    message("info", "The throne slides to the side revealing an exit.", this_player());
    add_exit(ROOMS"harem1", "north");
    call_out("go_north", 8);
    return 1;
}

void go_north() {
    message("info", "the throne shifts back into position.",
all_inventory(this_object()));
    remove_exit("north");
}

void reset() {
 ::reset();

  if (!present("king", this_object()))
    new(MOBS"king" )->move(this_object());

  if (!present("queen", this_object()))
    new(MOBS"queen" )->move(this_object());

  if (!present("assassin", this_object()))
    new(MOBS"rassassin" )->move(this_object());

 if (!present("advisor", this_object()))
    new(MOBS"royalmage" )->move(this_object());


 if (!present("guard", this_object()))
    new(MOBS"royalguard" )->move(this_object());

 if (!present("guard 2", this_object()))
    new(MOBS"royalguard" )->move(this_object());

 if (!present("guard 3", this_object()))
    new(MOBS"royalguard" )->move(this_object());

 if (!present("guard 4", this_object()))
    new(MOBS"royalguard" )->move(this_object());

 if (!present("servant", this_object()))
    new(MOBS"kservant" )->move(this_object());

 if (!present("servant 2", this_object()))
    new(MOBS"kservant" )->move(this_object());

 if (!present("servant 3", this_object()))
    new(MOBS"kservant" )->move(this_object());

 if (!present("servant 4", this_object()))
    new(MOBS"kservant" )->move(this_object());

 if (!present("maid", this_object()))
    new(MOBS"queensmaid" )->move(this_object());

 if (!present("maid 2", this_object()))
    new(MOBS"queensmaid" )->move(this_object());

 if (!present("maid 3", this_object()))
    new(MOBS"queensmaid" )->move(this_object());

 if (!present("maid 4", this_object()))
    new(MOBS"queensmaid" )->move(this_object());

 if (!present("maid 5", this_object()))
    new(MOBS"queensmaid" )->move(this_object());






}
