#include <ansi.h>
inherit NPC;

void create()
{
	set_name("金庸",({"jinyong","jin"}));
       set("title",HIY"大侠"NOR);
	set("long", 
              "他就是传说中的大侠金庸。\n"
              "如果你有所有的神书。你可以用findbook给他.\n");
        set("age", 57);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("per", 50);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 30000000);
	set("score", 50000);                
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("blade",200);

       
        create_family("金庸学会",1,"元老");

       	setup();
	
}
void init()
{
	add_action("do_findbook", "findbook");
}

int do_findbook(object ob)
{
        object me  = this_player();
        string name, new_name;
	int exp,pot,score;

        if (present("shenbook1", me)  && present("shenbook2", me)&& present("shenbook3", me)&& present("shenbook4", me)&& present("shenbook5", me)&& present("shenbook6", me)&& present("shenbook7", me)&& present("shenbook8", me)&& present("shenbook9", me)&& present("shenbook10", me)&& present("shenbook11", me)&& present("shenbook12", me)&& present("shenbook13", me)&& present("shenbook14", me))  
         {
                 destruct(present("shenbook1",me));
                 destruct(present("shenbook2",me));
                 destruct(present("shenbook3",me));
                 destruct(present("shenbook4",me));
                 destruct(present("shenbook5",me));
                 destruct(present("shenbook6",me));
                 destruct(present("shenbook7",me));
                 destruct(present("shenbook8",me));
                 destruct(present("shenbook9",me));
                 destruct(present("shenbook10",me));
                 destruct(present("shenbook11",me));
                 destruct(present("shenbook12",me));
                 destruct(present("shenbook13",me));
                 destruct(present("shenbook14",me));
           command("say 好吧，既然你帮我找到了所有的神书，难为你" +
             "如此辛苦跑来，我不会亏待你的。");
             exp =1000+random(4000);
             pot = exp/5;
             score = random(5000);
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
             me->add("per",1);
             me->add("str",1);
             me->add("int",1);
             me->add("con",1);
             me->add("dex",1);
             me->add("kar",1);
     	      tell_object(me,"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点综合评价\n");
                     tell_object(me,HIR"你的臂力提高了!\n"NOR);
                     tell_object(me,HIG"你的悟性提高了!\n"NOR);
                     tell_object(me,HIY"你的根骨提高了!\n"NOR);
                     tell_object(me,HIB"你的身法提高了!\n"NOR);
                     tell_object(me,HIM"你的福缘提高了!\n"NOR);
                     tell_object(me,HIC"你的容貌提高了!\n"NOR);
              command("chat* haha"); 
         }
        else
          command("say 你身上哪里有所有的神书!");
        return 1;
}
 


