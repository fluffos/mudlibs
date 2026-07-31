// map.c
#define MaxX 15
#define MaxY 20
#define MinX 7
#define MinY 10

inherit F_CLEAN_UP;


#include "ansi.h"
#include "/doc/help.h"
static int X,Y;
static mixed m;
static string *rfile;
static mapping *data;
int draw_room(int,int,object);
int main2(object me);
void set_room(int,int,object);
void set_x_y(int,int,int);

// 转换颜色
string clean_color2(string arg)
{
    if(!arg)     return "";
    arg = replace_string(arg, BLK, "");
    arg = replace_string(arg, RED, "");
    arg = replace_string(arg, GRN, "");
    arg = replace_string(arg, YEL, "");
    arg = replace_string(arg, BLU, "");
    arg = replace_string(arg, MAG, "");
    arg = replace_string(arg, CYN, "");
    arg = replace_string(arg, WHT, "");
    arg = replace_string(arg, HIR, "");
    arg = replace_string(arg, HIG, "");
    arg = replace_string(arg, HIY, "");
    arg = replace_string(arg, HIB, "");
    arg = replace_string(arg, HIM, "");
    arg = replace_string(arg, HIC, "");
    arg = replace_string(arg, HIW, "");
    arg = replace_string(arg, NOR, "");
    arg = replace_string(arg, BLINK,"");
    return arg;
}

string clean_color(string arg);
string getwhere(object ob);
string make_color(string map);
string *dirs = ({
	"north",
	"south",
	"east",
	"west",
	"northup",
	"southup",
	"eastup",
	"westup",
	"northdown",
	"southdown",
	"eastdown",
	"westdown",
	"northeast",
	"northwest",
	"southeast",
	"southwest",
	"up",
	"down",
	"enter",
	"out",
});
int main(object me, string arg)
{
	int i, j, jj = 0, k, kk = 0;
	string file,map,name,dest,*search;
	mapping exit1, exit2, exit3;
	object room1, room2, room3, room4;
string *dir2;
	seteuid(getuid());
	if (!arg || arg == "here")
	{
		if( !file = environment(me)->query("outdoors"))
		{
			room1 = environment(me);
			if( mapp(exit1 = room1->query("exits")))
			{
				for (i=0; i<sizeof(dirs); i++)
				{
					if(dest = exit1[dirs[i]])
					{
						if(!(room2 = find_object(dest)))
							room2=load_object(dest);
						if(file=room2->query("outdoors"))
							break;
						else
						{
							if( mapp(exit2 = room2->query("exits")))
							{
								for (j=0; j<sizeof(dirs); j++)
								{
									if(dest = exit2[dirs[j]])
									{
										if(!( room3 = find_object(dest)) )
											room3 = load_object(dest);
										if( file = room3->query("outdoors"))
										{
											jj = 1;
											break; 
										}
										else
											if( mapp(exit3 = room3->query("exits")))
											{
												for (k=0; k<sizeof(dirs); k++)
												{
													if(dest = exit3[dirs[k]])
													{
														if(!( room4 = find_object(dest)) )
															room4 = load_object(dest);
														if( file = room4->query("outdoors"))
														{
															kk = 1;
															break; 
														}
													}
												}
											}
										if (kk == 1)
										{
											jj = 1;
											break;
										}
									}
								}
							}
						}
						if (jj == 1) break;
					}
				}
			}
			if (i==sizeof(dirs))
				return notify_fail(HIG"这里不能查看地图，请到室外。\n"NOR);
		}
		name = clean_color(environment(me)->query("short"));
if( file_size("/doc/map/" + file)<=0 )
{
dir2=explode(base_name(environment(me)),"/");
file=dir2[1];
}
		if( file_size("/doc/map/" + file)>0 ) 
		{
			if(stringp(map = read_file("/doc/map/" + file)))
			{
				//map = make_color(map);
				map = replace_string(map, name, HIR+name+NOR);
				//me->start_more(map);
				write("$map"+ map + "$#\n");
				return 1;
			}
		}

    if(me->is_busy() )
        return notify_fail("你的体力不太好了，先休息一下吧！\n");
    if (!me->is_busy()) me->start_busy(3);
		main2(me);
		return notify_fail(HIY"暂时还没有开放这里的地图查询，只能提供即时地图查询。\n"NOR);
	}
	else
	{
		if( file_size("/doc/map/" + arg)>0 ) 
		{
			if(stringp(map = read_file("/doc/map/" + arg)))
			{
//				map = make_color(map);
				//me->start_more(map);
				write("$map"+ map + "$#\n");
				return 1;
			}
		}
		return notify_fail(HIR"没有你指定的地图查询。请help maps查询地图册。\n"NOR);
	}
}
string clean_color(string arg)
{
	if(!arg) return "";
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
	arg = replace_string(arg, BLINK,"");
	return arg;
}

