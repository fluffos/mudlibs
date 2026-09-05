// Modified by iszt@pkuxkx, 2007-04-20

#include <ansi.h>

inherit NPC;

int accept_object (object ob,object obj);
int ask_zhou();
int ask_rong();
int ask_mudi();

void create()
{
        set_name("傻姑",({"sha gu","gu"}));
	set("long","她看起来二十多岁。\n"
"她一副傻乎乎的样子，总是做出一些不可思议的事情。\n");
        set("title",YEL"桃花岛"NOR+GRN"傻女"NOR);
        set("gender","女性");
        set("age",30);
        set("attitute","peaceful");
        set("shen_type",0);
        set("str",20);
        set("con",25);
        set("dex",24);
        set("int",23);
        set("max_qi",1200);
        set("qi",1200);
        set("max_jing",800);
        set("jing",800);
        set("max_neili",1200);
        set("neili",1200);
	set("jiali",100);
        set("combat_exp",200000);
        set_skill("force",80);
        set_skill("bihai-shengong",80);
        set_skill("dodge",80);
        set_skill("luoying-shenfa",80);
        set_skill("parry",80);
        set_skill("hand",80);
        set_skill("fuxue-shou",80);
        map_skill("force","bihai-shengong");
        map_skill("dodge","luoying-shenfa");
        map_skill("parry","fuxue-shou");
        map_skill("hand","fuxue-shou");
        prepare_skill("hand","fuxue-shou");
        create_family("桃花岛",2,"弟子");
        set("shen_type",1);set("score",500);setup();
        set("chat_chance", 3);
        set("chat_msg",({
		"傻姑嘴一撅：「蓉姐姐又不陪我玩了。」\n",
		"傻姑露出恐惧的神色，道：「那个放死人的地方有好多珠宝哟。可是我不敢拿，怕公公打我。」\n",
		"傻姑拍手笑道：「那个白胡子大哥哥真好，总是陪我玩。」\n",
		"傻姑说：「公公又不给我吃点心了。」\n",
		"傻姑吐了吐舌头：「蓉姐姐那件衣服真厉害，又把我的手给刺破了。」\n",
        }));
        set("inquiry",([
		"周伯通" : (: ask_zhou :),
		"墓地" : (: ask_mudi :),
		"蓉姐姐" : (: ask_rong :),
		"山洞" : (: ask_mudi :),
        ]));
        carry_object(__DIR__"obj/dianxin");
        carry_object("/d/guiyunzhuang/obj/dianxin");
}
int accept_object(object ob, object obj)
{
	object me = this_object();
	if((string)obj->query("id") == "dian xin")
        {
		this_player()->set_temp("marks/姑",1);
		command("say 这是我最喜欢的糕点呀。");
		command("jump");
		return 1;
        }
	command("smile");
	command("say 这不是我想要的东西.");
	command("give " + obj->query("id")+ " to " +me->query("id"));
	return 0;
}
int ask_zhou()
{
        if((int)this_player()->query_temp("marks/姑"))
        {
		say("傻姑说道：那个周大哥就在墓地旁边的那个山洞里。\n");
        	say("傻姑说道：不过他被公公的「桃花迷阵」困住了，只有公公才知道怎么走。\n");
        	this_player()->set_temp("marks/周1",1);
        	this_player()->set_temp("marks/姑",0);
        	return 1;
        }
	else
	{
		command("say 我不知道你说什么呀");
		return 1;
	}
}
int ask_rong()
{
        // if((int)this_player()->query_temp("marks/姑"))
        // {
        command("say 蓉姐姐在西边的那个厢房里。\n");

	this_player()->set_temp("marks/蓉1",1);
	return 1;
	// this_player()->set_temp("marks/姑",0);
        // }
	// else
        //{
        //say("你在说什么，我不知道呀. \n");
	// return 1;
}

int ask_mudi()
{
	if((int)this_player()->query_temp("marks/周1"))
        {
        	command("say 你要在墓地拜祭了才能进山洞。\n");
        	this_player()->set_temp("marks/周1",0);
		this_player()->set_temp("marks/姑",0);
		return 1;
	}
	else
	{
		say("你在说什么，我不知道. \n");
		return 1;
	}
}