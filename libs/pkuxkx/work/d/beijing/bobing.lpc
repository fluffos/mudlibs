//bobing.c -博饼屋
//有Bug，去掉奖励，仅供消遣
#include <room.h>
#include <ansi.h>
inherit ROOM;
int Maxperson,minperson;
int allow_leave,allow_start;
int Max1,Max2,Max3,Max4,Max5,Max6;
int Realmode;
object* member,leader,dutang1,dutang2,winner;
string roomname;
int add_member(object ob);
int delete_member(object ob);
int query_member(object ob);
void do_yao();
string getit(object,int,int,string);
string checkcolor(int);
int countit( int,int,int,int,int,int,int);
int pass_token(int,int);
int startreal();
int stopreal();
void create()
{
    Maxperson=10;
    minperson=2;
    allow_leave=1;
    allow_start=0;
    Max1=32;//一秀的个数
    Max2=16;//二举的个数
    Max3=8; //四进的个数
    Max4=4; //三红的个数
    Max5=2; //对堂的个数
    Max6=1; //状元的个数
    Realmode=1;
    roomname="博饼屋";
    set("no_fight","1");
    set("no_magic","1");
    set("no_steal","1");
    set("no_beg","1");
    set("short",HIC"博饼屋"NOR);
    set("long",
CYN"这是一间古朴典雅的的博饼屋。房间的装修充满了盛明时候的风味，满屋子
的琳琅玉石衬着柔和的光线，洋溢着温馨的气氛，真是个温暖而热闹的地方。房
间的四周点着一溜松明子，中间一张楠木桌，大家都席地而坐 (sit)，看着桌面
上一个大海碗，碗里面滴溜溜转着六颗玉制的骰子！南边的墙上贴着一张发黄的
陈纸(paper)。\n"NOR
);
    set("item_desc", ([
        "paper" : @LONG              
		博饼屋命令及闽南博饼游戏介绍
               =====================================

　　“博饼”是流行于福建一带的中秋节时的一种庆祝佳节的活动。相传为国姓
爷郑成功为鼓舞军中士气而发明。玩家人数没有严格限制，以掷六个骰子的组合
来决定大小，遴选出当年彩头的归属。

一．博饼游戏方法:
　  先用（sit ）坐下来才能加入到博饼游戏中。
　  几个人轮流掷六个骰子，在轮到你时，请使用（throw）命令。
    可用（view）查看已加入游戏的玩家。
 　 离开时用（leave）命令才能离开博饼游戏。

二．博饼游戏规则：
　  总共六个骰子，大小顺序排列如下:
　  六个四        　六  红 （通吃）
　  六个相同      　六  黑 （通吃）
　  四个四加两个一　状元插金花
  　五个四          五  红
  　五个其他的      五  主
  　四个四          状  元
    一至六各一个    对  堂
  　三个四          三  红
  　四个同点子的　  四  进 （四除外）
  　两个四          二  举
  　一个四          一  秀
LONG,
    ]));
    set("exits", ([
	         "south" : __DIR__"changanjie_w",
    ]));
    set("no_clean_up",1);
    setup();
}

void init(){
    add_action("fsit","sit");
    add_action("fleave","leave");
    add_action("fview","view");
    add_action("fyao","throw");
    add_action("startreal","start");
    add_action("stopreal","stop");
}

int startreal()
{
	object ob;
	object* pl;
	ob=this_player();
	if (wizardp(ob))
	{
		Realmode=1;
		pl=users();
		return 1;
	}
	return 0;
}

int stopreal()
{
	object ob;
	object* pl;
	ob=this_player();
	if (wizardp(ob))
	{
		Realmode=1;
		pl=users();
		return 1;
	}
	return 0;
}
int pass_token(int index,int passmode)
{
	int me,i,passok;
	me=index-1;
	allow_leave=0;
	passok=0;
	if( passmode==0)
	{
		for(i=0;i<sizeof(member)-1;i++)
		{
			index=index+i;
			if (index>=sizeof(member)) index=index-sizeof(member);
                          if (index>=sizeof(member)) index=sizeof(member)-1;
			if (interactive(member[index]))
			{
				passok=1;
				leader=member[index];
				break;
			}
		}
		if ((!passok)||(sizeof(member)<minperson))
		{
			allow_start=0;
	tell_room(environment(leader),"陪你玩的人还不够，等人来了吧。\n");
		} else
tell_room(environment(leader),"现在轮到"+leader->query("name")+"掷了。\n");
	}
	if(passmode==1)
	{
		if (index>=sizeof(member)) index=index-sizeof(member);
		passok=1;
		leader=member[index];
	}
	allow_leave=1;
}

