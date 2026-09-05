// lingwu.c
// 把达摩院的领悟命令抽出来变成本地，为以后扩展方便考虑。zine@pkuxkx 2013/2/28
#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/skill/study_class_benefit.h"
//string *legal_lingwu_place=({"/d/shaolin/dmyuan2",});
string *adv_weapon=({"sword","blade","whip","staff","dagger","axe","halberd","spear","hammer","throwing"});
int main(object me,string arg)
{
  object where = environment(me);
  string skillname,arg2, lfam;
  int skill, skill_basic;
  int imp_skill;
  int cost;
  int lingwu_times;
  seteuid(getuid());
//  if (member_array(base_name(where),legal_lingwu_place)==-1)
//  return 0;
  
  if ( stringp(lfam=where->query("lingwu_family")) )
  {
    if ( !me->query("family/family_name") &&
         lfam!="百姓" )
      return notify_fail("你并没有门派，只能去武馆里参悟自己已学的武学。\n");
    
    if ( me->query("family/family_name") &&
         me->query("family/family_name")!=lfam )
      return notify_fail("你只能去自己门派的相应场所参悟自己所学的武学。\n");
  }
  else
    return 0;
  
  if ( !me->query("luohan_winner") )
    return notify_fail("你还没有过阵，无法在这里领悟更高深的武学。\n");
  
  if (where->query("pigging"))
    return notify_fail("你还是专心拱猪吧！\n");
  
  if (me->is_busy())
    return notify_fail("你现在正忙着呢。\n");
  
  if( me->is_fighting() )
    return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");
  
  if( !arg ) return notify_fail("领悟什么？\n");
  
  arg2=arg;
  if(sscanf(arg2,"%s %d",arg,lingwu_times)!=2) 
  {
    arg=arg2;
    lingwu_times=1;
  }
  
  if (lingwu_times < 1) return notify_fail("你至少要领悟一次！\n");
  
  if (lingwu_times>100) return notify_fail("你至多领悟一百次！\n");
  
  skill_basic = me->query_skill(arg, 1);
  
  if( skill_basic < 1 )
    return notify_fail("你还没学过这项技能吧？最好先去请教别人。\n");
  
  if( !stringp(skillname = me->query_skill_mapped(arg)) )
    return notify_fail("你只能领悟 enable 了高级技能的基本技能。\n");
  
  skill = me->query_skill(skillname, 1);
  cost=20;
  if( skill_basic > skill)
    return notify_fail("你的基本功夫比你的高级功夫还高！\n");
  
  if (me->query("jing") < cost)
    return notify_fail("你现在过于疲倦,无法静下心来领悟功夫！\n");
  
  if ( (me->query("jing")/cost)<lingwu_times)
    lingwu_times = me->query("jing")/cost;
  
  imp_skill = random((int)me->query_int()/4)+1;
  imp_skill = imp_skill * SPEWEEK_D->query_lingwu_bonus()/100; //special week effect
  if (member_array(arg,adv_weapon)!=-1)
  {
    if (me->query("adv_weapon/class/"+arg+"/lv")>=8)
      imp_skill=imp_skill/4*5;
    if (me->query("adv_weapon/class/"+arg+"/lv")>=11)
      imp_skill=imp_skill/4*5;
  }
  
  me->improve_skill(arg,benefit(me,imp_skill*lingwu_times));
  me->receive_damage("jing", cost*lingwu_times );
//  message_vision("$N领悟了" + chinese_number(lingwu_times) + "次" + to_chinese(arg) + "。\n", me);
  tell_object(me,"你领悟了" + chinese_number(lingwu_times) + "次" + to_chinese(arg) + "。\n");  
  return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : lingwu <技能> <次数>

这个指令可以让你在特定地点领悟提高基本武功，比如过阵以后在达摩院二层领悟。

HELP
         );
    return 1;
}

