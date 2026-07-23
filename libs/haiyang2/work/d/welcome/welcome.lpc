// /d/welcome/welcome.c
// 海洋II
// 星星(lywin) 2000/6/4

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "欢迎光临侠客行海洋II");
  set ("long", @LONG
你混混沌沌的来到了一个陌生的世界，你想看看你在哪里(l, look),
你想知道这个世界里都有谁(who),或许你要四处走走，(w,s,n,e,nw,ne,
,sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)，不过你得先看看有那些出口。
新手请用chat加空格，然后再加上要说的话来聊天。
东边(east)是新手培训室。 另外这里有8条路分别通向
yz 扬州 bj 北京 xy 襄阳 dl 大理 lz 兰州 xz 拉萨
qz 泉州 wg 武馆 pa 平安 cd 成都 km 昆明 xj 新疆
[1;31m金庸大侠看来会给你一些帮助的(ask jin yong about liwu)

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "yz" : "/d/city/kedian",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "pa" : "/d/pingan/pingankezhan",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
  "xz" : "/d/xizang/octostreet",		
  "xj" : "/d/xinjiang/nanmen",			
"east" : __DIR__"newbie4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"jing" : 1,
 //"/clone/gift/newbieliwu" : 1,
]));
  set("no_beg", 1);
  set("valid_startroom", "1");
  set("pingan", 1);
  set("no_fight", 1);

  setup();
  replace_program(ROOM);
}
void init()
{
	object me;
me=this_player();
if( me->query_temp("netdead")) 
"/cmds/usr/quitgame"->main(me);
	return;
}
