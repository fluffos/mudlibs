
// mei_po.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("镇关西", ({ "zgx" }) );
        set("title", "边军恶霸");
        set("gender", "男性" );
        set("age", 43);
     set("shen_type",-1);
	set("cps",10);
	set("str",40);
	set("cor",35);
	set("int",15);
	set("spi",5);
	set("per",1);
	set("con",20);
	set("kar",18);
        set("long",
                "一个满脸横肉，虎背熊腰的大块头\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
set("combat_exp", 810000);
	set("shen_type", 1);

    set("max_neili",8500);
    set("neili",8500);
    set("qi",8500);
    set("eff_qi",8500);
    set("max_qi",8500);

    set("jing",8500);
    set("eff_jing",8500);
    set("max_jing",8500);
        set_skill("force", 180+random(180));

        set_skill("unarmed", 180+random(180));
        set_skill("blade", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 280+random(180));
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),

        }) );




	set("jiali", 10);

        setup();
	carry_object("/d/city/npc/obj/gangdao")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
        add_money("gold", 3);
}
void init()
{
	object ob;
	::init();
	ob=previous_object();
	if(ob->query("gender")=="女性"&&ob->query("per")>=20)
		{
		remove_call_out("greeting");
		call_out("greeting", 1,ob);
		}
}
void greeting(object ob)
{
	if (is_fighting()) start_busy(2);
	tell_room(environment(),this_object()->query("name")+"色迷迷的流着口水......\n");
	message_vision(HIR "$N冲着$n说：小娘子。。。好俊嘛，陪大爷喝两盅吧！\n" NOR,this_object(),ob);
	if(ob->query("marks/杀镇"))
		ob->set("marks/杀镇",0);

}
void die()
{	int i;
	object *wife,room,killer;
	if(objectp(killer= query_temp("last_damage_from")))
		killer->set_temp("marks/杀镇",1);
	if(room=find_object("/d/ny/happyinn0"))
		room->set("exits/west","/d/ny/happyinn2");
	else return;
	write(HIR "后面的小门开了，里面冲出几个妖里妖气的女人。\n");
	write("这些女人扑在镇关西的尸体上放声大哭......\n" NOR);
	for(i=0;i<5;i++)
		new("/d/ny/npc/zwife")->move(room);
	::die();
}
