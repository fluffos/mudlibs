// Room: /d/dali/chaguan.c
// bbb 1997/06/11
inherit ROOM;

void create()
{
        set("short", "茶馆");
	set("long", @LONG
一走进来，你就闻到一股清清的茶香，茶馆一角放着好多坛子，全装满了
茶叶，有几个客人正在那细细的挑选茶叶。茶博士一脸微笑，招呼着在座的客
人，各色客人坐满了周围，却也没有几分喧闹。
LONG
	);
	set("resource/water", 1);

	set("exits", ([
              "east" : __DIR__"beijie1",
	]));

	set("objects", ([
                    __DIR__"npc/chabox" : 1,
                    __DIR__"npc/chake" : 1,
                    "/clone/npc/yinggu" :1,
	]));

	set("coor/x",-340);
  set("coor/y",-380);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/chaguan",1);
      }
}
