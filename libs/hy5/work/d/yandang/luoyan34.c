// Room: /d/yandang/luoyan34
inherit ROOM;

void create ()
{
  set ("short", "月洞门");
  set ("long", @LONG
这是一座月洞门,半圆形的造形,用黑色花岗石作底,顶上是白色的
大理石,上面镌了几个字'留月居',向里面看,是个花园,这里是庄主款留
贵宾的地方,庄中弟子不得允许是不准进的.
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shouwei" : 2,
]));
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"luoyan35",
  "west" : __DIR__"luoyan17",
]));
  set("outdoors", "/d/yandang");

  setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	mapping gt;
	seteuid(geteuid(me));
	
	if ( (me->query("family/family_name")=="雁荡派")&&(dir=="north") ) {
			ob = present("shou wei");
			if(!ob) return 1;
			{
			message_vision("\n$N拦住$n道：本庄弟子不得进入留月居,这是庄主的命令！\n", ob, me);
			return  notify_fail("");
            }    
	    }
     return 1;
}
