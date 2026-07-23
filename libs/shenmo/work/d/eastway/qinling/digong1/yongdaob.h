// Creat by windy 2/22/06 
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
"east" : __DIR__"yiceng"+sprintf("%d",random(13)), 
"south" : __DIR__"yiceng"+sprintf("%d",14+random(14)), 
"west" : __DIR__"yiceng"+sprintf("%d",random(13)), 
"north" : __DIR__"yiceng"+sprintf("%d",14+random(14)), 
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
"/d/eastway/qinling/npc/beast" : random(6), 
"/d/eastway/qinling/npc/stealer" : random(2), 
*/
])); 
setup(); 
}
void init() 
{
add_action("do_cast", "cast");
}
int do_cast()
{
object me;
me=this_player();
tell_object(me,"你念了几句咒语，竟然发觉自己的法力失灵了!\n");
return 1;
}
void reset()
{
if ( !query("last_update_time") 
  || time()>=query("last_update_time")+2700 )
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
