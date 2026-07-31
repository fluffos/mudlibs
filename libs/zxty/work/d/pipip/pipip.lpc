// liumang.c 流氓
inherit NPC;
string ask_penwu();
string ask_gun();


void create()
{
        set_name("星空", ({ "zjb" }));
        set("gender", "男性"); 
        set("combat_exp", 1000);
        set("shen_type", -1);
        set("per", 26);
        set("attitude", "peaceful");
        set("max_qi", 99900000);
        set("max_jing", 99900000);
        
        set_skill("unarmed", 20);
        set_skill("dodge", 20000);
        set_temp("apply/defense", 10);
      set("inquiry", ([
    "AK47":(:ask_gun:), 
    "防狼喷雾":(:ask_penwu:),        ]) );

        setup();
        carry_object("/clone/misc/hic_cloth")->wear();
        add_money("silver",2);
}

string ask_penwu()
{
        object ob;
           if (this_player()->query("zjb_money") < 50) 
return "得了吧,就你钱庄那点钱,也想买这么贵的东西！";
     ob = new("/d/pipip/obj/penwu");     
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-50);
return "这东西可贵的很需要五十枚星空币,我已经在钱庄帮您把钱转过来了";
}

string ask_gun()
{
        object ob;
           if (this_player()->query("zjb_money") < 50)
return "得了吧,就你钱庄那点钱,也想买这么贵的东西！";

     ob = new("/d/pipip/obj/gun");   
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-50);
return "这东西可贵的很需要五十枚星空币,我已经在钱庄帮您把钱转过来了";
}

