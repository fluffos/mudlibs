#include <ansi.h>
#include <combat.h>

inherit NPC;
void create()
{
	set_name("宠物", ({ "pet" }) );
	set("race", "野兽");
	set("age", 1);
	set("str",35);
	set("int",15);
	set("per",15);
	set("tol",15);
	set("con",15);
	set("dex",15);
	set("long", "一只小小小小宠物。\n");
	set("owner","R");
	set("limbs", ({ "头部", "身体", "前心", "後背", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("obedience",2);
        set("petdie",1);
	set("combat_exp", 100000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defence",100);
	set("deathstamp",1);
	set_skill("parry", 50 + random(50));
	set_skill("dodge", 50 + random(50));
	set_skill("unarmed", 50 + random(50));
	set_skill("puyaogedou", 50 + random(50));
	map_skill("unarmed", "puyaogedou");
	map_skill("parry", "puyaogedou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.pfm1" :),                
                (: perform_action, "unarmed.pfm2" :),                
                (: perform_action, "unarmed.pfm3" :),                
                (: perform_action, "unarmed.pfm4" :),                
                (: perform_action, "unarmed.pfm5" :),                
                (: perform_action, "unarmed.pfm6" :),                
        }) );


        setup();
}
string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf("/data/user/%c/%s", id[0],id+".pet");
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{	
        int i;
        object owner, *enemy;
	int jing,qi,exp;
	//set("deathstamp",time());
	exp = (int) query("combat_exp");
	jing = (int) query("max_jing");
        qi = (int) query("max_qi");
        if(!environment()->query("no_death_penalty"))
	set("combat_exp",exp/10 * 9);
	set("eff_qi",qi);
	set("eff_jing",jing);
	 set("qi",qi);
        set("jing",jing);
        if(objectp(owner=query("possessed")))
        {
                enemy = query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

        }

	save();	
	::die();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        if(!objectp(this_object()->query("possessed")))
	{
	set_heart_beat(1);	
	save();
	command("emote 一闪就不见了。");
//	message_vision("$N一闪就不见了。\n",this_object());
        destruct(this_object());
//	return;
	}
//	set_heart_beat(1);
}
/*int heal_up()
{
        if(!objectp(this_object()->query("possessed")))
	{
	set_heart_beat(1);	
	save();
	command("emote 一闪就不见了。");
//	message_vision("$N一闪就不见了。\n",this_object());
        destruct(this_object());
	return 1;
	}
	set_heart_beat(1);
        return ::heal_up() ;
}*/

void init()
{
	if(this_player() == query("possessed"))
	{
	add_action("do_order","order");
	add_action("do_modify","modify");
	add_action("do_gongji","gongji");
	add_action("do_teach","xunlian");
	add_action("do_shape","shape");
	add_action("do_eat","giveeat");
	add_action("do_move","fastmove");
	add_action("do_pfm","petpfm");
	}

}

int do_order(string arg)
{
	int obedience;
	object me = this_player();
	me->add("jing",-5);
	obedience = query("obedience");
	if(random(50) < obedience )
	command( "emote " + arg);
	else
	command("emote 很不情愿地哼了一声。");
	return 1;
}
int do_modify(string arg)
{
	string item, msg;
        object me = this_player();
	if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
	return notify_fail("SYNTAX: modify 款项 内容\n");
	if(item == "flee")
	{
		set("env/wimpy", atoi(msg));
                write("ＯＫ\n");
		save();
		return 1;
	}

		
                if(CHINESE_D->check_control(msg))
                return notify_fail("描述不可有控制符！\n");
//		if( i%2==0 && !is_chinese(name[i..<0]) ) {
                if(!is_chinese(msg))
                return notify_fail("描述必需是中文！\n");
                if(CHINESE_D->check_space(msg))
                return notify_fail("描述必需不含空格！\n");
                if(CHINESE_D->check_return(msg))
                return notify_fail("描述必需不含回车键！\n");
	me->add("jing",-10);
	switch(item)
	{
	case "desc":
		if(CHINESE_D->check_length(msg) > 100)
		return notify_fail("描述太长！\n"); 
		set("long",msg+"\n");
		write("ＯＫ\n");
		save();
		return 1;
	case "nickname" :
		if(CHINESE_D->check_length(msg) > 20)
                return notify_fail("描述太长！\n");
		set("nickname",msg);
		write("ＯＫ\n");
		save();
                return 1;
	case "title" :
                if(CHINESE_D->check_length(msg) > 10)
                return notify_fail("描述太长！\n");
                set("title",msg);
                write("ＯＫ\n");
		save();
                return 1;
	case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("描述太长！\n");
                set("arrive_msg",msg);
                write("ＯＫ\n");
		save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("描述太长！\n");
                set("leave_msg",msg);
                write("ＯＫ\n");
		save();
                return 1;

	}
	return notify_fail("你要修改什么？\n");

}
int  do_eat()
{
	object me, ob;
	object gold;
	int cost = 5;
	me = this_player();
        ob = this_object();
        gold = present("gold_money", this_player());
        if( !gold) return notify_fail("你身上没有金子。\n");

        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");

        if((int) gold->query_amount() < cost)
        return notify_fail("你身上没带够" + sprintf("%d",cost)+ "两金子。\n");
        gold->add_amount(-cost);
        if( ob->query("food") >= ob->max_food_capacity() )
        return notify_fail("它已经吃太饱了，再也塞不下任何东西了。\n");
  	ob->set("food", ob->max_food_capacity());
	ob->set("water",ob->max_water_capacity());
        me->start_busy(2);
        command("emote 高兴的叫了一声。");
        command("emote 接着一口把黄金给吃了。");
        	return 1;
}

int do_gongji(string arg)
{
	object me,obj;
	me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

if( query_temp("is_rided_by"))
return notify_fail("你的宏物不是正被你骑着吗!\n");

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

      if( environment(me)->query("no_fight") )
        return notify_fail("这里不准战斗。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
  
       if( obj->query_temp("no_kill") )
        return notify_fail("不能打，打不得啊！\n");


        if((int)obj->query("age") <= 17 && userp(obj))
        return notify_fail("为了世界更美好，放过小孩子吧.\n");

        if(userp(obj) && (int)obj->query("combat_exp") < this_object()->query("combat_exp"))
        return notify_fail("宏物不能向比自己低的玩家进攻.\n");

	message_vision(
	sprintf("$N对$n一指，对%s命令道：＂上！＂\n",this_object()->name()),me,obj);
        me->add("jing",-5);
	add("jing",-10);
        if(random(50) > query("obedience") )
        command("emote 很不情愿地哼了一声。");
	else
	kill_ob(obj);
	return 1;
	
}

int do_teach(string arg)
{
	object me;
	int gin_cost,amount;
        int myskill, itskill;
	me = this_player();
	if(!myskill = me->query_skill(arg,1))
	return notify_fail("这项技能你好象还不会呢！\n");
	if(arg != "unarmed" && arg != "dodge" && arg != "parry"  && arg != "puyaogedou")
	return notify_fail("它学不会这项技能的！\n");
	itskill = query_skill(arg,1);
	if(myskill <= itskill)
	return notify_fail(name()+"以嘲笑的目光望着你。\n");
	if((int)me->query("potential")-(int)me->query("learned_points") < 2)
	return notify_fail("你的潜能不够！\n");
	gin_cost =  (int) query_int();
	if((int)me->query("jing") < gin_cost)
	return notify_fail("你显然太累了没有办法教！\n");
	me->receive_damage("jing",gin_cost);
	me->add("potential",-2);
	amount = (int)me->query("int") * (int) query("int");
	message_vision(sprintf("$N不厌其烦地教$n「%s」。\n",to_chinese(arg)),me,this_object());
	  if(random(50) > query("obedience") )
        command("emote 很不情愿地哼了一声。");
	else 
	{
       improve_skill(arg,amount);
       improve_skill("puyaogedou", random(me->query_int()/2));
	message_vision(sprintf("$N似乎真的学会了一些「%s」！\n",to_chinese(arg)),this_object());
	}
	return 1;

}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int do_shape(string arg)
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
	my = query_entire_dbase();
	 printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);
printf("精力：%s%3d/ %3d %s(%3d%%)   气血：%s%3d/ %3d %s(%3d%%)\n",
                status_color(my["jing"], my["eff_jing"]), my["jing"],my["eff_jing"],
                status_color(my["eff_jing"], my["max_jing"]),     my["eff_jing"] * 100 / my["max_jing"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]),     my["eff_qi"] * 100 / my["max_qi"]            
	);		
	printf("主人： "HIW"%s"NOR"\t\t经验： %d\t\t"HIR"杀气： %d\n"NOR,
	my["owner"], my["combat_exp"],my["bellicosity"]
	);
        printf("才智： %d\t\t体质： %d\t\t体态： %d\n",
        query_int(), query_con(),query_per()
        );
        printf("速度： %d\t\t力量： %d\t\t灵性： %d\n",
        query_dex(), query_str(),query_kar()
        );
          printf("驯服度： "HIM"%d"NOR"\t\t个性： %d\n",
         query_obe(), query_tol()
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf(HIB"攻击力： %d\t\t\t\t"NOR+HIY"防御力： %d\n\n"NOR,
        at_pt+1, pa_pt/2+do_pt/2+1
        );
	printf("/cmds/skill/skills"->pet_skill(this_object()));
	 printf(HIC"≡"HIY"──────────────────────────────"HIC"≡\n"NOR);return 1;
}
void unconcious()
{
object me;string file;
me=this_player();
add("petdie",1);
if (query("petdie")>10)
{
me->delete("marks/pet");
write(HIR"你的宏物,由于收伤过多,而死亡了\n"NOR);
}
die();
}

