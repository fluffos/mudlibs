#include <ansi.h>
inherit NPC;
int ask_me();
int ask_here();
int ask_finish();
void create()
{

	set_name("余任",({"yu ren","yu","ren"}));
    set("title", "隐士");
    set("gender", "男性");
    set("age", 40);
    set("long", "他是在隐居在大石谷的高人，不过脾气就不大好。\n");
    set("attitude","heroism");
    set("generation",0);
    set("max_qi",500);
    set("eff_qi",500);
    set("qi",500);
    set("max_jing",8000);
    set("jing",8000);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",2000000);
	set("NoBusyAsking",1);
	set_skill("literate", 300);
	set_skill("alchemy", 300);
	set_skill("herbalism", 300);
	set_skill("wuqinxi", 300);
	set_skill("force", 300);
	set_skill("hand", 300);
	set_skill("strike", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	map_skill("force", "wuqinxi");
	map_skill("dodge", "wuqinxi");
	map_skill("parry", "wuqinxi");
	map_skill("strike", "wuqinxi");
	map_skill("hand", "wuqinxi");
	prepare_skill("strike", "wuqinxi");
	set("inquiry", ([
	"前辈" : (:ask_me:),
	"name" : (:ask_me:),
	"此处" : (:ask_here:),
	"here" : (:ask_here:),
	"finish" :(:ask_finish:),
    	]));
    setup();
    carry_object("/clone/cloth/ycloth2")->wear();
	carry_object("/clone/cloth/yring")->wear();
}
int ask_here()
{
	object me=this_player();
	if (me->query("tianmuQuests/dashigu/gather_finish"))
	{
		command("say 你的五禽戏练得怎样了？");
		return 1;
	}
	if (me->query_skill("herbalism",1)>30)
	{
		if (me->query_temp("tianmuQuests/dashigu/test_preoffer"))
		{
			command("say 总问一样的话，你不烦吗？");
			return 1;
		}
		command("say 这里是大石谷啊，你不知道就闯进来了？");
		me->set_temp("tianmuQuests/dashigu/test_preoffer",1);
	}
	else
	{
		command("say 不干你事。");
	}
	return 1;
}
int ask_me()
{
	object me=this_player();
	if (me->query("tianmuQuests/dashigu/gather_finish"))
	{
		command("say 你的五禽戏练得怎样了？");
		return 1;
	}
	if (me->query_skill("herbalism",1)>30)
	{
		if (!me->query_temp("tianmuQuests/dashigu/test_preoffer"))
		{
			command("say 我是什么人并不重要，重要的是这是什么地方。");
			return 1;
		}
		if (me->query_temp("tianmuQuests/dashigu/test_offer"))
		{
			command("say 你别老问我的事，我只问你，可愿意接受我的挑战(challenge)？");
			return 1;
		}
		command("say 我不是什么前辈，但一直在此静待有缘人。你可愿意接受我的挑战(challenge)？");
		me->set_temp("tianmuQuests/dashigu/test_offer",1);
		return 1;
	}
	else 
	{
		command("say 老子就是余任，余任就是老子，你待怎地？");
		return 1;
	}
}
int do_reg()
{
	object me=this_player();
	if (me->query("tianmuQuests/dashigu/gather_finish"))
	{
		if (me->query("ProfessionalClass/herbalism"))
		{
			tell_object(me,"你已经是采药师了。\n");
		}
		else
		{
			message_vision("$N请求$n的同意，成为一名采药师。\n",me,this_object());
			F_PRO->register_me(me,"herbalism");
			message_vision(HIG"$N"+HIG+"答应帮$n"+HIG+"成为一名采药师！\n"NOR,this_object(),me);
		}
		return 1;
	}
	else
	return 0;
}
int reg_herb(string arg,object me)
{
	if (arg=="yes")
	{
		message_vision("$N大声回答：“我愿意。”\n",me);
		F_PRO->register_me(me,"herbalism");
		message_vision(HIG"$N"+HIG+"答应帮$n"+HIG+"成为一名采药师！\n"NOR,this_object(),me);
	}
	else
	{
		message_vision(HIG"$N"+HIG+"见$n犹豫不决"+HIG+"，略有不快：“下次再说吧！”\n"NOR,this_object(),me);
	}
	return 1;
}
int ask_finish()
{
	mapping *list;
	object me=this_player(),book;
	int number=40;
	if (me->query("tianmuQuests/dashigu/gather_finish"))
	{
		command("say 你的五禽戏练得怎样了？");
		return 1;
	}
	if (!me->query("tianmuQuests/dashigu/gather"))
	{
		command("heng");
		return 1;
	}
	if (me->query("tianmuQuests/dashigu/monkey")=="kill")
	number=60;
	list="/obj/remedy/reference"->List();
	for (int i=0;i<sizeof(list);i++)
	if (list[i]["gather_lv"]<30&&!list[i]["animal_source"]&&list[i]["gather_lv"]>0)
	{
		if (me->query("tianmuQuests/dashigu/gather/"+list[i]["id"])<=number)
		{
			command("say "+list[i]["name"]+"呢？没采齐啊。");
			return 1;
		}
	}
	me->delete("tianmuQuests/dashigu/gather");
	me->set("tianmuQuests/dashigu/gather_finish",1);
	command("ah");
	command("say 居然这么快就完成了？那么看来你就是那个有缘人了。");
	book=new("/d/southmountain/dashigu/obj/qingnang");
	book->move(me);
	message_vision("$N交给了$n一页"+book->query("name")+"。\n",this_object(),me);
	me->set_skill("wuqinxi",10);
	command("whisper "+me->query("id")+" 我再教你一套五禽戏，这个早晚练练会很有帮助的。\n");
	write(HIC"你学会了『五禽戏』。\n"NOR);
	command("say 对了"+me->query("name")+"你愿意成为一名采药师吗？");
	tell_object(me,"yes or no 回答余任的邀请。采药师可以在采药方面有更大进步，但是会影响武者任务的效率。\n");
	tell_object(me,"如果现在不确定，可以答no，以后随时可以在余任面前用reg命令成为采药师。\n");
	input_to((:reg_herb:),me);
	return 1;
}
void init()
{
	add_action("do_challenge","challenge");
	add_action("do_reg","reg");
}
int confirm(object me)
{
	mapping *list;
	if (!me||environment(me)!=environment(this_object()))
	return 1;
	me->save();
	command("say 好，就等你这句。");
	command("whisper "+me->query("id")+" 大石谷是一处药材丰富的所在，你给我找来这些东西：");
	list="/obj/remedy/reference"->List();
	for (int i=0;i<sizeof(list);i++)
	if (list[i]["gather_lv"]<30&&!list[i]["animal_source"]&&list[i]["gather_lv"]>0)
	{
		write(list[i]["name"]+" ");
		me->set("tianmuQuests/dashigu/gather/"+list[i]["id"],1);
	}
	if (me->query("tianmuQuests/dashigu/monkey")=="kill")
	command("say 每种六十件！");
	else
	command("say 每样四十件！");
	command("say 找齐这些东西之前，你就不要出谷了。在谷里找到，你就丢在地上，我会跟在你身后的。");
	command("say 锄头坏了，就到后院去修。");
	return 1;
}
int do_challenge()
{
	object me=this_player();
	if (!me->query_temp("tianmuQuests/dashigu/test_offer"))
	return 0;
	if (time()<query("confirming"))
	{
		command("say 你没看到我正忙着吗？");
		return 1;
	}
	me->delete_temp("tianmuQuests/dashigu/test_preoffer");
	me->delete_temp("tianmuQuests/dashigu/test_offer");
	message_vision(HIC+"$N"+HIC+"大声道：“我愿意接受这个挑战。”\n"NOR,me);
	CHANNEL_D->do_channel(me, "bd", "我愿意接受这个挑战。");
    message_vision("$N似乎愣了一下……\n",this_object());
	call_out("confirm",2,me);
	set("confirming",time()+2);
	return 1;
}