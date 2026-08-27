/*
 * tilde_path.c
 *
 * Written: 921226 by Zak.
 * Attempts to reduce a given path into '~' format
 * 930320, Zak: added default for `name', idea from Pallando.
 */


string tilde_path(string path, string name)
{
    string wiz, rest;

    if(!path)
	return "";
    if ( !name && this_player() )
        name = geteuid( this_player() );
    if (sscanf(path, "/u/%*s/%s", rest) == 2)
    {
	if (sscanf(rest, "%s/%s", wiz, rest) != 2)
	{
	    wiz = rest;
	    rest = "";
	}
	else
	    rest = "/" + rest;
	if (wiz == name)
	    path = "~" + rest;
	else
	    path = "~" + wiz + rest;
    }
    return path;
} /* tilde_path */
