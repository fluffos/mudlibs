//long 须眉全白，脸色红润，有如孩童
//Xiakedao NPC
//modified by aiai on 6/3/1999

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <title.h>
//#include "/u/aiai/create_menpai/creat_menpai.h"
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();
void heal();
int check_legal_title(string arg , object me);

void create()
{
        set_name("木剑封", ({"mu jianfeng", "mu", "jianfeng"}));
	set("nickname", RED"与世无争"NOR);
	set("title",GRN "侠客岛" NOR + YEL "岛主" NOR);
	set("gender", "男性");
	set("age", 120);
	set("long", "此人长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。到底多大年纪，\n"
		"委实看不出来，总是在六十岁到九十岁之间，如说已年过百岁，也不希奇。\n");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 80);
	set("int", 80);
	set("con", 80);
	set("dex", 80);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("chat_chance", 10);
	set("chat_msg", ({
		(: heal :),
	}));
	
	
	set("max_qi", 10000);
	set("max_jing",10000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 400);
	
	set("combat_exp", 5000000);
	set("score", 500000);
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: consider() :)
	}) );
	
	set("inquiry", ([
		"" : (: ask_me :),
        ]) );
	
	set_skill("force", 500);
	set_skill("strike", 500);
	set_skill("xiake-strike", 500);
	set_skill("dodge", 500);
	set_skill("xiake-shenfa", 500);
	set_skill("literate", 500);
	set_skill("xiake-shengong",500);
	set_skill("literate", 500);
	set_skill("xiake-jianfa",500);
	set_skill("sword",500);
	set_skill("xiake-daofa",500);
	set_skill("blade",500);
	set_skill("throwing",500);
	map_skill("strike", "xiake-strike");
	map_skill("dodge", "xiake-shenfa");
	map_skill("force","xiake-shengong");
	map_skill("sword","xiake-jianfa");
	map_skill("blade","xiake-daofa");
	map_skill("parry","xiake-jianfa");
	prepare_skill("strike", "xiake-strike");
	
	create_family("侠客岛",1,"岛主");
	
	setup();
	//      carry_object("")->wield();
	//      carry_object("")->wear();
}

void init()
{
	::init();
//        add_action("do_create","create");
	add_action("do_dismiss","dismiss");
	add_action("do_bihua", "bihua");
	add_action("do_bihua", "fight");
	add_action("do_none",  "hit");
	add_action("do_none",  "kill");
	add_action("do_none",  "steal");
	add_action("do_none",  "yun");
	add_action("do_none",  "exert");
	add_action("do_none",  "perform");
	add_action("do_none",  "yong");
}

int do_none(string arg)
{
	object ob;
	ob = this_player();
	
	if ( ( arg == "mu jianfeng") || ( arg == "jianfeng") || ( arg == "all") ) 
        tell_object(ob,"木剑封不愿与你动手。\n");
	else command("say " + "大家切磋切磋武艺可以，何必真的动手呢?\n");
	return 1;
	
}

void attempt_apprentice(object ob)
{
	string callname;
	callname = RANK_D->query_respect(ob);
	
	command("say 我木某有生之年不会收徒弟了,但这个岛上有一处秘密所在可供修炼,"+callname+"可以自行方便。\n");
	return ;
}       

void consider()
{
	object *enemy,target;
	enemy = query_enemy() - ({ 0 });
	target = enemy[random(sizeof(enemy))];
	switch( random(2) )
	{
	case 0:
		command("yun qiankun " + target->query("id"));
		break;
	case 1:
		command("yun qiankun " + target->query("id"));
		break;
	}
}

void heal()
{
	object ob=this_object();
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 400");
		return;
	}
	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");
	return;
}

