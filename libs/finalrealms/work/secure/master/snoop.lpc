int valid_snoop(object snooper, object snoopee, object pobj) {
    if (snooper == snoopee) {
	tell_object(snooper, "You can't snoop yourself.\n");
	return 0;
    }
    if (snoopee && query_snoop(snoopee)) {
	tell_object(snooper,
	  snoopee->query_cap_name()+" is already being snooped.\n");
	return 0;
    }
    if (snooper->query_snoopee()) {
	if (!snooper->query_property("quiet snoop")) {
	    event(users(), snooper->query_cap_name()+" stops qsnooping "+
	      snooper->query_snoopee()->query_name(), "snoop");
	    tell_object((object)snooper->query_snoopee(),
	      snooper->query_cap_name()+" stops snooping you.\n");
	} else {
	    event(users(), snooper->query_cap_name()+" stops snooping "+
	      snooper->query_snoopee()->query_name(), "snoop"); 
	    snooper->remove_property("quiet snoop");
	}
	snooper->set_snoopee(0);
    }
    if (!snoopee) {
	return 1;
    }

    if (query_snoop(snoopee))
	return 0;
    if (!snooper->query_creator())
	return 0;
    if (pobj == this_object()) {
	event(users(), snooper->query_cap_name()+" starts qsnooping "+
	  snoopee->query_name(), "snoop"); 
	return 1;
    }
    if (query_verb() == "qsnoop" && query_lord(geteuid(snooper)))
    {
	tell_object(snooper, "You are quiet snooping "+
	  snoopee->query_cap_name()+"\n");
	snooper->add_property("quiet snoop", 1);
    } 
    else 
    {
	tell_object(snoopee, "You are being snooped by "+
	  snooper->query_cap_name()+".\n");
	tell_object(snooper, "You are snooping "+
	  snoopee->query_cap_name()+"\n");
    }
    // Radix...
    if(snooper->query_invis()  < 2)
    {
      log_file("SNOOP",ctime(time()) + " " +
	(string)snooper->query_cap_name() + " " +
	query_verb() + "s " + (string) snoopee-> query_cap_name()+ ".\n");
	snooper->set_snoopee(snoopee);
      tell_object(snooper, "Please share with us the reason why you are " +
	"snooping.\n: ");
      input_to("snoop_reason");
      event(users(), snooper->query_cap_name()+" starts snooping "+
	snoopee->query_name(), "snoop");
    }
    snoop_list[snooper] = snoopee;
    return 1;
} /* valid_snoop() */

void snoop_reason(string str) {
    object snooper;

    snooper = this_player();
    if (this_player(1) != this_player()) {
	write("Can't force people...\n");
	return ;
    }
    /*  if (!high_programmer(geteuid(this_player()))) {
	write("Not a high programmer.\n");
	return ;
      } */
    if (!snoop_list[snooper]) {
	write("The snoopee has just logged out.\n");
	return ;
    }
    if(!str) {
	write("Snoop canceled.\n");
	log_file("SNOOP", "  Chickened out.\n");
	return;
    }
    log_file("SNOOP", "  Reason: " + str + "\n");
    if (snoop(snooper, snoop_list[snooper]))
	write("Snoop suceeded,\n");
    else
	write("Snoop failed.\n");
} /* snoop_reason() */
