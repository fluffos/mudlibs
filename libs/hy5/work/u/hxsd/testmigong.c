// Room: /city/guangchang.c
// YZC 1995/12/04 

inherit ROOM;

#include <ansi.h>

//#define TIME_TICK1 (time()*60-900000000)
#define TIME_TICK1 (time()*60)

string *default_dirs=({
"south",
"north",
"west",
"east",
});

mapping default_dirs2 = ([
	"north":	"北方",
	"south":	"南方",
	"east":		"东方",
	"west":		"西方",
	"northup":	"北边",
	"southup":	"南边",
	"eastup":	"东边",
	"westup":	"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":		"上面",
	"down":		"下面",
	"enter":	"里面",
	"out":		"外面",
	"leitai":	"擂台上面",
]);
string tname="testmigong";
string oname="/d/city/wumiao";
string mnpc="/d/city/npc/liumang";
string mboss="/d/city/npc/liumangtou";
string mbox="/clone/box/gbox";
int st=random(4);




void create ()
{
	//string tname,oname;
	int st2;
	if (st==0) st2=1;
	if (st==1) st2=2;
	if (st==2) st2=3;
	if (st==3) st2=2;


  set ("short", "迷宫测试");
  set ("long", @LONG
迷宫测试
LONG );
 

  set("hxsdmigong",1);

  set("box1",random(10)+1);
  set("box2",random(10)+11);
  set("box3",random(10)+21);
  set("box4",random(10)+31);
  set("box5",random(10)+41);
  set("mgnpc",random(3));
  set("mgboss","1");
  set("0",st);
  set("0b",default_dirs[st2]);
  set("1",random(4));
set("2",random(4));
set("3",random(4));
set("4",random(4));
set("5",random(4));
set("6",random(4));
set("7",random(4));
set("8",random(4));
set("9",random(4));
set("10",random(4));
set("11",random(4));
set("12",random(4));
set("13",random(4));
set("14",random(4));
set("15",random(4));
set("16",random(4));
set("17",random(4));
set("18",random(4));
set("19",random(4));
set("20",random(4));
set("21",random(4));
set("22",random(4));
set("23",random(4));
set("24",random(4));
set("25",random(4));
set("26",random(4));
set("27",random(4));
set("28",random(4));
set("29",random(4));
set("30",random(4));
set("31",random(4));
set("32",random(4));
set("33",random(4));
set("34",random(4));
set("35",random(4));
set("36",random(4));
set("37",random(4));
set("38",random(4));
set("39",random(4));
set("40",random(4));
set("41",random(4));
set("42",random(4));
set("43",random(4));
set("44",random(4));
set("45",random(4));
set("46",random(4));
set("47",random(4));
set("48",random(4));
set("49",random(4));
set("50",random(4));
set("51",random(4));
set("52",random(4));
set("53",random(4));
set("54",random(4));
set("55",random(4));
set("56",random(4));
set("57",random(4));
set("58",random(4));
set("59",random(4));
set("60",random(4));

set("startr",st2);
  set("exits", ([ 
default_dirs[st] : __DIR__+tname,
  "out" : oname,
	  	
]));

set("tname",tname);
  set("no_sleep_room", 1);
  setup();

}


