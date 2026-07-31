// Room: /dali/zahuopu.c
// bbb 1997/06/12
// Modify By River 98/12/
inherit MISC_ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是一家小小的杂货铺，别看其小，却收拾得非常整齐，因为对面是城中
富人的积居地，所以卖的货物都是特地从产地长途贩来的。有一两个家人模样
正在和老板讨价还价。左侧立着一块招牌(zhaopai)。
    门前立了个牌子(sign)。
LONG
	);

	set("item_desc", ([
		"zhaopai": "请用 \"list\" 列出当前货物表，\"buy\" 向老板购物。\n",
	]));
	set("exits", ([
           "north" : __DIR__"nanjie5",
	]));
	set("objects", ([
		__DIR__"npc/yang": 1,
	]));

	set("coor/x",-290);
  set("coor/y",-470);
   set("coor/z",-20);
   setup(); 
}

void init()
{
	object me = this_player();
     	::init();
     	if(me->query_temp("xuncheng")){
      	me->set_temp("dali_xc/zahuopu",1);
      	}
}
