do_success(object me, string target)
{
  
	object o;
	string *danger_zones = (({"~", "L", "^", "V", "R"}));
	int ycord, xcord;
   	
	if (target && find_player(target)) 
		o = find_player(target);
	else o = me;	

	ycord = random(620);
	xcord = random(620);
	while (member_array("/daemon/world"->query_world(0, ycord)[xcord..xcord],
		danger_zones) != -1)
	{
		ycord = random(620);
		xcord = random(620);
	}
	
	emote("$n {banish} $N!", me, o, ENV(me));
	
	o->move_player("/world/y"+ycord+"x"+xcord);

      	return 1;
    
}

do_failure(object me, string target)
{
	object o;

	if (target && find_player(target)) 
		o = find_player(target);
	else o = me;	


	emote("$S's body flickers as if going to vanish but $n {lose} the spell.", me, o, ENV(me)); 

	return 1;
}

query_offensive() { return 0; }
query_true_magick() { return 1; }
