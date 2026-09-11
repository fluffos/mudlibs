// skill_reg.c write by fire on Dec 26 
#include <mudlib.h>
#include <config.h>
#include <classes.h>
#include <ansi.h>
#include <sanguo.h>
inherit CMD;
inherit CLASS_SG_SKILL;
	
class sg_skill_reg p_sk;
void def_skill(string skill)
{
	switch(skill)
	{
		case "sk_wuli" :
		    p_sk->sk_name=HIR+"武学修养"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_NOR;
                    p_sk->sk_get=
"$N一吸气，感到全身一阵轻松，双臂似乎充满了无穷的力量。\n"+
HIG+"$N的"+HIR+"武学修养"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=""; // when this skill used what will display
    		    p_sk->sk_succ=""; // when this skill succedd what will display
    		    p_sk->sk_fail=""; // when this skill fail what will display
		    break;
		case "jbsj" :
		    p_sk->sk_name=NOR+"基本水计"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_JI;
                    p_sk->sk_get=
"$N一凝神，仿佛听到了滚滚洪水咆哮而至声音。\n"+
HIG+"$N的"+NOR+"基本水计"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N手持令牌，喝道：“众将士听令，开闸放水！！！”"+NOR;
    		    p_sk->sk_succ=
HIG+"只听一声令下，滚滚洪流冲向敌营。$N仰天大笑“哈、哈、哈、哈 . . .”\n";
    		    p_sk->sk_fail=RED+"只听一声令下，大水怎么冲过来了。$N大叫“逃命呀。”\n"+NOR; 
		    break;
		case "jbhj" :
		    p_sk->sk_name=NOR+"基本火计"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_JI;
                    p_sk->sk_get=
"$N一抬头，好象看到了战场上无边的"+RED+"火海"+NOR+"。\n"+
HIG+"$N的"+NOR+"基本火计"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N手持令牌，喝道：“众将士听令，点火！！！”"+NOR;
    		    p_sk->sk_succ=
HIG+"只听一声令下，四处"+HIR+"火"+HIG+"起。$N仰天大笑“哈、哈、哈、哈 . . .”\n";
    		    p_sk->sk_fail=RED+"只听一声令下，四处冒起一阵青烟。$N奇怪地“咦”了一声。\n"+NOR; 
		    break;
			
		case "sk_zhimou" :
		    p_sk->sk_name=HIC+"兵法修养"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_NOR;
                    p_sk->sk_get=
"$N突然醒悟，一时间似乎万物奥妙全部了然于胸。\n"+
HIG+"$N的"+HIC+"兵法修养"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=""; // when this skill used what will display
    		    p_sk->sk_succ=""; // when this skill succedd what will display
    		    p_sk->sk_fail=""; // when this skill fail what will display
		    break;
		case "sk_meili" :
		    p_sk->sk_name=HIY+"治国修养"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_NOR;
                    p_sk->sk_get=
"$N举首远眺，放眼大好江山似有所悟。\n"+
HIG+"$N的"+HIY+"治国修养"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=""; // when this skill used what will display
    		    p_sk->sk_succ=""; // when this skill succedd what will display
    		    p_sk->sk_fail=""; // when this skill fail what will display
		    break;
		case "fyzf" :
		    p_sk->sk_name="方圆阵法"; // the chinese name for a skill
    		    p_sk->sk_type=SK_ZHENG;
                    p_sk->sk_get=
"$N底头瞑思，耳旁似乎响起了战场的厮杀声。\n"+
HIG+"$N的"+NOR+"方圆阵法"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N手举红旗，东南西北各挥一下，喝道：\n"+
"“众将士听令，摆"+NOR+"方圆阵"+HIG+"。”"+NOR;
    		    p_sk->sk_succ=
HIC+"只听军中一声号令，战鼓齐鸣，喊杀惊天，列队整齐，\n"+
"军士四面布开，形成防守稳固的方圆大阵。\n"+NOR; 
    		    p_sk->sk_fail=RED+"只听军中一声号令，战鼓齐鸣，喊杀惊天，列队混乱不齐，\n"+
"军士不知所措，完全乱了阵脚，方圆阵失败。\n"+NOR; 
		    break;
		case "zmyj" :
		    p_sk->sk_name=HIR+"致命一击"+NOR; // the chinese name for a skill
    		    p_sk->sk_type=SK_FIGHT;
                    p_sk->sk_get=
"$N潜运内力，只觉全身气力都集于双臂。\n"+
HIG+"$N的"+HIR+"致命一击"+HIG+"提高了。"+NOR+"\n";
                    p_sk->sk_use=
HIG+"$N潜运内力，一声暴喝，使出必杀技："+HIR+"“致命一击”"+NOR;
    		    p_sk->sk_succ=
RED+"$N一时慌了手脚，不知如何招架，只听“噗”的一声已经击中。\n"+
"$N狂吐一口鲜血 . . .\n"+NOR; 
    		    p_sk->sk_fail=HIG+"$N微微一笑，一闪身躲过这致命一招。"+
"顺势给出有力的回击。\n"+NOR; 
		    break;
			
		default :
		    printf("ddd\n");
		    p_sk->sk_name="";
  		    printf("ccc\n");
             
	}
}
			
// SK_NOR normal skills such as the wuli weili and zhimou 1
// SK_FIGHT skills used in fight such as 回马枪 2
// SK_ZHENG skills for 阵法 3
// SK_JI skills of 计 
private void main(string arg)
{
    string skill;
    skill=arg;  // 武学修养
    p_sk=new(class sg_skill_reg, 
		    sk_name : "",
    		    sk_type : 0,
                    sk_get : "",
                    sk_use : "" ,
    		    sk_succ : "",
    		    sk_fail : "" );
    def_skill(skill);
    if((p_sk->sk_name)!="")
    {
  	    SG_SKILL_D->register_skill(skill, p_sk);
    } 
   else
    {
	  printf("can't register this kind of skills\n");
    }
}
