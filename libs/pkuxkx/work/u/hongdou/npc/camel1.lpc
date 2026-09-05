// camel.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;
//inherit F_UNIQUE;
int ask_me();
int ask_me1();

void create()
{
        seteuid(getuid());
        set_name("毫毛", ({ "hao mao","mao mao","mao","camel" }) );
        set("title", MAG "江湖破烂王" NOR);
        set("gender", "男性" );
        set("age", 28);
        set("long", "一个慈眉善目、道貌岸然的家伙，身上穿得破烂不堪，到处捡别人扔掉的垃圾。\n");
        set("attitude", "peaceful");
        set("str", 25);
        set("con", 25);
        set("int", 25);
        set("dex", 25);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 1000);
        set("shen_type", 0);
        set("startroom","/d/city/guangchang");
        set("thief", 0);
	set("no_steal",1);
	set("no_fight",1);
        set_max_encumbrance(100000000);
        set("combat_exp", 0);
          set("chat_chance", 20);
	set("inquiry", ([
            "name" : "我就是大名鼎鼎的毫毛呀，连我都不知道，你别在江湖混了。",
	    "姓名" : "我就是大名鼎鼎的毫毛呀，连我都不知道，你别在江湖混了。",
            "问题" : (: ask_me :),
	    "帮助" : (: ask_me1 :),
	]) );
        set("chat_msg", ({
        "毫毛说道: “当年老子武功天下第一，谁敢跟我叫板，算他倒霉。哼！！！”\n",
        "毫毛懒洋洋地打了个哈欠。\n",
        "毫毛看看四周没人，拉开裤子在墙边撒了泡尿！！！ \n",
		(: random_move :),
	"毫毛高声喊道：“相当初，大爷我吃馆子都不要钱，何况你这几个烂西瓜。”\n",
	"毫毛道：“江湖险恶，豺狼当道，行走江湖没有一技之长别想活的舒坦。”\n",
		(: random_move :),
	"毫毛钻进路边的垃圾堆里,自言自语道：“这里一定有值钱的东西。”\n",
	"毫毛撇着嘴道：“象我这样上晓天文，下通地理，琴棋书画样样精通的人，世上已经没有了。”\n",
	"毫毛刚刚捡到一个破铁锅，欣喜地叫着：“发财了，发财了!!!”\n",
		(: random_move :),
	"毫毛放了个响屁，并且深深吸了几口气赞美道：“好香，好香！！！”\n",
                (: random_move :),
		(: random_move :),
	"毫毛啃着变了味的鸡腿唱道：“啦啦啦！啦啦啦！我是快乐的美食家......”\n",
		(: random_move :),
        }) );
        setup();
        carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/food/jitui");
	carry_object("/clone/food/jiudai");

}
void init()
{
        ::init();
	command("get all");
	command("get all from corpse");
        add_action("do_answer","answer");
}

int ask_me1()
{
	object *inv;
        object who=this_player();
	object me=this_object();
	object ob;

	if ( who->query_temp("marks/help"))
	  {
		say("毫毛不耐烦地道：“刚施舍给你东西，怎么还要？老子什么都没有了！滚蛋！！！”\n");
		return 1;
	   }
        
           inv = all_inventory(me);
	   
	   if ( !sizeof(inv) )
	      {	 say("本来想帮帮你，可我也是个穷光蛋。等我捡到好东西再分给你！\n");
		 return 1;
	      }	
	   ob = inv[random(sizeof(inv))];
	   ob->move(who);
	   say("毫毛拍拍"+ this_player()->name() +"的头道：“可怜的孩子，给你点东西，快走吧。”\n");
	   this_player()->set_temp("marks/help",1);
           return 1;
}
int ask_me()
{
	object who=this_player();
	
	if ( who->query_temp("marks/问"))
	  {
		say("毫毛不耐烦地道：“刚问完还问，你烦不烦呀？”\n");
		return 1;
	   }
	if (who->query_temp("marks/题"))
	  {
		say("毫毛道：“你先回答我上个问题再说！”\n");
		return 1;
	  }

        write("毫毛嘿嘿奸笑道：“看来你福缘深厚,给你出道题。”\n");
                 switch(random(0)) {
                   case 0:
                       write("金庸的真名叫什么？\n");
                       who->set_temp("marks/题", 1);
                       break;
                   
                  }
                  write("想好了回答 (answer) 我。记住，不可泄露谜语或谜底。\n");
                  message("vision", "毫毛对着"+who->name()+"嘀咕了几句话。\n",
                          environment(who), ({who}) );
                  return 1;
}

int do_answer(string arg)
{
        object me;
        int soln,riddle,jy,qn;
        me = this_player();
        riddle = this_player()->query_temp("marks/题");

        if (!riddle) {
           write("我又不是你师傅，你用不着回答我。\n");
           return 1;
        }

        if( !arg || arg=="" ) {
           write("想好谜底再回答。\n");
           return 1;
        }
        message("vision", me->name() + "把嘴凑到毫毛的耳边嘀嘀咕咕。\n",
                 environment(me), ({me}) );

        switch (arg) {
          case "查良镛": soln=1; break;
          case "灵灵" : soln=2; break;
          case "江百胜" : soln=3; break;
          
          default :
              say("毫毛大笑起来，说道：你说什么呀，牛头不对马嘴。\n"
                  + me->name() + "的脸被臊得通红。\n");
              return 1;
        }

        if (riddle==soln) {
          this_player()->set_temp("marks/题", 0);
          say ("毫毛对" + me->name() + "竖起大姆指：居然让你猜着了。\n");
          this_player()->set("combat_exp",this_player()->query("combat_exp")+0);
          write ("你的经验增加了！\n");
	  this_player()->set_temp("marks/问",1);
        }
        else
          write ("谁把谜底告诉你的? 不对!!\n");
        return 1;
} 

int heal_up()
{
        return ::heal_up() + 1;
}
