// File         : killer.c
// Created By   : whuan@pkuxkx, 2007-07-02
#include <ansi.h>
inherit FAMILY_NPC;
#include <random_name.h>


#include "killer.h"

int ask_rumors();
void create()
{
        set_name(get_rndname(), ({get_rndid(), }));
        set("title","见 习 盗 宝 人");
        set("nickname",HIW"化骨龙"NOR);
        set("gender", "男性" );
        set("age", 22+random(22));
        set("combat_exp", 10000000);
        set("attitude", "heroism");
        add("inquiry", ([
                "name" : "大爷我有要事在身，别烦我！",
                "here" : "大爷我有要事在身，别烦我！",
                "rumors" : (:ask_rumors:),
                "fight" : (:ask_fight:),
        ]));
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :),
                (: random_move :),
        }) );
        set("uni_target", 1);
        set("jiali", 50);
        set("hyd/step",1);
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        call_out("do_leave", 1800);
}


