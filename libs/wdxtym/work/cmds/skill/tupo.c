/* 仙武奇缘录修为突破指令2.0版。
笑世作于2018.6.7高考日
在保存我的签名的情况下当然可以修改。
*/

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

mapping roushen = ([
	"零" : HIW "肉体凡胎  ",
	"一" : HIY "筋骨强劲",
	"二" : HIY "刀枪不入",
	"三" : HIR "铜皮铁骨",
	"四" : HIR "金刚不坏",
	"五" : HIC "不死不灭",
]);

varargs int do_tupo(object me);
int halt_do_tupo(object me);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
if (arg=="explain")
{
string msg;
int newpoint=(me->query("blevel")+1)*(me->query("blevel")+1)*10000;
//msg  = ZJOBLONG;

msg= ZJOBLONG+HIR "◎"HIY "肉身系统" HIR "◎"NOR+ZJBR;
msg+=HIG"——————————————————————"NOR+ZJBR;
msg+="肉身是武者的根本，古往今来的强大武者，都拥有极为强大的肉身，当肉身成圣之时，便真正打开了人体密藏，若有一天能够激命海，入玄藏，开六合，刺天脉，通神窍便真正不死不灭于时间，岁月磨灭不了藏于躯体的意志。"ZJBR;
msg+="目前肉身等级："+roushen[chinese_number(me->query("blevel"))]+NOR+ZJBR;
msg+="当前肉身已开发系数："+chinese_number(me->query("bpoint"))+ZJBR;
msg+="距离下一层次所需肉身系数："+chinese_number(newpoint-me->query("bpoint"))+"\n";
msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
	msg += "肉身说明:help roushen"ZJSEP;	
	msg += "锤炼肉身:tupo\n";	
	message("vision", msg, me);	
}
else
{
if (me->query("blevel") >= 5)
		return notify_fail("你已经不死不灭了，无法通过锤炼肉身来提升自己。\n");
seteuid(getuid());
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if (me->query("blevel")>2 && me->query("dajif")<1000)
		return notify_fail("你钻石不够。\n");
me->set_temp("tupo",1);
	 me->start_busy(bind((: call_other, __FILE__, "do_tupo" :), me),bind((: call_other, __FILE__, "halt_do_tupo" :), me));
	 }
	return 1;
}
varargs int do_tupo(object me)  
{

string *jingjie;
	int point,skill, level,nlevel;
	jingjie = ({"筋骨强劲","刀枪不入","铜皮铁骨","金刚不坏","不死不灭",});
	level= me->query("blevel")+1;
	point = level*level*10000;
	if (!point)
	{
	point = 10000;
	}
	
	if( (int)me->query("qi") < level*level*5)
		return notify_fail("你现在的气太少了，无法产生内息运行真气锤炼肉身。\n");
			if ((me->query("potential") - me->query("learned_points")) < (level * level * 5))
		return notify_fail("你的潜能不够用于锤炼肉身了。\n");
	if (!me->query_temp("tupo"))
	return 0;
	   if (level >= 6)
	   return notify_fail("你已经达到了肉身的至高境界！\n");
if (!me)  return 0;
		 //当人物离线时，调用函数中止   
tell_object(me,ZJEXIT"northwest:"RED"停止锤炼"NOR":halt\n");
switch (random(5)+1)
	{
		case 1 :  write(ZJTMPSAY+HIG"你不断引吸内力，激发潜能，动用全身气血……\n");break;   //一绿
		case 2 :  write(ZJTMPSAY+HIC"丹田的真气在不断锤炼你的内脏……\n");break;   //二蓝
		case 3 :  write(ZJTMPSAY+HIR"全身感到一阵一阵疼痛，真气流入经脉……\n");break;   //三紫
		case 4 :  write(ZJTMPSAY+HIY"转化出的精纯真气流入骨骼……\n");  break;   //四黄
		case 5 :  write(ZJTMPSAY+HIM"你感到皮肤一阵阵痛快淋漓……\n");  break;   //五红
		}
		 if (me->query("bpoint")>=point)
	   {
	  me->add("blevel",1);
	  me->delete("bpoint");
	  write("你的肉身突破了！\n");          
	  message("channel:chat",HBRED"肉身锤炼"HIR"："+me->query("name")+"由感而生，踏入"+jingjie[me->query("blevel")-1]+"的肉身境界!\n"NOR,users());
	  return 0;
    }
   else
    {
    nlevel = level*level+random(10);
    nlevel *= 20;
    me->add("bpoint",nlevel);
      me->add("potential",-nlevel*2);   
    }
	return 1;
}

int halt_do_tupo(object me)
{
	tell_object(me, "你心随意转，收回念头，不再锤炼肉身。\n");
	tell_room(environment(me), me->name() + "唯一皱眉，收住了姿势。\n", me);
me->delete_temp("tupo");
	return 1;
}


