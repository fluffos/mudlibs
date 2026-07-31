// Room: /d/emei/hudi.c 湖底
// create by host dec,20 1997

inherit ROOM;

void init();
int do_swim();

void create()
{
        set("short", "湖底");
	set("long", @LONG
这里是深潭底部，张眼望去，四周长满了许多绿色的水草随着水波
不停的在那里晃动，鱼儿不断的在水草丛中游来游去。仔细看去约莫可
以看到前方有一个洞口，从洞口不时有阳光透入。
LONG
	);
        set("exits", ([
	]));
	setup();
}
void init()
{
	add_action("do_swim", "swim");
}

int do_swim()
{

	object me = this_player();
	int dex = this_player()->query_dex();
	object ob;

    message_vision("$N缓缓吐出一口浊气，猛的向洞口游去。\n", me);
    
    if ((dex <= 15)&&(random(3)<2) || (dex > 15)&&(dex <= 18)&&random(2) )  
    {
    	message_vision("突然一股巨大的暗流涌了过来，一阵天昏地暗过后，$N被冲回了岸上。\n", me);
       me->move(__DIR__"jiudaoguai2");
   		
    } else if (dex <= 23)
    {
    	message_vision("$N慢慢游到洞口，突然一股暗流涌了过来，$N被冲回了岸上。\n", me);
       me->move(__DIR__"jiudaoguai2");
    } else 
    {
    	message_vision("$N飞快的穿过洞口，游到了洞口的另一面。\n", me);
       me->move(__DIR__"dongkou");
    }
    
    
    
    return 1;
}
