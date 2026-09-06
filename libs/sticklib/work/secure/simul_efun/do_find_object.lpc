object
do_find_object(string fname)
{
    object ob;
    if (!stringp(fname))
	raise_error(sprintf("\nError in %s: Non-string argument for\
 simulated efun 'do_find_object()'.\n", object_name(previous_object())));
    if (ob = find_object(fname))
	return ob;
    call_other(fname, "?");
    return find_object(fname);
}
