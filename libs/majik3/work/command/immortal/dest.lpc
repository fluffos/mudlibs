int
main(string arg)
{
    object obj;

    if (!arg) 
    {
	write("usage: dest <object>\n");
	return 1;
    }

    if (!(obj = present(arg)))
    {
	notify_fail("Can't find " + arg + ".\n");
	return 0;
    }

/*
if (interactive(THIS)) { return 1; }
*/


    obj->remove();
    if (obj)
	destruct(obj);

    return 1;
}
