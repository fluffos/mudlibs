// 大石谷，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
string look_tao();
void create()
{
	set("short", HIM"桃花亭"+NOR);
	set("long", @LONG
桃花亭里观桃花，坐在这里正好可以看见谷里盛开的桃花。地上散落着几只
桃子(taozi)。
LONG
	);
        set("outdoors", "dashigu");
	set("item_desc",(["taozi":(:look_tao:)]));
	set("exits", ([
		"southeast" : __DIR__"wanshi",
		//"northdown" : __DIR__"jingshui",
		//"northwest" : __DIR__"taohua",
		//"eastdown" : __DIR__"xiaoxic",
	]));
	set("stay_time",1);
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"obj/tao" : 2,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
string look_tao()
{
	object tao;
	if (!tao=present("tao zi",this_object()))
	return "可惜这些桃子全都烂掉了。\n";
	if (!tao->query("dashigu_tao"))
	return "可惜这些桃子全都烂掉了。\n";
	return "这些桃子看起来鲜嫩多汁，让人垂涎欲滴。\n";
}
void init()
{
	object me=this_player();
	me->set_temp("xitianmu/xiaoxi_stay",time());
	if (me->query("tianmuQuests/dashigu/gather"))
	{
		me->set("startroom", base_name(this_object()));
		me->set_temp("revive_room",base_name(this_object()));
	}
}
int valid_leave(object me,string dir)
{
	if (member_array(dir,keys(query("exits")))!=-1&&
	time()-me->query_temp("xitianmu/xiaoxi_stay")<query("stay_time"))
	return notify_fail("你观赏着"+query("short")+NOR+"风光，一步一步慢慢前行。\n");
	return ::valid_leave(me,dir);
}