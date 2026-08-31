//  Trance Command

int cmd_trance(string s) {
    int x, b, time;
    object o, t;
    if(!s || s == "") return notify_fail("Trance who?\n");
    if(!o=present(s, environment(this_player()))) return
	notify_fail("You do not notice that here.\n");
    t=this_player();
    if(!o->is_living()) return notify_fail("You cannot trance "
	  "inanimate objects.\n");
    if(o->query_trance()) notify_fail(o->query_cap_name()+" is already under "
	  "someone elses control.\n");
    x=(o->query_stats("intelligence")+o->query_stats("wisdom"))*2/3+random(t->query_level());
    b=(t->query_stats("intelligence")+t->query_stats("wisdom")+
      (t->query_stats("charisma")/2))*2/3+random(t->query_level());
    if(x < b) return notify_fail("Your trance fails to affect "+o->query_cap_name()+".\n");
    time=(x-b)*3/2;
    if(time > 25) time=25;
    write("X: "+x+" T: "+b+" Time: "+time);
    write("You trance "+o->query_cap_name()+".");
    message("", "You pay a little too much attention to "+
      (string)t->query_cap_name()+"'s eyes and you fall under "+
      possessive(t)+" trance.", o);
    message("", o->query_cap_name()+" places "+o->query_cap_name()+
      " under a trance.", environment(t), ({o,t}) );
    o->set_trance(t);
    t->set_trancing(o, time);
    return 1;
}

