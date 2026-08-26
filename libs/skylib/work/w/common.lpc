/**
 * Creators' common room by Liceas Shadowstealer - 27/07/01
 */

#include <config.h>

inherit ROOM_OBJ;

object board, dartboard, cart;

void setup() {
    set_short("creators' common room");
    add_property("determinate", "the ");
    set_light(100);

    set_long("This is the spacious creators common room, where creators, "
        "seniors, lords and admin alike can kick back and relax, take their "
        "rage out on a game of darts, or sit besides the cosy little fire.  "
        "The walls of the room have been painted a light green colour and "
        "smell like they have just been painted.  In one corner of the room "
        "is a small wooden table and several chairs, next to them in the "
        "northeast corner of the large room is a black leather upholstered "
        "sofa and close by that, in the middle of room, is a drinks cart "
        "where people can quench their thirst.  Beside one of the entrances "
        "is a clothes rack and in one of the corners of the room is a metal "
        "cage with a large lock on it.  Several objects also appear to be "
        "embedded into the ceiling.\n");

    add_item( ({"creator", "senior", "lord", "admin"}), "These are the ranks "
        "of creatorship.");
    add_item( ({"rage", "violence"}), "Rage is often built up from hard work "
        "or trying to sort out runtime errors, and can lead to much "
        "violence.");
    add_item("darts", "Since there is a dartboard here, people have an "
        "opportunity to vent frustration by throwing pointy bits of metal at "
        "pictures of each other's faces.");
    add_item( ({"green painted wall", "green colour"}), "The walls of the "
        "room appear to have been painted a light green colour just "
        "recently.");
    add_item("corner", "There are items of interest in two of the corners, "
        "in the northeastern corner is the fairly large black leather sofa, "
        "while across the room to the southwest lies a medium sized metal "
        "cage.");
    add_item("clothes rack", "On the coat rack are pegs for clothing to hung "
        "up on, on one of the pegs is a latex bunny suit with "
        "'%^RED%^FlUFfY%^RESET%^' etched onto it, while on another hangs a "
        "red star-trek uniform with the name 'Patrick Stewart' above it.");
    add_item("cage", "This is a medium sized cage that has a large lock "
        "attached to it.  It seems to have something inside that is "
        "gibbering.  On top of the cage is etched "
        "'%^YELLOW%^AppRenTiceZZZZ....%^RESET%^'.");
    add_item("fire", "Carved into the middle of the right wall is a small "
        "cosy fire for warming up after coming in from the cold.  Beside the "
        "fire is a bucket of coal.  On occasion creators have been known to "
        "set fire to others from here.");
    add_item( ({"bucket", "coal"}), "Beside the fire is a small metal bucket "
        "full of coals to keep the fire stoked up and warm.");
    add_item("chair", ({"long", "Around the room are loads of chairs, some "
        "are wooden, others padded, and some are designed for great comfort.",
        "position", "one of the"}) );
    add_item("black leather upholstered sofa", ({"long", "In the northeast "
        "corner of the room is a large, black leather-upholstered sofa "
        "designed to fit as many creators onto it as possible.", "position",
        "black leather upholstered sofa"}) );
    add_item("thirst", "Quenching thirst here can include drinking your "
        "skull into oblivion, or just having a soda while chatting to "
        "other creators about life in general.");
    add_item( ({"object", "embedded", "ceiling", "paper", "scribbles",
        "knife", "explosive", "miners' pickaxe", "miner", "ceiling"}),
        "Embedded in the ceiling are several objects that seem to belong to "
        "a variety of creators.  Amongst the objects are a pencil and paper "
        "full of mad scribbles, a few knives, some explosives as well as a "
        "miners' pickaxe with a miner still attached to it.");

    add_exit("pub", CONFIG_START_LOCATION, "path");
    add_exit("adminc", "/d/admin/common", "path");
    add_exit("school", "/d/learning/school/school", "path");

} /* create() */

void reset() {
    if( !board ) {
        board = clone_object(BOARD_OBJ);
        board->move(TO);
        board->set_datafile("creator");
    }
    if( !dartboard ) {
        dartboard = clone_object("/std/objects/dartboard");
        dartboard->move(TO);
    }
    if( !cart ) {
        cart = clone_object("/std/objects/drinkscart");
        cart->move(TO);
    }
} /* reset() */
