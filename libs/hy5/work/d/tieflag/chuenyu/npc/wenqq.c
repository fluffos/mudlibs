// xiaozh.c 萧中慧
// zly 99.6.22

#include <ansi.h>
inherit NPC;
string ask_yyd();
int ask_me();
void create()
{
        object ob;
        set_name("温青青", ({ "wen qingqing", "wen", "qingqing"}));
        set("gender", "女性");
        set("unique", 1);
        set("age", 20);
        set("long", "
浙江石梁温家之女温仪与金蛇郎君夏雪宜私生女，母温仪将其抚养长大。\n温青青长的貌美如花、娇媚可人，天真可爱，活泼乐观，心地单纯。\n 虽然身世悲惨，但是从来不会产生心理仇恨感。也爱吃醋耍小脾气。\n");
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

"营救" : (: ask_me :),
        ]));



        setup();

        carry_object("/d/city/obj/necklace")->wear();
        carry_object("/d/city/obj/pink_cloth")->wear();
        carry_object("/d/city/obj/flower_shoe")->wear();



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
	

	  	if(((int)who->query("jinyong/book13")>=1))
	{
		message_vision("$N对$n说道： 我听不懂,你在说什么啊！\n",this_object(),who);
		call_out("destroying", 0);     
		return 1;	
	}
	command("thank " + who->query("id"));
	message_vision("$N对$n说道： 谢谢大侠教命之恩。。\n",this_object(),who);
	message_vision("$N对$n说道：大侠能帮我找到我父亲，去救我母亲吗? 我父亲夏雪宜在边城的万马堂办事。\n",this_object(),who);

who->set_temp("book131",1);
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