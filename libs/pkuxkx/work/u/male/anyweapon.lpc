// standard spear

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SPEAR;

void create()
{
        set_name( RED + "千面神兵" + NOR , ({ "any weapon","weapon" }) );
	set_weight(3000);
      set("value",1000000000);
	if ( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unique",1);
        set("long", "这是千面巫师曾经使用的神奇兵器,他现在是一杆长枪。你可以用rename改变它的名字!\n传说mudy还可以改变它的杀伤力(damage)、兵器种类,甚至变成盔甲(change)！\n传说福缘高的人会受到千面神兵的宠幸!\n");
		set("auto_load", 1);

                set("unit", "杆");
		set("material", "steel");
		set("rigidity", 300);
                set("wield_msg", MAG"忽然间$n"+MAG"如同通灵一般跃在$N"+MAG"手中!\n"NOR);
                set("unwield_msg", HIW"$N"+HIW"将"+"$n"+HIW"撤回身后。\n");
	}

        init_spear(3000);

	setup();
}
void init()
{
 add_action("rename","rename");
 add_action("change","change");
 add_action("damage","damage");
 add_action("do_wield","changewield");
 add_action("do_take","take");
}
int change(string arg)
{
if(arg=="sword")
{
				set("advance_skill","kaitian-jianfa");
                set("long", "这是巫师使用的神剑。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
                set("unit", "柄");
				delete("armor_prop");
				set("skill_type", "sword");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "thrust" }) );
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一把剑！\n"NOR,this_player());
}
else if(arg=="spear")
{
				delete("advance_skill");
				set("skill_type", "spear");
                set("unit", "杆");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一杆长枪！\n"NOR,this_player());
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust", "pierce", "impale" }) );
                set("long", "这是巫师使用的长枪。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
}
else if(arg=="club")
{
				delete("advance_skill");
				set("skill_type", "club");
                set("unit", "根");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
                set("long", "这是巫师使用的长棍。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄长棍！\n"NOR,this_player());
}
else if(arg=="dagger")
{
				set("advance_skill","cike-bi");
				set("skill_type", "dagger");
                set("unit", "支");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slice", "pierce", "thrust" }) );
                set("long", "这是巫师使用的匕首。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一把匕首！\n"NOR,this_player());
}
else if(arg=="fork")
{
				delete("advance_skill");
				set("skill_type", "fork");
                set("unit", "柄");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust" }) );
                set("long", "这是巫师使用的钢叉。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄钢叉！\n"NOR,this_player());
}
else if(arg=="halberd")
{
				set("advance_skill","huifeng-ji");
				set("skill_type", "halberd");
                set("unit", "杆");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "hack" }) );
                set("long", "这是巫师使用的长戟。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一只长戟！\n"NOR,this_player());
}
else if(arg=="hammer")
{
				set("skill_type", "hammer");
				set("advance_skill","tongbi-chui");
                set("unit", "柄");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
                set("long", "这是巫师使用的神锤。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄神锤！\n"NOR,this_player());
}
else if(arg=="pestle")
{
				delete("advance_skill");
				set("skill_type", "pestle");
                set("unit", "根");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust", "pierce", "impale" }) );
                set("long", "这是巫师使用的神杵。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄神杵！\n"NOR,this_player());
}
else if(arg=="staff")
{
				delete("advance_skill");
				set("skill_type", "staff");
                set("unit", "根");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
                set("long", "这是巫师使用的宝杖。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄宝杖！\n"NOR,this_player());
}
else if(arg=="throwing")
{
				delete("advance_skill");
				set("skill_type", "throwing");
                set("unit", "枚");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "throw" }) );
                set("long", "这是巫师使用的暗器。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一枚暗器！\n"NOR,this_player());
}
else if(arg=="whip")
{
				delete("advance_skill");
				set("skill_type", "whip");
                set("unit", "根");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "whip" }) );
                set("long", "这是巫师使用的神鞭。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一条神鞭！\n"NOR,this_player());
}
else if(arg=="xie")
{
				delete("advance_skill");
				set("skill_type", "xie");
                set("unit", "双");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "bash", "crush", "slam" }) );
                set("long", "这是巫师使用的神靴。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一双神靴！\n"NOR,this_player());
}
else if(arg=="axe")
{
				delete("advance_skill");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄宝斧！\n"NOR,this_player());
                set("unit", "柄");
				set("skill_type", "axe");
                set("long", "这是巫师使用的宝斧。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "chop", "slice", "hack" }) );
}
else if(arg=="blade")
{
				set("advance_skill","liuxingmingwang-daofa");
				set("skill_type", "blade");
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "slash", "slice", "hack" }) );
                set("long", "这是巫师使用的宝刀。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
                set("unit", "柄");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一柄刀！\n"NOR,this_player());
return 1;
}
else if(arg=="armor")
{
				unequip();
				delete("weapon_prop");
				set("armor_type", "cloth");
				set("armor_prop/armor",10000);
				delete("skill_type");
				delete("advance_skill");
				delete("actions");
				delete("verbs");
                set("long", "这是巫师使用的宝甲。你可以用rename改变它的名字!\n还可以用damage来改变它的杀伤力和用change 种类 改变它的种类！\n");
                set("unit", "件");
				message_vision(HIW"突然"+query("name")+HIW"在$N"+HIW"手中就变成了一件盔甲！\n"NOR,this_player());
}
else 
{
				write(HIY"change spear/club/dagger/fork/halberd/pestle/staff/throwing/whip/xie/axe/blade/armor\n"NOR);
}
				this_player()->reset_action();
