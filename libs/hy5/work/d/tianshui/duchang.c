// /d/tianshui/duchang.c

inherit ROOM;

void create()
{
        set("short", "天水赌馆");
        set("long", @LONG
这里就是远近闻名的天水赌馆。里面此起彼伏的叫喊声，银
子、元宝叮叮当当的碰撞声使你也不禁血液沸腾起来，真想也赌
(bet)他几把试试运气。门边的牌子(paizi)写着这里的赌规。旁
边有楼梯通向二楼。
LONG
        );

        set("exits", ([
                "west" : __DIR__"nroad2",
		  "up" : __DIR__"duchang2"
                     ]));
	set("objects",([
	__DIR__"npc/judge" : 1,
]));
        
        setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "up")
		return notify_fail("通往楼上的门紧锁着，不时传出几声隐约的叫喊声，楼上好象也在赌钱。\n");
	return ::valid_leave(me,dir);
}
