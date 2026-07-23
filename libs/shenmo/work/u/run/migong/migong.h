#include <combat.h>

int update(object obj)
{
int i;
object *inv;
inv = all_inventory(obj);
i = sizeof(inv);

while(i--)
	if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
	else inv[i] = 0;
destruct(obj);
return 1;
}

void fullup(object obj) 
{
  if (!obj) return;
  obj->set("kee",250);
  obj->set("eff_kee",(int)obj->query("max_kee")*(5+random(5))/10);
  obj->set("sen",250);
  obj->set("eff_sen",(int)obj->query("max_sen"));
  obj->set("force",0);
  obj->set("mana",0);
}

int do_none( )
{
message_vision(HIR"四周毒雾弥漫，$N失去了方向感！\n"NOR,this_player() );
return 1;
}

void alternative_die(object me)
{
  if ( userp(me) )
	{
	fullup(me);
        me->move(__DIR__"migong1");
	message("channel:rumor",HIY"【"+BLU"死亡岛"+HIY"】沙织(Sha zhi):"+HIW+me->name()+ HIY"在死亡迷宫中遇到不名的攻击!\n"NOR,users());  
	message_vision("$N退守到迷宫入口。\n",this_player() );  
	update(this_object());
	}
else  destruct(me);
}

object npc_name( )
{
int i;
object ob,*players;
players = users();
i = random(sizeof(players));
ob = players[i];
return ob;
}

object npc_name2( )
{
object ob;
string *npc1,*npc2;
npc1 = ({
	"/d/9sky/guzhanchang/npc/shouhuzhe1",
  	"/d/9sky/guzhanchang/npc/shouhuzhe2

",
	"/d/9sky/guzhanchang/npc/shouhuzhe3",
	"/d/9sky/guzhanchang/npc/shouhuzhe4",
	"/d/9sky/guzhanchang/npc/shouhuzhe5",
	"/d/9sky/guzhanchang/npc/shouhuzhe6",
	"/d/9sky/guzhanchang/npc/shouhuzhe7",
	"/d/9sky/guzhanchang/npc/shouhuzhe8",
	"/d/9sky/guzhanchang/npc/shouhuzhe9",
	"/d/9sky/guzhanchang/npc/tianzun",
});
npc2 = ({
	"/d/death/npc/dizhang",
	"/d/death/npc/dizhang1",
	"/d/jjf/npc/chengyaojin",
	"/d/jjf/npc/luocheng",
	"/d/jjf/npc/qinqiong",
	"/d/moon/npc/chimeng",
	"/d/moon/npc/change",
	"/d/moon/npc/xiwangmu",
	"/d/pansi/npc/zixia",
	"/d/pansi/npc/qingxia",
	"/d/lingtai/npc/puti",
	"/d/sea/npc/longwang",
	"/d/qujing/kusong/npc/honghaier",
	"/d/nanhai/npc/guanyin",
	"/d/shushan/npc/jiansheng",
	"/d/qujing/wuzhuang/npc/zhenyuan",
	"/d/sanjie/npc/zhaoyang",
	"/d/youxia/npc/shaolong",
	"/d/youxia/npc/yegucheng",
	"/d/youxia/npc/tianji",
	"/d/youxia/npc/liuxiang",
	"/d/youxia/npc/xiaofeng",
	"/d/emei/npc/li",
	"/d/emei/npc/baimei",
	"/d/shaolin/npc/damo",
	"/d/kunlun/npc/tianzun",
	"/d/swordman/npc/jianxin",
	"/d/tiankongjie/npc/xiewu",
	"/d/tiankongjie/npc/huiming",
	"/d/sfighter/npc/gouki",
	"/d/mojie/npc/kongque",
	"/d/mojie/npc/wu tian",
	"/d/mingjiao/npc/zhangwuji",
});
if ( random(8)>5 )
	ob = new(npc1[random(sizeof(npc1))]);
else
	ob = new(npc2[random(sizeof(npc2))]);
return ob;
}

int do_go(string arg)
{
int pot,i,damage;
object me,env,target;
string msg;
me = this_player();
env = this_object();
pot = me->query_kar();

if ( !arg )
	{
	message_vision(CYN"$N"CYN"象没头苍蝇似的到处乱撞。\n"NOR,me);
	me->add("kee",50+random(150));
	me->add("sen",50+random(150));
	return 0;
	}
if ( random(10)<=3 )
	target = npc_name();
else
	target = npc_name2();

if ( !target )
	return 1;
msg = "$N在浓雾中小心翼翼的往前摸索。\n";
msg+= "到了！$N终于在浓雾中发现一个出口。\n";
message_vision(msg,me);
me->start_busy(random(2));
pot = random(pot);
pot+=random(10);
if ( pot<20 )
	{
	msg="忽然雾气一闪，$W从深处冲了出来！\n";
        msg+=HIR"看起来$W"HIR"像要杀了$N"HIR"!\n"NOR;
	msg = replace_string(msg,"$W",target->query("name"));
	message_vision(msg,me);
        for ( i=0;i<3+random(7);i++ )
		{
		random(2)?
		COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_QUICK):
		COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_REGULAR);
		damage = target->query_temp("apply/damage");
                damage+=target->query_skill("force");
                damage+=target->query_skill("spells");
                if ( wizardp(me) ) tell_object(me,"damage="+damage+"\n");
		me->receive_damage("kee",damage);
		COMBAT_D->report_status(me);
		}
	target->remove_killer(me);
	me->remove_killer(target);
	return 0;
	}
}

void init() 
{ 
add_action("do_none","move"); 
add_action("do_none","mark"); 
add_action("do_none","recall"); 
add_action("do_none","perform");
add_action("do_none","cast");
add_action("do_go","go");
} 

void die(object who)
{
    alternative_die(who);
}

void unconcious(object who)
{
    alternative_die(who);
}
