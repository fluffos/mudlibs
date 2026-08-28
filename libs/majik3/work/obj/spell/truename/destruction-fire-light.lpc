do_success(object me, string target)
{
      	object o, ob;
	
	if (target)
	  o = present(target);
	else 
	  o = THIS;

 	ob = clone_object ("/obj/sphere_of_darkness");
	if (living(o))
	emote ("Suddenly a sphere of darkness surrounds $N.",
		me, o, ENV(me));
	else message("spell", "Suddenly a sphere of darkness surrounds "
		+o->query_maybe_cap_name()+".\n", ENV(o));
      	ob->move(o);
     
      return 1;
    
}

do_failure(object me, string target)
{
  emote ("$s vision goes dark for a moment but then everything is back to normal.", me, 0, me);

  return 1;
}

query_offensive() { return 0; }
query_true_magick() { return 1; }
