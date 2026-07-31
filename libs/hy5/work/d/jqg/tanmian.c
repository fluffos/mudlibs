// tanmian.c

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", HIC"水潭表面"NOR);
    set("long", @LONG
你双手划水，漂浮在一片水面上面。你只觉阳光耀眼，水面上花香扑鼻，
竟是别有天地。
LONG
        );
   
    set("outdoors", "绝情谷");

    setup();
}

void init()
{
       object me;
       me=this_player();
       add_action("do_qian","qian");
       add_action("do_pa", "pa");
}

int do_qian(string arg)
{
	object me;
       	me=this_player();
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
       	if ( !arg || arg != "down"  )
       		return notify_fail("你要往哪里潜？\n");
       if (arg =="down"){
  	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() <= 50) 
           return notify_fail("由于重力不够，你无法继续下潜!\n");
          message_vision(HIG"$N一个猛栽，潜了下去。\n"NOR, me);
          me->receive_damage("jing", 50);
          me->receive_damage("qi", 50);
          me->move(__DIR__"tongdao");
          tell_room(environment(me), me->name() + "从上面潜了下来。\n", ({ me }));
          message_vision (HIB"$N只觉得头晕晕的，身体浸在冰冷的水中，不住的颤抖。\n"NOR,me);
          return 1;
       	  }
     return 1;
}
 
int do_pa(string arg)
{
	object me;
	int i;
	object who;
       	me=this_player();
       	who=me;
       	if ( !arg || arg != "up")
       		return notify_fail("你要往哪里爬？\n");
       	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
        message_vision(YEL"$N往水潭岸边爬了上去。\n"NOR, me);

  	if((int)who->query("jinyong/book10")==6 && who->query_temp("book51071"))
{
tell_object (who,"你发现了绝情谷底的秘密！\n");
		i = 1800+random(3000);
		who->set("jinyong/book10",7);
		who->add("combat_exp",i+18000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"胆色过人，义惩青城恶霸。");
		tell_object (who,"你赢得了"+chinese_number(i+18000)+"点经验"+
		           chinese_number(i*18)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
		who->save();
}

	me->move(__DIR__"tanan");
	tell_room(environment(me), me->name() + "从水潭中落汤鸡似的爬了上来。\n", ({ me }));
	return 1;
}
