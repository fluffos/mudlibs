// duanyu.c 段誉
// COOL@SJ,990827
#include <ansi.h>

inherit NPC;
string ask_duan1();
int ask_duan2();
void create()
{
        set_name("青年男子", ({"qingnian nanzi", "nanzi", "man"}));
        set("gender", "男性");
        set("age", 20);
	set("long", 
		"他是一个身穿青衫的年轻男子。脸孔略尖，自有一股书生的呆气。\n");
        set("attitude", "peaceful");
        set("str", 12);
        set("per", 29);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);

        set("inquiry", ([
          "相救" : (: ask_duan2 :),
           ]));

        set("jing", 10000);
        set("max_jing", 10000);
        set("jingli", 10000);
        set("max_jingli", 10000);
        set("qi", 20000);
        set("max_qi", 20000);
        set("neili", 3000);
        set("max_neili", 30000);
        set("jiali",50);
        
        set("combat_exp", 150000);
                 
        set_skill("force", 100);                
        set_skill("beiming-shengong", 120);     
        set_skill("dodge", 100);                
        set_skill("lingboweibu", 120);         
        set_skill("parry", 100);
        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingbo-weibu");
        setup();        
	carry_object("/clone/misc/cloth")->wear();        
}



int ask_duan2()
{
        object me,ob,obj,fang;
        int i;
        ob=this_player();
        me=this_object();
           if(!ob->query_temp("killtlbb6"))
{
message_vision("$N你见过慕容公子了吗？。\n", me, ob);
return 1;	
}     
       if(!ob->query_temp("killtlbb5") && !query("iskillok"))
      {
      message_vision("突然从附近跳出一个和尚 说道： 把六脉神剑谱交出来吧!\n",this_object(),ob);	
      	fang = load_object(__DIR__"jiumozhi");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 1;
      }	
       
        
    if(!ob->query_temp("killtlbb5"))
{
message_vision("$N你帮我对付了大轮明王了没有？。\n", me, ob);
return 1;	
}    

    

        
        if (ob->query_temp("killtlbb5") && ob->query("jinyong/book4")==3){
        message_vision("$N道：“今日相救无以回报，以后定当报答。\n", me, ob);
if((int)ob->query("jinyong/book4")==3)
{
 	i = 900+random(1200);
	ob->set("jinyong/book4",4);
	ob->add("combat_exp",i+9880);
	ob->add("potential",i*16);
	ob->add("mpgx",10);
	ob->add("expmax",2);


 message_vision("$N道：“我去岳阳看我大哥，有空你也来看看吧。\n", me, ob);
	tell_object (ob,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*16)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
}




                ob->start_busy(4);
                remove_call_out("dest");
                call_out("dest",3,me,ob);
                return 1;
        }
        else {
           message_vision("$N似乎不懂你的意思，道：你要救谁，莫不是又来骗我的？。\n", me, ob);
        }
        return 1;
}

void dest(object me,object ob)
{      
       object room;

       destruct(me);
       return;
}

