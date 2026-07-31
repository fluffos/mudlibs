// Room: /d/fengtian/quest2.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
这里是土山环绕的一块长满蒿草的草地，草地上零星长着的
几棵小树上挂着几把锈蚀的破刀，来到这里禁不住会让人产生一
种阴森恐怖的感觉。西面山坡上有一个小土洞。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"quest1",
  "enter" : __DIR__"quest3",
]));

	//

	set("objects",([
	__DIR__"npc/laozhe" : 1,
]));

	setup();
}

int valid_leave(object me,string dir)
{
	object ob;

	if( userp(me)
	&& (dir == "enter")
	&& objectp(ob = present("old man",this_object())) )
	{
		if(!me->query_temp("feiyu_upgrade_quest/ask_oldman"))
			return notify_fail(sprintf("%s拦住你问道：“你来这有什么事情吗？”\n",ob->name()));
		ob->set_leader(me);
		return 1;
	}
	return ::valid_leave(me,dir);
}
