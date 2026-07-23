// yinliting.c殷梨亭

inherit NPC;

int ask_me();

void create()
{
        set_name("殷梨亭", ({ "yin liting", "yin" }));
        set("nickname", "武当六侠");
        set("long", 
                "他就是张三丰的六弟子殷梨亭。\n"
                "长得一表人才，且精于武当剑法，就是生性较腼腆。\n");
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen", 9000);
        set("str", 26);
        set("int", 30);
        set("con", 26);
        set("dex", 28);
        set("unique", 1);
        set("max_qi", 1800);
        set("max_jing", 1000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 50);
        set("combat_exp", 900000);

        set_skill("force", 130);
        set_skill("yinyun-ziqi", 130);
        set_skill("dodge", 130);
        set_skill("tiyunzong", 130);
        set_skill("cuff", 130);
        set_skill("taiji-quan", 130);
        set_skill("parry", 130);
        set_skill("sword", 130);
        set_skill("taiji-jian", 130);
        set_skill("taoism", 100);
        set_skill("literate", 100);

        map_skill("force", "yinyun-ziqi");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");
        prepare_skill("cuff", "taiji-quan");
        create_family("武当派", 2, "弟子");
        set("inquiry", ([
                "纪晓芙" : (: ask_me :),
        ]));

        setup(); 
        carry_object("/d/wudang/obj/white-robe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
void kill_ob(object me)
{
          set("chat_chance_combat", 40);
	  set("chat_msg_combat", ({
	       (: perform_action, "sword.chan" :),
               (: perform_action, "dodge.zong" :),
               (: perform_action, "cuff.zhen" :),
          }));
          ::kill_ob(me);
}
/*
int accept_fight(object me)
{
        if((int)me->query("shen") < 1) {
           command("say 习武之人应志在锄恶济善，"+RANK_D->query_respect(me)+"目露瘴气，有违武学之本？");
           return 0;
        }
        ::fight_ob(me);
         return 1;
}
*/
int ask_me()
{
       object me=this_player();
      if(base_name(environment(this_object())) != query("startroom")) return 0;
        command("blush "+(string)me->query("id"));
        command("say 既然你是纪姑娘的朋友，那就给你行个方便吧 !\n");
        command("open door");
        message_vision("殷梨亭一侧身，把$N让进了小院。\n",me);
	me->move("/d/wudang/houyuan");
        tell_room(environment(me), me->name()
		+ "从北面的林间小径走了过来。\n",({me}));
        command("close door");
        return 1;
}
