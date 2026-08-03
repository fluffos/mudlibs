// gate.h
// by augx@sj  3/27/2002

void setup_var()
{
	if( query("indoors") ) {
		set("hp",1300);
		set("max_hp",1300);
	}
	else {
		set("hp",800);
		set("max_hp",800);
	}
	set("attack",0);
	set("no_save",1);
}

int valid_leave(object me, string dir)
{
	object door = present("shi men");
	string str;

	if( !door || door->query("open") || door->query("broken") ) return 1;
	if( !(str=query("exits/"+dir)) || strlen(str)<15 || str[0..14]=="/d/group/entry/" || str[0..8]!="/d/group/" ) return 1;
	if( me->query("group/id") == query("group1") ) {
		message_vision("$N敲了敲门，里面有人打开一扇小门，让$N进去了。\n",me);
		return 1;
	}

	return notify_fail("大门已经关上了，你必须打开大门才能进去。\n");
}

void reset()
{
	if( present("shi men") ) return;
	::reset();
}

void set_attack(object me)
{
	if( !query("attack")
	 || !me
	 || !me->query("group/id")
	 || query("group1")==GROUP_D->query_league(me->query("group/id"))
	 || time()>=query("attack")
	 || me->query_temp("group/attacking") )
	 	return;
	GROUP_D->attacking(me,query("attack")-time(),query("attack_type"));
}

void init()
{
	if( userp(this_player()) )
		set_attack(this_player());
}
