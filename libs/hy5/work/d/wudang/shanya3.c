// /d/wudang/shanya3.c  山崖

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","山崖");
        set("long", @LONG
这是一面陡峭的山崖，石壁平滑如镜，光可照人，山风刮得脸如
刀割，崖下深不见底，令人胆寒。你的绳子已放尽了，四周仍无可以
落脚的地方，离脚下几十丈处有棵万年松，枝叶茂密，型如圆桌。冒
险下跳，借物滑翔，也许能落在树上。
LONG                           
);
	set("outdoors", "武当");
        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_jump",({ "tiao", "jump" }));
}

int do_pa(string arg)
{       object me,tmp;
        object *ob;
        int i;
        me=this_player();
        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("你要往哪爬？\n");
        if (! present("sheng zi", me)) 
            return notify_fail("没有支撑点，你怎么爬？\n");

        if (arg =="down")
            return notify_fail("你已无法再往下爬了。\n");

        message_vision("$N颤颤噤噤地往上爬。\n", me);
        me->add("neili", -random(20));
        me->receive_damage("jing", 60-(int)me->query_skill("dodge", 1)/20);
        me->move(__DIR__"shanya2");
	tell_room(environment(me), me->name() + "从下面爬了上来。\n", ({ me }));
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

int do_jump(string arg)
{       object me, tmp;
	object *ob;
	int i;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("你要往哪跳？\n");
        message_vision("$N双手一松，朝准松树奋力跳下。\n"NOR, me);
	if (present("sheng zi", me))
           destruct(present("sheng zi",me));

        if (! present("mao tan", me))
          { 
            message_vision("$N象一铁秤砣般迅速下落，瞬间就到了松树边，连忙深手去抓，却发现差了几寸。\n"NOR, me);
            message_vision(RED"啊---，$N一声惨叫，直往万丈深谷落去。\n"NOR, me);
            me->set_temp("last_damage_from","摔下山崖跌");
            me->die();
		if (tmp = present("corpse", this_object())) {
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
			if (me) tell_room(this_object(), me->name()+"的尸骨都找不到了。\n");
		}
            return 1;
          }
        message_vision(HIY"$N人在空中，连忙把毛毯展开，顿时象长了翅膀般轻飘飘地朝松树落去。\n"NOR, me);
        me->move(__DIR__"wanniansong");
	tell_room(this_object(), me->name() + "飞了过来。\n", ({ me }));
     write(HIY"你终于安全着陆。\n"NOR);
	return 1;
}
