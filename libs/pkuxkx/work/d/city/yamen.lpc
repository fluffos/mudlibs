// Room: /city/yamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "衙门大门");
	set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。「肃静」「回避」的牌子分放
两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几名衙役在门前
巡逻。
LONG);

	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"ymzhengting",
		"west" : "/d/marry/yamen-datang",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

	if( dir != "north" || me->query("class") == "officer" )
		return ::valid_leave(me, dir);
	ob = all_inventory( environment( me ));
	for(i=0; i<sizeof(ob); i++) 
		if( living(ob[i]) && ob[i]->query("id") == "ya yi" )
			return notify_fail("衙役喝道：「威……武……」\n");
	return ::valid_leave(me, dir);
}