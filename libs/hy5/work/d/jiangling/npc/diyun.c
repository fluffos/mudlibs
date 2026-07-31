//Edited by fandog, 02/13/2000
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_me2();
string ask_book();
string ask_book2();
void do_kill(object ob);
void create ()
{
	object weapon;
	set_name("狄云", ({"di yun","di"}));
	set("long", "他长脸黝黑，颧骨微高，粗手大脚，象是湘西乡下常见的庄稼汉子。\n");
	set("gender", "男性");
	set("age", 24);

	set("combat_exp", 20000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 26);
	set_skill("force", 320);
	set_skill("dodge", 320);
	set_skill("sword", 220);
	set_skill("parry", 320);
	set_skill("feixian-steps", 320);
	set("max_qi",20000);
	set("max_jing",20000);
	set("max_neili",30000);
	set("qi",20000);
	set("jing",20000);
	set("neili",30000);

	set_skill("liancheng-jian", 320);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
        
        }) );
 

	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("blade", 300);
	set_skill("feixian-steps", 300);
	set_skill("shenzhao-jing", 300);
	set_skill("xue-dao", 300);
	map_skill("force", "shenzhao-jing");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");  
	set("inquiry", ([
		"水笙" : (: ask_me :),
		"剑谱":     (: ask_book :),
		"丁典":     (: ask_book2 :),
		"神照经":     (: ask_book2 :),
		"万震山":     "万震山这个狗贼我非杀了他不可。\n",
	]));
	set("wucan_count", 1);

        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);


	set("baodao_count",1);
	set("book_count",1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if (clonep())
	{
		weapon = new( __DIR__"xblade" );	
		if ( weapon->violate_unique() )
		{
			destruct( weapon );
			weapon = new( "/clone/weapon/changjian" );
		}
		weapon->move(this_object());
		weapon->wield();
	}
} 

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("wucan_count") < 1)
		return "水笙姑娘？她在雪域等着我？";

	add("wucan_count", -1);
	this_player()->set_temp("marks/wucan", 1);
	return "水笙姑娘？她在雪域等着我？她有什么东西捎给我么？";
}
int accept_object(object who, object ob)
{
	object obj;
	int i;
        object me;
        me=who;
        if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("id") == "wan zhenshan") 
	{
		write(HIC "\n狄云说道：这位" + RANK_D->query_respect(me)+"，如此大恩大德，在下实不知何以为报。\n");
		write(HIC "\n狄云大喜道：狗贼！想不到你也有今天！！。\n"NOR);
                call_out("destroying", 1, this_object(), ob);
		me->set_temp("marks/lianchenpu",1);
        return 1;
        }

	if (ob->query("id") != "da chang")
		return notify_fail("给我这东西有什么用？");
	message_vision("狄云笑着说道：“谢谢你！这位" + RANK_D->query_respect(ob) +"，辛苦你了。”\n", who);
	if (!who->query_temp("marks/wucan"))
	{
		return 1;
	}
	obj = new(__DIR__"wucanyi");
	this_player()->delete_temp("marks/wucan");
	if ( obj->violate_unique() || uptime() < 300)
	{
		destruct( obj );
		return 1;
	}
	message_vision("狄云对$N说道：“这件乌蚕衣也不算是什么宝贝，聊表心意吧！”狄云从怀里掏出一团不起眼的东西，递到$N的手上。\n", who);
	obj->move(this_player());
	return 1;
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


string ask_book2()
{
	object ob, me;
	int i;
	object fang;
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "请先帮我把万震山这恶人抓来吧！ \n";
	if (!me->query_temp("tssword",1)) return "你帮我找到唐诗剑谱了吗? \n";
	
	  	if(((int)me->query("combat_exp",1)<=1000000))
	{
		message_vision("$N对$n说道： 你的武功太差了，等武功好点再来吧！\n",this_object(),me);
                return " 快去吧。\n";	
	}
	
	  	if(((int)me->query("jinyong/book3")>=1))
	{
		message_vision("$N对$n说道： 我不是已经让你去救丁大哥过了吗? \n",this_object(),me);
                return " 快去吧。\n";	
	}
	
	if((int)(me->query("shen")<100000))
		return "你这恶人，有什么资格去救丁大哥?\n";

   	else 
	{
        command("bow " + me->query("id"));
	message_vision("$N对$n说道： 多谢帮我手刃仇人。\n",this_object(),me);
	message_vision("$N对$n说道： 我大哥丁典被关在江凌知府中，请帮我去看看他吧。\n",this_object(),me);


	
	i = 200+random(800);
	me->set("jinyong/book3",1);
	me->add("combat_exp",i+9880);
	me->add("potential",i*12);
	me->add("mpgx",10);
	me->add("expmax",2);

	tell_object (me,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	}

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
