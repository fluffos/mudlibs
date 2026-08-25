/* This will be the table for spells.
 * It will be the place spells.c will look for when it casts a spell, and the
 * guld will find the spells to add to a player. 
 * This will reduce the memory requirements in the spell array in the player obs
 * But it may be slower than the old system. I am not sure yet tho..
 * Started sept 11 '93 by Baldrick.
 */
/* the complete array will not be finished until I know what I need */
/* it looks like the easiest method is to have two tables, one for sphere/spell
 * and one for spell/filename.. Shame ..*/

/*** Addition of spells and new spheres started by Eerevann Nov 93 ***/

mixed query_spellist()
{
    mixed list;
    int level;
    string bing;

    list = ({ });
    level = this_player()->query_level();

    /* I'm afraid we have to put a query_spell into all the cases.. */

    /* this is the way of adding a sphere/school */

    /*** Level/Spell progression is as per AD&D ***/
    /*** CLERIC MAGIC ***/
    /*** 1st level spells at 1st level, 2nd level spells at 3rd level ***/
    /*** 3rd level spells at 5th level, 4th level spells at 7th level ***/
    /*** 5th level spells at 9th level, 6th level spells at 11th level ***/
    /*** 7th level spells at 14th level ***/

    /*** WIZARD MAGIC ***/
    /*** 1st level spells at 1st level, 2nd level spells at 3rd level ***/
    /*** 3rd level spells at 5th level, 4th level spells at 7th level ***/
    /*** 5th level spells at 9th level, 6th level spells at 12th level ***/
    /*** 7th level spells at 14th level 8th level spells at 16th level ***/
    /*** 9th level spells at 18th level ***/


    if (this_player()->query_sphere("all"))
    {
	switch(level)
	{
	case 14..1000:
	case 11..13:
	case 9..10:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    if(!this_player()->query_spell("bless"))
		list += ({"bless"});
	    break;
	}
    } /* if ALL SPHERE */


    if (this_player()->query_sphere("healing"))
    {
	switch(level)
	{
	case 1..2:
	    if (!this_player()->query_spell("cure light wounds"))
		list += ({"cure light wounds",});
	    if (!this_player()->query_spell("cause light wounds"))
		list += ({"cause light wounds",});
	    break;
	}
    } /* if HEALING SPHERE */

    if (this_player()->query_sphere("plant"))
    {
	switch(level)
	{
	case 14..1000:
	case 11..13:
	    if(!this_player()->query_spell("pacify"))
		list += ({ "pacify", });
	case 9..10:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    break;
	}
    } /* if PLANT */


    if (this_player()->query_sphere("sun"))
    {
	switch(level)
	{
	case 14..1000:
	case 11..13:
	case 9..10:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    if(!this_player()->query_spell("light"))
		list += ({"light",});
   	  break;
	}
    } /* if SUN */

    if (this_player()->query_sphere("weather"))
    {
	switch(level)
	{
	case 14..1000:
	case 11..13:
	case 9..10:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    break;
	}
    } /* if WEATHER */

    /*** THIS SECTION FOR MAGE SCHOOLS ****/

    if (this_player()->query_sphere("abjuration"))
    {
	switch(level)
	{
	case 30..1000:
	case 18..29:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
 	case 5..6:
	case 3..4:
	case 1..2:

	    break;
	}
    } /* if ABJURATION */

    if (this_player()->query_sphere("alteration"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:

	    break;
	}
    } /* if ALTERATION */

    if (this_player()->query_sphere("conjuration"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    break;
	}
    } /* if CONJURATION */


    if (this_player()->query_sphere("enchantment"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    break;
	}
    } /* if enchantment */
    if (this_player()->query_sphere("aphelic"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    break;
	}
    } /* if aphelic */

    if (this_player()->query_sphere("illusion"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:

	    break;
	}
    } /* if ILLUSION */

    if (this_player()->query_sphere("invocation"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 10..11:
	case 9:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:
	    break;
	}
    } /* if INVOCATION */

    if (this_player()->query_sphere("lesserdivination"))
    {
	switch(level)
	{
	case 7..1000:
	case 5..6:
	case 3..4:
	case 1..2:

	    break;
	}
    } /* if LESSERDIVINATION EVERY SPECIALIST AND WIZARD GETS THIS */

    if (this_player()->query_sphere("greaterdivination"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	    break;
	}
    } /* if GREATER DIVINATION 5TH LEVEL MAGIC AND HIGHER */


    if (this_player()->query_sphere("necromancy"))
    {
	switch(level)
	{
	case 18..1000:
	case 16..17:
	case 14..15:
	case 12..13:
	case 9..11:
	case 7..8:
	case 5..6:
	case 3..4:
	case 1..2:

	    break;
	}
    } /* if NECROMANCY */

    if(this_player()->query_sphere("test"))
    {
	switch(level)
	{
	case 1..1000:
	    if(!this_player()->query_spell("teleport"))
		list += ({"teleport",});
	    if(!this_player()->query_spell("typetest"))
		list += ({"typetest",});
	    if(!this_player()->query_spell("test"))
		list+= ({"test",});
	    break;
	}
    }  /*** TEST SPHERE, for testing spells...doh! ***/

    return list;
} /* mixed query_spellist */

string query_spellfilename(string spell)
{
    if (spell)
    {
	switch (spell)
	{

	    /*** Cleric Spell Listing, also Ranger and Paladin ****/

	case "symbol transformation": return ("sym_spell");
	case "holy storm": return "holy_stm";
	case "pacify": return ("pacify"); 
	case "cure light wounds": return ("cure_lt");
	case "bless": return ("bless");
	case "spirit armour": return ("sp_armour");
	}
    } /* if (spell) */
    return 0;
} /* query_spellfilename */
