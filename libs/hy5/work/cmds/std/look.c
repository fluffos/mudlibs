// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)
// 星星6/16 以前辈发现号(find)在inventory.c中的记数方法改成现在
// 这个look.c中极重要的一部份，特此感谢find，得罪得罪。

#include <room.h>
#include <ansi.h>
#include <combat.h>
//#define TIME_TICK1 (time()*60-900000000)
#define TIME_TICK1 (time()*60)
//#define TIME_TICK1 ((time()-900000000)*24)
//#define TIME_TICK1 (time()*60-890000000)

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
BLU"不堪一击"NOR,BLU"毫不足虑"NOR,BLU"不知所以"NOR,BLU"新学乍练"NOR,BLU"勉勉强强"NOR,
BLU"初窥门径"NOR,BLU"初出茅庐"NOR,BLU"略知一二"NOR,BLU"普普通通"NOR,BLU"平平淡淡"NOR,

HIB"平淡无奇"NOR,HIB"粗通皮毛"NOR,HIB"半生不熟"NOR,HIB"马马虎虎"NOR,HIB"略有小成"NOR,
HIB"已有小成"NOR,HIB"渐入佳境"NOR,HIB"登堂入室"NOR,HIB"挥洒自如"NOR,HIB"融会贯通"NOR, 

CYN"心领神会"NOR,CYN"炉火纯青"NOR,CYN"了然於胸"NOR,CYN"略有大成"NOR,CYN"已有大成"NOR,
CYN"豁然贯通"NOR,CYN"出类拔萃"NOR,CYN"无可匹敌"NOR,CYN"技冠群雄"NOR,CYN"神乎其技"NOR,

HIC"出神入化"NOR,HIC"非同凡响"NOR,HIC"傲视群雄"NOR,HIC"登峰造极"NOR,HIC"无与伦比"NOR,
HIC"所向披靡"NOR,HIC"一代宗师"NOR,HIC"精深奥妙"NOR,HIC"神功盖世"NOR,HIC"举世无双"NOR,

HIR"惊世骇俗"NOR,HIR"撼天动地"NOR,HIR"震古铄今"NOR,HIR"超凡入圣"NOR,HIR"威镇寰宇"NOR,
HIR"空前绝后"NOR,HIR"天人合一"NOR,HIR"深藏不露"NOR,HIR"横扫江湖"NOR,HIR"深不可测"NOR,

HIY"威不可挡"NOR,HIY"技惊四座"NOR,HIR"强绝天下"NOR,HIY"威镇武林"NOR,HIR"前无古人"NOR,
HIY"返璞归真"NOR,HIY"独步天下"NOR,HIY"旷古绝伦"NOR,HIY"天下无敌"NOR,HIY"天下第一"NOR,
});
string *heavy_level_desc= ({
	"极轻",
	"很轻",
	"不重",
	"不轻",
	"很重",
	"极重"	
});

string w_power(int i)
{
	if( i >= 16 )	return HIY"灭世"NOR;
  if( i >= 15 )	return HIR"毁天"NOR;
	if( i >= 14 )	return HIR"创世"NOR;
	if( i >= 13 )	return HIR"开元"NOR;	
	if( i >= 12 )	return HIR"无双"NOR;	
	if( i >= 11 )	return HIM"绝世"NOR;	
	if( i >= 10 )	return HIY"天圣"NOR;
	if( i >= 9 )	return HIG"魔王"NOR;
	if( i >= 8 )	return HIB"举世"NOR;
	if( i >= 7 )	return HIC"完美"NOR;
	if( i >= 6 )	return RED"精致"NOR;
	if( i >= 5 )	return MAG"标准"NOR;
	if( i >= 4 )	return YEL"很高"NOR;
	if( i >= 3 )	return GRN"粗糙"NOR;
	if( i >= 2 )	return BLU"细碎"NOR;
	if( i >=	1  )	return CYN"不错"NOR;
	if( i <= 0 )	return "    ";
	return "    ";
}

