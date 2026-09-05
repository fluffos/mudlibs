//书店老板
inherit NPC;
#include <ansi.h>
inherit F_DEALER;
void create()
{
        set_name("花老板", ({ "hua laoban", "hua","laoban" }));
        set("long","花老板是出名的花痴，不仅爱花，种花，还卖花。\n");
        set("title",HIM"花痴"NOR);
        set("shen_type", 1);
        set("gender", "女性");
        set("age", 38);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        set("vendor_goods", ({
             __DIR__"obj/peony",
             __DIR__"obj/rose",
             __DIR__"obj/lavandula",
        }));
        setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


