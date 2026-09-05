// tang.c 唐老板 

inherit NPC;
//inherit F_VENDOR;

void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));	
	set("title", "当铺老板");
	set("random_npc",1);
    set("shen_type", 0);
	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", random(30)+35);
	set("long",
		this_object()->query("name")+"是这里的老板，守着这件当铺已经有很久了。\n");
//          set("no_get_from", 1);
    set("no_get", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	set("shen_type",1);set("score",500);setup();
}

