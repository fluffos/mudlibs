// punk.cvillage/npc/punk.c
inherit NPC;
void create()
{
        set_name("庄丁", ({"zhuang ding","ding"}) );
        set("gender", "男性" );
        set("age", 18);
        set("long", "这是一个懒惰的小庄丁，是正在着打水。\n");
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set("combat_exp", 700);
        set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
"庄丁骂骂咧咧的说道：他妈的，又让老子打水。\n",
"庄丁爬在井上喝了几口水，说道：真他妈的邪，全山庄就这一口井最甜\n",
"庄丁嘿嘿奸笑几声，说道：我先在这歇会儿，回去还得干。\n",
        }) );
        carry_object(__DIR__"obj/cloth")->wear();
}