int fyao()
{
	object ob;
	int i,j,k;
	ob=this_player();
	i=query_member(ob);
	if (allow_start )
	{
		if (i>0)
		{
			if(ob==leader)
			{
				do_yao();
				pass_token(i,0);
				return 1;
			}
			else
			notify_fail(CYN"还没轮到你呢，瞎嚷嚷个啥劲呢！\n"NOR);
		}
		else notify_fail(CYN"你要先坐下来才能和大家一起博饼。\n"NOR);
	}
	else notify_fail(YEL"现在人还不够，悠着点吧。\n"NOR);
}

int fview()
{
	object ob;
	int i;
	ob=this_player();
	if (!arrayp(member)||sizeof(member)==0) notify_fail("没人在这博饼。\n");
	else
	{
printf("玩家          最高奖       一秀  二举  四进  三红  对堂  状元\n");
printf("=============================================================\n");
		for(i=0;i<sizeof(member);i++)
		{
printf("%-14s%-11s%6d%6d%6d%6d%6d%6d\n",
member[i]->query("name"),member[i]->query_temp("cocacola/dest"),
member[i]->query_temp("cocacola/g1"),member[i]->query_temp("cocacola/g2"),
member[i]->query_temp("cocacola/g3"),member[i]->query_temp("cocacola/g4"),
member[i]->query_temp("cocacola/g5"),member[i]->query_temp("cocacola/g6"),);
		}
printf("=============================================================\n");
if(objectp(winner)) printf("现在的状元是由%s保持..\n",winner->query("name"));
if(objectp(leader)) printf("现在该轮到%s掷了\n",leader->query("name"));
return 1;
	}
}

int fleave()
{
	object ob;
	object nil;
	ob=this_player();
	if (query_member(ob)) pass_token(query_member(ob),1);
	message_vision(HIG"$N离开了大家玩不成了！\n"NOR,ob);
	Maxperson++;
	delete_member(ob);
	if(ob=winner) winner=nil;
	return 1;
}

