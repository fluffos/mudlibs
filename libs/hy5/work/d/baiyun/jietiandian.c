 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
#include <room.h> 
inherit ROOM; 
void create() 
{ 
        set("short", "接天楼");
        set("long", @LONG 
危乎高哉！接天而立，比天之高！叶孤城心怀天下，立志有朝一日逐鹿中原。而
此楼地处白云岛最高之处，仿佛一柄利剑划破长空遥指中原九州。楼上别无他物，一
座高台上汉白玉雕成的龙椅面北迎风。
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"yuequedian",
       "south" : __DIR__"changlang",
            ])); 
        set("objects",  
           ([  
              __DIR__"npc/jiankuang" : 1,
            ])); 
       set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-2000); 
        set("coor/z",20); 
        setup(); 
        create_door("south", "石门", "north", DOOR_CLOSED); 
        replace_program(ROOM); 
}  
