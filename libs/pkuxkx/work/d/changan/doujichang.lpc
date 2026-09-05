
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "斗鸡场");
        set("long", @LONG
整个长安城上至皇公大臣、下至黎民百姓都酷爱斗鸡，斗鸡场周围
围满观看的皇亲国戚、名门仕女。
LONG        );
        
        set("exits", ([
                "east" : __DIR__"chengtianstreet-9"
        ]));
        
        set("item_desc", ([
          "斗鸡场" : "斗鸡场里面正有两只公鸡在相斗，四周洒满了赌斗(bet)的铜钱。\n"]));
        
        set("locate_level",1);

        set("outdoors", "changan");
        set("changan", 2); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

void init()
{
	add_action("do_bet", "bet");
}

int do_copy()
{
	write("功能待开放！敬请期待。\n");
	return 1;
}