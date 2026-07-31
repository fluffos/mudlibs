inherit NPC;
inherit F_SAVE;

string query_save_file() { return DATA_DIR + "npc/孙二娘"; }
void create()
{

	set_name("孙二娘", ({ "sunerniang", "sunerniang", "sunerniangr" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"这位孙二娘正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/jiu1",
		__DIR__"obj/jiu2",
		__DIR__"obj/jiu3",
	}));
	set("area_name","雁荡芙蓉客栈");
	set("area_file","/d/yandang/yuanluo.c");
	 setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/hainan/npc/weapon/thin_sword")->wield();
}

int accept_object(object who,object obj)
{
        string bh;

        bh=(string)who->query("banghui");
        if( !bh || bh!=(string)query("banghui"))        {
                if (obj->query("money_id")&&obj->value()>=200)  {
			if(who->query("gender")=="女性")
                	tell_object(who,"孙二娘面带笑容道:北面客房请。\n");
			else tell_object(who,"孙二娘面带笑容道:南面客房请。\n");
                who->set_temp("rent_paid",1);

                return 1;
                }
                else    {
                tell_object(who,"孙二娘道：住店要二两纹银。\n");
                return 0;
                }
        }
        if (obj->query("money_id")&&obj->value()>=100)  {
 		if(who->query("gender")=="女性")
             	tell_object(who,"孙二娘面带笑容道:这位姐妹，北面客房请。\n");
		else tell_object(who,"孙二娘面带笑容道:这位弟兄，南面客房请。\n");
        
        who->set_temp("rent_paid",1);
        return 1;
        }
        else    {
                tell_object(who,"孙二娘道：同帮弟兄也得付个一两银子意思意思吧。\n");
                return 0;
        }
}