int look_room(object me, object env)
{
        int i, j, k, l;
        object *inv;
        mapping exits,*data;
        string str, *dirs,str2,str1;
        mixed *cmds;
        k = 0;
	data = allocate(3000);

        if( !env ) {
                write("你的四周灰蒙蒙地一片，什么也没有。\n");
                return 1;
        }
// 天气颜色
       switch (NATURE_D->outdoor_room_outcolor())
        {
              case "BLK":
        str = sprintf( BLK + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + BLK + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "RED":
        str = sprintf( RED + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + RED + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIR":
        str = sprintf( HIR + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIR + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "GRN":
        str = sprintf( GRN + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + GRN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIG":
        str = sprintf( HIG + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "YEL":
        str = sprintf( YEL + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + YEL + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIY":
        str = sprintf( HIY + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIY + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "BLU":
        str = sprintf( BLU + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + BLU + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIB":
        str = sprintf( HIB + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIB + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "MAG":
        str = sprintf( MAG + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + MAG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIM":
        str = sprintf( HIM + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIM + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "CYN":
        str = sprintf( CYN + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + CYN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIC":
        str = sprintf( HIC + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIC + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "WHT":
        str = sprintf( WHT + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + WHT + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIW":
        str = sprintf( HIW + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIW + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              default:
        str = sprintf( HIC + "【"+ "%s"+"】"+ NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
	}

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
//                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
//                                dirs[i] = 0;
                dirs -= ({ 0 });

		if( sizeof(dirs)==0 )
                        str += HIR + "    这里没有任何明显的出路。\n"NOR;
		else if( sizeof(dirs)==1 )
                        str += YEL + "    这里明显的"+ HIC +"【出口】"+ HIG +"是" + BOLD + dirs[0] + NOR + "。\n";
		else
                        str += sprintf(  HIG + "    这里明显的"+ HIC +"【出口】"+ HIG +"是" + BOLD + "%s" + NOR + " " + HIG + "和  " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
        inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++) {
 			if (inv[i]!=me 
			&&  me->visible(inv[i])
			&&  !inv[i]->query("money_id")
			&&  !inv[i]->query_temp("check_only"))
			{
				data[k]=([]);
				for(j = i; j < sizeof(inv); j++ )
				{
					if ( inv[i]->query("name")==inv[j]->query("name")
					&&   inv[i]->query("id")==inv[j]->query("id")
					&&   !inv[j]->query_temp("check_only") )
					{
						data[k]["id"]=inv[i]->short();
						data[k]["unit"]=inv[i]->query("unit");
						data[k]["num"]= data[k]["num"] + 1;
						inv[j]->set_temp("check_only", 1);
					}
					else continue;
				}
				k++;
			}
			else continue;
		}

		for (i = 0; i < sizeof(inv); i++) {
			if ( !inv[i]->query_temp("check_only") && inv[i]!=me && me->visible(inv[i]) )
			str += sprintf("%s%s\n", "  ", inv[i]->short());
		}

		for (i = 0; i < sizeof(inv); i++)
			if ( inv[i]->query_temp("check_only") )
				inv[i]->delete_temp("check_only");

		if (k > 0)
		{
			for (l = 0; l < k; l++)
				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
            }
        write(str);
        return 1;
}


int valid_leave(object me, string dir)
{
object env,fang;
int i,wjxh,j,wjxh2,k,addok;
string dir2,dir3,dir1,dir4,dir5,dir6;
mapping exit;
object *inv;
env = this_object();
wjxh=me->query_temp("migongxh");
if (me->is_fighting())
			return notify_fail("你正在战斗中。\n");
if (me->is_busy())
			return notify_fail("你正在忙乱中。\n");


if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
			return notify_fail("这个方向没有出路。\n");

dir1=env->query("addlj");
dir2=env->query("dellj");
dir4=env->query("addlj");
dir5=env->query("dellj");

addok=2;

if (!me->query_temp("migongxh")) 
{
addok=1;
me->set_temp("migongxh",1);
}
if (dir1 && dir2 )
{
if (dir==dir1 && addok=2)
 {
addok=1;
me->add_temp("migongxh",1);
}

if (dir==dir2)  {
addok=2;
me->add_temp("migongxh",-1);
}
}	


wjxh2=me->query_temp("migongxh");

if (me->query_temp("migongxh",1)<0) me->set_temp("migongxh",0);
if (me->query_temp("migongxh",1)>60) me->set_temp("migongxh",60);

j=env->query(""+wjxh2+"");
dir6=env->query(""+wjxh2+"b");
k=env->query(""+wjxh+"");
if (dir=="west") dir3="east";
if (dir=="east") dir3="west";
if (dir=="south") dir3="north";
if (dir=="north") dir3="south";

	

if (default_dirs[j]==dir3 && addok==1)
{
tell_object(me, "调整方向"+wjxh2+"原方向" + default_dirs[j] + "。\n");	
if (j==1  && random(2)==0) j=2;
else if (j==1 && random(2)==0) j=0;
else if (j==1) j=3;
else if (j==2 && random(2)==0) j=3;
else if (j==2 && random(2)==0) j=1;
else if (j==2) j=0;
else if (j==3 && random(2)==0) j=0;
else if (j==3 && random(2)==0) j=1;
else if (j==3) j=2;
else if (j==0 && random(2)==0) j=1;
else if (j==0 && random(2)==0) j=2;
else if (j==0) j=3;

tell_object(me, "调整方向"+wjxh2+"调整为" + default_dirs[j] + "。\n");
env->set(""+wjxh2+"",j);	
}


tell_object(me, "方向" + dir + "。\n");
tell_object(me, "玩家序号" + me->query_temp("migongxh",1) + "。\n");
tell_object(me, "产生路径"+wjxh2+":" + default_dirs[j] + "。\n");
tell_object(me, "产生路径2" + dir3 + "。\n");
tell_object(me, "上次路径4" + dir4 + "。\n");
tell_object(me, "上次路径5" + dir5 + "。\n");

tell_object(me, "0" + env->query("0") + "。\n");
tell_object(me, "0b" + env->query("0b") + "。\n");

tell_object(me, "1" + env->query("1") + "。\n");
tell_object(me, "1b" + env->query("1b") + "。\n");
tell_object(me, "2" + env->query("2") + "。\n");
tell_object(me, "2b" + env->query("2b") + "。\n");
tell_object(me, "3" + env->query("3") + "。\n");
tell_object(me, "3b" + env->query("3b") + "。\n");
tell_object(me, "4" + env->query("4") + "。\n");
tell_object(me, "4b" + env->query("4b") + "。\n");
tell_object(me, "5" + env->query("5") + "。\n");
tell_object(me, "5b" + env->query("5b") + "。\n");
if (dir=="out")
{
me->set_temp("migongxh",0);
me->delete_temp("migongxh");
me->move(oname);
tell_object(me, "移动" + oname + "。\n");
return notify_fail("你向"+default_dirs2[dir]+"走去。\n");
}
env->delete("exits");

if (wjxh2==0)
{
me->delete_temp("migongxh");	
env->delete("addlj");
env->delete("dellj");	
env->set("exits/out",oname);
env->set("exits/"+default_dirs[st],__DIR__+tname);
env->set("addlj",default_dirs[st]);
env->set("dellj","out");
}
else
if (wjxh2==60)
{
env->set("exits/out",oname);
env->delete("addlj");
env->delete("dellj");

}
else
{
dir4=default_dirs[j];
dir5=dir3;
if (addok==2) 
{
//dir4=env->query("addlj");
//if (env->query("addlj"))
//dir4=env->query("addlj");
if (dir6)
dir5=dir6;
if (addok==2) tell_object(me, "减少"+dir6+"处理。\n");
}	
env->set("exits/"+dir4,__DIR__+tname);
env->set("exits/"+dir5,__DIR__+tname);
env->set("addlj",dir4);
env->set("dellj",dir5);
if (random(10)==0)
{	
env->set("exits/"+default_dirs[random(3)],__DIR__+tname);
env->set("exits/"+default_dirs[random(3)],__DIR__+tname);
}
env->set(""+wjxh+"b",dir3);
}
if (addok==2) tell_object(me, "减少 。\n");
if (addok==1) tell_object(me, "增加 。\n");


        inv = all_inventory(env);
		for (i = 0; i < sizeof(inv); i++) {
 			if (inv[i]!=me 
			&&  !userp(inv[i])
)
			{
destruct(inv[i]);
			}

		}
if (random(30)==0 && (env->query("killbh",1) <=3 || !env->query("killbh"))) 
{
if (me->query_temp("migongxh",1)<=5) me->set_temp("migongxh",1);	
if (me->query_temp("migongxh",1)>=10) me->set_temp("migongxh",(random(10)+1));	
if (me->query_temp("migongxh",1)>=20) me->set_temp("migongxh",(random(10)+10));	
if (me->query_temp("migongxh",1)>=30) me->set_temp("migongxh",(random(10)+20));	
tell_object(me, "只见四周光影晃动，，等一切安静下来，周遭景象似乎有所改变。\n");
env->add("killbh",1);	
}

if (random(5)==0 && (env->query("killdl",1) <=20 || !env->query("killdl")) ) 
{
fang = new(mnpc);
	fang->move(env);	
	fang->kill_ob(me);
if (random(2)==0)
fang = new(mnpc);
	fang->move(environment(me));	
	fang->kill_ob(me);
if (!me->is_busy()) me->start_busy(1);
env->add("killdl",1);	
	
}

if (me->query_temp("migongxh",1)==env->query("box1") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box1",999);	
}

if (me->query_temp("migongxh",1)==env->query("box2") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box2",999);	
}

if (me->query_temp("migongxh",1)==env->query("box3") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box3",999);	
}

if (me->query_temp("migongxh",1)==env->query("box4") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box4",999);	
}

if (me->query_temp("migongxh",1)==env->query("box5") ) 
{
fang = new(mbox);
	fang->move(env);	
env->set("box5",999);	
}

if (me->query_temp("migongxh",1)==60 && !env->query("killbs") ) 
{
fang = new(mboss);
	fang->move(env);	
	fang->kill_ob(me);

env->set("killbs",1);	
	
}


	//seteuid(getuid());
	look_room(me,env);
	return notify_fail("你向"+default_dirs2[dir]+"走去。\n");
	return ::valid_leave(me, dir);
}