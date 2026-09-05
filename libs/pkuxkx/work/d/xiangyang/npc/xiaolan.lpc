#include <ansi.h>
string ask_for_li();  
inherit NPC;
void create()  
{	set_name("小兰", ({ "xiao lan","lan"}));
	set("gender", "女性");
        set("age", 20);
	set("str", 17);
	set("dex", 16);
	set("start_room","/d/xiangyang/liwu");
	set("long", "她是老丈的女儿，今年刚满20，还没找婆家呢。\n");
	set("combat_exp", 1000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 20);
	set_skill("force", 30);
	set("max_qi", 200); 
	set("qi", 200);  
        set("inquiry",([  
              "李大哥"  : (: ask_for_li :),
              
          ]));


        set("chat_chance", 10);
        set("chat_msg", ({
       "小兰对着铜镜喃喃地说：我知道李大哥是喜欢我的，可是他为什么不来提亲呢？\n"
                }) );
        setup();

}


int accept_object(object me, object ob)
{

         if (ob->query("id")=="dahong tubu" || ob->query("id")=="qianlv shabu" || ob->query("id")=="tianlan jinduan" || ob->query("id")=="fenhong sichou")
     {
        if (!me->query_temp("小兰") ) {
               command("say 咦？我又不认识你，怎么能收你的东西呢？");
                ob = new(__DIR__"obj/buliao1");
                ob->move(this_player());    
               message_vision("小兰把布料又给了$N。\n", me);
                return 1;
        }
        else { 
               command("blush");
               command("xixi");
               me->set_temp("兰1",1);
               me->delete_temp("小兰"); 
                command("say 谢谢你啦,我还以为他不会理我呢。");
                return 1;
        }
    }
}
string ask_for_li()
{    
        return "李大哥就住在对门，你问他干什么呀.";
        command("blush");
}
