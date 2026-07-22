// Room: /d/dali/xs1.c
// bbb 1997/06/10 
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "西山森林");
	set("long", @LONG
这里位于大大小小的峰峦间。主要由华亭寺、太华寺、三清阁、龙门等风
景点组成。华亭寺位于海拔2050米的山间，创建于14世纪，寺内殿宇规模宏伟
壮观，是昆明著名的佛教圣地。太华寺建于14世纪初，花木繁盛，幽香袭人。
LONG
	);
        set("outdoors", "大理");
	set("exits", ([
           "northwest" : __DIR__"shanlu7",
           "south" : __DIR__"lunan",
	   "north" : __DIR__"xs2",
	]));
        set("objects", ([
	     __DIR__"npc/yetu" : 1,
             __DIR__"npc/songshu" : 1,
	]));

	set("coor/x",-260);
  set("coor/y",-430);
   set("coor/z",-20);
   setup();
}
