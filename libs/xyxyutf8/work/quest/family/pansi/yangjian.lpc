#include <ansi.h>
inherit SUPER_NPC;

int Die = 0;

void create()
{
        set_name("二郎真君", ({"erlang zhenjun", "erlang", "zhenjun"}));
        set("long", "他是赤城昭惠英灵圣，显化无边号二郎。
力伏八怪声名远，义结梅山七圣行。\n");
	set("looking", "仪容清俊貌堂堂，两耳垂肩目有光。");
        set("age", 28);
        set("attitude", "peaceful");
        set("gender", "男性");
        set("title", "昭惠灵显王");
        create_family("将军府", 2, "蓝");
        set("force_factor", 200);
        set("mana_factor", 200);
	set_level(40);
  	set_skill("literate",400);
  	set_skill("force",400);
  	set_skill("lengquan-force",400);
  	set_skill("parry",400);
  	set_skill("dodge", 400);
  	set_skill("yanxing-steps",400);
  	set_skill("unarmed", 400);
  	set_skill("changquan",400);
	set_skill("spear",400);
  	set_skill("bawang-qiang", 400);
	map_skill("force", "lengquan-force");
  	map_skill("unarmed", "changquan");
  	map_skill("spear", "bawang-qiang");
  	map_skill("parry", "bawang-qiang");
  	map_skill("dodge", "yanxing-steps");
	set("inquiry", ([ 
  		"here" : "我奉佛祖谕旨，正要捉拿青霞，紫霞二人。",
  		"name" : "我乃二郎神杨戬是也。",
	]) );
        setup();
}

void dies()
{
	object zixia,qingxia,who;

	who = query_temp("last_damage_from");
	if( !who || who!=query_temp("my_killer") 
	 || ( !present("qingxia xianzi") && !present("zixia xianzi") )
	 || !environment()
	 || !present(who,environment()) )
	{
		if( environment() )
			message("vision", "\n\n\n二郎神怒道：你莫要猖狂，待我到如来佛祖那里告状去！\n\n二郎神搭上白云，往西天灵山飞去。。。\n\n",environment());
		if( query_temp("invoker") )
		{    
			if( environment() )			
     				message("vision", "啸天犬也跟着二郎神往西逃去。\n\n", environment());
			destruct(query_temp("invoker"));
		}		
		if( who )
			CHANNEL_D->do_channel(this_object(),"chat",who->name()+	"！你莫要猖狂，待我到如来佛祖那里告状去！");
		destruct(this_object());
		return;
	}
	message_vision(WHT"\n\n战罢多久，青霞看着受了重伤的紫霞，紧紧的握着紫霞的手哽咽着说道：我也只有你这么一个妹妹，我们不要再斗下去了。二郎神已经去佛祖那里告状去了，我们也该回到佛祖那里继续作灯芯了，若是走晚了还要连累"+RANK_D->query_respect(who) + "被佛祖责怪。\n"NOR, who);
	message_vision(HIM"\n\n\n紫霞也紧紧的握着青霞的手止不住的泪水已经流了下来：这尘事已经没有什么可留恋的了，姐姐，我们走。\n\n\n"NOR, who);
   	message_vision("\n青霞搀着重伤的紫霞，两人对着$N再三拜谢后驾起云头往西天灵山去了．\n"NOR, who);
   	message_vision(HIY"\n\n\n$N仰天还礼，目送二人渐渐远去，一阵说不出的滋味涌上心头．．．．．．\n"NOR, who);
   	zixia = who->query_temp("pendding/fc_zixia");
   	if( zixia )
   		destruct(zixia);
   	qingxia = who->query_temp("pendding/fc_qingxia");
   	if( qingxia )
   		destruct(qingxia);
   	command("chat* crazy");
   	if( environment() )
		message("vision", "\n\n\n二郎神哈哈大笑道：灯芯事了，某这就去佛祖那里交差去！\n\n二郎神搭上白云，往西天灵山飞去。。。\n\n",environment());	
	if( query_temp("invoker") )
	{    
		if( environment() )			
     			message("vision", "啸天犬也跟着二郎神往西飞去。\n\n", environment());
		destruct(query_temp("invoker"));
	}
	message_vision("\n\n片刻过后，但见金灵圣母与紫青二仙在云端现出真容。\n\n",who);
	message_vision(CYN"金灵圣母说道：此番用偷天换日之法，倒也让两位仙子避开了眼前的祸端。\n"NOR,who);
	message_vision(CYN"金灵圣母由衷地向$N"CYN"道谢。\n"NOR,who);
	message_vision(CYN"青霞仙子由衷地向$N"CYN"道谢。\n"NOR,who);
	message_vision(CYN"紫霞仙子由衷地向$N"CYN"道谢。\n"NOR,who);	
   	who->set_temp("pendding/fc_visite_pansikill",1);
	set("channel_id","金灵圣母(Jinling shengmu)");
	CHANNEL_D->do_channel(this_object(),"chat",who->name()+"助紫青二仙暂避了佛门追杀，当真功德无量也。");
	if( base_name(environment())=="/quest/family/pansi/hgs" )
	{
		if( !environment()->query("exits") )
			environment()->set("exits/down","/d/pansi/hubian");
	}
	destruct(this_object());
}

void die()
{
	object me = this_object();
	if( Die>0 )
		return;
	QUEST_D->addEffKee(me);
	QUEST_D->addKee(me);
	QUEST_D->addSen(me);
	QUEST_D->addEffSen(me);
	if( query("kee")<1 || query("sen")<1 
	 || query("eff_kee")<1 || query("eff_sen")<1 )
	{
		Die = 1;
		dies();
		return;
	}	 
}

void unconcious()
{
	die();
}