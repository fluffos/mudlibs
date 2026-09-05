#include <ansi.h>          

inherit NPC;   
string ask_leave();

void create()         
{
    set_name(HIW"赵敏"NOR, ({ "zhao min", "zhao", "min" }) );    
    set("gender", "女性");   
    set("age", 20);    
    set("per", 40);     
    set("long", HIW "赵小姐身穿雪白绸衫，掩不住一副雍容华贵之气，美得出奇。但凡美人，
不是温雅娇美，便是艳媚婉转，这位小姐却是十分美丽之中，更带着三
分英气，三分豪态，同时雍容华贵，自有一副端严之致，令人肃然起敬。\n" NOR); 
    set("combat_exp", 6000000000);     
    set("shen_type", 0);      
    set("attitude", "friendly");       
    set("apply/attack",  60000);       
    set("apply/defense", 60000);       
    set_skill("unarmed", 4000);        
    set_skill("parry", 4000); 
    set_skill("dodge", 4000);        
    set_skill("force", 4000);
    set_skill("sword", 4000);
    set_skill("finger", 4000);
    set_skill("blade", 4000);
    set_skill("zhutian", 4000);
    set_skill("fuliu-jian", 4000);
	set_skill("tiangang-zhi", 4000);
	set_skill("linji-zhuang", 4000);
    map_skill("parry", "fuliu-jian");
    map_skill("dodge", "zhutian");
    map_skill("sword", "fuliu-jian");
    map_skill("finger", "tiangang-zhi");
    map_skill("force", "linji-zhuang");
    prepare_skill("finger", "tiangang-zhi");
    set_temp("apply/armor", 6000);
    set_temp("apply/damage", 4200);
    set("chat_chance_combat", 70);
    set("chat_msg_combat", ({
    (: perform_action, "sword.fuliu" :),
    (: perform_action, "sword.huifeng" :),
    (: perform_action, "sword.miejian" :),
     }) );
    set("max_qi", 75000);
    set("jingli", 20000);
    set("max_jingli",20000);
    set("jing",20000);
    set("max_jing",20000);
    set("neili", 160000);
    set("max_neili", 160000);
    set("jiali", 2000);
	set("inquiry",([
		"leave": (: ask_leave :),
		"离开": (: ask_leave :),
	]));
    setup();
    carry_object("/d/lvliu/obj/fake-yitianjian")->wield();
    carry_object("/clone/cloth/female2-cloth")->wear();
}      

void unconcious()
{
	die();
}

void die()
{
	object ob = this_object();
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	message_vision(HIM"$N" HIM "深深吸了几口气，脸色看起来好多了。\n"NOR, ob);
	return;
}

string ask_leave()
{
	object me=this_player();
	if (me->query_temp("ask_leave_lvliu"))
	{
		me->delete_temp("ask_leave_lvliu");
		message_vision(HIC"\n$N挥了挥手，两位下人走了过来，恭恭敬敬地伺立一旁，躬身送$n离开。\n\n"NOR, this_object(), me);
		me->move("/d/mingjiao/xiaoyuan");
		return "后会有期！";
	}
	me->set_temp("ask_leave_lvliu", 1);
	return "尊客这就要离开了么？如果确定要走，再询问我一次即可。";
}