// gaibang npc code

#include <ansi.h>
#include "gaibang-master.h"

inherit NPC;
inherit F_MASTER;

int accept_object(object ob, object obj);
int accept_fight(object ob);
int checking(object me, object ob);

void create()
{
        set_name("赵狗儿", ({"zhao gouer", "zhao", "gouer"}));
        set("title",MAG "丐帮" NOR + YEL "一袋" NOR+ MAG "弟子" NOR);
        set("gender", "男性");
        set("age", 17);
        set("long",
                "这是位衣著邋塌，蓬头垢面的丐帮一袋弟子。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 20);
        set("chat_msg", ({
              (: heal :),
        }));
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);
        set("jiali", 30);
        set("dai",1);
        set("combat_exp", 5000);

        set_skill("force", 30);
        set_skill("huntian-qigong", 30);
        set_skill("jiaohua-xinfa", 25);
        set_skill("blade", 30);
        set_skill("liuhe-dao", 30);
        set_skill("hand", 30);
        set_skill("shexing-shou", 30);
        set_skill("dodge", 30);
        set_skill("xiaoyaoyou", 30);
        set_skill("parry", 30);
        set_skill("begging", 30);
        set_skill("stealing", 30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: exert_function , "powerup" :),
                (: combat_heal :),
        }) );

        map_skill("force", "huntian-qigong");
        map_skill("hand", "shexing-shou");
        map_skill("blade", "liuhe-dao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");

        prepare_skill("hand", "shexing-shou");

        create_family("丐帮", 26, "弟子");
        setup();
}


