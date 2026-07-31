 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "武门"); 
        set("long", @LONG 
狭長的天街一变而为宽阔的庭院。庭院周围的门户也和天街的不同，都建在一人 
多高的台基之上。由於周围有高台环绕，更显得建筑物的高大，人置身其間，顿觉渺 
小。庭圆中心，五座飞虹拱桥和玉帶般的內金水河的纵横交织，皎白的石栏杆穿插其 
间。 
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"skystreet",
       "south" : __DIR__"yuequedian",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/guard1" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1850); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
}     
