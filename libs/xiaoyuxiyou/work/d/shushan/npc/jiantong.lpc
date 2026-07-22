//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

void create()
{
	int i = 40+random(10);
        set_name("剑童", ({ "jian tong", "tong" }));
        set("gender", "男性");
        set("age", 14 + random(5));
        set("attitude", "peaceful");
        set("class","taoist");
        create_family("蜀山派",5,"弟子");
	set_level(i);
	
        set_skill("force",i*10);
        set_skill("xianfeng-yunti",i*10);
        set_skill("dodge",i*10);
        set_skill("parry",i*10);
        set_skill("sword",i*10);
        set_skill("unarmed",i*10);
        set_skill("spells",i*10);
        set_skill("chuanyun-zhang",i*10);
        set_skill("yujianshu",i*10);
        set_skill("zuixian-wangyue",i*10);    
        set_skill("tianshi-fufa",i*10);

        map_skill("dodge", "zuixian-wangyue");
        map_skill("spells", "tianshi-fufa");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"sword",random(3))->wield();
}

