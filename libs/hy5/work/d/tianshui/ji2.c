// Room: /d/china/junying/xiaozhen/ji2.c

inherit ROOM;

void create()
{
	set("short", "回味轩");
	set("long", @LONG
这里就是回味轩。屋小幽雅，正中一张小几，几上
有琴，琴上无弦。旁边一圆凳，凳上鸳鸯垫。屋角木床
，床单上大红刺绣，绣的是一对鸳鸯戏水。墙角挂着一
幅小篆对联：
		焚琴煮鹤从来有，惜香怜玉几个知。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jiyuan2",
]));
	//set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int valid_leave(object me,string dir)
{
	object obj;
	if(dir == "east" || dir == "e")
	{
	if(me->query_temp("jiyuan/sleep") != "怜玉") return 1;
	call_out("zou_ren",1);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
	return 1;
	}

	return 1;
}

void zou_ren()
{
	object obj;

	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"幽怨的叹了一口气，走了。\n");
		destruct(obj);
		}
}