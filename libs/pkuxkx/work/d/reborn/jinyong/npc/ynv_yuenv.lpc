#include <ansi.h>

inherit NPC;
int ask_me();
void create()
{
        set_name("阿青", ({ "a qing", "qing" }));
        set("long","她长得一张瓜子脸，睫长眼大，皮肤白晰，容貌甚是秀丽，身材苗条，弱质纤纤。\n");
        set("gender", "女性");
        set("age", 17);
        set("attitude","friendly");
        set("str", 30);
        set("int", 30);
        set("dex", 30);
        set("con", 30);
        set("per", 40);
        set("spi", 30);
        set("kar", 30);
        set("max_qi", 30000);
        set("max_jing", 30000);
        set("qi", 30000);
        set("jing", 30000);
        set("max_neili", 30000);
        set("max_jingli", 30000);
        set("neili", 30000);
        set("jingli", 30000);
        set("jiali", 300);
        set_skill("sword", 3000);
        set_skill("dodge", 3000);
        set_skill("parry", 3000);
        set("combat_exp",300000000);
        set("inquiry", ([
                "越女剑" : (: ask_me :),
        ]) );
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/greenrobe")->wear();
}
int ask_me()
{
       command("sigh");
       say("阿青没有说什么，只是指了指地下，示意你自己想办法。\n");
       return 1;
}
