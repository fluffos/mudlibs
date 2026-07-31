inherit ROOM; 
void create() 
{ 
        set("short", "废弃的猎人小屋"); 
        set("long", @LONG 
试炼之森的深处，阵阵黑雾飘来，只觉头晕目眩。好象被人
设计了一种阵，一走进来，你仿佛迷失了方向。不时有腥风吹来，
发出阵阵恶臭。这里有一坐废弃的猎人小屋。
LONG); 
                        
        set("outdoors", "forest"); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("no_npc",1);
        set("exits", ([ /* sizeof() == 3 */ 
                "west" : __DIR__"maze2/entry", 
                "east" : __DIR__"out", 	
        ])); 
      set("objects",([
                __DIR__"npc/forest_master": 1,  
                "/d/city/npc/obj/jitui": 2,  	
                "/d/city/npc/obj/jiudai": 2,  		
        ])); 
        
/*        set("objects",([
                __DIR__"npc/forest_master": 1,  
        ])); */
        setup();
        replace_program(ROOM); 
} 
