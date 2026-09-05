backup
ep
#include <ansi.h>

inherit NPC;
void do_answer(string);
void ask_gift();
int do_changegift(string);
void create()
{
        set_name("行云", ({"wiz advent", "advent"}));
        set("title",HIW"巫师" NOR);
        set("gender", "男性");
        set("age", 27);
        set("long",
                "他就是行云(advent)，听说可以帮信人调整属性！\n你不妨上去打听一下属性的问题。\n");
        set("attitude", "heroism");
        set("str", 28);
        set("int", 18);
        set("con", 24);
        set("dex", 20);
        set("chat_chance", 20);
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 50);
        set("dai",2);

        set("combat_exp", 10000);

        set("inquiry", ([
                "属性":(:ask_gift:),
                "gift":(:ask_gift:),
        ]) );

        setup();
}

void init()
{
        add_action("do_answer","answer");
        add_action("do_changegift","changegift");
}

void ask_gift()
{
     say("你想改变先天属性吗？answer y/N。");
           input_to("do_answer",this_player());
           return;      
}

void do_answer(string arg)
{
        object me=this_player();
        if (!arg || (arg != "是" && arg != "y" && arg != "yes"))
                command("pat"+me->query("id"));
                command("say 那你赶紧去练功吧！");
                return;

  if (me->query("marks/changegift")==1)
           {
               command("? "+me->query("id"));
               command("say 你不是更改过了么？每个人只有一次机会！");
               return;
           }
           if (me->query("mud_age")>3600 || me->query("combat_exp")>100)
           {
              command("sigh "+me->query("id"));
              command("say 你筋骨已成，改变属性恐怕很难");
              return;
           }
           command("ok");
           command("say 请按命令格式输入：changegift <膂力> <悟性> <根骨> <身法>！");
           command("say 比如：changegift 20 20 20 20。");
           command("say 记得总和不能超过80!");
           input_to("do_changegift",me);        
           return;

}

int do_changegift(string arg)
{
     int str, ints, con, dex;
     object me;
     me = this_player();

     if ( !arg || sscanf(arg, "%d %d %d %d", str, ints, con, dex) != 4)
     {
     write("指令格式：changegift <膂力> <悟性> <根骨> <身法>。\n");
           input_to("do_changegift",me);             
     return 0;
     }
     
     if(str+ints+con+dex>80)
     {
     write("你的属性值超过80，请重新输入！");
           input_to("do_changegift",me);             
     return 0;
     }
     else
     {
     me->set("str",str);
     me->set("int",ints);
     me->set("con",con);
     me->set("dex",dex);
     me->set("marks/changegift",1);
     me->save();
     write("属性设置成功!\n");
     return 1;
     }
}

