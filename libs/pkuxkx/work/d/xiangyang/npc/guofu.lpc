#include <ansi.h>
inherit NPC;
string ask_for_ma();  
string ask_for_xiaoma();  
string ask_diao();  
string ask_guo();
int destroying(object);
void create()  
{       set_name("郭芙", ({ "guo fu","guo","fu"}));
        set("gender", "女性");
        set("title",RED"郭靖之女"NOR);
        set("age", 25);
        set("str", 17);
        set("dex", 16);
        set("long", "她是郭靖的女儿,从小娇生惯,养非常任性。\n");
        set("combat_exp", 100000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set_skill("unarmed", 130);
        set_skill("sword", 160);
        set_skill("dodge", 130);
        set_skill("parry", 120);
        set_skill("force", 130);
        set("neili", 400); 
        set("max_qi", 600); 
        set("qi", 600); 
        set("max_neili", 400);
       
        set("inquiry",([  
              "汗血宝马"  : (: ask_for_ma :),
                "小红马"  : (: ask_for_xiaoma :),
                  "郭靖"  : (: ask_guo :),
                  "白雕"  : (: ask_diao :),
                  "雕儿"  : (: ask_diao :),
          ]));


        set("chat_chance", 10);
        set("chat_msg", ({
       "爹爹每天忙啊忙的,也不陪我玩,真没劲.\n",
       "爹爹说他从前有两只白雕,后来死了,要是我也有一双多好啊.\n"
                }) );
        setup();
        carry_object(__DIR__"obj/changjian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}

string ask_diao()
{
        object me;
        me = this_player();
        if (!me->query_temp("马夫") ||
          !me->query_temp("红马") )
          return "听爹爹说白雕可好玩了,能骑两个人呢.\n";
        
        command ("say 我们家从前还有两只呢,后来死了.\n听人说城西有座高峰,不知道那上面有没有.\n你要是能帮我抓来,我就把红马送给你!");
         command ("xixi");
        me->delete_temp("红马");
        me->delete_temp("马夫");
        me->set_temp("白雕", 1);  
          return "白雕好利害的,你要小心啦.";
       
}
string ask_guo()
{    
        return " 那就是我爹爹呀,他现在也没空理我,真没劲.";
        command("sigh");
}
string ask_for_ma()
{       object me=this_player();
        return "你说的就是我家的小红吗吧,它可乖了!";
        me->set_temp("红马", 1);
        command("sigh");
}
string ask_for_xiaoma()
{       object me;
        me=this_player();
        me->set_temp("红马", 1);  
        return "你想借?不行的,明天我还要骑它去草原玩呢.";
}
int accept_object(object me, object ob)
{

        if (ob->query("id")=="diao chu")
     {
        call_out("destroying",1,ob);
        if (!me->query_temp("白雕") ) {
               command("say 谢谢你啦,不过这是你自己送我的,我可没求你呀.");
                return 1;
        }
        else {
                call_out("destroying",1,ob);
                command("wa " + me->query("id"));
               me->set_temp("取马",1);
               me->delete_temp("白雕"); 
               me->delete_temp("上峰"); 
                command("say 谢谢你啦,你去马房拿马吧,他们不会拦你的");
                return 1;
        }
    }
}
int destroying(object ob)
{
        destruct(ob);
        return 1;
}
