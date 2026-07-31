/*
技能分类快捷激发显示指令
简单型第一个版本 
笑世(白衣)作于
2018.7.5
7.7第二次调整：添加等级显示和颜色显示,缩进代码
2019.3.24
第三次调整，界面更直观
*/

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
string *basic_id = ({
	"force",//基本内功
	"dodge",//基本轻功
	"unarmed",//基本拳脚
	"cuff",//基本拳法
	"strike",//基本掌法
	"finger",//基本指法
	"hand",//基本手法
	"claw",//基本爪法
	"sword",//基本剑法
	"blade",//基本刀法
	"staff",//基本丈法
	"hammer",//基本锤法
	"club",//基本棍法
	"whip",//基本鞭法
	"dagger",//基本短兵
	"throwing",//基本暗器
	"parry",//基本招架
	"spear",//基本枪法
	"spells",//基本枪法
	"knowledge",//知识类技能
	"basic",//其他基本武功综合
	"fufa",//符法基础
});
string *basic_name = ({
HIM "内功"NOR,//基本内功
HIM	"轻功"NOR,//基本轻功
HIM	"拳脚"NOR,//基本拳脚
HIM	"拳法"NOR,//基本拳法
HIM	"掌法"NOR,//基本掌法
HIM	"指法"NOR,//基本指法
HIM	"手法"NOR,//基本手法
HIM	"爪法"NOR,//基本爪法
HIM	"剑法"NOR,//基本剑法
HIM	"刀法"NOR,//基本刀法
HIM	"杖法"NOR,//基本丈法
HIM	"锤法"NOR,//基本锤法
HIM	"棍法"NOR,//基本棍法
HIM	"鞭法"NOR,//基本鞭法
HIM	"短兵"NOR,//基础短兵
HIM	"暗器"NOR,//基本暗器
HIM	"招架"NOR,//基本招架
HIM "枪法"NOR,//基本枪法
HIM "仙术"NOR,//基本仙术
HIM "符法"NOR,//符法基础
YEL"知识类技能"NOR,//知识类技能
	"全部类型",//基本武功以及其他
	});
int main(object me,string arg)
{
string sks;
int i,j,is,js;
string *playersk,playerskill,sa,str;
playersk = keys(me->query_skills());//传回玩家的全部技能
		str=ZJOBACTS2+ZJMENUF(2,2,10,32);
if (!arg)//当没有参数进入主函数时，调用选择界面
{
for (i=0;i <sizeof(basic_name);i++)
{
        if (me->query_skill(basic_id[i],1))
      {
sa =  HIM+basic_name[i]+NOR;
if (me->query_skill_mapped(basic_id[i]))
sa +=HIC"："+to_chinese(me->query_skill_mapped(basic_id[i]))+NOR;
else
sa +=HIR"：(待激发)"NOR;
str += sa+":fskill "+ basic_id[i]+ZJSEP;//指令主函数参数循环，用来识别和选择技能种类
      }
}	
str =ZJOBLONG+HIC"你的武功分配如下\n"+str;
}
   else//参数导入，技能分类开始
      {
      		for (i = 0; i < sizeof(basic_name); i++)//选择基本分类
   		{
		if (arg==basic_id[i])
		{
		for (is = 0; is < sizeof(playersk); is++)//选择符合这个基本类型的特殊武功
		{
		playerskill = playersk[is];
			sa = to_chinese(playersk[is]);
		sa+=HIC"［"+me->query_skill(playersk[is],1)+"级］"NOR;			
if (SKILL_D(playersk[is])->valid_enable(basic_id[i]))	//识别类型
str += sa+":jifa "+ arg +" " +playerskill +ZJSEP; 
		}
		break;				
		}		
		}
		str += HIY"返回全部"NOR":fskill"ZJSEP+"\n";
	str =ZJOBLONG"请你选择激发类型\n"+str;
		}
	write(str+"\n");
	return 1;
}