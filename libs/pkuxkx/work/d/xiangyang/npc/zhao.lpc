#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void create()
{
        set_name(HIC"赵老板"NOR, ({ "zhao laoban", "zhao","laoban" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "这是一位饱经风霜的生意人."
           );
        set_skill("unarmed", 80);
        set_skill("dodge", 60);
        set_temp("apply/damage", 15);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("vendor_goods", ({
             __DIR__ "obj/buliao1",
             __DIR__"obj/buliao2",
             __DIR__"obj/buliao3",
             __DIR__"obj/buliao4",
                }));
         set("chat_chance", 8);
        set("chat_msg", ({
      HIG"赵老板殷勤地招呼你：来看看我卖的绸衫吧？\n"NOR
      HIG"买我的料子给你的小情人做件新衣服吧!\n"NOR
        }) );     
   setup();
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
