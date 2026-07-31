 inherit ROOM;
void create() 
{ 
        set("short", "城南小路"); 
        set("long", @LONG 
北边就是高大的风云城，南边则是一望无涯的平原,平原上种有大片的庄稼。 
平原的尽头好象有一个湖，湖面反射着落日的余辉。 
LONG 
        ); 
        set("exits", ([ /* sizeof() == 4 */ 
  "east" : __DIR__"fysouth", 
  "northwest": __DIR__"sroad2", 
])); 
        set("outdoors", "fengyun"); 
       set("coor/x",-60); 
        set("coor/y",-160); 
        set("coor/z",0); 
            replace_program(ROOM); 
 
        set("coor/x",-60); 
        set("coor/y",-160); 
        set("coor/z",0); 
        setup(); 
} 
       
