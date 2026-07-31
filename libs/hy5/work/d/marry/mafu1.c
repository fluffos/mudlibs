// 马夫

inherit NPC;

int do_hunli();

void create()
{
        set_name("马夫", ({ "ma fu", "ma", "fu" }));
        set("gender", "男性");
        set("age", 25);
        set("long", "他就是红娘庄专门接人去参加婚礼的马夫。\n");
        
        set("combat_exp", 7000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("inquiry", ([
                "婚礼"     : (: do_hunli :),
                "参加婚礼" : (: do_hunli :),
        ])); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 2);

}
int do_hunli()
{
  object me, ob ;
  
  me= this_player();

  ob= this_object();

 if (!( present("qing tie", me)) )
        {
             say("马夫翻了翻白眼说：“你有请贴吗？”\n");
             return 1;
        }

  say("马夫一哈腰对"+(string)me->query("name")+"说：“你老请上车。”\n");

  say((string)me->query("name")+"被带到了红娘庄。\n");

me->move("/d/marry/honglou");

  return 1;
}  
