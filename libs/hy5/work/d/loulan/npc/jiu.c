#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("韩伶", ({ "han ling","han" }) );
        set("gender", "男性" );
        set("long",
"这人五十上下，蜡黄脸色。细眉小眼，留着几根山羊胡子，穿着半新不旧\n的狐皮袄；乃快活王手下四使之酒使，专为其搜寻天下美酒。\n"
                );
        create_family("快活林", 1, "酒使");
        set("attitude", "peaceful");
        set("class","bat");
        set("reward_npc", 1);
        set("difficulty", 2);
        
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                (:perform_action,"dodge.huanyinqianchong":),
        }));
        
        set("age", 65);
        set("cps", 40);
        set("int", 10);
        set("per", 4);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 1200000);
        set("force", 1000);
        set("max_force", 1000);
        set_temp("apply/armor",100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "韩伶捋了捋花白的山羊胡子，长长叹了口气。\n",
                "韩伶眉头微皱，叹气道：若在王爷吉日之前不能配出这【孔雀开屏】，真
不知该如何交待？",
                }) );
        set("inquiry", ([
                "孔雀开屏" : "这白宫主真是。。。。。。唉，说这【孔雀开屏】酒需要天下七
大名酒调配而成，什么『古城烧』，『狼酒』，『竹叶青』，『女儿红』，
『高梁酒』，『剑南春』，『董酒』这叫我一时去哪找啊？ \n",
                "wine" : "这白宫主真是。。。。。。唉，说这【孔雀开屏】酒需要天下七
大名酒调配而成，什么『古城烧』，『狼酒』，『竹叶青』，『女儿红』，
『高梁酒』，『剑南春』，『董酒』这叫我一时去哪找啊？ \n",
        ]) );
        
        set_skill("unarmed", 140);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("move", 120);
        set_skill("meng-steps", 120);
        set_skill("nine-moon-claw", 120);
        map_skill("dodge", "meng-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("blade", "bat-blade");
        map_skill("parry", "bat-blade");
                
        setup(); 
        carry_object(__DIR__"obj/foxcloth")->wear();
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")==HIC"【孔雀开屏】"NOR && ob->query("liquid/name")=="孔雀开屏")
        {
                if (ob->query("liquid/remaining") > 95)
                {
                        message_vision("$N花白的眉头不禁一挑，笑道：不错，不错，真是谢谢$n,王爷吉日\n即到，贵客不妨里边走走。\n",this_object(),this_player());
                        who->set_temp("marks/give_han_wine",1);
                }
                else
                {
                        message_vision("$N花白的眉头紧锁，苦笑道：不错，不错，这就是【孔雀开屏】，可是\n都快被喝光了，我怎么交差呢？\n",this_object());
                }
                return 1;
        }
        else
        {
                message_vision("$N的头摇得像拨浪鼓一般，道：老朽什么都不缺，就是缺那个什么【孔雀开屏】。\n",this_object());     
                return 0;
        }
}     
