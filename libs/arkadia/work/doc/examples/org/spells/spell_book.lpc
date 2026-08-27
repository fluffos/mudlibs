/* An example spell book made by Nick */

inherit "/std/spells";  /* To inherit the standard spell function. */
#include <macros.h>

#define SPELL_DIR "/doc/examples/spells/" /* To be used later. */

string spell_verb; /* This string will hold the verb the caster of a spell */
		   /* used. */

/*
 * Here follow the standard create routine of spells.
 * Here you can add spells to the object 
 */
void
create_spells()
{
    set_name("book");   /* A name for the object. */
    set_adj("spell");   /* It's a spell book. */

    set_long("It looks very interesting, perhaps you " +
        "should read it?\n");

    /* Now we add the spells. */
    /*         verb           function              name  */

    add_spell("light",      "cast_spell",       "light room");
    add_spell("shield",     "cast_spell",       "magic shield");
    add_spell("energy_blast", "cast_spell",     "energy blast");
}

/*
 * Add any more commands here?
 */
void
init()
{
    ::init(); /* Always good to do. */
    add_action("read", "read");
}

/*
 * Player tries to read something
 */
int
read(string str)
{
    notify_fail("Read what? The spell book?\n");
    if (!id(str))
	return 0;

    write(break_string("You start to read the old runes in the " +
        "book. You recognize The formulas of three spells:\n", 70) +
        "light room     - to light up the room you are in.\n" +
        "shield         - to get yourself or another person a magic\n" +
        "                 shield as protection.\n" +
        "energy_blast   - to burn your enemy with raw energy.\n");
    return 1;
}

/*
 * This function is called when the spell is actually cast. This is the
 * second argument in add_spell(). See create_spell() above
 */
int
cast_spell(string str)
{
    string spell_file;

    seteuid(getuid(this_object())); /* We might have to load a file. */
    spell_file = SPELL_DIR + spell_verb;

    /* This will call the <function name> in th <spell_file> with the
       argument str. The actual spell code is there. */
    return call_other(spell_file, spell_verb, str);
}

/*
 * Does this spell take much time to cast? 
 */
int
query_spell_time(string str)
{
    spell_verb = str;

    if (str == "energy_blast")
	return 3; /* Energy_blast takes a little more concentration */

    return 0; /* Concentration will be during 2 (default value) + 0 */
	      /* heart beats this way. */
}

/*
 * Do we want a special message to be printed or is the default message fine
 * with us?
 */
int
query_spell_mess(string str)
{
    if (str == "energy_blast")
    {
	write("You begin to speak ancient words aloud.\n");
	say(QCTNAME(this_player()) + " starts to speak ancient words aloud.\n");
        return 1;
    }
    return 0;
}

/*
 * Description:	This is called upon given spell command.
 *		It should print fail messages if appropriate
 * Returns:	1 if the spell fails.
 */
int
start_spell_fail(string verb, string arg)
{
    string str;
    string spell_file;

    spell_verb = verb;

    seteuid(getuid(this_object())); /* We might have to load a file. */
    spell_file = SPELL_DIR + verb;

    /* This will call the <function name> in th <spell_file> with the
       argument str. The actual spell code is there. */
    str = call_other(spell_file, spell_verb + "_start_fail", verb, arg);
    if (stringp(str))
    {
	write(str);
	return 1;
    }
    return str;
}

	
