// liumang.c 流氓
inherit NPC;
string ask_penwu();
string ask_gun();
string ask_mi();

void create()
{
        set_name(HIW"西门无剑"NOR, ({ "npc pipip", "npc" }));
        set("gender", "男性"); 
        set("title", HIG"孤家寡狼"NOR);        set("age", 19);
        set("nickname", HIY"天涯玩具公司"NOR);
       set("long", "长得好帅好帅的小p哦，他应该是现在jhfy系列mud中最年轻的小wiz了。\n");
        
        set("combat_exp", 1000);
        set("shen_type", -1);
        set("per", 26);
        set("dex", 2600);
        set("jiali", 99999999999);
        set("attitude", "peaceful");
        
        set_skill("unarmed", 20);
        set_skill("dodge", 200);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
      set("inquiry", ([
    "AK47":(:ask_gun:), 
    "防狼喷雾":(:ask_penwu:), 
//      "麦克峰":(:ask_mi:), 
//该obj所显示的message太过耀眼，请不要再放出来。。
       ]) );

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

     ob = new("/d/pipip/obj/ak");   
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-50);
return "这东西可贵的很需要五十枚星空币,我已经在钱庄帮您把钱转过来了";
}
string ask_mi()
{
        object ob;
           if (this_player()->query("zjb_money") < 50)
return "得了吧,就你钱庄那点钱,也想买这么贵的东西！";

     ob = new("/d/pipip/obj/phone");   
     ob->move(this_player()); ;
     this_player()->add("zjb_money",-50);
return "这东西可贵的很需要五十枚星空币,我已经在钱庄帮您把钱转过来了";
}


