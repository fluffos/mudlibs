// npc: /d/xingxiu/npc/afanti.c
// Vast 2003.2

inherit NPC;
#include <ansi.h>;

int TLINES=45;//谜语的总条数,修改riddle文件时，注意同时修改此数值
string filename=__DIR__"riddle/riddle";//谜语文件存放相对路径
string new_riddle(object who);
string ank;//谜底

void create()
{
        set_name("阿凡提", ({ "afanti" }) );
        set("gender", "男性" );
        set("age", 48);
        set("long", 
            "他头上包着头巾，长着向上翘的八字胡，最喜欢捉弄巴依、帮助穷人。他常"
            "给别人出谜语。\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 30);
        set_skill("dodge", 25);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2500);

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "我就是纳苏尔的阿凡提。",
            "here" : "这里可真是个好地方。",
            "纳苏尔" : "是我出生的地方。",
            "谜语" : "你帮我找到小毛驴，我就给你出谜语。",
            "巴依" : "他把我关在这里，有吃有喝，我就不走了。巴依是个坏蛋，愿胡大惩罚他。",
            "毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "小毛驴" : "我的小毛驴在我到沙漠里骗巴依种金子时走丢了。",
            "卷帘格" : "卷帘格指谜底各字顺序颠倒过来和谜面相扣。",
            "粉底格" : "粉底格指谜底末一字作谐音读。如：“年终结帐”（打一食物）---大蒜（大算）。",
            "胡大" : "就是真主。又名安拉或阿拉。",
            "真主" : "真主至大，万物非主，唯有真主。穆罕默德是真主的使者。",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
             "阿凡提叹了口气：嗨，可惜我的驴。\n",
        }) );
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/dongbula");
}

void init()
{
        ::init();
        add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{
     if ( userp(ob) ) return 0;
    this_object()->start_busy(3);
     if((string)ob->query("name")=="小毛驴" && (string)ob->query("id")=="donkey") {
           remove_call_out("destroying");
           if( who->query_temp("marks/谜") ) {
                 write("阿凡提笑了笑，说：你先把上个谜猜出来再说。\n");
                 return 0;
           }
           else {
                 write("阿凡提笑得嘴都合不上了，说：多谢这位" + 
                       RANK_D->query_respect(who) +
                       "的帮助，咱们猜个谜语吧：\n");
                  ank = new_riddle(who);//返回谜底
                  who -> set_temp("riddle/answer",ank);
                  write("想好了回答 (answer) 我。记住，不可泄露谜语或谜底。\n");
                  message("vision", "阿凡提对着"+who->name()+"嘀咕了几句话。\n",
                          environment(who), ({who}) );
                  remove_call_out("destroying");
                  call_out("destroying", 1, this_object(), ob);
                  return 1;

            }
	 }
return 0;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

int do_answer(string arg)
{
        object me,gold;
        int riddle,t;
        me = this_player();
        riddle = this_player()->query_temp("marks/谜");

        if (!riddle) {
           write("我又不是你师傅，你用不着回答我。\n");
           return 1;
        }

        if( !arg || arg=="" ) {
           write("想好谜底再回答。\n");
           return 1;
        }
        message("vision", me->name() + "把嘴凑到阿凡提的耳边嘀嘀咕咕。\n",
                 environment(me), ({me}) );
		arg += "\n";//从文件中读取时总是会多出一个回车...有隐患，不过暂时未发现问题
        if (strsrch(arg,me->query_temp("riddle/answer")) == -1)
           {
              write("阿凡提大笑起来，说道：你说什么呀，牛头不对马嘴。\n"
                  + me->name() + "的脸被臊得通红。\n");
              return 1;
           }
          else
           {
          gold = new("clone/money/gold");
          gold->move(this_player());
          say("阿凡提给了" + me->name() + "一两黄金。\n");
          this_player()->set_temp("marks/谜", 0);
          say ("阿凡提对" + me->name() + "竖起大姆指：居然让你猜着了。黄金是巴依的不义之财，你拿去分给穷人吧。\n");
          this_player()->set("combat_exp",this_player()->query("combat_exp")+1000);
          write ("你的经验增加了！\n");
          return 1;
            }
} 
 
string new_riddle(object who)
{   
	string q , a;
    int sline;
    sline=(random(TLINES)+1)*2-1;
   
    q=read_file(filename,sline,1);
    a=read_file(filename,sline+1,1);
   
    write(q);
         if (wizardp(who) && who->query("riddle")==1) write("谜底："+a);//巫师可以看到答案
    who->set_temp("marks/谜", sline);
    return a ;
}
