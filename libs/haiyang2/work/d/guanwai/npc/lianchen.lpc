// hufei.c
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_book();
void do_kill(object ob);

void create()
{
	set_name("狄云", ({"di yun", "di", "yun"}));
	set("gender", "男性");
	set("nickname", HIR"连城剑"NOR);
	set("age", 25);
	set("long", 
		"他就是狄云发的大弟子，因其武功高强神出鬼没。\n"
		"在江湖上人送外号「连城剑」。\n"
		"他看上去就像一个乡下的农民。\n");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 25);
	set("chat_chance", 20);
	set("chat_msg", ({
		"狄云叹了口气道：“不知什么时候还能再见到师妹。\n",
		"狄云恨恨道：“万震山是我杀师仇人，我必报此仇！”\n",
		"狄云切齿恨道：“万老贼暗下毒手，我必手刃此人！”\n",
		(: random_move :),
	}));
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),                	                	                	
                (: perform_action, "sword.zhu" :),                	                	                	
		            (: random_move :),
        }) );

	
	set("qi", 13000);
	set("max_qi", 13000);
	set("jing", 11000);
	set("max_jing", 11000);
	set("neili", 23000);
	set("max_neili", 23000);
	set("jiali", 100);
	set("combat_exp", 2990000);
	set("score", 20000);
	 
	set_skill("force", 110);             // 基本内功
	set_skill("liancheng-jian", 350);       // 胡家刀法	
	set_skill("sword", 320);             // 基本刀法
	set_skill("hunyuan-yiqi", 320);      // 混元一气功
	set_skill("dodge", 120);             // 基本躲闪
	set_skill("shaolin-shenfa", 220);    // 胡家身法
	set_skill("parry", 220);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("sword", "liancheng-jian");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);

	set("inquiry",([
		"剑谱":     (: ask_book :),
		"万震山":     "万震山这个狗贼我非杀了他不可。\n",
	]));
	set("baodao_count",1);
	set("book_count",1);
	setup();
	carry_object("clone/weapon/gangjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
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
		command("say 你这恶贼竟敢打我剑谱的主意，给我纳命来！\n");
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
	if ( (string)ob->query("id") == "wan zhenshan") 
	{
		write(HIC "\n狄云说道：这位" + RANK_D->query_respect(me)+"，如此大恩大德，在下实不知何以为报。\n");
		write(HIC "\n狄云大喜道：狗贼！想不到你也有今天！！手起刀落，将阎基剁为两段。\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/lianchenpu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "你说什么? \n";
	if((int)(me->query("shen")<100000))
		return "剑谱落入宵小之手，难免是万震山第二。\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "狄云说着转身从万震山尸身上搜出一本破旧书本，递了给你。\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/lian_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"拿到连城剑谱啦。\n");
			return "这本连城剑谱被这狗贼霸占多时了，现在就赠与你吧。\n";
		}
		else return "你来晚了，现在连城剑谱已不在此处。\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
