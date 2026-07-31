inherit F_DEALERVIP;
inherit NPC; 

int ask_me();

void create()
{

        set_name("伙计", ({ "vip huoji", "huoji" }));
        set("title", "VIP伙计");
        set("kaifa",38);
        set("jizhi",46);
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "VIP伙计。\n");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/damage", 15);
        set("combat_exp", 40000);
        set("attitude", "friendly");
                set("inquiry", ([
    "vip":(:ask_me:),
        ]) );
        setup();
        carry_object("/clone/misc/changpao")->wear();
}
void init()
{
        add_action("do_pawn", "cun");
        add_action("do_redeem", "na");
        add_action("do_check", "check");
}
string ask_me()
{
        object ob;
         if (!this_player()->query("vip")) 
return "得了吧,请加入VIP先！";
         if (this_player()->query("vipget")>1) 
return "得了吧,拿过了还来！";
      this_player()->add("moneyvip",40);
     this_player()->set("vipget",10);

return "恭喜你获得VIP赠送的40天涯币";
}
