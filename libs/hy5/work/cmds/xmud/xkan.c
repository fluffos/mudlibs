// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)

#define C_MAP_S "/inherit/maps.c"
#include <room.h>
#include <ansi.h>
#include <combat.h>
#define TIME_TICK1 ((time()-900000000)*60)

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
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;
	string str;
        if( !arg ) result = look_room(me, environment(me));
	else if(arg=="long") {
 	result = look_room(me, environment(me));

		}
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
                printf(NOR"\n                            %s\n"NOR,map_room);
                
        }
        return;
}

int look_room(object me, object env)
{
	int i,n;
	object *inv,*ob,env1;
	mapping exits;
	string str,*dirs,*cdirs; 
	mixed *objs;

        int j, k, l;
        mapping *data;
    int amount;
    object obj,room;
        mixed *cmds;
    mapping my;
    string message,str2,modify;
         mapping item;
         string *sk,itemdesc,strrk;
        k = 0;
	data = allocate(3000);
	if( !env ) {
		write("你的四周灰蒙蒙地一片，什么也没有。\n");
		return 1;
	}

	str = sprintf( "$ct#%s\n",env->query("short"));
 if (me->query_temp("xmud"))	str += sprintf( "$fln#%s\n",file_name(env));
        str += sprintf( "$miao#    %s%s",
              replace_string( environment(me)->query("long"), "\n", "\n$miao#")+"\n",
		environment(me)->query("outdoors")?"$miao#"+ NATURE_D->outdoor_room_description() : "" );
        //str +="\n";


        
/*        if( mapp(item = env->query("item_desc"))  ) {
sk = keys(item);
for(i=0; i<sizeof(item); i++) {
                if( stringp(item[sk[i]]) )
                        itemdesc=item[sk[i]];
                //else if( functionp(item[sk[i]]) )
                 //       itemdesc=(string)(*item[sk[i]])(me);
        str += sprintf( "$miao#    %s:%s",
               sk[i],itemdesc);
        str +="\n";

	}
       }
  */      
        	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			{
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				{
				dirs[i] = 0;
				map_delete(exits, dirs[i]);
				}
			}
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    这里没有任何明显的出路。\n";
		else if( sizeof(dirs)==1 ){
				str += "$exit#" + dirs[0] + ":"+exits[dirs[0]]->query("short")+"\n";
			}
		else
			{
				str += sprintf("$exit#%s|%s:",
				implode(dirs[0..sizeof(dirs)-2], "|"), dirs[sizeof(dirs)-1]);
str += sprintf("%s|%s\n",
                implode(map_array(values(exits)[0..sizeof(exits)-2], (: $1 = $1->query("short") :)), "|"), values(exits)[sizeof(dirs)-1]->query("short"));	       	}
		}

	inv = all_inventory(env);
	i=sizeof(inv);
	while(i--) {
		if( !me->visible(inv[i])) continue;
		if( inv[i]==me ) continue;
		if(inv[i]->is_character())
		{
strrk="";
   if( inv[i]->is_ghost() ) strrk = HIB "<鬼气> " NOR + strrk;
 	 if (inv[i]->query_condition("killer")) strrk = HIR "<通缉犯> " NOR + strrk;
	 if( inv[i]->query_temp("sleepbag") ) strrk += HIR " <睡在睡袋中>" NOR;
   if(inv[i]->query("disable_type") && !living(inv[i]) )  strrk += HIR + inv[i]->query("disable_type") + NOR;
	 if( interactive(inv[i])	&&	query_idle( inv[i] ) > 120 ) strrk += HIM " <发呆中>" NOR;
   if (inv[i]->is_fighting())  strrk = HIR " <战斗中> " NOR + strrk;

		if (inv[i]->query("rider"))
			str +="$rw#"+inv[i]->name()+"("+inv[i]->query("id")+")" + "<"+inv[i]->query("rider") +strrk+">\n";
		else	
			str +="$rw#"+inv[i]->name()+"("+inv[i]->query("id")+")"+strrk+"\n";
		}
		else{
		if (inv[i]->query("rider"))
			str +="$cw#"+ inv[i]->name()+"("+inv[i]->query("id")+")" + "<"+inv[i]->query("rider") +strrk+">\n";
		else	
			str +="$cw#"+ inv[i]->name()+"("+inv[i]->query("id")+")"+strrk+"\n";
		}
		}
	//str+="$#\n";
        if( env->query("roomif")) 
        str +=env->query("roomif")+"\n";
       else str +="$botten#$#\n";
