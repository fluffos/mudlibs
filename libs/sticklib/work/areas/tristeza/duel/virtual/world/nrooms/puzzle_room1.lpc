#include <room.h>

#include <areas.h>

void
create_room() {

    object game;
    set_light(LT_LIGHTS);
    set_outdoors(WD_INDOORS);

    set(PREVENT_TELEPORT);
    set_short("Tomb chamber");
    set_long("It's a round chamber filled with pictures of mages. Green "+
      "stones emit green light from the roof.\n");

    add_item("pictures", "It's a fresco with mages using magic in it.");
    add_item("stones", "They are strange glowing stones, out of your reach.");
    add_item("green stones", "=stones");

    game = clone_object(AREA_TRISTEZA "duel/obj/puzzle2");
    game->set_trigger_fun(
      find_object(AREA_TRISTEZA "duel/virtual/world/nrooms/puzzle_room"),
      "move_me");
    move_object(game, this_object());
}

init_room() {
    call_out("say_it", 1);
}

void
say_it() {

    write("You have five minutes, mortal.\n");
}

status
query_puzzle_room() { return 1; }
