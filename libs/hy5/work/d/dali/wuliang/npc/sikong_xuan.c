// NPC :sikong_xuan.c 司空玄
// By River 98/12
inherit NPC;
void create()
{
        set_name("司空玄", ({ "sikong xuan", "sikong", "xuan"}));
        set("title","神农帮帮主"); 
        set("gender", "男性" );
        set("age", 56);
        set("str", 27);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 20);
        set("attitude", "heroism");

        set("max_qi", 11800);
        set("max_jing", 12000);
        set("eff_jingli", 12000);
        set("neili", 12000);
        set("qi", 11800);        
        set("max_neili", 12000);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","他是神农帮帮主，颏下一把山羊胡子，神态甚是倨傲。\n");
        set("combat_exp", 400000);
        set("shen", -1000); 

        set_skill("parry", 220);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("strike", 200);
        set_skill("sword", 200);
        set_skill("kurong-changong", 200);   
        set_skill("feixing-shu", 200);
        set_skill("chousui-zhang", 200);
        map_skill("dodge", "feixing-shu");
        map_skill("parry", "chousui-zhang");
        map_skill("strike", "chousui-zhang");
        map_skill("force", "kurong-changong");
        prepare_skill("strike", "chousui-zhang");

        setup(); 
        carry_object("/clone/misc/cloth")->wear();
}

