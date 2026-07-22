// Room: /qian.c
// bbb 1997/06/11
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "大理钱庄");
	set("long", @LONG
这家钱庄据说是来自中原的一位退位高官所开办，在全国各地开了不少分
店。因为谣言，曾经有过一次挤兑风潮，钱庄一一兑付，不欠分毫。如今名气
大震，发行的银票通行全国。
LONG
	);

	set("exits", ([
                "south" : __DIR__"beijie4",
	]));

	set("objects", ([
		__DIR__"npc/qian" : 1
	]));

	set("coor/x",-300);
  set("coor/y",-370);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-370);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/qian",1);
      }
}
