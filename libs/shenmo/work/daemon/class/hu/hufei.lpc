// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// hufei.c 胡斐

#include <ansi.h> 

inherit NPC; 
inherit F_MASTER; 
string ask_me();
string ask_book();
void do_kill(object ob);
// inherit F_NOCLONE;




    
void create() 
{ 
        object ob; 
        set_name("胡斐", ({"hu fei", "hu", "fei"})); 
        set("gender", "男性"); 
        set("nickname", HIW "雪山飞狐" NOR); 
        set("age", 25); 
        set("long", @LONG 
他就是胡一刀之子胡斐，因其武功高强神出鬼 
没。在江湖上人送外号「雪山飞狐」。他身穿 
一件白色长衫，腰间别着一把看起来很旧的刀。 
满腮虬髯，根根如铁，一头浓发，却不结辫。 
LONG 
        ); 
        set("attitude", "peaceful"); 
        set("shen_type", 1); 
        set("str", 45); 
        set("int", 30); 
        set("con", 30); 
        set("dex", 30); 
        
        set("qi", 25200); 
        set("max_qi", 25200); 
        set("jing", 23500); 
        set("max_jing", 23500); 
        set("neili", 26500); 
        set("max_neili", 26500); 
        set("jiali", 180); 
        set("combat_exp", 7000000); 
        set("level", 50);
        set("score", 20000); 
        
        set_skill("force", 440); 
        set_skill("lengyue-shengong", 440); 
        set_skill("blade", 460); 
        set_skill("baisheng-daofa", 460); 
        set_skill("hujia-daofa", 460); 
        set_skill("dodge", 460); 
        set_skill("sixiang-bufa", 460); 
        set_skill("taxue-wuhen", 460);
        set_skill("parry", 440); 
        set_skill("throwing", 460); 

        set_skill("strike", 440); 
        set_skill("tianchang-strike", 440); 
        set_skill("cuff", 440); 
        set_skill("hujia-quan", 440); 
        set_skill("literate", 480); 
        set_skill("martial-cognize", 340); 

        map_skill("force", "lengyue-shengong"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("parry", "hujia-daofa"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
           
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff",   "hujia-quan"); 
        
        
        create_family("关外胡家", 7, "传人"); 
        
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);
	set("inquiry",([
		"宝刀":     (: ask_me :),
		"刀谱":     (: ask_book :),
		"胡家刀谱": (: ask_book :),
		"阎基":     "阎基这个狗贼我非杀了他不可。\n",
		"胡一刀":   "辽东大侠胡一刀是我爹。不过我从没见过他。\n",
		"苗人凤":   "苗人凤虽和家父齐名，家父却死在他的剑下。\n",
		"苗若兰":   "不知什么时候还能再见到若兰姑娘。\n",
		"若兰":   "不知什么时候还能再见到若兰姑娘。\n",
		"若兰姑娘":   "不知什么时候还能再见到若兰姑娘。\n",
		"程灵素":   "二妹是为我而死的。\n",
		"赵半山":   "你见我赵三哥了? \n",
		"袁紫衣":   "算了，别提这伤心事了。\n"
	]));
        
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({ 
                (: perform_action, "blade.huanying" :),
               	(: perform_action, "blade.lian" :),
                (: perform_action, "blade.xian" :), 
                (: perform_action, "blade.zhui" :), 
                (: perform_action, "blade.cang" :), 
                (: perform_action, "cuff.kuai" :), 
                (: perform_action, "strike.jian" :), 
                (: perform_action, "dodge.fei" :), 
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 
        
        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 
 	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);        
            
        set("master_ob",5);
	setup(); 
        
  
          
        carry_object("/clone/cloth/cloth")->wear(); 
        carry_object("/d/guanwai/npc/obj/cwbdao");
        carry_object("/d/zhongzhou/npc/obj/lengyuedao")->wield();       
        set("startroom", "/d/guanwai/xiaowu");  
        // check_clone(); 
} 

void attempt_apprentice(object ob) 
{ 
        
        if (ob->name(1) == "胡一刀") 
        { 
                command("say 我操！你想做我的老子啊？"); 
                return; 
        } 
        
        if (ob->name(1) == "胡斐") 
        { 
                command("say 他奶奶的！你咋也起这个名字？"); 
                return; 
        } 
        
        if (ob->name(1) == "胡子" || ob->name(1) == "胡臭") 
        { 
                command("say 你给换起个名字，现在这个名字也太龌龊了。"); 
                return; 
        } 
 
        command("recruit " + ob->query("id")); 
        command("say 今日我便收下你，我们胡家还要靠你们来发扬光大！"); 
        return; 
} 

string ask_me()
{
	object ob, me;
	
	me = this_player();
	if((int)me->query("shen") < 0)
	{
		me->set_leader(ob);
		call_out("do_kill",1,this_player());
	}
	else if((int)(me->query("shen")<100000))
		return "以你目前的作为是不能拿这把刀的。\n";

   	else if((int)(me->query("shen") > 100000))
	{
		if(query("baodao_count") > 0)
		{		
	    		call_out("waiting",0,me,ob);
			add("baodao_count", -1);
    			ob = new (__DIR__"obj/cwbdao");
    			ob->move(me);
			command("rumor "+me->query("name")+"拿到闯王军刀啦。\n");
			return " 好吧，这把闯王宝刀就赠与你，希望你好好利用它。\n";
		}
		else return "你来晚了，现在这把刀已不在此处。\n";
	}

}

void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
//	room1 = environment(me);
 
//	if (room1->query("no_fight"))
//	    room1->set("no_fight", 0);
 
	if (interactive(ob))
	{
		command("say 你这恶贼竟敢打我宝刀的主意，给我纳命来！\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("id") == "yan ji") 
	{
		write(HIC "\n胡斐说道：这位" + RANK_D->query_respect(me)+"，如此大恩大德，在下实不知何以为报。\n");
		write(HIC "\n胡斐大喜道：狗贼！想不到你也有今天！！手起刀落，将阎基剁为两段。\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/hujiadaopu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/hujiadaopu",1)) return "你说什么? \n";
	if((int)(me->query("shen")<100000))
		return "刀谱落入宵小之手，难免是阎基第二。\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "胡斐说着转身从阎基尸身上搜出一本破旧书本，递了给你。\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/blade_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"拿到胡家刀谱啦。\n");
			return "这本刀谱被这狗贼霸占多时了，现在就赠与你吧。\n";
		}
		else return "你来晚了，现在刀谱已不在此处。\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
