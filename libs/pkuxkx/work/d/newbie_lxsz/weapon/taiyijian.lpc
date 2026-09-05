//Cracked by Roath
// longsword.c 长剑

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
#include "../newbie_village.h"

int do_enable(string);
int do_lian(string);
int do_prepare(string);
int do_pfm(string);

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
	set_name("太乙剑", ({ "taiyi jian", "jian", "sword"}));
	set_weight(5000);

	if (clonep())
		set_default_object(__FILE__);
	else
    {
        set("unit", "柄");
        set("long", "这是一柄只有太乙学徒才能使用的长剑。\n");
        set("value", 250);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        set("no_drop",1);
        set("no_get",1);
    }
	init_sword(15);
	setup();
}

void init()
{
    add_action("do_lian", "lian");
    add_action("do_lian", "practice");
    add_action("do_pfm", "perform");
    add_action("do_enable","enable");
    add_action("do_enable","jifa");
    add_action("do_prepare","prepare");
    add_action("do_prepare","bei");
}

int do_lian(string arg)
{
    object who,ob;
    string failmsg;
    who=this_player();
    ob=this_object();
    
    if (0==call_other("cmds/skill/practice","main",who,arg))
    {
        if (stringp(failmsg=query_notify_fail()))
        {
            tell_object(who,failmsg);
            return 1;
        }
    }

    if (6==who->query_skill("taiyi-jian",1) && 0==who->query("newbie_village/pfm")) //临时调试设为5，正常应为6
    {
        who->set("newbie_village/pfm",1);
        tell_object(who,HIC"你颇有慧根，竟悟出了太乙剑法的绝招之一：八方风雨！\nperform sword.bafang 即使用太乙剑法的绝招：八方风雨\n"NOR);
        ob->set("long", "这是一柄只有太乙学徒才能使用的长剑。\n"+HIC"目前你可以使用太乙剑法的绝招：八方风雨(perform sword.bafang)\n"NOR);
        set_nextquest(who,"练习一级太乙剑法，学会用太乙剑法的一个绝招","你握了握手中的剑，感觉自己有点功夫了，去找找游鲲翼，再向他打听闯荡江湖的事！", 20, 100);
    }
	return 1;
}

int do_enable(string arg)
{
    object who;
    string *skill,failmsg;
    mapping map;
    who=this_player();
   
    if (0==call_other("cmds/skill/enable","main",who,arg))
    {
        if (stringp(failmsg=query_notify_fail()))
        {
            tell_object(who,failmsg);
        }
    }
    
    map = who->query_skill_map();
	if (5==sizeof(map))
    {
        set_nextquest(who,"激发内功为太乙神功、轻功为太乙轻功、掌法为太乙掌法、剑法为太乙剑法、招架为太乙剑法","基本功夫是准备好了，还要再准备一下主用空手招式\nbei taiyi-zhang\n", 20, 100);
    }

    return 1;
}

int do_prepare(string arg)
{
    object who;
    string *skill,failmsg;
    mapping map;
    who=this_player();
    
    if (0==call_other("cmds/skill/prepare","main",who,arg))
    {
        if (stringp(failmsg=query_notify_fail()))
        {
            tell_object(who,failmsg);
            return 1;
        }
    }

    map=who->query_skill_prepare();
	if(mapp(map))
	{
		skill=keys(map);
		
		if (1==sizeof(skill) && skill[0]=="strike")
		{
			set_nextquest(who,"指定平时要用的空手技能-太乙掌法","你学会新功夫，欣喜若狂，迫不及待要和人过招了！\n再和武师过过招试试！\n", 20, 100);
		}
	}
  return 1;
}

int do_pfm(string arg)
{
    object who,ob,target_ob,weapon;
    string martial,target,pfm_id;
    int cd;
    who=this_player();
    ob=this_object();

    if( !arg || sscanf(arg, "%s.%s", martial, arg)!=2 )
    {
        tell_object(who,"指令格式 perform sword.bafang");
        return 1;
    }
    else 
    {
        if( sscanf(arg, "%s %s", pfm_id, target)==2 ) 
        {
            target_ob = present(target, environment(who));
            if( !target_ob ) 
            {
                tell_object(who,"这里没有这个人。\n");
                return 1;
            }
        }
        else 
        {
            pfm_id=arg;
            target_ob = offensive_target(who);
        }
    }

    if( !target_ob || !target_ob->is_character() || !who->is_fighting(target_ob) )
    {    
        tell_object(who,"八方风雨只能对战斗中的对手使用。\n");
        return 1;
    }

    if (martial=="sword" && who->query_skill_mapped("sword")=="taiyi-jian" && pfm_id=="bafang" )
    {
        if (0==who->query("newbie_village/pfm"))
        {
            tell_object(who,"你还没有领悟八方风雨的真谛。\n");
            return 1;    
        }
        weapon = who->query_temp("weapon");
        if( !weapon || !objectp(weapon) || weapon->query("skill_type") != "sword" )
        {
            tell_object(who,"你手中无剑，如何使得「八方风雨」绝技？\n");
            return 1;
        }
        if( !living(target_ob) )
        {
            tell_object(who,"你现在不必使用「八方风雨」绝技。\n");
            return 1;
        }
        if (1==who->query_temp("newbie/pfmcd"))
        {
            tell_object(who,"你刚使用过「八方风雨」绝技，现在还无法使用。\n");
            return 1;

        }
        message_vision(HIC"$N捏了个剑诀，脚踩巽位，以应风势，忽然$N的剑尖以暴雨狂风之速点向$n全身！\n正是“天通八风，地应八卦”的精要！\n"NOR,who,target_ob);
        if (who->query("combat_exp") > random(target_ob->query("combat_exp")))
        {
            cd=who->query_skill("sword",1);
            who->set_temp("newbie/pfmcd",1);
            target_ob->start_busy(cd/2+random(cd/2));
            call_out("remove_cd",cd+1,who);
            message_vision("$N使出此招完全出乎$n意料之外，竟然不知闪避，中了一剑！\n",who,target_ob);
			target_ob->receive_damage("qi",10+random(10));
			target_ob->receive_wound("qi",10+random(10));
			COMBAT_D->report_status(target_ob,0);
        }
        else
        {
            who->set_temp("newbie/pfmcd",1);
            call_out("remove_cd",1,who);

            message_vision("$n侥幸躲过了$N的「八方风雨」绝技。\n",who,target_ob);
        }
        return 1;
    }
    return 0;

// 你捏了个剑诀，脚踩巽位，以应风势，忽然你的剑尖以暴雨狂风之速点向武师全身！

// 正是“天通八风，地应八卦”的精要！

// 武师见你悟出此招惊呆了。

}

void remove_cd(object who)
{
	if (!objectp(who)) return;
    who->set_temp("newbie/pfmcd",0);
}

