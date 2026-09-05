// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include <ansi.h>
#include "/d/hangzhou/to_song.h"
void create()
{
	set("short", "和宁门瓮城");
	set("long", @LONG
这里是和宁门的瓮城，也是殿前司和四卫指挥使司的驻地。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"northeast" : __DIR__"yuchu",
		//"southeast" : __DIR__"yujiu",
		"south" : __DIR__"xueshiyuan",
		//"northwest" : __DIR__"yuyao",
		//"southwest" : __DIR__"zaozuo",
		"north" : "/d/hangzhou/heningmen",
	]));
	set("dirs_to_song",(["enter":({"dianqiansi","里","殿前都禁军驻地"}),"northwest":({"pengri","西北","捧日卫指挥使司"}),"southwest":({"tianwu","西南","天武卫指挥使司"}),"northeast":({"long","东北","龙卫指挥使司"}),"southeast":({"shen","东南","神卫指挥使司"})]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    "/d/hangzhou/npc/songbing_y" : 2,
        ]));
	set("WAICHAO",1);
	set("ZHUDI",1);
	setup();
	make_entrance();
}
int dest(object army)
{
	if (army)
	destruct(army);
	return 1;
}
int check_army(object me)
{
	object army=me->query_temp("ARMY");
	if (!army)
	{
		if (me->query_temp("songtasks/dianqian/diaobing"))
		{
			tell_object(me,"你的皇城巡逻任务失败了。\n");
			return 1;
		}
		return 1;
	}
	if (me->query_temp("songtasks/dianqian/3/finish"))
	return 1;
	if (!me->query_temp("songtasks/dianqian/place_escort"))
	return 1;
	if (sizeof(me->query_temp("songtasks/dianqian/place_escort"))<7)
	{
		tell_object(me,"你的皇城巡逻还有一些地方尚未完成。\n");
		return 1;
	}
	if (!me->query_temp("songtasks/dianqian/tingzhu"))
	{
		tell_object(me,"你没有在该停驻的地方停驻。\n");
		return 1;
	}
	if (!me->query_temp("songtasks/dianqian/jixing"))
	{
		tell_object(me,"你没有在该疾行的地方疾行。\n");
		return 1;
	}
	me->set_temp("songtasks/dianqian/3/finish",1);
	tell_object(me,"你完成了皇城巡逻，可以回殿前司复命了。\n");
	DASONG_D->multi_record(me,1,"宫城巡防",2);
	call_out("dest",1,army);
	return 1;
}
