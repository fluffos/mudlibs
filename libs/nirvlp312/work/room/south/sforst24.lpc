inherit "/obj/clean";
reset(started)
{
    if (!started)
  set_light(1);
}

init()
{
    add_action("south", "south");
    add_action("east", "east");
}

short()
{
    return "A dimly lit forest";
}

long()
{
    write("You are in part of a dimly lit forest.\n" +
    "Trails lead south and east\n");
}

south()
{
    call_other(this_player(), "move_player", "south#room/south/sforst25");
    return 1;
}

east()
{
    call_other(this_player(), "move_player", "east#room/south/sforst23");
    return 1;
}
