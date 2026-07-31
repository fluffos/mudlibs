// shop.c
#define SKILLS_D "adm/daemons/skillsd"
inherit F_CLEAN_UP;
mapping basic_id = ([
	"force":"基本内功",
	"dodge":"基本轻功",
	"unarmed":"基本拳脚",
	"cuff":"基本拳法",
	"strike":"基本掌法",
	"finger":"基本指法",
	"hand":"基本手法",
	"claw":"基本爪法",
	"sword":"基本剑法",
	"blade":"基本刀法",
	"staff":"基本丈法",
	"hammer":"基本锤法",
	"club":"基本棍法",
	"whip":"基本鞭法",
	"dagger":"基本短兵",
	"throwing":"基本暗器",
	"parry":"基本招架",
	"spear":"基本枪法",
]);

int main(object me, string arg)
{
        if (! wizardp(me) && time() - me->query_temp("last_combat") < 10)  
                return notify_fail("系统气喘嘘地叹道：慢慢来 ....\n");   
   if (!arg)
  {
   string type,*types = keys(basic_id);
   string msg= ZJOBLONG+HIR "◎"HIY "江湖武学系统" HIR "◎"NOR+ZJBR;
	msg+="你可以选择查看以下类型\n";
	msg+=ZJOBACTS2+ZJMENUF(3,3,9,30); 
	foreach (type in types)
	msg += basic_id[type]+":combat "+type+ZJSEP;
	msg += "全部排名:combat all\n";
	 return notify_fail(msg+"\n");
	}
        me->set_temp("last_combat", time());        
          if (arg=="all")
          {
            SKILLS_D->show_skills_power_point(me);    
            return 1;
            }
        SKILLS_D->show_skills_power_point(me, arg);      
        return 1;
}

int help (object me)
{
        write(@HELP
查看武功各种参数值
    combat attack             查看攻击力排名
    combat dodge              查看躲闪力排名
    combat parry              查看招架力排名
    combat damage             查看伤害力排名
    combat force              查看内功的排名
    combat difficult          查看难度的排名
    combat ultimate           查看终极的武功
    combat expert             查看超级的武功
    combat advance            查看高级的武功
    combat normal             查看普通的武功
    combat public             查看公共的武功
    combat family             查看门派的武功
    combat private            查看自创的武功
    combat <门派名称>         查看该门派武功
    combat <技能名称>         查看该武功参数
    combat <技能种类>         查看可激发武功

HELP);
        return 1;
}
