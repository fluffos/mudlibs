// /d/zhuojun/yaopu.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "药铺");
	set("long", @LONG
这是一家远近闻名的药铺，全国各地的药材在这里面应有尽有，但
是价格却是非常昂贵，只有富贵人家和武林人士来此光顾，所以药铺显
得冷冷清清。
LONG
	);
set("exits", ([
                "west"  :__DIR__"nandajie1",
	]));
	set("objects",([
	__DIR__"npc/song":1,
	]));
       setup();
	replace_program(ROOM);
}	
