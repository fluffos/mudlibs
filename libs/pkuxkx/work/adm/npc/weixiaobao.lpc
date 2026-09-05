// wei.c

inherit NPC;
//inherit F_SKILL;
#include <ansi.h>;
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
int time_period(int timep,object me);
void pay_him(object who, int amount);
void clear_stat();
void pre_cal();

void create()
{
	int i,amun;

	set_name("韦小宝", ({ "wei xiaobao", "wei", "xiaobao" }));
	set("title", HIC"大清国抚远大将军"HIY"一等鹿鼎公"NOR);
	set("gender", "男性");
	set("age", 18);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("per", 28);
        set("no_get", 1);
	set("long", 
"这位少年将军头戴红顶子，身穿黄马褂，眉花眼笑，贼忒兮
兮，左手轻摇羽扇，宛若诸葛之亮，右手倒拖大刀，俨然关
云之长，正乃韦公小宝是也。见你看着他，“哈哈哈”，仰
天大笑三声，学足了戏文中曹操的模样，你顿时忍不住凑个
趣，问一句：“将军为何发笑？”\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
        set("max_qi", 2500);
        set("max_jing", 1000);
        set("neili", 500);
        set("max_neili", 500);
	set("jiali", 50);
	set("round",1);

        set_skill("force", 20);
        set_skill("parry", 20);
        set_skill("hand", 20);
        set_skill("dodge", 20);
        set_skill("shenxing-baibian", 20);
        set_skill("yunlong-shengong", 20);
        set_skill("qianye-shou", 90);

        map_skill("force", "yunlong-shengong");
        map_skill("parry", "qianye-shou");
        map_skill("dodge", "shenxing-baibian");
        map_skill("hand", "qianye-shou");
        prepare_skill("hand", "qianye-shou");
        set("inquiry", ([
             "job"  : "直接输入命令 job 就行了。\n",
            "天地会"  : "别烦我！\n",
            "陈近南"  : "那是我师父！\n",
            "茅十八"  : "就是那十八个毛虫啊？他还没死吧！\n",
            "独臂神尼": "那是我美貌尼姑师父！\n",
            "韦春芳"  : "我娘做婊子生意越来越差了，现在改行作老鸨了！\n",
            "康熙"    : "那是我皇帝师父！\n",
            "小玄子"  : "那是我皇帝师父！\n",
            "小桂子"  : "别提这个名字了，我怕怕！\n",
            "阿珂"    : "她是我明媒正娶的大老婆！\n",
            "双儿"    : "你认识她？大功告成，亲个嘴儿！\n",
            "曾柔"    : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "方怡"    : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "苏荃"    : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "沐剑屏"  : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
            "建宁公主": "这个骚娘皮，亲厚不及双儿、美貌不及阿珂、武功不
及苏荃、机巧不及方怡、天真纯善不及沐剑屏、温柔斯文不及曾柔，
差有一日之长者，不过横蛮泼辣而已！\n",
        ]) );

	setup();
	carry_object("/d/city/npc/obj/zhja")->wear();
	set("lower_limit",1);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet", "bet");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        write( "小宝笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，过来赌两手，开开心吧。\n");
                        break;
                case 1:
                        write( "小宝晃了晃手中的骰子，叫道：这位" + RANK_D->query_respect(ob)
                                + "，小赌可以养家糊口，大赌可以定国安邦。来吧！\n");
                        break;
                case 2:
                        write( "小宝说道：这位" + RANK_D->query_respect(ob)
                                + "，进来！进来！ 输了算我的！\n");
                        break;
        }



	return;

}
 
