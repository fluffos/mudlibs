mapping query_apply(int troop, string what)
{
	mapping apply, troops;

	troops = TROOP_D->query_troops();
	if( member_array(troop, keys(troops)) == -1 )return ([ ]);
	apply = troops[troop]["apply"];
	if( !what || !stringp(what) || what == "" )return apply;
	else return apply[what];
}
void set_apply(int troop, string what, mixed val)
{
	mapping apply;

	apply = query_apply( troop, "");
	if( !apply || !mapp(apply) || !sizeof(apply) )apply = ([ ]);
	apply[what] = val;
	TROOP_D->set_troops(troop, "apply", apply);
}
void update_apply(int troop)
{
	mapping apply, tmp, one;
	object ob, *players;

	apply = query_apply(troop, "");
	tmp = ([ ]);
	if( !apply || !mapp(apply) || !sizeof(apply) )return;
	foreach(string tt in keys(apply)){
		one = apply[tt];
		one["time"] = one["time"] - 1;
		if( one["time"] != 0 )tmp[tt] = one;
		else {
			ob = TROOP_D->find_troop( troop );
			players = all_inventory( ob );
			tell( players, one["dis_msg"] );
		};
	};

	TROOP_D->set_troops(troop, "apply", tmp);
}
