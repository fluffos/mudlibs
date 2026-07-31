//Cracked by Roath
// Room: /d/changan/duchang2
// by snowcat 7/5/1997
inherit ROOM;
#include <ansi.h>

string one = "\n"+
HBYEL"        "NOR"\n"+
HBYEL"        "NOR"\n"+
HBYEL"   ●   "NOR"\n"+
HBYEL"        "NOR"\n"+
HBYEL"        "NOR"\n";

string two = "\n"+
HBYEL"        "NOR"\n"+
HBYEL"        "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL"        "NOR"\n"+
HBYEL"        "NOR"\n";

string three = "\n"+
HBYEL"        "NOR"\n"+
HBYEL" ●     "NOR"\n"+
HBYEL"   ●   "NOR"\n"+
HBYEL"     ● "NOR"\n"+
HBYEL"        "NOR"\n";

string four = "\n"+
HBYEL"        "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL"        "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL"        "NOR"\n";

string five = "\n"+
HBYEL"        "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL"   ●   "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL"        "NOR"\n";

string six = "\n"+
HBYEL"        "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL" ●  ● "NOR"\n"+
HBYEL"        "NOR"\n";

int room_status = 0;
int *big = allocate(2);
int *res = allocate(2);

mapping gutous = ([ 
  "tc" : "头彩",
  "sd" : "双对",
  "qx" : "七星",
  "sx" : "散星",
 ]); 

void create()
{
	set("short", "长安大赌场");
  	set("long", @LONG

这里摆着一个八仙桌，中间摆着一个银盘。赌客们正聚精会神地下赌。
正席是一位胖子，手里不断玩弄着一对玉骰，他就是这里的庄东。

墙上挂有一个匾，上面写着：
    头彩（骰数由每次开盘前确定）      ：一赔三十六
    双对（两骰号相同，且为偶数）      ：一赔十二
    七星（两骰之和为七）              ：一赔六
    散星（两骰之和为三，五，九，十一）：一赔三

匾角有一个牌子(paizi)。

LONG);

	set("item_desc",([
    		"paizi" : @LONG
	押头彩骰： gutou|ya tc <amount>  赔率：36
        押双对骰： gutou|ya sd <amount>  赔率：12
        押七星骰： gutou|ya qx <amount>  赔率：6
        押散星骰： gutou|ya sx <amount>  赔率：3

*注：押好后如果中途离场，将按最大赔率扣除你的潜能！
        
LONG,              
  	])); 
	set("objects", ([ /* sizeof() == 1 */
    		__DIR__"npc/zhuangd" : 1,
  	]));
  	set("exits", ([ /* sizeof() == 1 */
    		"west" : __DIR__"clubup",
    		//"east" : __DIR__"shaizi-room",
  	]));
  	set("light_up", 1);
  	set("no_fight", 1);
  	set("no_magic", 1);
  	set("channel_id","赌场(Du chang)");
  	setup();
}

void reset(){return;}

void init ()
{
	object me = this_player();
	if( me) me->delete_temp("gamble_gutou");
	add_action ("do_gutou","gutou");
	add_action ("do_gutou","ya");
  	add_action ("do_bian","bian");
  	add_action ("do_ban","get");
  	add_action ("do_ban","give");
  	add_action ("do_ban","back");
  	add_action ("do_ban","ask");
	if(room_status > 0)
    		return;
	remove_call_out ("gamble_prepare");
  	remove_call_out ("gamble_start");
  	remove_call_out ("gamble_perform");
  	remove_call_out ("gamble_finish");
  	call_out ("gamble_prepare",2);
  	room_status = 1;
}

int do_gutou (string arg)
{
	object me = this_player();
  	string what;
  	int amount;
  	string money;
  	object ob;

  	if( ! arg || sscanf (arg,"%s %d",what,amount) != 2)
		return notify_fail("请使用： gutou <押骰种类> <潜能数目>\n");
	if( what != "tc" && what != "sd" && what != "qx" && what != "sx")
    		return notify_fail("你要押什么骰？\n");
	if( amount<=0 )
		return notify_fail("你也好意思？\n");
	if( me->query("potential")-(int)me->query("learned_points")<amount )
		return notify_fail("你没有这么多潜能。\n");
	if( me->query("potential")-(int)me->query("learned_points")<amount*36 )	
		return notify_fail("为防止中途离场，你得保证身上的潜能够36倍赔率！\n");
	if( amount > 50000 )
    		return notify_fail("你下的注不能超过50000。\n");
	if( me->query_temp ("gamble_gutou/amount") > 0)
    		return notify_fail("你已经押过了。\n");
	if( room_status > 1)
    		return notify_fail("现在正在赌呢，稍等片刻。\n");
	me->set_temp("gamble_gutou/kind",what);
  	me->set_temp("gamble_gutou/amount",amount);
  	me->set_temp("gamble_gutou/money","pot");
  	message_vision (sprintf("$N拿出 %s 点潜能，押在%s上。\n",chinese_number(amount),gutous[what]),me);
  	tell_object(me,HIR"*注：押好后如果中途离场，将按最大赔率扣除你的潜能！\n"NOR);
  	me->add("potential",-amount);
  	me->save();
	return 1;
}