int do_bihua(string arg)
{
	object ob1, ob2;
	ob1 = this_player();
	ob2 = this_object();
	
	if( !arg || arg=="" ) return 0;
	
	if ( arg != "mu jianfeng" && arg != "jianfeng" )
	{
		command("say " + "大家切磋切磋武艺可以，何必真的动手呢?\n");
		return 1;
	}
	
	return 0;
}       
int do_create(string arg)
{
	string file,*menpai=({});
	object me;
	int i ,size;
	me=this_player();
	if(!arg) return notify_fail(HIW"你要创立什么门派？\n"NOR);
	if(!file=read_file("/menpai/exist")) return 0;
	menpai=explode(file,"\n");
	size=sizeof(menpai);
	for( i = 0;i < size; i ++)
	{
		if(arg==menpai[i]) return notify_fail("你想加入"+arg+"吗？\n");
	}
	if(me->query("repute")<1000000) return notify_fail(HIW"你一个无名小卒，还想什么开宗立派啊？\n"NOR);
	if(me->query("balance")<100000000) return notify_fail(HIW"你的家底太小了，不足以在江湖上维持门面。\n"NOR);
	me->set_temp("marks/自创门派",1);
	if(me->query("自创门派",1))
		return notify_fail(HIW"你以为你有多大本事，可以独自统领两大帮派？\n"NOR);
	if(me->query("family",1))
		write(HIW"你真的要脱离原来的门派并创立"+arg+"吗？(y/n):"NOR);
	else
		write(HIW"你真的要创立"+arg+"吗？(y/n):"NOR);
	me->set_temp("marks/门派名称",arg);
	input_to("confirm_create",me);
	return 1;
}
protected void confirm_create(string arg, object me)
{
	string file;
	if( arg=="")
	{
		write(HIW"你真的要脱离原来的门派并创立"+arg+"吗？(y/n):"NOR);
		input_to("confirm_create", me);
		return;
	}
	if( arg[0]!='y' && arg[0]!='Y' ) {
		write(HIW"这位"+RANK_D->query_respect(me)+HIW+"还是下次再来吧。\n"NOR);
		me->delete_temp("marks/自创门派");
		me->delete_temp("marks/门派名称");
		return;
	}
	me->set("自创门派/开山祖师",1);
	me->set("自创门派/门派名称",me->query_temp("marks/门派名称",1));
        me->set("generation",1);
        me->set("menpai/gen",1);
	if(!file=read_file("/menpai/exist")) return 0;
        file="\n"+me->query("自创门派/门派名称",1);
        if(!write_file("/menpai/exist",file,0)) return 0;
	me->delete("family");
	me->delete_temp("marks/自创门派");
	me->delete_temp("marks/门派名称");
	write(HIW"你可以自己设置你的title(<颜色> <字符> ...):\n"NOR);
	input_to("get_title",me);
}
protected void get_title(string arg, object me)
{
	if(arg=="") 
	{
		write(HIW"你可以自己设置你的title(<颜色> <字符> ...):\n"NOR);
		input_to("get_title",me);
		return;
	}
	if( !check_legal_title(arg , me) ) 
	{
		write(HIW"你的输入有误，请重试。\n"NOR);
		write(HIW"\n请重新设置你的title(<颜色> <字符> ...):\n"NOR);
		input_to("get_title",me);
		return;
	}
	return;
}
int check_legal_title(string arg , object me)
{
	int i , j , size , length ;
	string *title = ({}) , cTitle;
	object obj;
	title = explode(arg," ");
	size = sizeof(title);
	cTitle = " ";
	for( i = 0 ; i < size ; i ++)
	{
		if(title[i][0]=='$')
		{
			for( j = 0 ; j < 5 ; j ++ )
			{
				if( (title[i][j]<'A'|| title[i][j]>'Z') && title[i][j]!='$')
					return 0;
			}
			if(title[i]=="$HIR$")
				cTitle+=HIR;
			else if(title[i]=="$HIG$")
				cTitle+=HIG;
			else if(title[i]=="$HIC$")
				cTitle+=HIC;
			else if(title[i]=="$HIY$")
				cTitle+=HIY;
			else if(title[i]=="$HIW$")
				cTitle+=HIW;
			else if(title[i]=="$HIM$")
				cTitle+=HIM;
			else if(title[i]=="$HIB$")
				cTitle+=HIB;
			else if(title[i]=="$RED$")
				cTitle+=RED;
			else if(title[i]=="$BLU$")
				cTitle+=BLU;
			else if(title[i]=="$GRN$")
				cTitle+=GRN;
			else if(title[i]=="$CYN$")
				cTitle+=CYN;
			else if(title[i]=="$WHT$")
				cTitle+=WHT;
			else if(title[i]=="$BLK$")
				cTitle+=BLK;
			else if(title[i]=="$NOR$")
				cTitle+=NOR;
			else if(title[i]=="$YEL$")
				cTitle+=YEL;
			else if(title[i]=="$MAG$")
				cTitle+=MAG;
			else if(title[i]=="$BNK$")
				cTitle+=BNK;
			else
				return notify_fail("对不起，这里没有你想要的颜色。");
		}
		else
		{
			length=strwidth(title[i]);
			while(length--)
			{
				if( !is_chinese(title[i][length..<0]) )
					return notify_fail("对不起，请您用「中文」取名字。\n");
			}
			cTitle+=(string)title[i];
		}
	}
	me->set("title",cTitle+NOR);
//title系统记录玩家title by seagate@pkuxkx
  me->set_title(TITLE_RANK, me->query("title"));
	write("\n");
        message( "channel:" + "chat",HIW + "【新闻】：『" + me->query("title",1)+HIW+" 』"+me->query("name") + "于今日创立了"+me->query("自创门派/门派名称",1)+HIW+"，真是可喜可贺!\n"NOR,users());
        if ( write_file("/hate/"+me->query("自创门派/门派名称",1),"侠客岛 0",0))
        {
                write("无法创建文件。\n");
                return 1;
        }
        me->create_family(me->query("自创门派/门派名称",1),1,title);
        return 1;
}
