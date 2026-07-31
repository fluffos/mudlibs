// Room: /d/taiwan/chitang
inherit ROOM;

void create()
{
  set ("short", "池塘");
  set ("long", @LONG
推开摇晃的大门,你吃惊的发现眼前居然是个池塘,池中掉满了残枝
败叶,间中还有红色的鲤鱼游过.池塘上面还有一条小拱桥,通向里面.
LONG);

  set("outdoors", "/d/taiwan");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"huilang",
  "south" : __DIR__"zhuanyuan",
]));
  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string str)
{
   object ob;
   ob=this_player();
   if (!ob||environment(ob)!=this_object()) return notify_fail("");
   message_vision("$N噗通一声连衣跳入冰冷的池塘!\n",ob);
   ob->move(__DIR__"tangzhong");
   return 1;
}