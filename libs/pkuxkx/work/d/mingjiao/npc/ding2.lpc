// ding2,by binlang
inherit NPC;
void create()
{
        set_name("庄丁", ({"zhuang ding","ding"}) );
        set("gender", "男性" );
        set("age", 48);
        set("long", "这是一个守门的庄丁，紧绷着脸，他们是从庄丁中
精选出来看门的，所以功夫比较高。\n");
        set_temp("apply/attack", 35);
        set_temp("apply/defense", 35);
        set_temp("apply/damage",20);
        set("combat_exp", 30000);
        set("shen_type", -1);
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
       add_money("silver", 10);
}
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
		ob->delete_temp("marks/庄"); //modified by iszt, to avoid blocking the way after paid, 2006-09-03
                call_out("greeting", 1, ob);
        }
}
void greeting(object me)
{
	if(!me->query_temp("marks/庄"))
		command("say 想要进庄吗？是不是该意思一下？嘿嘿……");
}
int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 200
                && !this_object()->query("waiting_target"))
        {
           command("bow " + who->query("id"));
            command("say 您里面请。");
            who->set_temp("marks/庄", 1);
              
              
                return 1;
        }
        else if (ob->query("money_id") && ob->value() < 200)
        {
                command("heng");
                command("say 大爷我不稀罕你这点破东西。");      
                return 1;
        }
        return 0;
}
