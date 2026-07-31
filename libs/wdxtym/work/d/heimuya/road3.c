// road3.c
inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("channel_id", "倚天屠龙");
	set("long", @LONG
你走在一条黄土路上。西面望去，隐隐可以看到平定州。望
东，北京城快到了。
LONG );
	set("outdoors", "heimuya");
	set("exits", ([
		"north" : "/d/tulong/yitian/road3",
		"east" : "/d/beijing/ximenwai",
		"west" : __DIR__"pingdingzhou",
	]));

	setup();
}

int start_yitian()
{
	shout(HIR "\n【倚天屠龙】" NOR+WHT "赵敏冷哼几声，露出不屑的眼神。" NOR );
	shout(HIR "\n【倚天屠龙】" NOR+WHT "赵敏：不错！倚天剑就在我手中，有本事就尽管到万安寺中来拿。"NOR"\n" );
	CHANNEL_D->do_channel(this_object(), "chat", "赵敏一众携带倚天剑出现在万安寺，倚天剑剧情启动。");
	set("open",1);
	call_out("clear_yitian",1800);
	return 1;
}

int clear_yitian()
{
	mixed *files;
	string file;
	object *inv,room;
	int i,j;

	files = list_dirs("/d/tulong/yitian/");
	for(i=0;i<sizeof(files);i++)
	{
		file = "/d/tulong/yitian/"+files[i];
		if(file_size(file))
		{
			room = find_object(file);
			if(room)
			{
				inv = all_inventory(room);
				if(sizeof(inv))
				{
					for(j=0;j<sizeof(inv);j++)
					{
						if(playerp(inv[j]))
						{
							tell_object(inv[j],"你被强行离开了万安寺！\n");
							inv[j]->move("/d/heimuya/road3");
						}
					}
				}
			}
		}
	}
	this_object()->delete("open");
	CHANNEL_D->do_channel(this_object(), "chat", "倚天剑剧情已结束。");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (dir=="north"&&!this_object()->query("open"))
		return notify_fail("万安寺已关闭，开放时间每日晚上9:30-10:00。\n");
      if (dir=="north"&& me->query("combat_exp", 1)<1000000 )
		return notify_fail("你这么点低微的武功恐怕无法从赵敏手中抢回倚天剑吧？\n");
	//if (dir=="north"&&!wizardp(me))
	//	return notify_fail("测试中，暂时不能进入。\n");
	return 1;
}
