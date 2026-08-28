main(string str)
{       
    object ob;
    if (!str) 
    {
	snoop();
	return 1;
    }

   ob = (find_player(lower_case(str)) || find_object(str));
    if(!ob)
    {
	write("No such player.\n");
	return 1;
    }
    if(!interactive(ob))
    {
	write("Target is not interactive.\n");
	return 1;
    }
    if (ob->query_security() > this_player()->query_security())
    {
	write ("Permission denied.\n");
	tell_object (ob, capitalize(THIS->query_name()) + " tried to snoop you!.\n");
	return 1;
    }
    if (ob->query_security() == this_player()->query_security())
    {
        write ("You are snooping a dude with same security.\n Informing " + ob->query_cap_name() + " about your snooping.\n");
	tell_object (ob, capitalize(THIS->query_name()) + " is snooping you! (same security alert).\n");
	snoop(ob);
	return 1;
    }
    if(ob)
	snoop (ob);
    else
	write ("No such living thing.\n");

    return 1;   
}
