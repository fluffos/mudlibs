//modified by vikee for xlqy for NK_DX
//2000-11-23 16:21

inherit NPC;
 
void create()
{
        set_name("魔礼寿", ({ "moli shou", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "男性" );
        set("long","
四大天王之一，身担着保护后宫安全的重担，非同小可。他
的武功似乎属佛门一派，护国天王还有另外的杀手绝招，但
没有人知道是什么。也许正因为如此，玉皇才放心让他独担
重任。\n"
        );
	set("class", "xian");
	set("title", "持国天王");
        set("age",43);
        set_level(140);
        set("daoxing",3000000);
        set("force_factor", 120);
        set("mana_factor",120);

        set("eff_dx", 1500000);
        set("nkgain", 800);

        set_skill("unarmed",1400);
	set_skill("changquan", 1400);
        set_skill("parry",1400);
        set_skill("dodge",1400);
        set_skill("mace",1400);
	set_skill("spells", 1400);
        set_skill("wusi-mace",1400);
        set_skill("force",1400);
	set_skill("moshenbu", 1400);
	map_skill("dodge", "moshenbu");
        map_skill("mace","wusi-mace");
        map_skill("parry","wusi-mace");
	map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "在下就是持国天王，奉圣谕把守东天门。",
                "here" : "这里就是东天门，里面就是天宫。",
        ]) );
	set_temp("armor_level",100);
	set_temp("weapon_level",100);
	setup();
	carry_object(0,"mace",random(10))->wield();
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

