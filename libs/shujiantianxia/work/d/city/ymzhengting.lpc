// Room: /d/city/ymdongting.c

inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
这里是衙门的正堂，堂上东西有两根楹住，挂着一幅对联，但是你无心细
看。正面墙上悬挂一个横匾，上书“正大光明”四个金光闪闪的大字。两旁衙
役们手持板子侧立两旁，朝廷刚派来的知府赵城之正坐在文案后批阅文书，师
爷随侍在后。
LONG
	);

	set("exits", ([
		"east" : __DIR__"dongting",
		"west" : __DIR__"xiting",
                "south" : __DIR__"menlang",
                "northwest" : __DIR__"fyhouyuan",
	]));
	set("objects", ([
		NPC_D("guanfu/zhaochengzhi") : 1,
        	__DIR__"npc/shiye" : 1,
        	__DIR__"npc/dayayi" : 1,
	]));
	set("incity",1);
	setup();
}
int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("da yayi", environment(me))) &&
                dir == "northwest")
                return notify_fail("“后院不得乱闯！”大衙役一把拦住了你。\n");
        return ::valid_leave(me, dir);
}