string w_power2(int i)
{
	if( i >= 200 )	return HIY"灭世"NOR;
  if( i >= 180 )	return HIR"毁天"NOR;
	if( i >= 160 )	return HIR"创世"NOR;
	if( i >= 130 )	return HIR"开元"NOR;	
	if( i >= 120 )	return HIR"无双"NOR;	
	if( i >= 110 )	return HIM"绝世"NOR;	
	if( i >= 100 )	return HIY"天圣"NOR;
	if( i >= 90 )	return HIG"魔王"NOR;
	if( i >= 80 )	return HIB"举世"NOR;
	if( i >= 70 )	return HIC"完美"NOR;
	if( i >= 60 )	return RED"精致"NOR;
	if( i >= 50 )	return MAG"标准"NOR;
	if( i >= 40 )	return YEL"很高"NOR;
	if( i >= 30 )	return GRN"粗糙"NOR;
	if( i >= 20 )	return BLU"细碎"NOR;
	if( i >	10  )	return CYN"不错"NOR;
	if( i >	5  )	return YEL"一般"NOR;
	if( i >=	1  )	return GRN"极差"NOR;
	if( i <= 0 )	return "    ";
	return "    ";
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
             {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
             } else result = look_room_item(me, arg);

        return result;
}

void realtime_map(object me,object env)
{
        object room_obj;
        mapping exits;
    int i;
        string map_room, map_room2,jiantou;
     string *dirs,dirn;
        mapping alldirs=([      
                        "northwest" : "          ",
                        "north"     : "          ",
                        "northup"   : "          ",
                        "northeast" : "          ",
                        "west"      : "          ",
                        "east"      : "          ",
                        "southeast" : "          ",
                        "south"     : "          ",
                        "southwest" : "          ",
                        "southdown" : "          ",
                        "eastup" : "          ",
                        "southup" : "          ",
                        "northdown" : "          ",
                        "eastdown" : "          ",
                        "westup" : "          ",
                        "westdown" : "          ",
                        "enter" : "          ",
                        "out" : "          ",
                        "up" : "          ",
                        "down" : "          ",
                        "left" : "          ",
                        "right" : "          ",
                        ]);  
       if( mapp(exits = env->query("exits")) ) 
        {                       
                dirs=keys(exits);
                for(i=0;i< sizeof(dirs);i++)
                {
                        if(!room_obj=find_object(exits[dirs[i]]))
                                room_obj=load_object(exits[dirs[i]]);
                        if(room_obj){
                                dirn=dirs[i];
                                if (dirs[i]=="northeast") dirn="ne";
                                if (dirs[i]=="northwest") dirn="nw";
                                if (dirs[i]=="north") dirn="n";
                                if (dirs[i]=="northdown") dirn="nd";
                                if (dirs[i]=="northup") dirn="nu";
                                if (dirs[i]=="southeast") dirn="se";
                                if (dirs[i]=="southwest") dirn="sw";
                                if (dirs[i]=="south") dirn="s";
                                if (dirs[i]=="southdown") dirn="sd";
                                if (dirs[i]=="southup") dirn="su";
                                if (dirs[i]=="west") dirn="w";
                                if (dirs[i]=="westdown") dirn="wd";
                                if (dirs[i]=="westup") dirn="wu";
                                if (dirs[i]=="east") dirn="e";
                                if (dirs[i]=="eastdown") dirn="ed";
                                if (dirs[i]=="eastup") dirn="eu";
                                if (dirs[i]=="up") dirn="u";
                                if (dirs[i]=="down") dirn="d";
                                if (room_obj->query("short"))
                                alldirs[dirs[i]]=room_obj->query("short")+"("+dirn+")";                              ;
                                }
        
                }
        
                jiantou="  ";
                map_room2=alldirs["enter"];
                if(alldirs["enter"]!="          "){
                        map_room2=alldirs["enter"];
                        jiantou=HIR+"∧"+NOR;
                        }
                if(alldirs["up"]!="          "){
                        map_room2=alldirs["up"];
                        jiantou=HIC+"〓"+NOR;
                        }
                if(alldirs["northdown"]!="          "){
                        map_room2=alldirs["northdown"];
                        jiantou="↓";
                        }
                if(alldirs["northup"]!="          "){
                        map_room2=alldirs["northup"];
                        jiantou="↑";
                        }
                if(alldirs["north"]!="          "){
                        map_room2=alldirs["north"];
                        jiantou="｜";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room+" ";
                                map_room =" "+map_room;
                        }
                printf("             %10s  %-10s  %-10s\n",
                alldirs["northwest"],map_room,alldirs["northeast"]);
                
                printf("                        %s   %s   %s\n",
                alldirs["northwest"]=="          " ? "  ":"＼",
                jiantou,
                alldirs["northeast"]=="          " ? "  ":"／");
                
                jiantou="  ";
                map_room2=alldirs["westdown"];
                if(map_room2!="          ")
                                jiantou="→";
                if(alldirs["left"]!="          "){
                        map_room2=alldirs["left"];
                        jiantou="〈";
                        }
                if(alldirs["westup"]!="          "){
                        map_room2=alldirs["westup"];
                        jiantou="←";
                        }
                if(alldirs["west"]!="          "){
                        map_room2=alldirs["west"];
                        jiantou="--";
                        }
                printf("             %10s%s",map_room2,jiantou);        
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("%s",map_room);
                
                jiantou="  ";
                map_room2=alldirs["eastup"];
                if(map_room2!="          ")
                                jiantou="→";
                if(alldirs["right"]!="          "){
                        map_room2=alldirs["right"];
                        jiantou="〉";
                        }
                if(alldirs["eastdown"]!="          "){
                        map_room2=alldirs["eastdown"];
                        jiantou="←";
                        }
                if(alldirs["east"]!="          "){
                        map_room2=alldirs["east"];
                        jiantou="--";
                        }
                
                printf("%s%-10s\n",jiantou,map_room2);
                
                jiantou="  ";
                map_room2=alldirs["out"];
                if(alldirs["out"]!="          "){
                        map_room2=alldirs["out"];
                        jiantou=HIR+"∨"+NOR;
                        }
                if(alldirs["down"]!="          "){
                        map_room2=alldirs["down"];
                        jiantou=HIC+"〓"+NOR;
                        }
                
                if(alldirs["southdown"]!="          "){
                                map_room2=alldirs["southdown"];
                                jiantou="↑";
                                }
                if(alldirs["southup"]!="          "){
                        map_room2=alldirs["southup"];
                        jiantou="↓";
                        }
                if(alldirs["south"]!="          "){
                        map_room2=alldirs["south"];
                        jiantou="｜";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room + " ";
                                map_room =" "+map_room;
                        }
                printf("                        %s   %s   %s\n",
                alldirs["southwest"]=="          " ? "  ":"／",
                jiantou,
                alldirs["southeast"]=="          " ? "  ":"＼");
                printf("             %10s  %-10s  %-10s\n",
                alldirs["southwest"],map_room,alldirs["southeast"]);
                
                        
        }       
        else
        {
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("\n                            %s\n",map_room);
                
        }
        return;
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
// 天气到此结束
/*    if (!objectp(present("fire", me))  && environment(me)->query("outdoors") 
    && !wizardp(this_player()) 
    &&   ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0))
     )
    str = sprintf( "%s"+NOR+BLU+"\n　　  夜晚了，你虽然睁大了眼睛仔细观看，可还是看不清楚周围的事物。\n"+
			"一切都被夜色所笼罩，连脚下的道路都模糊不清了...\n"+NOR+"",
        env->query("short"));
*/
        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
/*                if ( env->query("outdoors") &&
                    !present("fire", this_player()) &&
                    !wizardp(this_player()) &&
                    ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0)))
                        str += BLU + "    天色太黑了，你看不清明显的出路。\n"NOR;
                else  */
				//	dirs -= ({ 0 });
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
/*               if ( env->query("outdoors") &&
                    !present("fire", this_player()) 
                     && !wizardp(this_player())                     
                    && ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0)))
				str = sprintf("%s", str);
else*/				str = sprintf("%s%s%s\n", str,  (data[l]["num"]==1)? "  ":"  "+ chinese_number(data[l]["num"])+data[l]["unit"], data[l]["id"]);
		}
