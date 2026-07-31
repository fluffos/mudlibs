#include <ansi.h>;
inherit SUPER_NPC;

object query_gy(){ return query("guangyun");}

void set_skills(int j)
{
        set_skill("unarmed", j);
        set_skill("dodge", j);
        set_skill("parry", j);
        set_skill("force", j);
        set_skill("spells", j);
	set_skill("stick", j);
        set_skill("qianjun-bang", j);
        map_skill("stick","qianjun-bang");
        map_skill("parry", "qianjun-bang");
        set_skill("jindouyun", j);
        set_skill("wuxiangforce", j);
        set_skill("puti-zhi", j);
        set_skill("dao", j);
        map_skill("force", "wuxiangforce");
        map_skill("spells", "dao");
        map_skill("dodge", "jindouyun");
        map_skill("unarmed", "puti-zhi");
	carry_object(0,"armor",1)->wear();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"pifeng",1)->wear();
	carry_object(0,"kui",1)->wear();
	carry_object(0,"shoes",1)->wear();
	carry_object(0,"shield",1)->wear();
	carry_object(0,"hand",1)->wear();
	carry_object(0,"neck",1)->wear();
	carry_object(0,"ring",1)->wear();
	carry_object(0,"waist",1)->wear();
	carry_object(0,"wrists",1)->wear();
	carry_object(0,"stick",1)->wield();
}

void create()
{
	set_name("三头六臂任务",({"stlb job",}));
	set("age",18+random(30));
	set("gender","男性");
	set("class", "taoist");
	set("title","广筠子分身");
	create_family("方寸山三星洞", 2, "首徒");
	set("attitude", "heroism");
	setup();
}

void leave()
{
	if(environment())
        	message("vision",HIY"\n\n广筠子将身一摇，收起了分身。\n\n"NOR,environment());
	if( query_gy() )
		query_gy()->finish_stlb();		
	destruct(this_object());
}

int copy_status(object ob)
{
	int i, k,level,max_skill;

	if( !ob || !environment(ob) )
		return 0;
	level = ob->query_level();
	if( level<40 )
		level = 40;
	this_object()->set_level(level);
	max_skill = QUEST_D->maxSkill(ob);
	if( max_skill>level*10 )
		max_skill = level*10;
	if( max_skill<=400 )
		max_skill = 400;
	set_skills(max_skill);	
	set("bellicosity",ob->query("bellicosity")/3*2+1);
	set("owner", ob->query("id"));
	set("owner_ob", ob);
	if( random(10)<6 ) 
        	set("type","aggressive");
	else    set("type","normal");
	set_name(ob->query("name"),ob->parse_command_id_list());
	setup();
	add_temp("apply/max_kee",2000+level*5);
	add_temp("apply/max_sen",2000+level*5);
	add_temp("apply/max_force",2000+level*2);
	add_temp("apply/max_mana",2000+level*2);
	add_temp("apply/combat_damage",200+level);
	add_temp("apply/spells_damage",200+level);
	add_temp("apply/combat_def",200+level);
	add_temp("apply/spells_def",200+level);
	powerup(0,1);
	set("force_factor",this_object()->query_maxforce()/25+1);
	set("mana_factor",this_object()->query_maxmana()/25+1);
	if( !this_object()->move(environment(ob)) )
		return 0;
	return 1;
}

string invocation(object who)
{
	if( !who )  
		return 0;
	if( !copy_status(who) )
	{
		leave();
		return 0;
	}
	return HIY"广筠子手捻口诀，念动真言，摇身一变，顿时化出一道分身，和$N"HIY"一般无二！\n"NOR;
}

int accept_object (object who, object ob){return 0;}

void die()
{
	if( environment() )
		message("vision",HIY"\n\n广筠子将身一摇，收起了分身，摇了摇头道：万不可以杀止杀。。。\n\n"NOR,environment());
	if( query_gy() )
		query_gy()->finish_stlb();		
        destruct(this_object());
}

void combat_lose(object me)
{
	object puti;
	powerup(0,1);
	if( !me || !living(me) )
		return;
	remove_killer(me);
	me->remove_killer(this_object());
    	this_object()->delete_temp("last_opponent");
	if( !me->is_knowing("puti_stlb") && me==query("owner_ob") )
	{
		puti = find_object("/d/lingtai/npc/puti");
		if( puti )
			puti->command("chat* haha");
		puti = find_object("/d/lingtai/npc/guangyun");
		if( puti )
			puti->command("chat* gongxi");
		me->set_knowing("puti_stlb",1);
		me->save();
		CHANNEL_D->do_channel(this_object(),"rumor","听说"HIY+me->name()+HIM"领悟了三星洞绝学「"HIY"三头六臂"HIM"」！"NOR);	
	}
	remove_call_out("leave");
	call_out("leave",5);
    	return;
}

void combat_win(object me)
{
	powerup(0,1);
	if( !me || !living(me) )
		return;
	remove_killer(me);
	me->remove_killer(this_object());
	message("vision",HIY"\n\n广筠子将身一摇，收起了分身，摇了摇头道：还需努力。。。\n\n"NOR,environment());
	if( me==query("owner") )
		me->set("family/stlb_fail",time());
	remove_call_out("leave");
	call_out("leave",5);
    	return;
}