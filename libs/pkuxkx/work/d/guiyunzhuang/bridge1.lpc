// Room: /u/pingpang/room/bridge1.c
// Made by: pingpang

#include <ansi.h>
inherit ROOM;
               
void create()
{
	set("short", "太湖桥");
	set("long","这是闻名遐尔的"YEL"太湖桥"NOR",在此你能看到远处的"GRN"天水一色"NOR"的美景.\n");
	set("exits", ([ /* sizeof() == 2 */
			       "north" : __DIR__"bridge","east":__DIR__"rukou",
]));
     set("outdoors","guiyunzhuang");
	setup();
} 
void init()
{
	object ob;
	ob = this_player();   
	call_out("check", 1, ob); 
}
void check(object ob)
{                     
	int i;
	object *inv, me; 
	string name;
        if (!ob) return;
	name = ob->query("id");
	me = this_object();
	inv = all_inventory(me); 
	for( i = 0; i < sizeof(inv); i++)
	{    
	if( inv[i]->query("id") != "ghost" ) continue;
	if( inv[i]->query_temp("ghost") != 5 ) continue;
	if( inv[i]->query_temp("leader") != name ) continue;
	message_vision(ob,HIG"野鬼悄悄告诉你道：“多谢你帮了我一个大忙，我\n"
		"有一个小小的秘密要告诉你，你可不要告诉别人哟！”\n"NOR);
	message_vision(ob,HIG"野鬼瞅了瞅四周，对你说：“在这里的迷魂阵深处有一\n"
		"个秘密，不过具体位置我记不清了，你要是有心，就好好找一找吧。\n"NOR);
	remove_call_out("dest");
	call_out("dest", 10, inv[i]);
	}
	return;	
}	
void dest(object obj)
{                                 
	message("vision",YEL"只见天际划过一道闪光，让你眼花缭乱；一个声音萦荡着:你得找到陆乘风的贴身金手印和[黑风山]上的骷髅。\n"
		"发现孤魂野鬼已经消失不见了。\n"NOR,environment(obj), obj);
	destruct(obj);
}	                                 

