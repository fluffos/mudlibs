#include <ansi.h>
inherit ROOM;

mapping bagua = ([
	"1" : "坎水",
	"2" : "坤地",
	"3" : "震雷",
	"4" : "巽风",
	"5" : "中宫",
	"6" : "乾天",
	"7" : "兑泽",
	"8" : "艮山",
	"9" : "离火",
]);

mixed init_key()
{
	object me = this_player();
	string *ks,tmp,arg,anw,qust,ss,str = @STR
	
	     NORREVYEL        NOR         REVYEL        NOR  
             REVYEL   尊   NOR         REVYEL   尊   NOR
             REVYEL   父   NOR         REVYEL   兄   NOR
             REVYEL   李   NOR         REVYEL   哪   NOR
             REVYEL   天   NOR         REVYEL   吒   NOR
             REVYEL   王   NOR         REVYEL   三   NOR
             REVYEL   生   NOR         REVYEL   太   NOR
             REVYEL   位   NOR         REVYEL   子   NOR
             REVYEL        NORREVHIY   生    NORREVYEL        NOR
             REVYEL        NORREVHIY   位    NORREVYEL        NOR
             
STR;	
	str = COLOR_D->replace_color(str,1);
	if( time()>=query("last_key")+3600 
	 || !stringp(qust=query("quest")) )
	{
		set("last_key",time());
		ks = keys(bagua);
		tmp = "";
		anw = "";
		ss = "";
		arg = ks[random(sizeof(ks))];
		ss+= arg;
		tmp = bagua[arg];
		if( arg!="5" )
		{
			if( random(2) )
				anw+= sprintf("%s",tmp[0..1]);
			else	anw+= sprintf("%s",tmp[2..3]);
		}
		else	anw+= tmp;	
		ks-=({arg});
		anw+= "、";
		
		arg = ks[random(sizeof(ks))];
		ss+= arg;
		tmp = bagua[arg];
		if( arg!="5" )
		{
			if( random(2) )
				anw+= sprintf("%s",tmp[0..1]);
			else	anw+= sprintf("%s",tmp[2..3]);
		}
		else	anw+= tmp;	
		ks-=({arg});
		anw+= "、";
		
		arg = ks[random(sizeof(ks))];
		ss+= arg;
		tmp = bagua[arg];
		if( arg!="5" )
		{
			if( random(2) )
				anw+= sprintf("%s",tmp[0..1]);
			else	anw+= sprintf("%s",tmp[2..3]);
		}
		else	anw+= tmp;	
		ks-=({arg});
		anw+= "、";
		
		arg = ks[random(sizeof(ks))];
		ss+= arg;
		tmp = bagua[arg];
		if( arg!="5" )
		{
			if( random(2) )
				anw+= sprintf("%s",tmp[0..1]);
			else	anw+= sprintf("%s",tmp[2..3]);
		}
		else	anw+= tmp;	

		set("answer",ss);		
		set("quest",anw);
		qust=query("quest");
	}
	me->start_more(str);
	tell_object(me,CYN"\n隐约有声音在耳边传来：今日方位「"+qust+"」。"NOR"\n");
	return 1;
}

void create ()
{
  set ("short", "供室");
  set ("long", @LONG

近后壁处铺着一张龙吞口漆雕供桌。桌上有一个大流金香炉，炉内香
烟缭绕。香炉后面供着两块牌位。
    右面书架上散乱地堆着一些东西，书架边墙上有一个小木轮(wheel)，不知有何用处。
LONG);
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"inner-tang",
  "east" : __DIR__"cave2",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "wheel" : "
一个做得很精细的转盘，上有零到九几个数字。
",
		     "paiwei": (: init_key :),
]));

  setup();
}
void init()
{
  add_action("do_turn", "turn");
  add_action("do_turn", "zhuan");
}
int do_turn(string arg)
{
  object me=this_player();
  int mykee, mymaxkee, num, mypot, mylp, mynewpot;
  
  if ( !arg )
    return notify_fail("你要转什么？\n");
  if(arg=="wheel")
    return notify_fail("请输入相应的密码！\n譬如：turn 1 或 turn 1234。。。\n");
  mymaxkee=(int)me->query("max_kee");
  mykee=(int)me->query("kee");
  if(arg!=query("answer") )
    {
      message_vision(RED "只见一道火光从轮中窜出，直向$N扑来！\n" NOR, me);
      if (mykee<=200)
	{
	  me->set_temp("death_msg", "被烧成了飞灰。\n");
	  me->die();
	  me->save();
	  return 1;
	}
      me->receive_damage("kee", 200);
      me->receive_wound("kee", 180);
      message_vision(RED "$N显然伤得不轻！\n" NOR, me);	
      return 1;
    }			                                   
  else
    {
      message_vision("只听“叮”的一声，一道暗门突起，$N身不由己被推进暗室去了！\n", me);
      me->move(__DIR__"mishi");
      return 1;
    }
}
