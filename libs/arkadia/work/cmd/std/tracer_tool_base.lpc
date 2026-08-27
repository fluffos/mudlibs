/*
 * /cmd/std/tracer_tool_base.c
 * 
 * The basic tracer tool functions used in the commons soul for
 * parsing arguments to certain functions.
 */

#pragma no_clone
#pragma save_binary
#pragma strict_types

inherit "/cmd/std/command_driver";

#include <filepath.h>

#define TRACER_STORES	"_tracer_stores"
#define TRACER_VARS	"_tracer_vars"

/*
 * Function name: find_item
 * Description  : This function will try to find the object the wizard
 *                points at with the string argument.
 * Arguments    : object prev - the previous object found in the chain.
 *                string str  - the string to parse.
 * Returns      : object - the object described with 'str', if any.
 */
object
find_item(object prev, string str)
{
    object ob;
    object *ob_list;
    string tmp;
    int    i;

    if ((str == "here") ||
	(str == "!"))
    {
	return environment(this_interactive());
    }

    if (str == "me") 
    {
	return this_interactive();
    }

    if (str == "^")
    {
	return environment(prev);
    }

    if (sscanf(str, "@%s", tmp) == 1)
    {
	return find_living(tmp);
    }

    if (sscanf(str, "*%s", tmp) == 1)
    {
	return find_player(tmp);
    }

    if (sscanf(str, "$%d", i) == 1)
    {
	ob_list = users();
	write("size: " + sizeof(ob_list) + "\n");
	if ((i >= sizeof(ob_list)) ||
	    (i < 0))
	{
	    return 0;
	}
	return ob_list[i - 1];
    }

    if (prev == 0)
    {
	prev = environment(this_interactive());
    }

    if (sscanf(str, "\"%s\"", tmp) == 1)
    {
	ob_list = all_inventory(prev);
	for (i = 0 ; i < sizeof(ob_list) ; i++)
	{
	    if ((string)ob_list[i]->short() == tmp)
	    {
		return ob_list[i];
	    }
	}
    }

    if (sscanf(str, "#%d", i) == 1)
    {
	if (prev == 0)
	{
	    return 0;
	}
	ob_list = all_inventory(prev);
	if (i > sizeof(ob_list))
	{
	    return 0;
	}

	return ob_list[i - 1];
    }

    if (ob = present(str, prev))
    {
	return ob;
    }

    if (ob = present(str, this_interactive()))
    {
	return ob;
    }

    tmp = FTPATH(this_interactive()->query_path() + "/", str);
    if (strlen(tmp))
    {
	catch(call_other(tmp, "??"));	/* Force load */
	return find_object(tmp);
    }

    return 0;
}

/*
 * Function name: assign
 * Description  : This function will assign tracer values to special tracer
 *                variables stored in a player as properties.
 * Arguments    : string var - the name of the variable.
 *                mixed val  - the tracer value to store.
 */
void
assign(string var, mixed val)
{
    int i;
    mixed *vars;
    mixed *stores;

    vars = (string *)this_interactive()->query_prop(TRACER_VARS);
    stores = (mixed *)this_interactive()->query_prop(TRACER_STORES);

    while (i < sizeof(vars))
    {
	if (vars[i] == var)
	{
	    stores[i] = val;
	    break;
	}
	if (vars[i] == 0)
	{
	    vars[i] = var;
	    stores[i] = val;
	    break;
	}
	i += 1;
    }

    this_interactive()->add_prop(TRACER_VARS, vars);
    this_interactive()->add_prop(TRACER_STORES, stores);
}

/*
 * Function name: parse_list
 * Description  : This function will take a 'tracer tool' argument and
 *                turns it into an objectpointer if possible.
 * Arguments    : string str - the argument to parse.
 * Returns      : object - the object found, if any.
 */
object
parse_list(string str)
{
    string tmp;
    string rest;
    object prev;

    prev = environment(this_interactive());
    while (objectp(prev) &&
	   stringp(str))
    {
	if (sscanf(str, "%s:%s", tmp, rest) == 2)
	{
	    prev = find_item(prev, tmp);
	    str = rest;
	    continue;
	}
	prev = find_item(prev, str);
	break;
    }

    assign("$", prev);
    if (objectp(prev))
    {
	write(file_name(prev) + "\n");
    }

    return prev;
}

/*
 * Function name: print_value
 * Description  : print out a value in a format appropriate for its type.
 * Arguments    : mixed ret - the value to print.
 */
void
print_value(mixed ret)
{
    if (intp(ret))
    {
	write("(int) " + ret + "\n");
    }
    else if (pointerp(ret))
    {
	write("Array of size " + sizeof(ret) + "\n");
	dump_array(ret);
    }
    else if (mappingp(ret))
    {
	write("Mapping of size " + m_sizeof(ret) + "\n");
	dump_mapping(ret);
    }
    else if (stringp(ret))
    {
	write("String: '" + ret + "'\n");
    }
    else if (objectp(ret))
    {
	write("Object: " + file_name(ret) + "\n");
    }
    else if (floatp(ret))
    {
	write(ftoa(ret) + "\n");
    }
    else if (functionp(ret))
    {
	write(sprintf("%O\n", ret));
    }
    else
    {
	write("Unknown!\n");
    }
}

/*
 * Function name: fix_one_arg
 * Description  : The individual arguments found in parse_arg are checked
 *                with this function to catch all arrays and to distinct
 *                between string or integer
 * Arguments    : what  - the argument to parse
 * Returns      : mixed - either an integer or a string
 */
mixed
fix_one_arg(string what)
{
    int narg;
    string apa;

    if (sscanf(what, "({%s})", apa) == 1)
    {
	return map(explode(apa + ",", ","), fix_one_arg);
    }
    if (sscanf(what, "%d", narg) == 1)
    {
	return narg;
    }
    return what;
}

/*
 * Function name: parse_arg
 * Description  : This function is used to split the argument part of the
 *                paramtere to Call. Arguments, either string or integer
 *                may be separated by %% from eachother. An element may
 *                also be an array of mixed string and integer, though
 *                within the array, the elements should be devided by
 *                commas.
 *                Example: Mercade%%({Nick,Mrpr})%%45
 * Arguments    : what  - the string to parse
 * Returns      : mixed - an array with arguments
 */
mixed
parse_arg(string what)
{
    return map(explode(what + "%%", "%%"), fix_one_arg);
}
