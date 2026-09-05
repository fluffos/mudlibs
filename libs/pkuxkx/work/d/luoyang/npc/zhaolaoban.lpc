//书店老板
inherit NPC;
void create()
{
        set_name("赵老板", ({ "zhao laoban", "zhao","laoban" }));
        set("long","洛阳唐三彩的老板，他这里所出的瓷器闻名全国。\n");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 38);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
        setup();
}
void init()
{
        add_action("do_none", "list");
        add_action("do_none", "buy");
}
int do_none()
{
    write("对不起，本店不对普通客人售货！\n");
    return 1;
}

