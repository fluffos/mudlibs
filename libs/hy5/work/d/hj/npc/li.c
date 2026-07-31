// Jay 3/17/96
#include <ansi.h>
inherit NPC;
int ask_supu();
int ask_parent();
int ask_gaochang();
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
        set("max_qi", 9050);
        set("max_jing", 9050);
        set("neili", 8250);
        set("max_neili", 8250);
        set("jiali", 20);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 205);
        set_skill("xinyuegong", 210);
        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("parry", 200);
        set_skill("hammer", 200);
        set_skill("dodge", 200);
        map_skill("force", "taiji-shengong");
        map_skill("hammer", "xinyuegong");        
        map_skill("dodge", "xinyuegong");
        map_skill("parry", "xinyuegong");
        map_skill("cuff", "taiji-quan");        
        prepare_skill("cuff", "taiji-quan");
        set("inquiry", ([
             "苏普" : (: ask_supu :),
                "父母" : (: ask_parent :),
            "哈萨克人" : "哈萨克人热情好客，最爱喝又香又烈的美酒。\n",
            "计老人" : "计爷爷把我从小养大，他是我唯一的亲人。我们的帐篷就在草原的东北角上。\n",
            "白马李三" : "我爹爹已经死了，被汉人强盗杀死的。\n",
            "金银小剑三娘子" : "我妈妈也死了，和我爹爹一起被害死的。\n",
            "汉人强盗" : "我不知道他们为什么要杀死我爸爸妈妈，他们还要杀死我。\n",
        ]) );
        set("chat_chance", 10);
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
        carry_object(__DIR__"obj/chui")->wield();
        carry_object(__DIR__"obj/qun")->wear();
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
   me->set_leader(this_object());
   message_vision("$N决定开始跟随$n一起行动。\n",me, this_object());
   this_object()->set_temp("go", 1);	
   call_out("going", 4, this_object(), me);
   return 1;
}

void going(object ob, object me)
{
   ob->force_me("xixi " + me->query("id"));
   message_vision("$N和$n一起往大戈壁沙漠走去。\n",me, ob);	
   ob->force_me("go north");
   ob->force_me("go north");
   destruct(ob);
}

int accept_object(object who, object ob)
{
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。");
        if (userp(ob)) {
               command("? " + who->query("id"));
               command("say 你干嘛把别人打晕啊？");
               return notify_fail("糟糕，穿邦了！\n");
               }
        if ((string)ob->query("id") == "shou juan"){

        if ((int)who->query("jinyong/book6")==1 && !(int)who->query_temp("killltl3")) {
               command("? " + who->query("id"));
               command("say 先帮我把陈达海这恶贼先杀了吧");
               return notify_fail("看来李文秀 正在担心坏人的事！\n");
               }

        if ((int)who->query("jinyong/book6")==1 && !(int)who->query_temp("killltl2")) {
               command("? " + who->query("id"));
               command("say 先帮我把丁同这恶贼先杀了吧");
               return notify_fail("看来李文秀 正在担心坏人的事！\n");
               }

                command("ah "+(string)who->query("id"));
                command("say 这是我的手绢，你是怎么得到的？\n");
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
int i;
    if(interactive(who) && !is_fighting()) {
      if(!who->query_temp("no_quest")){    
        command("耶，这手绢上的地图。。。");
        command("say 这样吧，你一会儿去黑石围子等我，我现在要先回家啦。");      


        if(who->query("jinyong/book6")==1)
{
	i = 300+random(800);
	who->set("jinyong/book6",2);
	who->add("combat_exp",i+9880);
	who->add("potential",i*14);
	who->add("mpgx",10);
	who->add("expmax",2);
 message_vision(CYN"$N对$n说到，有一个叫华辉的坏人藏在那个地方，要小心他。\n"NOR, me, who);
	tell_object (who,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*14)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
        who->save();
 }

        who->set_temp("li_meet", 1);
        message_vision("$N微微一笑，转身离开了。\n",me);
        tell_room(environment(me), me->query("name")+"急急忙忙地走了过来。\n", ({me}));	
        me->move("/d/hj/room-ji1");
        remove_call_out("do_send");
        call_out("do_send", 60+random(100), me);
        me->set("chat_chance", 50);
        return;
        }
      else{
        who->delete_temp("no_quest");
        command("say 谢谢你啦，这是一点小礼物，你就收下吧。");
        new("/d/hj/obj/hebao")->move(who);
        message_vision("$N微微一笑，交给$n一个小荷包，接着转身离开了。\n",me, who);
        destruct(ob);
        me->set("chat_chance", 50);
        return;
        }
    }
    destruct(ob);
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
    where = environment(me); 
    if(where->query("short") == "黑石围子") return 0;
    else {
       tell_room(environment(me), me->query("name")+"急急忙忙地离开了。\n", ({me}));	
       me->move("/d/hj/hswz");
       tell_room(environment(me), me->query("name")+"急急忙忙地走了过来。\n", ({me}));	
       return 1;
       }
}


int ask_supu()
{
 say("李文秀黯然的说：他是我儿时的伙伴，他现在和阿曼在一起了，\n");
 this_player()->set_temp("marks/李1", 1);
 return 1;
}

int ask_parent()
{
object map;
object me;
me=this_player(); 

 say("李文秀说道：父母之仇，不共戴天。\n");
 return 1;

}
