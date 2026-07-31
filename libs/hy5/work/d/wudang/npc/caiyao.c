// caiyao.c 采药道长
#include <ansi.h>;
inherit NPC;

string ask_me();
int accept_object(object who, object ob);
void destroying(object me, object obj);

void create()
{
        set_name("采药道长", ({ "caiyao daozhang", "caiyao" }));
        set("long", 
                "他是武当山的采药道长。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);

        set("combat_exp", 5000);
        set("score", 1000);

        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("taiji-jian", 20);
        set_skill("taoism", 20);

        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        create_family("武当派", 4, "弟子");
        set("inquiry", ([
                "古道" : (: ask_me :),
        ]));

        set("chat_chance", 7);
        set("chat_msg", ({
"采药道长感慨道:想不到这深山里还有一条如此隐蔽的古道。\n",
"采药道长自我埋怨道:真是大头虾，居然把药锄给弄丢了，哎!还得回去再找一把。\n",
        }) );


        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

int accept_object(object who, object ob)
{
         object me;
         object obzi;
         me=this_player();
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。");
        if ((string)ob->query("id") == "yao chu"){
         command("say 这正是我需要的，为了报答你我就带你到一奇异的地方去吧!\n");
         remove_call_out("destroying");
         call_out("destroying", 1, this_object(), ob);
         command("say 这捆绳子是我采药用的，你也一并那拿去吧，说不定有用!\n");
         obzi=new("/d/wudang/obj/shengzi");
         obzi->move(me);
         me->move("/d/wudang/gudao1");
         return 1;
         }
        return 0;
}

string ask_me()
{
        return "为了发现这古道，我连锄头都丢了，可不能轻易告诉你!\n";
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
