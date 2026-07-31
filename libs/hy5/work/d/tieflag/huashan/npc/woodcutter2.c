 // woodcutter.c
inherit NPC;
int milin();
void create()
{
        set_name("樵夫", ({"woodcutter"}) );
        set("gender", "男性" );
        set("age", 36);
        set("agi",30);
        set("per", 10);
        set("str",100);
        set("long",
                "一个年轻的樵夫，由于常年的砍柴，使得他的一双手布满了老茧。\n"
                );
        set("max_jing", 1000);
        set("max_qi", 1000);
        set("max_sen", 1000);
        set("combat_exp", 20000);
                set("inquiry", ([
                        "milin" : (: milin :),
                        "树林" : (: milin :),
                        "密林" : (: milin :),
                ]));
        set_skill("move", 50);
        set_skill("parry", 50);
            set_skill("dodge", 60);
        set_skill("axe",50);
            setup();
            carry_object(__DIR__"obj/woodaxe")->wield();
            carry_object("/clone/misc/cloth")->wear();  
} 
int milin(){
        object me;
        me = this_player();
        message_vision("$N抬头看了$n一眼道：“那片密林连我也走不出，每次都转回到这里，我看也只有
会飞的鸟才知道密林后面是什么。\n", this_object(), me);
        return 1;
}    
