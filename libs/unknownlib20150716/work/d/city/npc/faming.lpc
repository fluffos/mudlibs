inherit NPC;
#include <ansi.h>

mixed check_maze();
mixed check_maze2();

void create()
{
        set_name("法明长老", ({"faming zhanglao","monk", "faming","zhanglao"}));
        set_level(39);
        set("long","法明长老是化生寺的主持，神色庄重，举止间自有一番威仪。
听说他有一身武艺，也能呼风唤雨，却不传授于寺里的和尚。\n");
	set("title", "主持");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");
        set("age", 55);
        set("force_factor", 40);
	set("mana_factor", 30);

        set("shen_type", 1);

        set("eff_dx", 90000);
        set("nkgain", 300);

        set_skill("force", 390);
        set_skill("unarmed", 390);
        set_skill("dodge", 390);
	set_skill("jienan-zhi", 390);
        set_skill("parry",390);
	set_skill("spells", 390);
	set_skill("buddhism", 390);
	map_skill("unarmed", "jienan-zhi");
	map_skill("spells", "buddhism");
	
	set("inquiry", ([
		"小雁塔" : (: check_maze :),
		"大雁塔" : (: check_maze2 :),
	]));
        setup();
        carry_object("/d/obj/cloth/monkcloth")->wear();
}

mixed check_maze()
{
	object fo,me = this_player();
	if( !userp(me) )
		return 0;
	if( !wizardp(me) && !me->query("env/test") )
	{		
		if( me->query_level()<25 )
			return "阿弥陀佛，这几日情况越来越危急了，看来贫僧要去南海请师兄帮忙了。";
		if( me->query_level()>30 )
			return "阿弥陀佛，此等芥子琐事哪敢劳烦"+RANK_D->query_respect(me)+"。";
		if( time()<me->query("maze/xiaoyan-ta")+1800 )
			return "阿弥陀佛，此事多多劳烦"+RANK_D->query_respect(me)+"了，还是歇歇再去。";
	}				
	if( objectp(fo=present("jin fo",me))
	 && base_name(fo)=="/d/maze/xiaoyan-ta/obj/fo" )
	 	return "阿弥陀佛，事不宜迟，"+RANK_D->query_respect(me)+"这就动身。";
	if( !me->query_temp("pending/faming_ask") )
	{	 	
		message_vision("$N长眉紧皱，好似有些心事。\n",this_object());
		if( me->query("class")=="bonze" )
			tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，这位师弟，化生寺今遭怕是有了劫难。\n"NOR);
		else	tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，这位檀越，化生寺今遭怕是有了劫难。\n"NOR);	
		EMOTE_D->do_emote(this_object(), "sigh",geteuid(me),CYN,0,0,0);	
		message_vision(CYN"$N"CYN"很疑惑地看着$n"CYN"。\n"NOR,me,this_object());
		tell_object(me,CYN+name()+CYN"说道：唉，城南小雁塔乃是为迎真经而建。此佛门盛事也，长安各沙门遂轮流打理。\n"NOR);
		tell_object(me,CYN+name()+CYN"说道：今岁为吾寺所值。不想，前些日休憩之际意外发现塔下另有玄机。\n"NOR);
		message_vision(CYN"$N"CYN"对着$n"CYN"惊讶地“啊”了一声。\n"NOR,me,this_object());
		tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，塔下有修仙古址，期间禁制大多破败，虽经寺中长老多次加持，但这几日洞内好似有些古怪。\n"NOR);
		me->set_temp("pending/faming_ask",1);
	}
	tell_object(me,CYN+name()+CYN"说道：还望"+RANK_D->query_respect(me)+"加以援手，前往探查，此功德之事，鄙寺不胜感激，不知你可愿意(agree)？\n"NOR);
	return 1;
}

void init()
{
	add_action("do_agree","agree");
}

int do_agree()
{
	object fo,me = this_player();
	if( me->query_temp("pending/faming_ask") )
	{
		EMOTE_D->do_emote(this_object(), "thank",geteuid(me),CYN,0,0,0);
		if( objectp(fo=present("jin fo",me))
	 	&& base_name(fo)=="/d/maze/xiaoyan-ta/obj/fo" )
	 		;
	 	else
	 	{
	 		fo = new("/d/maze/xiaoyan-ta/obj/fo");
	 		if( !fo->move(me) )
	 		{
	 			tell_object(me,HIR"【系统】你的背包满了。\n"NOR);
	 			if( fo ) destruct(fo);
	 		}
	 		else
	 		{
	 			tell_object(me,name()+"将一尊"+fo->name()+"递给你。\n"NOR);
	 			tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，凭此金佛，你去小雁塔自有门下弟子打理。\n"NOR);
	 			EMOTE_D->do_emote(this_object(), "thank",geteuid(me),CYN,0,0,0);
	 		}
	 	}	
	}
	else if( me->query_temp("maze/faming_ask2") )
	{
		EMOTE_D->do_emote(this_object(), "thank",geteuid(me),CYN,0,0,0);
		tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，你速速前往慈恩寺内，自有寺中僧侣打理。\n"NOR);
	}
	return 0;
}

mixed check_maze2()
{
	object fo,me = this_player();
	if( !userp(me) )
		return 0;
	if( !wizardp(me) && !me->query("env/test") )
	{		
		if( me->query_level()<30 )
			return "阿弥陀佛，这几日情况越来越危急了，看来贫僧要去南海请师兄帮忙了。";
		if( me->query_level()>39 )
			return "阿弥陀佛，此等芥子琐事哪敢劳烦"+RANK_D->query_respect(me)+"。";
		if( time()<me->query("maze/dayan-ta")+1800 )
			return "阿弥陀佛，此事多多劳烦"+RANK_D->query_respect(me)+"了，还是歇歇再去。";
	}				
	if( !me->query_temp("maze/faming_ask2") )
	{	 	
		message_vision("$N长眉紧皱，好似有些心事。\n",this_object());
		if( me->query("class")=="bonze" )
			tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，这位师弟，慈恩寺今遭怕是有了劫难。\n"NOR);
		else	tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，这位檀越，慈恩寺今遭怕是有了劫难。\n"NOR);	
		EMOTE_D->do_emote(this_object(), "sigh",geteuid(me),CYN,0,0,0);	
		message_vision(CYN"$N"CYN"很疑惑地看着$n"CYN"。\n"NOR,me,this_object());
		tell_object(me,CYN+name()+CYN"说道：唉，慈恩寺乃是为迎真经而建。此佛门盛事也。\n"NOR);
		tell_object(me,CYN+name()+CYN"说道：前些日小雁塔下拜火邪教肆虐，不想近日得知祸及大雁塔了。\n"NOR);
		message_vision(CYN"$N"CYN"对着$n"CYN"惊讶地“啊”了一声。\n"NOR,me,this_object());
		tell_object(me,CYN+name()+CYN"说道：阿弥陀佛，慈恩寺值守和尚近日发现大雁塔下地宫之内有邪教徒出没。\n"NOR);
		me->set_temp("maze/faming_ask2",1);
	}
	tell_object(me,CYN+name()+CYN"说道：还望"+RANK_D->query_respect(me)+"加以援手，前往探查，此功德之事，鄙寺与慈恩寺不胜感激，不知你可愿意(agree)？\n"NOR);
	return 1;
}