return 1;
}
int damage(string arg)
{
		int damage;
        if( !arg || (arg!="none" && !sscanf(arg, "%d", damage)) ) 
            return notify_fail("指令格式：damage 杀伤力点数\n");
		unequip();
		set("weapon_prop/damage",damage);
		message_vision(HIB"$N"+HIB"将"+query("name")+HIB"的杀伤力改为"+damage+"\n"NOR,this_player());
		return 1;
}
int do_wield(string arg)
{
		message_vision(HIB"$N"+HIB"修改了装备"+query("name")+HIB"的描述\n"NOR,this_player());
        set("wield_msg", HIB+arg+NOR+"\n");
return 1;
}
int rename(string arg)
{
		message_vision(HIB"$N"+HIB"将"+query("name")+HIB"的名字改成"+HIR+arg+"\n"NOR,this_player());
		set("name",HIR+arg+NOR);
		return 1;
}
int wield(string arg)
{
 if (environment(this_object())->query("id")!="mudy"&&!this_player()->query("mudygranted"))
{
if(this_player()->query("kar")<40)
{
message_vision(HIW"$N一碰到"+this_object()->query("name")+this_object()->query("name")+HIW"就烟消云散了\n"NOR,this_player());
call_out("des",1,this_object());
return 1;
}
else
{
unequip();
if (query("weapon_prop/damage")>100)
{
message_vision(HIW"由于$N不是千面巫师,$N感到"+this_object()->query("name")+HIW"的杀伤力无法超过100！\n"NOR,this_player());
set("weapon_prop/damage",100);
}
::wield();
return 1;
}
}
::wield();
return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
object shen;
int exp,level,myexp,victim_exp,exp1;
	object weapon;
	me->add_temp("apply/damage",30);
victim_exp=victim->query("combat_exp");
if(victim_exp<1000)
{
exp1=victim_exp/10+1;
}
else if(victim_exp<10000)
exp1=victim_exp/90*19-111;
else if(victim_exp<100000)
  exp1=victim_exp/45+1778;
else if(victim_exp<1000000)
  exp1=victim_exp/225+3556;
else if(victim_exp<10000000)
  exp1=victim_exp/1125+7111;
else if(victim_exp<100000000)
  exp1=victim_exp/5625+14222;
else if(victim_exp<1000000000)
  exp1=victim_exp/28125+28444;
else
  exp1=victim_exp/140625+56889;
	if(!objectp(weapon=victim->query_temp("weapon")))
	{
		message_vision(query("name")+HIW"饮到$N的鲜血之后突然发出强烈的振动！\n......\n.....\n...\n..\n.\n"+query("name")+HIW"从$n手中闪电般的飞出，在$N留下了一个深可见骨的伤痕！\n\n"NOR+MAG+"$N"+MAG+"只觉自己身上一阵巨痛!\n\n"NOR,victim,me);
		victim->set("eff_qi",victim->query("eff_qi")/2);
		victim->set("qi",victim->query("qi")/2);
		victim->start_busy(10);
		if(victim->query("id")!=query("target_id"))
		{
			if(query("skill_type")!="xie") 
				me->improve_skill(query("skill_type"),1000);
			else
				me->improve_skill("force",1000);
			if(query("advance_skill")) 
			{
				tell_object(me,HIB"你在战斗中领悟到了"NOR+query("name")+HIB"中的无上武功－－－"+to_chinese(query("advance_skill"))+"!\n\n"NOR);
				me->improve_skill(query("advance_skill"),1000);
			}
			me->add("combat_exp",50);
			tell_object(me,HIR"\n你突然觉得"NOR+query("name")+HIR"让你的武功精进不少!\n\n"NOR);
			if((me->query("id")=="mudy"||me->query("mudygranted"))&&(victim->query("combat_exp")>me->query("combat_exp")))
			{
				me->add("combat_exp",exp1);
			}
		}
	}
	else if(weapon->query("unique"))
	{
		message_vision(HIW"\n$N的"+this_object()->query("name")+HIW+
						"与$n手中的"+weapon->query("name")+HIW+
						"相击，竟都安然无恙。\n\n"NOR,me,victim);
		if(victim->query("id")!=query("target_id"))
		{
			if(query("skill_type")!="xie") 
				me->improve_skill(query("skill_type"),1000);
			else
				me->improve_skill("force",1000);
			if(query("advance_skill")) 
			{
				tell_object(me,HIB"你在战斗中领悟到了"NOR+query("name")+HIB"中的无上武功－－－"+to_chinese(query("advance_skill"))+"!\n\n"NOR);
				me->improve_skill(query("advance_skill"),1000);
			}
		
			me->add("combat_exp",25);
			tell_object(me,HIR"你突然觉得"NOR+query("name")+HIR"让你的武功精进不少!\n\n"NOR);
			if((me->query("id")=="mudy"||me->query("mudygranted"))&&(victim->query("combat_exp")>me->query("combat_exp")))
			{
				me->add("combat_exp",exp1);
			}
		}
	}
	else
	{
		message_vision(HIW"突然"+query("name")+HIW"发出强烈的振动让人无法抑制！\n......\n.....\n...\n..\n.\n"+HIW"只听一声巨响之后，$N手中的$n和"+
			this_object()->query("name")+HIW+"刚刚一接触便被震成了一堆粉末！\n\n"NOR+MAG"$N"+MAG"大骇!\n\n"NOR,victim,weapon);
		weapon->unequip();
		weapon->move(environment(victim));
		weapon->set_name(HIY"粉末"NOR,({"fen mo","fen","mo"}));
		weapon->set("unit","堆");
		weapon->set("long",HIY"一堆黄色的粉末，将他捧在手心里可以感觉到它还是温温的!你感到这堆粉末中隐隐透出一种魔力!\n"NOR);
		weapon->set("value", 10000);
		weapon->set("weapon_prop", 0);
		call_out("weapondes",10,weapon);
		me->reset_action();
		if(victim->query("id")!=query("target_id"))
		{
			if(query("skill_type")!="xie") 
				me->improve_skill(query("skill_type"),1000);
			else
				me->improve_skill("force",1000);
			if(query("advance_skill")) 
			{
				tell_object(me,HIB"你在战斗中领悟到了"NOR+query("name")+HIB"中的无上武功－－－"+to_chinese(query("advance_skill"))+"!\n\n"NOR);
				me->improve_skill(query("advance_skill"),1000);
			}
			me->add("combat_exp",100);
			tell_object(me,HIR"你突然觉得"NOR+query("name")+HIR"让你的武功精进不少!\n\n"NOR);
			if((me->query("id")=="mudy"||me->query("mudygranted"))&&(victim->query("combat_exp")>me->query("combat_exp")))
			{
				me->add("combat_exp",exp1);
			}
		}
	}
	set("target_id",victim->query("id"));
	call_out("return_normal",60,me,this_object());
if(random(8)==0&&query("skill_type")=="sword")
{
shen=new("/u/male/summoned");
myexp=me->query("combat_exp");
if(myexp<100000000)
exp=myexp*2;
else
exp=myexp;
shen->set("combat_exp",exp);
if(myexp<100000)
 level=100;
else if(myexp<800000)
level=200;
else if(myexp<2700000)
level=300;
else if(myexp<6400000)
level=400;
else if(myexp<12500000)
level=500;
else if(myexp<21600000)
level=600;
else if(myexp<34300000)
level=700;
else if(myexp<51200000)
level=800;
else if(myexp<72900000)
level=900;
else if(myexp<100000000)
level=1000;
else
level=1200;
shen->set_skill("force",level);
shen->set_skill("strike",level);
shen->set_skill("xiake-strike",level);
shen->set_skill("dodge",level);
shen->set_skill("jiuyin-shengong",level);
shen->set_skill("xiake-shengong",level);
shen->set_skill("xiake-jianfa",level);
shen->set_skill("sword",level);
shen->set_skill("throwing",level);
shen->set_skill("xiake-shenfa",level);
shen->set_skill("strike",level);
shen->set_skill("parry",level);
shen->move(environment(me));
shen->kill_ob(victim);
me->start_busy(3);
victim->start_busy(3);
                return HIR "\n\n$N突然感到手中的神兵发出剧烈的抖动......\n\n"+HIY "一阵强光过后,一位鹤发童颜的老者出现在你的面前!\n "+ HIW "\n\n只见这位老者手持侠光剑,透出无边杀气,手中剑气咄咄逼人!\n\n"+HIB "他就是......................剑神!!\n\n" NOR;
}
    return HIR "\n" NOR;
}
void des(object jane)
{
destruct(jane);
return;
}
int do_take(string arg)
{
	object me,*players,anyweapon;
	me=this_player();
	if(me->query("id")!="mudy"&&me->query("id")!="male")
	{
		tell_object(me,"只有mudy和male才能使用这个命令！\n");
		return 1;
	}
	if(!arg)
	{
		players=users();
		for(int i=0;i<sizeof(players);i++)
		{
			if(players[i]->query("id")=="mudy"||players[i]->query("id")=="male") continue;
			if(objectp(anyweapon=present("any weapon",players[i])))
			{
				anyweapon->move(me);
				tell_object(players[i],HIW"天神"+me->query("name")+HIW"突然出现在你的面前对你说道："+anyweapon->query("name")+HIW"流落到凡间太久，现在必须收回！\n"+me->query("name")+HIW"刚一说完"+anyweapon->query("name")+HIW"就已经化成一道青烟不见了！\n"NOR);
				tell_object(me,HIW"你得到"+players[i]->query("name")+HIW"的"+anyweapon->query("name")+"!\n"NOR);
				i--;
			}
		}
	}
	return 1;

}

string query_autoload()
{
	return query("name");
}

void autoload()
{}

int return_normal(object ppl,object ob)
{
//        ppl->add_temp("apply/attack",-30);

//        ppl->add_temp("apply/dodge", -30);
	ppl->add_temp("apply/damage",-30);
	return 1;
}
int weapondes(object weapon,string anyweapon)
{
	message("vision",HIW"一阵风吹来，将地上的一堆粉末吹得无影无踪了!\n"NOR,environment(weapon));
	destruct(weapon);
	return 1;
}
