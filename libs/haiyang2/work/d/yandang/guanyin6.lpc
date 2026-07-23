// Room: /d/yandang/guanyin6.c

inherit ROOM;

void create ()
{
  set ("short", "第七层");
  set ("long", @LONG
观音的第七层还是一间斋堂,每天早晚供应素斋,从此处向外面的岩
壁看,左面可见一指观音,当中可见侧面观音像,右面可见地藏王像.再向
外观,可见奇林林立.
LONG);

  set("objects", ([ /* sizeof() == 1 */
 // __DIR__"npc/heshang6" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin7",
  "down" : __DIR__"guanyin5",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("jue fei",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("觉非伸手拦住你.\n");
           }
return ::valid_leave(me,dir);
}