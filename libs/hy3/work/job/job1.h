#include <ansi.h>

mixed names = ({
	({
        "打手",
        }),
        ({
        "莫声谷",
        }),
        ({
        "张松溪",
         }),
        ({
          "俞岱岩",
        }), 
        ({
          "殷梨亭","莫声谷",
      }),
     });

void init()
{
        add_action("do_jie", ({"xian","jie"}));
     
}

int do_jie(string arg)
{
	object me;
	string  target;
	int exp, position;

	if(!arg) return 0;
	me = this_player(); 
	exp=(int)me->query("combat_exp"); 

	if(arg != "wenshu" && arg != "wen") return 0;

	if(me->query_condition("gb_mission") || me->query_condition("gb_busy") || me->query_condition("xx_task"))
		return notify_fail("你现在正忙着做其他任务呢！\n");
	if(me->query_condition("guanfu_task"))
		return notify_fail("你已经揭过榜了，难道不想做了？！\n");
	if(me->query_temp("guanfu_task"))
		return notify_fail("你已经揭过榜了，现在可以通过(guankai)来查询。\n");
    if(exp<40000)
		return notify_fail("你刚想伸手，忽然看到上面凶神恶煞的画像，想了想觉得自己的这点功夫，还是算了吧。\n"); 
	if(exp>=700000) position=5;
	else if(exp>=300000) position=4;
	else if(exp>=100000) position=3;
	else if(exp>=50000) position=2;
	else position=1;

	target = names[position-1][random(sizeof(names[position-1]))]; 
	tell_room(this_object(),
		HIY + me->name()
		+ "推开围观的行人，走到近前,微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR, ({ me }));
	write(HIY"你推开围观的行人，走到近前,微微睁开眼睛，冷冷瞥了一眼告示，随手揭了下来揣进了怀中。\n"NOR);
	new("/u/dubei/job/wenshu1")->move(me);

	me->set_temp("guanfu_target", target);
	me->apply_condition("guanfu_task", me->set_temp("guanfu_time", random(10)+10));
	return 1;
}
