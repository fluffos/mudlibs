 inherit NPC;
void create()
{
        set_name("小孩", ({ "sad kid","kid" }) );
        set("gender", "男性");
        set("age", 6);
        set("long",
                "一个六七岁的小孩，闷闷不乐地坐在田埂上。\n"
        );
        set("combat_exp",1000);
        setup();
        carry_object(__DIR__"obj/liandao")->wield();
}  
