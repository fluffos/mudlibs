inherit ROOM;
void create()
{
	set("short", "立春堂");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个
小抽屉里散发出来的。药房先生坐在茶几旁，独自喝着茶，看也不看你一眼。
一名小伙计站在柜台后招呼着顾客。
LONG
	);
        set("objects",([
           __DIR__"npc/laoban" : 1,
           __DIR__"npc/huoji" : 1,
         ]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));
	set("coor/x",150);
  set("coor/y",-200);
   set("coor/z",0);
   set("incity",1);
	setup();
}