if (me->query_temp("xmud"))write ("地图:\n");
if (me->query("env/showmap")) realtime_map(me,env);              
if (me->query_temp("xmud"))
{
str1="$botten#";
str2="";
if (!environment(me)->query("roomif"))
{
	cmds = me->query_commands();
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		if(present(cmds[i][2], me)) continue;
  if (str1=="$botten#")
	str1 +=cmds[i][0];
	else str1 +="|"+cmds[i][0];
	}
  if (str1!="$botten#")
  str1 +=":";
	
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		if(present(cmds[i][2], me)) continue;
  if (str2=="")
	str2 +=cmds[i][0];
	else str2 +="|"+cmds[i][0];
	}
	
str1 +=str2;
str1 +="\n$#\n";
if (str2=="") str1="$botten#$#\n";
	write(str1);
}
}              
        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;
int sharpness,lev;
        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("里面有：\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
if (obj->query("makeritem")==1 || obj->query("systemmake")==1 )
{
sharpness=obj->query("sharpness",1);
if (sharpness>=1) lev=1;
if (sharpness>=3) lev=2;
if (sharpness>=9) lev=3;
if (sharpness>=12) lev=4;
if (sharpness>=15) lev=5;
if (sharpness>=18) lev=6;
if (sharpness>=22) lev=7;
if (sharpness>=24) lev=8;

message("vision", sprintf("这是一件品质为"+chinese_number(lev)+"级的特殊物品 属性如下:\n"), me);


if (!obj->query("armor_type"))
{
	                message("vision", sprintf("天灵:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/intelligence"))), me);
	                message("vision", sprintf(" 天宇:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/strength"))), me);
