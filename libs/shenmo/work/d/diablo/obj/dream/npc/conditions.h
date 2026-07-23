object offensive_target(object me)
{
int sz;
object *enemy;

enemy = me->query_enemy();
if( !enemy || !arrayp(enemy) ) return 0;

sz = sizeof(enemy);
if( sz > 4 ) sz = 4;
if( sz > 0 ) return enemy[random(sz)];
else return 0;
}

void taishi_condition(object me,object hs) 
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,add_armor,add_dodge,add_kee,add_sen,add_spells,add_damage,i;
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

add_armor=(mj+1)*(4+lvl);
if ( add_armor<100 ) add_armor=100;
if ( add_armor>1000 ) add_armor=1000;

add_dodge=(mj+lvl)*5;
if ( add_dodge<50 ) add_dodge=50;
if ( add_dodge>200 ) add_dodge=200;

add_kee=(qz+1)*(5+lvl/5);
if ( add_kee<500 ) add_kee=500;
if ( add_kee>5000 ) add_kee=5000;

add_sen=(qz+1)*(5+lvl/5);
if ( add_sen<500 ) add_sen=500;
if ( add_sen>5000 ) add_sen=5000;

tell_object(me,hs->name()+HIY"覆盖你全身，你觉得自己更加强壮了！\n"NOR);
me->add("max_kee",add_kee);
me->add_temp("add_kee",add_kee);
me->add("max_sen",add_sen);
me->add_temp("add_sen",add_sen);
me->add_temp("apply/dodge",add_dodge);
me->add_temp("add_dodge",add_dodge);
me->add_temp("apply/armor",add_armor);
me->add_temp("add_armor",add_armor);
me->set("kee",(int)me->query("max_kee"));
me->set("eff_kee",(int)me->query("max_kee"));
me->set("sen",(int)me->query("max_sen"));
me->set("eff_sen",(int)me->query("max_sen"));
time=jl;
time+=lvl;
time/=2;	
if ( time<3 ) time=3;
if ( time>60 ) time=60;
call_out("huanyuan",time,me,hs);
remove_call_out("taishi_condition");
call_out("taishi_condition",2+random(3),me,hs);
}

void taichu_condition(object me,object hs) 
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,add_armor,add_dodge,add_kee,add_sen,add_spells,add_damage,i;
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

add_armor=(mj+lvl)*2;
if ( add_armor<10 ) add_armor=10;
if ( add_armor>200 ) add_armor=200;

add_damage=(mj+lvl)*5;
if ( add_damage<30 ) add_damage=30;
if ( add_damage>300 ) add_damage=300;

add_spells=(mj+lvl)*2;
if ( add_spells<10 ) add_dodge=10;
if ( add_spells>100 ) add_dodge=100;

tell_object(me,hs->name()+HIB"的蓝光在你全身游离，你觉得自己更加厉害了！\n"NOR);
me->add_temp("apply/damage",add_damage);
me->add_temp("add_damage",add_damage);
me->add_temp("apply/spells",add_spells);
me->add_temp("add_spells",add_spells);
me->add_temp("apply/armor",add_armor);
me->add_temp("add_armor",add_armor);

time=jl;
time+=lvl;
time/=2;	
if ( time<3 ) time=3;
if ( time>60 ) time=60;
call_out("huanyuan",time,me,hs);
remove_call_out("taichu_condition");
call_out("taichu_condition",2+random(3),me,hs);
}

void tu_condition(object me,object hs) //土 busy
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time;
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");


if( me->is_fighting() ) 
	{
	target = offensive_target(me);
	if ( environment(target)!=environment(me) ) return ;    

	msg =YEL"\n
"NOR+hs->name()+YEL"突发异彩，$n立刻只觉得脚下大地撼动，难以立足！\n"NOR;

	ap = me->query("combat_exp");
	dp = target->query("combat_exp");

	if( random(ap + dp) > dp )
		{
		spells_time=jl/5;
		if ( spells_time<1 ) spells_time=1;
		if ( spells_time>5 ) spells_time=5;
		msg+=YEL"
$n立刻吓得魂飞魄散，手足无措，哪里还动弹得了？！\n"NOR;
		target->start_busy(1+random(spells_time));
		}
	else msg+=YEL"\n
$n忙收敛心神，站稳脚步！\n"NOR;
	message_vision(msg,me,target);
	remove_call_out("tu_condition");
	call_out("tu_condition",2+random(3),me,hs);
	}
else tell_object(me,hs->name()+HIY"永远守护着你。\n"NOR);
time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);
}

void feng_condition(object me,object hs) //风 busy
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,damage;
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

