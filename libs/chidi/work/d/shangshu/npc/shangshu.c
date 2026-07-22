#pragma save_binary
inherit BHNPC;

void init()
{
add_action("do_dangguan","dangguan");
}
void create()
{
        set_name("庾子建", ({ "yu shangshu","yu" }));
        set("title","兵部尚书");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "他是当今皇上身边的红人，与宫中的关系也很熟络，手中掌管着\n"
		"兵马大权。不过能爬上这个位置，绝不是仅仅因为溜须拍马的缘\n"
		"故，当年战功赫赫，才有今天的地位。\n"
		);

        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

        set("force", 1400);
        set("max_force", 800);
        set("force_factor", 10);
        set("max_gin", 200);
        set("eff_gin", 200);
        set("gin", 200);
        set("max_sen", 200);
        set("eff_sen", 200);
        set("sen", 200);

        set("combat_exp", 400000);

        set_skill("blade", 70);
       set_skill("hujia-daofa", 105);
        set_skill("force", 80);
        set_skill("wu-shun", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("tiyunzong", 60);

        map_skill("blade", "hujia-daofa");
        map_skill("parry", "hujia-daofa");
        map_skill("force", "wu-shun");
       map_skill("dodge", "tiyunzong");
      set("inquiry", ([
        "当官": HIC "庾子建想了想说:想当官那要看你有无这分才能啊!\n" NOR,
        "升官": HIC "想升官就让我来考考你(dangguan)\n" NOR,
        ]));

        setup();

        carry_object(__DIR__"obj/blade")->wield();
}

int do_dangguan(string arg)
 {
  object ob;
  string old_title;
   ob=this_player();
   old_title = this_player()->query("title");
        if(ob->query("combat_exp")<1000000||ob->query("meili")<50){
        command(HIY "say 我主万岁,需要的是有用之人,你算什么东西。\n" NOR);
        return 1;
   }
else if((string)ob->query("family/family_name") != "朝廷")
{command("say 这年头什么人都想当官,真是稀奇啊！\n");
    command("sigh2");
    return 1;} 
  else {

        command("smile");
        command(BLU "say 很好,朝庭正是用人之季！" + ob->query("name") +
        "大侠肯为朝庭效力，我正求之不得！\n" NOR);
         ob->set("class", "officer");
        ob->set("weiwang", 0);
 if (ob->query("combat_exp")<2000000) 
 {ob->set("title", "朝廷七品官 俾将军");ob->set("rank",7);}
  else if (ob->query("combat_exp")<4000000) {ob->set("title","朝廷六品官 偏将军");ob->set("rank",6);}
 else if (ob->query("combat_exp")<6000000) {ob->set("title","朝廷五品官 威东将军");ob->set("rank",5);}
 else if (ob->query("combat_exp")<10000000) {ob->set("title","朝廷五品官 破虏将军");ob->set("rank",5);}
  else if (ob->query("combat_exp")<12000000){ob->set("title", "朝廷五品官 荡寇将军");ob->set("rank",5);}
 else if (ob->query("combat_exp")<14000000) {ob->set("title", "朝廷四品官 奋威将军");ob->set("rank",4);}
 else if (ob->query("combat_exp")<16000000) {ob->set("title", "朝廷四品官 建威将军");ob->set("rank",4);}
 else if (ob->query("combat_exp")<18000000) {ob->set("title", "朝廷四品官 征虏将军");ob->set("rank",4);}
 else if (ob->query("combat_exp")<20000000) {ob->set("title", "朝廷三品官 左将军");ob->set("rank",3);}
 else if (ob->query("combat_exp")<22000000) {ob->set("title", "朝廷三品官 平东将军");ob->set("rank",3);}
 else if (ob->query("combat_exp")<24000000) {ob->set("title", "朝廷三品官 安东将军");ob->set("rank",3);}
 else if (ob->query("combat_exp")<26000000) {ob->set("title", "朝廷二品官 镇东将军");ob->set("rank",2);}
 else if (ob->query("combat_exp")<28000000) {ob->set("title", "朝廷二品官 征东将军");ob->set("rank",2);}
 else if (ob->query("combat_exp")<30000000) {ob->set("title", "朝廷二品官 卫东将军");ob->set("rank",2);}
 else if (ob->query("combat_exp")<32000000){ ob->set("title", "朝廷一品官 车骑将军");ob->set("rank",1);}
 else if (ob->query("combat_exp")<34000000){ ob->set("title", "朝廷一品官 骠骑将军");ob->set("rank",1);}
 else {ob->set("title", "朝廷一品官 护国大将军");ob->set("rank",1);}
if (old_title==(string)ob->query("title")) 
command("say "+RANK_D->query_respect(ob)+"如果能够继续努力的话，将来一定会加官进爵，钱途不可限量!\n");
else if((string)ob->query("title") == "普通百姓") 
write("包龙星疑惑的看了看你，说道：嗯，你还是继续做你的普通百姓吧！\n");
else {
tell_object(ob,"你现在的官衔是[["+ob->query("title")+"]]\n");
message("system", HIY"圣旨：
由于"+ob->query("name")+"执政有方，特为嘉奖从即日起荣升为『"+ob->query("title")+"』！
望"+ob->query("name")+"能继续为朝庭效忠！
            钦此\n"NOR,users());
        }
       return 1;
       }
}