message("vision", sprintf(" 福源:") ,me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/karey"))), me);
message("vision", sprintf(" 绝代:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/percao"))), me);
message("vision", sprintf(" 天渊:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/dexerity"))), me);
message("vision", sprintf(" 天玄:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/constitution"))), me);
message("vision", sprintf(" 白石:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/dodge"))), me);
message("vision", sprintf(" 紫石:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/parry"))), me);
message("vision", sprintf("\n闪电:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/attack"))), me);
message("vision", sprintf(" 巧制:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/armor"))), me);
message("vision", sprintf(" 体灵:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/defense"))), me);
message("vision", sprintf(" 周天:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/neili"))), me);
message("vision", sprintf(" 长生:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/qi"))), me);
message("vision", sprintf(" 不老:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/jing"))), me);
message("vision", sprintf(" 不灭:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/jingli"))), me);
message("vision", sprintf(" 威力:"), me);
message("vision", sprintf(w_power2(obj->query("weapon_prop/damage"))), me);
}
else
{
	                message("vision", sprintf("天灵:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/intelligence"))), me);
	                message("vision", sprintf(" 天宇:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/strength"))), me);
message("vision", sprintf(" 福源:") ,me);
message("vision", sprintf(w_power2(obj->query("armor_prop/karey"))), me);
message("vision", sprintf(" 绝代:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/percao"))), me);
message("vision", sprintf(" 天渊:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/dexerity"))), me);
message("vision", sprintf(" 天玄:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/constitution"))), me);
message("vision", sprintf(" 白石:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/dodge"))), me);
message("vision", sprintf(" 紫石:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/parry"))), me);
message("vision", sprintf("\n闪电:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/attack"))), me);
message("vision", sprintf(" 巧制:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/armor"))), me);
message("vision", sprintf(" 体灵:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/defense"))), me);
message("vision", sprintf(" 周天:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/neili"))), me);
message("vision", sprintf(" 长生:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/qi"))), me);
message("vision", sprintf(" 不老:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/jing"))), me);
message("vision", sprintf(" 不灭:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/jingli"))), me);
message("vision", sprintf(" 威力:"), me);
message("vision", sprintf(w_power2(obj->query("armor_prop/damage"))), me);	
}		
	                message("vision", sprintf("\n这是一件打造的物品 符字如下:\n"), me);
	                message("vision", sprintf("金:"), me);
message("vision", sprintf(w_power(obj->query("wtypeA"))), me);
	                message("vision", sprintf(" 木:"), me);
