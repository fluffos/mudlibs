// Room: /d/yandang/guanyin3.c

inherit ROOM;

void create ()
{
  set ("short", "第四层");
  set ("long", @LONG
来到第四层,令你惊奇的是此处有一个的水池,池水碧绿,水中的鱼
儿正欢敞地嘻戏,这是佛门放生池.每年二月二,此处方丈还专门主持放
生,功德无量.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/heshang3.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanyin4",
  "down" : __DIR__"guanyin2",
]));

  setup();
}
int valid_leave(object me,string dir)
{
  object ob;
  ob=present("cheng guan",this_object());
 if (objectp(ob)&&dir=="up")   {
   if (ob->query("banghui")!=me->query("banghui"))
  return notify_fail("澄观伸手拦住你.\n");
           }
return ::valid_leave(me,dir);
}
