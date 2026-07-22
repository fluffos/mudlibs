//created 5-20-97 pickle
#include <ansi.h> 
inherit SUPER_NPC;

string ask_mieyao();
string ask_cancel();

void create()
{
	set_name("黄飞虎", ({"huang feihu", "huang", "feihu", "huangfeihu"}));
  	set("long", @LONG
开国武成王黄飞虎，兴周第一大将，封神榜
上五岳之首东岳泰山大齐仁圣大帝，下凡寻
找其五色神牛的下落。
LONG);
 	create_family("火云洞", 1, "蓝");
  	set("title", "东岳泰山大齐仁圣大帝");
  	set("gender", "男性");
  	set_level(150);
  	set("age", 43);
  	set_skill("spear",1500);
  	set_skill("force", 1500);
  	set_skill("dodge", 1500);
  	set_skill("literate", 1500);
  	set_skill("parry", 1500);
  	set_skill("unarmed", 1500);
	set_skill("wuyue-spear",1500);
	set_skill("spells", 1500);
	set_skill("pingtian-dafa", 1500);
  	set_skill("moshenbu", 1500);
  	set_skill("huomoforce", 1500);
  	set_skill("moyun-shou", 1500);
	map_skill("force", "huomoforce");
	map_skill("spells", "pingtian-dafa");
  	map_skill("unarmed", "moyun-shou");
  	map_skill("spear", "wuyue-spear");
  	map_skill("parry", "wuyue-spear");
  	map_skill("dodge", "moshenbu");

	set_skill("jiefeng",1500);
	set_skill("qiqing",1500);
	set_skill("tuyan",1500);	  	
  	set_skill("huifeng-fanhuo",1500);
  	
	set("force_factor",130);
	set("mana_factor", 150);
	set("inquiry", ([
        	"cancel": (: ask_cancel :),
     		"kill": (: ask_mieyao :),
	]) ); 
  	set("env/test","HIR");
	setup();
	carry_object(0,"armor",1)->wear();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"kui",1)->wear();
	carry_object(0,"shoes",1)->wear();
	carry_object(0,"pifeng",1)->wear();
	carry_object(0,"waist",1)->wear();
	carry_object(0,"spear",1)->wield();
	powerup(0,1);
}

int prevent_learn(object who,string skill)
{
	if( skill=="huifeng-fanhuo" )
	{
		if( who->query_level()<120 )
			return err_msg(name()+"朝你摇了摇头：你这点修为，不要侮辱了吾之神通。\n");
        }
        if( skill=="tuyan") 
        {
		if( who->query_level()<90 )
			return err_msg(name()+"朝你摇了摇头：你这点修为，不要侮辱了吾之神通。\n");
        }
        if( skill=="qiqing" )
        {
        	if( who->query_level()<80 )
        		return err_msg(name()+"朝你摇了摇头：你这点修为，不要侮辱了吾之神通。\n");
        }
	return 0;
} 
 
int accept_fight(object me)
{
  	command("say 老夫手重，若是伤人反而不美了。\n");
  	return 0;
}

int attempt_apprentice(object ob)
{
	if( ob->query("class")=="bonze" )
        {
		EMOTE_D->do_emote(this_object(), "pei",geteuid(ob),CYN,0,0,0);
           	tell_object(ob,CYN+name()+CYN"说道：老夫不收和尚。\n"NOR);
           	return 0;
        }	
	if( (string)ob->query("family/family_name")=="火云洞" ) 
	{
		if( ob->query_level()<20 )
		{
			EMOTE_D->do_emote(this_object(), "shake",geteuid(ob),CYN,0,0,0);
           		tell_object(ob,CYN+name()+CYN"说道：" + RANK_D->query_respect(ob) +"还是先去打好基础再来。\n"NOR);
   			return 0;
   		}
   		EMOTE_D->do_emote(this_object(), "haha",geteuid(ob),CYN,0,0,0);
		if( ob->query_level()<60 )
		{
			create_family("火云洞", 3, "蓝");
  			set("title", HIY"东岳泰山大齐仁圣大帝"NOR);
  			tell_object(ob,CYN+name()+CYN"说道：恩，我便收你作个记名的徒弟，传你些功夫！\n"NOR);			
		}
		else if( ob->query_level()<120 )
		{
			create_family("火云洞", 2, "蓝");
  			set("title", HIY"东岳泰山大齐仁圣大帝"NOR);
  			tell_object(ob,CYN+name()+CYN"说道：看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他K到没道行！\n"NOR);
		}
		else
		{
			create_family("火云洞", 1, "蓝");
  			set("title", HIY"东岳泰山大齐仁圣大帝"NOR);	
  			tell_object(ob,CYN+name()+CYN"说道：看你的身手，象是见过我那孽畜，我传你些功夫，你去帮我把他K到没道行！\n"NOR);		
		}		
		command("recruit " + ob->query("id") );
		return 1;
	}
	EMOTE_D->do_emote(this_object(), "?",geteuid(ob),CYN,0,0,0);
	tell_object(ob,CYN+name()+CYN"说道：老夫受人之托，只收火云洞的弟子。\n"NOR);
       	return 0;
}

string ask_mieyao()
{
    	object who=this_player();
    	if((string)who->query("family/family_name")=="火云洞") 
    	{
      		EMOTE_D->do_emote(this_object(), ({"addoil","touch","ok"})[1],geteuid(who),CYN,0,0,0);
      		return "/quest/family/mieyao"->query_yao(who);
    	}
    	return ("非我门人,何故来此?\n");
}

string ask_cancel()
{
	if( this_player()->query("family/family_name")!="火云洞" )
		return 0;
	return "/quest/family/mieyao"->cancel_me(this_player());	
}

void init(){}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        {
                ob->set("class", "yaomo");
        }
        create_family("火云洞", 1, "蓝");
  	set("title", HIY"东岳泰山大齐仁圣大帝"NOR);
}
