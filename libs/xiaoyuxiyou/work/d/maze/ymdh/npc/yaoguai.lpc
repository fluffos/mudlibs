inherit NPC;
#include <ansi.h>

string _invocation(object who, int level);

string *death_msg= ({
        HIG"\n$n"HIG"一看不是$N"HIG"的对手，只得就地一滚，变回原形，打了几个转，老老实实地走开了。"NOR"\n\n",
        HIG"\n$n"HIG"大叫一声“我服了，我服了，我投降。。”乖乖地伏在$N"HIG"脚下不动了。$N手"HIG"一挥，$n"HIG"如蒙大赦，驯服地走开了。"NOR"\n\n",
});

void _leave();
void leave();
void leave2();

int kee = 0;
int sen = 0;

void setname()
{
	object *tmp,*obj,who;
	int i;
	string *ids;
	mapping name;
	obj = users();
	tmp = ({});
	for(i=0;i<sizeof(obj);i++)
	{
		if( !obj[i] || !living(obj[i]) 
		 || !environment(obj[i])
		 || !objectp(obj[i]) 
		 || wizardp(obj[i]) )
			continue;
		tmp+= ({obj[i]});
	}
	if( !tmp || !arrayp(tmp) || sizeof(tmp)<1 )
	{
		name = NAME_D->random_name("yaoguai");
		ids = name["id"];
		ids+= ({"mo","yaomo"});
		set_name(name["name"],ids);
		set("gender",random(2)?"男性":"女性");
	}
	else
	{
		who = tmp[random(sizeof(tmp))];
		if( !who )
		{
			name = NAME_D->random_name("yaoguai");
			ids = name["id"];
			ids+= ({"mo","yaomo"});
			set_name(name["name"],ids);
			set("gender",random(2)?"男性":"女性");
		}
		else
		{
			set_name(who->query("name"),({who->query("id"),"yaomo","mo","yao"}));
			set("gender",who->query("gender"));
			if( who->query("title") )
				set("title",who->query("title"));
		}
	}	
}

void create()
{
	setname();
	set("chat_chance", 20);
	set("chat_msg", ({
        	(: random_move :)
	}) );
	set("age", 20+random(80));
	set("attitude", "aggressive");
	setup();
}

int random_move()
{
	if( this_object()->is_fighting() )
		return 0;
	return ::random_move();	
}

void set_skills(int j){ }

//me=NPC ob=owner lv=job_level
int copy_status(int lvl)
{
	int i;
	mapping skill;
	string *skills;

	set_level(lvl);
	set("chat_chance_combat",(200-lvl)/2);
	set_skills(lvl);	
	set("bellicosity",300+random(300));
	setup();
	powerup(0,1);
	kee = sen = 0;
	set("force",this_object()->query_maxforce()*2);
	set("mana",this_object()->query_maxmana()*2);
	set("force_factor",this_object()->query_maxforce()/20+1);
	set("mana_factor",this_object()->query_maxmana()/20+1);
	return 1;
}

void _leave()
{
	object me = this_object();
	if( me->is_fighting() || me->is_busy() )
        	return;
	leave();
}

void leave()
{
	if( this_object() ) 
        { 
        	if( environment() )
                	message("vision",HIB"\n" + name() + HIB"身子一晃，变成一股青烟散去了。\n" NOR,environment());
        	this_object()->move("/obj/empty");
        	remove_call_out("leave2");
        	call_out("leave2",5);
        }
}

void leave2()
{
	if( this_object() ) 
        	destruct(this_object());
}


void init()
{
	::init();
	add_action("do_go","go");
}

int do_go(string arg)
{
	if( !userp(this_player()) )
		return 0;
	if( !this_object()->is_fighting() )
	{
		EMOTE_D->do_emote(this_object(), ({"kick","pk","tuzi","spear","heihei","grin",})[random(6)],geteuid(this_player()),CYN,0,0,0);
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
		return 1;
	}
	else if( this_object()->is_fighting(this_player()) )
		return err_msg(name()+"一把拉住你：哪里走？！\n");
	else	return 0;
}