//if (!me->query("env/showmap"))	str +="$#\n";
	write(str);
//if (!me->query("env/showmap"))	
//write (".\n");


str="";
if (me->query("env/showmap"))
{
   reset_eval_cost();
    if (1==2 && !objectp(present("fire", me))  && environment(me)->query("outdoors") 
    && !wizardp(this_player()) 
    &&   ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
         (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0))
     ){
    str = sprintf( "%s"+NOR+BLU+"\n　　  夜晚了，你虽然睁大了眼睛仔细观看，可还是看不清楚周围的事物。\n"+
			"一切都被夜色所笼罩，连脚下的道路都模糊不清了...\n"+NOR+"",
        env->query("short"));

    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += HIR + "    这里没有任何明显的出路。\n"NOR;
    else if( sizeof(dirs)==1 )
                        str += YEL + "    这里唯一的出口是 " + BOLD + "("+dirs[0]+")" + NOR + "。\n";
        else{
            dirs = sort_array(dirs,"sort_exits");
                        str += sprintf(  HIG + "    这里明显的"+ HIC +"【出口】"+ HIG +"是" + BOLD + "("+"%s" + NOR + ")" + HIG + "和  " + BOLD +"("+"%s"+")" + NOR + "。\n",
                              implode(dirs[0..sizeof(dirs)-2], ")("), dirs[sizeof(dirs)-1]);
        }
      }else
            str += "　　这里没有任何明显的出路。\n";
        write(str);
        return 1;
    }
        if(env->query("outdoors",1))
                str2 = NOR+HIC"室外"NOR;
        if(!env->query("outdoors",1))
                str2 = NOR+HIC"室内"NOR;
    if (wizardp(me) && !me->query("env/show_room"))
    str = sprintf( HIC"〖"HIW"%s"HIC"〗　%s"+NOR+" - "+RED+"%s\n"+NOR+"    %s",
        env->query("short"),str2,
        SECURITY_D->valid_read(file_name(env),me)? file_name(env): "",
        env->query("long"));
    else 
    str = sprintf(  HIC"〖"HIW"%s"HIC"〗  %s"+NOR+"\n    %s",env->query("short"),str2,env->query("long"));
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
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });

    		if( sizeof(dirs)==0 )
                        str += HIR + "    这里没有任何明显的出路。\n"NOR;
		else if( sizeof(dirs)==1 )
                        str += YEL + "    这里明显的"+ HIC +"【出口】"+ HIG +"是" + BOLD + "("+dirs[0]+")"+ NOR + "。\n";
		else
                        str += sprintf(  HIG + "    这里明显的"+ HIC +"【出口】"+ HIG +"是" + BOLD + "("+"%s" +")"+ NOR + " " + HIG + "和  " + BOLD + "("+"%s" +")" NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], ")("), dirs[sizeof(dirs)-1]);
        }

/*    i=0;
    foreach (obj in all_inventory(env)){
    if (!wizardp(me) && obj->query("no_show")) continue;
        if (!obj->is_character() && (i++)>99) continue;
        if (obj==me || !me->visible(obj) ){
            continue;
        }
        if (obj->query("money_id") 
            || !obj->query("unit")
            || obj->is_character()){
                if(!wizardp(me)){str+=sprintf("    %-12s\n",obj->short());}
                if(wizardp(me)){str+=sprintf("　　%-28s" + YEL":"NOR + RED"%s" + ".c"NOR+ "\n",obj->short(),base_name(obj));}
            continue;
        }
        if (!mapp(my))
            my=([obj->query("unit")+obj->short():1]);
        else{
            amount=my[obj->query("unit")+obj->short()];
            my[obj->query("unit")+obj->short()]=amount+1;
        }
    }
    if (mapp(my)){
        dirs=keys(my);
        for (i=0;i<sizeof(my);i++)
                str+=sprintf("　　%s%s\n",
my[dirs[i]]==1?"":CHINESE_D->chinese_number(my[dirs[i]]),
my[dirs[i]]==1?dirs[i][2..]:dirs[i]);
    }
    write(str);
    return 1;
} */
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

//realtime_map(me,env);              
//write("\n");
             
