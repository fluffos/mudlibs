/*
 * /basic/debug.c
 */

void debug (string str) {
    mixed who;

    if ((who = creator (this_object())) && (who = find_living (who)))
	tell_object (who, object_name (this_object()) + ": " + str + "\n");
}

string debug_print_single (mixed val) {
    if (stringp (val))	return "\""+val+"\"";
    if (intp (val))	return ""+val;
    if (floatp (val))	return ""+val;
    if (objectp (val))	return "["+object_name (val)+"]";
    return "<UNKNOWN>";
}

string debug_print (mixed obj) {
    if (pointerp (obj)) {
	return
	    "({"
	    + implode (map (obj, "debug_print", this_object()), ",")
	    + ",})";
    }

    if (mappingp (obj)) {
	return
	    "(["
	    + implode (map (m_indices(obj), "debug_print", this_object()), ",")
	    + " : "
	    + implode (map (m_values(obj), "debug_print", this_object()), ",")
	    + "])";
    }

    return debug_print_single(obj);
}

varargs void debug_dump (mixed obj, string tab) {
    int i;

    if (!tab) tab = "";
    if (stringp (obj) || intp (obj)) debug (tab + obj);
    else if (objectp (obj)) debug (tab + object_name (obj));
    else if (pointerp (obj)) {
	debug (tab + "({");
	for (i = 0; i < sizeof (obj); i++) debug_dump (obj[i], tab + "  ");
	debug (tab + "})");
    } else if (mappingp (obj)) {
	obj = ({m_indices (obj), m_values (obj)});
	debug (tab + "([");
	for (i = 0; i < sizeof (obj[0]); i++)
	    debug (tab + "  "
		+ debug_print (obj[0][i])
		+ ": "
		+ debug_print (obj[1][i]));
	debug (tab + "])");
    } else debug (tab = "<UNKNOWN>");
}

