// Room: /d/emei/jiudaoguai3.c 峨嵋派 九十九道拐3

inherit ROOM;

void init();
int do_jump(string);

void create()
{
	set("short", "九十九道拐");
	set("long", @LONG
这里是瀑布上方一道窄窄的山梁，浑然天成。石梁上面人工凿出一格
格阶梯。边上钉了几棵木桩，绕上粗长的麻绳作为扶手。瀑布在脚下奔腾
而过，在不远的山脚下汇成一个深潭(lake)。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                "northdown":__DIR__"jiudaoguai2",
                "southeast" : __DIR__"jiudaoguai4",
	]));

	setup();
}
void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{

	object me = this_player();
	int dex = this_player()->query_dex();
	object ob;

    if (arg != "lake") return command("jump "+arg);
	
    message_vision("$N＂嗖＂地一声，从悬崖上跳了出去。\n", me);
    
    if ((dex <= 23)&&(random(3)<2) || (dex > 23)&&(dex <= 26)&&random(2) )  
    {
    	message_vision("结果＂咕咚＂一声巨响$N平平的掉入了水中。\n", me);
	tell_object(me, "你只觉得一阵天昏地暗，头一阵晕镟。\n");    
  		me->receive_damage("qi", 10);
   		
    } else if (dex <= 26)
    {
    	message_vision("$N摇摇晃晃地落入水中，溅起一朵巨大的浪花！\n", me);
    
    } else 
    {
    	message_vision("$N象一只离弦箭样，姿势十分优美的跃入水中，水面泛出几朵小浪花。\n", me);
    }
    
    me->move(__DIR__"hudi");
    
    return 1;
}


