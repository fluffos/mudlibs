//Made by goodtaste
//wanluntai.c

inherit ROOM;
void create()
{
        set("short", "石阶");
        set("long", @LONG
通往杀手帮的石阶，险峻异常，常人还是不要上去的好
LONG
        );
        set("outdoors", "pker");
        set("exits", ([
                "eastdown" : __DIR__"shijie2",
                 "north" : __DIR__"guangchang",
                ]));
          set("objects", ([
            // __DIR__"npc/jiaofu" : 1,
           ]));
        setup();
       // replace_program(ROOM);
}

int init()
{  int i;
   object me=this_player();
 me->start_busy(1);
   remove_call_out("delay");
   call_out("delay",0,me); 
   
  return 1;
}


int delay(object me)
{
	if (!me)
			return 1;
	
 if((int)me->query_skill("dodge", 1)<80)
  {
     write("石阶越来越险，你提心吊胆的走着，终于一个不小心滚了下去!!\n");
     me->start_busy(3);
   
     me->move(__DIR__"wanluntai");
     message("vision",
		"有个人失足从石阶上掉了下来，看来伤势不轻!\n", environment(me), me);
    return 1; 
    
  }
}
