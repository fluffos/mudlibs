// child.c
// edit by pian
inherit NPC;
void create()
{
        set_name("小孩", ({ "child" }) );
        set("long", "一个流著鼻涕的小孩，睁著一双无邪的眼睛望著你。\n");
        set("gender", "男性" );
        set("age", 6);
        set("chat_chance", 10);
        set("chat_msg", ({
                "小孩叫道：呀 ～ 骑大马\n",
                "小孩叫道：咿 ～ 坐马车\n"
        }) );
        setup();
        carry_object("/d/xueting/obj/bamboo_sword")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        message_vision("小孩兴奋地跳著：好呀！来比武！叱！\n", me);
        return 1;
}