message("vision", sprintf(w_power(obj->query("wtypeB"))), me);
message("vision", sprintf(" 水:") ,me);
message("vision", sprintf(w_power(obj->query("wtypeC"))), me);
message("vision", sprintf(" 火:"), me);
message("vision", sprintf(w_power(obj->query("wtypeD"))), me);
message("vision", sprintf(" 土:"), me);
message("vision", sprintf(w_power(obj->query("wtypeE"))), me);
message("vision", sprintf(" 风:"), me);
message("vision", sprintf(w_power(obj->query("wtypeF"))), me);
message("vision", sprintf("\n雷:"), me);
message("vision", sprintf(w_power(obj->query("wtypeG"))), me);
message("vision", sprintf(" 电:"), me);
message("vision", sprintf(w_power(obj->query("wtypeH"))), me);
message("vision", sprintf(" 天:"), me);
message("vision", sprintf(w_power(obj->query("wtypeI"))), me);
message("vision", sprintf(" 地:"), me);
message("vision", sprintf(w_power(obj->query("wtypeJ"))), me);
message("vision", sprintf(" 人:"), me);
message("vision", sprintf(w_power(obj->query("wtypeK"))), me);
message("vision", sprintf(" 魔:"), me);
message("vision", sprintf(w_power(obj->query("wtypeL"))), me);
message("vision", sprintf("\n"), me);



}	

        return 1;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	mapping prepare;
 	int attack_points;
    if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];   
	    }
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
    	return tough_level((int)(attack_points/100));
}
int look_living(object me, object obj)
{
        int per;
        int spi;
        int age;
        int weight;
        string str, limb_status, pro;
        mixed *inv;
        mapping my_fam, fam;
        int me_shen, obj_shen;
        int equip, wearornot;

        me_shen = (int)me->query("shen");
        obj_shen = (int)obj->query("shen");
        per = obj->query_per();
        age = obj->query("age");

        if( me!=obj )
                message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

        str = obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	    if (age>50) per = per*2/3;
		if (obj->query_temp("is_riding"))
                str += sprintf("%s正骑在%s上，低头看着你。\n", pro, obj->query_temp("is_riding"));

        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
        {       if(wizardp(obj))
			str+=sprintf(HIY"%s全身散发着耀眼的金光，看来是万物之尊的神类。\n"NOR,pro);
                str += sprintf("%s看起来约%s多岁，", pro, chinese_number(obj->query("age") / 10 * 10));
                  if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
        {
		   
                     if (per >=40) 
                        str +=pro+ HIG"英姿勃发，一表人才，称为古往今来第一人！\n";
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"清秀俊雅，相貌非凡，真是人中龙凤！\n";
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"生得英俊潇洒，风流倜傥。\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"生得相貌平平，不会给人留下什么印相。\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
                if (per <= 10)
                        str +=pro+ RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "女性")
            {
                if (per >=40) 
                        str +=pro+ HIW"现在宛如玉雕冰塑，似梦似幻，娇艳绝伦，貌如西子胜三分\n"NOR;
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"清丽绝俗，冰清玉洁，有如画中天仙！\n"NOR;
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"生得巧笑嫣然，宛约可人。\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"生得如梨花带露，清新秀丽。\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"生得风姿楚楚，明丽动人。\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
	         if (per <=10) 
                        str +=pro+ RED"生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += pro+"是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
                else
                   str += pro+"是一只被"+obj->query_temp("ownername")+"驯服的畜生，一副很温驯的样子。\n";
		}
            }
        }
				str += sprintf("%s的武功看来", pro);
		str +=gettof(me,obj);
		str +=sprintf("，");
		str +=sprintf("出手似乎");
		str +=getdam(me,obj);
		str +=sprintf("。\n");
        }
         
        wearornot = 0;
        inv = all_inventory(obj);
        for(equip=0; equip<sizeof(inv); equip++)
        {
                if( inv[equip]->query("equipped") ) wearornot = 1;
        }
        //check about wife and husband
        if((obj->parse_command_id_list())[0]==me->query("couple/couple_id") )
        {
              if( (string)me->query("gender")=="女性" )
              {
                    str += sprintf("%s是你的丈夫。\n", pro);
              }
              else{
                    str += sprintf("%s是你的妻子。\n", pro);
              }
        }
        if (me->query("jiebai") && stringp(me->query("jiebai")))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="女性" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的义姐。\n", pro);
                    else
                        str += sprintf("%s是你的结义妹子。\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的结义兄长。\n", pro);
                    else
                        str += sprintf("%s是你的义弟。\n", pro);
              }
        }
        if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
            str += pro+"身上居然什么都没穿耶！\n";
        if (!sizeof(inv) && me != obj && obj->query("race")=="人类")
                str += pro + "身上没有任何装备。\n";

        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {

                        if( (string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "无性")
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("%s连头都被割走了。\n", pro);

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n": "%s身上装备著：\n%s\n",
                                pro, implode(inv, "\n") );
        }
        if (!sizeof(inv) && me != obj && obj->query("race")=="人类")
                str += pro + "身上没有任何装备。\n";

        message("vision", str, me);

// Modified by Hop
/*
        if( obj!=me
        &&      living(obj)
        &&      random((int)obj->query("shen")) < 0 - (int)me->query("int") * 10 ) {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }
*/
        if( obj!=me && living(obj)
        && (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                if(obj->query("age") > 17 && me->query("age") > 17)
                   if(!wizardp(obj) && !wizardp(me) && !userp(obj))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  □" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string getdam(object me, object obj)
{

	int level;
	level = obj->query_temp("apply/damage") / 2 + obj->query("jiali");
        if (!level) level=30;
	level = level / 30;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}

int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。

HELP
);
        return 1;
}

