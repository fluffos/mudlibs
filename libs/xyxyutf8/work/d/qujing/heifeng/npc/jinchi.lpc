//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/jinchi.c
 
inherit NPC;

void create()
{
        set_name("金池长老", ({"jin chi","monk","jinchi"}));
        set("long", "一个看上去很慈祥的老和尚。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 150);
        set_level(45);
        set("per", 25);
        set("force_factor", 50);

        set_skill("force",450);
        set_skill("unarmed",450);
        set_skill("dodge",450);
        set_skill("parry",450);
        set_skill("spells",450);
        set_skill("buddhism",450);
        set_skill("unarmed",450);
        set_skill("jienan-zhi", 450);
        set_skill("lotusmove", 450);
        set_skill("lotusforce",450);
        set_skill("staff",450);
        set_skill("lunhui-zhang",450);

        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
       
        setup();
        carry_object("/d/obj/weapon/staff/chanzhang")->wield();
        carry_object("/d/qujing/heifeng/obj/cloth")->wear();
        setup();
}