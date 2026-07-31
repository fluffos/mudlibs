// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_valid_create(string skillname);
int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        int skill, skill_basic;

        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if( !arg ) return (__DIR__"enable")->main(me, arg);

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("你只能练习用 enable 指定的特殊技能。\n");


        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("你好像还没有学过这项技能吧？最好先去请教别人。\n");
        if( skill_basic < 1 )
                return notify_fail("你对这方面的技能还是一窍不通，最好从先从基本学起。\n");

 //here add something.....
        if(check_valid_create(skillname)==0)
                return notify_fail("这不是你创建的功夫呀？\n");
           

        if( skill_basic/2 <= skill/3 )
                return notify_fail("你的基本功火候未到，必须先打好基础才能继续提高。\n");

        notify_fail("你现在不能练习这项技能。\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
        

        notify_fail("你试着练习" + to_chinese(skillname) + "，但是并没有任何进步。\n");
        if( SKILL_D(skillname)->practice_skill(me) ) {
//original num is skill_basic/5 now to 4
//it should be adrusted properly

                me->improve_skill(skillname, skill_basic/4 +1, skill_basic > skill? 0: 1);
                write( HIY "你的" + to_chinese(skillname) + "进步了！\n" NOR);
                return 1;
        }
        else return 0;
}
int check_valid_create(string skillname)
{
string file,*list,playername;
object me;

me=this_player();
file=read_file(SKILL_D(skillname+".c"));
if(!file) 
     return 0;
list = explode(file, "\n");
playername=geteuid(me);

if(list[1]!="// "+playername)
      return 0;
if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
           return 0;

return 1;
}

int help(object me)
{
        write(@TEXT
指令格式：selfpractice <技能种类>

这个指令让你练习某个自己创建的技能，这个技能必须是经过 enable 的专业技能。

如果你对这方面的基本技能够高，可以经由练习直接升级，而且升级的上限只跟
你基本技能的等级有关，换句话说，勤加练习是使你的所学「青出于蓝胜于蓝」
的唯一途径，当然，在这之前你必须从实际运用中获得足够的经验以提升你的基
本技能。
例如：practice unarmed,practice sword......

TEXT
        );
        return 1;
}

