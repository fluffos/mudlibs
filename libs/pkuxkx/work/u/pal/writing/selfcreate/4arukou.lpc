//mjth 2003/10/7

inherit ROOM;

void create()
{
	set("short","风景区入口");
	set("long", @LONG
这里就是4A级世界风景区的入口。只见来往游客奔流不息。向南往去，
依稀可以感受到一股超尘脱俗自然的召唤。耳边小贩的叫卖声络绎不绝。
哇，一个ppmm 出现了！哇，一个盖世帅哥跑过来了！哇，一个天地英雄
开始签名了！yi 。。。 是谁说自己的钱袋被偷了？你不由紧紧按着钱
包，显出一副此地无银三百两的样子。
LONG
	);
	set("no_sleep_room",1);
	set("outdoor","city");
	set("exits",([
		"south" : __DIR__"center",
	]));
	setup();
	replace_program(ROOM);
}