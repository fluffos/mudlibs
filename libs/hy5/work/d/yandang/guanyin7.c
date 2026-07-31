// Room: /d/yandang/guanyin7
inherit ROOM;

void create ()
{
  set ("short", "第八层");
  set ("long", @LONG
第八层供奉的是药师佛,据说这位神佛保佑身体安康,合家平安,所
以来上香的还是很多,佛像前的大香炉插满了香,发出缕缕的青烟,整个
大殿也就笼罩在一股神秘的气氛中.
LONG);

  set("objects", ([ /* sizeof() == 1 */
//__DIR__"npc/heshang7.c":1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin8",
  "down" : __DIR__"guanyin6",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("da bei",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("大悲伸手拦住你.\n");
           }
return ::valid_leave(me,dir);
}
