// Room: /d/yandang/xiaolongq
inherit ROOM;
int last_time=-10000;

void create ()
{
  set ("short", "小龙湫");
  set ("long", @LONG
小龙湫瀑布从一道山崖上悬挂下来,如同一条玉带从九天抛下,崖
下积水成潭,潭边青草茵茵,水中巨石横空,石上青苔点点,看来很久没
人到此了,四周空谷鸟语,此地仅你一人.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shangty.c" : 1,
]));
  set("outdoors", "/d/yandang");
  set("exits", ([ /* sizeof() == 1 */
  "eastup" : __DIR__"wulonggu",
]));

  setup();
}
void init()
{
	add_action("do_search","search");
}
int do_search(string arg)
{
    object me,ob;
    int i;
    me=this_player();
    if (me->query("family/family_name")!="雁荡派")
{ if (!present("snake",this_object()))
clone_object(__DIR__"npc/mangshe")->move(environment(me));
return notify_fail("你在草丛中翻来翻去,结果翻出一条莽蛇\n");}
 
    me->set_temp("search",me->query_temp("search")+1);

    if(me->query_temp("search")==3)
    {
      me->set_temp("search",0);

      i=time();
      if((i-last_time)>4200)
      { if ((int)me->query_skill("sword",1)>60){
      clone_object(__DIR__"obj/biyuzan")->move(environment(me));
	message_vision(
	"$N在草丛中找到一枚碧玉簪。\n", me);
      last_time=i;}
    else message_vision("$N想现在还是学好剑法比较重要,不能浪费时间在这种事情上了!\n",me);
      }
      else          
	message_vision("$N在草丛中找来找去,差点被蛇咬上一口！\n", me); 
    }
    else
      message_vision("$N在草丛中找来找去,什么都没找到！\n", me);
    return 1; 
}
int valid_leave(object me, string dir)
{
  if(dir=="eastup") me->delete_temp("search");

  return ::valid_leave(me, dir);  
}
