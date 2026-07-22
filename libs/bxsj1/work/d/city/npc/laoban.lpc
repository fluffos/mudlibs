// laoban.c		地下赌场老板
// created by kaol 2003/9/27
// modified by campsun 2003/9/28

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
inherit F_BANKER;

int ask_match();
int ask_gold();
int ask_betrate();
int ask_convert();

void create()
{
    set_name( "黄富霸", ({ "huang fuba","huang","fuba" }) );
    set("gender", "男性");
    set("title", HIB"地下黑拳市兼地下钱庄头号老板"NOR);
    set("age", 45);
    set("long", "他就是这家隐蔽的地下黑拳市兼地下钱庄头号老板。\n"
				"他双目圆睁，冷静地打量着围观拳赛的每一个人。\n"
				"他心狠手辣，毫不在乎参赛拳手的生死。\n"
				"你可以向他打听有关比赛的进展情况(match)以及压注的情况(gold)。\n"
				);
        set("unique", 1);
        set("no_bark", 1);
        set("job_npc", 1);
        set("no_ansuan", 1);
        set("get", 1);

	set("str", 30);
    	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 7);
	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);
	set("shen_type", 1);
	set_skill("unarmed",100);
	set_skill("dodge",100);
	set("combat_exp", 100000);
	        set("vendor_goods", ({
    	(["name":__DIR__"obj/jitui","number":30]),
    	(["name":__DIR__"obj/jiudai","number":10]),
    	(["name":__DIR__"obj/hdjiudai","number":10]),
    	(["name":__DIR__"obj/kaoya","number":20])
        }));

    	set("attitude", "peaceful");
    	set("inquiry", ([
		"name" : "提起我黄某人的大名黄富霸，江湖上谁人不知，谁认不晓啊。",
		"here" : "别看这个拳市不起眼，来打拳的可都是江湖上各大门派的高手啊！",	
		"rumors" : "咱们都是大汉百姓，花花江山却给鞑子占了，总有一日，要把鞑子杀得干干净净！",
		"比赛" : (: ask_match :),
		"match" : (: ask_match :),
		"gold" : (: ask_gold :),
		"赌金" : (: ask_gold :),
		"赔率" : (: ask_betrate :),
		"betrate" : (: ask_betrate :),
	]));

     setup();

     carry_object(__DIR__"obj/b_cloth")->wear();
     carry_object(__DIR__"obj/blade")->wield();
}

void init()
{
        object ob = this_player();
        if (base_name(environment()) != query("startroom")) return;

        ::init();
		if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
        add_action("do_check", ({"check", "chazhang", "查帐"}));
	add_action("do_convert", ({"convert", "duihuan", "兑换"}));
	add_action("do_deposit", ({"deposit", "cun", "存"}));
	add_action("do_withdraw", ({"withdraw", "qu", "取"}));

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		message_vision("黄富霸对$N略拱了拱手道：今儿个我又召了几位江湖上各大门派的高手前来比拳，快请下注吧！\n", ob);
		return;
}

void relay_say(object me, string msg)
{
        if (!msg) return;
        if (random(50)==0){
        	switch(random(3)) {
                        case 0:         
                               	command("hi " + me->query("id"));  
                                break;
                        case 1: 
                                command("push " + me->query("id"));  
                                break; 
                        case 2:         
                                command("wah " + me->query("id"));  
                                break; 
                        default:
          	}
    	}
}

