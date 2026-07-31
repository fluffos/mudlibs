 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "白云渡");
        set("long", @LONG 
白云幽幽，海天一线。这里，就是白云岛了，但见阳光灿烂，岛边沙滩洁白柔细，
海水湛蓝如碧，浪涛带着新鲜美丽的白沫轻拍着海岸，晴空万里无云，岛上满眼翠绿。
一切有如仙境一般。往东去靠着岸边是个不大的码头，停靠着来往白云岛的船只，嘹亮
的呼声此起彼落。
LONG 
           ); 
        set("exits",  
           ([  
       "south" : __DIR__"huangsha1",
       "east" : __DIR__"matou",
            ])); 
        set("objects", ([
//        __DIR__"obj/boat" :1,
        ]));
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1500); 
        set("coor/z",0); 
        set("valid_startroom", 1); 
        setup(); 
        replace_program(ROOM); 
}      
