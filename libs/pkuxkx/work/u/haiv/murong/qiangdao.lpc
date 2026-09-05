// qiangdao.c 强盗
// lag.2000/3/17
// modified by iszt@pkuxkx, 2007-02-07

inherit NPC;
#include <ansi.h>
void move();
void auto_perform();
int ask_fight();

void create()
{
    string weapon;
    set_name(HIC "姑苏慕容叛徒" NOR, ({"murong pantu", "pantu"}));
    set("gender", "男性");
    set("age", 28);
    set("long", "他是一个姑苏慕容叛徒。\n");

    set("attitude", "peaceful");
    set_skill("force", 50);
    set_skill("sword", 50);
    set_skill("finger",  50);
    set_skill("strike",  50);
    set_skill("blade", 50);
    set_skill("dodge", 50);
    set_skill("parry", 50);

    set_skill("murong-jianfa", 50);
    set_skill("yanling-shenfa", 50);
    set_skill("xingyi-zhang", 50);
    set_skill("shenyuan-gong", 50);
    set_skill("canhe-zhi", 50);
    set_skill("murong-daofa", 50);
    set_skill("douzhuan-xingyi", 50);

    map_skill("parry","douzhuan-xingyi");
    map_skill("finger","canhe-zhi");
    map_skill("sword","murong-jianfa");
    map_skill("blade","murong-daofa");
    map_skill("force","shenyuan-gong");
    map_skill("dodge","yanling-shenfa");
    map_skill("strike","xingyi-zhang");

    prepare_skill("finger","canhe-zhi");
    prepare_skill("strike","xingyi-zhang");

    // 加下面5句是让强盗自动走，增添玩家做机器人的困难！-糖圆SMILE
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
    weapon = random(2)?"/clone/weapon/changjian":"/clone/weapon/gangdao";
    setup();

    if(random(5)==0)
	add_money("gold", random(6));
    if(random(4)==1)
	add_money("silver", 20+random(8)*10);
    carry_object(weapon)->wield();
    carry_object("/clone/misc/cloth")->wear();
}

