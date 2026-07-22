// Room: /d/yandang/guanyin4.c

inherit ROOM;

void create ()
{
  set ("short", "第五层");
  set ("long", @LONG
第五层景色奇瑰,首先进入你眼帘的是从釜形洞顶石缝中涓涓下滴
的水珠,似一幅悬挂着的珠帘,这就是石釜泉了.仰望洞顶,中开一小豁,
有一线天光泻下,名一线天.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/heshang4.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin5",
  "down" : __DIR__"guanyin3",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("hui ming",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("晦明伸手拦住你.\n");
           }
return ::valid_leave(me,dir);
}