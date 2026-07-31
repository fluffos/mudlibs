// wang.c

inherit NPC;

string ask_gongjv();

void create()
{
        set_name("王三力", ({"wang sanli", "wang" ,"sanli"}) );
        set("gender", "男性" );
        set("age", 35);
        set("long", "一个强壮的大汉，看他的胳膊就知道力气不小。他很聪明，是远近闻名的发明家。\n");

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("combat_exp", 20000);
	set("shen_type", 1);
        set("str", 30);
        set("dex", 30);
        set("con", 25);
        set("int", 20);
        set("attitude","friendly");
	set("unique", 1);

        set("inquiry", ([
                "肖老头" : (: ask_gongjv :),
        ]));
        set("gongjv_count", 2);
        setup();
        set("chat_chance", 1);
        set("chat_msg", ({
		"王三力自言自语道：“把硫磺、硝石和木炭掺在一起就可以燃烧爆炸，可每样放多少最好呢？”\n",
                "王三力拿起快黑色石头仔细看着说：“真是奇怪，它怎么能和铁吸在一处呢？”\n",
                "王三力叹道：“穷人家的孩子只能在木头、石片上写字，要能有种便宜的可以写字的东西就好了。”\n",
                "王三力摆弄着些竹片和绢帛，道：“竹片太沉，绢帛又不好保存，看来得找一种新东西。”\n",
                "王三力深思到：“佛经都是手抄的，真不方便。要怎样才能一次抄出很多来呢？”\n",
        }) );
carry_object("/clone/misc/cloth")->wear();
//        carry_object(ARMOR_D("pipao"))->wear();
}

 string ask_gongjv()
{
	object me,tool1,tool2;
	me=this_player();

	if (me->query_temp("baobei_ask")){
          if (query("gongjv_count") < 1){ 
	   return "啊？你问的是肖老头的工具吧？刚刚已经被人拿走了，不在我这里。";}
    tool1=new(__DIR__"obj/dingxie");     
    tool2=new(__DIR__"obj/binggao");
	tool1->move(me);
	tool2->move(me);
        add("gongjv_count", -2);
        return  "如果你不提他，我差点忘了。他在我这里有两件工具，拿去吧。
王三力交给你一双钉鞋。
王三力交给你一把冰镐。";
	}
}
