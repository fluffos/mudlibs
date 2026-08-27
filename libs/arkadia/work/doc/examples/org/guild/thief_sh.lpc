/* The magic shadow */

inherit "/std/guild/guild_lay_sh";

query_guild_tax_lay() { return 35; }

query_guild_not_allow_join_lay(player, type, style, name)
{
    if (::query_guild_not_allow_join_lay(player, type, style, name))
	return 1;

    notify_fail("No elves in our guild.\n");
    if (player->query_race_name() == "elf")
	return 1;

    return 0;
}
