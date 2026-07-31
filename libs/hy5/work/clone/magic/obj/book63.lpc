// 圣光壁卷轴

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
        set_name(HIY"圣光壁卷轴"NOR, ({ "lfield axes", "63axes" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一个魔法卷轴可以使用(spell id)上面的魔法。\n") ;

                set("unit", "个");
                set("value", 140000);
                set("zhen", 1);
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
	return notify_fail("你无法使用这个卷轴!\n");

        if(me->is_busy() )
                return notify_fail("你正忙着哪。\n");

        if( me->query("combat_exp")< 500000)
        return notify_fail("你的经验太少用不了！\n");


	
        if(me->query("magicgift")==6 )
                return notify_fail("你已经是光属性了!!\n");

        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"上的魔法力量用完了!  $N"HIY"消失了。\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        if( !objectp(ob = present("lfield axes", me)) )
                return notify_fail("你没有这种东西。\n");

        message_vision(HIY"\n$N"HIY"的附近形成了光之盾牌!!   $n被圣光包围了。\n"NOR,this_object(),me);
        me->set("magicgift",6);
        this_object()->add("zhen", -1);
        me->start_busy(1) ;
        if( this_object()->query("zhen") < 1 ) {
        message_vision(HIY"\n$N"HIY"上的魔法力量用完了!  $N"HIY"消失了。\n"NOR,this_object(),me);
        destruct(this_object());
return 1;
                }

        return 1;
}
