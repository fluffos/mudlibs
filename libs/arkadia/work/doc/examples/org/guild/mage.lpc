inherit "/std/room";
#define DIR "/doc/examples/guild/"
  /* What type of guild are we, occupational, layman, race, or minor */
#define GUILD_TYPE  "layman"
  /* What style are we, fighter, magic, cleric, thief, or any other?? */
#define GUILD_STYLE "magic"
  /* Hopefully a unique name of the guild. */
#define GUILD_NAME  "Darkwinged sorcerers"
  /* Name of the file the shadow is defined in */
#define SHADOW      DIR + "mage_sh"

create_room()
{
    set_short("Mages guild");
    set_long("You are in the mages guild. You could try to join (jjjj)\n"+
	     "here. List and leave (llll) also works.\n");

    add_exit(DIR + "fighter", "south");
}

init()
{
    ::init();
    add_action("join", "jjjj");
    add_action("my_leave", "llll");
    add_action("list", "list");
}

join()
{
    object shadow;
    int result;

    notify_fail("You aren't fit to join this guild.\n");
    if (!do_I_want_this_player_in_my_guild(this_player()))
	return 0;

    notify_fail("You have already joined a guild we cannot accept.\n");
    if (!do_I_accept_the_guilds_this_player_has_joined(this_player()))
	return 0;

    notify_fail("For unknown reasons we couldn't help you join " +
		"our guild.\n");
    shadow = clone_object(SHADOW);
    if ((result = shadow->shadow_me(this_player(), GUILD_TYPE,
		GUILD_STYLE, GUILD_NAME)) != 1)
    {
    /* result = -1 (no name), -2 (wrong type), -3 (no style set),
                -4 (the guild the player already joined don't want this guild.)
		-5 (couldn't shadow the player, security problems. )
                Probably they have set the notify_fail() appropriate.
		0 (already member or player wasn't set properly) */

    /* This is one of the few times you destruct is OK to use... */
        destruct(shadow);
	return 0;
    }

    write("You are now a new member of this guild.\n");
    return 1;
}

do_I_want_this_player_in_my_guild(player)
{
/* No check if already member */
/* You could test if the player has solved the guild quest or anything... */
    return 1;
}

do_I_accept_the_guilds_this_player_has_joined(player)
{
/* No check if player is already member of a this guild type.*/
    return 1;
}

list()
{
    string str;

    str = this_player()->list_mayor_guilds();
    if (str)
	write("You are member of following guilds.\n" + str);
    else
	write("You are not member of any guilds.\n");

    return 1;
}

my_leave()
{
    notify_fail("But you are no member of our guild.\n");
    if (this_player()->query_guild_name_lay() != GUILD_NAME)
	return 0;

    if (this_player()->remove_guild_lay())
	write("You left our beloved guild.\n");
    else
	write("There was a strange error, I'm afraid you are\n" +
	      "stuck with us.\n");

    return 1;
}

