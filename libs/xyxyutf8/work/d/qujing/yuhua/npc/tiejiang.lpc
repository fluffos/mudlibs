#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
set_name("铁匠", ({ "tie jiang", "jiang" }) );
set("gender", "男性");
set("age", 35);
set_level(4);
set("attitude", "heroism");

set("str", 40);
set("max_kee", 400);
set("max_gin", 400);
set("force", 400);
set("max_force", 400);
set("force_factor", 40);
set_skill("unarmed", 40);
set_skill("parry", 40);
set_skill("dodge", 40);
set_skill("blade", 40);

set("vendor_goods", ([
        "tongkuang" : "/d/obj/yelian/tong",
        "tongjia"   : "/d/obj/armor/tongjia",
]));    
setup();
carry_object("/d/obj/cloth/linen")->wear();
carry_object("/d/obj/weapon/hammer/hammer")->wield();
}