// Room: /dali/dangpu
// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家素以买卖公平著称的老字号当铺，在全国各地名气很大，一块牌
子（paizi)高高挂在墙上，柜台后坐着当铺的老板，手拿一杆大水烟袋上上下
下打量着你。
LONG
	);
	set("no_sleep_room",1);
        set("no_fight",1);
        set("no_clean_up", 0);

	set("item_desc", ([
		"paizi" : "公平交易，老少无欺。\n",
	]));
	set("objects", ([
		__DIR__"npc/shen" : 1,
             	__DIR__"npc/shengyiren" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"dongjie1",
	]));

	set("coor/x",-280);
  set("coor/y",-390);
   set("coor/z",-20);
   setup(); 
}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/dangpu",1);
      }
}
