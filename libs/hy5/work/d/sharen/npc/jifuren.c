 // waiter.c
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("姬夫人", ({ "ji furen" }) );
        set("gender", "女性" );
        set("age", 45);
//        set("title",RED  "杀人庄主"NOR);
        set("long",
                "一个神秘的黑衣女子，有人说她是庄主夫人，有人说她是庄主妹妹。
但自从十七年前庄里有个客人失踪後，这个庄主夫人就开始变得莫名其妙。\n");
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("reward_npc", 1);
        set("difficulty", 100);
        set("dex",150);
        set("str",150);
        set("per",50);
        set("fle",50);
        set("dur",50);
        set("con",50);
                set("max_qi", 15000);
        set("max_jing", 12000);
        set("neili", 32000);
        set("max_neili", 32000);
        set("jiali", 50);
        set("combat_exp", 9800000);
        set("score", 180000);


        set_skill("dodge",250);
        set_skill("parry",250);        
        set_skill("taiji-quan",250);        
        set_skill("unarmed",250);
        map_skill("unarmed","taiji-quan");

        set("force",3000);
        set("max_neili",3000);
        set("max_mana",10000);
        set("max_atman",10000);
        set("force_factor",30);

        setup();
        carry_object(__DIR__"obj/birdbox");
        carry_object(__DIR__"obj/wine");
        carry_object("/clone/misc/cloth")->wear(); 
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
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
message_vision("$N仔细打量着$n：你不是他。。。你不是他。。。\n",this_object(),ob);
                        break;
                case 1:
message_vision("$N对$n鞠了万福：这是女眷的厢房，客人不方便久留，还是请回吧。\n",this_object(),ob);
                        break;
                case 2:
message_vision("$N看都不看$n一眼，彷佛这个世界一切都是空。\n",this_object(),ob);
                        break;
        }
}
int accept_object(object who, object ob,object obj){
        object me;   
        me=this_player();
    if( ob->name() == GRN"无极八卦玉佩"NOR) {
    	            obj = new(__DIR__"obj/wine");
                message_vision(HIY"$N手里拿着"NOR + ob->name() + HIY"说道：“他……他……，\n是你！是你！你终于回来了，我早为你准备了酒菜，以待今日俞郎。”\n"+"$N将"NOR + obj->name() + HIY"塞入$n手中。\n", 
                            this_object(),this_player() );
                            obj = new(__DIR__"obj/wine");
                            obj->move(this_player());
                        //command("give taoqing-wine to " + me->query("id"));
    } else{
        return notify_fail("姬夫人摇摇头说：“我不要这个。” \n");
    }
        return 1;
} 
