 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <room.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "白云观"); 
        set("long", @LONG 
这里乃是叶孤城所居住的地方。叶孤城魈图皇位已久。是以白云城处处以皇宫为 
图本造筑。唯有此处甚为淡雅。小小的道观内，一桌，一椅，一圃而已。墙上一副字 
联，上书：一剑东来，天外飞仙！
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"changlang3",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//       __DIR__"obj/vase" : 1,
       "/d/huanghe/yyd/npc/changcf":1,
       __DIR__"npc/master" : 1,
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2200); 
        set("coor/z",20); 
        setup(); 
        create_door("north", "石门", "south", DOOR_CLOSED); 
        replace_program(ROOM); 
}     
