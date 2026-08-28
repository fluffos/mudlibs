do_success(object me, string target)
{
  
	object o;
	
	o = clone_object("/home/harum/random_animal");	
	

	emote("$n {summon} " +o->query_name()+"!", me, 0, ENV(me));

	o->move(ENV(me));

      	return 1;
    
}

do_failure(object me, string target)
{
	
	emote("$n {fail} the spell.", me, 0, ENV(me)); 

	return 1;
}

query_offensive() { return 0; }
query_true_magick() { return 1; }
