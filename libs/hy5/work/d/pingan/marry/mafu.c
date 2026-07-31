// 马夫

inherit NPC;

int do_out();

void create()
{
        set_name("马夫", ({ "ma fu", "ma", "fu" }));
        set("gender", "男性");
        set("age", 25);
        set("long", "他就是红娘庄专门带宾客离开婚礼的马夫。\n");
        
        set("combat_exp", 7000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        setup();
        set("inquiry", ([
                "离开"     : (: do_out :),
        ])); 
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 2);
}
int do_out()
{
  object me, ob ;
  
  me= this_player();

  ob= this_object();

  say("马夫一哈腰对"+(string)me->query("name")+"说：“你老请上车。”\n");

  say((string)me->query("name")+"被带出了红娘庄。\n");

  me->move("/d/pingan/guangchang");

  return 1;
}  
