// /guanwai/damenkan.c

inherit ROOM;

void create()
{
	set("short", "大门坎子");
	set("long", @LONG
这里是沿江向东的古道，多为进山采参的参客所走，因此也称“参路”
。前面一座小山截断去路，因其行似门坎，且为东去采参的第一道屏障，故
被称为大门坎子。西面是宽阔的松花江。松花江在冬春时结冰可通行，夏秋
化冻你只好找船家帮忙了。
LONG );
	set("exits", ([
		"northeast"  : __DIR__"ermenkan",
		"west"       : __DIR__"bingmian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	string chn_month;
	object obj, *ob;
        int i,j;

	if (dir=="west")
	{
		chn_month = CHINESE_D->chinese_month((time()-890000000)*60);
		if (chn_month=="十二" || chn_month=="一" || chn_month=="二" ||
		 chn_month=="三" || chn_month=="四" || chn_month=="五")
		{
			message_vision("$N见江面结冻，便壮起胆子踩冰而过。\n\n", me);
			if (random(me->query_dex())<20)
			{
				me->receive_wound("qi",20);
				me->receive_damage("qi",20);
			message_vision(chn_month+"$N只觉得脚下一滑，全身腾空而起，结结实实的摔在了冰面上！\n", me);
			}
			return 1;
		}
		else
		{
			j = 0;
			ob = all_inventory(environment(me));
			for(i=0; i<sizeof(ob); i++)
			{
				if ( (!userp(ob[i])) && (ob[i]->query("id")=="chuan fu"))
					j = 1;
			}
			if (j == 0)
			{
				obj = new(__DIR__"npc/chuanfu1");
				obj -> move(environment(me));
			message_vision("坎后走出一个船夫，站在边上瞪着眼看着$N。", me);
			}
			else
			message_vision("船夫在旁边拿眼瞪着$N看。", me);
			return notify_fail("冰面化冻，还是乘船吧！\n");
		}
	}
	return 1;
}

