// Made by goodtaste
//1999.5.21 
// hongyuntangzhu 

#include <ansi.h>

inherit NPC;
int ask_pk();

void create()
{
        set_name("杨啸天", ({"yang xiaotian" , "yang" ,}));
        set("long",
                "杀手帮清风堂堂主,年轻有为，深得帮主信任\n"
                );
        set("title",YEL"清风堂堂主"NOR);
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiaji", 100);
        set("combat_exp", 1800000);
        set("score", 10000);
        set("chat_chance",10);
        set("chat_msg",({"杨啸天说道：我是帮主的左右臂膀，将来这帮主之位必定是我的\n",}));
 
        set_skill("force", 200);
        set_skill("chuforce", 200);
        set_skill("dodge", 200);
        set_skill("guihun-jian", 200);
        set_skill("liuyun",200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        map_skill("force", "chuforce");
        map_skill("dodge", "liuyun");
        map_skill("parry", "guihun-jian");
        map_skill("blade", "guihun-jian");
        create_family("杀手帮",1,"弟子");
           set("inquiry",([
              "pk" : ( : ask_pk : ),
              "PK" : ( : ask_pk : ),
              "杀手" : ( : ask_pk : ),
                ]));

        setup();

      carry_object(__DIR__"obj/blade")->wield();
      carry_object(__DIR__"obj/cloth")->wear();
}



int ask_pk()
{
        object me=this_player();
        if(me->query_temp("testing")) {say("杨啸天说道：先回答我的问题再说\n");return 1;}
        if(me->query_temp("wen_pass")) {say("杨啸天说道：你不是通过了吗?\n");return 1;}
        if(me->query("age")<15){say("这位"+RANK_D->query_respect(me)+"年纪太小了，不要到这里来\n");return 1;}
 	message("vision","这位"+RANK_D->query_respect(me)+"想做杀手啊？那我可得先考考你\n",me);
        switch(random(10)){
     case 0:
            write("要成为一个出色的杀手，最重要的是什么?\n");me->set_temp("mark/文",1);break;  
     case 1:
            write("如果你接受的任务是要杀我，你会杀我吗?\n");me->set_temp("mark/文",2);break;     
     case 2:
            write("如果对方的经验比你高，你有什么方法可以杀死他\n");me->set_temp("mark/文",3);break;     
     case 3:
            write("你对Pk持的是什么态度?\n");me->set_temp("mark/文",4);break;
     case 4:
            write("这世界上最该死的是谁?\n");me->set_temp("mark/文",5);break;          
     case 5:
            write("青天有月来几时,下一句是什么?\n");me->set_temp("mark/文",6);break;     
     case 6:
            write("天下哪个门派最为强大?\n");me->set_temp("mark/文",7);break;     
     case 7:
            write("天下哪个门派最为可怕?\n");me->set_temp("mark/文",8);break;     
     case 8:
            write("我是谁?\n");me->set_temp("mark/文",9);break;     
     case 9:
            write("伏魔刀和金丝宝甲，你愿意要哪一个?\n");me->set_temp("mark/文",10);break;     
   }
  write("想好了回答(answer)我.\n");
  me->set_temp("testing",1);
  return 1;
}
void init()
{
        
	object me,ob;
        me=this_player();
        ob=this_object();
        add_action("get_answer","answer");
        if(me->query_temp("killer")) 
         {
             ob->kill_ob(me);
             message_vision(RED"得罪了帮主,"+RANK_D->query_rude(me)+"以为你还跑得掉吗?看招!\n" NOR,me);
         }

}


int get_answer(string answer)
{  object me=this_player();
   int riddle,sole;
   if(!me->query_temp("testing")) {say("我不明白你的意思\n");return 1;}
   if(!answer||answer=="") {say("你说的什么啊，胡扯!\n");return 1;} 
   riddle=me->query_temp("mark/文");
   switch(answer)
{
    case "无情":
                sole=1;break;
    case "当然":
                sole=2;break;
    case "哈哈，这可就多了，说了你也不懂!":
                sole=3;if(riddle==sole) say("杨啸天的脸红了红，没再说什么\n");break;
    case "人在江湖,身不由己":
                sole=4;break;
    case "克林顿":
                sole=5;if(riddle==sole) say("杨啸天点点头，'不错，天下兴亡匹夫有责,\n我们虽为杀手，却同样不可忘了这一点\n");break;
    case "我今停杯一问之":
                sole=6;break;
    case "少林":
                sole=7;break;
    case "杀手帮":
                sole=8;break;
    case "不知道":
                sole=9;say("杨啸天说道：很好!\n");break;
    case "金丝甲":
                sole=10;say("完全正确，杀人者第一必须学会自我保护\n");break;
    default:
                say("杨啸天大笑起来：你说的都是些什么啊？就你这样的也想来做杀手？\n
还是回家看孩子去吧!哈哈哈哈.....\n");break;
    }
    if(riddle==sole) {me->set_temp("testing",0);me->set_temp("wen_pass",1);say("杨啸天说道：你通过我的测试了，去见帮主吧!\n");return 1;}
    else {say("我都替你脸红，太差劲了!\n");return 1;}
}
     