 //XXDER
inherit NPC;
inherit F_MASTER;
int leave(); 
#include <ansi.h>
void create()
{
    set_name("白水娘娘", ({ "master shenshui", "master", "shenshui" }) );
    set("nickname", HIB"水母阴姬"NOR);
    set("gender", "女性");
    set("class", "shenshui");
    set("age", 33);
    set("long",
        "一位脸上带着面沙的美女，坐在雕花椅上，你虽然看不到她的面容，却可以感觉到她"
        "那绝佳的气质和举手投足间的成熟风韵。\n");
    set("attitude", "peaceful");
    set("class", "shenshui");
    set("apprentice_available", 2);
    
    create_family("神水宫", 11, "掌门");
    set("rank_nogen",1);
    set("ranks",({"弟子","小仙女","仙女","大仙女","神姬",MAG"仙姬"NOR,HIM"圣姬"NOR,
                      HIR"副掌门"NOR}));
    set("reward_npc", 1);
        set("difficulty", 30);
    set("inquiry", ([
        "leave" : (: leave :),
                ]));  
        
    set("int", 28);
    set("spi", 26);
    set("per", 30);
    set("cps", 30);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu"  :),
  //      (: perform_action, "unarmed.suicidal" :),
            }) );
  set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
    set("force_factor", 60); 
    set("combat_exp", 25000000);
    set("score", random(90000)); 
    set_skill("unarmed", 150);
    set_skill("sword", 150);
    set_skill("force", 180);
    set_skill("parry", 140);
    set_skill("dodge", 140);
    set_skill("literate", 140);
    set_skill("move",200);
set("pubmaster",1);

        set_temp("apply/defense", 100);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
    set_skill("nine-moon-steps", 580);
    set_skill("nine-moon-claw", 500);
    set_skill("nine-moon-force", 550);
    set_skill("nine-moon-sword", 500); 
    map_skill("dodge", "nine-moon-steps");
    map_skill("unarmed", "nine-moon-claw");
    map_skill("force", "nine-moon-force");
    map_skill("sword", "nine-moon-sword");  

    setup();
    carry_object(__DIR__"obj/ghostyboots")->wear();
    carry_object(__DIR__"obj/ghostycloth")->wear();
    carry_object(__DIR__"obj/ghostygirth")->wear();
    carry_object(__DIR__"obj/ghostyribbon")->wear();
} 
void reset()
{
    delete_temp("learned");
    set("apprentice_available", 5);
} 

void init()
{
	object ob;
        ::init();
        add_action("do_killing", "kill");
                if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",3 , ob);
        }
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
        if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "shenshui"&& userp(victim)&&player!=victim)
        {
message_vision(HIW"$N对著$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
} 
int leave() {
        if (this_player()->query("class")!="shenshui") return 0;
        message_vision(CYN"$N冷笑了一声。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：想走可以，但从此不能在江湖上使用九阴神功。\n"NOR,this_object(),this_player());
        return 1;
} 
void punish_betray(object ob)
{
        if( ( ob->query("once_shenshui")) && ( (ob->query("class"))!= "shenshui"))
          {      
                tell_object(ob, YEL"\n水母阴姬对你冷笑道：“你既然判出本门，就不配再有本门的武功！”\n"NOR);              
                message("vision", "水母阴姬对"+ ob->name() +"冷笑道：“"+ ob->name() + "！ 你既然判出本门，就不配再有本门的武功！\n", environment(ob), ob);
           tell_object(ob, HIW"水母阴姬手一扬，一支牛毛般细小的飞针射入你灵台！\n"NOR);              
                message("vision", HIW"水母阴姬对着"+ ob->name() +"手一扬，射出一支牛毛般细小的飞针！\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("nine-moon-claw",1)) ob->delete_skill("nine-moon-claw");
                if (ob->query_skill("nine-moon-force",1)) ob->delete_skill("nine-moon-force");
                if (ob->query_skill("nine-moon-steps",1)) ob->delete_skill("nine-moon-steps");
                if (ob->query_skill("nine-moon-sword",1)) ob->delete_skill("nine-moon-sword");
                tell_object(ob, HIR"你只觉血脉一阵逆流，武功全失！！\n"NOR);
                ob->start_busy(10);
                ob->delete("once_shenshui");
  
          }
} 

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
