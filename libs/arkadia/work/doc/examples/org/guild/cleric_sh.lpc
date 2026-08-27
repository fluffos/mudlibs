/* The magic shadow */

inherit "/std/guild/guild_occ_sh";

#define TAXRATE 11

/*
 * This is the initial taxrate for the guild. Use set_guild_pref() in the
 * player to change it if needed.
 */
query_guild_tax_occ() { return TAXRATE; }

query_guild_not_allow_join_occ(player, type, style, name)
{
    if (::query_guild_not_allow_join_occ(player, type, style, name))
	return 1;

    notify_fail("No thieves in our group.\n");
    if (style == "thief")
        return 1;

    return 0;
}
