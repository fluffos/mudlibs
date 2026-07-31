//xln.c 小龙女
#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name("小小龙女", ({ "xiao longnu", "xiao", "longnu" }));
        set("title","古墓侠侣");
        set("nickname",HIC"玉女素心"NOR);
        set("long", "她清丽异常，但也许是长居古墓之故，面色略白。\n");
        set("gender", "女性");
        set("age", 39);
        set("attitude", "friendly");
        set("per", 40);
        set("str", 24);
        set("dex", 23);
        set("con", 20);
        set("int", 24);

        set("max_qi", 1500);
        set("max_jing", 1000);
        set("neili", 1500);
        set("eff_jingli", 1000);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 400000); 
        set("unique", 1);
        
        set_skill("parry", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("throwing", 100);
        set_skill("whip", 100);
        set_skill("meinu-quanfa", 100);
        set_skill("cuff", 100);
        set_skill("yunu-shenfa", 100);
        set_skill("yinsuo-jinling", 100);
        set_skill("yunu-jianfa", 100);
        set_skill("yunu-xinjing", 100);
        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "yunu-shenfa");
        map_skill("cuff", "meinu-quanfa");
        map_skill("sword", "yunu-jianfa");
        map_skill("whip", "yinsuo-jinling");
        prepare_skill("cuff", "meinu-quanfa");

        setup();

        carry_object(__DIR__"obj/ys")->wield();
        carry_object("/d/gumu/obj/buxue1")->wear();
        carry_object("/d/gumu/obj/qun1")->wear(); 
        carry_object("/clone/medicine/rsg");
        carry_object("/clone/medicine/badan");
}