string make_color(string map)
{
	map = replace_string(map, "★", HIR"★"NOR);
	map = replace_string(map, "≈", HIC"≈"NOR);
	map = replace_string(map, "～", HIC"～"NOR);
	map = replace_string(map, "∧", HIG"∧"NOR);
	map = replace_string(map, "ψ", GRN"ψ"NOR);
	map = replace_string(map, "♀", HIR"♀"NOR);
	map = replace_string(map, "±", HIM"±"NOR);
	map = replace_string(map, "＋", HIG"＋"NOR);
	map = replace_string(map, "∴", YEL"∴"NOR);
	map = replace_string(map, "∷", YEL"∷"NOR);
	map = replace_string(map, "≌", HIW"≌"NOR);
	map = replace_string(map, "＊", MAG"＊"NOR);
	map = replace_string(map, "—", HIY"—"NOR);
	map = replace_string(map, "｜", HIY"｜"NOR);
	map = replace_string(map, "＼", HIY"＼"NOR);
	map = replace_string(map, "／", HIY"／"NOR);
	map = replace_string(map, "↑", HIY"↑"NOR);
	map = replace_string(map, "↓", HIY"↓"NOR);
	map = replace_string(map, "→", HIY"→"NOR);
	map = replace_string(map, "←", HIY"←"NOR);
	map = replace_string(map, "─", HIY"─"NOR);
	map = replace_string(map, "│", HIY"│"NOR);
	map = replace_string(map, "┼", HIY"┼"NOR);
	map = replace_string(map, "┌", HIY"┌"NOR);
	map = replace_string(map, "┐", HIY"┐"NOR);
	map = replace_string(map, "└", HIY"└"NOR);
	map = replace_string(map, "┘", HIY"┘"NOR);
	map = replace_string(map, "┬", HIY"┬"NOR);
	map = replace_string(map, "┴", HIY"┴"NOR);
	map = replace_string(map, "├", HIY"├"NOR);
	map = replace_string(map, "┤", HIY"┤"NOR);
	map = replace_string(map, "-", HIY"-"NOR);
	map = replace_string(map, "~", HIC"~"NOR);
	map = replace_string(map, "|", HIC"|"NOR);
	map = replace_string(map, "@", HIW"@"NOR);
	map = replace_string(map, "*", GRN"@"NOR);
	map = replace_string(map, "<", GRN"<");
	map = replace_string(map, ">", ">"NOR);
	map = replace_string(map, "【", YEL"【");
	map = replace_string(map, "】", "】"NOR);
	map = replace_string(map, "〖", CYN"〖"NOR);
	map = replace_string(map, "〗", CYN"〗"NOR);
	return map;
}


