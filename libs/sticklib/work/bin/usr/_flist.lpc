status
flist_cmd(string arg, object me)
{
    object ob;
    int i;
    string *funs;

    if(!arg || arg=="")
    {
	this_player()->tell_me("usage:flist <ob>\n");
	return 1;
    }
    ob = get_object(arg);
    if(!ob)
    {
	this_player()->tell_me(arg+" not found\n");
	return 1;
    }
    funs = functionlist(ob);
    me->tell_me(sprintf("Functions of object '%O' are:\n%s.",
	ob, implode(funs, ", ", " and ")));
    return 1;
}
