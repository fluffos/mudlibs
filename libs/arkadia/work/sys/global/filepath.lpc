/*
 * /sys/global/filepath.c
 *
 * Useful filepath manipulation
 */

#pragma no_clone
#pragma no_inherit
#pragma no_shadow
#pragma save_binary
#pragma strict_types

#include <std.h>

/*
 * Function name: fix_path
 * Description:   Fixes the pathname of files to a full path
 * Arguments:	  path: A pathname
 *                name: A filename possibly with path
 * Returns:       The full path filename or 0 if faulty format.
 */
string
fix_path(string path, string name) /* Revised Dworkin version by Cmd */
{
    string *fname;
    int i, sz;
    
    fname = explode((name[0] != '/' ? path : "") + "/" +name + "/", "/");
    
    /* resolve path */
    for (sz = 0, i = 0; i < sizeof(fname); i++)
	if (fname[i] == "..")
	    sz -= (sz) ? 1 : 0;
	else
	    if (fname[i] != "." && fname[i] != "")
		fname[sz++] = fname[i];
    
    if (sz > 0)
	return "/" + implode(slice_array(fname, 0, sz - 1),"/");
    else
	return "/";
}

/*
 * Function name: get_tilde_path
 * Description:   Gets the default path for a wizard or domain
 * Arguments:	  name: The name of the default wizard or domain
 *                tilde: A string of the type: '~', '~wizname' or '~Domname'
 * Returns:       A full path
 */
string
get_tilde_path(string name, string tilde)
{
    string *parts;
    
    if (tilde[0] != '~')
	return tilde;
    
    parts = explode(tilde + "/", "/");
    
    if (parts[0] != "~")
	name = extract(parts[0], 1);
    
    if (name != capitalize(name))
	return SECURITY->query_wiz_path(name) + "/" +
	    implode(slice_array(parts, 1, sizeof(parts)), "/");
    else
	return "/d/" + name + "/" +
	    implode(slice_array(parts, 1, sizeof(parts)), "/");
}

/*
 * Function name: reduce_to_tilde_path
 * Description:   Makes a 'tildepath' of a path if possible
 * Arguments:	  path: The path we are trying to make a 'tildepath' of.
 * Returns:       A tilde path
 */
string
reduce_to_tilde_path(string path)
{
    string *parts;

    parts = explode(path + "/", "/");

    while (sizeof(parts) > 1 && parts[0] == "")
	parts = parts[1..sizeof(parts)-1];

    if (sizeof(parts) < 2)
	return path;

    if ((sizeof(parts) > 2) && (parts[1] == WIZARD_DOMAIN))
	return "~" + implode(slice_array(parts, 2, sizeof(parts)), "/");


    if (parts[0] == "d")
    {
	if (SECURITY->query_domain_number(parts[1]) < 0)
	    return path;

	if (sizeof(parts) < 3)
	    return "~" + parts[1];

	if (SECURITY->query_wiz_path(parts[2]) == ("/d/" + parts[1] + "/" + parts[2]))
	    return "~" + implode(slice_array(parts, 2, sizeof(parts)), "/");

	return "~" + parts[1] + "/" +
	    implode(slice_array(parts, 2, sizeof(parts)), "/");
    }

    return path;
}
