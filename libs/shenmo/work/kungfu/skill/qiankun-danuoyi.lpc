// qiankun-danuoyi.c 乾坤大挪移
// by King 97.05

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
string  *msg_weapon = ({
YEL"$N回手一挥，想掠斜$w"YEL"来势，哪料到这么轻轻一挥之力，回击的力量竟如此大得异乎寻常！\n"NOR,
RED"哪知$N的$W"RED"微转，平平的搭在$w"RED"之上，一股柔和的劲力送出，将$w"RED"直荡了开去！\n"NOR,
HIY"$N向左踏出两步，右手$W"HIY"挥出，一股劲风扑向$n的后心，方位时刻拿捏得恰到好处！\n"NOR,
HIC"$n攻出的这一招，原是极高明的招数，但被$N手指一拂，劲力又斜斜卸了开去！\n"NOR,
BLU"$N待$n的$w"BLU"将要触及心口时，左足突然踢出，压下$w"BLU"，一借力顺势踏落！\n"NOR,
HIB"$N双手同时施展挪移乾坤心法，一声清啸，拔身而起，在半空中轻轻一个转折，飘然落在$n身旁！\n"NOR,
HIW"$n武功虽高，但于$N刚猛掌力袭体而来，手中$w"HIW"再也难以拆解$N的$W"HIW"招式！\n"NOR,
YEL"$N右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拨，上身半点不动，片刻间将$n的力道尽数卸了！\n"NOR,
GRN"$N右打出一招泰山剑法「来鹤清泉」，左手却已使出乾坤大挪移的手法，拂向$n手中$w"GRN"！\n"NOR,
CYN"$N单伸$W"CYN"，按在$n$w"CYN"边上，依照所练的乾坤大挪移心法，微一运劲，便将$n的劲力轻轻移开了！\n"NOR,
});

