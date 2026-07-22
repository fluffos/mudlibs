//  skill.c
//rewrite by lonely@yxcs
//  This is the standard skill daemon object. All objects defining a skill
//  should inherit this as its skeleton.
#include <ansi.h>
inherit F_SSERVER;
void create()
{
    seteuid(getuid());
}
//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.
int valid_learn(object me) { return 1; }     // 允许学
// 
// type()
//
// This function should return the type of the skill. The skill type now
// affects if the skill requires combat exp in order to be learned (see
// /cmds/std/learn.c ) and the ranking of a skill level (see 
// /cmds/usr/skills.c )。
// Currently we have only 2 types of skill: "martial" and "knowledge".
string type() { return "martial"; }
//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.
void skill_improved(object me) {}      // 当该skill进步时调用
//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>]). When <target> is not present,
// use the character himself as default.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 
int practice_level(){   return 100;}               //自己练隐含级别
int exert_function(object me, string arg)
{
    string func, target, file;
    object target_ob;
    if( sscanf(arg, "%s %s", func, target)==2 ) {
        target_ob = present(target, environment(me));
        if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
    } else {
        func = arg;
        target_ob = me;
    }
    if( !stringp(file = (string)this_object()->exert_function_file(func))
    ||  file_size(file + ".c") <= 0 )
        return 0;
    return (int)call_other( file, "exert", me, target_ob);
}
int perform_action(object me, string arg)
{
    string action, target, file;
    object target_ob;
    if( sscanf(arg, "%s %s", action, target)==2 ) {
        target_ob = present(target, environment(me));
        if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
    } else {
        action = arg;
    }
    if( !stringp(file = (string)this_object()->perform_action_file(action))
        ||  file_size(file + ".c") <= 0 )
        return 0;

        if( !target_ob ) target_ob = offensive_target(me);
        if( base_name(this_object()) != "/kungfu/skill/six-finger"
            && base_name(this_object()) != "/kungfu/skill/xianglong-zhang" )
        if( target_ob && target_ob->query_temp("yun/xingyi")
        && target_ob->query_skill("douzhuan-xingyi", 1) > 200
        && target_ob->query_skill_mapped("parry") == "douzhuan-xingyi"
        && target_ob->query("neili") > 500
        && target_ob->query("family/family_name")=="姑苏慕容"
        && random(target_ob->query("neili")*2) > random(me->query("neili"))
        && random(target_ob->query_skill("parry")) > me->query_skill("force")/4)  
        {
        if((int)call_other( file, "perform", me, me))
        {
         tell_object(all_inventory(environment(me)),sprintf(
         HIG+target_ob->query("name")+"施展出姑苏慕容家传绝技—— 「"NOR+BLINK+HIR"以彼之道 * * * 还施彼身"NOR+HIW"」\n"NOR
         +HIG"竟将"+me->query("name")+"的成名绝技尽数返施于"+me->query("name")+"自身！！！！\n"NOR));
         target_ob->add("neili",-300);
        return 1;
        } else
        return 0;
       }

    return (int)call_other( file, "perform", me, target_ob);
}
int cast_spell(object me, string spell, object target)
{
    string file;
    notify_fail("你所选用的咒文系中没有这种咒文。\n");
    if( !stringp(file = (string)this_object()->cast_spell_file(spell))
    ||  file_size(file + ".c") <= 0 )
        return 0;
    return (int)call_other( file, "cast", me, target);
}
int conjure_magic(object me, string spell, object target)
{
    string file;
    notify_fail("你所选用的法术系中没有这种法术。\n");
    if( !stringp(file = (string)this_object()->conjure_magic_file(spell))
    ||  file_size(file + ".c") <= 0 )
        return 0;
    return (int)call_other( file, "conjure", me, target);
}
int scribe_spell(object me, object ob, string spell)
{
    string file;
    if( !stringp(file = (string)this_object()->scribe_spell_file(spell))
    ||  file_size(file + ".c") <= 0 )
        return 0;
    return (int)call_other( file, "scribe", me, ob );
}
// The following two functions are used to modify the random function
// for shaolin wugong.
int sum(int n,int base,int d)
{
  return (n*(2*base+(n-1)*d)/2);
}
int NewRandom(int n,int base,int d)
{ 
  int i = 1;
  int randnum = random(sum(n,base,d));
  if (sum(6,base,d) < randnum)
   {
    i = 7;
    while (sum(i,base,d) < randnum)
          i++;
    }
  else {
    while (sum(i,base,d) < randnum)
        i++;
   } 
  return (i-1);
}

// 特殊招式(由combatd.c调用)
// modify by Fan
// 11/8/1998
void do_interlink(object me, object victim)
{
      return;
}

int is_reinpose(object me, object target)
{return 0;}

int reinpose(object me, object target, int damage)
{return damage;}

