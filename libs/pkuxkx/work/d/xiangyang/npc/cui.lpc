#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name("崔掌柜", ({ "cui zhanggui", "cui" }));
        set("title", BLU"沙锅王"NOR);
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "崔掌柜在这里老老实实的做沙锅,薄利多销,深得人心.\n");
        set_skill("unarmed", 80);
        set_skill("dodge", 60);
        set_temp("apply/damage", 15);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("vendor_goods", ({
             __DIR__ "obj/sgfan",
             __DIR__"obj/sgdoufu",
             __DIR__"obj/sgwanzi",
                }));
         set("chat_chance", 8);
        set("chat_msg", ({
      HIG"崔掌柜憨厚地对你笑着.\n"NOR
      HIG"客官进来吃碗沙锅暖暖身子吧!\n"NOR
        }) );     
   setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
