// /u/dubei/wudang/npc/laoweng
 
inherit NPC;
int ask_me();
int ask_me1();
  

void create()
{
    set_name("无名老翁", ({ "lao weng", "lao" }));
    set("long", "这位老者穿着简朴，满头银发，面色红润。\n");
    set("gender", "男性");
    set("age", 70);

    set_skill("medicine", 200);

    set_temp("apply/attack", 1000);
    set_temp("apply/defense", 1000);
    set_temp("apply/damage", 1000);

    set("combat_exp", 1000000);
    set("shen", 10000);
    set("inquiry", ([
                "采药道长" : (: ask_me :),
                "搭救" : (: ask_me1 :),
              
        ]));
    setup();

     carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	command("say 是武当的采药道长吗？偶尔能看到他来后山采药。\n");
	return 1;
}

int ask_me1()
{
        object me, ob;

        ob = this_player();
        me = this_object();
       
        command("say 昔年一位武当采药道长失足坠落后山悬崖，我正好采药路过，略加\n"
"医治。举手之劳，况陈年往事，提它干吗？");
        ob->set_temp("marks/jieguo",1);
	return 1;
}