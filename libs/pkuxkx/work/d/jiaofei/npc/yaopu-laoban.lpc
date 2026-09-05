// yaopu-laoban.c 药铺老板
// by skywolf 2009-2-5 for wuzhishan-yaopu

inherit NPC;
inherit F_DEALER;

int ask_jiu();
int ask_heal();
void create()
{
	set("title", "五指山庸医");
	set_name("诸葛不亮", ({ "yaopu laoban", "laoban" }));
	set("gender", "男性");
	set("long", "一位精明的药房老板,医术虽然不高，但却很会做生意。\n");
	set("age", 65);

	set("combat_exp", 5000);
	set("attitude", "friendly");

	set("vendor_goods", ({
	}));
       set("inquiry", ([
       "五仙大补酒" : (: ask_jiu :),
       "疗伤" : (: ask_heal :),
    ]));

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
//add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
	int duration = 0;
    if(JIAOFEI_D->istaskstart() != 1)
    {
        return notify_fail("诸葛不亮说：这不知从何所起，无功不受禄啊。\n");
    }
    if (ob->query("money_id"))		
    {
		if(ob->value() >= 3000000)
		{
	        who->set_temp("jiaofei/money_paid",2);
		}
		else if(ob->value() >= 200000 && who->query_temp("jiaofei/ask_heal"))
		{
			command("xixi");
			command("say 好啦，你的手没事了。继续杀猪去吧。");
            duration=who->query_condition("cannt_eq");
            if(duration>0) 
            {
				who->apply_condition("", 0);
            }
		}
        return 1;
    }
    return 0;
}


int ask_jiu()
{
	object me=this_player();
	object ob;
  
	if (me->query_temp("jiaofei/money_paid"))
	{
			me->delete_temp("jiaofei/money_paid");
			command("say 这酒可好着呢，咱俩有缘，我就将他赠予你吧。");
			command("say 此酒药性强烈，喝太多有害无益，切记切记。");
			ob=new(__DIR__"obj/wuxianjiu");
			ob->move(me);
            message_vision("\n诸葛不亮给了$N一壶五仙大补酒！\n",me); 
            return 1;
     }
     message_vision("\n诸葛不亮摸着胡子对$N说道：这酒可是珍品啊，一壶三百两，童叟无欺。\n",this_player());
     return 1;
}

int ask_heal()
{
     object me=this_player();
     object ob=this_object();
	 int duration = 0;
    if(JIAOFEI_D->istaskstart() != 1)
	 {
		return 0;
	 }
	 duration=me->query_condition("cannt_eq");
	 if(duration > 0)
  	 {
		 message_vision( "$n看了看$N的手腕，摇了摇头，伤的不轻啊。\n这样吧，你给我20两金子，我给你治好。\n", me, ob);
		 me->set_temp("jiaofei/ask_heal",1);
	 }
	 else
	{
		command("faint");
		command("say 没事你来看什么伤，要不要我砍你一刀再来看？");
	}
     return 1;
}