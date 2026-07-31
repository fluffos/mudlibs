// xiaozh.c 萧中慧
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();
int ask_me();
void create()
{
        object ob;
        set_name("萧中慧", ({ "xiao zhonghui", "xiao", "zhonghui"}));
        set("gender", "女性");
        set("unique", 1);
        set("age", 20);
        set("long", "
她是晋阳大侠萧半和的女儿，她容貌娇美，神色中散发着一股勃勃英气。\n");
        set("attitude", "friendly");
        set("shen", 150000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);

        set("max_qi", 13000);
        set("qi", 13000);
        set("jing",11600);
          set("max_jing", 11600);
        set("jingli", 12200);
        set("eff_jingli", 12200);        
        set("neili", 24500);
        set("max_neili", 24500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        
        set_skill("force", 180);             // 基本内功
        set_skill("huntian-qigong", 180);    // 混天气功
        set_skill("blade", 380);             // 基本刀法
        set_skill("wuhu-duanmendao", 390);
//      set_skill("fuqi-daofa", 180);        // 夫妻刀法
        set_skill("dodge", 180);             // 基本轻功
        set_skill("xiaoyaoyou", 180);        // 逍遥游
        set_skill("parry", 180);             // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");

        set("inquiry", ([
            "太岳四侠" : "那是四个活宝。说完，已经笑得腰都弯了。\n",
            "袁冠男" : "你认识袁大哥？袁大哥现在在哪里？说完，脸唰地红了起来。\n",
            "萧半和" : "爹爹马上就要过五十大寿了，发了很多英雄帖呢。你有吗？\n",
"营救" : (: ask_me :),
        ]));

        set("chat_chance", 3);
        set("chat_msg", ({
            "萧中慧忽然满脸红晕，低声念道：“清风引屋佩瑶台，明月照状成金屋。”\n",
            "萧中慧低声说道：“过两天就是爹爹的寿诞了，该送什么礼物呢？”\n", 
        }) );

        setup();
        if (clonep()) {
                ob = new(__DIR__"obj/yang");
                if (random(4)==0) ob = new("/clone/weapon/gangdao");
                ob->move(this_object());
                ob->wield();
        carry_object(__DIR__"obj/red-cloth")->wear();

}
}

/*string ask_yyd()
{
        object me=this_player();
        if(me->query_skill("blade", 1) <120)
                return "你先把刀法的基础打好再说吧。\n";
        if(me->query("fuqi"))
                return "咦，你不是已经学到了夫妻刀法了吗？\n";
        if(me->query_temp("mb"))
                return "咦，我不是刚才告诉你了吗？\n";
        command("blush");
        return "这夫妻刀法，是当年师母传给我的。\n";
}
*/
int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	

	  	if(((int)who->query("jinyong/book14")>=1))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}

	if (who->query("combat_exp",1) < 800000)
	{
	command("look  "+who->query("id"));
	command("sneer "+who->query("id"));
	return notify_fail("凭你这点本事配来管我的闲事？！\n");
	}
	
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。这把鸯刀就送于大侠。\n",this_object(),who);
	message_vision("听说太岳四侠是我的好朋友，但他们外出云游了。你能帮我联系他们吗?\n",this_object());
        message_vision("太岳四侠的脾气有点怪，会考验你的武功，小心了。\n",this_object());
	ob = new(__DIR__"obj/yang");
        ob->move(who);
	i = 200+random(800);
	who->set("jinyong/book14",1);
	who->add("combat_exp",i+8880);
	who->add("potential",i*8);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"你赢得了"+chinese_number(i+8880)+"点经验"+
	           chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
	who->save();
	call_out("destroying", 0);                       
	return 1;
}
void destroying()
{   
object ob=this_object();
   message_vision(HIM"$N说完闪了闪身就消失在门外......\n"NOR,ob);
destruct(this_object());
   return;      
}