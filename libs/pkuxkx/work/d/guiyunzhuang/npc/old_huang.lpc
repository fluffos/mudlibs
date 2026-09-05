// huang.c 黄药师
// Modified by iszt@pkuxkx, 2007-03-01
// re-modified by Zine,2012,for shediao quest
#include <ansi.h>
inherit NPC;
#include "/d/menggu/shediao_bonus.h"
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
	set_name("黄药师", ({ "huang yaoshi", "huang", "yaoshi" }));
	set("title",MAG"桃花岛"NOR + YEL"开山"NOR + MAG"祖师"NOR);
	set("nickname", RED "东邪" NOR);
	set("long",
		"他就是桃花岛的岛主，非正非邪而又脾气古怪的黄药师。\n"
		"并且他看起来风流飘逸，颇有一股逍遥自在的感觉。\n");
	set("gender", "男性");
	set("generation",1);
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 6000);
	set("max_jing", 5000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 150);
	set("combat_exp",11000000);
	set("fighting",0);
	set("score", 1000000);
	
	
	set_skill("force", 350);
	set_skill("bihai-shengong", 400);
	set_skill("dodge", 350);
	set_skill("luoying-shenfa", 300);
	set_skill("hand", 350);
	set_skill("music", 400);
        set_skill("qimen-bagua", 400);
	set_skill("fuxue-shou", 350);
	set_skill("finger", 350);
	set_skill("tanzhi-shengong",300);
	set_skill("parry", 350);
	set_skill("sword", 350);
	set_skill("yuxiao-jian", 400);
	set_skill("literate", 400);
	map_skill("force", "bihai-shengong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("hand", "fuxue-shou");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	map_skill("finger", "tanzhi-shengong");
	prepare_skill("finger", "tanzhi-shengong");
	create_family("桃花岛", 1, "岛主");
	set("class", "taoist");
	set("book_court", 1);

	set("shen_type",1);set("score",10000);setup();
	set("uni_target",1);
	carry_object("/d/taohuadao/npc/obj/yuxiao");
	call_out("check_leave",60);
}

int killair()
{
	command("killair");
}

int saysth()
{
	command("say 乘风，你很好，起来罢。当年我性子太急，错怪了你。");
}

int saylu()
{
	object ob=this_object();
	message_vision("$N对陆乘风道：“这个，给你！”却是一本《旋风扫叶腿法》。\n",ob);
	command("say 超风，接下来一年，你要帮我做三件事。\n");
}
int goout(object ob)
{
	message_vision(HIG"$N对在场众人手一挥，转身说走就走就走。\n"NOR,ob);
	destruct(ob);
	return 1;
}
int beatme3(object ob,object me)
{
	int e_reward;
	string name=me->query("name");
	name=name[0..0];
	if (!me||!living(me))
	{
		return 1;
	}
	if (!ob||!living(ob))
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	if (me->query("shediaoquest/guiyun"))
	{
		message_vision(HIG"$N手一挥，转身就走。\n"NOR,ob);
		destruct(ob);
		return 1;
	}
	ob->remove_all_killer();
	me->remove_all_killer();
	if (me->query("gender")=="男性")
	{
		name+="小子";
	}
	else
	{
		name+="丫头";
	}
	command("say "+name+"，功夫还不错。\n");
	if (me->query("family/family_name")!="桃花岛")
	{
		e_reward=bonus(me,2600);
		me->add("combat_exp",e_reward);
		tell_object(me,HIC"完成射雕主线任务【归云庄】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
	}
	else
	{
		message_vision("$N传授了$n一些奇门八卦的知识。\n",ob,me);
		me->set_skill("qimen-bagua",me->query_skill("qimen-bagua",1)+5+random(6));
		tell_object(me,HIC"完成射雕主线任务【归云庄】。\n");
	}
	me->delete_temp("shediaoquest/guiyun");
	me->set("shediaoquest/guiyun",1);
	remove_call_out("goout");
	call_out("goout",1,ob);
	return 1;
}
void init()
{
	add_action("do_hit","hit");
}
int do_hit(string arg)
{
	object me=this_player();
	object ob=this_object();
	if (member_array(arg,ob->parse_command_id_list())==-1)
	{
		return 0;
	}
	if (me->query_temp("shediaoquest/guiyun/step")!=15)
	{
		return 0;
	}
	message_vision(HIC+"$N道：“既是前辈有命，弟子不敢不遵。”运起势子，蹲身屈臂，画圈一掌击向$n。\n"+NOR,me,ob);
	me->set_temp("shediaoquest/guiyun/step",15);
	me->fight_ob(ob);
	call_out("beatme3",1,ob,me);
	return 1;
}
int beatme2(object ob,object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (!ob||!living(ob))
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	tell_object(me,"你暗想：到了这步田地，不动手万万不行，只好打他几掌。他不过是要借力打力，将我反震出去，我摔几交又有甚么？\n");
	tell_object(me,HIC+ob->query("name")+HIC+"的意思是让你出招攻他(hit huang yaoshi)。\n"+NOR);
	ob->set_temp("apply/dodge",50000);
	ob->set_temp("apply/parry",50000);
	ob->set("eff_qi",500000);
	ob->set("qi",500000);
	//me->fight_ob(ob);
	//call_out("beatme3",1,ob,me);
	return 1;
}
int beatme(object ob,object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (!ob||!living(ob))
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	message_vision("$N虽然暗赞这小子下盘功夫不错，怒气反而更炽，喝道：“我没弟子，只好自己来接你几掌。”\n",ob);
	message_vision("$N忙躬身道：“弟子就有天大的胆子，也不敢和前辈过招。”\n",me);
	message_vision("$N冷笑道：“哼，和我过招？谅你这小子也不配。我站在这里不动，你随意的向我身上招呼，只要引得我稍有闪避，举手挡格，就算是我栽了，好不好？”\n",ob);
	message_vision("$N道：“弟子不敢。”\n",me);
	message_vision("$N道：“不敢也要你敢。”\n",ob);
	call_out("beatme2",2,ob,me);
	return 1;
}
int aboutme(object me)
{
	object ob=this_object(),huang;
	string name=me->query("name");
	me->set_temp("shediaoquest/guiyun/step",15);
	message_vision("$N忽然向$n招了招手，道：“你叫"+name+"？”\n",ob,me);
	message_vision(RED"$N忽然出手，一把把$n扔了出去。\n"NOR,ob,me);
	message_vision("$N却是下盘甚稳，脚跟一着地，立时牢牢钉住，竟未摔倒。\n",me);
	if (huang=present("huang rong",environment(ob)))
	{
		if (huang->query("owner")==me)
		{
			huang->leave();
		}
	}
	call_out("beatme",2,ob,me);
	return 1;
}