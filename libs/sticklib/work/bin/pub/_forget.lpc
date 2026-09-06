

nomask int
forget_cmd(string s, object me) {
    object *list;
    string name;
    int i;

    if(!s || !me) return 0;
    s = lower_case(s);

    list = (object *)me->query_hunted();

    if(!list || !(i=sizeof(list))) {
	me->tell_me("You are not hunting anyone.");
	return 1;
    }

    while(--i) {
	if(list[i]) {
	    if(list[i]->query_npc()) {
		if(name = (string)list[i]->query_name()) 
		    name = lower_case(name);
		else continue;
	    }
	    else name = (string)list[i]->query_real_name();
	    if(name == s) {
		me->tell_me("You are no longer hunting "+capitalize(name));
		list -= ({list[i]});
		me->set_hunted(list);
		return 1;
	    }
	}
    }

    me->tell_me("Hmmmm... you are not hunting "+ capitalize(s) + ".");
    return 1;
}

