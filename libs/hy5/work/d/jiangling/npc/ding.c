//Edited by fandog, 01/31/2000

inherit NPC;
#include <ansi.h>
void destroying(object, object);

void create ()
{
	set_name("丁典", ({"ding dian","ding","dian"}));
	set("long", "
这人满脸虬髯，头发长长的直垂至颈，衣衫破烂不堪，简直如同荒山中
的野人。手上手铐，足上足镣，琵琶骨中穿着两条铁链。他脸上、臂上、
腿上，都是酷遭鞭打的血痕。\n");
	set("gender", "男性");
	set("age", 30);
	set("combat_exp", 5000000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("per", 24);
        set_skill("parry", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("dodge", 380);
	set_skill("taixuan-gong", 550);
	set_skill("feixian-steps", 580);
	set_skill("shenzhao-jing", 580);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taixuan-gong");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
	set("chat_chance", 10);
	set("chat_msg", ({
"丁典轻轻叹了一口气。那叹息中，竟有忧伤、温柔之意。\n",
"丁典嘴角挂着一丝微笑，痴望远处高楼纱窗上那一盆鲜花。\n",
"丁典大声道：怎么会忘记？决不会的！难道……难道是生了病？\n",
"丁典喃喃道：就算是生了病，也会叫人来换花啊！\n",
}) );
	set("inquiry", ([
		"凌霜华" : "“唉……”，然后指了指牢外那座小楼的窗口，啥也不说了。\n",

	]));
    set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "unarmed.wu" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
               
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 2000);
	set_temp("apply/damage", 2000);
        set("combat_exp", 9900000);
        set("shen_type", 1);
	setup();
	carry_object("/d/jiangling/obj/qiuyi")->wear();
}




int accept_object(object me, object obj)
{
	int i;
	object fang;
	object who;
	object where = environment(me);
	who=me;
        if ((string)obj->query("id")=="lu juhua") {
        message("vision",me->name()+"给丁典一盆绿菊花。\n",environment(me),
            ({me}));
        if(!this_object()->query("book_count")) {
		command("say 我已经托人给霜华捎话了，不劳您大驾了。");
		return 0;
	}
        command("touch "+me->query("id"));
        command("say 这位"+RANK_D->query_respect(me)+"是霜华派你来捎话的吧,嗨！我们可是苦命的鸳鸯。");

      if(!query("iskillok"))
      {
      message_vision("突然从门外突然杀进两个血刀派妖僧 对$n说道： 把神照经交出来吧!\n",this_object(),who);	
      	fang = load_object(__DIR__"baoxiang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object(__DIR__"shanyong");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 0;
      }	


        fang = present("shan yong",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败善勇吧。\n",this_object(),who);
		return 0;
	}

        fang = present("bao xiang",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N对$n说道： 这位"+ RANK_D->query_respect(who) +"先帮我战败宝象吧。\n",this_object(),who);
		return 0;
	}
	
		  	if((!(int)who->query_temp("killxs2")))
	{
		message_vision("$N对$n说道： 你帮我对付了善勇了吗?\n",this_object(),who);
		return 0;	
	}
	
		  	if((!(int)who->query_temp("killxs1")))
	{
		message_vision("$N对$n说道： 你帮我对付了宝象了吗?\n",this_object(),who);
		return 0;	
	}
	

	  	if(((int)who->query("jinyong/book3")==1))
	{
command("thank " + who->query("id"));
	message_vision("$N对$n说道： 多谢$n来帮我打败这两个妖僧。\n",this_object(),who);
	message_vision("$N对$n说道： 这血刀老祖做恶多端 希望$n帮我把他了结了吧。\n",this_object(),who);
	
	i = 400+random(800);
	who->set("jinyong/book3",2);
	who->add("combat_exp",i+10880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+10880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();	
	}
		if (present("shenzhao jing", me)) {
		command("say 你身上不是有着神照经吗？");
		return 0;
	}


	if (!present("shenzhao jing", me)) {
		if (me->query("szj/passed")) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n递给$N一本神照经。\n", me, this_object() );
		        command("say 这位"+RANK_D->query_respect(me)+"真是太感谢你了,这本内功心法希望你能好好珍惜。");
			this_object()->set("book_count", 0);
		} else if ((int)me->query("szj/failed") < 4 && me->query("kar") > 40 && !random(30)) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n递给$N一本神照经。\n", me, this_object() );
		        command("say 这位"+RANK_D->query_respect(me)+"真是太感谢你了,这本内功心法希望你能好好珍惜。");
			this_object()->set("book_count", 0);
			me->delete("szj/failed");
			me->set("szj/passed", 1);
		} else {
			command("sigh "+me->query("id"));
			command("say 我身无长物，实在没什么可以给你的了。");
			if (me->query("szj/failed") < 5)
				me->add("szj/failed", 1);
		}
	}
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
        }
        return 0;
}

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
