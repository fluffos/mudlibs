//勾魂
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

string *msgs = ({
	"\n忽然刮来一阵槮人的阴风，隐约中你看到几只面目可憎的亡魂围绕在$N周围。\n\n",
	"\n四周阴风阵阵，$N周围百鬼夜行......\n\n",
	"",
	"\n只见一只断体残肢的小鬼从地下爬出，紧紧的贴在$n背后......\n\n",
	"",
	"",	
});	
		
int update_condition(object me, int dur)
{
int damage;
string str;	
if( dur<=1 || me->query("family/family_name")=="阎罗地府" 
 || !environment(me) )
        return 0;
str = msgs[random(sizeof(msgs))];
str = replace_string(str,"$N",me->name());        
message("vision",str,environment(me),me);
tell_object(me,HIR"你耳边隐隐约约传来阵阵凄惨的尖叫声：还......我......命......来......\n");
me->set_temp("death_msg","被恶鬼缠身，索魂而死。\n");
if ( dur>120 )
	dur = 120;
damage = 120-dur;
if ( damage<1 ) damage = 1;		
damage*= 5;
me->receive_wound("sen",damage);
me->receive_damage("sen",damage/2);
me->apply_condition("gouhun_posion",dur-1);
return CND_CONTINUE;
}
