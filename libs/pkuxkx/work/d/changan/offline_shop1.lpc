
inherit OFFLINE_TRADE_ROOM;
#include <ansi.h>
int init_store()
{
	object npc;
	if (!present("quechang guanshi",this_object()))
	{
		npc=new("/clone/npc/offline_trader");
		npc->move(this_object());
	}
		set("short", "榷场");
        set("long", 
"这里是玩家可以自行离线交易的榷场，竖着一块牌子(paizi)。\n");
       
        set("item_desc", (["paizi" : "这是一面招牌，上面写着：离线寄售(sell)物品，可以取回(quhui)，物品列表(list)，查询(query)和提款(tikuan)。\n交易商税二十抽一，无正当理由取回货物价十罚一。摊位有限，七日之内既不交易，又不取回，货物充公。\n",]));
        
        set("outdoors", "changan");
        set("exits", ([
                
                "west" : __DIR__"eastmarket-2",        
        ]));
        set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        delete("realmap");
}
void create()
{
        setup();
		set("no",1);
        restore_itself();
		remove_call_out("dest_goods");
		call_out("dest_goods",1);
}


