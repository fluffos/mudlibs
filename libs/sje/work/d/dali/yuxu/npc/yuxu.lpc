// Modify By River 98/12
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("玉虚散人", ({ "yuxu sanren", "yuxu", "sanren" }));
        set("title", "玉虚观主持");
        set("long", "这是一个中年道姑，但容颜俏丽，略带些哀愁。\n");
        set("gender", "女性");
        set("rank_info/respect", "道姑");
        set("age", 37);
        set("attitude","friendly");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("unique", 1);
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("qiantian-yiyang",80);
        set_skill("dodge", 80);
        set_skill("whip",80);
        set_skill("qingxu-bian", 80);
        set_skill("tianlong-xiang",80);
        map_skill("whip", "qingxu-bian");
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        
        set("combat_exp", 150000);
        set("max_qi", 900);
        set("max_jing", 400);
        set("neili", 900);
        set("eff_jingli",400);
        set("max_neili", 900);
        setup();
        carry_object(__DIR__"obj/fuchen")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();

}
