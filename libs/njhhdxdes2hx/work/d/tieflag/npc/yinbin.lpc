// yinbin.c
inherit NPC;
void create()
{
    set_name("阴宾",({"yin bin","yin","bin"}));
    set("long","她面上蒙着轻红罗纱，隐约间露出面容轮廓，当真美得惊人，宛如烟笼芍药，雾里看花\n");
    set("gender","女性");
    set("age",42);
    set("int",20);
    set("per",35);
    set("cps",20);
    set("gin",200);
    set("max_gin",200);
    set("eff_gin",200);
    set("max_kee",400);
    set("eff_kee",400);
    set("kee",400);  
    set("max_sen",50);
    set("sen",50);    
    set("eff_sen",500);
    set("combat_exp",10000);
    set_skill("force",50);
    set_skill("nine-moon-force",20);
    set_skill("claw",70);
    set_skill("nine-moon-claw",40);
    set_skill("nine-moon-steps",40);
    set_skill("parry",50);
    set_skill("dodge",50);
    set("force",100);
    set("max_force",100);
    set("force_factor",1);
    map_skill("force","nine-moon-force");
    prepare_skill("claw","nine-moon-claw");
    map_skill("claw","nine-moon-claw");
    map_skill("dodge","nine-moon-steps");
    set("attitude", "friendly");
    set("chat_chance",5);     
    set("chat_msg",({
          "阴宾眼波四转，笑道：“他只当我自地道走了，可我偏偏留在这儿。”\n",
          "阴宾笑道：“你可要我掀开面纱让你看看么？”\n",
          }) );

    setup();
    carry_object(__DIR__"obj/redcloth")->wear();
    carry_object(__DIR__"obj/redjin")->wear();
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
    command("lovelook");
    call_out("leave",10,me);
    return 1;
} 
void leave(object me)
{
    if (living(this_object()) && environment(me) == environment())
    {
      command("say 我也该走了，外面有人接我呢！");
      message_vision("$N回眸一笑，走了出去。\n",this_object());
      me->set_temp("mark/阴宾",1);
      destruct(this_object());
    }
    else
      remove_call_out("leave");
}
