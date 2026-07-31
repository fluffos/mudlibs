#include <ansi.h>
inherit NPC;

string maze_meishan();

void create()
{
  set_level(90);	
  set_name("张伯时", ({ "zhang boshi", "zhang", "taiwei" }) );
  set("gender", "男性" );
  set("long", "张伯时是梅山七兄弟中的老五。\n");
  set("title", "梅山太尉");
  set("age", 35);
  set("attitude", "peaceful");
  set("str", 25);
  set("int", 25);
  set("force_factor", 20);
  set("mana_factor", 20);
  set_skill("unarmed",800);
  set_skill("dodge",900);
  set_skill("parry", 900);
  set_skill("blade",900);
  set_skill("force",900);
  set("inquiry", ([ 
  	"梅山" : (: maze_meishan :),
  ]));	
  setup();
  carry_object("/d/obj/armor/yinjia")->wear();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  add_temp("apply/max_kee",50000);
  add_temp("apply/max_sen",50000);
  powerup();
}

string maze_meishan()
{
	int i;
	object *t,me = this_player();
	if( me->query_level()<80 && !wizardp(me) )
		return "以你这样的修为，现在去还是很勉强。";
	if( me->query_level()>119 && !wizardp(me) )
		return "怎敢劳您大驾。";	
	if( time()<me->query("maze/meishan")+3600 && !wizardp(me) )
		return "你刚刚不是过去吗？";
	if( pointerp(t=me->query_team()) )
	{
		if( me!=me->query_leader() )
			return "这事还得和"+(me->query_leader())->name()+"说。";
		if( sizeof(t)<2 )
			return "你的队伍人数不够。";	
		for(i=0;i<sizeof(t);i++)
		{
			if( t[i]->query_level()<80 && !wizardp(t[i]) )
				return "以"+t[i]->name()+"这样的修为，现在去还是很勉强。";
			if( t[i]->query_level()>119 && !wizardp(t[i]) )
				return "怎敢劳"+t[i]->name()+"大驾。";	
			if( time()<t[i]->query("maze/meishan")+3600 && !wizardp(t[i]) )
				return t[i]->name()+"刚刚不是过去吗？";	
		}	
	}		
		
	message_vision("$N点了点头，说道：近日，一干精怪在梅山一带大肆喧嚣。奈何其中好似与天宫几位星君有些关系，我等也不好出手。我家爷爷虽没说什么，我们兄弟却还是要做些事。\n",this_object());
	message_vision("$N说道：我等不好出手，也只能劳烦"+RANK_D->query_respect(me)+"出手除掉这些破劳祸，也好还我梅山的清净。\n",this_object());
	me->delete_temp("maze");
	if( MAZE_D->enter_maze(me, "meishan") )
	{
		me->set_temp("maze/meishan",1);
		me->set_temp("maze_dir","meishan");
		if( pointerp(t=me->query_team()) )
		{
			if( me==me->query_leader() )
				CHANNEL_D->do_channel(this_object(),"rumor","听说"HIY+me->name()+HIM"带领一干人闯入了"HIR"梅山七圣"HIM"副本。"NOR);
			message("team",HIW"【组队】"+me->name()+"已进入"HIY"梅山七圣"HIW"副本。"NOR"\n",t);
		}
		else	CHANNEL_D->do_channel(this_object(),"rumor","听说"HIY+me->name()+HIM"单枪匹马闯入了"HIR"梅山七圣"HIM"副本。"NOR);		
		return "拜托了。";
	}
	else	return "还是准备好了再来吧。";		
}