//Made by goodtaste
//wanluntai.c

inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
一条弯弯曲曲的山路
LONG
        );
        set("outdoors", "pker");
        set("exits", ([
       
                "westup" : __DIR__"shanlu32",
                ]));
        
          set("objects", ([
        

                
                   
           ]));
   setup();
       // replace_program(ROOM);
}

void init()
{
   object me=this_player();
   if(me->query_temp("xia"))
   me->delete_temp("xia");
}



