//modified by vikee for xlqy for NK_DX
//2000-11-23 16:21


inherit NPC;
void create()
{
        set_name("魔礼海", ({ "moli hai", "duowen tianwang", "hai", "tianwang" }) );
        set("gender", "男性" );
	set("long",
		"魔家四将之一，使一根盘龙棍，背上一面琵琶，上有四条弦；也按\n"
                "地、水、火、风，拨动弦声，风火齐至，如青云剑一般。\n"
	);
	set("age",50);
	set_level(140);
	set("title", "多闻天王");
	set("attitude", "heroism");
        set("daoxing",3000000);
	set("force_factor", 120);
	set("mana_factor",120);

        set("eff_dx", 1500000);
        set("nkgain", 800);
	
	set_skill("unarmed",1400);
	set_skill("yingzhaogong", 1400);
	set_skill("parry",1400);
	set_skill("dodge",1400);
	set_skill("stick",1400);
	set_skill("kusang-bang",1400);
	set_skill("force",1400);
	set_skill("spells", 1400);
	set_skill("moshenbu", 1400);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "kusang-bang");
	map_skill("stick", "kusang-bang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "在下多闻天王魔礼海，奉圣谕把守北天门。",
		"here" : "这里就是北天门, 入内就是天界了。",
	]) );

	set_temp("armor_level",100);
	set_temp("weapon_level",100);
	setup();
	carry_object(0,"stick",random(10))->wield();
	carry_object(0,"armor",random(10))->wear();
	carry_object(0,"kui",random(10))->wear();
	carry_object(0,"shoes",random(10))->wear();
	carry_object(0,"pifeng",random(10))->wear();
}


int accept_fight(object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N说到：也要你知道本天王的厉害！\n", ob);
      }
        return 1;
}

void kill_ob (object me)
{
        object ob=this_object();

    if( living(ob) )
      {
        message_vision("$N说到：送你上西天！\n", ob);
      }

        ::kill_ob(me);

}

