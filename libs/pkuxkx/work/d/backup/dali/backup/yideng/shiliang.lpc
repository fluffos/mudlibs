//石梁
//by icer
inherit ROOM;
void create()
{
        set("short", "石梁");        set("long", @LONG
延着小路向前走去，行不多时，山路就到了尽头，前面是一条宽约尺许的石梁，
横架在两座山峰之间，云雾笼罩。石梁尽头有一个极长的缺口，看来总在一丈开外，
缺口彼端盘膝坐着一个书生，正自朗诵。
LONG
);
set("exits", ([
                "down" :__DIR__"banshan2",
]));
set("objects",([

      __DIR__"npc/du" : 1,
     ]));
setup();
}

void init()
{
	add_action("do_jump","jump");
}
int do_jump()
{
	if ((int)this_player()->query_skill("dodge",1)>150)
	{
	    if (this_player()->query_temp("marks/读2"))
	    {
		write("你提气一跃，过了那个缺口，在那书生先前坐处稳稳落住。那书生将你引到一处庙内。\n");
		this_player()->move(__DIR__"xiangfang");
		return 1;
	    }
	    else {
			return notify_fail("如要跳过缺口，只能在书生坐的地方落脚。这可如何是好？\n");
		}
	}
	else
	{
		write("你的轻功好象不足以跳过这个缺口，你再好好考虑一下，跳还是不跳？(y/n)\n");
		input_to("consider_jump",this_player());
		return 1;
	}
}

void consider_jump(string arg,object me)
{
	int dodge_skill;

	if (arg == "y" || arg == "Y")
	{
		dodge_skill = me->query("dodge",1);
		if (random( dodge_skill - 50)>(149 - dodge_skill))
		{
			write("你提气一跃，过了那个缺口，在那书生先前坐处稳稳落住。那书生将你引到一处庙内。\n");
			this_player()->move(__DIR__"xiangfang");
			return;
		}
		else
		{
			write("一阵山风吹来，你脚下一个不稳，跌进了无底深渊之中......\n");
            this_player()->delete_temp("last_damage_from");
            this_player()->set_temp("death_msg", "跌进无底深渊");
			this_player()->die();
			return;
		}
	}
	write("这就对了，还是小心点为好。\n");
	return;
}


