#include <ansi.h>
inherit NPC;
void create()
{
        set_name(BLK"疯子"NOR,({"crazy man","crazy"}));
        set("long",@LONG
他看上去四十来岁，乱发披肩，你难以看清楚他的脸孔。\n
他似乎有一点失忆了，说起话来糊理糊涂.\n
他衣衫褴褛，就像丐帮的乞丐,好像几年没洗过澡了.\n
LONG);
        set("age",43);
        set("gender","男性");
        set("nickname",RED"鬼手"NOR);
        set("str",30);
        set("int",19);
        set("con",29);
        set("dex",30);
        set("jiali",45);
        set("combat_exp",50000+random(3000));
        set("max_qi",600);
        set("qi",600);
        set("max_neili",500);
        set("neili",500);
        set_skill("dodge",70);
        set_skill("force",70);
        set_skill("parry",70);
        set_skill("unarmed",70);
        set_skill("sword",70);
        set_skill("yuxiao-jian",70);
        map_skill("sword","yuxiao-jian");
        set("chat_chance_combat",100);
        set("shen_type",-1);
set("score",1000);
setup();
        set("chat_chance",1);
        set("chat_msg",({"疯子道：“我不是人，你呢？”\n",
        "疯子道：“我是人，你不是人。”\n",
        }));
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void init()
{
        object ob,me;
        ob=this_player();
        me=this_object();
        if (!me) return;
        if(is_fighting()|| !ob || environment(ob) != environment()||environment(ob)->query("no_fight"))
                return;
        if(!living(me))
                return; 
        
                command("say 我要杀死你这个不是人的家伙!\n");
                me->set_leader(ob);
                me->kill_ob(ob);
                return;
        
}
