#include <ansi.h>
inherit NPC;

void create()
{
        set_name("地狮", ({ "di shi", "shi" }));
        set("long", 
                "他乃兽族二神将之一,和天虎并列,地位仅次与神兽王。\n"
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("int", 40);
        set("str", 40);
        set("con", 40);
        set("dex", 40);
        
        set("max_qi", 4000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 150);
        set("combat_exp", 600000);
        set("score", 50000);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("unarmed", 170);
        set_skill("parry", 170);


        set("chat_chance_combat", 90);

        setup();

}
