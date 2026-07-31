// Room: /d/huayin/minju1.c

inherit ROOM;

int is_hy_drying_room() { return 1; }

void create()
{
	set("short", "烘干房");
	set("long", @LONG
这是一间不大的土坯房，左面靠墙堆着不少粗大的原木，右
面是两个大土坯炉子，透过炉门的缝隙可以看到里面红红的火苗，
一进到这里就立刻被干燥的热浪包围了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"minju",
]));

	setup();
}

void init()
{
	object ob = this_player();

	if(objectp(ob) && !wizardp(ob))
	{
		ob->delete_temp("valid_enter_drying_room");
		call_out("force_leave",90,ob);
	}
}

protected void force_leave(object who)
{
	if(!objectp(who) || (environment(who) != this_object()))
		return;

	tell_object(who,"老赵冲进来朝你嚷道：我说你这么长时间不出来，还让不让我们做生意啦！\n老赵一把把你拽了出去。\n");
	who->move(__DIR__"minju");

	tell_room(__DIR__"minju",sprintf("老赵把%s从烘干房拽了出来。\n",who->name()));
}
