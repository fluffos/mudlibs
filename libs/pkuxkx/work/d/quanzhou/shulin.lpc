// /d/jiaxing/shulin1.c 江南树林

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
江南难得一见的大片树林，周围黑漆漆一团, 你几乎迷了路。
LONG
        );

        set("exits", ([
                 "east" : __DIR__"lumu",
                "south" : __DIR__"luzhuang",
            "northeast" : __DIR__"xiaojing",
        ]));

        set("objects", ([
//     __DIR__"npc/wu-xiuwen" : 1,
        ]));
        set("outdoors", "嘉兴");
        setup();
//       replace_program(ROOM);
}

void init()
{   object me = this_player();
    int luck = me->query_temp("oyf_meet");
      if(!me->query("oyf_son")) {
       if((random((int)me->query("kar")) <= 5 || random((int)me->query("kar")) >= 20) &&
          me->query_condition("bing_poison") > 30 &&
          me->query("age") < 19){
          if(!luck) {
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n");
          me->set_temp("oyf_meet", 1);
          }   
       if (luck >= 1) {
          write("你突然觉得好象有人在你身后，转过头来却发现什么也没有。\n"); 
          me->add_temp("oyf_meet", 1); 
          } 
        }      
     }                         
}
