// hufei.c
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_book();
void do_kill(object ob);

void create()
{
	set_name("胡斐", ({"hu fei", "hu", "fei"}));
	set("gender", "男性");
	set("nickname", "雪山飞"HIG"狐"NOR);
	set("age", 25);
	set("long", 
		"他就是胡一刀之子，因其武功高强神出鬼没。\n"
		"在江湖上人送外号「雪山飞狐」。\n"
		"他身穿一件白色长衫，腰间别着一把看起来很旧的刀。\n"
		"他满腮虬髯，根根如铁，一头浓发，却不结辫。\n");
	set("attitude", "peaceful");
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	
	set("qi", 50000);
	set("max_qi", 50000);
	set("jing", 50000);
	set("max_jing", 50000);
	set("neili", 53000);
	set("max_neili", 53000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 20000);
	 
	set_skill("force", 1300);             // 基本内功
	set_skill("hujia-daofa", 980);       // 胡家刀法	
	set_skill("blade", 1300);             // 基本刀法
	set_skill("hunyuan-yiqi", 980);      // 混元一气功
	set_skill("dodge", 1300);             // 基本躲闪
	set_skill("shaolin-shenfa", 980);    // 胡家身法
	set_skill("parry", 1300);             // 基本招架
		
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "hujia-daofa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "hujia-daofa");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
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
	set("baodao_count",1);
	set("book_count",1);
	setup();
	carry_object(__DIR__"obj/cwbdao")->wield();
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
	room1 = environment(me);
 
	if (room1->query("no_fight"))
	    room1->set("no_fight", 0);
 
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
		write(HIC "\n胡斐大喜道：狗贼！想不到你也有今天！！手起刀落，将阎基剁为两段。\n");
		ob->die();
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

