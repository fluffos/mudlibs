
inherit NPC;
#include <ansi.h>

string ask_baibao();
int ask_character(string arg);
int ask_fanli();
int ask_xiandan();
int ask_illness();
int ask_kuilei();
int ask_mengzi();
int ask_buchang();
int ask_gift();
int ask_yao();

void create()
{
        set_name(WHT "老"NOR HIY "人"NOR,({  "wizard", "wushi" }) );
        set("gender", "男性" );
        set("age", 1220);
        set("long", HIY "\n 他一身"WHT "麻衣"HIC ","MAG"一身云烟缭绕，身旁，"HIW"一把木剑倾斜插在地上，他是"HIY "蜀"HIC "山"HIW "剑"HIR "仙"HIW "。\n");
        set("str", 11117);
        set("dex", 11116);
        set("con", 111115);
        set("int", 1111117);
        set("shen_type", 1);
        set("combat_exp", 10011111);
        set("attitude", "peaceful");

        setup();

        set("inquiry", ([
              "蜀山之道": (: ask_gift :),
              //"新手礼包": (: ask_buchang :),
              //"储物袋": (: ask_baibao :),
              //"弟子贡献": (: ask_fanli :),
              //"仙丹": (: ask_xiandan :),
              //"改变性格" : (: ask_character(0) :),
              //"暗疾": (: ask_illness :),
              //"孟子": (: ask_mengzi :),
              //"大红包": (: ask_kuilei :),
			 
        ]) );

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("ask_character","washme");
}

int ask_gift()
{
    object ob = this_player();
    object gift;
	int a,b,c,d;
    if (ob->query("shushan")<1) {
        command("say 你今天的副本次数已经没有了！");
        return 1;
    }else{
    for(b=0;b<3;b++){
	a=random(2)+random(2)+random(2)+random(2)+random(2)+random(2)+random(2);
	if(a==1){
	gift = new("/clone/vip/book_tianfu",1);
	gift->set_amount(3);
	gift->move(ob); 
	tell_object(ob,HIY"你获得了三本天赋书。"NOR"\n");
	}else if(a==3){
	gift = new("/clone/vip/putao1",1);
	gift->move(ob); 
	tell_object(ob,HIY"你获得了一串神奇葡萄。"NOR"\n");
	}else if(a==7){
	gift = new("/clone/vip/jiuzhuan",1);
	gift->set_amount(1);
	gift->move(ob); 
	tell_object(ob,HIY"你获得了一颗九转金丹。"NOR"\n");
	}
	}
	c=1000+random(1002);
	d=10000+random(10002);
	ob->add("combat_exp",c);
    ob->add("potential",d);
		 ob->add("shushan",-1);
		tell_object(ob,HIW"你获得了"+c+"点修为，"+d+"点潜能。"NOR"\n");
		ob->move("/d/city/kedian");
	}
    return 1;
        
}

int ask_buchang()
{
    object ob = this_player();

    if (ob->query("zjvip/xslb")>0) {
        command("say 你已经领取过新手礼包了！");
        return 1;
    }

    command("nod "+ob->query("id"));
    command("say 我这就发给你。");
    ob->add("zjvip/xslb",1);
    ob->add("combat_exp",400000);
    ob->add("potential",400000);
    ob->add("score",10000);
	ob->add("weiwang",10000);
    tell_object(ob,HIC"你获得了400000点修为，并祝你游戏快乐！"NOR"\n");  
    tell_object(ob,HIY"你获得了400000点潜能，并祝你游戏快乐！"NOR"\n");  
    tell_object(ob,HIB"你获得了10000点阅历，并祝你游戏快乐！"NOR"\n"); 
	 tell_object(ob,HIB"你获得了10000点威望，并祝你游戏快乐！"NOR"\n");
	log_file("buchang", sprintf("%s：%s(%s)领取了新手礼包。\n",ctime(time()),ob->query("name"),ob->query("id")));
    return 1;
        
}

