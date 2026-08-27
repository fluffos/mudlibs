/* The hobbit shadow */

inherit "/std/guild/guild_race_sh";

query_guild_tax_race() { return 1; }

query_guild_not_allow_join_race(player, type, style, name)
{
    if (::query_guild_not_allow_join_race(player, type, style, name))
	return 1;

    notify_fail("No real hobbit is member of a layman guild.\n");
    if (type == "layman")
        return 1;

    return 0;
}

query_guild_keep_player(player)
{
    if (player->query_race_name() != "hobbit")
    {
	write("Only hobbits can be member of the hobbit race guild.\n");
	return 0;
    }

    return 1;
}
