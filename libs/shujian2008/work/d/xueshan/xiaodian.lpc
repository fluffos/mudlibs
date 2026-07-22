// Room: xiaodian.c 湖边小店

inherit ROOM;

void create()
{
	set("short", "湖边小店");
	set("long", @LONG
这是一间简陋的土坯房，门口挂着块裂了几个口子的木招牌。屋中凌乱不堪，
东倒西歪地散落着几件破旧的桌椅，蒙着厚厚的灰尘，墙角结着个蜘蛛网。
LONG
	);

	set("exits", ([
		"north" : __DIR__"tianhu",
	]));
        set("objects", ([
         __DIR__"npc/wuchou1" : 1,
         __DIR__"npc/wuchou2" : 1,
         __DIR__"npc/wuchou3" : 1,
         __DIR__"npc/wuchou4" : 1,
         __DIR__"npc/wuchou5" : 1
       ]));
	set("coor/x",-250);
  set("coor/y",130);
   set("coor/z",0);
   setup();
}
