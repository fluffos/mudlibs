 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "花径");
        set("long", @LONG 
海风习习，微微有些咸味之中夹着扑鼻花香，远远望去，蜿蜒曲折的小径上郁郁
葱葱，一团绿、一团红、一团黄、一团紫，端的是繁花似锦，落英缤纷。白云岛因天
地之宜，终年暖湿，树木长绿，花草繁茂，而岛上可爱的少女更是健康而可爱，纤手
轻扬。花香满径，人比花香。
LONG 
           ); 
        set("exits",  
           ([  
       "northeast" : __DIR__"flowerroad2",
       "southup" : __DIR__"yuhuage",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/flowergirl" : random(3),
       __DIR__"npc/xiaofan" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-1600); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}     
