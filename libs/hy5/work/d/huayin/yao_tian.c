// yao_tian.c

inherit ROOM;

protected string m_name, m_id;
protected object yao_miao;
protected int last_time;

void do_refresh()
{
	m_name = 0; m_id = 0;
	if(objectp(yao_miao) && (environment(yao_miao) == this_object()))
		destruct(yao_miao);
	yao_miao = 0;
}

protected void check_valid()
{
	if( m_name || m_id || yao_miao )
	{
		if( (yao_miao && (environment(yao_miao) != this_object()))
		|| (m_id && !objectp(find_player(m_id)))
		|| (time() - last_time > 300) )
			do_refresh();
	}
}

void init()
{
	add_action("do_zai","zai");
	add_action("do_pour", "pour");
	add_action("do_shi", "shi");
	add_action("do_wa", "wa");
}

int do_zai(string arg)
{
	object me = this_player(), *inv, miao;

	if(m_name)
	{
		if(m_id == me->query("id"))
			return notify_fail("你已经在这里栽了一株药苗，等这株栽好再说吧。\n");
		return notify_fail(sprintf("%s正在这里栽种药苗，你换个地方吧。\n",m_name));
	}

	if(!arg || (arg == ""))
		return notify_fail("你要在这里栽种什么？\n");

	inv = filter_array(all_inventory(me), (: $1->id($(arg)) && $1->is_yao_miao() && !$1->is_success() :));

	if(!sizeof(inv))
		return notify_fail("你要在这里栽种什么？\n");

	miao = inv[0];
	miao->do_zai();
	miao->move(this_object());

	message_vision("$N小心翼翼的将身上的药苗栽在了田里。\n", me);

	m_name = me->name();
	m_id = me->query("id");
	yao_miao = miao;
	last_time = time();

	return 1;
}

int do_pour()
{
	object me = this_player(), *inv;

	if(!objectp(yao_miao) || (environment(yao_miao) != this_object()))
		do_refresh();

	if(!m_id)
		return notify_fail("这里没有什么需要浇水的东西。\n");

	if(m_id != me->query("id"))
		return notify_fail(sprintf("%s正在这里栽种药苗，你换个地方吧。\n",m_name));

	inv = filter_array(all_inventory(me), (: $1->is_shui_piao() && $1->is_full() :));

	if(!inv || !sizeof(inv))
		return notify_fail("你没有盛满水的水瓢怎么给药苗浇水。\n");

	inv[0]->do_pour();

	message_vision("$N拿起水瓢，小心翼翼的给药苗浇了一遍水。\n", me);

	yao_miao->accept_pour();
	return 1;
}

int do_shi()
{
	object me = this_player(), fei;

	if(!objectp(yao_miao) || (environment(yao_miao) != this_object()))
		do_refresh();

	if(!m_id)
		return notify_fail("这里没有什么需要施肥的东西。\n");

	if(m_id != me->query("id"))
		return notify_fail(sprintf("%s正在这里栽种药苗，你换个地方吧。\n",m_name));

	if(!objectp(fei = present("hua fei",me)))
		return notify_fail("你身上没有花肥。\n");

	if(!yao_miao->time_to_fei())
		return notify_fail("药苗的水还没有浇足，恐怕还不是施肥的时候。\n");

	message_vision("$N小心翼翼的将一块花肥施在了地里。\n",me);
	destruct(fei);

	yao_miao->do_fei();
	return 1;
}

int do_wa(string arg)
{
	object me = this_player();

	if(!objectp(yao_miao) || (environment(yao_miao) != this_object()))
		do_refresh();

	if(!m_id)
		return notify_fail("这里没有什么可挖的东西。\n");

	if(m_id != me->query("id"))
		return notify_fail(sprintf("%s正在这里栽种药苗，你换个地方吧。\n",m_name));

	if(!arg || !yao_miao->id(arg) )
		return notify_fail("你要挖什么东西？\n");

	if(!yao_miao->can_wa())
		return notify_fail("药苗还没有栽好。\n");

	message_vision("$N小心翼翼的将药苗挖了出来。\n", me);

	yao_miao->do_wa();

	yao_miao->move(me);

        do_refresh();
	return 1;
}

void reset()
{
	::reset();

	check_valid();
}
