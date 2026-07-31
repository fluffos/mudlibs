// daobaifeng.c 刀白凤

#include <ansi.h>
inherit NPC;
int ask_duan2();

void create()
{
	set_name("康敏", ({ "kang ming", "kangming" }));
	set("nickname",  HIG"副帮主夫人"NOR );
	set("gender", "女性");
	set("long", "丐帮副帮主马大元的妻子，段正淳的情妇之一。她与白世镜、全冠清等武林人士有私情，天性放荡。。\n");
	set("age", 35);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 28);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("max_qi", 11800);
	set("max_jing", 1500);
	set("neili", 11500);
	set("max_neili", 11500);
	set("jiali", 100);
	set("combat_exp", 1500000);
	set("score", 200000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("cuff", 200);
	set_skill("strike", 200);
	set_skill("whip", 200);
	set_skill("kurong-changong", 301);
	set_skill("duanjia-sword", 300);
	set_skill("tiannan-step", 300);
	set_skill("jinyu-quan", 300);
	set_skill("wuluo-zhang", 300);
	set_skill("feifeng-whip", 300);
	set_skill("literate", 60);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("whip", "feifeng-whip");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "feifeng-whip");
	map_skill("sword", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");

        set("inquiry", ([
          "白世镜" : (: ask_duan2 :),
           ]));
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1200);
	setup();
	carry_object("/d/qianjin/obj/pink_cloth")->wear();
	
	add_money("silver", 10);

}

int ask_duan2()
{
        object me,ob,obj,fang;
        int i;
        ob=this_player();
        me=this_object();
       
       if(!ob->query_temp("killtlbb8") && !query("iskillok"))
      {
      message_vision("突然从附近杀出两个乞丐 说道： 杀了灭口!\n",this_object(),ob);	
      	fang = load_object(__DIR__"bai-shijing");
	fang->move(environment(ob));	
	fang->kill_ob(ob);

      	fang = load_object(__DIR__"quan-gq");
	fang->move(environment(ob));	
	fang->kill_ob(ob);

     this_object()->set("iskillok",1);
     set("iskillok",1);
      }	
       
        
    if(!ob->query_temp("killtlbb7"))
{
message_vision("$N你在说什么啊？。\n", me, ob);
return 1;	
}    

    if(!ob->query_temp("killtlbb8"))
{
message_vision("$N你在说什么啊？。\n", me, ob);
return 1;	
}         

        
        if (ob->query("jinyong/book4")==4){
        message_vision("$N道：“我就是要报复乔峰，谁让他看不上我的。\n", me, ob);

ob->set_temp("killtlbb9",1);
 message_vision("$N道：“即然被你识破了，我也不活了....\n", me, ob);
::die();
        }
        else {
           message_vision("$N似乎不懂你的意思。\n", me, ob);
        }
        return 1;
}