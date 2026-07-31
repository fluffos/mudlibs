// Room: /d/yandang/guanyin2.c

inherit ROOM;

void create()
{
	set("short", "第三层");
	set("long", @LONG
才上第三层,你就感受到上面飘洒下来的雨丝.抬头望,有一道泉水
从洞顶洒下,似珠似玉,在阳光照射下,五彩缤纷,正是天上人间,这就是
有名的淑玉泉了.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"guanyin1",
  "up" : __DIR__"guanyin3",
]));
	set("objects", ([ /* sizeof() == 1 */
  //__DIR__"npc/heshang2" : 1,
]));

	setup();

}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("jing ji",this_object());
if (objectp(ob)&&dir=="up")  {
  if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("净济拦住你:你好象不是我同帮弟兄吧?\n");
   }
 return ::valid_leave(me,dir);
}