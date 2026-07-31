// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIR"朱府大门"NOR"");
	set("long", @LONG
这里是朱府的大门，红漆漆的大门尽显豪气。
LONG
	);
	set("exits", ([
		"north" : __DIR__"room0",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	string fb_id;
	int i;
	object *team = me->query_team();
	if (userp(me) && dir == "out") {
		me->delete_temp("zxt_again");
		if (fb_id = me->query_temp("fuben_path"))
			FUBEN_D->des_fuben(fb_id, 1);
	}
		if (userp(me))
		{
		if (dir == "north") {
	for (i = 0;i < sizeof(team);i ++)
	{
    team[i]->delete_temp("xi");
    team[i]->delete_temp("dong");
    tell_object(team[i],"你来到了朱府！"NOR"\n");
	}
			}
		}
	return ::valid_leave(me, dir);
}

