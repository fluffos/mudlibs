// /d/changbai/npc/yan1.c

#include <ansi.h>

inherit NPC;
int ask_gulan(object me);

void create()
{
        set_name("阎世魁", ({ "yan shikui", "yan" }));
        set("nickname", HIY"关东五魔"NOR);
        set("long",
"他就是关外六魔中的五魔阎世魁，据说目前为镖局办事，好象要运送个宝物。\n");
        set("gender", "男性");
        set("age", 39);
        set("attitude", "heroism");
        set("shen_type", -1);

        set("str", 35);
        set("int", 20);
        set("con", 30);
        set("dex", 20);

        set("max_qi", 900);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 30);
        set("combat_exp", 400000);
        set("score", 20000);
        set("book_count",1);
        
        set_skill("force", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("cuff", 120);
        set_skill("club", 150);
/*
        set_skill("wuxingbu", 100);
        set_skill("wuxing-quan", 100);
        set_skill("weituo-gun", 150);
        set_skill("ding-force", 100);

        map_skill("force", "ding-force");
        map_skill("dodge", "wuxingbu");
        map_skill("parry", "weituo-gun");
        map_skill("club", "weituo-gun");
        map_skill("cuff", "wuxing-quan");

        prepare_skill("cuff", "wuxing-quan");
*/
        set("inquiry", ([
                "关东六魔" : "打听我们有什么企图不成？\n",
                "红花会" : "红花？还绿帽呢，要不要我给你戴一顶，哈哈。\n",
                "古兰经" : (: ask_gulan :),
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();

}

int ask_gulan(object me)
{       
        int i;
        object *obj;
        me = this_player();
        if ((int)this_player()->query_temp("sj3"))
        	
            {   
            	  command("say 再说废话也没用，去死吧！\n");
        kill_ob(this_player());
                return 1;
            }
            
        if ((int)this_player()->query_temp("sj2"))
            {       
               message("vision",HIY"阎世魁目露凶光，厉声喝道：“他奶奶的，到底追来了，书在这，来吧！”\n"NOR,environment(me),me);
               me->delete_temp("sj2");
               me->set_temp("sj3",1);
               if (query("book_count")==1)
               carry_object("/d/reborn/jinyong/obj/gljing");
               set("book_count",0);
               
               obj = all_inventory(environment());
               for(i=sizeof(obj)-1; i>=0; i--) 
                 {
                    if( !userp(obj[i]) ) continue;
                    kill_ob(obj[i]);
                    obj[i]->fight(this_object());
                 }
               command("say 想拿书，我直接送你上天堂。\n");
               return 1;
             }
             
        say("阎世魁警惕的说道：古兰经是吃的还是喝的，我没听过呀！\n");
        return 1;
}

