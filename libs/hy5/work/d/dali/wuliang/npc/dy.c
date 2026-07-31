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
        set("long", "这是一个青年男子，披头散发，赤裸着上身，下身只系着一条短裤，露出\n"
                    "了两条大腿，脸孔略尖，眼神似乎有些发狂。\n");
        set("attitude", "peaceful");
        set("str", 12);
        set("per", 29);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);

        set("inquiry", ([
          "段誉" : (: ask_duan1 :),
          "name" : (: ask_duan1 :),
          "获救" : (: ask_duan2 :),
          "救你" : (: ask_duan2 :),
          "救段誉" : (: ask_duan2 :),
          "救你们" : (: ask_duan2 :),
          "搭救" : (: ask_duan2 :),
          "解救" : (: ask_duan2 :),
          "save" : (: ask_duan2 :),
          "段延庆" : "就是他把我关进来的。\n",
          "拜师" : "嗯....，我的师傅是老子、孔子和庄子，他们的学问我还没学全呢。\n",
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
}

string ask_duan1()
{
        object me,ob;
        ob=this_player();
        me=this_object();
          me->set_name("段誉", ({ "duan yu", "duan","yu"}) );
          me->set("title","大理国镇南王世子");
          ob->set_temp("duanyu/answer1",1);
          return "在下便是段誉。";
}

int ask_duan2()
{
        object me,ob,obj,fang;
        int i;
        ob=this_player();
        me=this_object();
        
        
    if(!ob->query_temp("tlbb11"))
{
message_vision("$N我担心我木婉清妹妹，你有她消息了不？。\n", me, ob);
return 1;	
}    
        
    if(!ob->query_temp("tlbb12"))
{
message_vision("$N我担心我钟灵妹妹，你有她消息了不？。\n", me, ob);
return 1;	
} 
        
        if (ob->query_temp("duanyu/answer1") && ob->query("dali/pass")){
        message_vision("$N道：“今日相救无以回报，壮士是学武之人，我身上有卷帛卷，乃昔日\n"
                +"奇遇获得，今日赠于你，略表解救之谢意。”说完，$N从怀里摸出一团物事。\n"
                +"突然，$N大失惊色，“啊哟！怎么会变成这个样子？罢了！罢了！莫非天意？。”\n"
                +"拿去吧，能领会多少就看你的造化了。说完，$N把它交给$n。\n", me, ob);
                obj=new(__DIR__"obj/dodge_book");
                obj->move(ob);
if (!ob->query("dali/meet_dy1"))
{
ob->add("kar",2);
ob->add("per",1);
}
if((int)ob->query("jinyong/book4")==1)
{
 	i = 800+random(800);
	ob->set("jinyong/book4",2);
	ob->add("combat_exp",i+9880);
	ob->add("potential",i*13);
	ob->add("mpgx",10);
	ob->add("expmax",2);



	tell_object (ob,"你赢得了"+chinese_number(i+9880)+"点经验"+
	           chinese_number(i*13)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
 message_vision("$N对$n说道，有空来大理天龙寺找我吧。\n", me, ob);

      	fang = load_object(__DIR__"nan");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
      	fang = load_object(__DIR__"ye");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
      	fang = load_object(__DIR__"yun");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
}

                ob->delete_temp("duanyu/find2");
                ob->delete_temp("duanyu/answer1");
                ob->set("dali/meet_dy1",1);
                ob->start_busy(4);
//                log_file("quest/lbwb",sprintf("%s(%s)从段誉处学到凌波微步于：%s\n",ob->name(1), capitalize(getuid(ob)), ctime(time())));
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
       room = find_object("/d/dali/wuliang/muwu3");
       room->set("exits/down", "/d/dali/wuliang/midao1");
       
       message_vision("$n忽然看见角落里泥土翻飞，有三个身穿贴身紧靠的人从地里钻了出来 \n"
       +"$n仔细一看，原来是大理国的华赫艮、巴天石和范骅。范骅上前向段誉 \n"
       +"鞠了个躬,道：“公子，我们来救你来了。”眼角一瞥，看见了$n，道：\n"
       +"“敢问这位台兄？”，段誉道：“这位台兄也是来救我的，他杀了四大恶人\n"
       +"从前面推开巨石而入。”范、巴、华等人听了又惊又佩，，范骅道：“四。\n"
       +"大恶人党羽众多，恐怕还会有援兵来到，此地不宜久留，还是随我从地道。\n"
       +"赶紧离开吧。”众人点头称是，于是范、巴、华、段誉跳下地道离开了了\n", me, ob);
       destruct(me);
       return;
}

