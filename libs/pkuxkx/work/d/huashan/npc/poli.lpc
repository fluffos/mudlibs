// popi Zine huashan newbie job
inherit NPC;
void create()
{
        set_name("泼皮", ({ "po pi" }));
        set("nickname", "无赖汉");
        set("long",
"他是一个泼皮，整日靠讹诈华山进香客的钱过活\n");
        set("gender", "男性");
        set("age", 30+random(10));
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 2000);
        set("score", 100);
        set("is_hsblock",1);
        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("sword", 20);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        call_out("dest",900);
        call_out("moving",15);
}

int dest()
{
    destruct(this_object());
    return 1;
}

int moving()
{
    random_move();
    return 1;
}

int start_busy(int busy) 
{return 0;}

int add_busy(int busy) 
{return 0;}

void unconcious()
{
    message_vision("$N看到没有什么便宜好赚，远远逃开了。\n",this_object());
    random_move();
    this_object()->fullme();
    die();
}

void die()
{
    message_vision("$N看到没有什么便宜好赚，远远逃开了。\n",this_object());
    random_move();
    this_object()->fullme();
    return;
}


void init()
{
    object *all=all_inventory(environment(this_object()));
    int i;
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query_temp("hsnewbiejob/xunshan")&&random(2)&&!all[i]->query_temp("hsnewbiejob/xunshan/block"))
        {
            message_vision("$N一把拦住$n：要向从此过，留下买路财！",this_object(),all[i]);
            tell_object(all[i],this_object()->query("name")+"一把拉住了你。\n");
            all[i]->add_busy(1+random(5));
            all[i]->set_temp("hsnewbiejob/xunshan/block",1);
        }
    }
    return;
}

