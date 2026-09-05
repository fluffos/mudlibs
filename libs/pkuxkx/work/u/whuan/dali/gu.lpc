// by whuan@2008-3-6 大理段家
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("古笃诚", ({ "gu ducheng", "gu"}));
        set("long", "他黄衫褚巾头，身着黄衣军服，满脸虬髯，神态威猛，
腰间插着一对板斧，似是纯钢打制。他是段王爷的四大家臣之一。\n");
        set("title","大理国武将");
        set("gender", "男性");
        set("age", 35);
        set("inquiry", ([
                "段正淳": "正是我家王爷！",
            ]));
        set_skill("cuff", 60);
        set_skill("jinyu-quan", 60);
        set_skill("dodge", 50);
        set_skill("duanshi-shenfa", 50);
        set_skill("parry", 50);
        set_skill("force", 50);
        set_skill("buddhism", 65);
        set_skill("axe", 60);
        set_skill("duanjia-xinfa",60);
        map_skill("cuff","jinyu-quan");
        map_skill("dodge","duanshi-shenfa");
        map_skill("force","duanjia-xinfa");
        prepare_skill("cuff","jinyu-quan");
        set("str", 32);
        set("int", 21);
        set("con", 27);
        set("dex", 23);
        set("max_qi", 500);
        set("max_jing", 500);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 30);
        set("combat_exp", 150000);
        set("attitude", "peaceful");
        set("shen_type", 1);
        create_family("大理段家", 15, "弟子");
        setup();
        carry_object("/d/dalicheng/obj/ycloth")->wear();     
        carry_object("/d/dalicheng/obj/gangfu")->wield();
}
void attempt_apprentice(object ob)
{
        mapping fam;
        object obj;
        if((int)ob->query("betrayer"))
        {
        	      command("heng");
                command("say 我们段家岂能相信你这种背信弃义之徒！\n");
                return;
        }
        if ((string)ob->query("family/family_name")=="大理段家")
        {
                command("say 岂敢！岂敢！！");
                return;
        }
        command("say 既然"+RANK_D->query_respect(ob)+"愿意加入我们段家，
        我就收你为徒，暂时传授你一些入门的功夫。");
        command("recruit " + ob->query("id"));
        command("smile");
        ob->set("title",MAG"大理段家"HIC + "卫士" NOR);
        return;
}