if( me->is_fighting() &&target) 
	{
	target = offensive_target(me);
	if ( environment(target)!=environment(me) ) return ;    

	msg =CYN"\n
"NOR+hs->name()+CYN"突发异彩，一道猛烈无比的旋风立刻卷向$n！\n"NOR;
	ap = me->query("combat_exp");
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp )
		{
		spells_time=jl/5;
		damage=50*jl;
		if ( spells_time<1 ) spells_time=1;
		if ( spells_time>5 ) spells_time=5;
		if ( damage<50 ) damage=50;
		if ( damage>1000 ) damage=1000;
		msg+=CYN"
$n闪避不及，给狂风卷得在半空翻滚不定！\n"NOR;
		target->start_busy(1+random(spells_time));
              target->receive_damage("sen", damage);
              target->receive_wound("sen", damage/2);
		COMBAT_D->report_status(target);
		}
	else   {
		random(2)?
			msg+=YEL"\n
$n一个野驴打滚，闪开了风头！\n"NOR:
			msg+=YEL"\n
$n轻蔑一笑，鹤立于风头之上，好不逍遥！\n"NOR;
		}
	message_vision(msg,me,target);
	remove_call_out("feng_condition");
	call_out("feng_condition",2+random(3),me,hs);
	}
else tell_object(me,hs->name()+HIY"永远守护着你。\n"NOR);
time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);
}

void huo_condition(object me,object hs) //火 eff_kee,eff_sen
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,damage;
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

if( me->is_fighting() &&target) 
	{
	target = offensive_target(me);
	if ( environment(target)!=environment(me) ) return ;    

	msg =HIR"\n
"NOR+hs->name()+HIR"突发异彩，一团炙热无比的烈炎立刻卷向$n！\n"NOR;
	ap = me->query("combat_exp");
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp )
		{
		damage=50*jl;
		if ( damage<50 ) damage=50;
		if ( damage>1000 ) damage=1000;
		msg+=CYN"
$n闪避不及，给狂风卷得在半空翻滚不定！\n"NOR;
              target->receive_wound("kee", damage/2);
              target->receive_wound("sen", damage/2);
		COMBAT_D->report_status(target);
		}
	else   {
		random(2)?
			msg+=HIR"\n
$n一个旱地拔葱，跃过了火焰！\n"NOR:
			msg+=HIR"\n
$n哈哈一笑，张口一吹，吹歪了火向！\n"NOR;
		}
	message_vision(msg,me,target);
	remove_call_out("huo_condition");
	call_out("huo_condition",2+random(3),me,hs);
	}
else tell_object(me,hs->name()+HIY"永远守护着你。\n"NOR);

time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);
}

void lei_condition(object me,object hs) //雷 kee eff_kee eff_sen
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,damage,i;
qz=hs->query("qz"); //强壮 影响所加气血
mj=hs->query("mj"); //敏捷 影响所加防御
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

if( me->is_fighting() &&target) 
	{
	target = offensive_target(me);
	if ( environment(target)!=environment(me) ) return ;    

	msg =HIM"\n
"NOR+hs->name()+HIM"忽然闪动起来，随之一道电光班驳的光柱从天而降，落卷向$n！\n"NOR;
	ap = me->query("combat_exp");
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp )
		{
		damage=50*jl;
		if ( damage<50 ) damage=50;
		if ( damage>1000 ) damage=1000;
		msg+=HIM"
电光一闪，$n一身惨叫，浑身给电得皮肉模糊，抽搐不止！\n"NOR;
              target->receive_wound("kee", damage/2);
              target->receive_wound("sen", damage*2/3);
              target->receive_damage("sen", damage);
		COMBAT_D->report_status(target);
		}
	else   {
		random(2)?
			msg+=HIM"\n
$n连滚带爬，躲过了电击！\n"NOR:
			msg+=HIM"\n
$n将兵器对地一插，将电花引入了脚下。\n"NOR;
		}
	message_vision(msg,me,target);
	remove_call_out("lei_condition");
	call_out("lei_condition",2+random(3),me,hs);
	}
else tell_object(me,hs->name()+HIY"永远守护着你。\n"NOR);
time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);
}

void shui_condition(object me,object hs) // 水,busy kee,sen
{
string msg,sx;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,add_kee,add_sen;
qz=hs->query("qz"); //强壮 影响所加气血
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

msg =HIW"\n
"NOR+hs->name()+HIW"上忽然发出一道柔和的波纹，$N整个人沐浴在其中，好似渐渐恢复了气力！\n"NOR;
message_vision(msg,me,hs);
add_kee=jl+qz+lvl;
add_kee*=100;
add_kee=add_kee/2+random(add_kee/2);
if ( add_kee<100 ) add_kee=100;
if ( add_kee>800 ) add_kee=800;
add_sen=add_kee;
me->add("kee",add_kee);
me->add("sen",add_sen);
if ( me->query("kee")>=me->query("eff_kee") )
	me->set("kee",me->query("eff_kee") );
if ( me->query("sen")>=me->query("eff_sen") )
	me->set("sen",me->query("eff_sen") );

time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);