int fsit()
{
	object ob;
	ob=this_player();
	if (!(query_member(ob)))
	{
		if (Maxperson>0)
		{
	message_vision(HIC"$N坐下来和大家一起博饼。\n"NOR,ob);
			Maxperson--;
			add_member(ob);
			ob->set_temp("cocacola/dest","");
		}
		else tell_object(ob,HIY"这一桌满了，你去别处看看吧。\n"NOR);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if( query_member(me) )
		return notify_fail(HIB"你要先离开博饼桌才能离开这里。\n"NOR);
	return 1;
}

int delete_member(object ob)
{
	int i;
	if (!arrayp(member)) return 0;
	for (i=0;i<sizeof(member);i++)
	{
        	if (member[i]==ob)
		{
			member-=({ob});
			ob->delete_temp("cocacola");
			break;
		}
	}
}

int add_member(object ob)
{
	if (!arrayp(member))
	{
		member=({ob});
		leader=ob;
	}
	else
	{
		member+=({ob});
		if (sizeof(member)>=minperson)
		{
			allow_start=1;
tell_room(environment(leader),"太好了，人凑够了，可以开始玩了。\n");
tell_room(environment(leader),leader->query("name")+"先掷吧。\n");
		}
	}
	return 1;
}

int query_member(object ob)
{
	int i;
	if (!arrayp(member)) return 0;
	for (i=0;i<sizeof(member);i++)
	{
		if (member[i]==ob)
		{
			return i+1;
		}
	}
	return 0;
}

void do_yao()
{
	int s1,s2,s3,s4,s5,s6,c1,c2,c3,c4,c5,c6,getaward,getscore;
	object ob;
	string result,dest;
	ob=this_player();
	getscore=0;
	dest="";
	s1=random(5)+1;
	s2=random(5)+1;
	s3=random(5)+1;
	s4=random(5)+1;
	s5=random(5)+1;
	s6=random(5)+1;
//按点数统计
	c1=countit(s1,s2,s3,s4,s5,s6,1);//一的个数
	c2=countit(s1,s2,s3,s4,s5,s6,2);//二的个数
	c3=countit(s1,s2,s3,s4,s5,s6,3);//三的个数
	c4=countit(s1,s2,s3,s4,s5,s6,4);//四的个数
	c5=countit(s1,s2,s3,s4,s5,s6,5);//五的个数
	c6=countit(s1,s2,s3,s4,s5,s6,6);//六的个数

	if(c1==6||c2==6||c3==6||c4==6||c5==6||c6==6)
	{
		getaward=6;
		if(c1==6)
		{
			dest="六  黑(一)";
			getscore=1201;
		}
		if(c2==6)
		{
			dest="六  黑(二)";
			getscore=1202;
		}
		if(c3==6)
		{
			dest="六  黑(三)";
			getscore=1203;
		}
		if(c5==6)
		{
			dest="六  黑(五)";
			getscore=1204;
		}
		if(c6==6)
		{
			dest="六  黑(六)";
			getscore=1205;
		}
		if(c4==6)
		{
			dest="六  红(通吃)";
			getscore=1206;
		}
	}
	else
	if(c4==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五红带一";
			getscore=1102;
		}
		if(c2==1)
		{
			dest="五红带二";
			getscore=1103;
		}
		if(c3==1)
		{
			dest="五红带三";
			getscore=1104;
		}
		if(c5==1)
		{
			dest="五红带五";
			getscore=1105;
		}
		if(c6==1)
		{
			dest="五红带六";
			getscore=1106;
		}
	}
	else
	if(c6==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(六)带一";
			getscore=1002;
		}
		if(c2==1)
		{
			dest="五主(六)带二";
			getscore=1003;
		}
		if(c3==1)
		{
			dest="五主(六)带三";
			getscore=1004;
		}
	 	if(c5==1)
		{
			dest="五主(六)带五";
			getscore=1005;
		}
		if(c4==1)
		{
			dest="五主(六)带四";
			getscore=1006;
		}
	}
	else
	if(c5==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(五)带一";
			getscore=902;
		}
		if(c2==1)
		{
			dest="五主(五)带二";
	 		getscore=903;
		}
		if(c3==1)
		{
			dest="五主(五)带三";
			getscore=904;
		}
		if(c6==1)
		{
			dest="五主(五)带六";
			getscore=905;
		}
		if(c4==1)
		{
			dest="五主(五)带四";
			getscore=906;
		}
	}
	else
	if(c3==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(三)带一";
			getscore=802;
		}
		if(c2==1)
		{
			dest="五主(三)带二";
			getscore=803;
		}
		if(c5==1)
		{
			dest="五主(三 )带五";
			getscore=804;
		}
		if(c6==1)
		{
			dest="五主(三)带六";
			getscore=805;
		}
		if(c4==1)
		{
			dest="五主(三)带四";
			getscore=806;
		}
	}
	else
	if(c2==5)
	{
		getaward=6;
		if(c1==1)
		{
			dest="五主(二)带一";
			getscore=702;
		}
		if(c3==1)
		{
			dest="五主(二)带三";
			getscore=703;
		}
		if(c5==1)
		{
			dest="五主(二)带五";
			getscore=704;
		}
		if(c6==1)
		{
			dest="五主(二)带六";
			getscore=705;
		}
		if(c4==1)
		{
			dest="五主(二)带四";
			getscore=706;
		}
	}
	else
	if(c1==5)
	{
		getaward=6;
		if(c2==1)
		{
			dest="五主(一)带二";
			getscore=602;
		}
		if(c3==1)
		{
			dest="五主(一)带三";
			getscore=603;
		}
		if(c5==1)
		{
			dest="五主(一)带五";
			getscore=604;
		}
		if(c6==1)
		{
			dest="五主(一)带六";
			getscore=605;
		}
		if(c4==1)
		{
			dest="五主(一)带四";
			getscore=606;
		}
	}
	else
	if (c4==4)
	{
		getaward=6;
		if((s1+s2+s3+s4+s5+s6-16)==2)
		{
			dest="状元插金花";
			getscore=1100;
		}
		if((s1+s2+s3+s4+s5+s6-16)==12)
		{
			dest="状元带十二";
			getscore=512;
		}
		if((s1+s2+s3+s4+s5+s6-16)==11)
		{
  			dest="状元带十一";
			getscore=511;
		}
		if((s1+s2+s3+s4+s5+s6-16)==10)
		{
			dest="状元带十";
			getscore=510;
		}
		if((s1+s2+s3+s4+s5+s6-16)==9)
		{
			dest="状元带九";
			getscore=509;
		}
		if((s1+s2+s3+s4+s5+s6-16)==8)
		{
			dest="状元带八";
			getscore=508;
		}
		if((s1+s2+s3+s4+s5+s6-16)==7)
		{
			dest="状元带七";
			getscore=507;
		}
		if((s1+s2+s3+s4+s5+s6-16)==6)
		{
			dest="状元带六";
			getscore=506;
		}
		if((s1+s2+s3+s4+s5+s6-16)==5)
		{
			dest="状元带五";
			getscore=505;
		}
		if((s1+s2+s3+s4+s5+s6-16)==4)
		{
			dest="状元带四";
			getscore=504;
		}
		if((s1+s2+s3+s4+s5+s6-16)==3)
		{
			dest="状元带三";
			getscore=503;
		}
	}
	else
	if(c1==4||c2==4||c3==4||c5==4||c6==4)
	{
		getaward=3;
		if (c4==2)
		{
			getscore=302;
			dest="四进带二举";
		}
		if(c4==1)
		{
			getscore=301;
			dest="四进带一秀";
		}
		if(c4==0)
		{
			getscore=300;
			dest="四进";
		}
	}
	else
	if(c4==3)
	{
		getaward=4;
		getscore=400;
		dest="三红";
	}
	else
	if(c4==2)
	{
		getaward=2;
		getscore=200;
		dest="二举";
	}
	else
	if (c4==1)
	{
		if(c1==1&&c2==1&&c3==1&&c5==1&&c6==1)
		{
			getaward=5;
			getscore=500;
			dest="对堂";
		}
		else
		{
			getaward=1;
			getscore=100;
			dest="一秀";
		}
	}
	else
	{
		getaward=0;
		getscore=0;
		dest="………哇塞！居然什么都不是哦！？真同情你，呵呵呵呵。";
	}
	result= " -------  -------  -------  -------  -------  -------\n"+
		"|       ||       ||       ||       ||       ||       |\n"+
		"|   "+checkcolor(s1)+"%d"+NOR+
		"   ||   "+checkcolor(s2)+"%d"+NOR+
		"   ||   "+checkcolor(s3)+"%d"+NOR+
		"   ||   "+checkcolor(s4)+"%d"+NOR+
		"   ||   "+checkcolor(s5)+"%d"+NOR+
		"   ||   "+checkcolor(s6)+"%d"+NOR+
		"   |\n"+
		"|       ||       ||       ||       ||       ||       |\n"+
		" -------  -------  -------  -------  -------  -------\n";
	result=sprintf(result,s1,s2,s3,s4,s5,s6);
	result=result+"\n居然是个"+dest+"加油啊。\n";
	message_vision(HIC"$N抓起六个骰子放在手心里拼命摇，然后团起手来向手\n"+
"中吹了口气，口中还神神叨叨地念念有词：天灵灵，地灵灵……来来来，开了……\n"NOR+result,ob);
	getit(ob,getaward,getscore,dest);
}