string *dice = ({
"[31m
	⊙ 

[37m",
"	⊙

	    ⊙
",
"	⊙
	  ⊙ 
	    ⊙
",
"	[31m⊙  ⊙

	⊙  ⊙
[37m",
"	⊙  ⊙
	  ⊙
	⊙  ⊙
",
"	⊙ ⊙
	⊙ ⊙
	⊙ ⊙
"
		});

int do_bet(string arg)
{
        int i,bet_amt;
        int bet_type;
        object me, gold;
        string message;
	if(!arg || !sscanf(arg, "%d %d",bet_type,bet_amt))
                return notify_fail("bet <种类> <金量>\n");
	if(bet_type>18 || bet_type < 0)
		return notify_fail("种类只可从零到十八\n");
	me = this_player();
	if(me->is_busy())
		return notify_fail("你上个动作还没完成。\n");
	gold = present("gold", me);
	if(!gold) return notify_fail("你身上没有金子。\n");
	if((int) gold->query_amount() < bet_amt)
		return notify_fail("你身上没有那麽多金子。\n");	
	if((int) this_object()->query("lower_limit") > bet_amt)
		return notify_fail("这张台的最小赌注是"+chinese_number((int) this_object()->query("lower_limit"))+"两金子。\n");
        if((int) this_object()->query("too_late") )
	        return notify_fail("这铺来不及了，等下手吧．\n");
	if((int) me->query("gamble/amount"))
	{ 
		if(bet_type != (int) me->query("gamble/type"))
			return notify_fail("你不可在一铺中下不同的注．\n");
        	gold->add_amount(-bet_amt);
	        me->start_busy(1);
	        if(bet_type == 0)
        	        message = sprintf(RED"小"NOR);
	        if(bet_type == 1)
        	        message = sprintf(RED"大"NOR);
	        if(bet_type == 2)
        	        message = sprintf(RED"围骰"NOR);
	        if(bet_type >=3)
        	        message = sprintf(RED"%s"NOR,chinese_number(bet_type));
		        message_vision(sprintf("$N又从身上拿出%s两黄金，加压在%s上．\n",
                                chinese_number(bet_amt), message), me);
		        bet_amt += (int) me->query("gamble/amount");
                	me->set("gamble/amount",bet_amt);

	}
	else
	{
		gold->add_amount(-bet_amt);
		me->start_busy(1);
		if(bet_type == 0)	
			message = sprintf(RED"小"NOR);
		if(bet_type == 1)
			message = sprintf(RED"大"NOR);
	        if(bet_type == 2)
        	        message = sprintf(RED"围骰"NOR);
		if(bet_type >=3)
        	        message = sprintf(RED"%s"NOR,chinese_number(bet_type));
		message_vision(sprintf("$N从身上拿出%s两黄金，压在%s上．\n",
				chinese_number(bet_amt), message), me);
		me->set("gamble/type",bet_type);
		me->set("gamble/amount",bet_amt);
	}
	me->set("gamble/round",this_object()->query("round"));
        seteuid(ROOT_UID);
        me->force_me("save");
	stat[bet_type] += bet_amt;
	if( find_call_out("rolldice") == -1)
		call_out("rolldice",30);
	if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
		call_out("advertise",random(5)+1);
	return 1;
}

void advertise()
{
        switch( random(3) ) {
                case 0:
	message_vision("$N向你笑道：快下注！这注你一定会赢！\n",this_object());
                        break;
                case 1:
	message_vision("$N说道：再不下注就来不及了！\n",this_object());
                        break;
                case 2:
	message_vision("$N满面红光，耸恿着大家：加！再加大你的赌注！一定赢！\n",this_object());

                        break;
        }

        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
	return;
}

void rolldice()
{
	this_object()->set("too_late",1);
	message_vision("$N大声叫道：下定注！说罢，将手中的三粒骰子撒向碗里．\n",this_object());
	message_vision("\n．．．三粒骰子在碗里蹦跳着，发出悦耳的声音．．．\n",this_object());
	pre_cal();
	call_out("first_dice",3);
	return;
}

void first_dice()
{
	int first;
        switch( random(3) ) {
                case 0:
        message_vision("\n一粒骰子弹了几下，停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n一粒骰子＂叮叮叮＂的跳动了几下，缓缓的停了下来：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n三粒骰子相互一撞，一颗直落碗底：\n\n",this_object());

                        break;
        }

	first = (int) this_object()->query("first_dice");
	message_vision(dice[first], this_object());
	this_object()->set("first_dice",first+1);
	call_out("second_dice",4);
	return;
}

void second_dice()
{
	int second;
        switch( random(3) ) {
                case 0:
       	message_vision("\n又一粒骰子缓缓的停了下来：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n第二粒骰子在碗边旋转不停．．忽地翻了个身：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n二粒骰子相互一撞，其中一颗跳了一跳：\n\n",this_object());

                        break;
        }
        second= (int) this_object()->query("second_dice");
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
	call_out("third_dice",5);


	return;
}

void third_dice()
{
        int third;
        switch( random(3) ) {
                case 0:
        message_vision("\n最后一粒骰子在碗里滑了两下，终于停在：\n\n",this_object());
                        break;
                case 1:
        message_vision("\n还有最后一粒骰子嘀遛遛的转个不停．．终于：\n\n",this_object());
                        break;
                case 2:
        message_vision("\n最后一粒骰子也终于停稳了：\n\n",this_object());

                        break;
        }
        third= (int) this_object()->query("third_dice");
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",2);


	return;
}

void end_the_round()
{
	int tot,reward,i,first, second, third;
	object *inv;
	first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");


	message_vision(sprintf("\n$N高声叫道：%s，%s，%s，",
		chinese_number(first),chinese_number(second),chinese_number(third)),
		this_object());
// see who is the winner!
	
	if( second == first && third == first)
	{
		message_vision("大小通吃！！\n",this_object());
		inv = all_inventory(environment(this_object()));
        	for(i=0; i<sizeof(inv); i++) {
			if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") && (inv[i]->query("gamble/round") == this_object()->query("round")) )
			{
				if((int) inv[i]->query("gamble/type") == 2)
				{
					message_vision("赢家－$N，一赔十二！！\n",inv[i]);
					reward = (int) inv[i]->query("gamble/amount") * 13 ;
					pay_him( inv[i],reward);
				}
				inv[i]->set("gamble/amount",0);
			}
        	}


	}
	else
	{
	tot = first+second+third;
	message_vision(sprintf("%s点，",chinese_number(tot)),this_object());
	if( tot>10 )
		message_vision("赔大吃小！\n",this_object());
	else
		message_vision("赔小吃大！\n",this_object());


	inv = all_inventory(environment(this_object()));
        for(i=0; i<sizeof(inv); i++) {
        if( userp(inv[i]) && (int) inv[i]->query("gamble/amount")&& (inv[i]->query("gamble/round") == this_object()->query("round"))  )
        {
		if((int) inv[i]->query("gamble/type") == tot)
		{
                message_vision("赢家－$N，一赔六！\n",inv[i]);
                 reward = (int) inv[i]->query("gamble/amount") * 7 ;
                pay_him( inv[i],reward);
                inv[i]->set("gamble/amount",0);
		}
		else 
                if(((int) inv[i]->query("gamble/type") == 0 && tot <=10 ) ||
			((int) inv[i]->query("gamble/type") == 1 && tot > 10 ))
                {
                message_vision("赢家－$N，一赔一！\n",inv[i]);
                reward = (int) inv[i]->query("gamble/amount") * 2 ;
                pay_him( inv[i],reward);
                inv[i]->set("gamble/amount",0);
		}
		else
		{
		reward = (int) inv[i]->query("gamble/amount");
                inv[i]->set("gamble/amount",0);
		}
        }
        }


	}
	this_object()->set("too_late",0);
	this_object()->set("first_dice",0);
	this_object()->set("second_dice",0);
	this_object()->set("third_dice",0);
	this_object()->add("round",1);
	clear_stat();
	return;
}

void pay_him(object who, int amount)
{
        object ob;
        object cash, tencash, gold, silver, coin;

        if( amount < 1 ) amount = 1;
        if( amount ) {
                ob = new("/clone/money/gold");
                ob->set_amount(amount);
                ob->move(who);
                
        }
}


void clear_stat()
{
	int i;
	for(i=0;i<=18;i++)
		stat[i]=0;
}

void pre_cal()
{
	this_object()->set("first_dice",0);
	this_object()->set("second_dice",0);
	this_object()->set("third_dice",0);
	if( !random(25)) {
	int index = 12;
	int amount ;
	int amt1,amt2,amt3;
	int i;
	int stp;
	stat[2] *= 36;
	for(i=3;i<=10;i++)
		stat[i] = 8*stat[i] + stat[0];
	for(i=11;i<=18;i++)
		stat[i] = 8*stat[i] + stat[1];
	stat[3] += stat[2];
	stat[18] += stat[2];
	amount = stat[12];

	for(i=11;i<=18;i++)
		if( stat[i] < amount)
			{
				amount = stat[i];
				index = i;
			}	
	stp = 2;
	for(i=10;i>=stp;i--)
		if( stat[i] < amount)
                        {
                                amount = stat[i];
                                index = i;
                        }

		if( index == 2  )
		{
		amount = random(6);
		this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
		}
		else 
		if( index == 3)
		{
                amount = 0; 
                this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
                }
		else
		if( index == 18 )
		{
                amount = 5;
                this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
		}
		else
		{
		if( index / 3 * 3 == index ) amount = index / 3 + 1;
		else
		amount = index / 3;
		this_object()->set("first_dice",amount-1);
		index -= amount;
		amount = index / 2;
		this_object()->set("second_dice",amount-1);
		index -= amount;
		amount = index /1;
		this_object()->set("third_dice",amount-1);
		}

	}
	else
	{
		this_object()->set("first_dice",random(6));
		this_object()->set("second_dice",random(6));
		this_object()->set("third_dice",random(6));
	}

}
