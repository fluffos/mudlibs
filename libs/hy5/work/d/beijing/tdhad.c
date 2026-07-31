// Room: /d/welcome/newbie3
inherit ROOM;

void create ()
{
  set ("short", "天地会暗道网");
  set ("long", @LONG
地道里一片漆黑，呼呼的风声从四面八方传来。你什么也看不见，
只能在地道里瞎摸乱撞。北面似乎隐隐约约有人说话，但只一会儿又没
声了。你使劲地摇了摇头，很怀疑这到底是不是幻觉。好象你已经迷路
了。
这里有24条路分别通向
yz 扬州 bj 北京 xy 襄阳 dl 大理 lz 兰州 xz 拉萨
qz 泉州 wg 武馆 jp 日本 cd 成都 km 昆明 xj 新疆
dx 定襄 ca 长安 jz 荆州 yj 盛京 sz 苏州 fz 福州
cz 沧州 yx 宜兴 yy 岳阳 yp 延平 hz 杭州 bl 巴陵
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "yz" : "/d/city/guangchang",
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
"dx" : "/d/dingxiang/beidajie1",	
"ca" : "/d/changan/ca",	
"jz" : "/d/jingzhou/guangchang",	
"yj" : "/d/yanjing/street",	
"sz" : "/d/suzhou/canlangting",	
"fz" : "/d/fuzhou/majiu",	  
"cz" : "/d/cangzhou/beimen",	
"yx" : "/d/yixing/yixing",	
"yy" : "/d/yueyang/guangchang",	
"yp" : "/d/yanping/majiu",	
"hz" : "/d/hangzhou/kedian",	
"bl" : "/d/baling/dongdajie1",	  
  "north" : "/d/beijing/andao10",	
]));


  setup();
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	

		if ( me->query("family/family_name") != "云龙门" && dir !="north")
		return notify_fail("只有天地会的人懂得使用这里的暗道。\n");
	


	return ::valid_leave(me, dir);
}
