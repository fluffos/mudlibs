inherit NPC;
inherit F_DEALER;
void create()
{
    set_name("左左木",({"zuozuo mu","mu"}));
        set("title","神户当铺");
   set("age",40);
   set_max_encumbrance(100000000);
   set("combat_exp",1200000);
   set("force",1000);
   set("max_force",1000);
   set("force_factor",30);
   set("max_qi",800);
   set("mingwang",500);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("dodge",100);
   set_skill("force",100);
   set_temp("apply/armor",50);
   set_temp("apply/damage",25);
   
   setup();
   carry_object("/clone/misc/cloth")->wear();
 add_money("gold",1);
}
void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");
}
void unconcious()
{

        message_vision("\n$N死了。\n", this_object());
        destruct(this_object());
}
