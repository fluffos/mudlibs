inherit ROOM; 
 
void create() 
{ 
        set("short", "大平原"); 
        set("long", @LONG 
这里是一望无际的大平原。绿色的草地美丽得就象晴朗的蓝天。草原上 
三三两两的羊群则是蓝天上飘浮的朵朵白云。 
LONG 
        ); 
        set("exits", ([  
 "south": __DIR__"road5" , 
])); 
        set("outdoors", "fengyun"); 
          set("coor/x",50); 
        set("coor/y",200); 
        set("coor/z",0); 
        set("coor/x",50); 
        set("coor/y",200); 
        set("coor/z",0); 
        setup(); 
} 
  
