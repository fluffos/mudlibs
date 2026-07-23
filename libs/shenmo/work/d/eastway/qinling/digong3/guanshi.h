// Creat by windy 2/24/06 
#include <ansi.h> 
inherit ROOM; 
void create () 
{
set ("hell", 1);
set ("short", HIW"地陵棺室"NOR);  
set ("long", @LONG 

走到这里忽然开阔了许多，你举火定睛观看，原来这里是一 
个地陵棺室。你大喜之下急忙走到棺椁旁边，却发现已经被 
人打开了，大概是盗墓者所为。
LONG);
set("exits", ([ /* sizeof() == 5 */ 
"southeast" : __DIR__"sanceng"+sprintf("%d",40+random(9)), 
"northeast" : __DIR__"sanceng"+sprintf("%d",30+random(19)), 
"southwest" : __DIR__"sanceng"+sprintf("%d",30+random(19)), 
"northwest" : __DIR__"sanceng"+sprintf("%d",40+random(9)), 
])); 
set("item_desc" , ([ /* sizeof() == 1 */  
"southeast": "黑咕隆咚的，什么也看不清楚。\n", 
"southwest": "黑咕隆咚的，什么也看不清楚。\n", 
"northwest": "黑咕隆咚的，什么也看不清楚。\n", 
"northeast": "黑咕隆咚的，什么也看不清楚。\n", 
])); 
set("valid_startroom", 1); 
set("objects", ([ /* sizeof() == 1 */ 
/*
"/d/eastway/obj/bingma" : random(2), 
"/d/eastway/qinling/npc/beast" : random(3), 
"/d/eastway/qinling/npc/stealer" : random(2), 
"/d/eastway/qinling/npc/killer" : random(3), 
"/d/eastway/qinling/npc/worker" : random(2), 
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
