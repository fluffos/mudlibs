do_success(object me, string target)
{
      	object o, ob;
	
	if (target && present(target))
	  o = present(target);
	else
	  o = me;

	ob = clone_object ("/obj/sphere_of_light");
	if (living(o))
	emote ("Suddenly a small sphere of light appears and begins to follow $N.",
		me, o, ENV(me));
	else message("spell","Suddenly a small sphere of light appears and begins to follow "
		+o->query_maybe_cap_name()+".\n",ENV(o));
      	ob->move(o);
//	o->set_long(o->long()+ "A small light emitting sphere is levitating beside "
//		+o->query_objective()+ ".\n");

      return 1;
    
}

do_failure(object me, string target)
{
	object o;
	
	if (target && present(target))
	  o = present(target);
	else
	  o = me;

  emote ("Something bright flashes beside $n but nothing more seems to happen.", o, 0, ENV(o));
  
  return 1;
}

query_offensive() { return 0; }
query_true_magick() { return 1; }