void relay_emote(object me, string arg)
{
        switch (arg) {
                case "die":
                case "idle":
                case "sure":
                case "lazy":
                case "xbc97":
                case "smell":
                case "bored":
                case "escape":
                case "chicken":
                case "laughproud":
                case "nonsense":
                        command(arg);
                        break;
                case "waggle":
                case "willbe":
                case "pain":
                case "push":
                case "puke":
                case "poke":
                case "stare":
                case "admit":
                case "rascal":
                case "story":
                case "crazy":
                case "thank":
                case "disapp":
                case "disapp1":
                case "accuse":
                case "homework":
                case "papaya":
                case "benger":
                case "sue":
                case "regard":
                case "courage":
                case "meeting":
                case "pat":
                case "pig":
                case "piggy":
                case "flower":
                case "joke":
                case "sigh":
                case "poor":
                case "ugly":
                case "rabbit":
                case "pretty":
                case "knife1":
                case "grpfight":
                case "points":
                case "congra":
                case "sing3":
                case "lover":
                case "nocry":
                case "flatter":
                case "rabbit2":
                case "goodkid":
                case "fire":
                case "boat":
                        command(arg + " huang");
                        break;
                case "interest":
                        command("liar");
                        break;
                case "slow":
                        command("lover");
                        break;
                case "shout":
                        command("peace");
                        break;
                case "bug":
                case "cook":
                command("taste");
                        break;
                case "hero":
                case "hehe":
                        command("fear");
                        break;
                case "cold":
                case "sing2":
                case "magic":
                case "taste":
                        command("escape");
                        break;
                case "inn":
                case "sorry":
                case "careful":
                        command("sneer");
                        break;
                case "kick":
                case "slap":
                case "trip":
                        command("pain");
                        break;
                case "fire1":
                case "swear":
                        command("shake");
                        break;
                case ":)":
                case "haha":
                case "xixi":
                case "laugh":
                case "hehehe":
                case "giggle":
                        command("nosmile");
                        break;
                case "claw":
                        command("cry");
                        break;
                case "!!!":
                case "gun":
                case "club":
                case "hug":
                case "drug":
                case "doubt":
                case "makeup":
                        command("corpse huang");
                        break;
                case "shameless":
                        command("hate huang");
                        break;
                case "admire":
                        command("humble huang");
                        break;
                case "joythank":
                        command("thank huang");
                        break;
                case "rhero":
                        command("shout huang");
                        break;
                case "poem":
                        command("raise huang");
                        break;
                case "slogan":
                        command("slogan2 huang");
                        break;
                case "angry":
                        command("stare huang");
                        break;
                case "happy":
                        command("rich huang");
                        break;
                case "dare":
                        command("points huang");
                        break;
                case "lick":
                        command("smell huang");
                        break;
                case ":(":
                case "cry":
                        command("nocry " + me->query("id"));
                        break;
                case "xigua":
                        command("xigua2 " + me->query("id"));
                        break;
                case "nod":
                        command("shake " + me->query("id"));
                        break;
                case "shake":
                        command("nod " + me->query("id"));
                        break;
                case "blush":
                        command("lover " + me->query("id"));
                        break;
                case "monk":
                        command("buddhi " + me->query("id"));
                        break;
                case "hungry":
                        command("rich " + me->query("id"));
                        break;
                case "slapsb":
                        command("inn " + me->query("id"));
                        break;
                case "wait":
                        command("nomatch " + me->query("id"));
                        break;
                case "lean":
                        command("hug " + me->query("id"));
                        break;
                case "god":
                        command("comfort " + me->query("id"));
                        break;
                case "faint":
                        command("nofear " + me->query("id"));
                        break;
                case "wanfu":
                        command("bow " + me->query("id"));
                        break;
                case "innocent":
                        command("goodman " + me->query("id"));
                        break;
                case "yawn":
                        command("zzz " + me->query("id"));
                        break;
                case "visit":
                        command("welcome " + me->query("id"));
                        break;
                case "welcome":
                        command("visit " + me->query("id"));
                        break;
                case "brag":
                        command("gun " + me->query("id"));
                        break;
                case "dunno":
                        command("disapp " + me->query("id"));
                        break;
                case "hmm":
                        command("? " + me->query("id"));
                        break;
                case "poem3":
                        command("willbe " + me->query("id"));
                        break;
                case "zzz":
                        command("shutup " + me->query("id"));
                        break;
                case "nomatch":
                        command("mother " + me->query("id"));
                        break;
                case "nofear":
                        command("chicken " + me->query("id"));
                        break;
                case "meet":
                case "smell1":
                        command("seduce " + me->query("id"));
                        break;
                case "rose":
                case "kiss":
                        command("yeah " + me->query("id"));
                        break;
                case "rich":
                case "protect":
                        command("joythank " + me->query("id"));
                        break;
                case "hammer":
                case "killair":
                        command("peace " + me->query("id"));
                        break;
                case "uncle":
                case "anniversary":
                        command("sure " + me->query("id"));
                        break;
                case "cut":
                case "corpse":
                case "soup":
                case "smash":
                case "slash":
                case "knife":
                        command("peace1 " + me->query("id"));
                        break;
                case "thumb":
                case "mother":
                case "praise":
                case "goodman":
                case "applaud":
                case "handsome":
                        command("noshame " + me->query("id"));
                        break;
                case "bf":
                case "gf":
                case "chitchat":
                        command("nonsense " + me->query("id"));
                        break;
                case "wave":
                case "bye":
                case "byebye":
                case "goodbye":
                        command("byebye " + me->query("id"));
                        break;
                case "rob":
                case "fat":
                case "zhu":
                case "dumb":
                case "uncle":
                case "u&me5":
                case "congra1":
                case "marriage":
                        command("faint " + me->query("id"));
                        break;
                case "love":
                case "lovelook":
                case "loveshoe":
                case "deadlove":
                case "ghostlove":
                case "joycup":
                case "touch1":
                case "wink":
                case "u&me2":
                case "xigua2":
                case "sex":
                case "seduce":
                case "doufu":
                case "oath":
                case "flirt":
                        command("puke " + me->query("id"));
                        break;
                case "nosmile":
                case "brother":
                case "massage":
                        command("goodkid " + me->query("id"));
                        break;
                case "ysis":
                case "sister":
                case "aunt":
                case "18mo":
                case "beauty1":
                case "shajiabang1":
                        command("uncle " + me->query("id"));
                        break;
                case "bite":
                case "grin":
                case "hate":
                case "consider":
                        command("fear " + me->query("id"));
                        break;
                case "flush":
                case "u&me1":
                case "callname":
                        command("shout " + me->query("id"));
                        break;
                case "agree":
                case "u&me":
                case "raise":
                        command("raise " + me->query("id"));
                        break;
                default:
                        command(arg + " " + me->query("id"));
                        break;
        }
}
int ask_gold()
{
	object ob=this_object();
	object me=this_player();
	object room=environment(ob);
	string str_temp;
	int money_gold;
	int money_silver;
	tell_object(me,"本比武场目前情况如下：\n");
	switch(room->query("state"))
	{
		case "bound":
		break;
		default:
	
	tell_object(me,RED"红方"NOR+"的总赌金为："HIY+chinese_number(room->query("red_money"))+NOR"两黄金。\n");
	tell_object(me,BLU"黑方"NOR+"的总赌金为："HIY+chinese_number(room->query("black_money"))+NOR"两黄金。\n");
	tell_object(me,HIW"平局"NOR+"的总赌金为："HIY+chinese_number(room->query("none_money"))+NOR"两黄金。\n");

	if(room->query("red_betrate") && room->query("black_betrate"))
	{
		tell_object(me,"黄富霸说道：这场比武的赔率目前为：\n");
		tell_object(me,HIR"红方"NOR+"：100:"+room->query("red_betrate")+HIB"          黑方"NOR+"：100:"+room->query("black_betrate")+HIW"          平局"NOR+"：100:"+room->query("none_betrate")+"\n");
	}
	if (me->query_temp("dxdc/bet"))
	{
		tell_object(me,"您目前压的是");
			if(me->query_temp("dxdc/side")=="red")
				tell_object(me,HIR"红方："NOR);
			else
				if(me->query_temp("dxdc/side")=="black")
					tell_object(me,HIB"黑方："NOR);
				else
					tell_object(me,HIW"平局 ："NOR);
		tell_object(me,HIY+chinese_number(me->query_temp("dxdc/bet"))+NOR"两黄金。\n");
	}
	else
	{
		tell_object(me,"您还没下注呢。选好了就赶紧下注吧，机会可不等人啊！\n");
	}
}//end switch
	if(room->query("yingyu")<0)
	{
		money_gold=-room->query("yingyu")/100;
		money_silver=-room->query("yingyu") % 100;
	}
	else
	{
		money_gold=room->query("yingyu")/100;
		money_silver=room->query("yingyu") % 100;
	}
	str_temp="本比武场目前盈利状况为：";
	if (room->query("yingyu")<0) 
		str_temp+="亏损 "; 
	else 
		if (room->query("yingyu")>0)
			str_temp+="盈利 ";
		else
			str_temp+="平衡";
			
	if (money_gold) str_temp+=HIY+chinese_number(money_gold)+"两黄金"NOR;
	if (money_silver) str_temp+=HIW+chinese_number(money_silver)+"两白银"NOR;
	str_temp+="。\n";
	
	tell_object(me,str_temp);
	
	return 1;

}
int ask_match()
{
	object me,room,red,black;
	string str_msg="";
	me = this_player();
	room = environment(this_object());
	red = room->query_red_fighter();
	black = room->query_black_fighter();
	

	if(room->query("state")=="") 
	{
		tell_object(me,"黄富霸略欠了欠身道：今天的选手正在后台准备，即将登场，请稍安毋躁！\n");
		return 1;
	}
	if(room->query("state")=="wait" || room->query("state")=="fighting")
	{
		if (!objectp(red))
		{
			tell_object(me,"红方选手拉肚子不能出席比赛，这场比赛取消了。\n");
			return 0;
		}
		if (!objectp(black))
		{
			tell_object(me,"黑方选手刚才扭伤了脚，不能参加比赛了。这场比赛取消了。\n");					//一般不会发生这两种情况
			return 0;
		}
		str_msg+="本场对阵的双方是来自"HIW+red->query("family/family_name")+NOR"的"RED+red->query("name")+NOR"和来自"HIW+black->query("family/family_name")+NOR"的"BLU+black->query("name")+NOR"!\n";
		str_msg+="其中"RED+red->query("name")+NOR"的"HIY+red->query("good_skills")+NOR"和"BLU+black->query("name")+NOR"的"HIY+black->query("good_skills")+NOR"那可都是江湖上赫赫有名的绝技啊！\n";
		str_msg+="这局比武";
		if(!room->query("use_weapon")) str_msg+=HIC"不允许使用兵器，"NOR;
		else str_msg+=HIC"允许使用兵器，"NOR;
		switch(room->query("base_jiali"))
		{
			case 0:
				str_msg+=HIB"不使用内力进行生死相搏！\n"NOR;
			break;
			case 10:
				str_msg+=HIB"使用全力进行生死相搏！\n"NOR;
			break;
			default:
				str_msg+="使用"HIW+chinese_number(room->query("base_jiali"))+"成内力"NOR+"进行生死相搏!\n";
		}
	switch(room->query("state"))
	{
		case "wait":
			tell_object(me,"黄富霸赶忙催着你说：本场比赛的选手已经登场了，比赛即将开始，要下注抓紧哪！\n");
			tell_object(me,str_msg);
			return 1;
		break;
		case "fighting":
			tell_object(me,"黄富霸不耐烦地挥了挥手道：比赛已经开始了，快专心看吧，不然赌输了可别怪我！\n");
			tell_object(me,str_msg);
			return 1;
		break;
	}//end switch
	}//end if
	tell_object(me,"黄富霸转过脸来说道：本场比赛已经结束，要赌下场请稍候！\n");
	return 1;
}
int ask_betrate()
{
	object me=this_player();
	object room=environment(this_object());
	if(room->query("red_betrate") && room->query("black_betrate"))
	{
		tell_object(me,"黄富霸说道：这场比武的赔率目前为：\n");
		tell_object(me,HIR"红方"NOR+"：100:"+room->query("red_betrate")+HIB"          黑方"NOR+"：100:"+room->query("black_betrate")+"\n");
		return 1;
	}
	tell_object(me,"黄富霸恶狠狠的看着你：我这里赔率多少关你什么事？\n");
	return 1;	
}
int ask_convert()
{
	object silver_amount;
	object gold_amount;
	object me=this_player();
	int silver_in;
	tell_object(me,"黄富霸对你说道：我会把你身上的所有白银全兑换成黄金的。\n");
	silver_amount = present("silver_money", me);
	if(!objectp(silver_amount))
	{
		tell_object(me,"黄富霸对你说道：你身上根本没有白银，你向兑换什么？\n");
		return 1;
	}
	silver_in=silver_amount->query_amount();
	if(silver_in<100)
	{
		tell_object(me,"黄富霸对你说道：你身上的白银不够一百两不能兑换成黄金。\n");
		return 1;
	}
	silver_amount->add_amount(-silver_in/100*100);
	gold_amount = present("gold_money", me);
	if(objectp(gold_amount))
	{
		gold_amount->add_amount(silver_in /100);
	}
	else
	{
   		gold_amount=new("/clone/money/gold");
 		gold_amount->set_amount(silver_in / 100);
   		gold_amount->move(me);
	}
	tell_object(me,"黄富霸对你说道：我已经把你身上的"+chinese_number(silver_in/100*100)+"两"+HIW"白银"NOR+"兑换成"+chinese_number(silver_in/100)+"两"+HIY"黄金"NOR+"。\n");
	
	return 1;
	
	
	
}
void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        command("swear");
}

void unconcious()
{
        say("黄富霸大叫一声: 妈呀!救命。\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
        clear_conditions_by_type("poison");
}

void die()
{
        unconcious();
}