/// troop.c

int load_my_chars(int t_id) {
	object tob,ob;
	string *chars;
	int i,sum;
	tob=SGTROOP(t_id);
	if(!objectp(tob)) return 0;

	chars=TROOP_D->get_troops(t_id,"chars");
	sum=sizeof(chars);
	for(i=0;i<sum;++i)
	{
		CHAR_D->put_char(chars[i],file_name(tob));
		ob=find_body(chars[i]);
		if(objectp(ob))
			ob->do_game_command("look");
	}
	return 1;
}

object virtual_create(string p_id)
{
	object o_troop;
	int t_id;
	t_id=to_int(p_id);
	if(!TROOP_D->troop_exist(t_id)) return 0;
	o_troop=new (M_TROOP);
	if(objectp(o_troop)) {
		o_troop->setup(t_id);
		call_out("load_my_chars",1,t_id);
	}
	return o_troop;
}
