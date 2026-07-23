// Creat by windy 2/25/06 
#include <ansi.h> 
inherit ROOM; 
void create () 
{
set ("hell", 1);
set ("short", "地陵甬道"); 
set ("long", @LONG

这里是秦始皇地下陵园的一条甬道，阴冷黑暗。你只能靠着 
手中火扇子的微弱光芒摸索前行。四周不时传来野兽的嚎叫 
。你鼓足勇气向前走去。 
LONG);
set("exits", ([ /* sizeof() == 5 */ 
"east" : __DIR__"sanceng"+sprintf("%d",random(12)), 
"south" : __DIR__"sanceng"+sprintf("%d",random(24)), 
"west" : __DIR__"sanceng"+sprintf("%d",random(36)), 
"north" : __DIR__"sanceng"+sprintf("%d",random(48)), 
])); 
set("item_desc" , ([ /* sizeof() == 1 */  
"east": "黑咕隆咚的，什么也看不清楚。\n", 
"south": "黑咕隆咚的，什么也看不清楚。\n", 
"west": "黑咕隆咚的，什么也看不清楚。\n", 
"north": "黑咕隆咚的，什么也看不清楚。\n", 
])); 
set("objects", ([ /* sizeof() == 1 */
/*
"/d/eastway/obj/bingma" : random(2),
"/d/eastway/qinling/npc/cike" : random(3), 
"/d/eastway/qinling/npc/killer" : random(2), 
"/d/eastway/qinling/npc/kulou2" : random(2), 
"/d/eastway/qinling/npc/guard" : random(2), 
*/
]));
setup();
}
/*
void init()
{
add_action("do_drop", "drop");
//add_action("do_perform", "perform");
}
int do_drop()
{
object me;
me=this_player();
tell_object(me,"这里这么黑，东西扔了就找不回来了!\n");
return 1;
}
int do_perform (string arg)
{
object who = this_player();
if (arg=="hunpofeiyang" || arg=="sanjiao" || arg=="shixie" || arg=="piyi")
{
tell_object(who,"你发觉自己似乎被一种邪恶的力量控制着，许多绝技竟然施展不出！\n");
return 1;
}
else return 0;
}
*/
void reset() 
{
if ( !query("last_update_time") 
|| time()>=query("last_update_time")+1800 )  
{
set("last_updata_time",time()); 
::reset(); 
}
return;  
}
int is_digong()
{
return 1;
}
