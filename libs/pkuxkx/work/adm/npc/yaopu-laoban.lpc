// yaopu-laoban.c 药铺老板
// by skywolf 2009-2-5 for wuzhishan-yaopu
#include <ansi.h>
//inherit ROOM;

inherit NPC;
inherit F_DEALER;

int ask_jiu();
void create()
{
	set("title", "五指山庸医");
	set_name("诸葛不亮", ({ "yaopu laoban", "laoban" }));
	set("gender", "男性");
	set("long", "这是一个江湖郎中，不知怎么跑到五指山开了一间药铺，专卖大力丸、十全大补丸
等药品。不过此人长的倒一表堂堂，五络长须，所以就给自己起了个名号叫诸葛不
亮，原来的名字，反倒没人知道了。\n");
	set("age", 65);

	set("combat_exp", 5000);
	set("attitude", "friendly");

	set("vendor_goods", ({
	}));
       set("inquiry", ([
       "五仙大补酒" : (: ask_jiu :),
    ]));

	set("shen_type",1);set("score",200);setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
//add_action("do_buy", "buy");
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 3000000)
        {
			who->set_temp("money_paid",1);
			return 1;
        }
        return 0;
}


int ask_jiu()
{		
	object me=this_player();
   	object ob;
    int jiu_time1;
	int jiu_count1;
	string jiu_time;
	string jiu_count;
	int time3=time();
	if (!read_file("/d/jiaofei/npc/obj/jiutime", 1, 1))
	{
		write_file("/d/jiaofei/npc/obj/jiutime","0"+time3,1);	
	}
    jiu_time = read_file("/d/jiaofei/npc/obj/jiutime", 1, 1);
    jiu_time1 = atoi(jiu_time);
	if (!read_file("/d/jiaofei/npc/obj/jiucount", 1, 1))
	{
		write_file("/d/jiaofei/npc/obj/jiucount","01",1);
	}
	jiu_count = read_file("/d/jiaofei/npc/obj/jiucount", 1, 1);
	jiu_count1 = atoi(jiu_count);
	

	if (jiu_count1>=6)
	{
		if (time3-jiu_time1 < 24*3600)
		{
			message_vision("\n诸葛不亮摸着胡子对$N说道：这酒配制不易，已经卖光了。\n",this_player());
			return 1;
		}

		if (time3-jiu_time1 >= 24*3600)
		{
			jiu_count1=1;
			write_file("/d/jiaofei/npc/obj/jiutime","0"+time3,1);
			write_file("/d/jiaofei/npc/obj/jiucount","0"+jiu_count1,1);
		}
	}
	if (me->query_temp("money_paid"))
		{
			me->delete_temp("money_paid");
			command("say 这酒可好着呢，咱俩有缘，我就将他赠予你吧。");
			command("say 此酒药性强烈，喝太多有害无益，切记切记。");
            jiu_count1=jiu_count1+1;
			write_file("/d/jiaofei/npc/obj/jiucount","0"+jiu_count1,1);
			ob=new("/d/jiaofei/npc/obj/wuxianjiu");
			ob->move(me);
            message_vision("\n诸葛不亮给了$N一壶五仙大补酒！\n",me); 
            return 1;
		}
            message_vision("\n诸葛不亮摸着胡子对$N说道：这酒可是珍品啊，一壶三百两，童叟无欺。\n",this_player());
            return 1;
}
