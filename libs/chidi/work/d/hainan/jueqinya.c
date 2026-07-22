// Room: /d/hainan/jueqinya
inherit ROOM;

void create()
{
  set ("short", "绝情崖");
  set ("long", @LONG
绝情崖是一座悬崖,从崖边向下望,片片白云,阵阵迷雾,只能听到海
涛拍岸声.据说以前有个痴情的女子,因为爱人落海而死,就从此地跳了下
去,从此人们把这地方就叫作'绝情崖',你不会也想跳(jump down)下去吧?
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "westdown" : __DIR__"road5",
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
    object ob;
ob=this_player();
	if( !living(ob))	return 0;
if (str!="down") return 0;
message_vision("$N看着崖下朵朵白云,突然一纵身,从悬崖上跳了下去!\n",ob);
ob->move("/d/hainan/xialuo.c");
return 1;
}
