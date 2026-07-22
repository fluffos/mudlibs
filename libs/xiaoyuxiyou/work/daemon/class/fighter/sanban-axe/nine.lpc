// nine.c 
//将军府终极pfm 盘古九式 
// snowtu
#include <ansi.h>
#include <combat.h>
inherit SSERVER; 

string name()
{
	return "「"NOR YEL"盘古九式"NOR"」";
}

int valid_perform(object me)
{
	int i;
	string sk,*skills = ({
        	"baguazhou","changquan","lengquan-force","sanban-axe","yanxing-steps",
	});     
	if( !me )
        	return 0;
	if( me->query("family/family_name")!= "将军府" )
        	return notify_fail(name()+"乃是将军府不传绝招。\n");
	if( !me->query("family/jjf_type") 
  	  || me->query("family/jjf_type")!="axe" ) 
        	return notify_fail(name()+"乃是将军府斧系不传绝招。\n");
	i = sizeof(skills);
	while ( i-- )
        {
        	sk = skills[i];
        	if( !sk || !stringp(sk) )
                	continue;       
        	if( me->query_skill(sk,1)<800 )
                	return notify_fail("你的"+to_chinese(sk)+"等级不足 800 级，不能施展"+name()+"。\n");       
        }
	if( me->query("faith")<5000 )
        	return notify_fail("你的门忠不足 5000 点，不能施展"+name()+"。\n");
	if( me->query("max_force")<5000 )
        	return notify_fail("你的内力修为不足五十年，不能施展"+name()+"。\n");
	if( me->query("force")<2500 )
        	return notify_fail("你的内力不足 2500 点，不能施展"+name()+"。\n");   
	if( me->query_str()<25 )
        	return notify_fail(name()+"需要浑身发力，你的膂力好象还不够。\n");
	if( time()<me->query_temp("zjpfm_jjf_nine")+5 )
        	return notify_fail("你刚刚想施展"+name()+"，只觉浑身乏力，提不起力来。\n");    
	return 1;               
}

