 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "雁翅楼"); 
        set("long", @LONG 
雁翅楼的兩端，各設有一座重檐尖頂的闕亭。整座楼上的构形，三面环抱，五峰
突出，高低錯落，主次相鋪，气势雄伟，有"五凤楼"之称。楼上古篆一幅：
                           苍    有 
                           松    凤
                           迎    栖
                           客    梧
LONG 
           ); 
        set("exits",  
           ([  
       "northdown" : __DIR__"dragonplace",
       "southeast" : __DIR__"duixiuhill",
//           "west"  : __DIR__"beach1", 
//           "east"  : __DIR__"beach2", 
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/songshi" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",8); 
        set("coor/y",-1690); 
        set("coor/z",11); 
        setup(); 
        replace_program(ROOM); 
}   
