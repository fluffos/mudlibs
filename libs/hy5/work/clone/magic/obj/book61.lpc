// 属性检测卷轴

#include <ansi.h>
inherit ITEM;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

void create()
{
        set_name(HIY"属性检测卷轴"NOR, ({ "dele axes", "1axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个魔法卷轴可以使用(spell id)上面的魔法。\n") ;

                set("unit", "个");
                set("value", 30000);
                set("zhen", 3);
        }
        setup();
}

void init()
{
        add_action("do_shot","spell");
}

int do_shot(string arg)
{
        object me,ob,target;
        int myskill , tgskill;
        int mylev ,damage;

        me = this_player();

 	if (!id(arg))
	return notify_fail("你要使用什么卷轴？\n");
        if( !arg ) return notify_fail("你想对谁使用属性检测卷轴？\n");

      if( !target ) target = offensive_target(me);

      if( !target || !target->is_character() || !me->is_fighting(target) )
              return notify_fail("属性检测卷轴只能对战斗中的对手使用。\n");

        if( !target->is_character() || target->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");



if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("魔法不是用来对付弱小玩家的！\n");

        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"上的魔法力量用完了!  $N"HIY"消失了。\n"NOR,this_object(),target);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("dele axes", me)) )
                return notify_fail("你没有这种东西。\n");

        message_vision(HIY"\n$N"HIY"突然发光  探测光波动!!  一道白光打向$n。\n"NOR,this_object(),target);
if ((int)target->query("magicgift")==1)
tell_object(me, HIR"\n敌人的能量属性是火。\n" NOR);
if ((int)target->query("magicgift")==2)
tell_object(me, HIW"\n敌人的能量属性是水。\n" NOR);
if ((int)target->query("magicgift")==3)
tell_object(me, HIC"\n敌人的能量属性是气。\n" NOR);
if ((int)target->query("magicgift")==4)
tell_object(me, YEL"\n敌人的能量属性是土。\n" NOR);
if ((int)target->query("magicgift")==5)
tell_object(me, BLK"\n敌人的能量属性是暗。\n" NOR);
if ((int)target->query("magicgift")==6)
tell_object(me, HIY"\n敌人的能量属性是光。\n" NOR);
if (!target->query("magicgift"))
tell_object(me, HIG"\n敌人没有能量属性。\n" NOR);

        this_object()->add("zhen", -1);
        me->start_busy(1) ;
        return 1;
}