void init()
{
    add_action("do_none", "steal");
    add_action("do_none", "attack");
    add_action("do_none", "beg");
    if(random(3)>1)  {
	if(this_player()->query("id") == this_object()->query("killer"))
	    kill_ob(this_player());
    }
    remove_call_out("leave");
    call_out("leave",15);
}
void auto_perform()
{
    object *enemy,target, weapon;
    int k;
    enemy = query_enemy() - ({ 0 });
    target = enemy[random(sizeof(enemy))];
    command("exert powerup");
    command("exert recover");
    weapon = this_object()->query_temp("weapon");
    if (!weapon && random(2))
    {
	weapon = new("/clone/weapon/sword/qingfeng");
	weapon->move(this_object());
	weapon->set("no_sell",1);
	weapon->set("no_store",1);
	weapon->set("value", 0);
    }
    k = random(6);
    switch (k)
    {
    case 0:
	command("unwield jian");
	command("unwield dao");
	command("perform parry.xingyi " + target->query("id"));
	command("wield jian");
	command("wield dao");
	break;
    case 1:
	command("unwield jian");
	command("unwield dao");
	command("perform finger.dianxue " + target->query("id"));
	command("wield jian");
	command("wield dao");
	break;
    case 2:
	command("wield jian");
	command("wield dao");
	command("perform sword.liuxing " + target->query("id"));
	break;
    case 3:
	command("wield jian");
	command("wield dao");
	command("perform sword.lianhuan " + target->query("id"));
	break;
    case 4:
	command("wield jian");
	command("wield dao");
	command("perform blade.daoying " + target->query("id"));
	break;
    case 5:
	command("unwield jian");
	command("unwield dao");
	command("perform strike.xingdian " + target->query("id"));
	command("wield jian");
	command("wield dao");
	break;
    }        
}
void leave()
{
    object ob = this_object();
    object me = find_player(ob->query("killer"));
    if (!me) {
	destruct(this_object());
	return ;}
    if (!ob->is_fighting() && ob->query("murong/pin")!=me->query("murong/pin")) {
	message_vision(HIC "姑苏慕容叛徒一闪身就不见了。\n" NOR,this_object());
	destruct(this_object());
    }
    else call_out("leave",30);
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
	ob->set_name(HIC "姑苏慕容叛徒首领" NOR, ({"murong pantu", "pantu"}));
	ob->set("combat_exp", (me->query("combat_exp") * 4 / 5));
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/armor", 150);
    }
    else if (me->query("combat_exp") > 100000)
	ob->set("combat_exp", (me->query("combat_exp") * 3 / 4));
    else
	ob->set("combat_exp", (me->query("combat_exp") * 2 / 3));

    skill = skill * 2 / 3 + random( skill / 4 );

    //这里skill初始值为player最高武功等级

    ob->set_skill("force", skill);
    ob->set_skill("sword", skill);
    ob->set_skill("finger",  skill);
    ob->set_skill("strike",  skill);
    ob->set_skill("blade", skill);
    ob->set_skill("dodge", skill);
    ob->set_skill("parry", skill);

    ob->set_skill("murong-jianfa", skill);
    ob->set_skill("yanling-shenfa", skill);
    ob->set_skill("xingyi-zhang", skill);
    ob->set_skill("shenyuan-gong", skill);
    ob->set_skill("canhe-zhi", skill);
    ob->set_skill("murong-daofa", skill);
    ob->set_skill("douzhuan-xingyi", skill);

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

    map_skill("parry","douzhuan-xingyi");
    map_skill("finger","canhe-zhi");
    map_skill("sword","murong-jianfa");
    map_skill("blade","murong-daofa");
    map_skill("force","shenyuan-gong");
    map_skill("dodge","yanling-shenfa");
    map_skill("strike","xingyi-zhang");

    prepare_skill("finger","canhe-zhi");
    prepare_skill("strike","xingyi-zhang");

    ob->set("jiali", skill/6);

    return 1;
}
//死亡管理
void die()
{
    object killer, yuxi,where,equip;
    object* inv;
    string msg;

    //如果找不到杀手，就暂时不死
    if(!objectp(killer = query_temp("last_damage_from")) || killer->query("id")!= this_object()->query("killer"))
	//	if(!objectp(killer = query_temp("last_damage_from"))||this_object()->query("killer")!=this_object()->query_temp("last_damage_from"))
    {
	message_vision(HIY+this_object()->name()+"说道：君子报仇十年不晚，咱们后会有期。\n"NOR,this_object());
	destruct(this_object());
	return;
    }

    if(killer->query("murong/yuxi"))
    {
	yuxi = new("/d/murong/npc/obj/yuxi");
	killer->set("murong/done",1);
	yuxi->set_temp("owner/id", killer->query("id"));
/*	if ( (random(killer->query("combat_exp"))>1000000) && (random(10)>4) ) 
	{	//经验越高越复杂
	    msg = "唉，人算不如天算，终究还是被你坏了事。\n";
	    where = TASK_D->random_place();
	    if(!TASK_D->place_belong(where))
	    {
		yuxi->move(this_object());
	    } else
	    {
		msg+= HIY"宝物被我藏在了"HIB + TASK_D->place_belong(where) + NOR"的"HIB + where->query("short") + HIY",也不知道被没被人取走，你赶快去找吧！\n";
		inv = all_inventory(where);
		yuxi->move(where);
		if (sizeof(inv) > 0)
		    if (!yuxi->move(inv[random(sizeof(inv))]))	//有obj则移到obj上，不成功直接放地上
			yuxi->move(where);
		message_vision(HIY+this_object()->name()+NOR"说道：" + msg + NOR,this_object());
	    }

	}
	else  
*/
	{
	    yuxi->move(this_object());
	}
		if (random(2)) GEM_D->drop(this_object(),killer);
    }
    ::die();
}

void unconcious() { call_out("die",1); }

int do_none()
{
    return 1;
}
int ask_fight()
{
        if (this_object()->query("killer")==this_player()) {
        	if (environment(this_object())->query("no_fight")) 
        	{
        		command("say 此处比武多有不便，你且随我来！");
        		random_move();
        	}
        	else command("say 要打便打，不必多言！");
        } else command("say 就你也配跟我讨教功夫？！");
        return 1;
}
