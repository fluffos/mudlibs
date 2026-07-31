// Room: /d/hainan/cave5
inherit ROOM;

void create()
{
  set ("short", "小洞天");
  set ("long", @LONG
好不容易从小洞中爬出来,这个地方总算开阔了点.头顶的石壁上有
个小小的正圆天窗,阳光便从这天窗中射进来,在正下面,有一块莲花形状
的石头,显得分外光滑.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"outcave",
  "southwest" : __DIR__"cave4",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "石头" : "这块石头跟旁边的都有所不同,你仔细看了看,似乎是有人经常摩挲
的原因,不知道能不能推开(push stone).
",
]));
  setup();
}
void init()
{
    add_action("do_push", "push");
    add_action("do_say","shuo");
}

int do_say(string sss)
{

object ob;
ob=this_player();
seteuid(geteuid(ob));
if((ob->query("gender")=="男性")&&(sss=="芝麻开门"))
{
message_vision("$N说道:芝麻开门.\n",ob);
message_vision("莲花形的石头应声向下沉去,$N走了进去. \n",ob);
ob->move(__DIR__"midao2.c");
  return 1;
 } 
}
int do_push(string sss)
 { object ob;
ob=this_player();
if ((sss=="stone")||(sss=="石头")) 
 message_vision("$N用力推了半天,莲花型的石头纹丝不动. \n",ob);
  return 1;
 }