int do_move(string arg)
{

          string pla;
          object me = this_player();
 if( query("up1") < 2 )
return notify_fail("你的宏物还没有到终级.\n");
if(!query_temp("is_rided_by"))
return notify_fail("你还没有骑上你的宏物呢!\n");
if( !me->query_temp("is_riding") )
return notify_fail("你还没有骑上你的宏物呢!\n");

if( me->query("jing") < 50 )
               return notify_fail("你精神不够旺盛，宏物跑得这么快！你吃不消的!\n");
if( me->is_busy())
return notify_fail("你现在在正忙着呢!\n");

if( !environment(me)->query("no_fight"))
{
  message_vision("只有在安全区域才能让宏物飞跑!!!\n"
                 ,me);
      	return 1;
}
          if (!arg)
              return notify_fail("你想去哪里呢？\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("这么危险，宏物怎么跑呢?\n");

          else {
          message_vision(HIG
"$N对着自己的宏物做了一个手势,然后飞身跃上，身手很是矫捷。。\n"+
"$N爬上自己的宏物，大喝一声“去吧”，只见宏物向外飞跑而去。。。\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/city2/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";

               else {
               message_vision(HIR
"宏物跑了半天,没找到要去的地方！\n"NOR, me);
               message_vision(HIR
"目前你可以去的地方有如下:
天安门(tam) 大理(dl) 泉州(qz) 少林(shl)华山(hs) 灵鹫(lj)  
 武当(wd)    明教(mj) 扬州(gc) 星宿(xx) 雪山(xs) 峨眉(em)  
全真(quz)  白驼山(bt) 古墓(gm) 苏州(sz)归云庄(gyz)襄阳(xy)  \n"NOR, me);

}
     if (me->move(pla)) {
       message_vision(HIC"\n到了！你飞身一跃,跳下自己的宏物。\n"NOR,me);
me->add("jing",-30);
me->start_busy(4);
}
     return 1;
}


int do_pfm(string arg)
{
	int obedience;
	object me = this_player();
if( query("up1") < 1 )
return notify_fail("你的宏物还没有这个能力.\n");
if( !is_fighting())
return notify_fail("你的宏物现在没有站斗啊?\n");
if( query_temp("is_rided_by"))
return notify_fail("你的宏物不是正被你骑着吗!\n");

if( me->is_busy())
return notify_fail("你现在正忙着呢!!\n");
if( me->query("jing") < 50 )
   return notify_fail("你精神不够旺盛！你吃不消的!\n");


	me->add("jing",-5);
        me->start_busy(random(7));
	obedience = query("obedience");
	if(random(50) < obedience )
{
	command("emote 大声努吼了一下。");
command("perform pfm1");
command("perform pfm2");
command("perform pfm3");
command("perform pfm4");
command("perform pfm5");
command("perform pfm6");
}
	else
	command("emote 很不情愿地哼了一声。");
	return 1;
}