string checkcolor(int i)
{
	if(i==1||i==4) return RED;
	else return GRN;
}

int countit(int s1,int s2,int s3,int s4,int s5,int s6,int sd)
{
	int i;
	i=0;
	if (s1==sd) i++;
	if (s2==sd) i++;
	if (s3==sd) i++;
	if (s4==sd) i++;
	if (s5==sd) i++;
	if (s6==sd) i++;
	return i;
}

string getit(object ob,int getaward,int getscore,string dest)
{
	object* play;
	if (getaward>(ob->query_temp("cocacola/maxaward")))
	{
		ob->set_temp("cocacola/maxaward",getaward );
		ob->set_temp("cocacola/dest",dest);
	}
	if (getscore>(ob->query_temp("cocacola/maxscore")))
		ob->set_temp("cocacola/maxscore",getscore);
	if (getaward==1)
	{
		ob->set_temp("cocacola/g1",ob->query_temp("cocacola/g1")+1);
		if (Max1<=0 )
		{
tell_room(environment(ob),CYN"可惜啊！一秀已全被博光了！继续努力吧……\n"NOR);
		}
		else
		{
			if(Realmode)
			{
//				ob->add("combat_exp",100);
		message_vision(YEL"$N博到一秀一个，恭喜恭喜，但是没有奖品……\n"NOR,ob);
				Max1--;
			}
			else
message_vision(CYN"$N博到一秀一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==2)
	{
		ob->set_temp("cocacola/g2",ob->query_temp("cocacola/g2")+1);
		if (Max2<=0 )
		{
tell_room(environment(ob),CYN"可惜啊！二举已全被博光了，继续努力吧……\n"NOR);
		}
		else
		{
			if(Realmode)
			{
//				ob->add("combat_exp",200);
//				ob->add("potential",5);
	message_vision(YEL"$N博到二举一个，恭喜恭喜，但是没有奖品……\n"NOR,ob);
				Max2--;
			}
			else
message_vision(CYN"$N博到二举一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==3)
	{
		ob->set_temp("cocacola/g3",ob->query_temp("cocacola/g3")+1);
		if (Max3<=0 )
		{
tell_room(environment(ob),CYN"可惜啊！四进已全被博光了，继续努力吧……\n"NOR);
		}
		else
		{
			if(Realmode)
			{
//				ob->add("combat_exp",500);
//				ob->add("potential",15);
message_vision(HIY"$N博到四进一个，恭喜恭喜，但是没有奖品……\n"NOR,ob);
				Max3--;
			}
			else
message_vision(CYN"$N博到四进一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==4)
	{
		ob->set_temp("cocacola/g4",ob->query_temp("cocacola/g4")+1);
		if (Max4<=0 )
		{
tell_room(environment(ob),CYN"可惜啊！三红已全被博光了，继续努力吧……\n"NOR);
		}
		else
		{
			if(Realmode)
			{
//				ob->add("combat_exp",888);
//				ob->add("potential",30);
//				ob->add("con",1);
message_vision(HIY"$N博到三红，恭喜恭喜，但是没有奖品……\n"NOR,ob);
				Max4--;
			}
			else
message_vision(CYN"$N博到三红一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==5)
	{
		ob->set_temp("cocacola/g5",ob->query_temp("cocacola/g5")+1);
		if (Max5<=0 )
		{
tell_room(environment(ob),CYN"可惜啊！对堂已全被博光了，继续努力吧……\n"NOR);
		}
		else
		{
			if(Realmode)
			{
//				ob->add("combat_exp",1000);
//				ob->add("potential",50);
//				ob->add("int",1);
//				ob->add("con",1);
message_vision(HIY"$N博到对堂一个！恭喜恭喜，但是没有奖品……\n"NOR,ob);
				Max5--;
			}
			else
message_vision(CYN"$N博到对堂一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
		}
	}
	if (getaward==6)
	{
		ob->set_temp("cocacola/g6",ob->query_temp("cocacola/g6")+1);
		if(Realmode)
		{
//			ob->add("combat_exp",2000);
//			ob->add("potential",88);
//			ob->add("int",1);
//			ob->add("con",1);
//			ob->add("str",1);
//			ob->add("dex",1);
message_vision(HIY"$N博到状元一个，恭喜恭喜，但是没有奖品……\n"NOR,ob);
		}
		else
message_vision(CYN"$N博到状元一个，真是可惜巫师不在，没有奖品……\n"NOR,ob);
	}
}