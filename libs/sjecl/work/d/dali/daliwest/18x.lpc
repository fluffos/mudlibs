// Room: /d/dali/18x.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "十八溪");
	set("long", @LONG
十八溪也溪溪有名，由北向南名为：霞移、万花、阳溪、茫涌、锦溪、灵
泉、白石、双鸳、隐仙、梅溪、桃溪、中溪、绿玉、龙溪、青碧、莫残、葶溟
和阳南。这些溪水，有的源于积雪，涓涓流淌；有的是天然泉水，飞瀑若雷。
它们流经大理坝子注入洱海。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
                "southwest" : "/d/tls/diancang",
	]));

	setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/18x",1);
      }
}
