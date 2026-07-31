// Room: /d/sandboy/undertree 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "大榕树下");
  set ("long", @LONG
高大的榕树枝叶繁茂,许多树枝垂了下来,又深入泥土之中,盘根交错.
西面是一片晒谷场,向北有口水井.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"well",
  "west" : __DIR__"ground",
]));
set("outdoors","/d/jiangnan");
  setup();
}
void init()
{
  add_action("do_climb","climb");
}
int do_climb(string arg)
{
  object pla;
  pla=this_player();
if (!arg||arg!="榕树") return 
       notify_fail("你要爬什么?\n");
if (living(pla)&&environment(pla)==this_object())
   message_vision("$N双手攀着树干,蹭蹭地爬了上去.\n",pla);
tell_room(__DIR__"intree","有人爬上树来.\n");
  pla->move(__DIR__"intree");
return 1;
}
