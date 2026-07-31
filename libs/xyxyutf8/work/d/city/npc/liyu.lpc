#include <ansi.h>
inherit NPC;

mixed fan_me();
mixed maze_me();

void create()
{
        set_name("李玉娘", ({"li yuniang", "li"}));
        set("age", 28);
        set_level(5);
        set("gender", "女性");
        set("long","李玉娘是袁天罡的老婆，正在洗菜做饭。\n");
        set("attitude", "friendly");
	set("per", 25);

        set("shen_type", 1);
        set_skill("unarmed", 20);
	set_skill("parry", 20);
        set_skill("dodge", 40);
        set("inquiry", ([
		"袁天罡": "气死人了，这么晚了也不回家吃饭！也找不到个人把饭送去！\n",
		"送饭": (: fan_me :),
		"烦心事" : (: maze_me :),
	]));
	setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
}

mixed fan_me()
{	
	object he,me,who;
	me = this_object();
	who=this_player();
	
	if( !wizardp(who) && (who->query_level()<10 || who->query_level()>25) )
		return "这天黑路远的，算了吧，多谢了！\n";
	if( time()<who->query("maze/beiyin")+1800 )
		return "老是麻烦你，也不好意思。\n";
	else
	{
		he = carry_object("/d/city/obj/fanhe");
		if( he && he->move(who) )
			message_vision("$N递给$n一个热乎乎的饭盒。\n",me,who);
		else	return "还是我自己送去吧。";
		message_vision(CYN"$N说道：多谢了，快去吧！\n"NOR,me);
		return 1;
	}
}

void die()
{
	powerup(0,1);
}

void unconcious()
{
        die();
}

void kill_ob(object who)
{
	message_vision("$N摇了摇头。\n",this_object());
	this_object()->remove_killer(who);
	who->remove_killer(this_object());
}

mixed maze_me()
{
	object who = this_player();
	
	if( !who->query_temp("maze/beiyin_asked") )
		return "奴家的心事你不知啊你不知。";
	if( !wizardp(who) 
	 && (who->query_level()<10 && who->query_level()>25) )
		return "那些天杀的。";
	if( who->query_temp("pending/beiyin_ok") )
		return (who->query("gender")=="女性"?"妹妹":"叔叔")+"事不宜迟，现在就动身吧，出门望南便是。";		
	if( who->query_temp("pending/beiyin") )
		return (who->query("gender")=="女性"?"妹妹":"叔叔")+"到底是答不答应奴家(agree)？";	
	who->set_temp("pending/beiyin",1);	
	EMOTE_D->do_emote(this_object(), "wuwu",geteuid(who),CYN,0,0,0);
	message_vision("$N抹了抹眼泪，朝$n楚楚地看了一眼。\n",this_object(),who);
	message_vision(CYN"$N说道：久来都城，本来也无甚烦恼事。奈何最近巷子内新立个帮会，闹得街坊里乌烟瘴气，奴家很是闹心。\n"NOR,this_object());
	message_vision(CYN"$N抹了抹眼泪，接着道：这些琐事也想让相公知道，挠他前程。\n"NOR,this_object());
	message_vision(CYN"$N朝$n"NOR CYN"看了一眼，羞涩说道：我见这位"+RANK_D->query_respect(who)+"是个古道热肠的"+(who->query("gender")=="女性"?"女":"")+"汉子，不知是否愿意(agree)为奴家跑一趟，去杀杀那些泼户的威风？\n"NOR,this_object(),who);
	return 1;
}

void init()
{
	::init();
	add_action("do_agree","agree");
}

int do_agree()
{
	object who = this_player();
	if( !who->query_temp("pending/beiyin") )
		return 0;
	if( who->query_temp("pending/beiyin_ok") )
		return err_msg("事不宜迟，现在就动身吧，出门望南便是。\n");		
	if( who->query("gender")=="女性" )
		message_vision("$N霸气侧漏的朝$n点了点头：姐姐，这事就放在我身上，我这就去办了他们！\n",who,this_object());
	else	message_vision("$N将自己的胸脯拍得砰砰作响，朝$n道：嫂嫂，这事就放在我身上，我这就去办了他们！\n",who,this_object());
	who->set_temp("pending/beiyin_ok",1);
	return 1;
}