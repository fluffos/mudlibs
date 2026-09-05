// qiangdao.c 强盗
// By Zine 2010 Nov 13 图片版慕容


inherit NPC;
#include <ansi.h>
#include "banhe_bonus.h"
void move();
void auto_perform();
int ask_fight();

void create()
{
    string weapon;
    string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
    set("gender", "男性");
    set("age", 20+random(40));
    set("long", "他是一个形迹可疑的人。\n");
    set("random_npc",1);
    set("attitude", "peaceful");
    set_skill("sword", 250);
	set_skill("parry",250);
	set_skill("dodge", 250);
	set_skill("force",250);
	set_skill("literate",250);
	set_skill("taiyi-zhang",250);
	set_skill("strike",250);
	set_skill("taiyi-jian",250);
	set_skill("taiyi-shengong",250);
	set_skill("taiyi-you",250);
	map_skill("parry","taiyi-zhang");
	map_skill("sword","taiyi-jian");
	map_skill("force","taiyi-shengong");
	map_skill("dodge","taiyi-you");
	map_skill("strike","taiyi-zhang");
	prepare_skill("strike","taiyi-zhang");
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
	(: auto_perform :),
      }));
    set("chat_chance", 20);
    set("chat_msg", ({
	(: random_move :)
      }) );
	add("inquiry", ([
        "fight" : (:ask_fight:),
	]));
    set_temp("apply/attack", 10);
    set_temp("apply/defense", 20);
    set_temp("apply/armor", 20);
    set("init_time",time());
    setup();

    if(random(5)==0)
	add_money("gold", random(2));
    if(random(4)==1)
	add_money("silver", 20+random(8)*10);
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
	call_out("leave",15);
}

void init()
{
    add_action("do_none", "steal");
    add_action("do_none", "attack");
    add_action("do_none", "beg");
    if(random(4)>1&&this_player()==query("killer"))
	kill_ob(this_player());
}
void auto_perform()
{
    object *enemy,target, weapon;
    int k;
    enemy = query_enemy();
    target = enemy[random(sizeof(enemy))];
    if (!living(this_object()))
    return;
    command("exert powerup");
    command("exert recover");
    weapon = this_object()->query_temp("weapon");
    if (!weapon && random(2))
    {
	weapon = new("/clone/weapon/sword/qingfeng");
	weapon->move(this_object());
    weapon->set("no_get",1);
	weapon->set("no_sell",1);
	weapon->set("no_store",1);
	weapon->set("value", 0);
    }
    k = random(3);
    switch (k)
    {
    case 0:
	command("unwield jian");
	command("perform strike.jianzhang " + target->query("id"));
	command("wield jian");
	break;
    case 1:
	command("perform dodge.lingxu");
	break;
    case 2:
	command("wield jian");
	command("perform sword.jianqi " + target->query("id"));
	break;
    
    }        
}
void leave()
{
    object ob = this_object();
    object me = ob->query("killer");
    if (!me||time()-query("init_time")>1800) 
	{
		message_vision(HIC+"$N一闪身就不见了。\n"+NOR,ob);
		destruct(ob);
		return;
	}
    else
	{
		remove_call_out("leave");
		call_out("leave",30);
		return;
	}
}

int do_copy(object me,int skill)
{
    int i,j;
    object ob;
    ob = this_object();

    ob->set("uni_target", me);
    ob->set("str", me->query("str"));
    ob->set("dex", me->query("dex"));
    ob->set("con", me->query("con"));
    ob->set("per", me->query("per"));

    if(me->query("combat_exp") > 1000000)
    {
	ob->set("combat_exp", (me->query("combat_exp") / 5 * 4));
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/armor", 150);
    }
    else if (me->query("combat_exp") > 100000)
	ob->set("combat_exp", (me->query("combat_exp")/ 4 * 3 ));
    else
	ob->set("combat_exp", (me->query("combat_exp") * 2 / 3));

    skill = skill * 2 / 3 + random( skill / 4 );

    //这里skill初始值为player最高武功等级

    set_skill("sword", skill);
	set_skill("parry",skill);
	set_skill("dodge", skill);
	set_skill("force",skill);
	set_skill("literate",skill);
	set_skill("taiyi-zhang",skill);
	set_skill("strike",skill);
	set_skill("taiyi-jian",skill);
	set_skill("taiyi-shengong",skill);
	set_skill("taiyi-you",skill);

    ob->set("jing",me->query("max_jing"));
    ob->set("eff_jing",me->query("max_jing"));
    ob->set("max_jing",me->query("max_jing"));
    ob->set("jingli",me->query("max_jingli"));
    ob->set("max_jingli",me->query("max_jingli"));
    ob->set("qi",me->query("max_qi"));
    ob->set("eff_qi",me->query("max_qi"));
    ob->set("max_qi",me->query("max_qi"));
    ob->set("neili",me->query("max_neili"));
    ob->set("max_neili",me->query("max_neili"));

    map_skill("parry","taiyi-zhang");
	map_skill("sword","taiyi-jian");
	map_skill("force","taiyi-shengong");
	map_skill("dodge","taiyi-you");
	map_skill("strike","taiyi-zhang");

	
	prepare_skill("strike","taiyi-zhang");

    ob->set("jiali", skill/6);

    return 1;
}
//死亡管理
void die()
{
    object killer,yyd, ob=this_object();
    if(!objectp(killer = get_damage_origin_object()) || 
        killer!=query("killer") ||
       (ob->query("xbh/time") && 
        ob->query("xbh/time")!=killer->query("banhe/lasttime") ) )
    {
		message_vision(HIY+"$N说道：君子报仇十年不晚，咱们后会有期。\n"NOR,this_object());
		destruct(this_object());
		return;
    }
    if ( ob->query("xbh/lianxu")>killer->query_temp("banhe/lianxu") )
      killer->set_temp("banhe/lianxu", ob->query("xbh/lianxu"));
    
	yyd=new(__DIR__"obj/yuanyangdao");
	yyd->set_temp("owner/id", killer->query("id"));
		yyd->set("xbh/time", killer->query("banhe/lasttime") );
		yyd->set("xbh/lianxu", killer->query_temp("banhe/lianxu") );
	yyd->move(this_object());
    bonus(killer,2);
	if (random(5)>random(8) && killer->query("antirobot/deactivity") < 2) GEM_D->drop(this_object(),killer);
    ::die();
}

void unconcious() { call_out("die",1); }

int do_none()
{
    return 1;
}
int ask_fight()
{
	if (query("killer")==this_player()) 
	{
		if (environment(this_object())->query("no_fight")) 
		{
			command("say 此处比武多有不便，你且随我来！");
			random_move();
		}
		else command("say 要打便打，不必多言！");
	} 
	else command("say 就你也配跟我讨教功夫？！");
	return 1;
}
