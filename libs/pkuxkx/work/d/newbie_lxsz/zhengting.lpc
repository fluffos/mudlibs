// D:\xkx\d\liuxiu-shanzhuang\zhengting.c柳秀山庄正厅
// labaz  2012/10/22

#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void command_me(string);
int show_localmaps();

void create()
{
    set("short", "柳秀山庄正厅");
    set("long", @LONG
你走进此屋，并没有被风雅绰约的大厅所吸引。而是被端坐在大厅正
中央的那位英雄投去了敬佩的目光。他没有锦衣玉袍，喝的茶也只是普通
的碧螺春。样貌也不是鹤发童颜的世外高人模样。但他坐在那里垂目朝你
望来你就觉得这个人和这个山庄已经融为一体了，他有它的故事，它有他
的心事，能坐拥如此山庄的人，必然是胸怀抱负的英雄。曾经叱咤江湖的
辉煌不用多说，就在他的眼里，也在山庄里。
LONG);

    set("indoors","liuxiu-shanzhuang");

    set("exits", ([
        "west" : __DIR__"wxiangfang",
		"east" : __DIR__"exiangfang",
        "south" : __DIR__"yangui-huayuan",
		"north" : __DIR__"shangwutang",
        ])
     );

	set("objects", ([
		__DIR__"npc/youkunyi" : 1,
		__DIR__"npc/ashu" : 1,
	]));

    set("valid_startroom", 1);
    setup();
}

void init()
{
	object me,weapon;
	me=this_player();
    me->save();
    if (1==me->query("newbie_village/master") && !objectp(present("taiyi jian",me)))
    {
        weapon=new(__DIR__"weapon/taiyijian");
        if (1==me->query("newbie_village/pfm"))
            weapon->set("long", "这是一柄只有太乙学徒才能使用的长剑。\n"+HIC"目前你可以使用太乙剑法的绝招：八方风雨(perform sword.bafang)\n"NOR);
        weapon->move(me);
    }
	call_out("set_nextquest",1, me, "再次敲门(knock gate)，去见山庄庄主", "你怔怔地站在那里不知所措,不如去敲敲门，找里面的人问问", 20, 100);
	add_action("show_quest", "quest");
	add_action("show_localmaps","localmaps");

}

int show_localmaps()
{
	object me;
	me=this_player();

	call_out("set_nextquest",2, me, "使用localmaps命令查看票号的位置", "快去柳秀票号看看游鲲翼给你存了多少钱，都取出来吧", 20, 100);
}


void command_me(string arg)
{
	command(arg);
}

int valid_leave(object me, string dir)
{
    if (1==check_questindex(me,"使用localmaps命令查看票号的位置")) return notify_fail("你还是先用localmaps查下柳秀票号的位置再走吧。\n");
	if (me->query("id")!="a shu")
    {
		if (dir=="west" && me->query("gender")=="女性") return notify_fail("那是男子的厢房！\n");
		if (dir=="east" && me->query("gender")=="男性") return notify_fail("那是女子的厢房！\n");
	}
	return ::valid_leave(me, dir);
}