int perform(object me, object target)
{
	object weapon;
	int ap,dp,damage;
	string tmp;
	return notify_fail("暂未开放。\n");
	if( !valid_perform(me) )
        	return 0;
	if( !target ) 
        	target = offensive_target(me);
	if( !target
  	 || !target->is_character()
  	 || !me->is_fighting(target) )
        	return notify_fail(name()+"只能对战斗中的对手使用。\n");

	weapon = me->query_temp("weapon");
	ap = COMBAT_D->skill_power(me,"axe",SKILL_USAGE_ATTACK)/2;
	ap+= COMBAT_D->skill_power(me,"force",SKILL_USAGE_ATTACK)/2;
	dp = COMBAT_D->skill_power(target,"dodge",SKILL_USAGE_DEFENSE)/2;
	dp+= COMBAT_D->skill_power(target,"force",SKILL_USAGE_DEFENSE)/2;

	if( random(me->query_str())>target->query("str") )
        	ap+= ap/5;
	if( target->is_busy() )
	        ap+= ap/10;      
	if( target->query("family/family_name")=="将军府" )
        	dp+= random(dp/5);
	if( COMBAT_D->wuxing_restrain(me,target)==1 )
        	dp-= random(dp/3);      
	if( COMBAT_D->wuxing_restrain(me,target)==-1 )
        	dp+= random(dp/3);      

	if( wizardp(me) )  tell_object(me,HIY"ap="+ap+"  dp="+dp+"\n"NOR);
	me->set_temp("zjpfm_jjf_nine",time());
	me->add("force",-300);
	me->add("faith",-1);
	tell_object(me,HIR"你口念八卦九字真言：请神！半空之中立时显出一尊盘古幻像。\n"NOR);
	message("vision",HIR"忽地狂风骤起，大地动容，九天之上，隐隐浮显一燕额虎须，赤膊神将，手持通体血红
的开天斧。却是将军府授道祖师盘古大神。\n"NOR,environment(me),({me,target}));
	tell_object(target,HIW"半空中，一声怒吼：以武犯禁，必诛无赦。\n"NOR);

//1
	damage = COMBAT_D->attacking_perform_damage(me,target,me->query_skill("axe"));
	if( damage>0 || random(ap+dp)>dp )
        {
        	damage+= me->query_temp("apply/damage")*(1+me->query("kar")/8);
        	damage-= target->query_temp("apply/armor");
        	damage+= me->query_skill("axe");
        	if( damage<800 )  damage = 800;
        	COMBAT_D->apply_damage(me,target,damage,"kee",YEL"$N"YEL"一声大喝“开”一道血影划过，大斧直劈$n"YEL"面门。竟
是程咬金三板斧中“开瓜”之招式，但其威武却不可同语。\n"NOR);
        }
	else    message_vision("\n结果$N第一式攻击落空。\n",me,target);
	if( !me || !target || !me->is_fighting(target)
  	 || !weapon || !present(weapon,me) )
        	return 1;
	if( me->query("force")<1000 )
        {
        	tell_object(me,CYN"你的内力不足，难以继续下面的攻击。\n"NOR);
        	return 1;
        }
	me->add("force",-100);        

//2-3
	if( random(ap+dp)>dp )
        {
		damage = damage/2+random(damage);        	
        	COMBAT_D->apply_damage(me,target,(damage+800),"eff_kee",NOR"\n"CYN"$N"NOR CYN"又喝道：“剔牙！掏耳朵！”大斧疾挑，横劈$n"CYN"
面门，正是“剔牙”“掏耳朵”两式。原来是那白发老人梦中所授，将军府威震天下的绝杀。\n"NOR);
        }
	else    message_vision("\n结果$N后两式攻击被$n闪开。\n",me,target);

	if( damage<=0 )
        {
        	if( !me->query_temp("zjpfm_jjf_nine_add_str") )
                {
                	if( !me->query("env/brief_message") && !target->query("env/brief_message") )           
                        {       
                        	tell_object(me,HIR"三式过后，你收回"+weapon->name()+"，情形是大相同，单臂血脉贲张，暴涨了一倍有余，通臂现出血色雾气。\n"NOR,me,target);
                        	message("vision",HIR+me->name()+"三招过后，单臂血脉贲张，暴涨了一倍有余，通臂现出血色雾气。"NOR,environment(me),me);
                        }
                	me->add_temp("apply/strength",20);
                	me->set_temp("zjpfm_jjf_nine_add_str",1);
                }
        }
	if( !me || !target || !me->is_fighting(target)
  	|| !weapon || !present(weapon,me) 
  	|| me->query_skill("literate",1)<300 )
        	return 1;
	if( me->query("force")<1000 )
        {
        	tell_object(me,CYN"你的内力不足，难以继续下面的攻击。\n"NOR);
        	return 1;
        }
//4
	if( !me->query("env/brief_message") && !target->query("env/brief_message") )        
        {
        	message_vision(HIR"
$N"HIR"单手回转，暴喝一声“挖”，这一式除却斧的大力，又兼收了枪的灵动，
锏的豪迈，如影随形，贴身而来，避无可避。"NOR,me,target);
        tell_object(target,HIR"程咬金虽也贵为有缘人，想来终究是无法参透这第四式起的古韵，终没能化为己用。\n"NOR);
        }
	else    message_vision(HIR"第四式！\n"NOR,me,target);   
	me->add("foce",-200);
	damage = COMBAT_D->attacking_perform_damage(me,target,weapon->query("weapon_prop/damage")-target->query_temp("apply/armor"));
	if( wizardp(me) )   tell_object(me,"damage="+damage+"\n");
	if( damage<=0 )
        {
        	if( !me->query("env/brief_message") && !target->query("env/brief_message") )           
                	message_vision(HIR"$n"HIR"沿着"+weapon->name()+HIR"的来势，翻转腾挪，弄得是手忙脚乱，倒也算窥得这式的一丝破绽。\n"NOR,me,target);
        	me->add("force",-100);
        }
	else    
	{
        	if( !me->query("env/brief_message") && !target->query("env/brief_message") )        
	                message_vision(HIR"$n"HIR"被"+weapon->name()+HIR"带起风势卷起，在半空翻转腾挪，弄得是手忙脚乱，心神大乱。\n"NOR,me,target);            
        	if( !target->is_busy() )
	                target->start_busy(5);
        	target->receive_damage("sen",damage,me,"perform");
        	COMBAT_D->report_sen_status(target);
        }
//5-6        
	if( !me || !target || !me->is_fighting(target)
  	|| !weapon || !present(weapon,me) 
  	|| weapon!=me->query_temp("weapon") )
        	return 1;
	if( me->query("force")<1000 )
        {
        	tell_object(me,CYN"你的内力不足，难以继续下面的攻击。\n"NOR);
        	return 1;
        }
	tmp = ({
        	"口喷鲜血整个人横飞了出去",
	        "整个人似一捆稻草般飞了出去",
        	"狂吐鲜血，身子象断了线的风筝向後飞去",
	        "血肉横飞，十命断了九条",
        	"闷哼一声，吐出一口鲜血，五脏六腑都错了位",
	})[random(4)];

	if( !me->query("env/brief_message") && !target->query("env/brief_message") )                        
        {
        	message_vision(YEL"
$N"NOR YEL"毫无停手之意，连喝“进”“逼”，"+weapon->name()+NOR YEL"璇飞而出，只带得飞沙走石，令人难睁
双目，待看得清了，那还来得及闪避。先是一记，紧跟再一记，招式中竟有些许鞭和枪的特质，却比鞭，
棍的力量更浑厚，更霸道。\n"NOR,me,target);
        tell_object(target,HIR"这两式本就都以快为进，你切肤感觉到的只能是斧的冰冷和血的滚烫。\n"NOR);
        }
	else    message_vision(HIR"再两式！\n"NOR,me,target);   
	me->add("force",-200);
	if( random(ap+dp)>dp/2 )
        {
        	if( !me->query("env/brief_message") && !target->query("env/brief_message") )           
                	message_vision(YEL"$n"NOR YEL"但见眼前净是扑面的风沙，虽知命悬一线，可惜心神已乱，给打得"+tmp+"！\n"NOR,me,target);
        	damage = me->query_skill("dodge");
        	damage = damage/2+random(damage/2);
        	target->receive_damage("kee",damage,me,"perform");
        	target->apply_condition("jjf_poison",1000);
        	target->update_condition();
        }
	else    
	{
        	me->add("force",-100);
        	if( !me->query("env/brief_message") && !target->query("env/brief_message") )        
                	message_vision(YEL"$n"NOR YEL"虽双目紧闭，但凭扑面而来风沙，已知命悬一线，即刻攒起身躯，缩成一团，这才护住要害。\n"NOR,me,target);
        }
	if( !me->query_temp("zjpfm_jjf_nine_add_str2") )
        {
        	if( !me->query("env/brief_message") && !target->query("env/brief_message") )                   
                {
	                message_vision(HIR"\n又两式过后，情形再变，$N"HIR"似开启了灵魂深处的烙印，转瞬间，已幻化作盘古肉身。\n"NOR,me,target);
        	        tell_object(me,HIR"你只觉浑身似乎流淌出无匹大将军的彪悍，传承了上古大神开天的胆略，胸中豪气激荡澎湃，不甘与狂妄喷薄而出。\n"NOR);
                }
        	me->add_temp("apply/strength",100);
        	me->set_temp("zjpfm_jjf_nine_add_str2",1);
        }
	//7        
	if( !me || !target || !me->is_fighting(target)
  	|| !weapon || !present(weapon,me) 
  	|| weapon!=me->query_temp("weapon") 
  	|| ( random(me->query_skill("literate",1))/10)<10 && !me->is_boss() ) 
	        return 1;
	
	if( me->query("force")<1000 )
        {
        	tell_object(me,CYN"你的内力不足，难以继续下面的攻击。\n"NOR);
        	return 1;
        }
	me->add("force",-100);        
	if( !me->query("env/brief_message") && !target->query("env/brief_message") )           
        	message_vision(HIR"        
$N"HIR"声音滚滚如雷，再度响起“列”"+weapon->name()+HIR"挟开天之势，化万千影像，劈头盖脸的飞出,
$n"HIR"不知如何藏身，浑身上下有如被千刀万剐，血流如注。盘古第七式，也作“血雨”"NOR,me,target);
	else    message_vision(HIR"第七式！\n"NOR,me,target);
	damage = me->query_temp("apply/damage");
	damage+= me->query_temp("apply/attack");
	damage+= me->query("force_factor");
	damage-= target->query_temp("apply/armor");
	if( random(ap+dp)>dp )
        {
        	if( damage<=0 )
                	damage = 500;
        }
	else    damage = 100;             
	target->receive_damage("kee",damage*2,me,"perform");
	COMBAT_D->report_status(target);

//8
	if( !me || !target || !me->is_fighting(target)
  	|| !weapon || !present(weapon,me) 
  	|| weapon!=me->query_temp("weapon") )
        	return 1;  
	if( me->query("force")<1000 )
        {
        	tell_object(me,CYN"你的内力不足，难以继续下面的攻击。\n"NOR);
        	return 1;
        }
	if( !me->query("env/brief_message") && !target->query("env/brief_message") )           
        	message_vision(HIR"
七式过后，八式再起，漫天斧影，尽皆化去。$N"HIR"不再如先前般狂妄，神情倒变得更加凝重
“在式”如混沌初开之纯粹浩荡，顿时，风雷哀号，天与地闪过一阵阵的胆怯。\n"NOR,me,target);
	else    message_vision(HIR"第八式！\n"NOR,me,target);
	me->add("force",-300);
	if( random(ap+dp)>dp )
        {
        tell_object(target,HIR"你如中魔咒，再低头看向自己，身上虽一片的血色，却并无新伤。心里明白，内里已经心胆尽碎，
肝肠寸断。这第八式，也作“肃杀”。\n"NOR);
        	damage = target->query("kee")/100*60;
        	if( damage<100 )  damage = 100;
        	damage*= me->query("kar")/5;
        	target->receive_damage("kee",damage,me,"perform");
        	COMBAT_D->report_status(target);
        }
	else    
	{
        	me->add("force",-100);
        	message_vision(HIR"     
$n"HIR"观此气象，不敢怠慢，运足内劲，护于体内要害之穴道，但觉一股大力涌来时，爆出毕生功力将其抗出体外。\n"NOR,me,target);
        }
//9        
	if( me && target && me->is_fighting(target) && living(target) 
  	&& random(50)==47 )
        {
        	me->add("force",-300);
        	if( !me->query("env/brief_message") && !target->query("env/brief_message") )           
                {
                	message_vision(HIR"
可一切尚未结束，未及$n"HIR"转念，最后一声若旱地焦雷再度响起“杀”，"+weapon->name()+HIR"瞬息向前刺出，
引导着$N"HIR"整条手臂，尽皆没入$n"HIR"胸前，贯胸而出！盘古第九式，是刺，也作“命绝”。\n"NOR,me,target);
                	tell_object(target,HIR"你眼中再无天地，耳中再无声息，生命唯余这夺命的一刺。\n"NOR);
                }
        	else    message_vision(HIR"最后一式！\n"NOR,me,target); 
        	target->set_temp("last_damage_from",me);
        	target->unconcious();
        }
	if( me && !me->query("env/brief_message") )           
        {        
        	tell_object(me,HIR"
你渐渐淡定，浑然忘记刚刚做过了些什么，唯沾满鲜血的"+weapon->name()+HIR"和整一条手臂上潺潺流下的红色，似依然在诉说着杀戮...、\n"NOR);
        }
	return 1;
}

int help(object me)
{
string str;     
if( !me )      return 0;
str = @LONG
        外功名称：盘古九式
        外功所属：宣花三斧
        外功效果：斧系兵卫终极技能，对敌进行强力的九击
                  冷却时间5秒
        外功条件：
                  内力修为五十年  
                  内力2500点
                  宣花三斧800级
                  八 卦 咒800级
                  长    拳800级
                  冷泉心法800级
                  雁行步法800级
LONG;
me->start_more(str);
return 1;
}
