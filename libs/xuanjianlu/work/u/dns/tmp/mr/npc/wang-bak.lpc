// /u/beyond/mr/npc/wang.c 王夫人
// this is made by beyond
// update 1997.6.29
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_job();
int ask_ok();

void create()
{
	set_name("王夫人",({"wang furen","wang","furen"}));
	set("gender", "女性");
	set("rank_info/respect", "夫人");
        set("title","曼佗罗山庄主");
  	set("long", 
              "她就是曼佗罗山庄的主人，她看上去虽以四十有加，但风韵尤存。\n");
        set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 0);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1500);
	set("max_jing", 1500);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 0);
	set("combat_exp", 180000);
	set("score", 15000);

        set_skill("dodge",100);
        set_skill("force", 100);
	set_skill("shenyuan-gong", 100);
	set_skill("yanling-shenfa", 100);
        set_skill("parry", 100);
	set_skill("murong-jianfa", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);
        set_skill("finger", 100);
        set_skill("canhe-zhi", 100);
        set_skill("strike", 100);
        set_skill("xingyi-zhang", 100);
//         set_skill("beauty",300);
        
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("strike", "xingyi-zhang");
        map_skill("finger", "canhe-zhi");
        map_skill("parry", "murong-jianfa");
        map_skill("sword", "murong-jianfa");	
        prepare_skill("finger", "canhe-zhi");
        prepare_skill("strike", "xingyi-zhang");
        
	setup();
        carry_object(__DIR__"obj/shoe")->wear();
        carry_object(__DIR__"obj/red_silk")->wear();
        carry_object(__DIR__"obj/skirt")->wear();
        create_family("姑苏慕容",3,"弟子");
        set("inquiry", ([
            "name" : "我就是曼佗罗山庄的主人，见到我难道没有什么表示吗？\n",
            "here" : "这里是曼佗罗山庄的庄院之所在，此处名为云锦楼？\n",
            "rumors" : "最近我那表亲慕容博不幸仙逝了。\n",
            "王语嫣" : "语嫣是我的宝贝女儿，你可别想打她的主意。\n",
            "慕容复" : "慕容复是我那不成器的侄儿，练就了以彼之道还施彼身的绝技，名震江湖。\n",
            "娘缳玉洞" : "娘缳玉洞是我曼佗罗山庄的藏书之处，一般人是别想进去了。\n",
            "曼佗罗山庄" : "这里就是曼佗罗山庄，我就是这里的主人。\n",
            "还施水阁" : "那是燕子坞的秘密之所在，不过还施水阁的藏书比那里可是多的多呀。\n",       
            "job" : (: ask_job :),
            "ok"  : (: ask_ok :),
       ]));
       
}

string ask_job()
{
	mapping fam;
	object me = this_player();
	
	if (!(fam = me->query("family")) || fam["family_name"] != "姑苏慕容") // 必须是慕容派弟子
               return RANK_D->query_respect(me) +
               "与本派素无来往，不知此话从何谈起？";
        if(me->query_condition("mrhua_busy") > 0)
               return "我正在美容，你过一会再来吧。\n";       
               
        if ((int)me->query("combat_exp") > 80000 )
               return "你武功这么高，我可不敢用你。\n";
               
        if (me->query_temp("mrhua")||me->query_temp("yanpopo"))
               return "你不是已经领了工作么，还不快去做！\n";
               
        me->set_temp("mrhua",1);
        me->set_temp("yanpopo",1);
        me->apply_condition("mrhua_job",random(10)+20);
        
        return "庄门口的茶花最近开的不盛，该好好照料一下了，你去找严婆婆，听她安排吧。\n";
}

int ask_ok()
{
	object me = this_player();
	int exp, pot, gold;
	
	if(me->query_temp("mark/还了"))	
	{
		
		   
		exp = random(30)+me->query("max_pot")/2;
                pot = exp / 2;		
		gold = random(3) + 1;
		
		if(me->query_temp("killke"))
		    exp = exp + exp / 3;
		    
		me->add("potential",pot);
		me->add("combat_exp",exp);
		me->add_money("gold",gold);
		
		if(me->query("potential") > me->query("max_pot"))
		    me->set("potential", me->query("max_pot"));
		
		tell_object(me,HIW"你被奖励了：\n" + 
                       chinese_number(exp) + "点实战经验\n" +
                       chinese_number(pot) + "点潜能\n"+
                       chinese_number(gold)+"两黄金\n"
                       NOR);      
                me->delete_temp("mark/还了");
                me->delete_temp("mrhua");
                me->delete_temp("yanpopo");
                me->clear_condition("mrhua_job");
                me->delete_temp("killke");	
                me->apply_condition("mrhua_busy",2+random(2));
         }
         return 1;
}

void attempt_apprentice(object ob)
{
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("title","姑苏慕容第四代弟子");
}