string  *msg_unarmed = ({
HIC"一刹那间$N化刚为柔的急剧转折，已使出属乾坤大挪移心法的第七层神功！\n"NOR,
HIW"$N动也不动，待他进到身前，乾坤大挪移内力斜引，将他力道挪移推卸了开去！\n"NOR,
GRN"岂知刚刚相触，突然一股柔和而厚重的劲力从$N身上发出，挡住了$n的劲力。同时，$N右手五指也已按在$n胸口膻中穴的周遭！\n"NOR,
RED"结果$N使出乾坤大挪移心法，依着八卦方位，倒反了$n这招的去势。\n"NOR,
CYN"$N运使乾坤大挪移，越奔越快，如风如火，似雷似电，跟着纵身而前，左手探出抓向$n！\n"NOR,
BLU"$N此时体内真气流转，一遇外力，自然而然而生反击，比之$n击来的力道又大得多了！\n"NOR,
BLU"$n右手一指戳向$N肩头，却不知如何被轻轻一带，噗的一响，竟戳到了自己手臂，只痛得眼前金星直冒！\n"NOR,
YEL"蓦地里好象旁边有一股力道飞来，将$n的力道一引，从$N身旁斜斜带过！\n"NOR,
YEL"$N当下潜运乾坤大挪移心法，使$n击向$N的一招莫名奇妙的溜滑向一旁。\n"NOR,
HIR"$N再使挪移乾坤心法，一牵一引，托的一响，将$n的力道引偏。\n"NOR,
YEL"$N右手五指犹如抚琴鼓瑟，忽挑忽捻，忽弹忽拔，上身半点不动，将$n此招化于无形！\n"NOR,
WHT"$N巧运乾坤大挪移心法，使$n这招莫名其妙的在中途转了方向，力道化于无形！\n"NOR,
CYN"乾坤大挪移神功变幻，何等奥妙，结果$N手指拂出，已点中了$n双腕穴道！\n"NOR,
GRN"$N使出挪移大乾坤，$n这招莫名其妙的在中途转了方向，打出的力量向自己飞了回来！\n"NOR,
});
string *parry_msg = ({
	"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
        "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
        "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
        "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

string *dodge_msg = ({
	"$N一招击在$n身上，却被$n暗运乾坤大挪移，将内力尽数移入地下。\n",
	"$n轻轻一带，$N发现自己招数回击过来，吓得往后倒退几步。\n",
        "$n手臂回转，在$N手肘下轻轻一推，$N招数落空。\n",
        "$n右手伸出，在$N手腕上轻轻一拉，$N收势不住，直往前扑去。\n",
        "$n身形不动，$N一招击下，有如石沉大海，不觉呆住了。\n",
	"$n左牵右引，$N如身处漩流，连续转了好几个圈。\n",
	"$n双手回圈，$N只觉得前面好象有一堵墙，再也攻不进去。\n",
	"$n轻轻一转，$N一招击在地上，只打得尘土飞扬。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int valid_learn(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

	if ( me->query("gender") == "无性" && lvl > 99)
		return notify_fail("你先天不足，再学下去难免走火入魔。\n");

	if ((int)me->query_skill("force", 1) < 100)
		return notify_fail("就这么点基本内功还想学乾坤大挪移？\n");

	if (lvl > 150 && me->query("family/family_name") != "明教" )
		return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移>>心法提高。\n");


	if ((int)me->query("max_neili", 1) < 1500)
		return notify_fail("就这么点内力还想学乾坤大挪移？\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
                return notify_fail("你的九阳神功火候还不够，小心走火入魔！\n");

	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！\n");

       if( me->query("family/family_name") != "明教")
           return notify_fail("你非明教弟子！只能通过读<<乾坤大挪移>>心法提高。\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");

        if ((int)me->query_skill("qingfu-shenfa", 1) < 80)
		return notify_fail("你的青蝠身法火候太浅。\n");

        if ((int)me->query_skill("sougu", 1) < 80)
		return notify_fail("你的搜骨鹰爪功火候太浅。\n");

        if ((int)me->query_skill("hanbing-mianzhang", 1) < 80)
		return notify_fail("你的寒冰绵掌火候太浅。\n");
		
        if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
                return notify_fail("你的九阳神功火候还不够，小心走火入魔！\n");

	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！\n");

        if ((int)me->query("qi") < lvl)
           return notify_fail("你的体力不够练乾坤大挪移。\n");

        if ((int)me->query("jing") < lvl)
           return notify_fail("你的精力不够练乾坤大挪移。\n");

        if ((int)me->query("neili") < lvl)
           return notify_fail("你的精力不够练乾坤大挪移。\n");

if ( lvl > 149)
{
        me->receive_damage("jing", lvl/2);
        me->receive_damage("qi", lvl);
        me->add("neili", -lvl);
}
        return 1;
}


void skill_improved(object me)
{
   int skill, lit, med;
   skill = (int)me->query_skill("qiankun-danuoyi", 1);
   lit = (int)me->query_skill("literate", 1);
   med = me->query_skill("jiuyang-shengong", 1);
   if( skill == 50 && !me->query("qkdny") && lit > 50 && med > 50){
      tell_object(me, HIY"你按照羊皮上所书，运气导行、移宫使劲，竟是毫不费力的便做到了。\n"NOR);
      me->add("max_neili", 10+random(30));
      me->set("qkdny", 1);
//      me->add("qkdny", 1);
      }
else if(skill == 80 && me->query("qkdny") == 1 && lit > 80 && med > 50){
      tell_object(me, HIM"你修炼第二层心法，依法施为，片刻真气贯通，只觉十根手指之中，似乎有丝丝冷气射出。\n"NOR);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 100 && me->query("qkdny") == 2 && lit > 100 && med > 50){
      tell_object(me, CYN"你按照羊皮上所书，边读边练，精神为之大振！\n"NOR);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else  if(skill == 130 && me->query("qkdny") == 3 && lit > 120 && med > 50){
      message_vision(RED"$N半边脸孔胀得血红，半边脸颊却发铁青，但神完气足，双眼精光炯炯，料是无碍。\n"NOR, me);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 150 && me->query("qkdny") == 4 && lit > 140 && med > 50){
      message_vision(HIW"$N脸上忽青忽红，脸上青时身子微颤，如堕寒冰；脸上红时额头汗如雨下。\n"NOR, me);
      me->add("max_neili", 10+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 170 && me->query("qkdny") == 5 && lit > 160 && med > 50){
      tell_object(me, MAG"你觉得体内潜力便如山洪突发，沛然莫之能御。原来是乾坤大挪移心法发挥了你本身所蓄有的潜力！\n"NOR);
      me->add("max_neili", 20+random(30));
      me->add("qkdny", 1);
      }
else if(skill == 190 && me->query("qkdny") == 6 && lit > 180 && med > 50){
      tell_object(me, MAG"你猛地里气血翻涌，心跳加快，终于练成了乾坤大挪移神功！\n");      
      me->add("max_neili", 50+random(30));
      me->add("qkdny", 1);
      }
}

int practice_skill(object me)
{
	int lvl = (int)me->query_skill("qiankun-danuoyi", 1);

        if( me->query("family/family_name") != "明教")
           return notify_fail("你非明教弟子！只能通过读<<乾坤大挪移>>心法提高。\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("你的基本内功火候还不够，小心走火入魔！\n");

        if ((int)me->query_skill("jiuyang-shengong", 1) < lvl)
                return notify_fail("你的九阳神功火候还不够，小心走火入魔！\n");

	if ((int)(me->query("max_neili")/15) < lvl)
		return notify_fail("你的内力火候还不够，小心走火入魔！\n");

        if ((int)me->query("qi") < lvl)
           return notify_fail("你的体力不够练乾坤大挪移。\n");

        if ((int)me->query("jing") < lvl)
           return notify_fail("你的精力不够练乾坤大挪移。\n");

        if ((int)me->query("neili") < lvl)
           return notify_fail("你的精力不够练乾坤大挪移。\n");

        if ((int)me->query_skill("qingfu-shenfa", 1) < 80)
		return notify_fail("你的青蝠身法火候太浅。\n");

if ( lvl > 149)
{
        me->receive_damage("jing", lvl/2);
        me->receive_damage("qi", lvl);
        me->add("neili", -lvl);
}
        return 1;
//	return notify_fail("乾坤大挪移只能通过读<<乾坤大挪移>>心法提高。\n");
}

string perform_action_file(string action)
{
        return __DIR__"qiankun-danuoyi/"  + action;
}

int ob_hit(object ob, object me, int damage)
{
        object wp,wp1, target;
        string msg;
        int p,j,skill, neili, neili1, exp, exp1;
        int level,level2,damage2;
        wp = me->query_temp("weapon");
        wp1 = ob->query_temp("weapon");
        skill = me->query_skill("qiankun-danuoyi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");


        level = (int) me->query_skill("unarmed",1);
        level2= (int) me->query_skill("jiuyang-shengong",1);
        skill = me->query_skill("jiuyang-shengong", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");

if ( level2<= 0) level2= (int) me->query_skill("shenghuo-shengong",1);
damage2= (int) ob->query("neili",1)/10;
if (random(8)==0 && level2>=300 && (me->query_skill_mapped("force") == "jiuyang-shengong" || me->query_skill_mapped("force") == "shenghuo-shengong"))
{
j = -damage/2; 
j = 0;
if (damage2> 5000)	damage2=5000;
msg = HIC+"$N运起九阳神功 全身内力爆发，浮现出一层刚猛的劲气! !\n" +NOR;
           message_vision(msg, me, ob);
if ( me->is_busy())
{
me->start_busy(1);
ob->start_busy(2);
}
if (me->query("neili") > me->query("max_neili")*2)
{
		
		me->add("neili", damage2);
}


}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("neili") < me->query("max_neili")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
)

{
message_vision(HIR"$N运起九阳神功，全身内力源源不断的涌出!\n"NOR,me, ob);
me->add("neili",random(me->query_skill("jiuyang-shengong",1))+200);
}

if (random(me->query_skill("jiuyang-shengong",1)) > 120
&& me->query("qi") < me->query("max_qi")
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0
)
{
message_vision(RED"$N运起九阳神功，身上的伤好了很多!\n"NOR,me, ob);
me->add("qi",random(me->query_skill("jiuyang-shengong",1))+380);
if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",random(me->query_skill("jiuyang-shengong",1))+380);
}



if (random(me->query_skill("qiankun-danuoyi",1)) > 120
&& me->is_busy()
&& me->query_skill_mapped("force") == "jiuyang-shengong"
&& random(2)==0)
{
message_vision(HIC"$N暗运乾坤大挪移，本来忙乱的动作快了起来!\n"NOR,me, ob);
me->start_busy(1);
}
      if(me->query_temp("yi_ob") && living(me)
      	&& me->query_skill_mapped("force") == "jiuyang-shengong"){
         target = present(me->query_temp("yi_ob"), environment(me));
         me->delete_temp("yi_ob");
         if(!target){
            tell_object(me, HIY"你发现你想挪移的目标对象已经不在这里了。\n"NOR);
            return damage;
            }
         if(!living(target)){
            tell_object(me, HIY"你发现你想挪移的目标对象已经昏迷不醒了。\n"NOR);
            return damage;
            }
         if(neili < 800){
            tell_object(me, HIY"你正要挪移，却发现自己的真气不够了！\n"NOR);
            return damage;
            }
         message_vision(WHT"$N突然双手晃动击出阵阵气流，左拔右带要把$n的招数向旁边众人牵引！\n"NOR,me, ob);
         if(random(exp) < exp1/3){
            me->add("neili", -125);
            message_vision(HIY"结果$n并没有受到干扰，反而顺势来到$N的侧面，发出强力的一击！\n"NOR,me, ob);
            return random(damage);
            }
         me->add("neili", -250);
         tell_room(environment(me), "结果引得"+ob->name()+"的力道直向"+target->name()+"冲击过去！\n",({ target,ob }));
         tell_object(target, HIR"结果你发现"+ob->name()+"的力道直向自己冲击过来！\n"NOR);
         tell_object(ob, HIR"结果你发现自己的力道直向"+target->name()+"冲击过去！\n"NOR);
         if(target->query_skill("dodge")>=damage)
            msg = HIY"结果$n没有受到任何伤害。\n"NOR;
         else{
            target->receive_damage("qi", damage-target->query_skill("dodge"), ob);
            target->receive_wound("qi", damage-target->query_skill("dodge"), ob);
            p = target->query("qi")*100/target->query("max_qi");
            msg = damage_msg(damage/2, "伤害");
            msg += "( $n"+eff_status_msg(p)+" )\n";
            }
         if(target->query("shen") < -1000 && !target->is_killing(ob->query("id"))){
              if(random(target->query_int()) < 20)
                   target->kill_ob(ob);
              else if(random(target->query_int()) > 30)
                   target->fight_ob(me);
              }
         if(target->query("shen") > -1000 && !target->is_killing(ob->query("id"))){
              if(random(target->query_int()) < 20)
                   target->fight_ob(ob);
              else if(random(target->query_int()) > 30)
                   target->fight_ob(me);
              }
         message_vision(msg, me, target);
         return -5000;
         }
      if(me->query_temp("fanzhen")){
           me->delete_temp("fanzhen");
           return 1;
           }
      if(me->query("jiali") && living(me) &&
         random(exp) < exp1/3 && skill > 50 && neili > 500 && living(ob)
         && !ob->query("env/invisibility")
         && me->query_skill_mapped("force") == "jiuyang-shengong"
         ){
         if(random(2)==1) me->add_temp("fanzhen", 1); 
         me->add("neili", -(random(10)));
        if(wp && wp1 && userp(me)){                    
           msg = msg_weapon[random(sizeof(msg_weapon))];
           msg = replace_string(msg, "$W", wp->name());
           msg = replace_string(msg, "$w", wp1->name());
           if(neili >= neili1*2+damage){
              if(random(me->query_str()) > ob->query_str()/2 && skill > 150){
                  msg += HIW"结果$n一个抵挡不住，手中"+wp1->name()+HIW"脱手飞出！\n"NOR,
                  me->add("neili", -50);
                  wp1->unequip();
                  wp1->move(environment(ob));
                  j = -5000;
                  }
              else{
                  if (damage>50)
{
                  ob->receive_damage("qi", damage/2?damage/2:10, me);
                  ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
}
                  p = ob->query("qi")*100/ob->query("max_qi");
                  msg += damage_msg(damage/2, "伤害");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  j = -5000;
                  }
              }
           else if(neili >= random(neili1)*2+damage){
              msg += "结果基本上卸掉了$n的力道。\n";              
              j = -5000;
              }
           else{
              j = damage/2+random(damage/2);
              if(j<damage/2) msg += "结果卸掉了一些$n的力道。\n";
              else msg += "结果卸掉了$n大半的力道。\n";
              j = -j;
              }           
           message_vision(msg, me, ob);
           return j;
           }          
        else{
           msg = msg_unarmed[random(sizeof(msg_unarmed))];
           if(neili >= neili1*2+damage){
if (damage>50)
{
              ob->receive_damage("qi", damage/2?damage/2:10, me);
              ob->receive_wound("qi", damage/10 > 0?damage/10:2, me);
}
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += damage_msg(damage, "内伤");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -5000;
              }
           else if(neili >= random(neili1)*2+damage){
              msg += "结果基本上卸掉了$n的力道。\n";              
              j = -5000;
              }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += "结果卸掉了一些$n的力道。\n";
              else msg += "结果卸掉了$n一半的力道。\n";
              j = -j;
              }           
           message_vision(msg, me, ob);
           return j;
           }
     }
}