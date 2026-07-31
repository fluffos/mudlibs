//modified by hanchat@txwx2005
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

//inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
int do_study(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIW"圣灵珠"NOR, ({"sheng lingzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "crystal");
                set("value",10000);
set("no_steal",1);
                set("no_drop", "如此宝贵的宝物再世难求啊。\n");
                set("no_get", "送人？亏你想的出来！\n");
//                set("no_give", "这种稀世之宝怎么能轻易送人呢?\n");
                set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","天地初开时，清者归于上，浊者归于下；有一种半清半浊归于中，是为此宝!
因此五行皆为其子。/n五颗灵珠合为一体的圣灵珠,似乎触摸(touch)之下会发生奇特的变化。\n");
//                set("replace_file", "/d/obj/flower/rose");
                set("armor_prop/armor", 1);
                set("spells/fire", 1);
                set("spells/thunder",1);
                set("spells/water",1);
                set("spells/wind",1);
                set("spells/earth",1);
        }
        setup();
}

int init()
{
        object who = this_player();
/*        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 800000 )
        this_object()->move("/obj/empty"); 
         }
*/
//modified by hanchat@txwx2005
	 add_action("do_study","touch");
        add_action("do_wear","wear");
        add_action("do_remove", "remove");

}

// This function selects a random target for offensive spells/functions.
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

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "sheng lingzhu" )
    return notify_fail("你要佩带什么？\n");
  msg = "$N戴上一颗"+name+"，顿感神清气爽。\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "sheng lingzhu")
    return notify_fail("你要摘掉什么？\n");

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIR"圣灵珠五彩毫光猛然四射，刹时风雨雷电齐至，山崩地裂！\n"NOR;
//divid by 10;

                ap = who->query("combat_exp");
                dp = target->query("combat_exp");
                        
                        
                if( random(dp) < ap/2 )
                 {
                        damage = 500+random(300)+who->query_skill("xianfeng-spells", 1);
                        damage -= random((int)target->query("eff_jing") / 100);

                        if( damage > 0 ) 
                        {
                                msg += HIC "结果$n躲避不及，被雷电劈个正着，又被地火烧得皮焦骨烂。\n
被山石砸得皮破血流，还被风迷了双眼，又被水浇个透心凉，肌肤尽裂。\n" NOR;

                                target->receive_damage("jing", damage*8/5);
                                target->receive_wound("jing", damage*2/3);
                                target->receive_damage("qi", damage*8/5);
                                target->receive_wound("qi", damage/2);
                                target->start_busy(5);
				    ob->add("use_times", 1);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n谁知$n毫无反应。\n" NOR;   
                }
                else
                        msg += "但是被$n躲开了。\n";

                message_vision(msg, who, target); 
        }
if(ob->query("use_times")>15)
{
message_vision("$N手中的圣灵珠突发七彩之光，一道霞光过后便失去了颜色。\n", who, target); 
remove_call_out("shengzhuconditions");
}
else
call_out("shengzhuconditions",30,who,ob);
}


int do_study(string arg)
{
	object me,pearl;
	int i;
	me=this_player();

	if( !arg || (arg!="ling zhu"
			&& arg!="zhu"
			&& arg!="pearl") )
		return notify_fail("你要摸什么？\n");

	if( (int)me->query_skill("xianfeng-spells",1) < 100)
		return notify_fail("你的仙风云体术不够，还感受不到灵珠内的魔力。\n");
	if( (int)me->query_skill("xianfeng-spells",1) >= 500)
		return notify_fail("你的仙风云体术过高，灵珠内的魔力以对你豪无作用了。\n");
	if( (int)me->query_skill("taoism",1) < 500)
		return notify_fail("你的法术休养不够，还领悟不到灵珠内的魔力。\n");
	if( (int)me->query("qi") < 500)
		return notify_fail("你的气血不足，再练会晕倒过去。\n");
	if( (int)me->query("jing") < 500)
		return notify_fail("你的精神不济，再练会昏迷过去。\n");
	if( (int)me->query("neili") <50000)
		return notify_fail("你的内力不足，再练有害无益。\n");

	message_vision("$N双手轻握$n，只见几缕淡淡霞光流入掌中。\n",me,this_object());
	me->improve_skill("xianfeng-spells", random( (int)me->query_int()/4 )+10+random(10) );
	me->receive_damage("qi",30+random(300));
	me->receive_damage("jing",30+random(300));
	me->add("neili",-500-random(500));
	me->start_busy(2+random(5));

	write("你对仙风云体术的领悟似乎又深了一层。\n");
	return 1;
}



void owner_is_killed()
{
write(HIY"只见眼前金光一闪....圣灵珠突然破裂了!\n"NOR);
destruct(this_object());
}