//船夫
//kiden
//2006.8.27
#include <ansi.h>
inherit NPC;
int ask_me();

void create()
{
        set_name("船夫", ({ "chuan fu","chuanfu" }));
    set("gender", "男性");
    set("age", 48);

    set("long", "一个中年船夫，身上的皮肤被阳光晒成了古铜色。\n");
    set("attitude", "friendly");
    set("combat_exp", 10000+random(50000));
    set("shen_type", 1);
    set("no_get",1);
    set_skill("unarmed", 20);
    set_skill("dodge", 20);
    set_skill("parry", 20);
        set_temp("apply/attack", 10);
    set_temp("apply/defense", 10);
    set("inquiry", ([

        "神龙岛" : (: ask_me :),
        "去神龙岛" : (: ask_me :),
        "出海" : (: ask_me :),
    ]) );

    setup();

}

int ask_me()
{
        command("say 好，我这就带你出海去神龙岛吧。请上船（enter boat）。\n");
        this_player()->set_temp("shenlong/去神龙岛",1);

        return 1;
}
