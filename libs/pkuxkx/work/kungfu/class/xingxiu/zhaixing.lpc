#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void consider();
void create()
{
        set_name("摘星子", ({ "zhaixing zi", "zhaixing" }));
        set("nickname", "星宿派大师兄");
          set("title",HIR "星宿派" NOR + GRN +"邪士" NOR);
		  set("start_room","/d/xingxiu/xxh1");
        set("long",
                "他就是丁春秋的大弟子、星宿派大师兄摘星子。\n"
                "他三十多岁，脸庞瘦削，眼光中透出一丝乖戾之气。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 28);
        set("con", 26);
        set("dex", 26);
        set("step", 3);
        set("max_qi", 700);
        set("max_jing", 700);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 30);
        set("combat_exp", 300000);
        set("score", 40000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: consider :)
        }) );
        set_skill("force", 100);
        set_skill("huagong-dafa", 100);
        set_skill("dodge", 100);
        set_skill("zhaixinggong", 110);
        set_skill("strike", 100);
        set_skill("xingxiu-duzhang", 100);
        set_skill("hand", 100);
       set_skill("zhaixing-shou", 100);
        set_skill("parry", 100);
        set_skill("staff", 100);
//      set_skill("tianshan-zhang", 60);
//      set_skill("literate", 50);
        set_skill("poison", 90);
        map_skill("force", "huagong-dafa");
        map_skill("dodge", "zhaixinggong");
        map_skill("strike", "xingxiu-duzhang");
        map_skill("hand", "zhaixing-shou");
        map_skill("parry", "xingxiu-duzhang");
//      map_skill("staff", "tianshan-zhang");
        prepare_skill("strike", "xingxiu-duzhang");
        set("inquiry",
                ([
                        "秘籍" : (: ask_me :),
                        "天山器法" : (: ask_me :),
                     ]));
        set("book_count",1);
        create_family("星宿派", 2, "弟子");
        setup();
//      carry_object("/clone/weapon/gangzhang")->wield();
}
void attempt_apprentice(object ob)
{       if ((int)ob->query("score") < 500) 
          {
           command("say 你自问对本门尽心了吗？");
          }
        else 
          {
           command("say 好吧，我就收下你了。");
           command("recruit " + ob->query("id"));
          }
}
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
          if (random(2)>=1)
                command("exert qisuck " + target->query("id"));
        else
                command("exert jingsuck " + target->query("id"));
}
string ask_me()
{
        mapping fam;
        object ob;
        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "星宿派")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if (this_player()->query("combat_exp")<3000)
             return RANK_D->query_respect(this_player()) +
            "初来乍到，还不能给你我派秘籍。";
        if (this_player()->query("score") < 100)
            return "你对师门没什么贡献，怎么能让你保管秘籍呢.";
        if (query("book_count") < 1)
                return "你来晚了，我派的秘籍不在此处。";
        add("book_count", -1);
        ob = new("/d/xingxiu/npc/obj/throwing_book");
        ob->move(this_player());
        return "好吧，我派的「天山器法」就给你拿回去好好钻研。";
}
#include "/kungfu/class/xingxiu/kill.h"
#include "/kungfu/class/xingxiu/qingan.h"
          
