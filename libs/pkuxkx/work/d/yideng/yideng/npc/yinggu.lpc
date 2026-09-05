//瑛姑
//by icer
#include <ansi.h>


inherit NPC;

int ask_treat();
int ask_duan();
int ask_jian();
int ask_yideng();
int ask_qiu();
int ask_zhou();
//void seeing();


void create()
{
        set_name("瑛姑", ({ "yinggu", "ying", "gu" }));
        set("long", "只见她额头满布皱纹，面颊却如凝脂，一张脸以眼为界，上半老，下半少，却似相差了二十多岁的年纪。\n");
	set("nickname", "神算子");
        set("gender", "女性");
        set("rank_info/respect", "前辈");
        set("age", 27);
        set("attitude","heroism");
        set("str", 20);
        set("dex", 35);
        set("con", 20);
        set("int", 30);
        set("shen_type", 0);

        set_skill("finger", 80);
	set_skill("parry",80);
	set_skill("yiyang-zhi",80);
        set_skill("force", 100);
        set_skill("dodge", 100);
	set_skill("xiantian-gong",50);
	set_skill("staff",100);
        map_skill("force", "xiantian-gong");
	map_skill("parry","yiyang-zhi");
	map_skill("finger","yiyang-zhi");
        set("jiali",50);

        set("combat_exp", 150000);

        set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);

        set("inquiry", ([
	    "治伤" : (: ask_treat :),
	    "段皇爷" : (: ask_duan :),	
	    "见段皇爷" : (:ask_jian :),
	    "一灯大师" : (:ask_yideng :),
	    "裘千仞" : (:ask_qiu :),
	    "周伯通" : (:ask_zhou :),
       ]) );

        setup();
        set("chat_chance", 2);
        set("chat_msg", ({
            "瑛姑轻轻吟道：「四张机，鸳鸯织就双欲飞。可怜未老头先白，春波碧草，哓寒湿处，相对浴红衣。」\n",
        }) );

        carry_object("/d/wudang/obj/greenrobe")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("seeing");
                call_out("seeing", 1, ob);
        }
	add_action("do_fight","bihua");
}

void seeing(object ob)
{
		if (!ob) return;
        if( !this_object()->visible(ob)) return;
        switch( random(5) ) {
                case 0:
                       command("sigh" );
                       break;
                case 1:
                       command("say");
                       break;
                case 2:
                       command("?");
                       break;
                case 3:
                       command("pat yinggu");
                       break;
                case 4:
                       command("look " + ob->query("id"));
	               if( (int)ob->query("eff_qi") < (int)ob->query("max_qi") / 2 )
        	       {
	               command("? " + ob->query("id"));
		       command("say 你受了伤?");
                       command("look " + ob->query("id"));
		       command("say 伤得很重啊！");
               ob->set_temp("marks/瑛1", 1);
		       }
                       break;
        }
}

int ask_treat()
{
	if ((int)this_player()->query_temp("marks/瑛1")) {
	say("瑛姑怒道：你我非亲非故，我凭什么帮你？除非你在武功上胜过我，要不我什么也不会诉你的！\n");
	this_player()->set_temp("marks/瑛2", 1);
	}
	else
	{
		say("瑛姑一脸迷茫，问到：你说什么呀？\n");
	}
	return 1;
}

	
int do_fight()
{
	object me, obj, book;
	int current_qi;

	me = this_object();
	obj = this_player();
	current_qi = (int)me->query("qi");

   say(obj->name() + "对瑛姑说：好吧，那我" + 
"就陪老前辈练几招。\n");
        if( obj->query_temp("marks/瑛2") ) {
                obj->set_temp("marks/瑛2", 0);
		while ( ((int)obj->query("qi")*100 / (int)obj->query("max_qi")) > 50) { 
			if ( !present(obj, environment()) )
				return 1;
                        COMBAT_D->do_attack(obj, me, query_temp("weapon"));
			if (((int)me->query("qi")*100/current_qi)< 50) {
				say(
"瑛姑对" + obj->name() + "说道：你的武功还过得去。可惜伤势太重，活不过24个时辰了。\n"
"	你的伤当世只有段皇爷治得。\n"
				);
 				obj->set_temp("marks/瑛3", 1);
				return 1;
			}
	                 COMBAT_D->do_attack(me, obj);
		}
		say(
"瑛姑冲着" + obj->name() + "撇了撇嘴，说道：就你这点本事还来\n"
"充英雄?!给我乖乖的爬出去吧!\n"
		);
                message("vision",
obj->name() + "乖乖的趴在地上，从洞里爬了出去。\n", environment(obj), ({obj}) );
                obj->move("/d/yideng/yideng/heizhao");
                message("vision",
obj->name() + "从洞里爬了出来。\n", environment(obj), ({obj}) );
                return 1;
	}
	say("瑛姑不耐烦的对" + obj->name() + "说道：要打就动手，罗嗦什么!\n"
	);
	return 1;
}
	
