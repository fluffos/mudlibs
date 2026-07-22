inherit NPC;

void create()
{
        set_name("金甲卫士", ({ "wei shi", "shi", "guard" }) );
        set("gender", "男性");
        set("age", 25);
        set_level(38);
        set("long","这是位守护皇城的金甲武士，身披铜甲，手执金瓜。他双目精光炯炯，警惕地巡视着四周的情形。\n");
        set("attitude", "heroism");
        set("force_factor", 15);
        set_skill("hammer", 380);
        set_skill("unarmed", 380);
        set_skill("parry", 380);
        set_skill("dodge", 380);
	set_skill("force", 380);
        setup();
	carry_object(0,"hammer",random(2))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        powerup(1,1);
}
