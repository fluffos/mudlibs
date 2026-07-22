// Room: /d/yandang/luoyan40
inherit ROOM;

void create ()
{
  set ("short", "炼功室");
  set ("long", @LONG
炼功室是专门供庄内弟子锻炼武功的地方,这里有专门的师傅给以
指点,有功力相当的弟子相同炼功,别派的人士,这是恕不接待了,而观看
别人炼功更是武林大忌.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guoxiaot.c" : 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"luoyan41",
  "south" : __DIR__"luoyan42",
  "west" : __DIR__"luoyan43",
  "north" : __DIR__"luoyan23",
]));

  setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	seteuid(geteuid(me));
ob = present("guo xiaotian");
if(!ob) return 1;
if (((dir=="east")&&(me->query_temp("agree")!=1))
    ||((dir=="south")&&(me->query_temp("agree")!=2))
    ||((dir=="west")&&(me->query_temp("agree")!=3))) 
 {message_vision("$N拦住$n道:你不适合进哪个房间!\n",ob,me);
  return notify_fail("");}
return 1;
} 

