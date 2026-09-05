// xiaomao.c
// cgbii
#include <ansi.h>

inherit NPC;

int do_kill(object me, object dest);
string ask_me();

void create()
{
set_name("小毛",({"xiao mao","mao"}));
	set("gender", "男性" );
        set("nickname", HIG"不是老朋友，恕不接待"NOR );
	set("shen_type", 0);
        set("age",15);
	set("str", 30);
	set("con", 30);
	set("int", 30);
	set("dex", 30);

	set("no_clean_up",1);

	set("long",
"小毛是不火不毛的儿子，自小在不火不毛和众\n武林前辈的教导下，武功比他爹还厉害，是个\n不可多得的武学奇才。\n");

	set("combat_exp", 500000);
	set("attitude", "peaceful");
	set("chat_chance", 1);
	set("chat_msg", ({
"你听道小毛在自言自语：怎么老头子去了还不\n回家？跑出去大半个月了！我看他肯定在丽春\n院不肯走，这老不修！唉... \n",
"小毛大声对你喝道：你在这里干嘛？没见过帅\n哥么？快走！快走！再不走我放狗啦！ \n",
"小毛说道：杨过老头和小龙女老婆婆好久都没\n来啦，好想和雕伯伯去玩哦，骑着它飞来飞去\n酷呆了耶。 \n",
"小毛在自言自语道：好久没见过老爷师傅啦！\n不知道他现在在哪里快活呢？好想吃他弄的\n乞丐鸡呀，想起都流口水。 \n",
"小毛很气愤的道：黄鼠狼这老头上次说教我钻\n地神功的，到现在都没有教我,哼！说话都不\n算数的！",
	}) );

	set("inquiry", ([
            "老朋友":(:ask_me:),
	]) );

	set("max_qi", 1000);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili",1000);
	set("jiali", 50);
	set("shen_type", 0);
	set("env/wimpy", 60);

	set_skill("force", 100); 
	set_skill("unarmed", 100);
	set_skill("sword", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("taiji-jian", 100);
	set_skill("taiji-quan",100);
	set_skill("tiyunzong",100);	
set("shen_type",1);set("score",200);setup();
  carry_object(__DIR__"obj/gangjian")->wield();
carry_object("d/city/obj/cloth")->wear();
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
}


string ask_me(){
object me,ob;
int i;
me=this_object();
ob=this_player();
	if(base_name(environment(this_object())) != "/d/taishan/dongtian")
	{
                message_vision("小毛对$N怒道：“你他妈的把老子给搬到什么地方来了？还不把我给搬回去。”\n",ob);
                command("slapfy " + ob->query("id"));
                   return "你在这里看啥？去！去！没你的事。\n";
		}
command("say 原来你是我老头子的朋友，失敬失敬，请进去喝杯茶啦！");
message("vision","只见小毛一手拉住你的手，向北面山上纵去，你觉得如腾云驾雾一般。 \n",ob);
message("vision","你吓得紧闭着眼睛看都不敢看。 \n",ob);
message("vision",".\n.\n.\n.\n",ob);
message("vision","你觉得好象停了下来，睁开眼一看。 \n",ob);
  me->move("/d/taishan/fefe5");
message("vision","只见小毛一手拉住"+ob->name()+"的手往北面山上去了。 \n",environment(ob),({ob}));
    ob->move("/d/taishan/fefe5");
command("tell fefe 老家伙，有朋友来找你，快回来！");
command("say 到啦，老头子我出去给你把风，你俩慢慢搞啦！");
message("vision","小毛说完后就转身往山下去了。 \n",environment(),me);
me->move("/d/taishan/dongtian");
message_vision("小毛从北面山上纵了下来，用不太友善的眼光看着你。 \n",me);
return "你在这里看啥？去！去！没你的事。\n";
}
