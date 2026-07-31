// Room: /d/yandang/luoyan14
inherit ROOM;

void create ()
{
  set ("short", "卧室");
  set ("long", @LONG
室中布置得十分精致,雕花棱窗前的檀木桌上摆着一盆君子兰,绿
色的叶子垂下来,一颗水珠正似乎要掉下来,仔细看,才发现是用名贵
的泪滴钻镶上去的.对面的墙上挂着一把陈旧的破剑,把手上绕着的
红布绸露出一丝血腥.据说是百年前剑圣的遗物.
LONG);

  set("sword", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan13",
]));

  setup();
}
void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
    object me,ob1;
    me=this_player();

    if ( (arg!="sword")&&(arg!="剑")) return 0;
if (!query("sword")) return notify_fail("墙上的剑已经给人取走了!\n");
if((me->query("family/family_name")=="雁荡派")&&(query("sword")))
    {message_vision(
"$N从墙上取下一把无双神剑！\n", me);
      		 ob1=clone_object(__DIR__"obj/wushuang.c");
			 ob1->move(me);
        set("sword",0);
        return 1;
}
return 0;
}
