/* This spell is a test spell. It is extremely powerful and therefore needs tuning before
the game begins in the earnest. */
do_success(object me, string target)
{
    object *all;
    object ob;
    all=all_inventory(environment(me));
    foreach (ob in all)
    {
	if(ob->query_race()=="dwarf")
	{
	    tell_object(ob,"You shriek from pain as cease from existing!\n");
	    tell_room(environment(me),
	      ob->query_cap_name()+" shrieks in terror and disappears!\n",
	      ({ob}));
	    destruct(ob);
	}
    }
    return 1;
}

do_failure(object me, string target)
{
    object *all, ob;
    all=all_inventory(environment(me));
    foreach (ob in all)
    {
	if(ob->query_race()=="dwarf")
	{
	    tell_room(environment(ob),
	      ob->query_cap_name()+" looks very ill.\n",({ob}));
	    tell_object(ob,"You feel very sick!\n");
	    ob->damage_me(ob->query_hp()/2,0,"head");
	}
    }
    return 1;
}

query_offensive() { return 1; }
query_true_magick() { return 1; }
