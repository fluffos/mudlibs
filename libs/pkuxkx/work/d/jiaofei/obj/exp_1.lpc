inherit ITEM;

void create()
{
	set_name("涨经验",({"exp"}));
	set("long","这是一个读了(read)可以涨经验的宝物\r\n");
	set("value",1);
	set("reward",1);
	set("no_give",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_get",1);
	set("unit","个");
	setup();
}

void init()
{
	add_action("do_look","look");
	add_action("do_read","read");
}

int do_look(string arg)
{
	if(arg == query("id"))
	{
		write(query("long")+sprintf("它可以提升%d点经验值。\r\n",query("reward")));
		return 1;
	}
	return 0;
}

int do_read(string arg)
{
	if(arg == query("id") && environment() == this_player())
	{
		write(sprintf("你的经验提升了%d点！\r\n",query("reward")));
		this_player()->add("combat_exp",query("reward"));
		write(query("name")+"化作灰烬了\r\n");
		destruct(this_object());
		return 1;
	}
	return 0;
}