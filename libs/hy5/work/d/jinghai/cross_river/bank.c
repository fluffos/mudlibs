// Cross_river: bank.c
// by Find.

inherit ROOM;

protected string bfile;
protected int max_passenger = 6;
protected object boat;
protected string yell_msg = "$N扯着嗓子喊道：“船家！！我要过河！！”\n";

// 接口函数
protected void set_boat_file(string file)
{
	if(!stringp(file) || !strlen(file))
		return;

	bfile = file;
}

protected void set_max_passenger(int n)
{
	if(n > 0)
		max_passenger = n;
}

protected void set_yell_msg(string msg)
{
	if(!stringp(msg) || !strlen(msg))
		return;

	yell_msg = msg;
}
// 结束

protected int check_boat()
{
	if(!objectp(boat = find_object(bfile)) && !objectp(boat = load_object(bfile)) )
		return notify_fail("无法载入移动体，请找管理员处理。\n");
	return 1;
}

void init()
{
	add_action("do_yell", "yell");
}

int do_yell(string arg)
{
	object me = this_player();

	// 参数检查
	if(arg != "船家" && arg != "boat")
	{
		message_vision("$N扯着脖子喊了一嗓子，也不知道喊的是什么。\n",me);
		return 1;
	}

	if(me->query_temp("yell_boat"))
		return notify_fail("你已经喊过船了，耐心等一会儿吧。\n");

	if(!boat && !check_boat())
		return 0;

	me->set_temp("yell_boat", 1);

	if(find_call_out("yell_boat") == -1)
		call_out("yell_boat", 2);

	message_vision(yell_msg, me);
	return 1;
}

protected void yell_boat()
{
	boat->reply_yell(this_object());
}

// 可被重载灵活改变摆渡的条件
protected int valid_passenger(object who)
{
	if(!who)
		return 0;

	if( !who->query_temp("payed_duchuan") )
		return notify_fail("\n请先交钱后上船。\n");

	return 1;
}

int valid_leave(object me,string dir)
{
	if(!userp(me))
		return 1;

	me->delete_temp("yell_boat", 1);

	if(!boat && !check_boat())
		return notify_fail("此地渡船出现错误，请找管理员处理。\n");

	if(dir == "enter")
	{
		if(!boat && !check_boat())
			return notify_fail("此地渡船出现错误，请找管理员处理。\n");

		if( sizeof(filter_array(all_inventory(boat),(: userp :) )) >= max_passenger )
			return notify_fail("船上已经再也坐不下了，等下一趟吧。\n");

		if(!valid_passenger(me))
			return 0;
	}

	return 1;
}
