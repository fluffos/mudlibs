// Room: /d/heimuya/basket.c
inherit ROOM;
void create()
{
	set("short", "掉蓝");
	set("long", @LONG
这是一个掉蓝，是用来上下黑木崖的工具。
LONG
	);
	set("outdoors", "heimuya");
	setup();
}
int do_check()
{
	object *obj;
	int	i;
	obj=all_inventory(this_object());
	if (!sizeof(obj))	return 1;
	for (i=0;i<sizeof(obj);i++)
		if (userp(obj[i]))	return 0;
	return 1;
}
