// /d/wudang/shanya2.c  山崖

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","山崖");
        set("long", @LONG
这是一面陡峭的山崖，石壁平滑如镜，光可照人，山风刮得脸如刀割，崖
下深不见底，令人胆寒。
LONG);
	set("outdoors", "武当");
        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
}

int do_pa(string arg)
{       object me,tmp;
        object *ob;
        int i;
        me=this_player();
        if ( !arg ||( (arg != "down") && ( arg != "up") ) )
            return notify_fail("你要往哪爬？\n");
        if (! present("sheng zi", this_player()))
            return notify_fail("没有支撑点，你怎么爬？\n");

        if (arg =="down") {
           message_vision("$N颤颤噤噤地爬了下去。\n", me);
           if ((int)me->query_skill("force", 1) < 20) {
            message_vision(RED"山风突然转强，$N功力不够，无法稳住身体，一阵摇晃，又被吹了回去。\n"NOR, me);
            message_vision(HIR"$N心里一急，一口气转不过来顿时昏了过去。\n"NOR, me);
            me->unconcious();
            return 1;
           }
           me->receive_damage("jing", random(20));
           me->add("neili", (int)me->query_skill("force", 1)/20-60);
           me->move(__DIR__"shanya3");
	tell_room(environment(me), me->name() + "从上面爬了下来。\n", ({ me }));
        }
        else
          {message_vision("$N颤颤噤噤地爬了上去。\n", me);
           me->add("neili", -random(20));
           me->receive_damage("jing", 60-(int)me->query_skill("dodge", 1)/20);
           if ((int)me->query_skill("dodge",1)<180)
              me->improve_skill("dodge", me->query("dex")+random((int)me->query_skill("dodge",1)/10));
           me->move(__DIR__"shanya1");
	tell_room(environment(me), me->name() + "从下面爬了上来。\n", ({ me }));
          }
        if ((int)me->query("jing", 1)<0||(int)me->query("neili", 1)<0)
         {
            message_vision(RED"$N突然眼冒金星，摇摇欲坠。脚下一打滑，[啊...]，一跟头栽下了万丈深谷。\n"NOR, me);
            me->set_temp("last_damage_from","摔下山崖跌");
            me->unconcious();
            me->die();
		if (tmp = present("corpse", this_object())) {
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
                        destruct("corpse");
                        if (me) tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
		}
         }

     return 1;
}
