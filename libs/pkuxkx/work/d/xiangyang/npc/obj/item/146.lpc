#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( YEL "洋枪" NOR, ({ "gun"}) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把七寸长的西洋货，威力可不小．\n");
                set("material", "silver");
                set("no_sell",1);
        }
        setup();
}
void init()
{
	add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
	object ob;
	object me;
	int dp;
	int damage;
	if (!arg) return notify_fail("你要打谁？\n");
	if (query("used")) return notify_fail(this_object()->name()+"只有一颗子弹．\n");
	me=this_player();
    if( environment(me)->query("no_fight") 
      	)
	return notify_fail("在这不可偷袭！\n");
    ob=present(arg,environment(me));
      if(ob==me) return notify_fail("我建议你还是用suicide -f\n");
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"只能对活的生物使用\n");
    message_vision("$N阴笑一声，从怀里摸出一件东西．．\n",me);
    message_vision("$N对着$n举起了手中的"+this_object()->name()+"...\n",me,ob);
if(random(2)!=1) {message_vision(RED "糟了,你的洋枪 卡壳了!\n",me);
ob->kill_ob(me);
return 1;}
    message_vision(YEL "一声震耳欲聋的枪声响起．．．...\n" NOR,me);
     message_vision(RED "$n身上喷出一股鲜红的血柱.....\n" NOR,me,ob);
    dp=COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
    damage=10*ob->query("dex",1)+ob->query_skill_eff_lvl("dodge",1);
 damage=(random(2)+1)*(random(2*(1000-damage))+1000);
    if (damage<0) damage=0;
    ob->add("qi",-1*damage);    
    ob->kill_ob(me); 
    set("used",1);
    me->start_busy(3);
      destruct(this_object());
    return 1;
}
