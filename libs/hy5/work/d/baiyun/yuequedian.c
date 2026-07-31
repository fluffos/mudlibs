 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "月阙殿"); 
        set("long", @LONG 
再行不远，一座雄伟壮丽的大殿呈现在眼前。金瓦琉璃，在寬阔的庭院下和高大 
的建筑物前，所谓天高地广，人自然更渺小。竟然生出一种“唯我独尊”的天子气氛 
来。 
LONG 
           ); 
        set("exits",  
           ([  
       "north" : __DIR__"fightdoor",
       "south" : __DIR__"jietiandian",
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
//           __DIR__"obj/sand" : 1, 
            ])); 
        set("indoors", "baiyun");
        set("coor/x",10); 
        set("coor/y",-1930); 
        set("coor/z",20); 
        setup(); 
        replace_program(ROOM); 
}     
