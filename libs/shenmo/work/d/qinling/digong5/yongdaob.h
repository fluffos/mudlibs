// Creat by windy 2/24/06 
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
"east" : __DIR__"sanceng"+sprintf("%d",50+random(49)), 
"south" : __DIR__"sanceng"+sprintf("%d",50+random(39)), 
"west" : __DIR__"sanceng"+sprintf("%d",50+random(29)), 
"north" : __DIR__"sanceng"+sprintf("%d",50+random(19)), 
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
"/d/eastway/qinling/npc/stealer" : random(2), 
"/d/eastway/qinling/npc/killer" : random(2), 
"/d/eastway/qinling/npc/worker" : random(2), 
"/d/eastway/qinling/npc/guard" : random(3), 
*/
]));
setup();
}
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
int valid_leave(object who,string dri){ return notify_fail("此处寸步难行。\n");}
