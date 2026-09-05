// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "东天门");
	set("long", @LONG
这里是岱顶的东面出口。往东依次经过伏虎门峡口、鹰愁涧等，
便可下山。
LONG
	);

	set("exits", ([
		"west" : __DIR__"tanhai",
             "northup" : __DIR__"fefe8",
	]));

set("objects",(["/d/taishan/npc/xiaomao":1,]));
	set("outdoors", "taishan");
	setup();

}

  int valid_leave(object me,string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if ((dir=="northup") && objectp(present("xiao mao",environment(me)))
    && living(present("xiao mao",environment(me))))
        return notify_fail("小毛拦住你说道：这是我的家，爸爸说不能给陌生人进去的，
        你还是马上离开吧！\n");
    return::valid_leave(me,dir);
}
