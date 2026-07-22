// wujiang.c 武将

inherit NPC;

#include <greeting.h>

void create()
{
        set_name("守城武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set_level(39);
        set("age", random(10) + 30);
        set("str", 25);
        set("long", "他威风凛凛，杀气腾腾，虽然只是个守城门的小官，当年也是打过大仗的。\n");
        set("combat_exp", 80000);
        set("attitude", "peaceful");
        set_skill("unarmed", 370);
        set_skill("force", 370);
        set_skill("dodge", 370);
        set_skill("parry", 370);
        set_skill("spear", 370);
        set_skill("bawang-qiang", 370);
        map_skill("spear","bawang-qiang");
        map_skill("parry","bawang-qiang");
        set_skill("lengquan-force",370);
        map_skill("force","lengquan-force");
        set_skill("yanxing-steps",370);
        map_skill("dodge","yanxing-steps");
        set("force_factor", 15);
        create_family("将军府",4,"");
        delete("title");
       set("chat_chance_combat", 50);
        
       set("chat_msg_combat", ({
                (: perform_action, "spear", "ba" :),
                (: perform_action, "spear", "bugong" :),
                (: perform_action, "spear", "huima" :),                
                (: perform_action, "spear", "juanlian" :),                
       }) );
        
        setup();
        carry_object(0,"spear",random(2))->wield();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"shield",random(2))->wear();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"waist",random(2))->wear();
        carry_object(0,"wrists",random(2))->wear();
        carry_object(0,"neck",random(2))->wear();
        setup();        
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
                return;
        }
        greeting2(this_player());
}

int accept_fight(object me)
{
        message_vision("守城武将对$N把眼一瞪，喝道：呔，大胆，还不退下！\n\n", me);
        return 0;
}

