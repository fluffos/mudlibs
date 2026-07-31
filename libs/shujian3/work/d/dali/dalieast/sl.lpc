// Room: /d/dali/sl.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "石林");
	set("long", @LONG
主要包括大石林、乃古石林、大叠水瀑布、芝云洞、奇风洞、长湖、月湖
等七个景区。景区内石峰林立、万峰迭嶂，千姿百态的石峰、石柱、石花石坪、
石流----犹如一片莽壮黝黑的森林，被誉为“天下第一奇观”。石林奇观世所
罕见，它以宏大奇伟的喀斯特地貌向世人展现了其独特的风采。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
          "west" : __DIR__"lunan",
	]));

	set("coor/x",-250);
  set("coor/y",-440);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/sl",1);
      }
}
