#include "riyuenpc.h"
#include "riyuenpc2.h"

string askren();

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("绿竹翁", ({ "lvzhu weng", "weng" }));
        set("title",HIG "老篾匠" NOR);
        set("long","他身子略形佝偻，头顶稀稀疏疏的已无多少头发，大手大脚，精神却十分矍铄。\n");
        set("gender", "男性");
        set("age", 78);
        set("shen_type", -1);
        set("str", 30);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 500000);
        set("score",1000);
        set("chat_chance", 30);
        set("chat_msg", ({
                (: heal :),
        }));
        set("inquiry", ([
            "东方不败" : "东方教主的名字也是你叫得的？",
            "圣药" : "你怎么会知道这件事的？",
            "三尸脑神丹" : "你怎么会知道这件事的？",
            "东方教主" : (: ask_df :),
       ]) );

        set_skill("force", 120);
        set_skill("riyue-shengong", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("sword",120);
        set_skill("strike",120);
        set_skill("claw",120);
        set_skill("kaishan-zhang",120);
        set_skill("ryingzhua-gong",120);
        set_skill("panguan-bifa",120);
        set_skill("feitian-shenfa", 120);
        set_skill("literate",140);
        map_skill("force", "riyue-shengong");
        map_skill("parry", "panguan-bifa");
        map_skill("dodge", "feitian-shenfa");
        map_skill("sword","panguan-bifa");
        map_skill("strike","kaishan-zhang");
        map_skill("claw","ryingzhua-gong");
        prepare_skill("claw", "ryingzhua-gong");
        prepare_skill("strike", "kaishan-zhang");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
//                (: perform_action, "sword.xiezi" :),
        }) );
        create_family("日月神教", 21, "弟子");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
       }
void init()
{
        object ob;
        mapping fam;
        ::init();
        ob = this_player();
        if (interactive(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

