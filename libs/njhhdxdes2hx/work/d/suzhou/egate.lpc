//ROOM: d/suzhou/egate.c
// by dwolf
// 97.11.4

#include <ansi.h>
inherit ROOM; 

string look_gaoshi();

void create()
{
	set("short", MAG"东城门"NOR);
	set("long", @LONG
	  这是素来有天堂之称的苏州的东城门，城门正上方写有“东门”两个大字，
城墙上贴着一张告示(gaoshi)。官兵们戒备森严。一条笔直的青石板大道向东西两边
延伸。东边是郊外，骑马的，坐轿子的，行人匆匆。西边是城里。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"east" : __DIR__"szroad1",
		"up" : __DIR__"eclou",    
		"west" : __DIR__"eroad2",
]));   
	set("item_desc", ([
                "gaoshi" : (: look_gaoshi :),
        ]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
		 "/obj/npc/wujiang1"+random(3) : 1,
]));
	setup();
}

string look_gaoshi()
{
        return "为配合全国精神文明建设，请大家不要乱丢垃圾。\n\n\t\t    杨康\n";
}

void init()
{
        object me,guanchai;

        me = this_player();

        if( interactive(me) && me->query("pk_exp") > 0 && !me->query_temp("be_ki
lled"))
        {
        message_vision(HIR "突然间斜刺里冲出一个官差！\n\n" NOR, this_player());
        guanchai=new("/d/city/npc/guanchai");
        guanchai->move("/d/city/dongmen");
        write(RED"官差大喝道：你欺凌弱小，拿命来！\n"NOR);
        }


}

int valid_leave(object me, string dir)
{

        if( me->query("pk_exp") > 0 )
        {
                return notify_fail("你还没有对付官差，怎么离开这里？\n");
        }
        return ::valid_leave(me, dir);
}





