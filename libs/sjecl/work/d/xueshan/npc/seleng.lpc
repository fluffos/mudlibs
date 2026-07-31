// seleng.c 色楞
// by iceland

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("色楞", ({ "se leng", "seleng" ,"se","leng" }));
        set("long",@LONG
他长得身材矮小，肥肥胖胖。因为不肯下功夫，练武参禅样样不行。平时爱管个闲事，
所以寺里分配他管理寺中大小各项杂物。
LONG
        );
        set("title", HIY "大轮寺弟子" NOR);
        set("gender", "男性");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 15);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 300);
        set("eff_jing", 150);
	set("max_jing",150);
        set("neili", 100);
        set("max_neili", 100);
        set("combat_exp", 5000);
        set("score", 100);
	set("unique", 1);

        set_skill("huanxi-chan", 20);
        set_skill("force", 20);
        set_skill("longxiang-boruo", 20);
        set_skill("dodge", 20);
        set_skill("yuxue-dunxing", 20);
        set_skill("claw", 20);
        set_skill("tianwang-zhua", 20);
        set_skill("parry", 20 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("parry", "tianwang-zhua");
        map_skill("claw", "tianwang-zhua");

        prepare_skill("claw","tianwang-zhua");

        create_family("大轮寺", 13, "弟子");
        set("class", "huanxi");

        set("chat_chance", 3);
	set("chat_msg", ({
"色楞神气活现的来回巡视，不时嚷道：“快干！快干！别偷懒！”\n",
"色楞咂了咂嘴：“前天的烧狗肉真不错。”\n",
"“喂喂！你！”色楞冲上去，对着个老实巴交的工匠手舞足蹈，口沫横飞的大发脾气。\n",
}) );
        setup();
        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();

        add_money("silver",50);
}
