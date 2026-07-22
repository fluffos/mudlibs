//modified by vikee for xlqy for NK_DX
//2000-11-23 16:18




inherit NPC;
void create()
{
        set_name("魔礼红", ({ "moli hong", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "男性" );
	set("long",
		"魔家四将之一，使一杆方天画戟，秘授一把伞。名曰：「混元伞。」\n"
                "伞皆明珠穿成，有祖母绿，祖母碧，夜明珠，辟尘珠，辟火珠，辟水\n"
                "珠，消凉珠，九曲珠，定颜珠，定风珠。还有珍珠穿成「装载乾坤」\n"
                "四字，这把伞不敢撑，撑开时天昏地暗，日月无光，转一转乾坤晃动。\n"
	);
	set("age",50);
	set_level(140);
	set("title", "广目天王");
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
	set_skill("spear",1400);
	set_skill("bawang-qiang",1400);
	set_skill("force",1400);
	set_skill("spells", 1400);
	set_skill("moshenbu", 1400);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "bawang-qiang");
	map_skill("spear","bawang-qiang");
	map_skill("unarmed", "yingzhaogong");
	set("inquiry", ([
		"name" : "在下广目天王魔礼红，奉圣谕把守南天门。",
		"here" : "这里就是南天门, 入内就是天界了。",
	]) );
	set_temp("armor_level",100);
	set_temp("weapon_level",100);
	setup();
	carry_object(0,"spear",random(10))->wield();
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

