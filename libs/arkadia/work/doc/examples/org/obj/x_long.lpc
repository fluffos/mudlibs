/*
 * A stone which gives its holder extra long description
 *
 * Made by Nick
 */

inherit "/std/object";
#include <stdproperties.h>
#define SUBLOC "holding_stone_subloc"

void
create_object()
{
    set_name("stone");
    set_adj("dull");
    set_long("It looks just like a normal stone.\n");
}

/* Called when stone enters another object */
void
enter_env(object to, object from)
{
    if (living(to))
	to->add_subloc(SUBLOC, this_object());
    ::enter_inv(to, from);
}

/* Called when stone leaves another object */
void
leave_env(object from, object to)
{
    if (living(from))
	from->remove_subloc(SUBLOC);
    ::leave_env(from, to);
}

/* Called when listning of subloc should be done. */
string
show_subloc(string subloc, object carrier, object for_obj)
{
    string str;

    if (carrier->query_prop(TEMP_SUBLOC_SHOW_ONLY_THINGS))
	return ""; /* Don't show this sublocation as inventory. */

    if (for_obj == carrier)
	str = "You look ";
    else
	str = capitalize(carrier->query_pronoun()) + " looks ";

    return str + "pretty stupid holding that stone.\n";
}


