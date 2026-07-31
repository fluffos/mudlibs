// NPC :zhong_wanchou.c 钟万仇 
// By River 98/12
inherit NPC;
void create()
{
        set_name("钟万仇", ({ "zhong wanchou", "zhong", "wanchou"}));
        set("title","万劫谷谷主");
        set("nickname","马王神");
        set("gender", "男性" );
        set("age", 42);
        set("str", 26);
        set("con", 23);
        set("dex", 22);
        set("int", 10);
        set("per", 5);
   	set("attitude", "heroism");

        set("max_qi", 1800);
        set("max_jing", 2000);
        set("eff_jingli", 2000);
        set("neili", 2000);
	set("qi", 1800);	
        set("max_neili", 2000);
        set("jiali", 40);
        set("unique", 1);
        
        set("long","只见他好长一张马脸，眼睛生得甚高，一个园园的大鼻子却和嘴巴挤在一块。\n");
        set("combat_exp", 400000);
        set("shen", -1000); 

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("kurong-changong", 100);        
        set_skill("tiannan-step", 100);
        set_skill("kunlun-zhang", 100);
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "kunlun-zhang");
        map_skill("strike", "kunlun-zhang");
        map_skill("force", "kurong-changong");
        prepare_skill("strike","kunlun-zhang");

        set("inquiry", ([            
//            "段正淳" : (: ask_duan :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
