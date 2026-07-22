// Room: /d/hainan/pubu
inherit ROOM;
void create()
{
  set ("short", "瀑布");
  set ("long", @LONG
瀑布宛如一条巨龙从天而降,冲入你脚下的一个深渊,发出隆窿的
巨声,把你脚下的土地震得发抖.丝丝水花被风吹来,飘拂在你身上,远
处的山川变得分外清晰起来!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"road5",
  "west" : __DIR__"road4",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "瀑布" : "你仔细观察瀑布,似乎在它后面发现些什么,但水势太大,你实在
看不清楚.
",
]));
  set("outdoors", "/d/hainan");
  setup();
}
void init()
{
   add_action("do_jump","jump");
}
int do_jump(string str)
{
    if (str!="瀑布"&&str!="pubu")  return 0;
message_vision("$N用力一蹬腿向瀑布蹿去!\n",this_player());
tell_room("/d/hainan/pubuhou",this_player()->query("name")+"从外面蹿了进来!\n");
this_player()->move("/d/hainan/pubuhou");
tell_object(this_player(),"你蹿入瀑布,脚下被一根长长的红色锁链绊了一下!\n");
return 1;
}