string getwhere(object ob)
{
       object tmpobj,where, *ob_list,me,obtwo,obthree,tob;

        object item,room;

        string output,outputt,dis,alt,dir,local,tlocal,ck,playout;
        
        int i;

        int x,y,z,x0,y0,z0;

        int realdis;
	 mixed map,mapt;

        int tmp;
        string *dir1;
        string *dir2;

	string str="";
output="未知区域";

dir2=explode(base_name(ob),"/");

if (dir2[1]=="baituo")  

output="白驼山";

else if (dir2[1]=="binghuodao")  

	output="冰火岛";

else if (dir2[1]=="city")  

	output="扬州";

else if (dir2[1]=="city2" || dir2[1]=="beijing"  || dir2[1]=="huanggon"  || dir2[1]=="huanggong" || dir2[1]=="beihai")  

	output="北京城";

else if (dir2[1]=="city4" || dir2[1]=="changan")   

	output="长安城";

else if (dir2[1]=="dali")  

	output="大理";

else if (dir2[1]=="emei")  

	output="娥眉山";

else if (dir2[1]=="foshan")  

	output="佛山";

else if (dir2[1]=="gaibang")  

	output="丐帮";

else if (dir2[1]=="gaochang")  

	output="高昌迷宫";

else if (dir2[1]=="guanwai")  

	output="关外";

else if (dir2[1]=="guiyun")  

	output="归云庄";

else if (dir2[1]=="gumu")  

	output="古墓派";

else if (dir2[1]=="hangzhou")  

	output="杭州";

else if (dir2[1]=="heimuya")  

	output="黑木崖";

else if (dir2[1]=="hengshan")  

	output="恒山";

else if (dir2[1]=="henshan")  

	output="衡山";

else if (dir2[1]=="huanghe")  

	output="黄河九曲";

else if (dir2[1]=="huashan")  

	output="华山";

else if (dir2[1]=="jinshe")  

	output="金蛇山洞";

else if (dir2[1]=="lingjiu")  

	output="灵鹫宫";

else if (dir2[1]=="lingzhou")  

	output="灵州";

else if (dir2[1]=="meizhuang")  

	output="梅庄";

else if (dir2[1]=="mingjiao")  

	output="明教";

else if (dir2[1]=="qingcheng")  

	output="青城山";

else if (dir2[1]=="quanzhen")  

	output="全真派";

else if (dir2[1]=="quanzhou")  

	output="泉州";

else if (dir2[1]=="shaolin")  

	output="少林寺";

else if (dir2[1]=="shenlong")  

	output="神龙岛";

else if (dir2[1]=="songshan")  

	output="嵩山";

else if (dir2[1]=="suzhou")  

	output="苏州";

else if (dir2[1]=="taishan")  

	output="泰山";

else if (dir2[1]=="taohua")  

	output="桃花岛";

else if (dir2[1]=="tianlongsi")  

	output="天龙寺";

else if (dir2[1]=="wanjiegu")  

	output="万劫谷";

else if (dir2[1]=="wudang")  

	output="武当山";

else if (dir2[1]=="xiakedao")  

	output="侠客岛";

else if (dir2[1]=="xiangyang")  

	output="襄阳城";

else if (dir2[1]=="xiaoyao")  

	output="逍遥林";

else if (dir2[1]=="xingxiu")  

	output="星宿海";

else if (dir2[1]=="xueshan")  

	output="雪山寺";

else if (dir2[1]=="xuedao")  

	output="大雪山";

else if (dir2[1]=="mr")  

	output="慕容世家";

else if (dir2[1]=="kunlun")  

	output="昆仑山";

else if (dir2[1]=="tiezhang")  

	output="铁掌门";

else if (dir2[1]=="huizhu")  

	output="回族部落";

else if (dir2[1]=="yinju")  

	output="一灯大师居";

else if (dir2[1]=="menggu")  

	output="蒙古草原";

else if (dir2[1]=="qianjin")  

	output="北京千金楼";

else if (dir2[1]=="lingshedao")  

	output="灵蛇岛";

else if (dir2[1]=="ruzhou")  

	output="汝州城";

else if (dir2[1]=="kunming")  

	output="昆明";

else if (dir2[1]=="jingzhou")  

	output="荆州";

else if (dir2[1]=="yanjing")  

	output="燕京";

else if (dir2[1]=="lanzhou" || dir2[1]=="lanzhouchen")  

	output="兰州";

else if (dir2[1]=="jyguan")  

	output="北嘉峪关";

else if (dir2[1]=="changcheng")  

	output="北长城";

else if (dir2[1]=="fairyland")  

	output="红梅山庄";

else if (dir2[1]=="sdxl")  

	output="剑魔独孤求败墓";

else if (dir2[1]=="jqg")  

	output="绝情谷";

else if (dir2[1]=="nio")  

	output="牛家村";

else if (dir2[1]=="feihu")  

	output="闯王宝藏";

else if (dir2[1]=="wuguan")  

	output="襄阳武馆";

else if (dir2[1]=="village")  

	output="华山村";

else if (dir2[1]=="taohuacun")  

	output="桃花村";

else if (dir2[1]=="pingan")  

	output="平安城";

else if (dir2[1]=="lingxiao")  

	output="凌霄城";

else if (dir2[1]=="wudujiao")  

	output="五毒教";

else if (dir2[1]=="hj")  

	output="天山附近草原";
else if (dir2[1]=="dali/yuxu")  

	output="大理玉虚观";
else if (dir2[1]=="dali/wuliang")  

	output="大理无量山";
else if (dir2[1]=="huanghe/yyd")  

	output="黄河萧府";
else if (dir2[1]=="kaifeng")  

	output="开封城";
else if (dir2[1]=="feitian")  

	output="飞天御剑流";
else if (dir2[1]=="japan")  

	output="日本神户";
else if (dir2[1]=="tangmen")  

	output="唐门";
else if (dir2[1]=="luoyang")  

	output="洛阳城";

else if (dir2[1]=="chengdu" || dir2[1]=="city3")  

	output="成都";

else if (dir2[1]=="baihuagu")  

	output="百花谷";

else if (dir2[1]=="heizhao")  

	output="黑沼";

else if (dir2[1]=="jiaxing")  

	output="嘉兴";

else if (dir2[1]=="shiliang")  

	output="温家庄";

else if (dir2[1]=="wuyi")  

	output="武夷山区";

else if (dir2[1]=="yanping")  

	output="延平城";
	

if (dir2[1]=="jiangling")  
{
	output="江陵城";
}

if (dir2[1]=="yueyang")  
{
	output="岳阳城";	
}

if (dir2[1]=="qilian")  
{
	output="祁连山";	
}

if (dir2[1]=="shouxihu")  
{
	output="瘦西湖";	
}

if (dir2[1]=="wuxi")  
{
	output="无锡城";	
}

if (dir2[1]=="yixing")  
{
	output="宜兴城";	
}
if (dir2[1]=="taiwan")  
{
	output="台湾地区";	
}
if (dir2[1]=="nanyang")  
{
	output="南阳地区";	
}
if (dir2[1]=="nanshaolin")  
{
	output="南少林地区";	
}

if (dir2[1]=="cangzhou")  
{
	output="沧州地区";	
}

if (dir2[1]=="tanggu")  
{
	output="塘沽城地区";	
}

if (dir2[1]=="yunhe")  
{
	output="京杭大运河";	
}

if (dir2[1]=="hainan")  
{
	output="海南岛";	
}

if (dir2[1]=="jindezheng")  
{
	output="景德镇";	
}

if (dir2[1]=="yandang")  
{
	output="雁荡山";	
}

if (dir2[1]=="jinling")  
{
	output="金陵城";	
}

if (dir2[1]=="sandboy")  
{
	output="江南农村";	
}

if (dir2[1]=="huangshan")  
{
	output="黄山";	
}

if (dir2[1]=="yubifeng")  
{
	output="玉笔峰";	
}

if (dir2[1]=="quanzhouchen")  
{
	output="泉州城内";	
}

if (dir2[1]=="qingzh")  
{
	output="青藏高原";	
}

if (dir2[1]=="changbaishan" || dir2[1]=="gaoli")  
{
	output="高丽 长白山";	
}

if (dir2[1]=="annan")  
{
	output="安南";	
}

if (dir2[1]=="taiyuan")  
{
	output="太原";	
}

if (dir2[1]=="hefei")  
{
	output="合肥";	
}

if (dir2[1]=="jiujiang")  
{
	output="九江";	
}

if (dir2[1]=="baling")  
{
	output="巴陵";	
}

if (dir2[1]=="xinjiang")  
{
	output="新疆";	
}
if (dir2[1]=="dingxiang")  
{
	output="定襄";	
}
if (dir2[1]=="suiye")  
{
	output="碎叶";	
}


if (dir2[1]=="mayi")  
{
	output="马邑边疆";	
}
if (dir2[1]=="xuzhou")  
{
	output="徐州城";	
}
if (dir2[1]=="jinan")  
{
	output="济南城";	
}
if (dir2[1]=="guizhou")  
{
	output="贵阳城";	
}

if (dir2[1]=="nanchang")  
{
	output="南昌城";	
}


if (dir2[1]=="changsha")  
{
	output="长沙城";	
}


if (dir2[1]=="zhongzhou")  
{
	output="中州城";	
}

if (dir2[1]=="xizang" || dir2[1]=="zangbei")  
{
	output="西藏或藏北";	
}

if (dir2[1]=="cloud" )  
{
	output="东北绮云镇";	
}

if (dir2[1]=="xueting" )  
{
	output="东北雪亭镇";	
}

if (dir2[1]=="ny" )  
{
	output="东北宁远城";	
}

if (dir2[1]=="fengtian" )  
{
	output="东北盛京城";	
}

if (dir2[1]=="yanmen" )  
{
	output="雁门关";	
}

if (dir2[1]=="linzhi" )  
{
	output="西藏林芝地区";	
}

if (dir2[1]=="datong" )  
{
	output="大同府";	
}

if (dir2[1]=="tianshui" )  
{
	output="天水镇";	
}

if (dir2[1]=="heifeng" )  
{
	output="黑风寨";	
}

if (dir2[1]=="paiyun" )  
{
	output="排云寨";	
}


if (dir2[1]=="yeyangzai" )  
{
	output="野羊寨";	
}


if (dir2[1]=="jinghai" )  
{
	output="靖海派";	
}

if (dir2[1]=="zuojiacun" )  
{
	output="华亭镇";	
}


if (dir2[1]=="houjizhen" )  
{
	output="侯集镇";	
}

if (dir2[1]=="huayin" )  
{
	output="铜山村";	
}

if (dir2[1]=="lumaji" )  
{
	output="鹿马集";	
}


if (dir2[1]=="xiyu/gaochang" || dir2[1]=="xiyu/hami" || dir2[1]=="xiyu")  
{
	output="西域边疆";	
}

if (dir2[1]=="xibei/desert" || dir2[1]=="xibei/kongdong" || dir2[1]=="xibei/liangzhou" || dir2[1]=="xibei/xingqing" || dir2[1]=="xibei")  
{
	output="西北边疆";	
}

if (dir2[1]=="zhongyuan/chuzhou" || dir2[1]=="zhongyuan" )  
{
	output="中原关中";	
}

if (dir2[1]=="xinan/after_qingcheng" || dir2[1]=="xinan/cunzi" || dir2[1]=="xinan")  
{
	output="西南四川";	
}

if (dir2[1]=="loulan" )  
{
	output="楼兰";	
}

if (dir2[1]=="biancheng" )  
{
	output="边城";	
}

if (dir2[1]=="quicksand" )  
{
	output="大沙漠";	
}

if (dir2[1]=="tieflag/qianfo" || dir2[1]=="tieflag" || dir2[1]=="tieflag/palace" || dir2[1]=="tieflag/bat" || dir2[1]=="tieflag/chuenyu")  
{
	output="东海区域";	
}

if (dir2[1]=="taiping" )  
{
	output="太平镇";	
}

if (dir2[1]=="eren/eren2" || dir2[1]=="eren" )  
{
	output="恶人谷";	
}
return output;
}