int ask_character(string arg)
{
	object me = this_player();
	string msg, type, cs;

	if (!arg || arg == 0) {
		msg = ZJOBLONG+
		    "心狠手辣，宗师心法-九阴神功，提高攻击"ZJBR
			"光明磊落，宗师心法-南海玄功，增加防御"ZJBR
			"狡黠多变，宗师心法-不败神功，提高命中"ZJBR
			"阴险奸诈，宗师心法-葵花魔功，增加闪避"ZJBR
			"请选择你的性格：\n";
		
		msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
		msg += ZJSEP"光明磊落:washme 光明磊落";
		msg += ZJSEP"狡黠多变:washme 狡黠多变";
		msg += ZJSEP"阴险奸诈:washme 阴险奸诈";
		msg += ZJSEP"心狠手辣:washme 心狠手辣";
		
		write(msg + "\n");
		
	} else {
		if(sscanf(arg,"%s %s", type, cs) == 2)
		{
			if (me->query("character") == type) {
				tell_object(me, "你本来就是这种性格。\n");
				return 1;
			}

			if (cs == "yes") {
				if (type == "光明磊落" && me->query("character") == "心狠手辣") {
					me->set("character", type);
					tell_object(me, "你成功将性格改变为"+type+"。\n");
				} else if (type == "心狠手辣" && me->query("character") == "光明磊落") {
					me->set("character", type);
					tell_object(me, "你成功将性格改变为"+type+"。\n");
				} else if (type == "光明磊落" || type == "心狠手辣" || type == "狡黠多变" || type == "阴险奸诈") {
					tell_object(me, "对不起，你不符合改变性格的条件。\n");
                              return 1;
				} else {
					tell_object(me, "没有这种性格，请认真选择。\n");
					return 1;
				}
			} 
		} else {
			msg = ZJOBLONG+"你确定选择性格为"+HIG+arg+NOR"吗？\n";			
			msg += ZJOBACTS2+ZJMENUF(2,2,9,30);
			msg += "确定:washme "+arg + " yes";
			msg += ZJSEP"取消: ";
			
			write(msg + "\n");
		}
	}
	
	return 1;
}



int ask_fanli()
{
        int i;
        object ob = this_player();
        i=ob->query("zjvip/dizi_pay");
        i=i*10;
        if(ob->query("zjvip/dizi_pay")<1){
                command("say 你目前的弟子贡献太低，无法领取奖励。");
                message_vision("$N已累计获得了"+ob->query("zjvip/dizi_fanli")+"个通元大宝的奖励。\n",ob,  this_object());
                return 1;
        }
        else {
                command("nod "+ob->query("id"));
                command("say 你已符合领取弟子贡献奖励条件。");
	        ob->add("tydbl",i);
                ob->add("zjvip/dizi_pay",-i);
                ob->add("zjvip/dizi_fanli",i);
                message_vision("$N获得了"+i+"个通元大宝的奖励。\n",ob,  this_object());
                message_vision("$N已累计获得了"+ob->query("zjvip/dizi_fanli")+"个通元大宝的奖励。\n",ob,  this_object());
                return 1;
        }
}

int ask_xiandan()
{
    int a,b,c,d;
    object ob = this_player();

	a=ob->query("gift/xiandan");
	b=ob->query("gift/unknowdan");
	c=ob->query("gift/shenliwan");
	d=ob->query("gift/xisuidan");
     
	if (ob->query("zjvip/times") <1) {
        command("say 对不起，我只处理东方族人的事情！");
        return 1;
    }
    else {
    command("nod "+ob->query("id"));
    command("say 我来帮你查一下记录。");
    command("say 这位" + RANK_D->query_respect(ob) +"，你已经吃了："+chinese_number(a)+"颗"HIY"醍醐仙丹"NOR"，"+chinese_number(b)+"颗"HIR"火红仙丹"NOR"，"+chinese_number(c)+"颗"HIG"神力丸"NOR"，"+chinese_number(d)+"颗"YEL"洗髓丹"NOR"。");
	return 1;
    }
}

