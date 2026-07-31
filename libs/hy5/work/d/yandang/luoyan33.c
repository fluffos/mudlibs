// Room: /d/yandang/luoyan33
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "中折瀑");
  set ("long", @LONG
瀑布从百多米的半圆形洞顶凌空而下,纷纷扬扬的如万槲银珠洒落
潭中,潭面发出一阵阵叮叮咚咚的天籁之声,在墨黑色的里壁上,散落地
点缀着丛丛绿草.潭中似乎有东西在闪光.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhuyoumu.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("item_desc", ([ /* sizeof() == 1 */
  "潭" : "你仔细看了看,似乎是块小石子,不知能不能捞(lao)起来.
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "southup" : __DIR__"luoyan32",
]));

  setup();
}
void init()
{
	add_action("do_lao", "lao");
}
do_lao(string arg)
{
	object me,ob;
	me = this_player();
      if ((!arg)||(arg!="小石子")) return notify_fail("你要捞什么?\n");
      me=this_player();
      if (me->query("kar")>23)
{  message_vision("$N从水潭中捞出一块白色晶石.\n",me);
   ob=new(__DIR__"obj/stone")->move(me);
message("channel:rumor",YEL"【谣言】"+ "某人："+me->query("name")+"从水潭中捞到一块晶石。\n"NOR,users());
me->set("kar",me->query("kar")-1);
        return 1;
    }
else message_vision("$N捞了半天,什么都没捞到.\n",me);
return 1;
}