int main2(object me)
{
    object where;
    int i,j,k,l,n,p;
    int lineu,lined,linef;
    string *text;
    string tmp;



        X=MinX;
        Y=MinY;


    tmp="☆即时地图v2.0 (by zjpwxh) 2004/4/24 ☆地图大小："+X+"/"+Y+"\n\n";
    m=allocate(2*X+1);
    data=allocate((2*X+1)*(2*Y+1));
    rfile=({});
    for(i=0;i<2*X+1;i++)
    {
        m[i]=allocate(2*Y+1);
        for(j=0;j<2*Y+1;j++)
              m[i][j]=" ";
    }

    where=environment(me);
    if(!objectp(where))
        return notify_fail("对不起，不知道你到底在哪里呀！找巫师吧！\n");

    draw_room((2*X+1)/2,(2*Y+1)/2,where);

    for(l=0,linef=1;l<2*Y+1;l++)
    {
        for(n=0;n<2*X+1;n++)
        {
              if( m[n][l]!=" ")
                  p++;
        }
        if(!p && linef)
        {
              lineu++;
              linef=1;
        }
        else     linef=0;
        p=0;
    }
    for(l=2*Y,linef=1;l>=0;l--)
    {
        for(n=0;n<2*X+1;n++)
        {
              if( m[n][l]!=" ")
                  p++;
        }
        if(!p && linef)
        {
              lined++;
              linef=1;
        }
        else     linef=0;
        p=0;
    }

    for(i=lineu;i<2*Y+1-lined;i++)
    {
        for(j=0;j<2*X+1;j++)
        {
              if( m[j][i]==" " && i%2 && j%2 )
                  tmp+="     ";
              else
              {
                  //如果此项为空，并且此时j为偶数列，则输出空格
                  if( m[j][i]==" " && !(j%2) )
                      tmp+=" ";
                  else
                  {
                      if( m[j][i]==" " )
                            tmp+="     ";

                      else
                            tmp+=m[j][i];
                  }
              }
        }
        tmp+="\n";
    }
    text=explode(tmp, "\n");
    for(i=k; k<sizeof(text); k++)
        write(text[k] + "\n");

    return 1;
}

