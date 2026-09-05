inherit GUDONG_SHOP;
int init_store()
{
	object npc;
	if (!present("gudong shang",this_object()))
	{
		npc=new(__DIR__"npc/gudongshang");
		npc->move(this_object());
	}
	set("short", "古董店");
        set("long", 
"这里是一家古董店，古董商帮人鉴定古董发财以后，在这里开了一家店，挂\n起了一面招牌(paizi)。\n"

        );
	set("item_desc", ([
		"paizi" : "这是一面招牌，上面写着：代客存放(cun)古玩字画。需要时可随时取(qu)回，手续费古玩估值百分之五。\n", 
	]));
	set("exits", ([
                "east" : __DIR__"westmarket-1",
                
        ]));
	set("changan", 1); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
	delete("realmap");
}
void create()
{
        set("shop_no",1);
        setup();
        restore();
		init_store();
}