int ask_illness()
{
        int a,b,c,d;
        object ob = this_player();

	a=ob->query("gift/xiandan_fail");
	b=ob->query("gift/unknowdan_fail");
	c=ob->query("gift/shenliwan_fail");
	d=ob->query("gift/xisuidan_fail");
     
	if (ob->query("zjvip/times") <1) {
                command("say 对不起，我只处理东方族人的事情！");
                return 1;
        }
        else {
                command("nod "+ob->query("id"));
                command("say 我来帮你查一下记录。");
                command("say 这位" + RANK_D->query_respect(ob) +"，你吃了"HIY "醍醐仙丹" NOR"有"+chinese_number(a)+"处暗疾，吃了"HIR "火红仙丹" NOR"有"+chinese_number(b)+"处暗疾，吃了"HIG "神力丸" NOR"有"+chinese_number(c)+"处暗疾，吃了"YEL "洗髓丹" NOR"有"+chinese_number(d)+"处暗疾。");
                return 1;
        }
}

string ask_baibao()
{
        object ob;
        mapping myfam;
        object nang;

        ob = this_player();
        myfam = (mapping)ob->query("family");
        
        //if(!myfam) return "你还是先加入门派吧？";

	if (ob->query("combat_exp") < 10000)
		return "虽然我这里有只乾坤袋，可是你战斗修为这么差，被人抢走了怎么办？\n";

	if (ob->query("chuwudai1"))
		return "你之前不是已经领过了吗？你还是赶紧联系清风去处理一下吧。\n";
        
	if ( present("chuwudai", ob))
		return "你已经有了一个储物袋，别贪得无厌！\n";

	nang=new("/clone/baibao");
	nang->set("owner_id", ob->query("id"));
	nang->move(ob);
	ob->set("chuwudai1", 1);
	write("你得到一个储物袋!\n");
	return "这可是个宝贝，好好利用它吧。";
}


int ask_kuilei()
{
    object ob = this_player();
    object yao;
	int m = localtime(time())[4]+1,m1,m2,m3;
	m1= m-1;
	m2= m1-1;
	m3= m2-1;
     
	if (ob->query("zjvip/times") <1) {
        command("say 对不起，我只处理东方族人的事情！");
        return 1;
    }
	if ((ob->query("zjvip/all_pay")+ob->query("gongxians"))<3) {
        command("say 对不起，你的贡献不够三点，不符合领取大红包的条件！");
        return 1;
    }
	if (ob->query("zjvip/kuilei"+m)>=((ob->query("zjvip/all_pay")+ob->query("gongxians"))/3)) {
        command("say 以你目前的贡献只能领"+chinese_number((ob->query("zjvip/all_pay")+ob->query("gongxians"))/3)+"个开测大红包！");
        return 1;
    }

	command("nod "+ob->query("id"));
    command("say 我这就给你。");
    yao = new("/clone/gift/kc");
    yao->move(ob);
    ob->add("zjvip/kuilei"+m,1);
    ob->delete("zjvip/kuilei"+m1);
    ob->delete("zjvip/kuilei"+m2);
    ob->delete("zjvip/kuilei"+m3);
    message_vision("$N给了$n一个" + yao->query("name") + "。\n",this_object(),ob);
	log_file("gift", sprintf(ob->query("id")+"在%s：领取了一个开测大红包。\n",ctime(time())));
    return 1;
        
}


int ask_mengzi()
{
        object ob = this_player();
        object yao;

     
	if (ob->query("zjvip/times") <1) {
                command("say 对不起，我只处理东方族人的事情！");
                return 1;
        }
	if (ob->query("zjvip/all_pay")+ob->query("gongxians")<300) {
                command("say 对不起，你的贡献不够，不符合领取《孟子》的条件！");
                return 1;
        }

	if ( present("mengzi book", ob)) {
                command("say 你已经有了一本《孟子》了，别贪得无厌！");
                return 1;
        }

                command("nod "+ob->query("id"));
                command("say 我这就给你。");
        yao = new("/clone/shizhe/mengzi");
        yao->move(ob);
        message_vision("$N给了$n一本《" + yao->query("name") + "》。\n",this_object(),ob);
                return 1;
        
}
