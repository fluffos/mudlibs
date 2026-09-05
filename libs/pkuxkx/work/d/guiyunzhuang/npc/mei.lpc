#include <ansi.h>

inherit NPC;
int check_leave()
{
	object me,ob=this_object();
	if (!me=ob->query("owner"))
	{
		message_vision("$N见事情已成，转身离去了。\n",ob);
		destruct(ob);
		return 1;
	}
	if (!me->query_temp("shediaoquest/guiyun/step")&&!me->query_temp("shediaoquest/guiyun/start"))
	{
		message_vision("$N见事情已成，转身离去了。\n",ob);
		destruct(ob);
		return 1;
	}
	remove_call_out("check_leave");
	call_out("check_leave",60);
	return 1;
}
void create()
{
    set_name("梅超风",({"mei chaofeng","mei"}));
    set("nickname",GRN"风流女魔"NOR);
    set("title",RED"黑风双煞"NOR);
    set("long","她是一位冷血女魔，见人就杀。\n");
    set("gender","女性");
    set("age",40);
    set("attitute", "peaceful");
    set("str",28);
    set("int",29);
    set("con",29);
    set("dex",28);
    set("shen_type",-1);
    set("score",300000);
    set("max_qi",1200);
    set("max_jing",1000);
    set("neili",1500);
    set("max_neili",1500);
    set("jiali",30);
    set("combat_exp",350000);
	set_temp("apply/attack",-50);
	set_temp("apply/damage",-50);
    set_skill("force",100);
    set_skill("luoying-shenfa",110);
    set_skill("dodge",100);
    set_skill("claw",150);
    set_skill("parry",100);
    set_skill("bihai-shengong",110);
    set_skill("luoying-shenfa",100);
    set_skill("jiuyin-baiguzhao",150);
    map_skill("force","bihai-shengong");
    map_skill("dodge","luoying-shenfa");
    map_skill("claw","jiuyin-baiguzhao");
    map_skill("parry","jiuyin-baiguzhao");
    prepare_skill("claw","jiuyin-baiguzhao");
    create_family("桃花岛",2,"弟子");
	set("uni_target",1);
    setup();
    carry_object("/d/city/obj/cloth")->wear();
	call_out("check_leave",60);
}

int guiyun(object me)
{
	object ob=this_object();
	ob->kill_ob(me);
	me->kill_ob(ob);
	return 1;
}
int leave()
{
	if (this_object())
	{
		message_vision("$N远远遁去了。\n",this_object());
		destruct(this_object());
	}
	return 1;
}

int about_me(object me,object huang,object old_huang)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (!huang||!living(huang))
	{
		return 1;
	}
	if (!old_huang||!living(old_huang))
	{
		return 1;
	}
	if (environment(me)!=environment(huang)||environment(me)!=environment(old_huang))
	{
		return 1;
	}
	old_huang->aboutme(me);
	return 1;
}
int gogogo()
{
	if (this_object())
	{
		message_vision("$N见重回师门有望，也离开了。\n",this_object());
		destruct(this_object());
	}
}
int huang_appear3(object me,object huang,object mei,object old_huang)
{
	object lu;
	if (!me||!living(me))
	{
		return 1;
	}
	if (!huang||!living(huang))
	{
		return 1;
	}
	if (!old_huang||!living(old_huang))
	{
		return 1;
	}
	if (environment(me)!=environment(huang)||environment(me)!=environment(old_huang))
	{
		return 1;
	}
	if (lu=present("lu chengfeng",environment(me)))
	{
		old_huang->saysth();
		lu->saysth();
		old_huang->saylu();
		call_out("gogogo",3);
		call_out("about_me",2,me,huang,old_huang);
		return 1;
	}
}
int huang_appear2(object me,object huang,object mei,object old_huang)
{
	object lu;
	if (!me||!living(me))
	{
		return 1;
	}
	if (!huang||!living(huang))
	{
		return 1;
	}
	if (!old_huang||!living(old_huang))
	{
		return 1;
	}
	if (environment(me)!=environment(huang)||environment(me)!=environment(old_huang))
	{
		return 1;
	}
	huang->dad(old_huang);
	if (this_object())
	{
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", this_object(), old_huang);
	}
	if (lu=present("lu chengfeng",environment(me)))
	{
		message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", lu, old_huang);
	}
	call_out("huang_appear3",2,me,huang,mei,old_huang);
	return 1;
}
int huang_appear(object me,object mei)
{
	object old_huang,huang;
	if (!huang=present("huang rong",environment(me)))
	{
		message_vision("$N忽然发现，黄蓉不见了。\n",me);
		return 1;
	}
	if (huang->query("owner")!=me)
	{
		message_vision("$N忽然发现，黄蓉不见了。\n",me);
		return 1;
	}
	old_huang=new("/d/guiyunzhuang/npc/old_huang");
	old_huang->set("owner",me);
	old_huang->move(environment(me));
	old_huang->killair();
	call_out("huang_appear2",1+random(2),me,huang,mei,old_huang);
	return 1;
}
void die()
{
	object owner,ob=this_object();
	if (!owner=ob->query("owner"))
	{
		leave();
	}
	if (ob->query("times")<3)
	ob->add("times",1);
	if (ob->query("times")==1)
	{
		ob->remove_all_killer();
		owner->remove_all_killer();
		ob->fullme();
		command("say 好啊，洪七公指点了你一下，梅超风就败在你的手下，洪七公那老叫化就这么厉害么？不行，非再打一场不可。");
		call_out("guiyun",2,owner);
		return;
	}
	else if (ob->query("times")==2)
	{
		ob->remove_all_killer();
		owner->remove_all_killer();
		ob->fullme();
		command("say 打无声掌，有声掌你不是我对手。");
		message_vision(HIW+"$N道：“适才我中你毒抓，生死关头，不得不以无声掌保命，若是比武较量，如此太不光明磊落，晚辈不敢从命。”\n"+NOR,owner);
		command("say 我既叫你打无声掌，自有破你之法，婆婆妈妈的多说甚么？");
		call_out("guiyun",2,owner);
		return;
	}
	else if (ob->query("times")==3&&owner->query_temp("shediaoquest/guiyun/step")==13)
	{
		ob->remove_all_killer();
		owner->remove_all_killer();
		message_vision(HIG+"$N却发现刚才的比武，一直有一个青袍怪客在用石子提醒$n自己的出招路数。\n"+NOR,owner,ob);
		ob->fullme();
		owner->set_temp("shediaoquest/guiyun/step",14);
		huang_appear(owner,ob);
		return;
	}
	else
	{
		ob->fullme();
		return;
	}
	return;
}
void unconcious()
{
	die();
}