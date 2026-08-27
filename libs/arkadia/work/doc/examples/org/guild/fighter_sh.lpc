/* The fighter shadow */

inherit "/std/guild/guild_occ_sh";

query_guild_tax_occ() { return 12; }

query_guild_not_allow_join_occ(player, type, style, name)
{
    if (::query_guild_not_allow_join_occ(player, type, style, name))
	return 1;

    notify_fail("We brave fighters don't mess with magic.\n");
    if (style == "magic")
	return 1;

    return 0;
}
