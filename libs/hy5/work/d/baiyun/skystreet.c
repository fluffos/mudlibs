 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "天街"); 
        set("long", @LONG 
走进城门，一条长街笔直向前，隐没于亭殿之中。天街的兩旁由連檐通脊的廊廡 
甚是整齐工直。你心中径自生出一股严肃庄穆的气氛来，禁不住的收敛了笑意。 
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"baiyunwall",
       "west" : __DIR__"zhanmangtai",
       "east" : __DIR__"ziqilou",
       "south" : __DIR__"fightdoor",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1800); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
}   
