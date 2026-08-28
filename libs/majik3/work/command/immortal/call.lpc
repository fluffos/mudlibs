main(string str)
{
    string item, func;
    mixed arg, ret;
    int iwhat;
    object ob;

    if (!str) {
	notify_fail ("usage: call <object> <function>\n");
	return 0;
    }


    if (sscanf (str, "%s %s %d", item, func, arg) == 3)
    {
	iwhat = 1;
    }
    else if (sscanf (str, "%s %s %s", item, func, arg) != 3)
    {
	if (sscanf (str, "%s %s", item, func) == 2)
	{
	    iwhat = 0;
	}
	else
	{
	    notify_fail ("call: failed ("+item+":"+func+":"+arg+").\n");
	    return 0;
	}
    }

    if (item == "me")
	ob = this_player();
    else
    if(item=="here")
	ob=environment(this_player());
    else
	ob = find_living (item);

    if (!ob)
    {
	notify_fail ("No such object.\n");
	return 0;
    }

    ret = call_other(ob, func, arg);

    if (intp(ret))
	write("= (int) " + ret + "\n");
    else if (pointerp(ret)) {
	write("= (array size) " + sizeof(ret) + " ");
	for(int n=0;n<sizeof(ret);n++)
	    write (ret[n] + ",");
	write ("\n");
    }
    else if (stringp(ret))
	write("= (string) \"" + ret + "\"\n");
    else if (objectp(ret)) {
	write("= (object) "); write(ret);
	write("\n");
    }
    return 1;
}

