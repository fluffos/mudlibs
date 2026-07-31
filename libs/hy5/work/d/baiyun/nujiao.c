 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "怒礁");
        set("long", @LONG 
在整个白云岛中，唯独怒礁孑然傲立，值水涨之际，巨浪冲上外围的礁石，不住
发出使人心颤神荡，惊天巨响，不肯有一刻放缓下来。这里长年受狂风刮蚀，海水冲
刷，悬岩陡峭，石色赭赤的礁石巍然不动。走至怒礁尽头，但觉两耳风生，放眼则是
海天茫茫，怒浪惊涛中不时有几只海鸟翱翔搏击。怒浪，彩霞，青天、大海、鸥影、
孤帆，求索于天地之间，不禁怆然泣下。
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"shiliang",
            ])); 
        set("objects",  
           ([  
       __DIR__"obj/rock" : 1,
       __DIR__"npc/baiyunxian" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",80); 
        set("coor/y",-1710); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}       
