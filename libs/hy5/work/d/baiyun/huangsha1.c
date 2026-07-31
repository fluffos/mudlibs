 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "碧海黄沙");
        set("long", @LONG 
放眼望去，海天相接，虹霞绚烂，洒满了天地之间，海面上也荡起千万片多彩的
波浪。一只海鸥，冲天飞起，冲人了海天深处，像是人们的青春一般，一去不再回头。
海边是金灿灿的黄沙，几个岛上的渔童赤着脚丫，欢唱着不知名的童谣，清脆的歌声
随着海浪起伏回旋。
LONG 
           ); 
        set("exits",  
           ([  
       "south" : __DIR__"baiyunentrance",
       "north" : __DIR__"baiyundu",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/fishboy" : 2,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1530); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}    
