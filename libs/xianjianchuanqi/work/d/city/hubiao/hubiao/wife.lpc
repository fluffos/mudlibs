// NPC: wife.c
// Date: Look 99/04/25

inherit NPC;

string ask_me();
void create()
{
        set_name("女眷", ({ "nv juan", "wife" }));
        set("nickname", "豪门闺秀");
        set("long", 
"这是一个江湖侠客的家眷，因家主漂移不定，所以流落在外。\n"
"脸上隐约流露出无奈的神色。\n");
        set("gender", "女性");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 21+random(9));
        set("str", 10);
        set("int", 10);
        set("con", 10);
        set("dex", 10);
        
        set("max_qi", 200);
        set("max_jing", 200);
        set("neili", 200);
        set("max_neili", 200);
        set("eff_jingli", 200);

        set("combat_exp", 20000);
        set("score", 500);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("strike", 20);

        set("inquiry", ([
                "目的" : (: ask_me :),
        ]));

        setup();
        carry_object("/clone/armor/green_silk")->wear();
        carry_object("/clone/armor/flower_shoe")->wear();
}

string ask_me()
{
        if (this_player()->query_temp("mubiao") == this_object()->query_temp("mubiao"))
                return "这位"+RANK_D->query_respect(this_player())+"怎么如此健忘，咱们是去找"+this_player()->query_temp("mubiao")+"的啊！";
        return "你我素不相识，我的目的怎么会告诉你？";
}

void unconcious()
{
        command("corpse");
        die();
}
