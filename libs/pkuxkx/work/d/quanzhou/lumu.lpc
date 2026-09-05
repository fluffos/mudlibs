// /d/jiaxing/lumu.c 坟墓
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "坟墓");
	set("long", @LONG
这儿有两株高耸的大槐树，槐树下赫然并列著两座坟墓，一座
墓碑上写著「陆公展元之墓」六字，另一碑下则是「陆门何夫人之
墓」七字。墓畔青草齐膝，显是安葬已久。一青袍长须的老者呆呆
望著墓碑，自言自语。
LONG
	);

	set("exits", ([
                 "west" : __DIR__"shulin",
	]));

        set("objects", ([
                 __DIR__"npc/wu-santong" : 1,
        ]));

        set("outdoors", "嘉兴");
	setup();
	replace_program(ROOM);
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