//write (".\n");
//if (me->query_temp("xmud"))write ("环境:\n");
//if (me->query("env/showmap")) realtime_map(me,env); 
        write(str);

str="";     
}

	return 1;
}
int look_item(object me, object obj)
{
        mixed *inv;

        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("里面有：\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	int attack_points;
        if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
                parry_type = "parry";
        }
        else
        {
                skill_type = "unarmed";
                parry_type = "unarmed";
        }

        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
//        attack_points = ob->query_temp("apply/attack");
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



if (age>50) per = per*2/3;

/*        if(userp(obj) && me->query("combat_exp") < obj->query("combat_exp")/10 && me!= obj)
         {
        write("$renwu#"+"对方比你厉害太多，最好别乱看，小心被揍哦。$#\n");
        return 1;
         }
        if(userp(obj) && me->query("shen") >0 && obj->query("shen")<0 && me!= obj)
         {
        write("$renwu#"+"你俩一个是侠义派，一个是邪派，别乱看，打起来不好。$#\n");
        return 1;
         }
        if(userp(obj) && me->query("shen") <0 && obj->query("shen")>0 && me!= obj)
         {
        write("$renwu#"+"你俩一个是侠义派，一个是邪派，别乱看，打起来不好。$#\n");
        return 1;
         }
        if(userp(obj) && obj->query("shen")< -100000 && me!= obj)
         {
        write("$renwu#"+"对方是个大魔头，你还敢乱看？小心被杀哦。$#\n");
        return 1;
         }
*/
//        if( me!=obj )
//                message("vision", "$renwu#" + me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

        //str = obj->long();
        str = replace_string( obj->long(), "\n", "\n$renwu#")+"\n";
        //  str= obj->query("name");





        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	if (obj->query_temp("is_riding"))
                str += sprintf("$renwu#"+"%s正骑在%s上，低头看着你。\n", pro, obj->query_temp("is_riding"));

        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
        {
              if(wizardp(obj))
			str+=sprintf(HIY"%s全身散发着耀眼的金光，看来是万物之尊的神类。\n"NOR,pro);

                str += sprintf("$renwu#"+"%s看起来约%s多岁。\n", pro, chinese_number(obj->query("age") / 10 * 10));
                str += sprintf("$renwu#"+"%s的武功看来", pro);
		str +=gettof(me,obj);
		str +=sprintf("，");
		str +=sprintf("出手似乎");
		str +=getdam(me,obj);
		str +=sprintf("。\n");
        }
        if(age > 70 ) per = per/4;
        if(age > 60 ) per = per/3;
        if(age > 50 ) per = per/2;
        //str +=sprintf(obj->query_per());
        //per=30;

        //write(per+"对方比你厉害太多，最好别乱看，小心被揍哦。\n");
        //return 1;        
        if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
        {
		   
                     if (per >=40) 
                        str +="$renwu#"+pro+ HIG"英姿勃发，一表人才，称为古往今来第一人！\n";
                if (per <= 39 && (per > 38))
                        str +="$renwu#"+pro+ HIG"清秀俊雅，相貌非凡，真是人中龙凤！\n";
                if (per <= 38 && (per > 37))
                        str +="$renwu#"+pro+ HIG"现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
                if (per <= 37 && (per > 36))
                        str +="$renwu#"+pro+ HIG"现在飘逸出尘，潇洒绝伦。\n"NOR;
                if (per <= 36 && (per > 35))
                        str +="$renwu#"+pro+ HIG"现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
                if (per <= 35 && (per > 34))
                        str +="$renwu#"+pro+ HIG"现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
                if (per <= 34 && (per > 33))
                        str +="$renwu#"+pro+ HIY"现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
                if (per <= 33 && (per > 32))
                        str +="$renwu#"+pro+ HIY"现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
                if (per <= 32 && (per > 31))
                        str +="$renwu#"+pro+ HIY"现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
                if (per <= 31 && (per > 30))
                        str +="$renwu#"+pro+ HIY"现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
                if (per <= 30 && (per > 29))
                        str +="$renwu#"+pro+ HIY"生得英俊潇洒，风流倜傥。\n"NOR;
                if (per <= 29 && (per > 28))
                        str +="$renwu#"+pro+ MAG"生得目似点漆，高大挺俊，令人心动。\n"NOR;
                if (per <= 28 && (per > 27))
                        str +="$renwu#"+pro+ MAG"生得面若秋月，儒雅斯文，举止适度。\n"NOR;
                if (per <= 27 && (per > 26))
                        str +="$renwu#"+pro+ MAG"生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
                if (per <= 26 && (per > 25))
                        str +="$renwu#"+pro+ MAG"生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
                if (per <= 25 && (per > 24))
                        str +="$renwu#"+pro+ MAG"生得眉如双剑，眼如明星，英挺出众。\n"NOR;
                if (per <= 24 && (per > 23))
                        str +="$renwu#"+pro+ CYN"生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
                if (per <= 23 && (per > 22))
                        str +="$renwu#"+pro+ CYN"生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
                if (per <= 22 && (per > 21))
                        str +="$renwu#"+pro+ CYN"生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
                if (per <= 21 && (per > 20))
                        str +="$renwu#"+pro+ CYN"生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
                if (per <= 20 && (per > 19))
                        str +="$renwu#"+pro+ CYN"生得眉目清秀，端正大方，一表人才。\n"NOR;
                if (per <= 19 && (per > 18))
                        str +="$renwu#"+pro+ YEL"生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
                if (per <= 18 && (per > 17))
                        str +="$renwu#"+pro+ YEL"生得相貌平平，不会给人留下什么印相。\n"NOR;
                if (per <= 17 && (per > 16))
                        str +="$renwu#"+pro+ YEL"生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
                if (per <= 16 && (per > 15))
                        str +="$renwu#"+pro+ YEL"生得獐头鼠须，让人一看就不生好感。\n"NOR;
                if (per <= 15 && (per > 14))
                        str +="$renwu#"+pro+ YEL"生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
                if (per <= 14 && (per > 13))
                        str +="$renwu#"+pro+ RED"生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
                if (per <= 13 && (per > 12))
                        str +="$renwu#"+pro+ RED"生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
                if (per <= 12 && (per > 11))
                        str +="$renwu#"+pro+ RED"生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
                if (per <= 11 && (per > 10))
                        str +="$renwu#"+pro+ RED"生得呲牙咧嘴，黑如锅底，奇丑无比。\n"NOR;
                if (per <= 10)
                        str +="$renwu#"+pro+ RED"生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "女性")
            {
                if (per >= 42)
                {
                if(obj->query("describe"))
                {
             str += "$renwu#"+pro+"有倾国倾城之貌，容色丽都，娇艳绝伦，堪称人间仙子！\n"+(string)obj->query("describe")+"\n";
                }
            else
                        str += "$renwu#"+pro+"有倾国倾城之貌，容色丽都，娇艳绝伦，堪称人间仙子！\n长发如云，肌肤胜雪，风华绝代，不知倾倒了多少英雄豪杰。\n";
                }
                          if (per >=40) 
                        str +="$renwu#"+pro+ HIW"现在宛如玉雕冰塑，似梦似幻，娇艳绝伦，貌如西子胜三分\n"NOR;
                if (per <= 39 && (per > 38))
                        str +="$renwu#"+pro+ HIG"清丽绝俗，冰清玉洁，有如画中天仙！\n"NOR;
                if (per <= 38 && (per > 37))
                        str +="$renwu#"+pro+ HIG"现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
                if (per <= 37 && (per > 36))
                        str +="$renwu#"+pro+ HIG"现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
                if (per <= 36 && (per > 35))
                        str +="$renwu#"+pro+ HIG"现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
                if (per <= 35 && (per > 34))
                        str +="$renwu#"+pro+ HIG"现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
                if (per <= 34 && (per > 33))
                        str +="$renwu#"+pro+ HIY"现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
                if (per <= 33 && (per > 32))
                        str +="$renwu#"+pro+ HIY"现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
                if (per <= 32 && (per > 31))
                        str +="$renwu#"+pro+ HIY"现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
                if (per <= 31 && (per > 30))
                        str +="$renwu#"+pro+ HIY"现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
                if (per <= 30 && (per > 29))
                        str +="$renwu#"+pro+ HIY"生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
               if (per <= 29 && (per > 28))
                        str +="$renwu#"+pro+ MAG"生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
                if (per <= 28 && (per > 27))
                        str +="$renwu#"+pro+ MAG"生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
                if (per <= 27 && (per > 26))
                        str +="$renwu#"+pro+ MAG"生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
                if (per <= 26 && (per > 25))
                        str +="$renwu#"+pro+ MAG"生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
                if (per <= 25 && (per > 24))
                        str +="$renwu#"+pro+ MAG"生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
                if (per <= 24 && (per > 23))
                        str +="$renwu#"+pro+ CYN"生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
                if (per <= 23 && (per > 22))
                        str +="$renwu#"+pro+ CYN"生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
                if (per <= 22 && (per > 21))
                        str +="$renwu#"+pro+ CYN"生得巧笑嫣然，宛约可人。\n"NOR;
                if (per <= 21 && (per > 20))
                        str +="$renwu#"+pro+ CYN"生得如梨花带露，清新秀丽。\n"NOR;
                if (per <= 20 && (per > 19))
                        str +="$renwu#"+pro+ CYN"生得风姿楚楚，明丽动人。\n"NOR;
                if (per <= 19 && (per > 18))
                        str +="$renwu#"+pro+ YEL"生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
                if (per <= 18 && (per > 17))
                        str +="$renwu#"+pro+ YEL"生得虽不标致，倒也白净，有些动人之处。\n"NOR;
                if (per <= 17 && (per > 16))
                        str +="$renwu#"+pro+ YEL"生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
                if (per <= 16 && (per > 15))
                        str +="$renwu#"+pro+ YEL"生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
                if (per <= 15 && (per > 14))
                        str +="$renwu#"+pro+ YEL"生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
                if (per <= 14 && (per > 13))
                        str +="$renwu#"+pro+ RED"生得一嘴大暴牙，让人一看就没好感。\n"NOR;
                if (per <= 13 && (per > 12))
                        str +="$renwu#"+pro+ RED"生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
                if (per <= 12 && (per > 11))
                        str +="$renwu#"+pro+ RED"生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
                if (per <= 11 && (per > 10))
                        str +="$renwu#"+pro+ RED"生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
	         if (per <=10) 
                        str +="$renwu#"+pro+ RED"生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;

            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += "$renwu#"+pro+"是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
                else
                   str += "$renwu#"+pro+"是一只被"+obj->query_temp("ownername")+"驯服的畜生，一副很温驯的样子。\n";
		}
            }
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
                    str += sprintf("$renwu#"+"%s是你的丈夫。\n", pro);
              }
              else{
                    str += sprintf("$renwu#"+"%s是你的妻子。\n", pro);
              }
        }
                if (me->query("jiebai") && stringp(me->query("jiebai")))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="女性" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("$renwu#"+"%s是你的义姐。\n", pro);
                    else
                        str += sprintf("$renwu#"+"%s是你的结义妹子。\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("$renwu#"+"%s是你的结义兄长。\n", pro);
                    else
                        str += sprintf("$renwu#"+"%s是你的义弟。\n", pro);
              }
        }
        if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
            str += "$renwu#"+pro+"身上居然什么都没穿耶！\n";
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {

                        if( (string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "无性")
                                str += sprintf( "$renwu#"+pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( "$renwu#"+pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += "$renwu#"+pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += "$renwu#"+pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += "$renwu#"+pro + "是你的师伯。\n";
                        else
                                str += "$renwu#"+pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += "$renwu#"+pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += "$renwu#"+pro + "是你的弟子。\n";
                        else
                                str += "$renwu#"+pro + "是你的师侄。\n";
                }
        }

        if( obj->query("max_qi") )
                str += "$renwu#"+pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("$renwu#"+"%s连头都被割走了。\n", pro);

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "$renwu#"+"%s的遗物有：\n"+"$renwu#"+"%s"+"$renwu#"+"\n": "$renwu#"+"%s身上带著：\n""$renwu#"+"%s\n",
                                pro, implode(inv, "$renwu#"+"\n") );
        }
str+="$#\n";
        message("vision", "$renwu#"+str, me);

// Modified by Hop
        if( obj!=me && living(obj)
        && (((me_shen < -20000) && (obj_shen > 20000)) || ((me_shen > 20000) && (obj_shen < -20000)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                if(obj->query("age") > 15 && me->query("age") > 15)
                   if(!wizardp(obj) && !wizardp(me))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = "$renwu#"+HIC "  □" NOR + str;
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
	level = obj->query_temp("apply/damage") + obj->query("jiali");
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

