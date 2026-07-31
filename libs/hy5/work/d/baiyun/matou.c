 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "码头");
        set("long", @LONG 
白云岛跟南海互有来往，单单是每月的海产渔业生意就已经足够白云岛上上下下
花费使用，所以白云城主虽然挑剔奢华，但白云城内外还是歌舞升平。而南海的商人
为满足白云岛居民的生活需要，亦会不时派遣船只到彼岸来销售琳琅满目的吃喝玩乐
的商品。岛上需要外出的人，也可以乘搭这些回航的船过渡。
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"baiyundu",
            ])); 
        set("objects", ([
        __DIR__"obj/boat" :1,
        ]));
        set("outdoors", "baiyun"); 
        set("coor/x",18); 
        set("coor/y",-1500); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}      
