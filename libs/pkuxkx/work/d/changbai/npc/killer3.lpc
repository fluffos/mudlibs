// File         : killer.c
// Created By   : whuan@pkuxkx, 2007-07-02
#include <ansi.h>
inherit QUEST_NPC;
#include <random_name.h>
int whisper_to_me(object me,object killer)
{
    command("whisper "+ me->query("id")+ " 你有种去"+me->query_temp("yidao/where")
		            +"找我兄弟"+killer->query("name")+"("+killer->query("id")
		            +")，他会给我报仇的！”\n" );
    return 1;
}
#include "killer.h"

int ask_rumors();
int do_copy(object me);
void die();
void create()
{
        set_name(get_rndname(), ({get_rndid(), }));
        set("job_title","盗 宝 人");
        set("nickname",WHT"过江龙"NOR);
        set("gender", "男性" );
        set("killer_3","whatthehell");
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
        set("hyd/step",3);
        setup();
        carry_object("/clone/armor/bianfuxuejia")->wear();
        call_out("do_leave", 1800);
}
