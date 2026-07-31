#include <ansi.h>
inherit ROOM;
int do_zhuan(string arg);
int do_jiao(string arg);
int do_suo(string arg);
void create()
{
        set("short", "机关室");
        set("long", @LONG 
这是一个方广仅十步的小室,小室中央处有个水井般的设施，
井上有个大绞盘，盘上卷有一小截粗如儿臂的铁链!
LONG );
        set("objects", ([
                 ]));

               set("exits", ([
                                
        ]));

//      set("no_clean_up", 0);
        setup();
}
void init()
{
  object me = this_player();
        add_action("do_zhuan", "zhuan");
        add_action("do_jiao", "jiao"); 
        add_action("do_suo", "suo");
}

int do_zhuan(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("你要住转动什么东西!\n");
            if( arg=="绞盘" ) {
write(HIB"转动绞盘，盘上的铁链不断增多。另一端显然连系着轮轴一类的\n"
HIB"布置，只容他们逐分逐寸的把链子绞(jiao)上来。\n"NOR);
             this_player()->set_temp("jiaopan", 1);
             return 1;
       }
}

int do_jiao(string arg)
{
        object me;
        me = this_player();
      if( !me->query_temp("jiaopan")) return 0;
      if( !arg || arg=="" ) return notify_fail("你要绞动什么东西!\n");
            if( arg=="链子" ) {
write(HIR"只听到「卡」的一声!!链子再绞不动了。\n"NOR);
             this_player()->set_temp("suolian", 1);
 me->delete_temp("jiaopan");
             return 1;
       }
}

int do_suo(string arg)
{
        object me;
        me = this_player();
      if( !me->query_temp("suolian")) return 0;
           if( arg=="链子" ) {
write(HIR""+me->name()+"忙把链子锁好!\n"NOR);
  call_out("on_qidong", 3);
   return 1;
       }
}

void on_qidong(object room)
{
message_vision(HIB"好半晌後，脚下深处忽然传来如闷雷般「隆隆」异响!宝库的开关终於启动。\n"NOR, this_player());
message_vision(HIR"分隔西南轴和东北轴的两扇连锁活壁同时开启，现出通往东区宝库的秘道。\n"NOR, this_player());
        set("exits/east", __DIR__"baokudt");
this_player()->delete_temp("suolian");
 call_out("on_guanmen", 5);

}

void on_guanmen(object room)
{
      message_vision(HIG"突然出现咔咔的响声，钢门又合上了!\n"NOR, this_player());
delete("exits/east");
}



