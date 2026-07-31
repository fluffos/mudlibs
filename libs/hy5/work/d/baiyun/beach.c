 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "海岸");
        set("long", @LONG 
在这里，你已分不清天上人间。阳光灿烂，沙滩洁白柔细，海水湛蓝如碧，浪涛 
带着新鲜美丽的白沫轻拍着海岸。极目而望，海中有天，天中有海。仰视碧空，但见 
天做沧海，云做轻帆。听着浪涛轻拂海岸，你早已忘了今生何世。 
LONG 
           ); 
        set("exits",  
           ([  
             "north" : __DIR__"southsearoad1", 
             "west"  : __DIR__"beach1", 
             "east"  : __DIR__"beach2", 
            ])); 
        set("objects", 
          ([ 
        __DIR__"npc/yueyang" : 1,
        __DIR__"npc/husheng" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-680); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
} 
 