remove_call_out("shui_condition");
call_out("shui_condition",2+random(3),me,hs);
}

void light_condition(object me,object hs) // 光 kee,sen
{
string msg,sx;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,add_kee,add_sen;
qz=hs->query("qz"); //强壮 影响所加气血
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

msg =WHT"\n
"NOR+hs->name()+WHT"上忽然发出一道柔和的光线，将$N整个人包裹在其中！\n"NOR;
message_vision(msg,me,hs);
tell_object(me,WHT"你觉得自己的气力渐渐恢复了。。。\n"NOR);
add_kee=jl+qz+lvl;
add_kee*=100;
if ( add_kee<500 ) add_kee=500;
if ( add_kee>2000 ) add_kee=2000;
add_sen=add_kee;
me->add("eff_kee",add_kee);
me->add("eff_sen",add_sen);
if ( me->query("eff_kee")>=me->query("max_kee") )
	me->set("eff_kee",me->query("max_kee") );
if ( me->query("eff_sen")>=me->query("max_sen") )
	me->set("eff_sen",me->query("max_sen") );
me->set("kee",me->query("eff_kee") );
me->set("sen",me->query("eff_sen") );

time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);

remove_call_out("light_condition");
call_out("light_condition",2+random(3),me,hs);
}

void dark_condition(object me,object hs) //暗黑 pfm
{
string msg,sx;
object target;
int ap,dp,qz,mj,ll,jl,lvl,time,spells_time,damage,i;
ll=hs->query("ll"); //力量 影响物理攻击
jl=hs->query("jl"); //精力 影响法术攻击
lvl=hs->query("lvl"); //等级
sx=hs->query("shuxing");

if( me->is_fighting() &&target) 
	{
	target = offensive_target(me);

	if ( environment(target)!=environment(me) ) return ;    

	msg =RED"\n
"NOR+hs->name()+RED"忽然闪出一道奇异的光线笼罩住$N全身！
$N只觉浑身杀气腾腾，看谁都不顺眼。\n"NOR;
	ap = me->query("combat_exp");
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp )
		{
		spells_time=jl+qz+lvl;
		spells_time/=3;
		if ( spells_time<1 ) spells_time=1;
		if ( spells_time>10 ) spells_time=10;
		msg+=RED"\n$N身随心动，任由气驭，对着$n就是一招！\n"NOR;
		COMBAT_D->do_attack(me,target,me->query_temp("weapon"));         
		for ( i=0;i<spells_time;i++ )
			{		
			msg+=RED"\n$N一招发出，双目精光四谢，发狂般向$n又攻出一招！\n"NOR;
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"));         
			COMBAT_D->report_status(target);
			}
		}
	else   msg+=RED"\n"NOR;
	message_vision(msg,me,target);
	remove_call_out("dark_condition");
	call_out("dark_condition",2+random(3),me,hs);
	}
else tell_object(me,hs->name()+HIY"永远守护着你。\n"NOR);

time=jl;
time+=lvl;
time/=2;	
if ( time<5 ) time=5;
if ( time>30 ) time=30;
call_out("huanyuan",time,me,hs);

}


void huanyuan(object me,object hs)
{
string msg;
msg=HIY"\n
"+hs->name()+NOR HIY"渐渐又幻化成"+hs->query("name")+HIY"守侯在$N的身旁。\n"NOR;

if ( !hs->query_temp("no_heal_up/bian") )
	return;

remove_call_out("bianshen");
remove_call_out("tu_condition");
remove_call_out("lei_condition");
remove_call_out("shui_condition");
remove_call_out("huo_condition");
remove_call_out("feng_condition");
remove_call_out("dark_condition");
remove_call_out("light_condition");
remove_call_out("taichu_condition");
remove_call_out("taishi_condition");

hs->delete_temp("spellslevel");
hs->delete_temp("no_heal_up/bian");
hs->delete_temp("apply/name");
hs->delete_temp("apply/id");
hs->delete_temp("apply/long");
if ( environment(me)!=environment(hs) )
	hs->move(environment(me));
if ( me->query_temp("add_damage") )
	me->add_temp("apply/damage",-(int)me->query_temp("add_damage"));
if ( me->query_temp("add_dodge") )
	me->add_temp("apply/dodge",-(int)me->query_temp("add_dodge"));
if ( me->query_temp("add_armor") )
	me->add_temp("apply/armor",-(int)me->query_temp("add_armor"));
if ( me->query_temp("add_spells") )
	me->add_temp("apply/spells",-(int)me->query_temp("add_spells"));
if ( me->query_temp("add_kee") )
	me->add_temp("max_kee",-(int)me->query_temp("add_kee"));
if ( me->query_temp("add_sen") )
	me->add_temp("max_sen",-(int)me->query_temp("add_sen"));
me->delete("bianhuan");
hs->save();
me->save();	
message_vision(msg,me,hs);
return;
}

