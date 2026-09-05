// tufei for jiaofei task

inherit FAMILY_NPC;
#include <ansi.h>

void heal();
void wield_weapon(string weapon);
int ask_bangzhu();

void create()
{
	set_name("土匪", ({ "tufei"}));
	set("gender", "男性");
	set("age", 23+random(10));
  
  set("chat_chance", 100);
	set("chat_msg", ({
		(: heal :)		
	}));

  set("die_times",0);
  set("inquiry",([
    "帮主":(:ask_bangzhu:),
  ]));
  setup();
  carry_object(__DIR__"obj/cloth")->wear();
 
  set("shen_type", -1);
	
}
	
void heal()
{
	object ob=this_object();
	
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		return;
	}

	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	return;
}

void unconcious()
{
    if(query("qi") > 100 && query("eff_qi") > 100 && query("jing") > 100 && query("eff_jing") > 100) return;
    ::unconcious();
}

//死亡后给奖励,奖励包括经验和潜能

//任务的主要奖励在宝库里。
void die()
{
    object me,killer;
    int exp,pot;
    object ob;
    string skill;
    int dodge,parry;
    int damage;
    int max_life;
    
    
    me = this_object();
    
    max_life = me->query("level")/3;
    if(max_life > 3) max_life = 3;
    
    if (objectp(killer = me->get_damage_origin_object()))
    {
	    message("vision",query("name")+"大叫："+killer->name() + "杀了我，弟兄们，给我报仇啊！！\n",environment(me));
	    message("vision",query("name")+"临死前抱住"+killer->name() +"狠狠的咬了一口！\n",environment(me));
	    killer->add_busy(1);    	

		if(me->query("die_times") < max_life)
		{
			message("vision","又跳出来一个土匪大喊："+killer->name() + "还我兄弟命来！老子跟你拼了！\n",environment(me));
			me->add("die_times",1);
			me->set("eff_qi",me->query("max_qi"));
			me->set("qi",me->query("max_qi"));
			me->set("eff_jing",me->query("max_jing"));
			me->set("jing",me->query("max_jing"));
			me->set("neili",me->query("max_neili"));
			me->set("eff_neili",me->query("max_neili"));
			return;
		}
	
    	if(userp(killer) && JIAOFEI_D->istaskstart() == 1)
    	{        	
    		message_vision(YEL"$N剿灭土匪，战功赫赫！！功成之日，朝廷必有重赏！\r\n"NOR,killer);
			killer->add_temp("jiaofei/score",query("level"));//设置一个标记，表明这个人杀过土匪了			
            JIAOFEI_D->stat_user_score_reward(killer->query("id"),query("level"));			
			JIAOFEI_D->registeruser(killer->query("id"));
			//随机掉落点人参
            if (killer->query("special_skill/lucky"))
            {
                if(random(20) > 18)
                {
                    message_vision(YEL"从土匪身上掉出来一棵千年人参。\n"NOR,killer);
                    ob = new("/d/city/npc/obj/renshen2");
                    ob->move(environment(killer));
                }
            }

            //掉落宝石
            if(random(10) > 6 || wizardp(killer))
            {
                if(wizardp(killer)) printf("dropping...\n");
                GEM_D->drop(this_object(),killer);
            }

            //当战功超过500，所获得的exp奖励将是超过25w，开始增加限制
            //否则hyd玩家和其他玩家差距太远                                   
            if(random(killer->query_temp("jiaofei/score")) > 150)
            {
                message("vision",sprintf(HIW"土匪头目："HIR"%s，你这恶贼，还我众兄弟命来！！\r\n"NOR,killer->query("name")),killer);
                message("vision",sprintf(HIW"土匪头目使出了同归于尽的招数，夺命三刀！！！\r\n"NOR),killer);
                message("vision",HIR".....................刀光一闪！\r\n"NOR,killer);
                message("vision",HIR""BNK".....................\r\n"NOR,killer);
                message("vision",HIR"................................再闪！\r\n"NOR,killer);
                message("vision",HIR""BNK"................................\r\n"NOR,killer);
                message("vision",HIR"...................................刀光又闪！\r\n"NOR,killer);
                message("vision",HIR""BNK"...................................\r\n"NOR,killer);
                //靠轻功躲闪，靠招架防御
       			skill=killer->query_skill_mapped("dodge");
    			dodge = killer->query_skill("dodge")/2 + killer->query_skill(skill);
                if(random(dodge) < 800+killer->query_temp("jiaofei/score")*2/5)
                {
                    message("vision",HIR"你闪避不及，只得用身体硬抗下这三刀。\r\n"NOR,killer);
                    skill=killer->query_skill_mapped("parry");
                    parry = killer->query_skill("parry")/2 + killer->query_skill(skill);
                    if (killer->query_temp("jiaofei/score") > 800)
                    {
						damage = 16*killer->query_temp("jiaofei/score");
                    }
					else
					{
						damage = 15*killer->query_temp("jiaofei/score") - random(parry/2);
					}
                    if(damage < 1000) damage = 1000;
                    killer->receive_damage("qi",damage,"夺命三刀砍");
                    killer->receive_wound("qi",random(damage/2)+1,"夺命三刀砍");     
                    message("vision",HIR"你吐出一口鲜血，显然伤的极重。\r\n"NOR,killer);
                    COMBAT_D->report_status(killer);                              
                    killer->add_busy(2+random(2));
                }
                else
                {
                    message("vision",HIG"你施展轻功，堪堪避过了这夺命的三刀。\r\n"NOR,killer);                              
                    killer->add_busy(2+random(2));
                }
            }
    	}
    }
    //掉落

  //  ::die();	
	destruct(this_object());

}