object find_room(string path)
{
    object ob;
    if( objectp(ob=find_object(path)) || objectp(ob=load_object(path)) )
        return ob;
    return 0;
}

//←↑→↓↖↗↘↙
int draw_path(int x,int y,string direc)
{
    string str;
    int xx=0,yy=0;
    switch(direc)
    {
        case "south":
        case "north":         str="   │   ";break;
        case "southdown":
        case "northup":         str="   ↑   ";break;
        case "southup":
        case "northdown":     str="   ↓   ";break;
        case "east":
        case "west":         str="─";break;
        case "eastup":
        case "westdown":     str="→";break;
        case "westup":
        case "eastdown":     str="←";break;
        case "southeast":
        case "northwest":     str="↘";break;
        case "southwest":
        case "northeast":     str="↗";break;
        default:
              return 0;
    }
    if(sscanf(direc,"%*ssouth%*s"))
        yy++;
    if(sscanf(direc,"%*snorth%*s"))
        yy--;
    if(sscanf(direc,"%*seast%*s"))
        xx++;
    if(sscanf(direc,"%*swest%*s"))
        xx--;
    if( x+xx<=0 || y+yy<=0 || x+xx>=2*X || y+yy>=2*Y )
        return 0;
    m[x+xx][y+yy]=HIW+str+NOR;
    return 1;
}

