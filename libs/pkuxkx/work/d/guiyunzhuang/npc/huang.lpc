// 黄蓉Zine2012

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
	
	setup();
	carry_object("/d/city/obj/h_cloth")->wear();
	call_out("check_leave",60);
}

int hi_2(string arg,object huang,object me)
{
	string *yes=({"yes","YES","Yes","Y","y"});
	if (member_array(arg,yes)==-1)
	{
		message_vision("$N说道：“不去了，我今天有点累了。”\n",me);
		command("angry");
		command("say 好吧，那我去别处玩去了。");
		destruct(huang);
		return 1;
	}
	message_vision("$N说道：“好啊。”\n",me);
	message_vision("$N和$n两人找到湖畔一个渔村，将驴马寄放在渔家，借了一条小船，准备荡桨划入湖中。\n",me,huang);
	tell_object(me,HIG"你可以坐进(enter boat)小船，荡舟太湖。\n"NOR);
	me->set_temp("shediaoquest/guiyun/step",1);
	return 1;
}
int hi(object me,object ob)
{
	command("say 咱们到湖里玩去。好不好？(yes or no?)");
	input_to((:hi_2:),ob,me);
	return 1;
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
int followme(object me)
{
	command("follow "+me->query("id"));
	return 1;
}
int sing()
{
	message_vision(HIW"$N回应歌声唱道：“放船千里凌波去，略为吴山留顾。\n云屯水府，涛随神女，九江东注。\n北客翩然，壮心偏感，年华将暮。\n念伊蒿旧隐，巢由故友，南柯梦，遽如许！”\n"NOR,this_object());
	return 1;
}

int saylu()
{
	command("say 庄主这幅图画，写出了岳武穆作这首《小重山》词时壮志难伸、彷徨无计的心情。");
	command("say 庄主作画写字之时，却似是一腔愤激，满腔委曲，笔力固然雄健之极，但是锋芒毕露，");
	command("say 像是要与大仇人拚个你死我活一般，只恐与岳武穆忧国伤时的原意略有不合。");
	command("say 小可曾听人说，书画笔墨若是过求有力，少了圆浑蕴藉之意，似乎尚未能说是极高的境界。");
	return 1;
}
int dad(object ob)
{
	message_vision("$N突然高叫：“爹爹！”向那$n奔去，扑在他的怀里，放声大哭。\n",this_object(),ob);
	return 1;
}

int leave()
{
	command("say 你打他？我不理你了。");
	destruct(this_object());
	return 1;
}