// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
  set ("short", "古树的出口");
  set ("long", @LONG
这里是最后的大门，踏出这里就走向江湖了。请你记得多保存你的
资料(save),如果累了想离开请(quit),不懂的地方可以看(help),祝你
玩的愉快。这里有12条路分别通向
yz 扬州 bj 北京 xy 襄阳 dl 大理 lz 兰州 xz 拉萨
qz 泉州 wg 武馆 jp 日本 cd 成都 km 昆明 xj 新疆
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "yz" : "/d/city/kedian",
  "bj" : "/d/beijing/kedian",
  "xy" : "/d/xiangyang/kedian",
  "dl" : "/d/dali/kedian",
  "qz" : "/d/quanzhouchen/kedian",
  "wg" : "/d/wuguan/guanmen",
  "jp" : "/d/japan/dongmen",
  "cd" : "/d/chengdu/kedian",
  "lz" : "/d/lanzhou/kedian",
  "km" : "/d/kunming/kedian",		
  "xz" : "/d/xizang/octostreet",		
  "xj" : "/d/xinjiang/nanmen",	
]));
  set("no_magic", 1);
  set("no_beg",1);
  set("pingan",1);
  set("no_fight", 1);
  set("pingan", 1);
  set("chatroom",1);
  setup();
}
