 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <room.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "甬道");
        set("long", @LONG 
接天楼背靠绝壁，谁也无法想象绝壁之中竟然有如此一条笔直而幽长的甬道，两
旁点着不灭的长明灯，光线虽不很亮，但也可辨道路，似乎本是依着山腹中天然洞穴
修凿而成，人工开凿处甚是狭窄，有时却豁然开阔，只觉渐行渐低，道中出现了流水
之声，琮琮铮铮，清脆悦耳，如击玉罄。而前方似乎有些许灯光忽明忽暗。
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"changlang2",
       "south" : __DIR__"baiyunguan",
            ])); 
        set("objects",  
           ([  
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2150); 
        set("coor/z",20); 
        setup(); 
        create_door("south", "石门", "north", DOOR_CLOSED); 
        replace_program(ROOM); 
}       
