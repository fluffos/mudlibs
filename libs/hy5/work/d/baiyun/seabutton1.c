 //Created by justdoit at June 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "º£µ×"); 
        set("long", @LONG 
ÆáºÚÒ»Æ¬£¬º£Ë®±ùÀä´Ì¹Ç¡£ 
LONG 
           ); 
        set("exits",  
           ([  
//           "east"  : __DIR__"seabutton2", 
            ])); 
        set("objects",  
           ([  
             __DIR__"npc/shark" : 3, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1180); 
        set("coor/z",-50); 
        setup(); 
        replace_program(ROOM); 
}   
