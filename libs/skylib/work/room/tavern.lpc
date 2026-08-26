
inherit ROOM_OBJ;

void setup() {
    object ob;

    set_light(100);
    set_determinate("the ");
    set_short("wizards' room");

    set_long("This is just a bare room that is waiting to move quietly into "
        "the background when some rooms start to appear. There is a sign "
        "stuck to the wall here.\n");

    add_sign("This looks like a piece of cardboard that has been hastily "
        "stuck to the wall.\n", "If you wish to become a creator here please "
        "use the \"apply\" command.");

    ob = clone_object(BOARD_OBJ);
    ob->set_datafile("general");
    ob->move(TO);

} /* setup() */
