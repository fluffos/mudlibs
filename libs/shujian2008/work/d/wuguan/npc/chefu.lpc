//chefu.c 车夫

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("车夫", ({ "che fu","chefu","fu", "man" }));
        set("title", "襄阳武馆随从");
        set("gender", "男性");       
        set("long", "穿着破旧的粗布衣裳，苍白的脸，看来非但疲倦，而且憔悴衰老。\n");
        set("combat_exp", 5000);
        set("shen_type", 1);         
        set("age", 50);

        set_skill("force", 30);
        set_skill("strike", 30); 
	 
        set("inquiry", 
                ([
                        "万震山" : "他老人家是襄阳武馆的主人啊。", 
                  ]));

        setup();

        carry_object(ARMOR_D("cloth"))->wear();
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


void greeting(object ob)
{      
       command("hi "+ob->query("id"));  
       command("say 这位" + RANK_D->query_respect(ob) +"恭喜，恭喜！武艺有成，能到江湖上去闯荡一翻了，哈哈\n"+
               "哈！现在江湖上门派众多，你想去哪里呢？先看看牌子，然后再告诉我你要去哪\n"+
               "里吧"HIR"（qu ***）"CYN"。如果想去襄阳往南走就到了。"NOR);       
}                               
 