// 改用广度遍历寻路算法,使地图的显示更加合理
int draw_room(int x,int y,object room)
{
    int i,xx,yy;
    int front,rear;
    string *dirs;
    object froom,nroom;
    mapping dir,x_y;
    object *queue;
    front=0;rear=0;

    queue=allocate( (2*X+1)*(2*Y+1) );
    reset_eval_cost();
    if( x<0 || y<0 || !objectp(room) || x>2*X || y>2*Y )
        return 0;

    rfile=rfile + ({ base_name(room) });
    queue[rear]=room;
    set_room(x,y,room);
    set_x_y(x,y,rear);
    rear++;

    while( front < rear )
    {
        reset_eval_cost();
        froom=queue[front];
        x_y=data[front];
        front++;
        dir=froom->query("exits");
        if( !mapp(dir) || sizeof(dir)<1 )
              return 0;
        dirs=keys(dir);
              for(i=0;i<sizeof(dirs);i++)
        {
                    nroom=find_room(dir[dirs[i]]);
                    if(!objectp(nroom) || member_array(base_name(nroom),rfile)!=-1)
                        continue;
                    xx=0;yy=0;
              if( sscanf(dirs[i],"%*ssouth%*s"))
                  yy+=2;
              if( sscanf(dirs[i],"%*snorth%*s"))
                  yy-=2;
              if( sscanf(dirs[i],"%*seast%*s"))
                  xx+=2;
              if( sscanf(dirs[i],"%*swest%*s"))
                  xx-=2;
              if( x_y["xst"]+xx<0 || x_y["yst"]+yy<0 || x_y["xst"]+xx>2*X || x_y["yst"]+yy>2*Y )
                  continue;
              if( m[x_y["xst"]+xx][x_y["yst"]+yy]!=" ")
                  continue;
              if( !draw_path(x_y["xst"],x_y["yst"],dirs[i]) || (xx==0&&yy==0))
                  continue;
              rfile=rfile + ({ base_name(nroom) });
              queue[rear]=nroom;
              set_room(x_y["xst"]+xx,x_y["yst"]+yy,nroom);
              set_x_y(x_y["xst"]+xx,x_y["yst"]+yy,rear);
              rear++;
        }
    }
}

