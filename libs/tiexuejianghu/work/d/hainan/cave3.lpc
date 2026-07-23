// Room: /d/hainan/cave3
inherit ROOM;

void create ()
{
  set ("short", "落笔洞");
  set ("long", @LONG
眼前的地形突然开阔起来,你直起腰,发现自己在一个数丈高的山洞
中,岩壁垂直,石黑发亮,从洞顶垂下两条石头,形状酷似大号毛笔,从笔端
不断有[33m泉水[37m渗而漏下.
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "泉水" : "看不到水的源头,似乎直接从石笔中渗出来,看来十分清澈,不妨
喝几口(drink water)
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cave1",
  "northdown" : __DIR__"cave4",
]));

  setup();
}
void init()
{
    add_action("do_drink", "drink");
}

int do_drink(string sss)
{

object ob;
ob=this_player();
if (sss!="water") 
   return 0;
if(ob->query("water")> ((int)ob->query("str")-10)*10+150 )
 {
  tell_object(ob,"你饱涨的肚子不允许你这么做！\n");
  return 1;
 } 
else
 {  
 say(ob->query("name")+"凑到笔端前,喝了几口山泉. \n");
 tell_object(ob,"你捧起山泉,美美得喝了两口,真甜哪.... \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }

 }
