// Room: /d/hainan/underhill2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "琼崖下");
  set ("long", @LONG
陡峭的山崖到这里突然拐了个弯,形成一个突出的凸角,在离你头顶 
不远的地方,有棵歪脖子小树从山壁上伸出来.看来有希望.头顶上白云悠 
悠飘过,你的心情好了起来. 
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/shuzhi.c" : 1,
]));
  set("outdoors", "/d/hainan");
  set("item_desc", ([ /* sizeof() == 1 */
  "小树" : "一棵歪脖子树,斜生在峭壁上.看来能从这爬(climb)上去.",
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"underhill",
  "southwest" : __DIR__"underhill3",
]));

  setup();
}
int init()
{
object ob;
ob=this_player();
	remove_call_out("greeting");
	call_out("greeting",1,ob);
add_action("do_climb","climb");
}
void greeting(object ob)
{
  if (!ob||environment(ob)!=this_object()) return;
  tell_object(ob,HIC"一根树枝从山壁上掉下来,打了你一下.\n"NOR);
  return;
}
int do_climb()
{object ob;
ob=this_player();
if( living(ob) ==0 ) return 1;
message_vision("$N小心翼翼地向树上爬去!\n",ob);
if (random(ob->query("dex"))>15)
this_player()->move(__DIR__"ontree.c");
else message_vision("只听噗通一声,$N四脚朝天跌倒在地上!\n",this_player());
return 1;

}
