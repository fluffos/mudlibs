// Jay 3/17/96
#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name("李文秀", ({ "li wenxiu", "li", "wenxiu"}));
        set("gender", "女性");
        set("title", "草原上的天铃鸟");
        set("unique", 1);
        set("age", 18);
        set("long", "
她是白马李三的女儿，从小便生长在这大草原上。因为歌儿唱得好，
被人们称之为草原上的天铃鸟。她容貌娇美，神色中还散发着一股勃勃英气。\n");
        set("attitude", "friendly");
        set("combat_exp", 510000);
        set("shen", 5000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);
        set("max_qi", 1450);
        set("max_jing", 1200);
        set("max_neili", 3050);
        set("jiali", 20);
        set_skill("cuff", 140);
        set_skill("taiji-quan", 140);
        set_skill("xinyuegong", 140);
        set_skill("force", 140);
        set_skill("taiji-shengong", 140);
        set_skill("parry", 140);
        set_skill("hammer", 140);
        set_skill("dodge", 140);
        map_skill("force", "taiji-shengong");
        map_skill("hammer", "xinyuegong");        
        map_skill("dodge", "xinyuegong");
        map_skill("parry", "xinyuegong");
        map_skill("cuff", "taiji-quan");        
        prepare_skill("cuff", "taiji-quan");
        set("inquiry", ([
            "哈萨克人" : "哈萨克人热情好客，最爱喝又香又烈的美酒。\n",
            "计老人" : "计爷爷把我从小养大，他是我唯一的亲人。我们的帐篷就在草原的东北角上。\n",
            "苏普" : "苏普是我的好朋友，他。。。他现在和阿曼在一起。\n",
            "白马李三" : "我爹爹已经死了，被汉人强盗杀死的。\n",
            "金银小剑三娘子" : "我妈妈也死了，和我爹爹一起被害死的。\n",
            "汉人强盗" : "我不知道他们为什么要杀死我爸爸妈妈，他们还要杀死我。\n",
        ]) );
        set("chat_chance", 50);
        set("chat_msg", ({
            "李文秀轻轻地唱了起来：「啊，亲爱的牧羊少年，请问你多大年纪？」\n",
            (: random_move :),  
            "李文秀轻声唱道：「你半夜里在沙漠独行，我和你作伴愿不愿意？」\n", 
            (: random_move :),
            "李文秀接着唱道：「啊，亲爱的你别生气，谁好谁坏一时难知。」\n", 
            (: random_move :),
            "李文秀的歌声又响了起来：「要戈壁沙漠便为花园，只须一对好人聚在一起。」\n",           
        }) );
        setup();
        carry_object(BINGQI_D("chui"))->wield();
        carry_object(ARMOR_D("qun"))->wear();
}

void init()
{
        object ob = this_player();
        
        if(environment(this_object())->query("short")=="黑石围子"){
                set("chat_chance", 0);
                remove_call_out("back");
                call_out("back", 180, this_object());
        }
        
        if(interactive(ob) && !is_fighting() && ob->query_temp("li_meet") == 1
           && environment(this_object())->query("short") == "黑石围子") {
                command("hi "+ (string)ob->query("id"));
                command("say 你怎么这么久才来啊？");
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
        } 
          
        if(interactive(ob) && !is_fighting() && ob->query_temp("li_meet") == 3) {
                command("xixi " + ob->query("id"));
                command("say 怎么样？我没骗你吧？ ");
        }
           
        add_action("do_yes","yes");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;                       
        message_vision("$N拿起手绢又看了看，接着对$n神秘地一笑。\n",this_object(), ob);
        ob->add_temp("li_meet", 1);                
        command("whisper "+ob->query("id")+" 手绢上这地方我知道，你想不想(yes)去看看？");
}

int do_yes()
{
        object me = this_player();
        if(me->query_temp("li_meet") != 2) return 0;
        message_vision(CYN"$N连忙对$n点了点头，答道：麻烦姑娘了。\n"NOR,me, this_object());
        me->set_temp("gc/yes", 1);
        me->set_leader(this_object());
        message_vision("$N决定开始跟随$n一起行动。\n",me, this_object());
        this_object()->set_temp("go", 1);       
        call_out("going", 4, this_object(), me);
        return 1;
}

int desc(object ob)
{
        destruct(ob);
}

void going(object ob, object me)
{
        if(!ob) return;
        if( !me ) ob->return_home();
        
        ob->force_me("xixi " + me->query("id"));
        message_vision("$N和$n一起往大戈壁沙漠走去。\n",me, ob);        
        ob->force_me("go north");
        ob->force_me("go north");
        destruct(ob);
}

int accept_object(object who, object ob)
{
        if ( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。");
        if ( userp(ob)) {
                command("? " + who->query("id"));
                command("say 你干嘛把别人打晕啊？");
                return notify_fail("糟糕，穿邦了！\n");
        }
               
        if ((string)ob->query("id") == "shou juan"){
                command("ah "+(string)who->query("id"));
                command("say 这是我的手绢，你是怎么得到的？\n");
                call_out("desc", 1, ob );
                if(!ob->query("blooded")) who->set_temp("no_quest", 1); 
                set("chat_chance", 0);                              
                remove_call_out("ask_meet");
                call_out("ask_meet", 4, this_object(), who, ob);
                
                return 1;
        } 
               
        command("smile "+ (string)who->query("id"));
        command("say 谢谢你啦，可我不能拿你的东西。");
        return 0;
}

void ask_meet(object me, object who, object ob)
{
        if(interactive(who) && !is_fighting()) {
                if(!who->query_temp("no_quest")){    
                        command("耶，这手绢上的地图。。。");
                        command("say 这样吧，你一会儿去黑石围子等我，我现在要先回家啦。");      
                        who->set_temp("li_meet", 1);
                        message_vision("$N微微一笑，转身离开了。\n",me);
                        tell_room(environment(me), me->query("name")+"急急忙忙地走了过来。\n", ({me})); 
                        me->move("/d/hj/room-ji1");
                        remove_call_out("do_send");
                        call_out("do_send", 60+random(100), me);
                        me->set("chat_chance", 50);
                }
                else{
                        who->delete_temp("no_quest");
                        command("say 谢谢你啦，这是一点小礼物，你就收下吧。");
                        new("/d/hj/obj/hebao")->move(who);
                        message_vision("$N微微一笑，交给$n一个小荷包，接着转身离开了。\n",me, who);
                        me->set("chat_chance", 50);
                }
        }       
        me->set("chat_chance", 50);
}

void back(object me)
{
        command("say 汉人真是不守信用。");      
        message_vision("$N很生气地嘟了嘟嘴，转身离开了。\n",me);
        destruct(me);
        return; 
}

int do_send(object me)
{
        object where;
        
        if(!me) return 0;
        where = environment(me); 
        if(where->query("short") == "黑石围子") return 0;
        else {
                tell_room(environment(me), me->query("name")+"急急忙忙地离开了。\n", ({me}));   
                me->move("/d/hj/hswz");
                tell_room(environment(me), me->query("name")+"急急忙忙地走了过来。\n", ({me})); 
                return 1;
        }
}
