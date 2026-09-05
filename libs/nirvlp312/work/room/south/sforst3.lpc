reset(started)
{
    if (!started)
  set_light(1);
}

init()
{
    add_action("north", "north");
    add_action("south", "south");
    add_action("west", "west");
}

short()
{
    return "A dimly lit forest";
}

long()
{
    write("You are in part of a dimly lit forest.\n" +
    "Trails lead north, south and west\n");
}

north()
{
    call_other(this_player(), "move_player", "north#room/south/sforst2");
    return 1;
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst4");
    return 1;
}

west()
{
    call_other(this_player(), "move_player", "west#room/south/sforst7");
    return 1;
}
