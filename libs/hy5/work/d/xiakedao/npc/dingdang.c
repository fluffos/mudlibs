// dingdang.c 丁当
#include <ansi.h>
inherit NPC;
string inquiry_yu();
string ask_wine();
string ask_tian();
void create()
{
        set_name("丁当", ({ "ding dang","ding"}) );
        set("gender", "女性" );
        set("age", 18);
        set("long", "一个十七八岁的少女，身穿淡绿衫子，一张瓜子脸，秀丽美艳。\n");
        set("shen_type", 1);
        set("combat_exp", 100000);
        set("nickname", HIC"叮叮当当"NOR);
        set("str", 18);
        set("dex", 22);
        set("con", 25);
        set("int", 35);
        set("per",30);
        set("attitude", "friendly");

        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 50);

        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("taiji-shengong", 200);
        set_skill("taiji-quan", 300);
        set_skill("tiyunzong", 500);

        map_skill("force","taiji-shenfong");
        map_skill("unarmed","taiji-quan");
        map_skill("parry","taiji-quan");
        map_skill("dodge","tiyunzong");
        set("chat_change",15);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
            
        }) );
        set("chat_msg",({
            "丁当念叨着: 也不知道我的玉哥哥现在怎么样了。\n",
            "丁当暗暗抹了把眼泪。\n",
            "丁当一跺脚，说道: 不行，我要上摩天崖把我的玉哥哥救回来。\n",
            "丁当叹了口气，说道: 要是有玄铁令就好了。\n",
       }) );
       set("inquiry",([
           "石中玉" : (: inquiry_yu :),
           "摩天崖" : "\n 前面这座山就是了，你要小心呀，那个老头的武功好强呀。\n",
           "玄铁令" : "\n 据说是在石破天手里，真假我就不知道了。\n",
		"玄冰碧火酒" : (:ask_wine:),
		"wine" : (:ask_wine:),
		"丁不三" : "丁不三是我爷爷啊，你找他有事？我爷爷很凶的，你还是别找他了。\n",
		"天哥" : (:ask_tian:),
		"石破天" : (:ask_tian:),
		"雪山派" : "爷爷最讨厌雪山派的人了，你千万不要在他面前提起。\n",
		"xueshan" : "爷爷最讨厌雪山派的人了，你千万不要在他面前提起。\n",
		"name" : "我姓丁名当，大家都叫我叮叮当当。\n",
		"名字" : "我姓丁名当，大家都叫我叮叮当当。\n",
       ]) );
       set_temp("shoupa",1);
       setup();
//       carry_object("/d/city2/obj/baojia")->wear();
       carry_object("/d/city2/obj/shouzhuo")->wear();
       carry_object("/d/city2/obj/yupei")->wear();
       add_money("silver", 10);
}

string inquiry_yu()
{
 object me=this_player();
 object obn;
 message_vision("丁当说道：这位"+ RANK_D->query_respect(me)+"，玉哥哥是我的夫君，\n"
         +"可是去年在雪山派被谢烟客抓去，囚禁起来。现在也不知是死是活。唉￣\n"
         , me );
 if(query_temp("shoupa")==0)
 {  message_vision("丁当又说道：这位"+ RANK_D->query_respect(me)+"，我已经托"
       +"人去摩天崖看看了，也不知道怎么样了。\n",me);
   return "真急人！";
 }
   message_vision("丁当又说道：这位"+ RANK_D->query_respect(me)+"，我这里有"
       +"一个手帕，是我随身之物，你看到我的玉哥哥\n"
       +"你就把手帕交给他，他会明白的。拜托了。\n" , me);
   obn=new("/d/xiakedao/obj/shoupa");
   obn->move(me);
   set_temp("shoupa",0);
   return "丁当从怀里拿出一个漂亮的手帕，交给你。\n";
}


string ask_tian()
{
	object me=this_player();
	
	if ( me->query_temp("book111"))
	{
	command("sigh");
	return "天哥受了重伤，我刚喂了点「玄冰碧火酒」给他服用，希望他没事。";
	}
	else {
	return "你也认识天哥吗？噢，对了，你是他的属下吧。";
	}
}

string ask_wine()
{
	int i;
	object ob, *obs,who;
	object me=this_player();
	who=me;
	if (!me->query_temp("book111"))
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "你找到我丁不三爷爷了吗？ 听说他在济南附近！";
	}

	if (!me->query_temp("book112") )
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "你找到我丁不四爷爷了吗？ 听说他在狼山附近！";
	}
	

	if (me->query("combat_exp",1) < 500000)
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "凭你这点本事配来管本姑娘的闲事？！";
	}	

	if (query_temp("wine") )
	{
	command("look  "+me->query("id"));
	command("sneer "+me->query("id"));
	return "玄冰碧火酒已经给别人了啊！";
	}
	if ( me->query_temp("book111") && me->query_temp("book112") )
	{
	command("ah "+me->query("id"));
	add_action("do_pretty", "pretty");
	command("say 一定是爷爷派你来劝我回去的是不是？原来他已经知道我偷了他的宝贝。");
	command("sigh");
	command("say 天哥以前风流涕淌，对人家老是油腔滑调的，可是最近不知道怎么变傻了，连哄人家的话也不会说了。");
	command("disapp");
	me->set_temp("pretty/ding", 1);

	if (me->query_temp("pretty/ding")) 
        {
        command("giggle");
        command("happy2 "+me->query("id"));
        command("blush");
        command("say 谢谢你啦，不过我要留在这里陪天哥，你帮我把这剩下的「玄冰碧火酒」带回去给爷爷吧。");
        ob=new("/d/yixing/npc/jiu.c");
	message_vision("丁当将一瓶「玄冰碧火酒」交了给$N。\n", me);
	ob->move(this_player());
	me->set("got/wine", 1);
	me->delete_temp("book111", 1);
	me->delete_temp("book112", 1);
	me->delete_temp("pretty/ding", 1);
	me->delete_temp("first/ask");
	set_temp("wine",1);
if(!who->query("jinyong/book11"))	
{
        i = 300+random(800);
	who->set("jinyong/book11",1);
	who->add("combat_exp",i+9880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*12)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
}

	} 

	return "我真宁愿他是以前那个会哄人家开心的天哥。";
	}
	else {
		return "这酒是我爷爷的，你自己问他要吧。";
		}
}

