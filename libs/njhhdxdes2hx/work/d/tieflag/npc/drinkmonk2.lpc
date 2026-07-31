// drinkmonk2.c
inherit NPC;
int go_in();
void create()
{
    set_name("酒肉和尚",({"drink monk","monk"}));
    set("long","这是一个僧不僧俗不俗，满头乱发的怪人\n");
    set("gender","男性");
    set("age",42);
    set("int",20);
    set("cor",30);
    set("cps",20);
    set("gin",500);
    set("max_gin",500);
    set("eff_gin",500);
    set("max_kee",500);
    set("eff_kee",500);
    set("kee",500);  
    set("max_sen",500);
    set("sen",500);    
    set("eff_sen",500);
    set("combat_exp",1000000);
    set_skill("force",100);
    set_skill("lotusforce",100);
    set_skill("unarmed",100);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("force",1000);
    set("max_force",1000);
    set("force_factor",100);
    map_skill("force","lotusforce");
    set("attitude", "heroism");
    setup();
    carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    say ("酒肉和尚说道：“她此番逃将出去，乱子就要惹大了。洒家无论如何也要抓她回来。”\n");
    say ("酒肉和尚话声方了，便已飞身钻入地道。\n");
    destruct( this_object());
    return 1;
}