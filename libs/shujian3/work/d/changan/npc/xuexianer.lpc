// Write By Yanyang@SJ 2001.9.27
// npc: /d/changan/npc/xuexianer.c

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("雪仙儿", ({ "xue xianer", "xianer", "xue" }) );
        set("gender", "女性" );
        set("title", HIM"面若桃花"NOR);
        set("age", 36);
        set("long",
            "她原是一个青楼名妓，后来被当朝一位大官看中，据说这个妓院也是那个官员\n"
            "为她开的。雪仙儿已到中年，但仍风韵犹存。\n");
        set("str", 25);
        set("dex", 25);
        set("con", 25);
        set("int", 25);
        set("per", 30);
        set("shen_type", 1);
        set("no_get","雪仙儿你而言太重了。\n");


        set("combat_exp", 2000);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);

        set("attitude", "friendly");

        setup();

        carry_object(ARMOR_D("flower_shoe"))->wear();
        carry_object(ARMOR_D("pink_cloth"))->wear();
}
void init()
{
        object ob;

        ::init();
	if (base_name(environment()) != query("startroom")) return;
        if (interactive(ob = this_player()) && visible(ob) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting",1,ob);
        }
}

void greeting(object me)
{
        if (!me)
                return;
        command("look " + me->query("id"));

        if (me->query("gender")=="无性") {
        command("@@ "+ me->query("id"));
        command("say 我的天啊，快出去快出去，别人以为你是我们这儿的姑娘呢！看你长的……");
        message("vision", me->name() +"被哄出了万红楼。\n",
                environment(me), ({me}));
        me->move("/d/changan/eastjie1");
        message("vision", me->name() +"被人从万红楼里赶了出来。\n",
                environment(me), ({me}));

        }
        else {
                if (me->query("class") =="bonze") {
                command("say 我的天啊，" + RANK_D->query_respect(me)
                        +"也来光顾我们万红楼啊，欢迎欢迎，不过……。");
                }
                if (me->query("gender")=="女性") {
                command("say 我的天啊，这年月大姑娘也逛窑子？还是想入我们万红楼啊？");
                command("tsk");
                }
        }
        return ;
}
