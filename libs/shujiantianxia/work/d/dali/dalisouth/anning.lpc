// Room: /d/dali/anning.c
// bbb 1997/06/10 
// cool update 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "安宁温泉");
	set("long", @LONG
这里位于昆明西郊约八十里的螳螂川畔。这里山峦叠翠、森林茂密、空气
清新、自然环境优美，螳螂川江水绕泉而过。泉水质地优良，水温适当，含有
人体多种疾病较好疗效的各种微量元素，被誉为“天下第一汤”。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
          "west" : __DIR__"xgf",
	]));
        set("objects", ([
	      __DIR__"npc/caihuashe" : 1,
              __DIR__"npc/daxia" : 1,
              __DIR__"npc/dayetu" : 1,
	]));

	set("coor/x",-300);
  set("coor/y",-490);
   set("coor/z",-10);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/anning",1);
      }
}
