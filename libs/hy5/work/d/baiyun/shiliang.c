 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "怒海石梁");
        set("long", @LONG 
这石梁上隔青天，下绝碧海，孤零零横亘在怒礁与拍浪崖之间，仿佛天地之间至
此而断，人世间所有烦扰忧愁也随风而去，随海而逝。怒海惊涛，仿佛一个巨浪就可
把这千年石梁拍为齑粉。
LONG 
           ); 
        set("exits",  
           ([  
       "west" : __DIR__"pailangya",
       "east" : __DIR__"nujiao",
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",70); 
        set("coor/y",-1710); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}       
