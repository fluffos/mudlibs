// Room: /d/shaolin/wuchang2.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。练武场中间
竖立着不少草靶。十来个僧人正在练习武艺。西面有一长溜僧房。
LONG
	);

	set("exits", ([
		"south" : __DIR__"zoulang3",
		"west" : __DIR__"wuchang",
		"east" : __DIR__"luohan5",
		"north" : __DIR__"zoulang7",
//                 "up" : __DIR__"wuchangg2",
	]));

	set("objects",([
                   __DIR__"npc/mu-ren" : 2 ]));

	set("outdoors", "shaolin");
	setup();
}



int valid_leave(object me, string dir)
{
        int i;
        object* inv;
        
        inv = deep_inventory(this_player());
        if (dir == "up")
        {
                if (this_player()->query("combat_exp")<5000000)
                        return notify_fail("上面是专供武林绝顶高手练功的场所，你武功不够，不能进去!\n");
                for(i=sizeof(inv)-1; i>=0; i--)
                        if (userp(inv[i]))
                                return notify_fail("你不能背个人进去！\n");
        }
        return ::valid_leave(me, dir);
}

