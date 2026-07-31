// Room: /d/shaolin/fzjs1.c
// Date: YZC 96/01/19
// Date: cleansword 96/02/24

inherit ROOM;




void create()
{
	set("short", "茶室");
	set("long", @LONG
这里是方丈待客的地方，靠墙左右两侧摆着一溜太师椅。北面墙上挂了
一付对联。墙角一几，放着几个茶壶。有个茶壶壶身上题了“碧螺春”三个
篆字，壶嘴热气腾腾，似乎是刚沏的新茶。往北是方丈室。
LONG
	);

	set("exits", ([
		"north" : __DIR__"fzjs2",
		"down" : __DIR__"fzjs",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/qing-le" : 1,
	]));

	setup();
}

/*int valid_leave(object me, string dir)
{
	int skill;

	skill = me->query_skill("buddhism", 1);
	if (!wizardp(me) && skill < 30)
	{
		if (dir == "north" )
		{
			return notify_fail("你资格不够，不能进入方丈室。\n");
		}
	}
	return ::valid_leave(me, dir);
}
*/

