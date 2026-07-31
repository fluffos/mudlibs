 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "挂剑碑");
        set("long", @LONG 
路行至此，可俯视岛下碧海黄沙，也可远眺岛上白云孤城，而白云朵朵似乎就在
身边，可谓得白云岛天地之菁华所在，叶孤城立碑于此，尽抒其志： 
                           君
                           临
                           天
                           下 
LONG 
           ); 
        set("exits",  
           ([  
       "northdown" : __DIR__"jianlin",
       "southwest" : __DIR__"hillroad",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/guard2" : 1,
       __DIR__"npc/guard3" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1730); 
        set("coor/z",15); 
        setup(); 
        replace_program(ROOM); 
}  
