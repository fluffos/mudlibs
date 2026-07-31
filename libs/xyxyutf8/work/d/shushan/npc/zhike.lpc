//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("知客剑童", ({ "zhike jiantong", "jiantong","tong","zhike" }));
        set("title", "蜀山剑派");
        set("gender", "男性");
        set("age", 12 + random(5));
        set("attitude", "peaceful");
        set("class","taoist");
        create_family("蜀山派",5,"弟子");
	set_level(40);
	
        set_skill("force",400);
        set_skill("xianfeng-yunti",400);
        set_skill("dodge",400);
        set_skill("parry",400);
        set_skill("sword",400);
        set_skill("unarmed",400);
        set_skill("spells",400);
        set_skill("chuanyun-zhang",400);
        set_skill("yujianshu",400);
        set_skill("zuixian-wangyue",400);    
        set_skill("tianshi-fufa",350);

        map_skill("dodge", "zuixian-wangyue");
        map_skill("spells", "tianshi-fufa");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
