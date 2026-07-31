// Room: /huanghe/shulin1.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶而从茂
密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身後传来野
兽的啸声使人不觉犹豫了前进的脚步。林中立着一块牌子。
LONG );
	set("exits", ([
		"west"  : __DIR__"shulin2",
		"east"  : __DIR__"caodi2",
		"north" : __DIR__"shulin3",
	]));
	set("item_desc", ([
		"【牌子】" : HIR"\n非黄河帮众者    擅入格杀勿论"NOR"\n",
	]));
	set("objects", ([
		"/clone/beast/dushe" : 1,
		"/d/hangzhou/obj/shuzhi" : 1,
	]));

	set("resource/snake", ({ "/clone/beast/dushe",
				 "/clone/beast/fushe",
				 "/clone/beast/wubushe", }));

	set("outdoors", "huanghe");
	setup();
}
