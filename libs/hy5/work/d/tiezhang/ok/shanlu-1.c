// Room: /d/tiezhang/shanlu-1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条崎岖的山路上，道旁山峰壁立，长草过腰，中间一条羊肠小路，
仅容一人勉强过去。
LONG
	);
    
        set("outdoors", "tiezhang");
	
        set("exits", ([ 
"north" : __DIR__"shanlu-2",
"southdown" : __DIR__"shanmen.c",
]));
	set("no_clean_up", 0);

	setup();

}
void init()
{
        add_action("do_dig","wa");
        add_action("do_dig","dig");
}

int do_dig(string arg)
{    
        mapping fam;
        object me,ob,weapon;
        int costj, costq;
        me = this_player();
        if(me->query_temp("job_name")!="挖陷井") 
             return notify_fail("你必须跟帮主领了这工作才能在这里干! \n");
        if (me->is_busy())
             return notify_fail("你现在正忙着呢!\n");
        if (me->is_fighting())
             return notify_fail("你正在战斗中,无法专心干活!\n");
        weapon = me->query_temp("weapon");
        if( !weapon || weapon->query("id") != "tie chan")
             return notify_fail("你想用什么来挖？\n");
        if ( !arg || !(arg == "陷井" || arg == "xianjing"))
           return notify_fail("你想要干什么？\n");
             
        costj = random((int)me->query("con")/2);
        costq = random((int)me->query("str")/2);

        if ((int)me->query("jing") < costj 
         || (int)me->query("qi") < costq){
          message_vision(HIR"由于$N太疲倦了，$N一个不小心跌进了自己挖的陷井中。\n"NOR,me);
          me->unconcious();
          return 1;
          }        
          me->receive_damage("jing", costj);
          me->add("qi", -costq);       
        if (((int)me->query_temp("mark/挖陷井") > 8 + random(13)))
          {
          me->set_temp("mark/挖完",1);
          write(HIG"你发现陷井已挖好，赶紧把一些干草铺在陷井上，回去覆命了!!\n"NOR);
          return 1;
          }  
          write ("你挥起手中铁铲，在地上一下下挖了起来。\n");
          me->start_busy(1);
          me->add_temp("mark/挖陷井",1);
          return 1;
}