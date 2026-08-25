/*
 * /std/guild/guild_race_sh.c
 *
 * This is the standard guild shadow for an race guild. It defines
 * The necessary functions.
 */

/*
 * Functions in this object.
 *
 * Arguments:    s = string, i = integer, o = object
 *
 * query_guild_tax_race()  Should return the tax we want the player to pay.
 *			   If the tax is to change, i.e. the player learns a
 *			   new spell, call notify_guild_tax_changed() to set
 *			   the tax correctly.
 *
 * query_guild_type()      Always returns "race"
 *
 * query_guild_style_race() What styles are we? fighter, magic, cleric, thief
 *			   are the standard styles but there are other styles 
 *			   aren't there, perhaps we should enlarge the list.
 *
 * query_guild_name_race() The name of the guild.
 *
 * query_guild_title_race() This is called from the player object to find
 *                         the title of this guild.
 *
 * query_guild_family_name() Called in members of a racial guild to see
 *                         whether their guild-title is a family name of
 *                         just a title like other guilds have too. True
 *                         if the title is a family name.
 *
 * query_guild_not_allow_join_occ(o, s, s, s) This is called when our member
 *			   tries to join another guild. The type, style and 
 *			   name of the other guild is sent as argument and we
 *			   can deny our member to join that guild if we want.
 *			   Observe, returning 1 will deny the player. This
 *			   function will also be called each time a player 
 *			   logs on, we could test if the race has changed or
 *			   anything....
 *
 * query_guild_member_race() Is always true, ofcourse.
 *
 * query_guild_trainer_race() Returns a reference to the file or files that
 *			   defines sk_query_max for the player in question.
 *			   The returned items could be a string, an object
 *			   pointer or an array of the same.
 *
 * query_guild_leader_race() Define this function to return true of the player
 *                         is considered to be one of the leaders of his/her
 *                         guild in the form of a council-membership, et
 *                         cetera.
 *
 * query_guild_incognito_race() Define this function so that it returns true if
 *                         the player's guild affiliation should be unknown.
 *
 * remove_guild_race()     Call this if you are removeing your guild from the 
 *			   player, and you are a race guild.
 * 
 * autoload_shadow(s)      Is called when a player enters and we shall load
 *			   the autoloading shadows.
 *
 * Note: You will probably want to redefine query_guild_tax_race() and
 *       query_guild_not_allow_join_race(s, s, s).
 */

#pragma strict_types

inherit "/std/guild/guild_base";

#include <macros.h>
#include <ss_types.h>

/*
 * Function name: query_guild_tax_race
 * Description:   What's the tax to pay at this guild? You should write your
 *                own version of this function.
 * Returns:       the tax this guild wants
 */
public int
query_guild_tax_race()
{
    return 0;
}

/*
 * Function name: query_guild_type
 * Description:   what type of guild is this, occupational, layman or race?
 * Returns:       a string with the type
 */
public nomask string
query_guild_type()
{
    return "race";
}

/*
 * Function name: query_guild_style_race
 * Description:   What styles is this guild? fighter, magic, cleric, thief or  ?
 * Returns:       string - holding the style of guild
 */
public string
query_guild_style_race()
{
    return "race";
}

/*
 * Function name: query_guild_name_race
 * Description:   Returns the name of the guild this shadow represents
 * Returns:	  The name of the guild
 */
public string
query_guild_name_race()
{
    return "race";
}

/*
 * Function name: query_guild_title_race
 * Description  : This function should return the race title off
 *                the player. Since this function is not called for wizards
 *                you do not have to distinct for them in this function.
 *                If your racial guild consists of families that give its
 *                members a family name, you also need to define the
 *                function query_guild_family_name() defined below.
 * Returns      : string - the title for the player.
 *                The title will be incorporated in the format
 *                "the <race title>, <occ title> and <lay title>"
 *                if the player is a member of all major guild types.
 */
public string
query_guild_title_race()
{
    return "";
}

/*
 * Function name: query_guild_family_name
 * Description  : If the guild consists of families that give their members
 *                a family name, this function should return true. It
 *                moves the article 'the' to the occupational title of
 *                the member giving:
 *                "<race title>, the <occ title> and <lay title>"
 *                if the player is a member of all major guild types.
 * Returns      : int - true if the function query_guild_title_race()
 *                      returns the family name and not a normal guild
 *                      title.
 */
public int
query_guild_family_name()
{
    return 0;
}

/*
 * Function name: query_allow_join_race
 * Description:   Test if this guild allowed a player to join another
 * Arguments:     type  - the type of guild to join
 * 		  style - the style of the guild
 *		  name  - the name
 * Returns:       1 - I allow member to join another guild
 */
public int
query_guild_not_allow_join_race(object player, string type, string style,
			        string name)
{
    if (type == "race")
    {
        notify_fail("One race guild is enough.\n");
	return 1;
    }

    return 0;
}

/*
 * Function name: query_guild_member_race
 * Description:   This is a race guild
 * Returns:	  1
 */
public nomask int
query_guild_member_race()
{
    return 1;
}

/*
 * Function name: query_guild_trainer_race
 * Description:   Return one or more references to the object that define
 *                sk_train_max for the player. The returned refernce can
 *                be a string reference, an object pointer or an array of
 *                those.
 * Returns:       See description.
 */
public mixed
query_guild_trainer_race()
{
    return 0;
}

/*
 * Function name: query_guild_leader_race
 * Description  : Define this function to return true if the person is a
 *                leader of his/her race guild, in a council-membership
 *                or something similar.
 * Returns      : int 1/0 - layman guild leader or not.
 */
public int
query_guild_leader_race()
{
    return 0;
}

/*
 * Function name: query_guild_incognito_race
 * Description:   Define this function so that it returns true if
 *                the player's guild affiliation should be unknown.
 * Returns:       1/0 - unknown/not
 */
public int
query_guild_incognito_race()
{
    return 0;
}

/*
 * Function name: remove_guild_member_race
 * Description:   Remove a player from the guild. Will take care of everything.
 * Returns:       1 if removed
 */
public nomask int
remove_guild_race()
{
    if (!shadow_who->remove_autoshadow(MASTER + ":"))
	return 0;

    shadow_who->set_guild_pref(SS_RACE, 0);
    remove_shadow();
    return 1;
}

/*
 * Function name: init_race_shadow()
 * Description: This function is called from autoload_shadow and may
 *              be used to initialize the shadow when it's loaded.
 * Arguments: The argument string sent to autoload_shadow.
 */
public void
init_race_shadow(string arg)
{
}

/*
 * Function name: autoload_shadow
 * Description:   Called by the autoloading routine in /std/player_sec
 *		  to ensure autoloading of the shadow.
 * Arguments:	  str - the string holding type, style and name of the guild
 */
public nomask void
autoload_shadow(string str)
{
    if (shadow_who)
	return; /* Already shadowing */

    if (query_guild_not_allow_join_guild(this_player(), "race",
		query_guild_style_race(), query_guild_name_race()))
    {
	write("Your guilds don't seem to get along. Your race guild " +
	      "is removed.\n");
	this_player()->remove_autoshadow(MASTER);
	return;
    }

    if (!query_guild_keep_player(this_player()))
    {
	this_player()->remove_autoshadow(MASTER);
	return;
    }

    ::autoload_shadow(str);
    this_object()->init_race_shadow(str);

    this_player()->set_guild_pref(SS_RACE, query_guild_tax_race());
}
