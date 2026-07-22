// /kungfu/class/xueshan/gelunbu.c  葛伦布
// by secret
#include <ansi.h>
inherit BHNPC;
inherit F_MASTER;
void create()
{
        set_name("葛伦", ({ "gelunbu", "ge" }));
        set("long",@LONG
葛伦是雪山寺中护寺僧兵的头领。同时向本寺第子传授武功。
身穿一件黑色袈裟，头带僧帽。
LONG
        );
        set("title", HIY "喇嘛" NOR);
        set("nickname", HIG "僧兵头领" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "heroism");
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 1000000);
        set_skill("mizong-xinfa", 100);
        set_skill("literate", 110);
        set_skill("force", 110);
        set_skill("longxiang", 110);
        set_skill("dodge", 115);
        set_skill("shenkong-xing", 110);
        set_skill("parry", 110);
        set_skill("staff", 110);
        set_skill("xiangmo-chu", 110 );
        set_skill("hammer",110);
        set_skill("riyue-lun",110);
        set_skill("unarmed", 110);
        set_skill("yujiamu-quan", 110);


        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("hammer","riyue-lun");
        map_skill("unarmed","yujiamu-quan");
        create_family("雪山寺", 5, "喇嘛");
        set("class", "bonze");
        setup();
        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();
        add_money("silver",30);
}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "男性") {
                command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
        }
        command("say 我就传你一些武功吧！");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "bonze")       {
                ob->set("title","俗家弟子");
        }
        else    {
                ob->set("title",HIY"小喇嘛"NOR);
        }
        
}

