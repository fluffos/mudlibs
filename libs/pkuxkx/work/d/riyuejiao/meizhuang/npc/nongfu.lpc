// nongfu.c     农夫
// by bing

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set_name("农夫", ({ "nong fu", "fu" }) );
        set("gender", "男性" );
        set("shen_type", -1);
        set("age", 40);
        set("str", 25);
        set("cor", 25);
        set("cps", 25);
        set("int", 25);
         set("count", 1);
        set("long",
                "这是个穿着朴素，一脸憨厚的农夫，正在修理农具。\n" );

        set("combat_exp", 20000);
        set("attitude", "peaceful");
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "农夫忽然使出一记妙招，仿佛是一招「粉石碎玉」，但中途连忙缩手，换以平庸招数。\n",
        }) );

        set("inquiry", ([
                "华山派"   : (: ask_me :),
        ]) );

        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 20);
        set_skill("parry", 100);
        set_skill("huashan-jianfa",100);
        set_skill("huashan-neigong",100);
        set_skill("huashan-shenfa",100);
        setup();
        
        carry_object(__DIR__"obj/cloth")->wear();
}

string ask_me(object who)
{
        object me = this_player();
        object ob;

        if ( this_object()->query("asked") )
        {
                message_vision("农夫狞笑道：「我身上就一张地图，别做梦了你！」\n",me);
                return "哼！\n";
        }
          if (this_object()->query("count") < 1)
             return "我…不知道。\n";
        if( (random(10) < 5) || is_fighting() )
                return "我…不知道。\n";
        message("vision",
                HIY "农夫惊问道：「你，你，你怎么知道的？今天可不能留你的活口啦！」\n" NOR,
                environment(), who );

          set("count",0);
        set("combat_exp", 100000);
        map_skill("dodge","huashan-shenfa");
        map_skill("parry","huashan-jianfa");
        map_skill("sword","huashan-jianfa");
        ob = new(__DIR__"obj/changjian");
        ob->move(who);
        ob = new(__DIR__"obj/ditu");
        ob->move(who);
        this_object()->set("asked");
        command("wield jian");
        command("kill " + me->query("id"));
        return "纳命来吧！\n";
}

