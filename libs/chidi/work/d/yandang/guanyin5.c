// Room: /d/yandang/guanyin5.c

inherit ROOM;

void create ()
{
  set ("short", "第六层");
  set ("long", @LONG
上到第六层,你赫然发现此处是一个禅房,观音洞中的僧人平时就住
在这,朝暮晨钟,苦守青灯,除了几张卧榻之外就一无所有,房中柱子上挂
着的一盏油灯兀自吐着点点火苗.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/heshang5.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin6",
  "down" : __DIR__"guanyin4",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("guan zheng",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("观证伸手拦住你.\n");
           }
return ::valid_leave(me,dir);
}