void wield_weapon(string weapon)
{
	if(!weapon && query("use_weapon1"))
		wield_weapon(query("use_weapon1"));
	if(!weapon && query("use_weapon2"))
		wield_weapon(query("use_weapon2"));
	if(!weapon)
		return;
	switch(weapon)
	{
	case "sword":
		carry_object("/clone/weapon/changjian")->wield();
		break;
	case "blade":
		carry_object("/clone/weapon/gangdao")->wield();
		break;
	case "staff":
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
	case "whip":
		carry_object("/clone/weapon/changbian")->wield();
		break;
	case "zhen":
		set("gender", "无性");
		carry_object("/d/city/obj/flower_shoe")->wear();
		carry_object("/d/city/obj/pink_cloth")->wear();
		carry_object("/d/city/obj/goldring")->wear();
		carry_object("/d/city/obj/necklace")->wear();
		carry_object("/d/quanzhou/obj/xiuhua")->wield();
		carry_object("/d/riyuejiao/obj/xiuhuajia");
		break;
	case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
		break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
	case "hammer":
		carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
		break;
	default:
	}
	return;
}

//to save some cpu time
void jiaofei_move(object dest)
{
    if(objectp(dest))
        move_object(dest);
}

int ask_bangzhu()
{
    object me = this_player();

    if(JIAOFEI_D->istaskstart() != 1)
    {
        command("shake");
        command("say 没事别瞎问。");
        return 1;
    }
    if(me->query("jiaofei/xinren") <= 0)
    {
        command("say 帮主叫我送你去阴间！");
        if(sizeof(me->query_enemy()) < 5)
        {
            this_object()->kill_ob(me);
        }
        return 1;
    }
    if(query("level") < 15)
    {
        command("say 我什么都不知道，不要问我！");
    }    
    else
    {
        if(me->query("jiaofei/xinren") < 1000)
        {
            command("heng");
            command("你算什么东西，也敢过问帮主的事！");
        }
        else
        {
            if(random(me->query("kar")) > 20)
            {
                if(time() - me->query_temp("jiaofei/ask_bangzhu") < 60)
                {
                    command("say 你有完没完，问了还问。");
                }
                else
                {
                    command("wa");
                    command("say 你知道帮主的下落？弟兄们，你们顶住，我有事要办，不打了。");
                    if(sizeof(query_enemy()) > 0)
                    {
                        remove_all_killer();
                    }
                    me->set_temp("jiaofei/ask_bangzhu",time());
                }
            }
            else
            {
                command("heng");
                command("say 不关你事！");
            }
        }
    }
}