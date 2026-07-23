// taiji-quan.c 太极拳
// 增加不同技能级别相应的学习和能使出的招数名, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
#include <ansi.h>
#include <combat.h>
inherit SKILL;
#include "/kungfu/skill/eff_msg.h";


/*string taiji_names = ({
        "「乱环诀」",
        "「阴阳诀」",
        "「动静诀」",
        "「两仪诀」",
        "「刚柔诀」",
        "「沾黏诀」",
        "「挤字诀」",
        "「引字诀」",
        "「按字诀」",
        "钻翻",
        "螺旋",
        "静恒",
        "开合",
        "软手",
        "虚灵",
});*/
string *taijin = ({"「乱环诀」", "阴阳诀」", "「动静诀」", "「两仪诀」", "「刚柔诀」", "「沾黏诀」", "「挤字诀」", "「引字诀」","钻翻", "螺旋","静恒","开合","软手","虚灵"});
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});

mapping *action = ({
([	"action" : "$N使一招"+(order[random(13)])+"「揽雀尾」"NOR"，双手划了个半圈，按向$n的$l",
	"force" : 100,
	"dodge" : 150,
	"skill_name" : "揽雀尾",
	"lvl" : 0,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N使一招"+(order[random(13)])+"「单鞭」"NOR"，右手收置肋下，左手向外挥出，劈向$n的$l",
	"force" : 220,
	"dodge" : 148,
	"skill_name" : "单鞭",
	"lvl" : 5,
	"damage_type" : "瘀伤"
]),
([	"action" : "$N左手回收，右手由钩变掌，由右向左，使一招"+(order[random(13)])+"「提手上式」"NOR"，向$n的$l打去",
	"force" : 240,
	"dodge" : 46,
	"skill_name" : "提手上式",
	"lvl" : 10,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手划弧，右手向上，左手向下，使一招"+(order[random(13)])+"「白鹤亮翅」"NOR"，分击$n的面门和$l",
	"force" : 260,
	"dodge" : 144,
	"skill_name" : "白鹤亮翅",
	"lvl" : 15,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手由胸前向下，身体微转，划了一个大圈，使一招"+(order[random(13)])+"「搂膝拗步」"NOR"，击向$n的$l",
	"force" : 380,
	"dodge" : 142,
	"skill_name" : "搂膝拗步",
	"lvl" : 20,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手由下上挑，右手内合，使一招"+(order[random(13)])+"「手挥琵琶」"NOR"，向$n的$l打去",
	"force" : 300,
	"dodge" : 140,
	"skill_name" : "手挥琵琶",
	"lvl" : 25,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手变掌横于胸前，右拳由肘下穿出，一招"+(order[random(13)])+"「肘底看锤」"NOR"，锤向$n的$l",
	"force" : 320,
	"dodge" : 138,
	"skill_name" : "肘底看锤",
	"lvl" : 30,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚前踏半步，右手使一招"+(order[random(13)])+"「海底针」"NOR"，指由下向$n的$l戳去",
	"force" : 540,
	"dodge" : 136,
	"skill_name" : "海底针",
	"lvl" : 35,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N招"+(order[random(13)])+"「闪通臂」"NOR"，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去",
	"force" : 360,
	"dodge" : 134,
	"skill_name" : "闪通臂",
	"lvl" : 40,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N两手由相对，转而向左上右下分别挥出，右手使一招"+(order[random(13)])+"「斜飞式」"NOR"，挥向$n的$l",
	"force" : 380,
	"dodge" : 132,
	"skill_name" : "斜飞式",
	"lvl" : 45,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右手使一招"+(order[random(13)])+"「白蛇吐信」"NOR"，向$n的$l插去",
	"force" : 500,
	"dodge" : 130,
	"skill_name" : "白蛇吐信",
	"lvl" : 50,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，向前向后划弧，一招"+(order[random(13)])+"「双峰贯耳」"NOR"打向$n的$l",
	"force" : 520,
	"dodge" : 128,
	"skill_name" : "双风贯耳",
	"lvl" : 55,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚划，右手一记"+(order[random(13)])+"「指裆锤」"NOR"击向$n的裆部",
	"force" : 540,
	"dodge" : 126,
	"skill_name" : "指裆锤",
	"lvl" : 60,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N施出"+(order[random(13)])+"「伏虎式」"NOR"，右手击向$n的$l，左手攻向$n的裆部",
	"force" : 560,
	"dodge" : 124,
	"skill_name" : "伏虎式",
	"lvl" : 65,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N由臂带手，在面前缓缓划过，使一招"+(order[random(13)])+"「云手」"NOR"，挥向$n的$l",
	"force" : 380,
	"dodge" : 122,
	"skill_name" : "云手",
	"lvl" : 70,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左腿收起，右手使一招"+(order[random(13)])+"「金鸡独立」"NOR"，向$n的$l击去",
	"force" : 400,
	"dodge" : 120,
	"skill_name" : "金鸡独立",
	"lvl" : 75,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招"+(order[random(13)])+"「高探马」"NOR"",
	"force" : 420,
	"dodge" : 118,
	"skill_name" : "高探马",
	"lvl" : 80,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N右手使一式招"+(order[random(13)])+"「玉女穿梭」"NOR"，扑身向$n的$l插去",
	"force" : 440,
	"dodge" : 116,
	"skill_name" : "玉女穿梭",
	"lvl" : 85,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N右手经腹前经左肋向前撇出，使一招"+(order[random(13)])+"「反身撇锤」"NOR"，向$n的$l锤去",
	"force" : 460,
	"dodge" : 114,
	"skill_name" : "反身撇锤",
	"lvl" : 90,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手虚按，右腿使一招"+(order[random(13)])+"「转身蹬腿」"NOR"，向$n的$l踢去",
	"force" : 480,
	"dodge" : 112,
	"skill_name" : "反身蹬腿",
	"lvl" : 95,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手向上划弧拦出，右手使一招"+(order[random(13)])+"「搬拦锤」"NOR"，向$n的$l锤去",
	"force" : 400,
        "damage" : 50,
	"dodge" : 110,
	"skill_name" : "白蛇吐信",
	"lvl" : 100,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N使一招"+(order[random(13)])+"「栽锤」"NOR"，左手搂左膝，右手向下锤向$n的$l",
	"force" : 420,
        "damage" : 180,
	"dodge" : 8,
	"skill_name" : "栽锤",
	"lvl" : 110,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手先抱成球状，忽地分开右手上左手下，一招"+(order[random(13)])+"「野马分鬃」"NOR"，向$n的$l和面门打去",
	"force" : 400,
        "damage" : 100,
	"dodge" : 116,
	"skill_name" : "野马分鬃",
	"lvl" : 120,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左手由胸前向下，右臂微曲，使一招"+(order[random(13)])+"「抱虎归山」"NOR"，向$n的$l推去",
	"force" : 400,
        "damage" : 100,
	"dodge" : 114,
	"skill_name" : "抱虎归山",
	"lvl" : 130,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手经下腹划弧交于胸前，成十字状，一式"+(order[random(13)])+"「十字手」"NOR"，向$n的$l打去",
	"force" : 420,
	"dodge" : 112,
	"skill_name" : "十字手",
	"lvl" : 140,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N左脚踏一个虚步，双手交叉成十字拳，一招"+(order[random(13)])+"「进步七星」"NOR"，向$n的$l锤去",
	"force" : 440,
	"dodge" : 110,
	"skill_name" : "进步七星",
	"lvl" : 150,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N身体向后腾出，左手略直，右臂微曲，使一招"+(order[random(13)])+"「倒撵猴」"NOR"，向$n的$l和面门打去",
	"force" : 460,
        "damage" : 100,
	"dodge" : 112,
	"skill_name" : "倒撵猴",
	"lvl" : 160,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手伸开，以腰为轴，整个上身划出一个大圆弧，\n一招"+(order[random(13)])+"「转身摆莲」"NOR"，将$n浑身上下都笼罩在重重掌影之中",
	"force" : 480,
        "damage" : 100,
	"dodge" : 114,
	"skill_name" : "转身摆莲",
	"lvl" : 170,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手握拳，右手缓缓收至耳际，左手缓缓向前推出，\n拳意如箭，一招"+(order[random(13)])+"「弯弓射虎」"NOR"，直奔$n心窝而去",
	"force" : 490,
        "damage" : 100,
	"dodge" : 116,
	"skill_name" : "弯弓射虎",
	"lvl" : 180,
        "damage_type" : "瘀伤"
]),
([	"action" : "$N双手在胸前翻掌，由腹部向前向上推出，一招"+(order[random(13)])+"「如封似闭」"NOR"，一股劲风直逼$n",
	"force" : 500,
        "damage" : 100,
	"dodge" : 118,
	"skill_name" : "如封似闭",
	"lvl" : 200,
        "damage_type" : "瘀伤"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练太极拳必须空手。\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("你的太极神功火候不够，无法学太极拳。\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练太极拳。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/* ----------------
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
-------------------*/

mapping query_action(object me, object weapon)
{
	int i, level;
	string msg;
	level = (int) me->query_skill("taiji-quan",1);
msg = random(2)==1?HIW"只见$N虚灵顶劲、涵胸拔背、松腰垂臀、沉肩坠肘，双手抱了个太极式的圆圈，纯以意行太极，已达形神合一，心动气动的境界，\n结果使出了太级拳中的"NOR:
HIW"刹时间$N悟到了太极拳旨中“似松非松，将展未展，劲断意不断”的精微奥妙之处，使出一招犹如行云流水，潇洒无比。\n结果使出了太级拳中的"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
        if ( level > 250 
        && random(level) > 200
        && random(10)>5)
        	return ([  
                	"action" : msg,
                	"force" :  500,
                	"dodge":   100,
                	"damage":   500,
                	"parry":   100,
                	"damage_type" : random(2)==1?"瘀伤":"内伤",
        	]);
        	
        if (random(me->query_con()) > 25 && random(20) >= 15 &&
        level > 200 && me->query("neili") > 600){   
           me->add("neili", -30);    
              return ([
                "action": HIW"$N左掌阳，右掌阴，目光凝视$n，两掌向$p慢慢合拢，竟是凝重如山，却又轻灵似羽！"NOR,
                "force" : 500,
                "dodge" : 200,
                "damage" : 550,
                "damage_type" : "内伤",
                "skill_name" : "阴阳决",
                "lvl" : 200,
                ]); 
        }         

        if (random(me->query_con()) > 25 && random(20) >= 15 &&
        level > 200 && me->query("neili") > 600){   
           me->add("neili", -30);    
              return ([
                "action": HIW"$N左掌阳，右掌阴，目光凝视$n，两掌向$p慢慢合拢，竟是凝重如山，却又轻灵似羽！"NOR,
                "force" : 500,
                "dodge" : 200,
                "damage" : 550,
                "damage_type" : "内伤",
                "skill_name" : "阴阳决",
                "lvl" : 200,
                ]); 
        }         
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练太极拳。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp1,weapon;
        string msg;
        int p,j,skill, neili, neili1;
        int level,level2,damage2;
        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("taiji-shengong",1);
        skill = me->query_skill("taiji-quan", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && me->query_skill_mapped("force") == "taiji-shengong")
{
j = -damage/2; 
if (damage2> 5000)	damage2=5000;
if (ob->query("qi")>= damage2 )
{
	ob->receive_wound("qi", damage2);
}
           if (!ob->is_busy() && random(3)==0)
{
                ob->start_busy(3);  
}
msg = HIG"$N 如抱太极，一股雄浑无比的力道组成了一个旋涡来！\n"NOR;
msg = msg + order[random(13)] + taijin[random(14)] + NOR;
msg += HIY"$n"+HIY+"的内力 被太极神功借力打力 反击在自己身上 ！\n"NOR;
//msg += "$n的力道被太极拳借力打力反击回来！\n",  
           message_vision(msg, me, ob);
           return j;
}       

        if( random(me->query("combat_exp")) > ob->query("combat_exp")/3
           && !ob->is_busy()
           && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query_skill_mapped("unarmed") == "taiji-quan"
           && skill > 200)
            {
             msg = HIG"$p只觉上盘各路已全处在$P双掌的笼罩之下，无可闪避，无可抵御，只得运劲于背，硬接他这一掌，
同时右臂紧挥，只盼两人各受一招，成个两败俱伤之局。\n"NOR;
             if(random(20) >= 13 && me->query("neili") > 600){
                   msg += HIR"不料$N双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡，只带得$p在原地急转七八下，
如转陀螺，如旋纺锤，好容易使出“千斤坠”之力定住身形，却已满脸胀得通红，狼狈万状！\n"NOR;
                   ob->receive_damage("qi", me->query_skill("taiji-quan", 1)*2);
                   ob->receive_damage("jing", me->query_skill("taiji-quan", 1)/3);
  if( !ob->is_busy() )
{
                   ob->start_busy(2+random(2));
}
                   me->add("neili", -20);
                   }
             else 
{
  if( !me->is_busy() )
{
             me->start_busy(1+random(2));
}
             msg += HIY"$N但觉气息微窒，当下一招“斜飞势”，将$N力量引偏，自己也退开两步。\n"NOR;
}
             message_vision(msg, me, ob);
             return 1;
        }
      if(me->query("combat_exp") > ob->query("combat_exp")/2
         && me->query_skill_mapped("unarmed") == "taiji-quan"
         && me->query_skill_mapped("parry") == "taiji-quan"
         && me->query_skill("taiji-shengong", 1) > 50
         && neili > 100 
         && skill > 50 
         && living(me)
         && !ob->query("env/invisibility")
         && random(10) >= 3)
         {         
         if(wp1) msg = "$N双手连划，太极圆圈在$n的"+wp1->name()+"上一绕，";
         else msg = "$N双手划弧，连连打出太极圆圈，";
if (damage>50)
{
         if(neili >= neili1 + damage){
         		if( weapon ) msg = "$N伸手一拍震开了$n的"+weapon->name()+"，顺势一转，借力打力一掌按在$p下肋！\n";
         		else msg = "$N左手一划，套住$n，右掌顺势一推，借力打力将$p的劲力全数倒翻回去！\n";
              msg += "结果$n的力道被太极拳借力打力反击回来！\n",              

              ob->receive_damage("qi", damage/2+ob->query("jiali")*2, me);
              ob->receive_wound("qi", ob->query("jiali"), me);
}
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage/2, "震伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -8000;
              }             
           else if(neili >= neili1/2+random(neili1/2)+random(damage)){
              		if( weapon ) msg = "$N身形一转，一掌以四两拨千斤之巧劲从旁拍开了$n递近身的"+weapon->name()+"！\n";
         		else msg = "$N左手一划，右掌一转，以四两拨千斤之巧劲将$n的力道卸在一旁！\n"; 
            msg += "结果$n的力道被太极拳借力打力卸在一旁！\n", 
              j = -8000;
              }
           else if(neili > neili1/2+damage){
        	if( weapon ) msg = "$N情急之下，四两拨千斤一下拍在$n递近身的"+weapon->name()+"之旁，卸掉了$p一部分劲力！\n";
         	else msg = "$N连忙双手一加，以四两拨千斤之巧劲将$n的力道卸掉了一部分！\n";  

              msg += "结果$n的力道被太极拳借力打力卸掉了一部分！\n", 
              j = -(damage/3+random(damage));               
              }
           else{
        	if( weapon ) msg = "$N集中生智，用借力打力之法使身体微侧，让"+weapon->name()+"劲力稍减！\n";
         	else msg = "$N慌忙用借力打力之法靠上，想要卸掉一部分劲力！\n";  

              msg += "结果$n的力道被太极拳借力打力卸掉了一小半！\n", 
              j = -damage/3; 
              }           
           message_vision(msg, me, ob);
           return j;
       }          
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    string msg;
    int j,damage;
    j = me->query_skill("taiji-quan", 1);
   
    if( damage_bonus < 100 ) return 0;
    if(random(20) >= 13 && !victim->is_busy() && j > 120 &&
       me->query("neili") > victim->query("neili") &&
       me->query_skill_mapped("parry") == "taiji-quan" &&
        me->query_skill("taiji-shengong", 1) > 50 &&
       me->query_skill_mapped("unarmed") == "taiji-quan" &&
       me->query("neili") > 600 && me->query("max_neili") > 1200 &&
        j > random(victim->query_skill("dodge",1))){
        switch(random(4)){
            case 0 :
               msg = YEL"$N运起引字诀，粘连粘随，右掌已搭住$n左腕，巧劲随即发出！\n"NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
               break;
             case 1 :
               msg = YEL"$N运起挤字诀，双手一圈，如抱太极，一股雄浑无比的力道组成了一个旋涡！\n"NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
                break;
            case 2 :
               msg = YEL"$N运粘起字诀，双手弧划，左圈右围，一个跟着一个，太极圆圈连连发出！\n"NOR;
                damage = damage_bonus/4 + random(damage_bonus)/5;
                                if ((int)victim->query("jing")<=damage+10) 
                                 { victim->set("jing",10); }
                                 else {
                 victim->receive_damage("jing", damage); 
                                 }
           if (!victim->is_busy())
{
                victim->start_busy(2);  
}
                me->add("neili", -20);     
               break;
            case 3 :
               msg = YEL"紧接着$N运起太极拳中粘、引、挤、按等招式，想将$n身子带歪！\n"NOR;
                damage = damage_bonus/3 + random(damage_bonus)/4;
                if (damage < 10) damage=10;
                victim->receive_wound("qi", damage/5);
                me->add("neili", -damage/10);
               break;
            }
        switch(random(4)){
         case 0 : msg += HIR"结果$n身不由主的向前一冲，跨出几步，方始站定。\n"NOR; break;
         case 1 : msg += HIR"结果$n身不由主的在原地急转了七八下，如转陀螺，如旋纺锤！\n"NOR; break;
         case 2 : msg += HIR"登时便套得$n跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷。\n"NOR; break;
         case 3 : msg += HIR"$n想使出千斤坠之力定住身形，却已满脸胀得通红，身不由己，狼狈万状。\n"NOR; break;
         }
        message_vision(msg, me, victim);
        }
}	