int ask_duan()
{
	if ((int)this_player()->query_temp("marks/瑛3")) {
	say("瑛姑说道：他多行不义，避祸桃源。外人万难见到。出沼之后，直向东北，到了桃源县境内，就会遇到他的渔樵耕读四大弟子。见不见得到段皇爷，就得看你的缘分啦！\n");
	command("sneer "+this_player()->query("id"));
	this_player()->set_temp("marks/瑛4", 1);
	}
	else
	{
		say("瑛姑一脸迷茫，问到：你说什么呀？\n");
	}
	return 1;
}

int ask_jian()
{
	object ob;
	if ((int)this_player()->query_temp("marks/瑛4")){
	command("say 我这儿有一幅画，你带去。如果他不肯见你，你就把画给他看。\n");
        ob=new("/clone/yidengtask/paper");
	ob -> move(this_player());
	write("瑛姑给你一幅画。\n");
	}
	else
	{
		say("瑛姑一脸迷茫，问到：你说什么呀？\n");
	}
	return 1;
}

int ask_yideng()
{
	object me;
	me=this_player();
	
	if ( me->query("task_duan1"))
	{
		command("ah");
		command("say 想让我原谅他容易，让他还我孩子来！\n");
		command("sigh");
		command("say 我那可怜的孩子是被裘千仞害死的，不关他的事。\n");
		me->set_temp("marks/裘",1);
		return 1;
	}
}

int ask_qiu()
{
	object me,obj;
	me=this_player();

	if ( me->query_temp("marks/裘"))
	{
		if ( me->query_temp("marks/killed_qiu",1))
		{
			command("wa "+me->query("id"));
			command("thank "+me->query("id"));
			command("这个指环你给段皇爷吧。他会明白的。\n");
                        obj=new("/clone/yidengtask/zhihuan");
			obj->move(this_player());
         say("瑛姑给你一个指环。\n");
			return 1;
		}
		else
		{
			command("say 是裘千仞这个老贼杀了我的孩子，我恨不得亲手杀了他！\n");
			command("say 如果你能杀了裘千仞，替我的孩子报了仇，我就原谅他！\n");
			command("sigh");
			command("say 这样又有什么用呢？又不能让那个狠心的人回到我身边......\n");

			me->set_temp("marks/裘2",1);
			return 1;
		}
	}
}

int ask_zhou()
{
	object me,obj;
	me=this_player();

	if ( me->query_temp("marks/get周"))
	{
    say("瑛姑朝你和善地笑着说：多谢你啦！你竟然能把他找回来，我已经心满意足啦！\n");
		command("say 你去跟段皇爷和裘千仞他们说，我已经原谅他们啦！\n");
		command("smile "+ me->query("id"));
           me->set("task_duan2",1);
		return 1;
	}
	if ( me->query_temp("marks/裘2"))
	{
		command("yi");
		command("say 你是怎么知道的？如果你能把他找来，我原谅谁都行！\n");
		me->set_temp("marks/find周",1);
		return 1;
	}		
	return notify_fail("瑛姑脸上一阵红，一阵白，最后说道：嗯......今儿天儿不错呀！呵呵呵呵!\n");
}
