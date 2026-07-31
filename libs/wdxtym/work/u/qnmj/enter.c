inherit ROOM; 
void create() 
{ 
        set("short", "初级潜能"); 
        set("long", @LONG 
此处是潜能秘境的修炼之地。
LONG
); 
                        
        set("outdoors", "qnjm1"); 
        set("virtual_room", 1); 
        set("exits", ([ 
                "out" : "/d/city/guangchang", 
        ])); 
        set("objects",([
                "/d/maze/qnmj/npc/1": 5,
        ])); 
        setup();
        replace_program(ROOM); 
} 
