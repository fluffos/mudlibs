inherit ROOM;
void create()
{
        set("short", "南城门楼");
        set("long", @LONG
门楼呈方形，往下望是川流不息的人群，阳光下，流动的人群象微风中的彩带,
北方是平安城的中心，就是在这里也可以依稀的看到平安广场中心的纹龙柱。城中
的房屋连绵不断，索碎的小路象细小的银蛇，蜿蜒盘旋在灰色的房屋之间.
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swall1",
  "west" : __DIR__"swall11",
]));
        set("objects", ([
        __DIR__"npc/solider3" : 1,
                        ]) );
        set("outdoors", "pingan");
	setup();
        replace_program(ROOM);
}
	  void init() 
{         object me = this_player(); 
               me->query_temp("xunchen");
        if (me->query_temp("xunchen")) me->set_temp("xuncheng/supgate", 1);
         return;
 } 
