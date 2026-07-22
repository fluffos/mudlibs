#include <ansi.h>
inherit NPC;
void create()
{
        set_name("鹤笔翁", ({ "he biweng", "he", "biweng" }) );
        set("title", HBBLU"玄冥二老"NOR);
        set("long", "他就是玄冥二老中的鹤笔翁。\n");
        set("gender", "男性" );
        set("age", 53);
        set("attitude", "peaceful");
        set("str",25);
        set("int",25);
        set("con",25);
        set("dex",25);
        set("unique", 1);
        set("per", 20);
        set("no_get", 1);

        set("max_qi", 10000);
        set("max_jing", 6500);
        set("neili", 16000);
        set("max_neili", 16000);
        set("jiali", 100);
        set("combat_exp", 4150000);
        set("eff_jingli", 7000);

        set_skill("force", 350);
        set_skill("xiantian-gong", 350);
        set_skill("dodge", 350);
        set_skill("tiyunzong", 350);
        set_skill("strike", 350);
        set_skill("xuanming-shenzhang", 350);
        set_skill("parry", 350);
        set_skill("literate", 250);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "tiyunzong");
        map_skill("strike", "xuanming-shenzhang");
        map_skill("parry", "xuanming-shenzhang");
        prepare_skill("strike", "xuanming-shenzhang");

        setup();
        carry_object("/d/wudang/obj/white-robe")->wear();
}
