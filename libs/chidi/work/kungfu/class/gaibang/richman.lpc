// 菜板完成于2001 8.2

#include <ansi.h>
#include <command.h>
inherit BHNPC;
int do_back(object me);

void create()
{
        set_name("富商", ({ "rich man","man"}));
        set("gender", "男性");
        set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("long", "一个满身肥肉的家伙,身上珠光宝气，看起来就是个有钱人。\n");
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        setup(); 
 } 
 void init()
        {add_action("do_begging" , "begging");
        }  

int do_back(object me)
{                       
  tell_room(environment(me), me->query("name")+"匆匆忙忙的离开了。\n", ({me})); 
  destruct(me); 
  return 1;
}
int do_begging(string arg)
{
        object me = this_player();
        object ob = this_object();
        object ob1;
            if (!me->query("do_job")||me->query("do_job")<1)
        {
                message_vision(CYN"$N对$n说道:看你仪表人才不象个乞丐呀？\n"NOR,ob,me);
                  return 1;
        }
        if (arg=("man")||arg=("rich man"))
        {
        message_vision(CYN"$N对$n大声喊到：这位大爷行行好吧，给小的一口饭吃!。\n"NOR,me,ob);
        if (me->query("finish_coin"))
        {
                message_vision(CYN"$N对$n说道:我不是给你钱了吗？\n"NOR,ob,me);
                  return 1;
        }
        switch (random(4))
        {
                case(0) : message_vision(CYN"$N对$n说道:大爷我没有钱，快滚!\n"NOR,ob,me);
                          break;
                case(1) : message_vision(CYN"$N对$n说道:去去去，快走，哪有钱给你们这些乞丐!\n"NOR,ob,me);
                          break;
                case(2) : message_vision(CYN"$N对$n说道:我今天没带钱来，对不起拉!\n"NOR,ob,me);
                          break;
                case(3) : message_vision(CYN"$N对$n说道:好吧，就给你些钱吧!\n"NOR,ob,me);
                          ob1 = new("/clone/money/coin");
                          ob1 -> move(me);
                          me -> set("finish_coin",1);
                          break;
                        };
        call_out("do_back", 350,  ob);  
        return 1;
        }
}
