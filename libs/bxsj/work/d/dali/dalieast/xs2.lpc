// Room: /d/dali/xs2.c
// bbb 1997/06/10 
// cool 98.3.17
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "望海楼");
	set("long", @LONG
这里是观在滇池日出的好地方。三清阁和龙门是一组构建在西山主峰罗汉
山悬崖峭壁上的建筑群，有九层十一阁。龙门石雕工程，包括石道、古室古栏、
古窟、古佛等，是西山胜境的精华所在。登上龙门，凭栏下视，为百丈之悬崖
峭壁。举目远望，海天一色，五百里滇池尽收眼底。
LONG
	);
        set("outdoors", "大理");

	set("exits", ([
            "south" : __DIR__"xs1",
	]));

	set("coor/x",-260);
  set("coor/y",-420);
   set("coor/z",-20);
   setup();
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
       me->set_temp("dali_xc/xs2",1);
      }
}
