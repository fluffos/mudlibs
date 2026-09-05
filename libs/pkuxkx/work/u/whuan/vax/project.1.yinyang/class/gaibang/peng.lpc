// sample master.c code

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

#include "/new_quest/qgaibang.h"
#include "/new_quest/quest.h"
void consider();

void create()
{
        set_name("彭有敬", ({"peng youjing", "peng", "youjing"}));
        set("title",MAG "丐帮" NOR + YEL "九袋" NOR+ MAG "长老" NOR);
        set("nickname", GRN "掌钵龙头" NOR);
        set("gender", "男性");
        set("age", 50);
        set("long",
                "彭有敬是丐帮中净衣派的首领，衣着干净华丽，不象叫化子。\n"
                "他脸上挂着慈祥的笑容，一双眼睛有摄人心魄的力量。\n");

        set("attitude", "peaceful");

        set("str", 24);
        set("int", 20);
        set("con", 24);
        set("dex", 20);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 100);
        set("max_jing", 100);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 120);

        set("combat_exp", 1200000);
        set("score", 20000);

        set_skill("force", 120); // 基本内功
        set_skill("huntian-qigong", 120); // 混天气功
        set_skill("strike", 115);
        set_skill("xianglong-zhang", 110); // 降龙十八掌
        set_skill("dodge", 125); // 基本躲闪
        set_skill("xiaoyaoyou", 115); // 逍遥游
        set_skill("parry", 120); // 基本招架
        set_skill("staff", 120); // 基本棍杖

        map_skill("force", "huntian-qigong");
        map_skill("strike", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");

        prepare_skill("strike", "xianglong-zhang");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
      ]));


        create_family("丐帮", 18, "九袋长老");
        setup();
}

void attempt_apprentice(object ob)
{
        command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。
");
}
