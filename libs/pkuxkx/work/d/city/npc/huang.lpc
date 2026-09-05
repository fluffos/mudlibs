// 黄蓉Zine2012

#include <ansi.h>
inherit NPC;
#include <fishing.h>
int ask_where();
int ask_together();
int ask_swim();
void create()
{
	set_name("黄蓉", ({"huang rong", "rong","huang"}));
	set("long", HIW"她全身白衣，长发披肩，头上束了一条金带，白雪一映，更是灿然生光，全身装束犹如仙女一般。\n"NOR);
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 15);
	set("shen_type",1);
	set("str", 20);
	set("int", 50);
	set("con", 20);
	set("dex", 20);
	set("uni_target",1);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("combat_exp", 220000);
	set("per",100);
	set("shediao_huangrong",1);
	set("npc_permit_pass",1);
	set_temp("shediaoquest/kanglong/start",9);
	set_skill("force", 100);
	set_skill("bihai-shengong", 140);
	set_skill("dodge", 150);
	set_skill("luoying-shenfa", 150);
	set_skill("hand", 100);
	set_skill("music", 200);
	set_skill("qimen-bagua", 200);
	set_skill("fuxue-shou", 120);
	set_skill("finger", 110);
	set_skill("tanzhi-shengong",100);
	set_skill("parry", 120);
	set_skill("sword", 110);
	set_skill("yuxiao-jian", 100);
	set_skill("literate", 100);
	map_skill("force", "bihai-shengong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("hand", "fuxue-shou");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	map_skill("finger", "tanzhi-shengong");
	prepare_skill("finger", "tanzhi-shengong");
	create_family("桃花岛", 2, "少岛主");
	set("title",HIM"桃花岛"NOR);
	set("inquiry", ([
            "欲往何处" : (: ask_where :),
            "同去江南" : (: ask_together :),
			"游泳" : (: ask_swim :),
		]) );

	setup();
	carry_object("/d/city/obj/h_cloth")->wear();
	call_out("check_huang",240);
}
int saypass(object me)
{
	object ob=this_object();
	command("say 要去就去");
	message_vision("多日相处下来，$N已知$n心意，就知道$n想游(swim)过江去。\n",ob,me);
	return 1;
}
int leave(object me,object huang)
{
	if (!me||!huang)
	{
		return 1;
	}
	if (!living(me)||!living(huang))
	{
		return 1;
	}
	if (environment(huang)!=environment(me)||environment(me)->query("shediao_place")!=2)
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")!=9)
	{
		return 1;
	}
	tell_object(me,"你忽然发现"+huang->name()+"的厨艺简直是冠绝天下，无可挑剔。\n");
	command("say 玩够了，我们走吧？");
	command("follow "+me->query("id"));
	return 1;
}
int cook(object me,object huang)
{
	if (!me||!huang)
	{
		return 1;
	}
	if (!living(me)||!living(huang))
	{
		return 1;
	}
	if (environment(huang)!=environment(me)||environment(me)->query("shediao_place")!=2)
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")!=8)
	{
		return 1;
	}
	message_vision("$N一番忙碌之后，做了一条烤鱼，两人一起大快朵颐。\n",huang);
	me->set("food",me->max_food_capacity());
	me->set("water",me->max_water_capacity());
	me->set_temp("shediaoquest/kanglong/start",9);
	call_out("leave",2,me,huang);
	return 1;
}
int fish(object me)
{
	string name=me->query("name");
	int n=strwidth(name);
	object ob=this_object();
	name=name[n-2..n-1];
	if (me->query("gender")=="男性")
	name+="哥哥";
	else
	name+="姐姐";
	message_vision("$N脱去外衣，潜入水中，不多时浮上来时，手里已多了一条大鱼。\n",ob);
	command("say "+name+"，你稍等一下。");
	call_out("cook",3,me,ob);
	return 1;
}
int ask_swim()
{
	object me=this_player();
	if (me->query_temp("shediaoquest/kanglong/start")==6)
	{
		command("say 你只需放松身体，手脚配合好自然能浮起来的，试试(swim)吧。");
		me->set_temp("shediaoquest/kanglong/start",7);
	}
	else if (me->query_temp("shediaoquest/kanglong/start")==7)
	{
		command("say 怎么说都没有，你要自己试试(swim)就会了。");
	}
	else
	{
		command("say 现在我累了。");
	}
	return 1;
}
int sayswim(object me)
{
	string name=me->query("name");
	int n=strwidth(name);
	name=name[n-2..n-1];
	if (me->query("gender")=="男性")
	name+="哥哥";
	else
	name+="姐姐";
	command("say "+name+"，我教你游泳可好？");
	me->set_temp("shediaoquest/kanglong/start",6);
	return 1;
}
int check_huang()
{
	if (this_object()&&!this_object()->query("follow"))
	{
		message_vision("$N见没有什么好玩的，就转身离去了。\n",this_object());
		destruct(this_object());
	}
	return 1;
}
int ask_together()
{
	object me=this_player(),ob=this_object();
	if (!me->query_temp("shediaoquest/kanglong/start"))
	{
		command("ah");
		tell_object(me,ob->name()+"道：“有病！”\n");
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")==1)
	{
		command("say 我可没说我要去江南啊。");
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")==2)
	{
		me->set_temp("shediaoquest/kanglong/start",3);
		ob->set("follow",1);
		command("say 呵呵，一起去一定会有趣些。");
		command("follow "+me->query("id"));
		command("say 走，到长江北岸扬子津的东边，我告诉你好玩的。");
		return 1;
	}
	else
	{
		command("say 你倒是跟我走呀。");
		command("smile");
		return 1;
	}
}
int ask_where()
{
	object me=this_player(),ob=this_object();
	if (!me->query_temp("shediaoquest/kanglong/start"))
	{
		command("xixi");
		tell_object(me,ob->name()+"道：“不告诉你！”\n");
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")==1)
	{
		me->set_temp("shediaoquest/kanglong/start",2);
		command("say 我要去江南玩玩。");
		return 1;
	}
	else
	{
		command("say 不是和你说过了嘛。");
		return 1;
	}
}
int hong_appear2(object me,object huang)
{

	object hong=new("/d/changjiang/npc/hong");
	string name;
	int n;
	if (!me||!living(me))
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")!=15)
	{
		return 1;
	}
	if (!huang)
	{
		return 1;
	}
	if (!living(huang))
	{
		return 1;
	}
	if (environment(me)!=environment(huang))
	{
		return 1;
	}
	name=me->query("name");
	n=strwidth(name);
	if (me->query("gender")=="男性")
	name=name[n-2..n-1]+"哥哥";
	else
	name=name[n-2..n-1]+"姐姐";
	message_vision("忽然听到有人说：“撕成三份，鸡屁股给我。”\n",me);
	hong->move(environment(me));
	command("whisper "+me->query("id")+" "+name+"，这可能是前辈高人，你把整只鸡都给他吧。");
	me->set_temp("shediaoquest/kanglong/start",16);
	return 1;
}
int hong_appear(object me)
{
	object ob=this_object();
	command("say 做得真香啊。");
	call_out("hong_appear2",2,me,ob);
	return 1;
}
int cook_ji(object me,object huang)
{
	object ji;
	if (!me||!living(me))
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")!=14)
	{
		return 1;
	}
	if (!huang)
	{
		return 1;
	}
	if (!living(huang))
	{
		return 1;
	}
	if (environment(me)!=environment(huang))
	{
		return 1;
	}
	ji=new("/d/changjiang/obj/ji");
	ji->move(huang);
	command("give "+me->query("id")+" fei ji");
	command("say 把鸡的内脏剥(bo)掉，找(zhao)些泥土裹(guo)上，放在火上烤(kao)就可以了。\n");
	command("say 我先去把衣服弄干，一会就回来。");
	huang->move("/d/city/hideroom");
	me->set_temp("shediaoquest/kanglong/start",15);
	return 1;
}
int cookji(object me)
{
	object huang=this_object();
	me->set_temp("shediaoquest/kanglong/start",14);
	call_out("cook_ji",2,me,huang);
	return 1;
}
int check_live()
{
	object owner,ob=this_object();
	if (!owner=ob->query("owner"))
	{
		message_vision("$N静静地离开了。\n",ob);
		destruct(ob);
		return 1;
	}
	if (!owner->query_temp("shediaoquest/kanglong/start"))
	{
		message_vision("$N静静地离开了。\n",ob);
		destruct(ob);
		return 1;
	}
	remove_call_out("check_live");
	call_out("check_live",60);
	return 1;
}
int hi(object me)
{
	string name=me->query("name");
	int n=strwidth(name);
	set("owner",me);
	check_live();
	if (me->query("gender")=="男性")
	{
		command("say "+name[n-2..n-1]+"哥哥，不想在这里又遇见了你。");
	}
	else
	{
		command("say "+name[n-2..n-1]+"姐姐，不想在这里又遇见了你。");
	}
}

void init()
{
	add_action("do_look","look");
}

int do_look(string arg)
{
	object me=this_player();
	if (member_array(arg,this_object()->parse_command_id_list())!=-1&&base_name(environment(this_object()))=="/d/changjiangnorth/inriver"&&!me->query_temp("shediaoquest/kanglong/lookrong"))
	{
		tell_object(me,"你仔细端详黄蓉清丽的容颜，觉得恰是：\n");
		tell_object(me,HIW+"雁霜寒透幕。\n正护月云轻，嫩冰犹薄。\n溪奁照梳掠。\n想含香弄粉，艳妆难学。玉肌瘦弱。\n更重重、龙绡衬著。\n倚东风，一笑嫣然，转盼万花羞落。\n"NOR);
		me->set_temp("shediaoquest/kanglong/lookrong",1);
		return 1;
	}
	return 0;
}