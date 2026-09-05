// displace.c
// yhzzyahoo@pkuxkx 2017/5/11
//遁形：类似于displace效果，busy中跑到另外一个房间去，需要布阵，发动前判定sk，(玩家sk*布阵叠加buff)，一般2,3次以后100%，
//如果参数时间超过busy时间，则成功跑到隔壁房间
#include <ansi.h>
#include <skill.h>
/*#define interval 15
#define vein "足太阴脾经"
#define STUNT "displace"*/
inherit F_CLEAN_UP;
mapping default_dirs = ([
        "north":        "北",
        "south":        "南",
        "east":         "东",
        "west":         "西",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上",
        "down":         "下",
		"enter":        "里",
        "out":          "外",
]);

int main(object me,string arg)
{
	int busy_d=0;
	object env,target;
	object *enemy;
	string dir;
	int d_temp1,d_temp2;
	if (me->query("family/family_name")!="桃花岛" || !me->query("safari_skill/thd_dunxing"))
	return notify_fail("你还没有掌握遁形绝技。\n");
	if (!me->query_temp("active_buffer/qimen-baguazhen.buzhen"))
	{
		return notify_fail("你都没布阵，凭啥遁形。\n");
	}
	if (!env=environment(me))
	return notify_fail("都在这里了，还是老老实实待着吧。\n");
	if (!me->is_busy())
	return notify_fail("你要走就走过去好了，还要用什么遁形？\n");
	if (!me->is_fighting())
	return notify_fail("你没在战斗啊，要走就走过去好了，还要用什么遁形？\n");
	if (time() < me->query_temp("qmbgz.dunxing_cdtime"))
	return notify_fail("你刚刚使用过遁形，等等再用吧。\n");
	
	enemy = me->query_enemy();
	target = enemy[0];
	d_temp2 = me->query_temp("active_buffer/qimen-baguazhen.buzhen/cengshu");
	d_temp1 = me->query_skill("parry",1)*d_temp2;
	if (F_KUNGFU->hit_rate(d_temp1, (int)target->query_skill("parry",1), 6, me, target))
	{

		busy_d = me->query("dex")-10;

		if (busy_d > 30)
		{
			busy_d = 30;
		}

		busy_d *= d_temp2;//可以闪躲的时间判断
	//	write("你的逃跑提前时间为："+busy_d+",你现在还busy:"+me->query_busy()+"\n");
		d_temp2=3;
		if (me->query("chushi/done")||me->query("betrayer"))
		{
			d_temp2=5;
		}
		dir=keys(env->query("exits"))[random(sizeof(env->query("exits")))];
		message_vision(HIW+"$N"+HIW+"借助阵型掩护，身形左绕右闪，躲向了"+default_dirs[dir]+"方位。\n"+NOR,me);
		if (me->query_busy() > busy_d||!env->valid_leave(me,dir))
			write("很可惜，你没有能成功遁逃开去。\n");
		else if (!me->move(env->query("exits")[dir]))
			write("很可惜，你没有能成功遁逃开去。\n");
		me->set_temp("qmbgz.dunxing_cdtime",time()+d_temp2);
		return 1;
	}
	else
	{
		return notify_fail("你左躲右闪在原地就没能动弹。\n");
	}

}