void kill_ob(object who)
{
	object target;
	if( !who || !objectp(who) || !environment() )
		return;
	if( !environment()->is_ymdh() )
	{
		EMOTE_D->do_emote(this_object(), "pei",geteuid(who),CYN,0,0,0);	
		say(CYN+name()+CYN"说道：这里是哪里？！\n"NOR);
		remove_all_killer();
		all_inventory(environment())->remove_killer(this_object());
		return;
	}
	if( !userp(who) )
	{
		if(objectp(who->query_temp("invoker")))
			target = who->query_temp("invoker");
		else
		{
			EMOTE_D->do_emote(this_object(), "pei",geteuid(who),CYN,0,0,0);	
			say(CYN+name()+CYN"说道：你这等小虾米，大爷懒得理！\n"NOR);
			remove_killer(who);
			who->remove_killer(this_object());
			return;
		}
	}
	else	target = who;
	if( !this_object()->is_fighting() )
	{
		this_object()->set_temp("my_killer",target);
		powerup(0,1);
		kee = sen = 0;
		::kill_ob(who);
		return;
	}
	else if( !query_temp("my_killer") )
	{
		remove_all_killer();
		all_inventory(environment())->remove_killer(this_object());
		this_object()->set_temp("my_killer",target);
		powerup(0,1);
		kee = sen = 0;
		::kill_ob(who);
		return;
	}
	else if( query_temp("my_killer")!=target )
	{
		EMOTE_D->do_emote(this_object(), "pei",geteuid(who),CYN,0,0,0);	
		say(CYN+name()+CYN"说道：尔等以多欺少，大爷不伺候！\n"NOR);
		remove_killer(who);
		who->remove_killer(this_object());
		return;			
	}
	else	::kill_ob(who);
}

varargs int receive_damage(string type, int damage, object who,mixed attack_type)
{
	if( !who || who==this_object() 
	 || !query_temp("my_killer") || who!=query_temp("my_killer") )
	{
		damage = 0;
		return ::receive_damage(type,damage,who,attack_type);
	}
	if( type=="kee" )
		kee+= damage;
	else	sen+= damage;
	return ::receive_damage(type,damage,who,attack_type);
}

varargs int receive_wound(string type, int damage, object who,mixed attack_type)
{
	if( !who || who==this_object() 
	 || !query_temp("my_killer") || who!=query_temp("my_killer") )
	{
		damage = 0;
		return ::receive_wound(type,damage,who,attack_type);
	}
	if( type=="kee" )
		kee+= damage;
	else	sen+= damage;
	return ::receive_wound(type,damage,who,attack_type);
}

void dies()
{
	string str;
	int reward,p1,p2,maxkee,maxsen;
	object who,ye;
	who = query_temp("last_damage_from");
	
	powerup(0,1);
	if( !who )
		message_vision(HIR"\n$N"HIR"惨叫一声，化作一阵红雾消散在空气中。\n\n"NOR,this_object());
	else	message_vision(death_msg[random(sizeof(death_msg))],who,this_object());
	
	who = query_temp("my_killer");
	if( !who  || !environment()->is_ymdh() 
	 || !who->query_temp("maze/ymdh")
	 || !objectp(ye=who->query_temp("maze/ymdh_ye")) )
	{
		destruct(this_object());
		return;
	}
	reward = environment()->check_palyer_level(who);
	if( reward<=0 )
	{
		destruct(this_object());
		return;
	}
	reward = reward*3/2;
	reward = reward*2/3+random(reward/3);
	maxkee = this_object()->query_maxkee();
	p1 = kee*100/maxkee+50;
	if( p1>=100 )
		p1 = 100;
	maxsen = this_object()->query_maxsen();
	p2 = sen*100/maxsen+50;	
	if( p2>=100 )
		p2 = 100;
	if( p1<p2 )
		p1 = p2;
	reward = reward*p1/100;
	QUEST_D->job_reward_player(who,"combat_exp",reward,"妖魔大会");		
	if( random(2) )
		str = "妖魔大会："+this_object()->name()+"被"+who->name()+"杀死了，"+who->name()+"得到了"+reward+"点武学经验。\n";
	else	str = "妖魔大会："+who->name()+"杀死了"+this_object()->name()+"，得到了"+reward+"点武学经验。\n";
	ye->announce(str);
	who->save(1);	
	who->add_temp("ymdh/yaomokilled",1);
	tell_object(who,HIW"【妖魔大会】你已杀死了"+chinese_number(who->query_temp("ymdh/yaomokilled"))+"个妖魔。"NOR"\n");
	destruct(this_object());
}

void die()
{
	QUEST_D->addEffKee(this_object());
	QUEST_D->addKee(this_object());
	QUEST_D->addSen(this_object());
	QUEST_D->addEffSen(this_object());
	if( query("kee")<=0 || query("sen")<=0 
	 || query("eff_kee")<=0 || query("eff_sen")<=0 )
        	dies();
}

void unconcious(){die();}	