void valid_move(object me)
{
	int lose;
	if( me )
	{
		if( me->query_temp ("gamble_gutou/amount") > 0) 
      			tell_object(me,"你离开了赌场，所压的潜能全部充公了。\n");
      		lose = me->query_temp ("gamble_gutou/amount")*35;
      		if( lose>0 )
      		{
      			tell_object(me,HIY"因为你中途离开了赌场，被追加扣除了"+ lose +"点潜能！\n"NOR);
      			me->add("potential",-lose);
      			me->save();
      		}	
		me->delete_temp("gamble_gutou");
	}	
}

void display_gutou (object room, int i)
{
	string str;
	switch (i)
  	{
    		case 1: str = one;break;
    		case 2: str = two;break;
    		case 3: str = three;break;
    		case 4: str = four;break;
    		case 5: str = five;break;
    		case 6: str = six;break;
    		default: str = "出错了!!\n";break;
    	}
    	tell_room(this_object(),str);	
}

int rdm()
{
	switch(random(10))
	{
		case 0 :
		case 1 : return random(4)+random(3)+1;
		case 2 :
		case 3 : return random(3)+random(4)+1;
		case 5 : 
		case 6 : return random(2)+random(2)+random(4)+1;
		default: return random(6)+1;
	}	
}

void gamble_prepare ()
{
  	object room = this_object();
  	tell_room (room,"小雨唱道：新开盘！瘠叫头彩！\n");
  	tell_room (room,"小雨将两枚玉骰往银盘中一撒。\n");
  	big[0] = rdm();
  	big[1] = rdm();
  	// keep two numbers different for a probability == 1/36
  	while (big[0] == big[1])
  	{
    		reset_eval_cost();
    		big[1] = rdm();
  	}
  	display_gutou (room,big[0]);
  	display_gutou (room,big[1]);
  	tell_room (room,"小雨叫道：头彩骰号"+chinese_number(big[0])+chinese_number(big[1])+"！\n");
  	tell_room (room,"接着小雨麻利地顺手将玉骰从盘中收回：现在开盘押钱！\n");
  	room_status = 1;
  	call_out ("gamble_start",24);
}
 
void gamble_start ()
{
  	object room = this_object();
  	tell_room (room,"小雨喊声：封盘停押！\n");
  	tell_room (room,"又补道：本盘头彩骰号是"+chinese_number(big[0])+chinese_number(big[1])+"。\n");
  	tell_room (room,"然后将两枚玉骰扔进两个金盅，一手持一盅摇将起来。\n");
  	room_status = 2;
  	call_out ("gamble_perform",6,0);
  	call_out ("gamble_perform",12,1);
  	call_out ("gamble_finish",18);
}

void gamble_perform (int i)
{
  	object room = this_object();
	tell_room (room,"金盅倒扣在银盘上，玉骰滚了出来。\n");
  	res[i] = rdm();
  	display_gutou (room,res[i]);
}

void player_wins (object who, int total)
{
	int num,amount;
	if( !who || !present(who,this_object()) )
		return;
	amount = who->query_temp("gamble_gutou/amount");
	num = amount;
  	total = total * amount;
  	message_vision (sprintf("$N赢了 %s 点潜能！\n",chinese_number(total),),who);
  	if( total>100000 )
  		CHANNEL_D->do_channel(this_object(),"rumor","听说"+who->query("name")+"在"+query("short")+"赢得了"+chinese_number(total)+" 点潜能！");
	who->add("potential",total);
	who->add("potential",num);
	who->save();
}

void player_loses (object who, int total)
{
	int num;
	if( !who )
		return;
	num = who->query_temp("gamble_gutou/amount");
	message_vision (sprintf("小雨将$N押在银盘中的 %s 点潜能收走。\n",chinese_number(num)),who);
}

void gamble_finish ()
{
  	string win;
  	int total, i;
  	object room = this_object();
  	object *list = all_inventory(room);
  	if( res[0]==big[0] && res[1]==big[1])
  	{
    		total = 36;
    		win = "tc";
  	}
  	else if( res[0]==res[1] && (res[0]/2*2 == res[0]))
  	{
    		total = 12;
    		win = "sd";
  	}
  	else 
  	{
    		int r = res[0]+res[1];
    		if( r==7)
    		{
      			total = 6;
      			win = "qx";
    		}
    		else if( r==3 || r==5 || r==9 || r==11) 
    		{
      			total = 3;
      			win = "sx";
    		}
    		else
    		{
      			total = 0;
      			win = "none of them";
    		}
  	}
  	if( total == 0)
    		tell_room (room,"小雨叫道："+chinese_number(res[0])+chinese_number(res[1])+"……空盘！\n");
  	else	tell_room (room,"小雨叫道："+chinese_number(res[0])+chinese_number(res[1])+"……"+gutous[win]+"！\n");
  	i = sizeof(list);
  	while (i--)
  	{
    		if( !userp(list[i]))
      			continue;
    		if( list[i]->query_temp("gamble_gutou/kind") == win)
      			player_wins(list[i],total);
    		else if( list[i]->query_temp("gamble_gutou/kind"))
      			player_loses(list[i],total);
    		list[i]->delete_temp("gamble_gutou");
  	}
  	tell_room (room,"\n");
  	if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
  		call_out ("gamble_prepare",5);
  	else	room_status=0;
}

int do_bian(string arg)
{
	return 1;
}

int do_ban(string arg)
{
   	object ob;
   	object who=this_player();
   	if( arg) ob=present(arg, environment(who));
   	if( ob && userp(ob))
     		return 1;
	return 0;
}