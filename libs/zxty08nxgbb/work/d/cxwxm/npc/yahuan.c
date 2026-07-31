//yahuan.c
inherit NPC;
void init();
void create()
{
       set_name("丫鬟", ({ "ya huan" }) );
        set("gender", "女性" );
        set("jihao",1);
        set("age", 15);
        set("long", "门主的贴身丫鬟。\n");
        set("shen_type", 1);
        set("combat_exp", 10000);
        set("str", 20);
        set("dex", 22);
        set("con", 20);
        set("int", 21);
        set("attitude", "friendly");
        setup();
        carry_object("/d/cxwxm/obj/cloth2")->wear();
        }
