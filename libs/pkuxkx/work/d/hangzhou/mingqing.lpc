// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit GUDONG_SHOP;
int init_store()
{
	object npc;
	if (!present("gudong zhanggui",this_object()))
	{
		npc=new(__DIR__"npc/gudongshang");
		npc->move(this_object());
	}
	set("short", "明庆寺");
	set("long", @LONG
这里是一家香火很旺盛的寺庙，南面有一间客栈，北面是一间车马行。长安
的古董商租用了部分庙产，在这里开了一家分店，挂起了一面招牌(paizi)。
LONG);
        set("outdoors", "hangzhou");
		set("item_desc", ([
		"paizi" : "这是一面招牌，上面写着：代客存放(cun)古玩字画。需要时可随时取(qu)回，手续费古玩估值百分之五。\n", 
	]));
   set("exits", ([
				"south" : __DIR__"kedian",
				"west" : __DIR__"beidajie1",       
				"north" : __DIR__"machehang",
	]));
	delete("realmap");
}
void create()
{
	set("shop_no",1);
	setup();
	restore();
	init_store();
}