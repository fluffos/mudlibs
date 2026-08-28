void do_nuke(object target);
int main (string str)
{
    object ob;
    if(!str)
	ob=environment(this_player());
    else
	ob=present(str,environment(this_player()));
    if(!ob)
	ob=find_player(str);
    if(!ob)
	ob=find_object(str);
    if(!ob)
    {
	write("Could not find the target.\n");
	return 1;
    }
    if(environment(ob))
	tell_room(environment(ob),
	  ob->query_name()+" explodes into thousands of pieces!\n",({ob}));
    do_nuke(ob);
    return 1;
}
void do_nuke(object target)
{
    object o, ob, *all;
    all=all_inventory(target);
    foreach (o in all)
    {
	if(!interactive(o))
	{
	    ob=first_inventory(o);
	    if(ob)
		do_nuke(o);
	    destruct(o);
	}
    }
}
