// Npc: /kungfu/class/shaolin/hui-xiu.c
// Date: YZC 96/01/19

inherit NPC;
string ask_me();

void create()
{
	set_name("慧修尊者", ({
		"huixiu zunzhe",
		"huixiu",
		"zunzhe",
	}));
	set("long",
		"他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
		"太阳穴微凸，双目炯炯有神。\n"
	);


	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

        set("age", 50);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 450);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
 
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 100);

        set_skill("force", 70);
        set_skill("hunyuan-yiqi", 70);
        set_skill("dodge", 70);
        set_skill("shaolin-shenfa", 70);
        set_skill("cuff", 75);
        set_skill("jingang-quan", 75);
        set_skill("staff", 76);
        set_skill("pudu-zhang", 76);
        set_skill("parry", 70);
        set_skill("buddhism", 70);
        set_skill("literate", 70);
   	map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("staff", "pudu-zhang");
        map_skill("parry", "pudu-zhang");

        prepare_skill("cuff", "jingang-quan");



	create_family("少林派", 38, "弟子");
        set("inquiry", 
                ([
                     	"轮值" : (: ask_me :),
                ]));
	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"

void init()
{
	add_action("do_tast","task");
}
string ask_me()
{
        mapping fam; 
        object me;
        object ob;
        ob=this_player();
//        me=this_object();
        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "少林派")
                return RANK_D->query_respect(ob) + 
                "，你不是本寺弟子，此话从何说起？";
        if ((string)ob->query("class")!="bonze")
            return ("俗家弟子不能轮值。");
        if (ob->query("combat_exp")>=50000)
                return ("我看你的武功已有相当的功底了，就把轮值的机会让给师弟们吧。\n");
	if (ob->query_temp("lunzhi"))
		return ("现在已有人轮值了，你就等下一次吧。\n");
       
	ob->set("lunzhi_name",ob->query("name"));
	//me->set_temp("lunzhi",1);
	ob->set_temp("lunzhi",1);
	ob=new("/d/shaolin/npc/obj/lunzhi-ling");
	ob->move(this_player());
	write("慧修大师给你一块轮值令。\n");
        return "好吧，你就到迎客亭把令交给虚通吧，轮值时应当小心防范，防止外敌偷入寺中。";
}
int do_tast(string arg)
{
	object ob,me;
	ob=this_player();
	me=this_object();
	if(!(arg||arg=="ok")) return 0;
	if(!ob->query_temp("lunzhi")) return 0;
	if(!ob->query_temp("lunzhied")) return 0;
	if(arg=="ok"&&ob->query_temp("lunzhied")
		&&ob->query("name")==me->query("lunzhi_name"))
	{
             
              if (interactive(ob = this_player()) && 
            	(int)ob->query_condition("sl_lunzhi")) {
                 command("angry"+ob->query("id"));
                 command("slap"+ob->query("id"));
                 return notify_fail("想偷懒，快给我滚回去。");
                 }          
                command("pat "+ob->query("id"));
		command("say 哈哈，真难为你了，"+RANK_D->query_respect(ob)+"，干得好！");
                  ob->add("potential",(int)(ob->query_skill("buddhism",1)/10)+10);
		if (ob->query("potential") > ob->query("max_pot"))
                  ob->set("potential", ob->query("max_pot"));   
                ob->add("combat_exp",(int)(ob->query_skill("buddhism",1)/4)+100);
                me->delete("lunzhi_name");
		me->delete_temp("lunzhi");
		ob->delete_temp("lunzhi");
		ob->delete_temp("lunzhied");
		return 1;
	}
	return 1;
}