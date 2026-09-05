inherit NPC;
inherit F_DEALER;
void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("title","老工匠");
	set("gender", "男性" );
	set("age", 40+random(20));
	set("long",
		"这是一位老年的船匠，偶尔也买一些东西。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("random_npc",1);
	setup();
    set("vendor_goods", ({
		"/d/yingtianfu/neicheng/obj/boat_tool",
	}));
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
    
}

