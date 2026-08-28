/*
 * ZAP!            (c) Dazzt 
 * */

string msg = 
"Small cloud of  bluish smoke starts  to swirl over your head,  accelerating\n" +
"in speed.  It continues to swirl faster  and faster while starting to glow.\n" +
"The glow gets brighter and brighter forcing you to cover your eyes from the\n" +
"intense light emanating from the cloud.\n" +
"\n" + 
"In a loud ^cW*ZAP*^c0, a  sudden burst of lightning ^cBJOLTS^c0 from the cloud striking\n" +
"through your body causing your skin to ^crSIZZLE^c0 and heart miss several beats.\n" +
"\n";

zap(string who, int dam)
{
	object target;
	
         if (present(lower_case(who)))
                target = present(lower_case(who));
	else
                target = find_player(lower_case(who));
	
	if (!target)
	{
		message("0", "No such player.\n", THIS);
		return 1;
	}
	
	if ((target->query_hp() / 1.5) > dam)
		dam = target->query_hp() / 1.5;
	
	message("zap", "Ok, zapping " + capitalize(who) + 
			". Now has " + to_int(target->query_hp() - dam) + " hp left.\n", THIS);
	message("zap", msg, target);
	target->add_hp(-dam);
}


main(string args)
{
	string who;
	int amount;
	
	if (!args)
	{
		notify_fail("usage:  zap  <who> [amount of damage]\n");
		return 0;
	}
	
	if (sscanf(args, "%s %d", who, amount) == 2)
		zap(who, amount);
	else
		zap(args, 100 + random(100));

	return 1;
}
