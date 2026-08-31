mixed check_attack(string arg){
    object victim;
    if(!arg && VAGSOUL->query_cur_opponent() != 0 ) {
	if(present(VAGSOUL->query_cur_opponent(),
	    ENV(TP) )) {
	    arg = VAGSOUL->query_cur_opponent();
	} else {
	    write("That creature is no longer present.\n");
	    return 1;
	}
    }

    if(arg != 0 ) {
	victim = present(arg, ENV(TP) );
    } else {
	write("Invalid input!\n");
	return 1;
    }


    if(objectp(victim) && living(victim) &&
      ENV(victim) == ENV(TP) )
    {
	VAGSOUL->set_cur_opponent(arg);
	return victim;
    } else {
	write("No such creature is present.\n");
	return 1;

    }
}