void set_room(int x,int y,object room)
{
    int i,d,xx,yy,flag;
    string name;
    mapping dir;
    string *dirs;

    // 求取无颜色的房间short描述
    name=clean_color(room->query("short"));

    // 房间的短名字最好在4个汉字以内
    if(strlen(name)>8) name=name[0..7];

    if(strlen(name)<7) //对不足4个汉字的房间名进行居中处理
    {
        d=8-strlen(name);
        if( d%2 )
        {
              name+=" ";
              d--;
        }
        for(i=0;i<d/2;i++)
              name=" "+name+" ";
    }

    dir=room->query("exits");
    if( !mapp(dir) || sizeof(dir)<1 )
        flag=1;
    dirs=keys(dir);
    for(i=0;i<sizeof(dirs);i++)
    {
        xx=0;yy=0;
        if( sscanf(dirs[i],"%*ssouth%*s"))
              yy+=2;
        if( sscanf(dirs[i],"%*snorth%*s"))
              yy-=2;
        if( sscanf(dirs[i],"%*seast%*s"))
              xx+=2;
        if( sscanf(dirs[i],"%*swest%*s"))
              xx-=2;
        if( xx==0 && yy==0 )
              flag=1;
    }

    if( flag ) name=HIY+name;
    if((x==(2*X+1)/2)&&(y==(2*Y+1)/2))
        name=BLINK+HIC+name;
    name+=NOR;
    m[x][y]=name;
}

void set_x_y(int x,int y,int rear)
{
    data[rear]=([
        "xst":x,
        "yst":y,
    ]);
}


int help(object me)
{
	write(@HELP
指令格式：map <参量>

    这个指令用来显示指定的地图。地图册，请用help maps查询。
    不带参数或带的参数是here，则显示你所在地的地图。亮红色表示你所
处之地。

HELP
	);
	return 1;
}

