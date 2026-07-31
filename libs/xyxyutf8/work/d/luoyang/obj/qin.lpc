#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;
void init();
int do_play(string arg);
int do_tanzou(string arg);
void create()
{
  set_name(HIB "七弦琴" NOR, ({ "qin","wuxian","wuxian qin"})); 
  set_weight(10000);
  set("long","一架古色古香的七弦琴,但是已经断了两根弦。\n");
  set("unit", "架");
  setup();
}

void init()
{
  add_action("do_play", "play");
  add_action("do_tanzou", "tanzou");
}

int do_play(string arg)
{
  object me, where;
  int sen_cost, gain;
  string *msgs = ({
    "$N伸出纤指在琴上轻拨了一下，不禁想起梦中人。\n",
    "$N轻拨了一下琴弦，脸色绯红。\n",
    "$N若有所思地在弦上一拨，沉默几许……\n",
    "$N伏身抚琴，禁不住泪如雨下。\n",
    "$N轻轻地弹着琴，面色婉尔。\n",
    "$N小心地弹着琴弦，低低地唱了起来。\n",
    "$N边唱边弹，一曲凄歌断人心肠。\n",
  });
  me = this_player();
  where=environment(me);
	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("琴要放在膝上弹。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有闲情逸致弹琴...\n");
   	if( me->is_fighting() )
        		return notify_fail("太风雅了吧？打架时还弹琴...\n");
	if( where->query("no_fight") )
			return notify_fail("此处不宜大声喧哗。\n");
	if( (int)me->query_skill("qin",1)<50 )
		return notify_fail("你伸手撩拨了几下琴弦，要使这断弦的琴响起来，显然琴艺还没入门。\n");
	if( (int)me->query_skill("qin",1)>100 )
		return notify_fail("你的琴艺已经炉火纯青，此琴已与你合而为一。\n");

	sen_cost = 20 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("qin", 1)/5+(int)me->query("int")+1;
	me->improve_skill("qin", gain);

	message_vision (msgs[random(sizeof(msgs))],me);


  
  return 1;
}
int do_tanzou(string arg)
{
  	object me, where, qinqu ,*inv;
	object qupu1,qupu2,qupu3,qupu4,qupu5,qupu6,qupu7,qupu8,qupu9,qupu10;
	int i,gqupu1=0,gqupu2=0,gqupu3=0,gqupu4=0,gqupu5=0,gqupu6=0,gqupu7=0,gqupu8=0,gqupu9=0,gqupu10=0;
  	string *msgs = ({
    "$N伸出纤指在琴上轻拨了一下，曲调悠扬流畅。\n",
    "$N若有所思地在弦上一拨，沉默几许……\n",
    "$N轻轻地弹着琴，面色婉尔。\n",
    "$N小心地弹着琴弦，低低地唱了起来。\n",
    "$N边唱边弹，一曲凄歌断人心肠。\n",
  	});
  	me = this_player();
  	where=environment(me);
//	if( !this_object()->id(arg) ) return 0;
        if( !arg ) return notify_fail("你要弹奏什么？\n");
	if( environment(this_object())!=me ) return notify_fail("琴要放在膝上弹。\n");
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有闲情逸致弹琴...\n");
   	if( me->is_fighting() )
        		return notify_fail("太风雅了吧？打架时还弹琴...\n");
	if( where->query("no_fight") )
			return notify_fail("此处不宜大声喧哗。\n");
	if( (int)me->query_skill("qin",1)<200 )
		return notify_fail("你伸手撩拨了几下琴弦，要使这断弦的琴响起来，显然琴艺还没入门。\n");

		if ((arg== "qin" )
			&&(me->query_temp("10qu/10qu1")=="done") 
			&& (me->query_temp("10qu/10qu2")=="done")
			&& (me->query_temp("10qu/10qu3")=="done")
			&& (me->query_temp("10qu/10qu4")=="done")
			&& (me->query_temp("10qu/10qu5")=="done")
			&& (me->query_temp("10qu/10qu6")=="done")
			&& (me->query_temp("10qu/10qu7")=="done")
			&& (me->query_temp("10qu/10qu8")=="done")
			&& (me->query_temp("10qu/10qu9")=="done")
			&& (me->query_temp("10qu/10qu10")=="done"))
	{
		me->delete_temp("10qu");
		message("chat",HIC+"〖"+HIM+"小道消息"+HIC+"〗某人："+me->query("name")+"得到了古琴曲琴谱！\n"NOR,users());
        	qinqu = new("/d/luoyang/obj/qinqu");
        	qinqu->move(me);
		message_vision(HIG"$N十指飞弹，曲调时而高亢悲壮，时而抑扬悠远，时而凄婉断肠，时而急转直下。\n"NOR,this_player());
		message_vision(HIG"这架断了两弦的琴“铮铮”几声，剩下的琴弦相继断了！\n"NOR,this_player());
		message_vision(HIG"$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
               	destruct(this_object());
		return 1;
	}
				
	inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "高山流水") {gqupu1 = 1; qupu1 = inv[i];}
                        if(inv[i]->query("name") == "广陵散琴曲") {gqupu2 = 1; qupu2 = inv[i];}
                        if(inv[i]->query("name") == "平沙落雁") {gqupu3 = 1; qupu3 = inv[i];}
                        if(inv[i]->query("name") == "十面埋伏") {gqupu4 = 1; qupu4 = inv[i];}
                        if(inv[i]->query("name") == "渔樵问答") {gqupu5 = 1; qupu5 = inv[i];}
                        if(inv[i]->query("name") == "夕阳箫鼓") {gqupu6 = 1; qupu6 = inv[i];}
                        if(inv[i]->query("name") == "汉宫秋月") {gqupu7 = 1; qupu7 = inv[i];}
                        if(inv[i]->query("name") == "梅花三弄") {gqupu8 = 1; qupu8 = inv[i];}
                        if(inv[i]->query("name") == "阳春白雪") {gqupu9 = 1; qupu9 = inv[i];}
                        if(inv[i]->query("name") == "胡笳十八拍") {gqupu10 = 1; qupu10 = inv[i];}
		}
                        
	if( (arg== "高山流水" ) && (gqupu1 == 1)) 
	{
        destruct(qupu1);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu1", "done");
	return 1;
        } 
	if( (arg== "广陵散琴曲" ) && (gqupu2 == 1)) 
	{
        destruct(qupu2);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu2", "done");
	return 1;
        } 
	if( (arg== "平沙落雁" ) && (gqupu3 == 1)) 
	{
        destruct(qupu3);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu3", "done");
	return 1;
        } 
	if( (arg== "十面埋伏" ) && (gqupu4 == 1)) 
	{
        destruct(qupu4);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu4", "done");
	return 1;
        } 
	if( (arg== "渔樵问答" ) && (gqupu5 == 1)) 
	{
        destruct(qupu5);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu5", "done");
	return 1;
        } 
	if( (arg== "夕阳箫鼓" ) && (gqupu6 == 1)) 
	{
        destruct(qupu6);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu6", "done");
	return 1;
        } 
	if( (arg== "汉宫秋月" ) && (gqupu7 == 1)) 
	{
        destruct(qupu7);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu7", "done");
	return 1;
        } 
	if( (arg== "梅花三弄" ) && (gqupu8 == 1)) 
	{
        destruct(qupu8);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu8", "done");
	return 1;
        } 
	if( (arg== "阳春白雪" ) && (gqupu9 == 1)) 
	{
        destruct(qupu9);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu9", "done");
	return 1;
        } 
	if( (arg== "胡笳十八拍" ) && (gqupu10 == 1)) 
	{
        destruct(qupu10);
	message_vision (msgs[random(sizeof(msgs))],me);
	message_vision(HIG"古曲谱化做片片碎纸飘飞而去，$N心中恍然有所悟，急忙记下心中所得。\n"NOR,this_player());
	this_player()->set_temp("10qu/10qu10", "done");
	return 1;
        } 
return notify_fail("你要弹奏什么？\n");
}


