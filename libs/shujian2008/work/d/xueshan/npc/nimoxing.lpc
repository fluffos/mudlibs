// nimoxing.c 尼摩星
// by iceland

#include <ansi.h>
inherit NPC;
#include "cike.h";

void create()
{
        set_name("尼摩星", ({ "nimo xing", "nimoxing","nimo","xing" }));
        set("long",@LONG
他肤色黝黑，犹如铁板一样，两只眼睛炯炯有神。他原是西域逾迦高手，曾在比武中
败在金轮法王手下，因此拜到大轮寺门下。
LONG
        );
        set("title", HIY "大轮寺第十二代弟子" NOR);
        set("gender", "男性");
	set("class", "huanxi");
        set("age", 36);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 30);
        set("int", 20);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1200);
        set("eff_jing", 500);
	set("max_jing",500);
        set("neili", 1600);
        set("max_neili", 1600);
        set("jiali", 50);
        set("combat_exp", 450000);
        set("score", 50000);
	set("unique", 1);

        set_skill("huanxi-chan", 120);
        set_skill("literate", 80);
        set_skill("force", 120);
        set_skill("longxiang-boruo", 120);
        set_skill("dodge", 120);
        set_skill("yuxue-dunxing", 120);
        set_skill("tianwang-zhua", 120);
        set_skill("parry", 120);
        set_skill("wushang-dali", 120);
        set_skill("staff", 120);
        set_skill("claw", 120 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("claw", "tianwang-zhua");
        map_skill("parry", "wushang-dali");
        map_skill("staff", "wushang-dali");

        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 12, "弟子");
        set("class", "huanxi");

        setup();
        carry_object(__DIR__"obj/gongde-jiasha")->wear();
        carry_object(BINGQI_D("dujiaotongren"))->wield();        

        add_money("gold",1);
}
