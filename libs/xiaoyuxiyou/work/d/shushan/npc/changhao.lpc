#include <ansi.h>
inherit SUPER_NPC;

mixed chu_jia();
string expell_me(object me);
string ask_mieyao();
string ask_cancel();

void create()
{
        set_name("常浩", ({ "chang hao", "chang" }));
        set("long", "他是蜀山派年轻一代中的佼佼者，后来所收徒弟出了意外，颇有些意兴索然。不过最近又收了一名资质不凡的徒儿，心情稍微好了一些。所以出山帮助师兄管理一些新进弟子日常。\n");
        set("gender", "男性");
        set("age", 40);
        set_level(90);
        set("attitude", "peaceful");
        set("class","taoist");
        
        set("force_factor", 160);
        set("mana_factor", 250);

        set_skill("spells",900);
        set_skill("force", 900);
        set_skill("dodge", 900);
        set_skill("parry", 900);
        set_skill("sword", 900);
        set_skill("xianfeng-yunti", 900);
        set_skill("zuixian-wangyue", 900);
        set_skill("chuanyun-zhang", 900);
        set_skill("literate", 900);
        set_skill("unarmed", 900);
	set_skill("yujianshu", 900);
        set_skill("tianshi-fufa",900);
        map_skill("spells", "tianshi-fufa");
        map_skill("dodge", "zuixian-wangyue");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");
        set_skill("jiefeng",900);
	set_skill("jianshu",900);
	set_skill("zhili",900);
	
        create_family("蜀山派", 4, "四代弟子");
        set("env/wimpy",10);
	set("env/test","HIR");
	set_temp("weapon_level",40+random(40));
	set_temp("armor_level",40+random(40));    
        
        set("inquiry",([
        	"出家" : (: chu_jia :),
        	"leave": (: expell_me :),
	   	"kill": (: ask_mieyao :),
	   	"师门任务": (: ask_mieyao :),
	    	"cancel": (: ask_cancel :),        	
        ]));	
        setup();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"sword",random(3))->wield();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"armor",random(2))->wear();
}

string expell_me(object me)
{       
	me=this_player();
	if((string)me->query("family/family_name")=="蜀山派") 
	{
		tell_object(me,CYN+name()+CYN"说道：你既是执意下山，我却有几句话说。\n"NOR);
		me->set_temp("betray", "shushan");
		return ("脱离师门要需要有一定惩罚，你可愿意(agree)？");
	}
	return ("问什么问！自己想去！\n");
}

void init()
{
	::init();
	add_action("do_agree","agree");
}

int do_agree(string arg)
{
	if( this_player()->query_temp("betray")=="shushan"
	 && this_player()->query("family/family_name") == "蜀山派" )
	{
		if( FAMILY_D->leave_family(this_player(),this_object()) )
		{
			message_vision("$N答道：弟子愿意。\n\n", this_player());
			command("say 既然与我蜀山派无缘，你便下山去吧！");
			return 1;
		}
	}
	return 0;
}

mixed chu_jia()
{
	int i;
	mapping nn;
	string name,arg,daohao;
	object me = this_player();
	
	if( me->query("class") 
	 && me->query("class")!="taoist" )
		return "这位"+RANK_D->query_respect(me)+"莫要开玩笑。";
	if( me->query("taoist/class") 
	 && me->query("taoist/old_name") )
	{
		if( me->query("taoist/class")=="shushan" )
		{
			i = this_object()->query("family/generation")-me->query("family/generation");
			if( i<-1 )
				arg = "你这刁蛮徒孙";
			else if( i<0 )
				arg = "这位师侄";
			else if( i==0 )
				arg = "这位师弟";
			else if( i==1 )
				arg = "师叔";
			else	arg = "您老人家";
			return arg+"莫要消遣我。";
		}
		else	return me->query("name")+"道长，你在其他宝山出家了，莫要来消遣贫道。";
	}
	message_vision("$N点了点头。\n");
	i = me->query("family/generation");
	i = 2-i;
	if( i>=1 )
		name = "清";
	else if( i==0 )
		name = "常";
	else if( i==-1 )
		name = "守";
	else if( i==-2 )
		name = "宁";
	else	name = "阳";
	message_vision("$N朝$n点了点头：我蜀山以『"HIG"清、常、守、宁、阳"NOR"』排辈，以你的资历，便为「"HIG+name+NOR"」字辈吧。\n",this_object(),me);
	nn = NAME_D->random_name2((me->query("gender")=="女性"?1:0), -1, name, 0, 0);
	name = nn["name"];
	
	CHANNEL_D->do_channel(this_object(),"chat","近日，"+me->query("name")+"于我川中蜀山之巅，归化三清，行冠巾之仪，道名「"+name+"」。");
	me->set("taoist/old_name", me->query("name"));
	me->set("name", name);
	me->set("taoist/class", "shushan");
        me->set("class", "taoist");
        me->save(1);
        message_vision("$N朝$n点了点头：今日你入我三清，道名「"+name+"」，日后，便须放下世间一切。\n",this_object(),me);
        return 1;
}

string ask_mieyao()
{
    	object who=this_player();
    	if((string)who->query("family/family_name")=="蜀山派") 
    	{
      		EMOTE_D->do_emote(this_object(), ({"addoil","touch","ok"})[random(3)],geteuid(who),CYN,0,0,0);
      		return "/quest/family/mieyao"->query_yao(who);
    	}
    	return ("非我门人,何故来此?\n");
}

string ask_cancel()
{
	if( this_player()->query("family/family_name")!="蜀山派" )
		return 0;
	return "/quest/family/mieyao"->cancel_me(this_player());	
}