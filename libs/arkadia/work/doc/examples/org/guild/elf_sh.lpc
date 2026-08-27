/* The elf shadow */

inherit "/std/guild/guild_race_sh";

query_guild_tax_race() { return 2; }

query_guild_not_allow_join_race(player, type, style, name)
{
    if (::query_guild_not_allow_join_race(player, type, style, name))
	return 1;

    return 0;
}

query_guild_keep_player(player)
{
    if (player->query_race_name() != "elf")
    {
	write("Only elves can be member of the elf race guild.\n");
	return 0;
    }

    return 1;
}


