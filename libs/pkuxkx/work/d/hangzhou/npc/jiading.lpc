// jiading,by hubo
inherit NPC;

void create()
{
        set_name("家丁", ({"jia ding","ding"}) );
        set("gender", "男性" );
        set("age", 25);
        set("long", "这是一个守门的庄丁，紧绷着脸，他们是从庄丁中
精选出来看门的，所以功夫比较高。\n");
        set_temp("apply/attack", 35);
        set_temp("apply/defense", 35);
        set_temp("apply/damage",20);
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("str", 30);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
       set_skill("unarmed",45);
       set_skill("dodge",45);
        set_skill("parry",45);
        set("attitude","heroism");
        setup();
 
        carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object me)
{
        command("say 这里是私人场所，不接待外来游客");
        me->set_temp("marks/庄",0);
}