 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "排浪崖");
        set("long", @LONG 
但见浪涛不断地冲击着岩石，浪花飞溅，在阳光照射之下，发出千万金光，远方
也是光鳞万点，无涯无际，蔚为奇观。飒飒的海风把岩石上行人的衣袂，拂得猎猎有
声。这儿离海面约有三四十丈，极是高峭，身後虽还有更高的岩石峭壁，不过，当站
在这一块巨大的岩石上之时，除了天上的浮云比你更高之外，连海鸥也很少飞上来，
俯视着大海、浪花、海鸥……胸中豪情激荡，热血如沸。;
LONG 
           ); 
        set("exits",  
           ([  
       "southup" : __DIR__"jintaoting",
       "northwest" : __DIR__"baiyunentrance",
       "east" : __DIR__"shiliang",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1710); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}  
