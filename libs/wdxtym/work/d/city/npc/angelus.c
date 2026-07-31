// city/npc/angelus.c

inherit NPC;
inherit F_DEALER;
string do_level_up();
void create()
{
	set_name("神秘商人", ({ "shen mi"}));
	set("level_up",1);
	set("gender", "男性");
	set("age", 20);
	set("per", 30);
	set("con", 30);
	set("int", 30);
	set("level", 99);
	set("dex", 30);
	set("str", 30);
	set("long","神秘商人，回收各种书籍和套装部件，同时出售一些套装。\n");
	set_skill("unarmed", 600);
	set_temp("apply/damage", 150);
	set("inquiry", ([
		"回收": "如果有多余的<套装>或<书籍>,可以给我换取<兑换点>",
	]) );
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("duihuan",1);
	set("vendor_goods", ({
	       "/clone/suit/wudang/zhenwu_sword",
	      "/clone/suit/wudang/zhenwu_finger",
	      "/clone/suit/wudang/zhenwu_arrmor",
	      "/clone/suit/wudang/zhenwu_neck",	
	      "/clone/suit/wudang/zhenwu_head",
	      "/clone/suit/wudang/zhenwu_hands",
	      "/clone/suit/wudang/zhenwu_pants",
	      "/clone/gift/jiuzhuan",
	      "/clone/gift/unknowdan",
	       "/clone/gift/xisuidan",
	       "/clone/gift/shenliwan",
		"/clone/gift/xiandan",
	       "/clone/gift/mdiamond",
	}));
	
	setup();
	carry_object(__DIR__"cloth/cloth")->wear();
}

void init()
{
	add_action("do_level_up","level_up");
	add_action("do_up_skills","up_skills");
	add_action("do_up_tianfu","up_tianfu");
	add_action("do_pointlist", "list");
	add_action("do_huan", "huan");
}
//回收套装.
int accept_object(object who, object ob)
{
      int suit_point=0,suit_level=0;
      mapping book=([ ]);
	if(ob->query("skill")) book=ob->query("skill");
	if(ob->query("suit"))
	{
	    suit_level=(int)ob->query("suit_lvl");
	    if(suit_level != 1)
	    {
	       suit_point=random(suit_level*10)+1;
	    }
	    else
	    {
	       suit_point=random(suit_level*2)+1;
	    }	
	    who->add("suit_point",suit_point);
	    message_vision(HIG"神秘商人对你点点头,这件套装我收了,< "+HIM+suit_point+HIG+" 兑换点 > 已经给你了。"NOR"\n", who);
	    destruct(ob);
	    return 1;
	}
	if(book["max_skill"])
	{
	    suit_level=(int)ob->query("value")/10000;
	    suit_point=random(suit_level)+1;
	     who->add("suit_point",suit_point);
	    message_vision(HIG"神秘商人对你点点头,这本书我收了,< "+HIM+suit_point+HIG+" 兑换点 > 已经给你了。"NOR"\n", who);
	    destruct(ob);
	    return 1;
	}
	    command("say 这不是套装或书籍,我不回收！");
	    return 0;
}
