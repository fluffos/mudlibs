// look.c
// Modified by iszt@pkuxkx, 2007-03-26, fixed realtime_map, updated mudlook_living

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <color.h>
#include <mxp.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
#include <identify.h>

int webmain(object me, string arg);//用网页玩的
int weblook_room(object me, object env);//用网页玩的
int weblook_item(object me, object obj);//用网页玩的
int weblook_living(object me, object obj, string arg);//用网页玩的
int weblook_room_item(object me, string arg);//用网页玩的

int mudmain(object me, string arg, int busy);//用ZMUD连入的
int mudlook_room(object me, object env, int busy);//用ZMUD连入的
int mudlook_item(object me, object obj);//用ZMUD连入的
int mudlook_living(object me, object obj);//用ZMUD连入的
int mudlook_room_item(object me, string arg);//用ZMUD连入的
string getper(object me, object obj);
string tough_level(int power, int hide_level);
string gettof(object obj);
string getdam(object obj);
string do_query(object obj);

//发现新区域，给奖励
void give_found_region_reward(object pl,object room);

string *peep_msg = ({
        "好像有人探头探脑地向这边张望了几眼。\n",
        "$N探头探脑地向这边张望了几眼。\n",
        "$N鬼鬼祟祟看了这边几眼，又把脑袋缩回去了。\n",
        "$N伸长了脖子朝这边看了几眼。\n",
        "你忽然觉得似乎有双眼睛在背后盯着你看。\n",
});
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object ob = this_player();     	
	int result;

	
if( ob->query("position") == "zmuduser" ) //如果身上有这个记号就调用MUDMAIN
	{
	if(arg == "+frommove")
	result = mudmain(me, "",0);//使用antirobot算法，随机减少一个出口显示
	else
	result = mudmain(me, arg,1);//正常look，有1s的cd
}
	else 
result = webmain(me, arg);//如果身上没有记号就调用WEBMAIN
	return result;
}
void Examine_Surroundings(object me)
{
	object env,room,*all_pl,ob;
	string *rooms,*dirs,msg="",target;
	int examine_limit=10;
	mapping default_dirs = (["north":"北面","south":"南面","east":"东面","west":"西面","northup":"北边","southup":"南边",
"eastup":"东边","westup":"西边","northdown":"北边","southdown":"南边","eastdown":"东边","westdown":"西边","northeast":"东北",
"northwest":"西北","southeast":"东南","southwest":"西南","up":"上面","down":"下面","enter":"里面","out":"外面",]);
	if (!me||!living(me)||!environment(me)||me->query("level")<101||!me->query("env/shiye")||(me->pure_degree("neili")<0.75&&me->pure_degree("exercised_neili")<0.5)||me->query("neili")<1000)
	return;
	env=environment(me);
	if (!mapp(env->query("exits")))
	return;
	dirs=keys(env->query("exits"));
	rooms=values(env->query("exits"));
	for (int i=0;i<sizeof(rooms);i++)
	{
		if (!load_object(rooms[i])->isroom()) continue;
		if (stringp(target=me->query("env/shiye")))
		{
			if (!ob=present(target,load_object(rooms[i]))) continue;
			else if (ob->query("no_show")) continue;
			else msg=COLOR_D->uncolor(present(target,load_object(rooms[i]))->name());
		}
		else
		{
			all_pl=all_inventory(load_object(rooms[i]));
			all_pl=filter_array(all_pl, (:living:));
			msg="";
			if (sizeof(all_pl)>0)
			{
				if (sizeof(all_pl)<10)
				examine_limit=sizeof(all_pl);
				for (int j=0;j<examine_limit;j++)
				{
					if( !me->visible(all_pl[j]) ) continue;
					msg+=COLOR_D->uncolor(all_pl[j]->name());
					if (j==examine_limit-2)
					msg+="和";
					else if (j!=examine_limit-1)
					msg+="、";
				}
			}
		}
		if (msg!="")
		{
		msg+="在";
		msg+=stringp(default_dirs[dirs[i]])?default_dirs[dirs[i]]:dirs[i];
		msg+="的方向。\n";
		tell_object(me,replace_string(msg,msg,HBGRN+WHT+msg+NOR));
		}
	}
}
void realtime_map(object me,object env)
{
    object room_obj;
    mapping exits;
    int i;
    string ln1,ln2,ln3,ln4,ln5,ln6;
    string map_room, map_room2,jiantou,msg;
    int map_room_width;
    string setforroom;
    string *dirs;
    mapping alldirs=([      
        "northwest"	: "          ",
        "north"		: "          ",
        "northup"	: "          ",
        "northeast"	: "          ",
        "west"		: "          ",
        "east"		: "          ",
        "southeast"	: "          ",
        "south"		: "          ",
        "southwest"	: "          ",
        "southdown"	: "          ",
        "eastup"	: "          ",
        "southup"	: "          ",
        "northdown"	: "          ",
        "eastdown"	: "          ",
        "westup"	: "          ",
        "westdown"	: "          ",
        "enter"		: "          ",
        "out"		: "          ",
        "up"		: "          ",
        "down"		: "          ",
        "left"		: "          ",
        "right"		: "          ",
        ]);  
        //add for save time
	if (me->query("combat_exp")>5000000&&me->query("antirobot/deactivity")>=2)
	return;//5M以上不fullme不显示小地图。Zine 2013/4/20
	msg = env->query("realmap");
	if(msg&&msg!="")
	{
//		printf(msg)
		tell_object(me, msg);
		return;
	}
	msg = "";
	if( mapp(exits = env->query("exits")) ) 
	{                       
		if (me->query("position") != "zmuduser")
			printf("\n");
		dirs=keys(exits);
		for(i=0;i< sizeof(dirs);i++)
		{
//支持exits目标存放object而不是string by seagate@pkuxk 2011/12/24			
			if(!objectp(room_obj=exits[dirs[i]]) &&
				 !room_obj=find_object(exits[dirs[i]]))
				room_obj=load_object(exits[dirs[i]]);
			if(room_obj)
				if (room_obj->query("short"))
					alldirs[dirs[i]]=room_obj->query("short");
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
		for(i=0;i<(10+COLOR_D->color_len(map_room)-strwidth(map_room2))/2;i++)
		{
			map_room =map_room+" ";
			map_room =" "+map_room;
		}
		if (me->query("position") == "zmuduser")
		{
			msg = sprintf("             %"+(int)(COLOR_D->color_len(alldirs["northwest"])+10)+"s  %-"+(int)(COLOR_D->color_len(map_room)+10)+"s  %-"+(int)(COLOR_D->color_len(alldirs["northeast"])+10)+"s\n",
				alldirs["northwest"],map_room,alldirs["northeast"]);
//			printf(msg);
			tell_object(me, msg);
			setforroom = msg;
		}
		else{
			msg = sprintf("%10s %-10s  %-10s\n",
				    alldirs["northwest"],map_room,alldirs["northeast"]);
			msg = replace_string(msg," ","&nbsp");
			msg = replace_string(msg,alldirs["northwest"],
				    "<a target=nothing href=\\\"../Command/go northwest\\\">" + alldirs["northwest"] + "</a>");
			msg = replace_string(msg,alldirs["north"],
				    "<a target=nothing href=\\\"../Command/go north\\\">" + map_room + "</a>");
			msg = replace_string(msg,alldirs["northeast"],
				    "<a target=nothing href=\\\"../Command/go northeast\\\">" + alldirs["northeast"] + "</a>");
			msg = replace_string(msg,alldirs["northup"],
				    "<a target=nothing href=\\\"../Command/go northup\\\">" + alldirs["northup"] + "</a>");
			msg = replace_string(msg,alldirs["northdown"],
				    "<a target=nothing href=\\\"../Command/go northdown\\\">" + alldirs["northdown"] + "</a>");
			msg = replace_string(msg,alldirs["enter"],
				    "<a target=nothing href=\\\"../Command/go enter\\\">" + alldirs["enter"] + "</a>");
			msg = replace_string(msg,alldirs["up"],
				    "<a target=nothing href=\\\"../Command/go up\\\">" + alldirs["up"] + "</a>");
			//write(msg);
			ln1 = msg;
		}
		msg = sprintf("%s   %s   %s\n",
				alldirs["northwest"]=="          " ? "  ":"＼",
				jiantou,
				alldirs["northeast"]=="          " ? "  ":"／");
		setforroom = setforroom + "                        " + msg;
		if (me->query("position") == "zmuduser")
			printf("                        " + msg);
		else
			ln2 = (replace_string("           "+msg," ","&nbsp"));
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
		msg = sprintf("             %"+(int)(COLOR_D->color_len(map_room2)+10)+"s%s",map_room2,jiantou);
		setforroom += msg;
		if (me->query("position") == "zmuduser")
//                printf(msg);
		  tell_object(me, msg);
		else
		{
			msg = sprintf("%10s%s",map_room2,jiantou);
			msg = replace_string(msg," ","&nbsp");
			msg = replace_string(msg,alldirs["westdown"],
				    "<a target=nothing href=\\\"../Command/go westdown\\\">" + alldirs["westdown"] + "</a>");
			msg = replace_string(msg,alldirs["left"],
				    "<a target=nothing href=\\\"../Command/go left\\\">" + alldirs["left"] + "</a>");
			msg = replace_string(msg,alldirs["westup"],
				    "<a target=nothing href=\\\"../Command/go westup\\\">" + alldirs["westup"] + "</a>");
			msg = replace_string(msg,alldirs["west"],
				    "<a target=nothing href=\\\"../Command/go west\\\">" + alldirs["west"] + "</a>");
			ln3 = msg;
		}
		map_room2=env->query("short") ? env->query("short"): "----------";
		map_room=HIG+map_room2+NOR;
		map_room_width = (10+COLOR_D->color_len(map_room)-strwidth(map_room))/2;
		for(i=0;i<map_room_width;i++)
		{
			if(alldirs["east"]=="          ")
				map_room =map_room + " ";
			else map_room=map_room + "-";
			if(alldirs["west"]=="          ")
				map_room =" "+ map_room;
			else map_room ="-"+map_room;
		}
		msg = sprintf("%s",map_room);
		setforroom +=msg;
		if (me->query("position") == "zmuduser")
			tell_object(me, msg);
		else
		{
			msg = replace_string(msg," ","&nbsp");
			msg = replace_string(msg,map_room,
				    "<a target=nothing href=\\\"../Command/look\\\">" + map_room + "</a>");
			ln3 += msg;
		}
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
		msg = sprintf("%s%-"+(int)(COLOR_D->color_len(map_room2)+10)+"s\n",jiantou,map_room2);
		setforroom += msg;
		if (me->query("position") == "zmuduser")
			tell_object(me,msg);
		else
		{
			msg = replace_string(msg," ","&nbsp");
			msg = replace_string(msg,alldirs["eastdown"],
				    "<a target=nothing href=\\\"../Command/go eastdown\\\">" + alldirs["eastdown"] + "</a>");
			msg = replace_string(msg,alldirs["left"],
				    "<a target=nothing href=\\\"../Command/go right\\\">" + alldirs["right"] + "</a>");
			msg = replace_string(msg,alldirs["eastup"],
				    "<a target=nothing href=\\\"../Command/go eastup\\\">" + alldirs["eastup"] + "</a>");
			msg = replace_string(msg,alldirs["east"],
				    "<a target=nothing href=\\\"../Command/go east\\\">" + alldirs["east"] + "</a>");
			ln3 += msg;
		}
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
		for(i=0;i<(10+COLOR_D->color_len(map_room2)-strwidth(map_room2))/2;i++)
		{
			map_room =map_room + " ";
			map_room =" "+map_room;
		}
		msg = sprintf("%s   %s   %s\n",
				alldirs["southwest"]=="          " ? "  ":"／",
				jiantou,
				alldirs["southeast"]=="          " ? "  ":"＼");
		setforroom = setforroom + "                        " + msg;
		if (me->query("position") == "zmuduser")
			tell_object(me,"                        "+msg);
		else
			ln4 = replace_string("           "+msg," ","&nbsp");
		msg = sprintf("%"+(int)(COLOR_D->color_len(alldirs["southwest"])+10)+"s  %-"+(int)(COLOR_D->color_len(alldirs["map_room"])+10)+"s  %-"+(int)(COLOR_D->color_len(alldirs["southeast"])+10)+"s\n",
				alldirs["southwest"],map_room,alldirs["southeast"]);
		setforroom = setforroom + "             " + msg;
		if (me->query("position") == "zmuduser")
			printf("             "+msg);
		else
		{
			msg = sprintf("%10s %-10s  %-10s\n",
				    alldirs["southwest"],map_room,alldirs["southeast"]);
			msg = replace_string(msg," ","&nbsp");
			msg = replace_string(msg,alldirs["southdown"],
				    "<a target=nothing href=\\\"../Command/go southdown\\\">" + alldirs["southdown"] + "</a>");
			msg = replace_string(msg,alldirs["down"],
				    "<a target=nothing href=\\\"../Command/go down\\\">" + alldirs["down"] + "</a>");
			msg = replace_string(msg,alldirs["southup"],
				    "<a target=nothing href=\\\"../Command/go southup\\\">" + alldirs["southup"] + "</a>");
			msg = replace_string(msg,alldirs["south"],
				    "<a target=nothing href=\\\"../Command/go south\\\">" + map_room + "</a>");
			msg = replace_string(msg,alldirs["out"],
				    "<a target=nothing href=\\\"../Command/go out\\\">" + alldirs["out"] + "</a>");
			msg = replace_string(msg,alldirs["southeast"],
				    "<a target=nothing href=\\\"../Command/go southeast\\\">" + alldirs["southeast"] + "</a>");
			msg = replace_string(msg,alldirs["southwest"],
				    "<a target=nothing href=\\\"../Command/go southwest\\\">" + alldirs["southwest"] + "</a>");
			ln5 = msg;
		}
	}
	else
	{
		map_room2=env->query("short") ? env->query("short"): "----------";
		map_room=HIG+map_room2+NOR;
		for(i=0;i<(10-strwidth(map_room2))/2;i++)
		{
			if(alldirs["east"]=="          ")
				map_room =map_room + " ";
			else map_room=map_room + "-";
			if(alldirs["west"]=="          ")
				map_room =" "+ map_room;
			else map_room ="-"+map_room;
		}
		msg = sprintf("\n                            %s\n",map_room);
		//        setforroom += msg;
		if (me->query("position") == "zmuduser")
			tell_object(me,msg);
	}
	if (me->query("position") != "zmuduser")
	{
		if( mapp(exits = env->query("exits")) ) {
			dirs = keys(exits);
			for(i=0; i<sizeof(dirs); i++)
				if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				    dirs[i] = 0;
			dirs -= ({ 0 });
			if( sizeof(dirs)==0 )
				ln6 = "    这里没有任何明显的出路。";
			else if( sizeof(dirs)==1 )
				ln6 = "    这里唯一的出口是 <a target=nothing href=\\\"../Command/go "  + dirs[0] + "\\\"" + WEBRED + dirs[0]  + "</a>" + WEBNOR + "。";
			else {
				ln6 = "    这里明显的出口是 ";
				for (i = 0; i < sizeof(dirs) - 2; i++)
				    ln6 += sprintf("<a target=nothing href=\\\"../Command/go %s\\\">%s</a>、", dirs[i], dirs[i]);
				ln6 += sprintf("<a target=nothing href=\\\"../Command/go %s\\\">%s</a>和", dirs[sizeof(dirs) - 2], dirs[sizeof(dirs) - 2]);
				ln6 += sprintf("<a target=nothing href=\\\"../Command/go %s\\\">%s</a>", dirs[sizeof(dirs) - 1], dirs[sizeof(dirs) - 1]);
				ln6 += "。";
			}
		}
		printf(JSP "parent.look_map(\"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\")" NSP, 
				ln1,ln2,ln3,ln4,ln5,ln6);	
	}
	env->set("realmap",setforroom);
	return;
}

string gettof(object ob)
{
    object weapon;
    string skill_type;
    int attack_points, hide_level;
    mapping prepare;
    if( objectp(weapon = ob->query_temp("weapon")) )
    {
        skill_type = weapon->query("skill_type");
    }
    else
    {
        prepare = ob->query_skill_prepare();
        if (!sizeof(prepare)) skill_type = "parry";
        else skill_type = keys(prepare)[0];
    }
    attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
//展示的时候减弱apply/strength的效果 by seagate@pkuxkx
    if ( ob->query_temp("apply/strength")>0 )
    	  attack_points=(attack_points/ob->query_str())*(ob->query_str()-ob->query_temp("apply/strength")*2/3);
    if( intp(hide_level = ob->query("hide_level")) && hide_level > 0)
        return tough_level(attack_points, hide_level);
    return tough_level(attack_points, 0);
}

string tough_level(int power, int hide_level)
{
    int lvl, rawlvl;
    string *tough_level_desc = ({
    BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,BLU "勉勉强强" NOR,
    HIB "初窥门径" NOR,HIB "初出茅庐" NOR,HIB "略知一二" NOR,HIB "普普通通" NOR,HIB "平平淡淡" NOR,
    CYN "平淡无奇" NOR,CYN "粗通皮毛" NOR,CYN "半生不熟" NOR,CYN "马马虎虎" NOR,CYN "略有小成" NOR,
    HIC "已有小成" NOR,HIC "鹤立鸡群" NOR,HIC "驾轻就熟" NOR,HIC "青出于蓝" NOR,HIC "融会贯通" NOR,
    GRN "心领神会" NOR,GRN "炉火纯青" NOR,GRN "了然于胸" NOR,GRN "略有大成" NOR,GRN "已有大成" NOR,
    YEL "豁然贯通" NOR,YEL "出类拔萃" NOR,YEL "无可匹敌" NOR,YEL "技冠群雄" NOR,YEL "神乎其技" NOR,
    HIY "出神入化" NOR,HIY "非同凡响" NOR,HIY "傲视群雄" NOR,HIY "登峰造极" NOR,HIY "无与伦比" NOR,
    RED "所向披靡" NOR,RED "一代宗师" NOR,RED "精深奥妙" NOR,RED "神功盖世" NOR,RED "举世无双" NOR,
    WHT "惊世骇俗" NOR,WHT "撼天动地" NOR,WHT "震古铄今" NOR,WHT "超凡入圣" NOR,WHT "威镇寰宇" NOR,
    HIW "空前绝后" NOR,HIW "天人合一" NOR,MAG "深藏不露" NOR,HIM "深不可测" NOR,HIR "返璞归真" NOR
    });
    if(power<0) power=0;
    rawlvl = (int) pow( (float) 1.0 * power, 0.2);
    lvl = to_int(rawlvl);
    if(hide_level)
        lvl = hide_level;
    if( lvl >= sizeof(tough_level_desc) )
        lvl = sizeof(tough_level_desc)-1;
    return tough_level_desc[lvl];
}

string getdam(object obj)
{
    int level;
    string *heavy_level_desc= ({
        MAG"极轻"NOR,HIC"很轻"NOR,HIM"较轻",HIY"不重"NOR,HIG"不轻"NOR,BLU"较重"NOR,HIB"很重"NOR,HIR"极重"NOR,
        });
    level = obj->query("jiali");
    if(obj->query_temp("apply/damage") > 0)
        level += obj->query_temp("apply/damage")/3;  // weapon 加力效果等于 unarmed / 3
    level /= 50;
    if( level >= sizeof(heavy_level_desc) )
        level = sizeof(heavy_level_desc)-1;
    return heavy_level_desc[((int)level)];
}
string inventory_look(object obj, int flag)
{
    string str;

    str = obj->short();
    if( obj->query("equipped") )
        str = HIC "  □" NOR + do_query(obj);
    else if( !flag )
        str = "    " + str;
    else
        return 0;
    return str;
}

int sort_inventory(object ob1,object ob2)
{
	return strcmp(ob1->name(),ob2->name());
}

int random_flee(object user)
{
  mapping exits;
  string *dirs;
  int i;

  if ( !environment(user) ) 
  	return 0;

  if ( sizeof(environment(user)->query("exits")) == 0 ) 
  	return 0;
  
  if ( !mapp(exits = environment(user)->query("exits")) ) 
  	return 0;
  
  dirs = keys(exits);
  i = random(sizeof(dirs));
  
  if( !environment(user)->valid_leave(user, dirs[i]) ) 
  	return 0;
  
  user->move(exits[dirs[i]]);
}

//******************************************************
//如果是用网页玩的执行这一部份的LOOK
int webmain(object me, string arg)
{
        object obj;
        int result;
        string str;

	if (me->query("position") != "zmuduser")
	{
write("<html>");
write("<head>");
write("<meta http-equiv=\\\"Content-Type\\\" content=\\\"text/html; charset=gb2312\\\">");
write("<title>status</title>");
write("<STYLE type=text/css>BODY {");
write("	COLOR: #000000; FONT-FAMILY: \\\"宋体\\\"; ");
write("FONT-SIZE: 11pt");
write("}");
write("TD {");
write("	FONT-FAMILY: \\\"宋体\\\"; FONT-SIZE: ");
write("9pt");
write("}");
write("A:link {");
write("	COLOR=\\\"#00ff00\\\"; TEXT-DECORATION: none");
write("}");
write("A:visited {");
write("	COLOR=\\\"#00ff00\\\"; TEXT-DECORATION: none");
write("}");
write("A:active {");
write("	COLOR=\\\"#00ff00\\\"; TEXT-DECORATION: none");
write("}");
write("A:hover {");
write("	COLOR=\\\"#006666\\\"; TEXT-DECORATION: none");
write("}");
write("</style>");
write("</head>");
		str = "parent.document.forms['commandForm'].input.select(); parent.document.forms['commandForm'].input.focus();";
        	printf(JSP + str + NSP);
        }

  	if( me->query_temp("blind") ) return notify_fail("你现在是个瞎子,看不见东西。\n");
        if( !arg ) result = weblook_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = weblook_living(me, obj,arg);
                else result = weblook_item(me, obj);
        } else result = weblook_room_item(me, arg);

        return result;
}

int weblook_room(object me, object env)
{
    int i,j;
    object *inv1;
    object ob;
    int *count,cnn;
    object *inv;
    mapping exits;
    string str, *dirs;
    string bfile;//file_name,name;
    mapping buffo = ([]), buffobj = ([]);
    string short, long, exit, desc;

    if( !env ) {
        write("你的四周灰蒙蒙地一片，什么也没有。\n");
        return 1;
    }
    short = sprintf(WEBBLK "【" WEBNOR WEBRED " %s"  WEBNOR WEBBLK "】" + WEBNOR, env->query("short"));
    short += wizardp(me)? file_name(env): "";
    desc = replace_string(env->query("long"),"\n","");
    long = desc + "<br>　　" + WEBYEL +
        replace_string(implode(explode((env->query("outdoors")?"":"窗外：") + NATURE_D->outdoor_room_description(), "\n"), ""),"[0m","")  + WEBNOR;

    str = sprintf( "%s - %s\n    %s%s",
            env->query("short"),
            wizardp(me)? file_name(env): "",
            env->query("long"),
            env->query("outdoors")? replace_string(NATURE_D->outdoor_room_description(),"[0m","") + WEBNOR: "" );

    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
        if( sizeof(dirs)==0 )
            str += "    这里没有任何明显的出路。\n";
        else if( sizeof(dirs)==1 )
            str += "    这里唯一的出口是 <a target=nothing href=\"../Command/go "  + dirs[0] + "\"" + WEBRED + dirs[0]  + "</a>" + WEBNOR + "。";
        else {
            cnn = 0;
            str += "    这里明显的出口是 ";
            for (i = 0; i < sizeof(dirs) - 2; i++)
                str += sprintf("<a target=nothing href=\"../Command/go %s\">%s</a>、", dirs[i], dirs[i]);
            str += sprintf("<a target=nothing href=\"../Command/go %s\">%s</a>和", dirs[sizeof(dirs) - 2], dirs[sizeof(dirs) - 2]);
            str += sprintf("<a target=nothing href=\"../Command/go %s\">%s</a>", dirs[sizeof(dirs) - 1], dirs[sizeof(dirs) - 1]);
            str += "。";
        }
    }
    str += "\n";

    ob = env;
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]==me ) continue;
        if( inv[i]->query("no_show")) continue;
        if( !me->visible(inv[i]) ) continue;
        bfile=base_name(inv[i]);
        if ( member_array(bfile,keys(buffo)) == -1 )
        {
            buffo[bfile]=1;
            buffobj[bfile]=inv[i];
            str += sprintf("<a target=nothing href=\"../Command/look %s\">%s</a><br>",
                    inv[i]->query("id"), inv[i]->short());
        }
        else 
        {
            buffo[bfile] ++;
            str += sprintf("<a target=nothing href=\"../Command/look %s %d\">%s</a><br>",
                    inv[i]->query("id"), buffo[bfile], inv[i]->short());
        }
    }

    realtime_map(me,env);
    printf(str);

    printf(JSP "parent.look_room(\"%s\", \"%s\", \"%s\")" NSP, 
            short, long, exit);
    return 1;
}

int weblook_item(object me, object obj)
{
    mixed *inv;

    write(obj->long());
    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object() );
        message("vision", sprintf("里面有：\n  %s\n", implode(inv, "\n  ") ), me);
    }
    return 1;
}

int weblook_living(object me, object obj, string arg)
{
    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;
    int age, complex, anti_complex;
    string gender;
    object head;

    if( me!=obj && !wizardp(me))
        message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

//如果对方伪装则自动进行伪装识别鉴定，鉴定成果则破除伪装
//by seagate@pkuxkx 2010/12/09
    if ( me!=obj && 
    	   obj->is_mask() &&
    	   (anti_complex=DISGUISE_D->query_anti_complex(me)) &&
    	   obj->can_anti_disguise(anti_complex) ) 
    {
    	complex=obj->query_face_complex();
      random_flee(obj);
      obj->add_busy(1);
      obj->uncover_mask();
//如果头上戴着面具则自动去除面具
      if ( (head=obj->query_temp("armor/head")) &&
      	   head->query("mask") )
        head->unequip();

      message_vision("$n发现自己的伪装被$N识破了，连忙卸下伪装逃跑了！\n", me, obj);
      if ( complex * 2 > anti_complex ) 
      {
      	DISGUISE_D->improve_disguise(1, anti_complex, me);
      	message_vision("$N通过这次伪装识别锻炼，发现自己对伪装识别技巧又有了更加深刻的理解！\n", me);
      }
      return 1;
    }

    str = obj->long();

    if (obj->query_temp("apply/gender"))
        gender = obj->query_temp("apply/gender")[0];
    else
        gender = obj->query("gender");

    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(gender);

    if (obj->query_temp("apply/age"))
        age = obj->query_temp("apply/age")[0];
    else
        age = obj->query("age");

    if( (string)obj->query("race")=="人类"
            &&      intp(age) )
    {
//内力深厚以后对年龄的视觉效果有轻微影响。
//by seagate@pkuxkx
        if ( !obj->query_temp("apply/age") &&
        	   obj->query_skill("force")>800 )
        {
			if (age<10)
			str+= sprintf("%s看起来还不满十岁。\n", pro );
        	else if( age-(obj->query_skill("force")-800)/120>=30 )
            str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number( (age-(obj->query_skill("force")-800)/120) / 10 * 10));
          else if ( age >= 30 )
          	str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(30));
          else
          	str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 10 * 10));
        }
        else if (age<10)
			str+= sprintf("%s看起来还不满十岁。\n", pro );
		else
          str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 10 * 10));
    }

    if (obj==me) str += "你看来很象镜子中的你呀!\n";
    else if ( me->query("age") <= 14 ) 
        str += "你才十四岁就要看吗,你什么也不懂呀.\n";
    else if(obj->is_character()&&obj->query("race")=="人类")
    {
        if ( age > 14 )
            str += getper(me, obj);
        else
            str += "这么个小家伙有什么可看的呢?\n";
    }
    // If we both has family, check if we have any relations.
    if( obj!=me
            &&      !obj->query_temp("apply/name")
            &&      mapp(fam = obj->query("family"))
            &&      mapp(my_fam = me->query("family")) 
            &&      fam["family_name"] == my_fam["family_name"] ) {

        if( fam["generation"]==my_fam["generation"] ) {
            if( (string)obj->query("gender") == "男性" ||
                    (string)obj->query("gender") == "无性")
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
            else
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
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
	if (obj->query("race")=="人类" || obj->query("race")=="机关人")
	{
		str +=sprintf("%s的武艺看上去", pro);
		str +=gettof(obj);
		str +="，";
		str +=sprintf("出手似乎");
		str +=getdam(obj);
		str += sprintf("。\n");
		if( obj->query("max_qi") )
			str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";
	} 
    inv = all_inventory(obj);
	if(me->is_realuser())
	{
		inv = filter_array(inv,(:$1->query("equipped"):));
		inv = sort_array(inv,"sort_inventory",this_object());
	}

    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
        inv -= ({ 0 });
        if( sizeof(inv) )
            str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                    pro, implode(inv, "\n") );
    }

    message("vision", str, me);

/*
    if( obj!=me 
            &&      living(obj)
        &&      random((int)obj->query("shaqi")) > (int)me->query_per() -(int)me->query("age")/2 ) {
        write( obj->name() + "突然转过头来瞪你一眼。\n");
        COMBAT_D->auto_fight(obj, me, "berserk");
    }

*/
    if( obj!=me 
            &&      living(obj)
        &&  (int)obj->query("shaqi")>50 ) {
       if (random(to_int(obj->query("shaqi")*10)) > (int)me->query_per()*50)
{
        write( obj->name() + "突然转过头来瞪你一眼。\n");
        COMBAT_D->auto_fight(obj, me, "berserk");
}
    }

    return 1;
}

int weblook_room_item(object me, string arg)
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
                        weblook_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        weblook_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}

//######################################################
//如果是用ZMUD玩的执行这一部份的LOOK

int mudmain(object me, string arg,int busy)
{
    object obj;
    int result;

    if( me->query_temp("blind") ) return notify_fail("你现在是个瞎子，看不见东西。\n");
    if( !arg || sizeof(arg) == 0) result = mudlook_room(me, environment(me),busy);
    else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
        if( obj->is_character() ) result = mudlook_living(me, obj);
        else result = mudlook_item(me, obj);
    } else result = mudlook_room_item(me, arg);

    return result;
}

string mixed_long(string des)
{		
	string output="";
	string *biaodian=({
		"，",
		"。",
		"“",
		"”",
		"！",
		"？",
		"（",
		"）",
		"：",
		"；",
		"、",
		"《",
		"》",
		"〉",
		"〈",
		"’",
		"‘",
	});
	
	//close the function
	return des;
	
	if(sizeof(des)==0) return "";
	for(int i=0;i<sizeof(des);i++)
	{
		if(des[i]>160&&des[i]<255)
		{
			if(member_array(des[i..i+1],biaodian)==-1)
			{
				if(random(200) == 5) {i++;continue;}
			}
			output = output + des[i..i+1];
			i++;					
		}
		else
		{
			output = output + des[i..i];
		}
	}
	return output;
			
}

int mudlook_room(object me, object env,int busy)
{
    int i,j;
    object *inv1;
    object ob;
    int *count,cnn;
    object *inv;
    mapping exits;
    string str, *dirs;
	string* items;
	string MUD_HOST;
	
	if(busy == 1 && time() - me->query_temp("antirobot/last_look_time") < 1)
	{
		write("风景要慢慢的看。\n");
		return 1;
	}
	
    if( !env ) {
        write("你的四周灰蒙蒙地一片，什么也没有。\n");
        tell_object(me, "由于你不知身在何处，你被送到了最后乐园...\n");
        me->move( VOID_OB );
        return 1;
    }


    give_found_region_reward(me,env);

	
	if(!env->query_temp("mixed_long"))
	{
		env->set_temp("mixed_long",mixed_long(env->query("long")));
	}
	
    str = sprintf( "%s - %s\n    %s%s%s",
            env->query("short"),
            wizardp(me)? file_name(env): "",
            env->query_temp("mixed_long"),
            env->is_guider_base()? "\n    "+HIC+"这里建起了一大片宅子，气势恢宏，不知道主人是谁。\n"+NOR:"",
            env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );
	if(env->query("item_desc") && sizeof(env->query("item_desc")) > 0)
	{
		items = keys(env->query("item_desc"));
		str += "    你可以看看(look):";
		for(i=0;i<sizeof(items);i++)
		{
			if (env->query("item_desc_color"))
			items[i]=env->query("item_desc_color")+items[i]+NOR;
			
			str += items[i];
			if (i!=sizeof(items)-1)
			str +=",";
		}

		str += "\n";
	}

    if( mapp(exits = env->query("exits")) ) {
        dirs = keys(exits);
        for(i=0; i<sizeof(dirs); i++)
            if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                dirs[i] = 0;
        dirs -= ({ 0 });
		/*if(busy == 0 && random(30) == 0 && sizeof(dirs) > 0)
		{
			dirs -= ({dirs[random(sizeof(dirs))]});
		}*/			
		
        if( sizeof(dirs)==0 )
            str += "    这里没有任何明显的出路。\n";
        else if( sizeof(dirs)==1 )
            str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
        else {
            cnn = 0;
            for (j = 0;j < sizeof(dirs); j++)
            {
                if (j != 0 && j % 6 ==0)
				{
                    dirs[j]+= "\n";
				}
            }
            str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                    implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
    }

    ob = env;
    inv = all_inventory(ob);
    for (i = 0; i < sizeof(inv); i++) 
    {
        if(!me->visible(inv[i])) continue;
        if (!arrayp(inv1))
        {
            inv1=({inv[i]});
            count=({1});
        }
        else
        {
            for (j = 0; j < sizeof(inv1); j++)
                if  ( (base_name(inv[i])==base_name(inv1[j])) && (inv[i]->query("name") == inv1[j]->query("name")) && (inv[i]->query("id") == inv1[j]->query("id")) && (inv[i]->query("disable_type") == inv1[j]->query("disable_type")) )
                    break;
            if (j == sizeof(inv1) || userp(inv[i]))
            {
                inv1+=({inv[i]});
                count+=({1});
            }
            else
                count[j]+=1;
        }                
    }
    for(i=0; i<sizeof(inv1); i++) 
    {
        if(i%100 == 0) reset_eval_cost();
        if( inv1[i]==me ) continue;
        if( !userp(inv1[i]) && inv1[i]->query("no_show") ) continue;
        if( !me->visible(inv1[i]) ) continue;
        if(count[i]==1)
            str += "    "+inv1[i]->short()+"\n";
        else
            str +="    "+chinese_number(count[i]) +"" + inv1[i]->query("unit") +""+ inv1[i]->short()+"\n";
    }
    realtime_map(me,env);
    me->start_more(str);
	if (busy)
	Examine_Surroundings(me);
	me->set_temp("antirobot/last_look_time",time());

	if(me->query("env/mxp_image") == 1 && stringp(env->query("mxp/icon")))
	{
		if(me->query("env/edu") == 1)
		{
			MUD_HOST = MUD_EDU_WEB;
		}
		else
		{
			MUD_HOST = MUD_WEB;
		}
		tell_object(me,"\n\n");
		SendImage(me,env->query("mxp/icon"),64,64,"center",MUD_HOST+"/player_icon/");
	}
	
    return 1;
}

int mudlook_item(object me, object obj)
{
    object *inv;
    object *inv1;
	string str;
    int rig;
	int i ,j , idf, itype;
	int *count;
	str = "";
    write(obj->long());
    
    idf = obj->get_idflevel();
    itype = obj->is_identify();
    
    if( itype==IDF_EQUIP || 
        ( itype==IDF_SIMPLE &&
          idf==IL_FULL ) )
    {
      if( idf==IL_INIT )
    	  str = HIR"（未鉴定）\n"NOR;
      else if ( idf==IL_SIMPLE )
    	  str = HIY"（部分鉴定）\n"NOR;
      else if ( idf==IL_FULL )
    	  str = HIG"（已鉴定）\n"NOR;
      
      str+=obj->identify(idf);
  	}
  	else if ( itype==IDF_SIMPLE )
  	  str=obj->identify(IL_FULL);
    
    rig = obj->query("rigidity");
    if (rig > 0)	//已经坏了的就不管了。
        if (rig > 100)
            message("vision", obj->name() + "完好无损，宛如新的一般。\n", me);
        else if (rig > 80)
            message("vision", obj->name() + "已经轻微磨损，表面布满了细细的划痕。\n", me);
        else if (rig > 40)
            message("vision", obj->name() + "多次与其他兵器撞击，表面已是遍体鳞伤，但仍然可以凑合着用。\n", me);
        else if (rig > 10)
            message("vision", obj->name() + "已是严重受损，几道明显的裂纹已经危及了它的寿命。\n", me);
        else if (rig > 0)
            message("vision", obj->name() + "被几道深深的裂痕分割成几部份，几乎马上就要断了。\n", me);
       inv = all_inventory(obj);
       for (i = 0; i < sizeof(inv); i++) 
		{
		   if (!arrayp(inv1))
			{inv1=({inv[i]});
			 count=({1});}
		    else
		   {
			for (j = 0; j < sizeof(inv1); j++)
            if ((base_name(inv[i]) == base_name(inv1[j])) && (inv[i]->short() == inv1[j]->short()))
			break;
			if (j == sizeof(inv1))
			{
			inv1+=({inv[i]});
			count+=({1});
			}
			else
			count[j]+=1;
			}
		}
         for(i=0; i<sizeof(inv1); i++) {
         if(count[i]==1)
         str += ""+inv1[i]->short()+"\n";
         else
        str +=""+chinese_number(count[i]) +"" + inv1[i]->query("unit") +""+ inv1[i]->short()+"\n";
	}
    this_player()->start_more(str);
    return 1;
}


int mudlook_living(object me, object obj)
{
    string str, limb_status, pro;
    mixed *inv;
    mapping my_fam, fam;
    int age, complex, anti_complex;
    string gender;
    string MUD_HOST;
    object head;

    if( me!=obj && !wizardp(me))
        message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);

//如果对方伪装则自动进行伪装识别鉴定，鉴定成果则破除伪装
//by seagate@pkuxkx 2010/12/09
    if ( me!=obj && 
    	   obj->is_mask() &&
    	   (anti_complex=DISGUISE_D->query_anti_complex(me)) &&
    	   obj->can_anti_disguise(anti_complex) ) 
    {
    	complex=obj->query_face_complex();
      random_flee(obj);
      obj->add_busy(5);
      obj->uncover_mask();
//如果头上戴着面具则自动去除面具
      if ( (head=obj->query_temp("armor/head")) &&
      	   head->query("mask") )
        head->unequip();

      message_vision("$n发现自己的伪装被$N识破了，连忙卸下伪装逃跑了！\n", me, obj);
      if ( complex * 2 > anti_complex ) 
      {
      	DISGUISE_D->improve_disguise(1, anti_complex, me);
      	message_vision("$N通过这次伪装识别锻炼，发现自己对伪装识别技巧又有了更加深刻的理解！\n", me);
      }
      return 1;
    }

	if(me->query("env/mxp_image") == 1 && stringp(obj->query("mxp/icon")))
	{
		if(me->query("env/edu") == 1)
		{
			MUD_HOST = MUD_EDU_WEB;
		}
		else
		{
			MUD_HOST = MUD_WEB;
		}
		tell_object(me,"\n\n");
		SendImage(me,obj->query("mxp/icon"),64,64,"left",MUD_HOST+"/player_icon/");
	}
    str = obj->long();

    if (obj->query_temp("apply/gender"))
        gender = obj->query_temp("apply/gender")[0];
    else
        gender = obj->query("gender");

    pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(gender);

    if (obj->query_temp("apply/age"))
        age = obj->query_temp("apply/age")[0];
    else
        age = obj->query("age");

    if( (string)obj->query("race")=="人类"
            &&      intp(obj->query("age")) )
    {
//内力深厚以后对年龄的视觉效果有轻微影响。
//by seagate@pkuxkx
      if ( !obj->query_temp("apply/age") &&
      	   obj->query_skill("force")>800 )
      {
			if (age<10)
			str+= sprintf("%s看起来还不满十岁。\n", pro );//小于10岁直接返回不满10岁，不然就是零多岁。 zine@pkuxkx 2014/7
        	else if( age-(obj->query_skill("force")-800)/120>=100 )
            str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number( (age-(obj->query_skill("force")-800)/120) / 100 * 100));
          else if( age-(obj->query_skill("force")-800)/120>=30 )
          	str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number( (age-(obj->query_skill("force")-800)/120) / 10 * 10));
          else if ( age >= 30 )
          	str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(30));
          else
          	str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 10 * 10));
      }
      else
      {
		if (age<10)
		str+= sprintf("%s看起来还不满十岁。\n", pro );
      	else if (age<100)
          str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 10 * 10));
        else		
          str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(age / 100 * 100));
      }
    }

    if (obj==me) str += "你看来很象镜子中的你呀！\n";
    else if ( me->query("age") <= 14 ) 
        //str += "你才十四岁就要看吗,你什么也不懂呀.\n";
        str += "";
    else if(obj->is_character()&&obj->query("race")=="人类")//必须是人类才出容貌或者稚气未脱，否则对一个动物用这个形容太弱了，By Zine
    {
        if (obj->query("age") > 14)
            str += getper(me, obj);
        else
            str += "年纪太小，还是稚气未脱的孩子。\n";
    }
    // If we both has family, check if we have any relations.
    if( obj!=me
            &&      !obj->query_temp("apply/name")
            &&      mapp(fam = obj->query("family"))
            &&      mapp(my_fam = me->query("family")) 
            &&      fam["family_name"] == my_fam["family_name"] ) {

        if( fam["generation"]==my_fam["generation"] ) {
            if( (string)obj->query("gender") == "男性" ||
                    (string)obj->query("gender") == "无性")
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
            else
                str += sprintf( pro + "是你的%s%s。\n",
                        my_fam["master_id"] == fam["master_id"] ? "": "同门",
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
	if (obj->query("race")=="人类" || obj->query("race")=="机关人" )//必须是人类才用人类的武功级别描述，否则对一个动物用这个形容太弱了，By Zine
	{
		if (!obj->is_corpse() ) {
		str +=sprintf("%s的武艺看上去", pro);
		str +=gettof(obj);
		str +="，";
		str +=sprintf("出手似乎");
		str +=getdam(obj);
		str += sprintf("。\n");
		 }
		if( obj->query("max_qi") )
			str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";
	}
    inv = all_inventory(obj);
    if( sizeof(inv) ) {
        inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
        inv -= ({ 0 });
        if( sizeof(inv) )
            str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "%s身上带著：\n%s\n",
                    pro, implode(inv, "\n") );
    }

    message("vision", str, me);

    if( obj!=me 
            &&      living(obj)
        &&  (int)obj->query("shaqi")>50 ) {
       if (random(to_int(obj->query("shaqi")*10)) > (int)me->query_per()*50)
{
        write( obj->name() + "突然转过头来瞪你一眼。\n");
        COMBAT_D->auto_fight(obj, me, "berserk");
}
    }

    return 1;
}

string do_query(object obj)
{
        string str, units;

        units = obj->query("unit");
        str = obj->short();
        if( obj->query("armor_type") )
                switch( obj->query("armor_type") ) {
                        case "surcoat":
                                str = "披着一" + units + str;
                                break;
                        case "cloth":
                        case "armor":
                        case "skirt":
                                str = "身穿一" + units + str;
                                break;
                        case "boots":
                                str = "脚穿一" + units + str;
                                break;
                        case "head":
                        case "neck":
                        case "wrists":
                        case "finger":
                        case "hands":
                                str = "戴着一" + units + str;
                                break;
                        case "waist":
                                str = "腰绑一" + units + str;
                                break;
                        case "flower":
                                str = "头戴一" + units + str;
                                break;
                        case "shirt":
                                str = "衬着一" + units + str;
                                break;
                        default:
                                str = "装备着" + str; 
                }
        else if( obj->wield() ) {
                if( obj->query("skill_type") == "throwing" )
                        str ="身上带着"+str;
                else
                        str ="手持一" + units + str;
        }
        return str;     
}

int mudlook_room_item(object me, string arg)
{
        object env;
        mapping item, exits;
        function f_item;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                {
//重新绑定函数指针与环境的关系，防止副本类地图的时候base object被自动清理产生的对象丢失问题。
//Virtual Object中函数指针必须是(:call_other,__FILE__,"myfunction":)形式，否则绑定会报错。
// by seagate 2011/05/14
                        if ( virtualp(env) )
                        {
                        	f_item=bind(item[arg],env);
                        	write((string)evaluate(f_item));
                        }
                        else
                	        write((string)(*item[arg])(me));
                }
                        
                return 1;
        }
/*
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        mudlook_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        mudlook_room(me, find_object(exits[arg]));
                }
                return 1;
        }
*/
        if( env->query("no_look") )
                return notify_fail("你什么也看不见。\n");
        if( mapp(exits = env->query("exits")) && exits[arg] && !undefinedp(exits[arg]) ) {
                if( (objectp(exits[arg]) && env=exits[arg]) || objectp(env = load_object(exits[arg])) ) {
                        mudlook_room(me, env,0);
                        if( !me->query("env/invisibility") && random(3)==0 && env != environment(me) ) {
                                string msg=peep_msg[random(sizeof(peep_msg))];
                                msg = replace_string(msg, "$N", me->name());
                                tell_room(env, msg);
                        }
                } else
                        return notify_fail("你什么也看不见。\n");
                return 1;
        }

        return notify_fail("你要看什么？\n");
}

//增加内功对年龄的增益作用，将80岁作为容貌的分界点。
// by seagate@pkuxkx
string getper(object me, object obj)
{
    int per;
    int age;
    int bty;
    string cls;
    string str;
    string gender;
	string pro;
    per = obj->query_per();
    if (obj->query_temp("apply/age"))
        age = obj->query_temp("apply/age")[0];
    else
        age = obj->query("age");
//    age = obj->query("age");
    if ( !obj->query_temp("apply/age") &&
     	   obj->query_skill("force")>800 )
    {
     	if ( age-(obj->query_skill("force")-800)/120>=30 )
        age=age-(obj->query_skill("force")-800)/120;
      else if ( age>30 )
      	age=30;
    }
    
    bty = obj->query_skill("beauty",1);
    cls = obj->query("class");

    if (random(2)) per = per + 1;
    if (obj->query_temp("apply/gender"))
        gender = obj->query_temp("apply/gender")[0];
    else
        gender = obj->query("gender");

    if(age > 80 ) per = per/2;
    else if( age > 60 ) per = per*2/3;

    if (age>=80)
    {
      if (gender=="男性")
        {
        if (cls=="bonze") 
          {
	        if (per >20) str= HIG"他宝相庄严，眉直口阔，近看似天尊入世，远观如西天活佛。\n"NOR; 
	        else if (per > 15) str=HIG"他貌相庄严，身如山岳，虎目含威，便似这一生纵横四海，从未屈服过。\n"NOR; 
	        else str=HIG"他脸上的松皮都耷拉到了肩膀上，口中牙齿早已掉光，秃秃一个脑袋到还算得油光锃亮。\n"NOR; 
        	}
        else if (cls=="taoist") 
        	{
                if (per >20) str= HIG"他仙风道骨，清逸出尘，笑看白云变苍狗，闲品逝水入流年，天子呼来不应对，自称本是酒中仙。\n"NOR; 
	        else if (per > 15) str=HIG"他面如冠玉，长身如龙，精神矍铄，一望便知是得道仙人。\n"NOR; 
	        else str=HIG"他道袍邋遢，形容猥琐，像极了那招摇撞骗的茅山道士。\n"NOR; 
        	}
      	else
          {
	        if (per >20) str= HIG"他鹤发童颜，红光满面，福似东海长流水，寿比南山不老松。\n"NOR;          
	        else if (per > 18) str=HIG"他目光炯炯，长髯无风自动，尽显长辈威严。\n"NOR;         
	        else if (per > 16) str=HIG"他白眉入鬓，虬髯连胸，顾盼之间还可显出年轻时的几分神韵。\n"NOR;  
	        else if (per > 14) str=HIG"他面容慈和，笑意盈盈，一副心满意足的老人模样。\n"NOR; 
	        else if (per > 12) str=HIG"他一头乱蓬蓬的花白头发，布满皱纹的脸上点缀着暗绿色的斑痕，称得上是行将就木，风烛残年。\n"NOR; 
	        else if (per > 10) str=HIG"他鸡皮鹤发，双颧突出，眼中半点精光也无，显见得是两条腿都已经迈进棺材了。\n"NOR;         	
	        else str=HIG"他眼窝深陷，面如枯骨，如是躺在路边，十足一个荒年的饿殍。\n"NOR;         	
         }
        }
      else if (gender=="女性")
        {
        	if (bty>=500)
        	{
        		switch (random(5))
        		{
        			case 0 : str="她乍看去有三十许的风情，仔细瞧又像二十岁的美貌，再端详又是十六七岁的清新，你难以想象这跨越时空的美在同一张脸展现。\n"NOR;break;
        			case 1 : str="她肌肤胜雪，长发如云，风采鲜艳夺目，便似一朵娇花在最盛时永驻了它那璀璨的容颜。\n"NOR;break;
        			case 2 : str="岁月并非是一把公平的快刀，它将这张脸雕琢得如此精致美丽，却将余下那本该衰老的光阴一挥斩去了。\n"NOR;break;
        			case 3 : str="你心口突地一热，似有什么热浪翻了上来，霎时脑中一片空白，只道：我死了！我死了！世上怎有如此美丽的女人？\n"NOR;break;
        			default: str="她的容貌也并没有什么特别，既不是艳冠京华，也不是风姿绝代，只不过，这是一张永远充满青春、充满活力的十八岁的脸。\n"NOR;break;
        		}             			
        	}
        	else 
        	{
		        if (per >23) str= HIG"娴静有如花照水，行动好比风拂柳。便是宋子渊再生，顾长康返世，亦难以描绘她那绝世容颜。\n"NOR;          
		        else if (per > 22) str=HIG"这张脸可以让你忘记她的年龄，忘记你自己的年龄，忘记所有的一切。即便是一根朽木也会毫不犹豫地疯狂地爱上她。\n"NOR;         
		        else if (per > 21) str=HIG"她冰肌玉骨，眉目难画，风姿绰约，早也不是凡间人物。\n"NOR;  
		        else if (per > 20) str=HIG"她的眉毛弯弯似弯月，她的眼儿闪闪如明星，上天真是眷顾你，让你见到了这样一张绝美的脸。\n"NOR; 
		        else if (per > 19) str=HIG"几丝鱼尾纹反而增添她说不出的亲和力，举手投足间尽可见到她年轻时的风采。\n"NOR; 
		        else if (per > 18) str=HIG"她的眼神依旧蕴藏着成熟女人的风情，年华并没有从她本已经不太年轻的脸上流逝，她依然有足够的魅力。\n"NOR;         	
		        else if (per > 17) str=HIG"她的容貌似乎并没有受到岁月的太多影响，肤色仍然白皙，容颜依旧秀丽。\n"NOR; 
		        else if (per > 16) str=HIG"她脸上已经布满了皱纹，眼神也失去了风采，好在整个人精神还算不错。\n"NOR; 
		        else if (per > 15) str=HIG"她的相貌让你想起你少年时的外婆，每个人都曾有一个这样慈祥、温暖、和蔼可亲的外婆吧？\n"NOR; 
		        else if (per > 14) str=HIG"这样平常的一位老人家，坐在人群里你绝不会认出她。\n"NOR; 	  
		        else if (per > 13) str=HIG"一个普普通通的老妇人，她的相貌很容易让人忘记。\n"NOR; 	  
		        else if (per > 12) str=HIG"她几颗桀骜的暴牙黑黑黄黄地从两片灰白的嘴唇中伸出，脸上的蜡黄皱纹比头发还要密集得多。\n"NOR;   
		        else if (per > 11) str=HIG"一堆一堆的肥肉淹没了她也许曾经玲珑的身材，这样的脂肪一看就是至少积攒了八九十年了。\n"NOR; 
		        else               str=HIG"一具骷髅顶着花白的头发，这幅模样白天也可吓人个半死。\n"NOR;           			
        	}
        }
        else 
        {
	        if (per >20) str= HIG"他有着薄薄的嘴唇，细细的眉毛，挺直的鼻梁，只有眼中偶尔闪过的一丝光芒透露出冷酷和残忍。\n"NOR;                 
	        else if (per > 18) str=HIG"他雪白的眉毛根根倒立，深陷的眼珠暗藏精光，一个大大的鹰钩鼻显出他阴鸷狠鲁的性格。\n"NOR;  
	        else if (per > 16) str=HIG"他对生活已经没有兴趣，一双死灰眼睛的眼睛空洞、漠然，便如一尊石像从上方俯视着苍生。\n"NOR; 
	        else if (per > 14) str=HIG"他头发乱蓬蓬地，眉毛乱蓬蓬地，五官乱蓬蓬地，只有一张下巴，干干净净，半根毛也没有。\n"NOR; 
	        else if (per > 12) str=HIG"他干瘪的嘴唇深深地凹进了牙床，瘦削的颧骨实他整个面部嶙峋地突出，暗淡的眼神里没有丝毫男性的风采。\n"NOR;         	
	        else str=HIG"老而不死，是以为妖。一个又老又丑的死人妖，这幅模样，你自己想罢。\n"NOR;          	
        }      	
    }
    else {    	
        if (gender == "男性") 
        {
	        if (per >39) str= HIG"他现在一派神人气度，仙风道骨，举止出尘。\n";
	        else if (per > 38) str=HIG"他现在神清气爽，骨格清奇，宛若仙人。\n";
	        else if (per > 37) str=HIG"他现在丰神俊朗，长身玉立，宛如玉树临风。\n"NOR;
	        else if (per > 36) str=HIG"他现在飘逸出尘，潇洒绝伦。\n"NOR;
	        else if (per > 35) str=HIG"他现在面如美玉，粉妆玉琢，俊美不凡。\n"NOR;
	        else if (per > 34) str=HIG"他现在丰神如玉，目似朗星，令人过目难忘。\n"NOR;
	        else if (per > 33) str=HIY"他现在粉面朱唇，身姿俊俏，举止风流无限。\n"NOR;
	        else if (per > 32) str=HIY"他现在双目如星，眉梢传情，所见者无不为之心动。\n"NOR;
	        else if (per > 31) str=HIY"他现在举动如行云游水，独蕴风情，吸引所有异性目光。\n"NOR;
	        else if (per > 30) str=HIY"他现在双眼光华莹润，透出摄人心魄的光芒。\n"NOR;
	        else if (per > 29) str=HIY"他生得英俊潇洒，风流倜傥。\n"NOR;
	        else if (per > 28) str=MAG"他生得目似点漆，高大挺俊，令人心动。\n"NOR;
	        else if (per > 27) str=MAG"他生得面若秋月，儒雅斯文，举止适度。\n"NOR;
	        else if (per > 26) str=MAG"他生得剑眉星目，英姿勃勃，仪表不凡。\n"NOR;
	        else if (per > 25) str=MAG"他生得满面浓髯，环眼豹鼻，威风凛凛，让人倾倒。\n"NOR;
	        else if (per > 24) str=MAG"他生得眉如双剑，眼如明星，英挺出众。\n"NOR;
	        else if (per > 23) str=CYN"他生得虎背熊腰，壮健有力，英姿勃发。\n"NOR;
	        else if (per > 22) str=CYN"他生得肤色白皙，红唇墨发，斯文有礼。\n"NOR;
	        else if (per > 21) str=CYN"他生得浓眉大眼，高大挺拔，气宇轩昂。\n"NOR;
	        else if (per > 20) str=CYN"他生得鼻直口方，线条分明，显出刚毅性格。\n"NOR;
	        else if (per > 19) str=CYN"他生得眉目清秀，端正大方，一表人才。\n"NOR;
	        else if (per > 18) str=YEL"他生得腰圆背厚，面阔口方，骨格不凡。\n"NOR;
	        else if (per > 17) str=YEL"他生得相貌平平，不会给人留下什么印相。\n"NOR;
	        else if (per > 16) str=YEL"他生得膀大腰圆，满脸横肉，恶形恶相。\n"NOR;
	        else if (per > 15) str=YEL"他生得獐头鼠须，让人一看就不生好感。\n"NOR;
	        else if (per > 14) str=YEL"他生得面颊深陷，瘦如枯骨，让人要发恶梦。\n"NOR;
	        else if (per > 13) str=RED"他生得肥头大耳，腹圆如鼓，手脚短粗，令人发笑。\n"NOR;
	        else if (per > 12) str=RED"他生得贼眉鼠眼，身高三尺，宛若猴状。\n"NOR;
	        else if (per > 11) str=RED"他生得面如桔皮，头肿如猪，让人不想再看第二眼。\n"NOR;
	        else if (per > 10) str=RED"他生得呲牙咧嘴，奇丑无比。\n"NOR;
	        else str=RED"他生得眉歪眼斜，瘌头癣脚，不象人样。\n"NOR;
        }
        else if (gender == "无性") 
        {
	        if (per >20) str=HIG"他长身玉立，风流倜傥，龙行虎步中不失娇柔温婉，阳刚之力与阴柔之美竟然在同一人身上尽情展现。\n他的笑容蕴藏着一种很怪的魅力，让你觉得他似乎是你的兄弟那样令人放心，又像你的姐妹那般容易亲近。\n他沉静地望着你，你也沉静地望着他，似乎你们已经相识多年，只是太久不曾相见。\n"NOR;  
	        else if (per > 16) str=HIG"他珠圆玉润，恬静中带着慵懒，虽有七尺身高，却好像一位未出阁的大姑娘。\n"NOR; 
	        else if (per > 14) str=HIG"他他肥胖得胸前堆了三个下巴，整张面皮干净得像一张烙饼。\n"NOR; 
	        else if (per > 10) str=HIG"他秃秃的眉骨，秃秃的下巴，突突的脑袋，便连头顶也是秃秃的，仿佛这人全身上下没有一个地方是长毛的。\n"NOR;         	
	        else str=HIG"他眼神闪闪缩缩地不敢看人，佝偻的身躯总是下意识地把俩腿夹紧。\n"NOR;         	
        }
        else
        {
	        if (per >39) str =HIW"她现在宛如玉雕冰塑，似梦似幻，已不再是凡间人物\n"NOR;
	        else if (per > 38)  str =HIG"她现在美若天仙，不沾一丝烟尘。\n"NOR;
	        else if (per > 37)  str =HIG"她现在灿若明霞，宝润如玉，恍如神妃仙子。\n"NOR;
	        else if (per > 36)  str =HIG"她现在气质美如兰，才华馥比山，令人见之忘俗。\n"NOR;
	        else if (per > 35)  str =HIG"她现在丰润嫩白，婴桃小口，眉目含情，仿佛太真重临。\n"NOR;
	        else if (per > 34)  str =HIG"她现在鲜艳妩媚，袅娜风流，柔媚姣俏，粉光脂艳。\n"NOR;
	        else if (per > 33)  str =HIY"她现在鬓若刀裁，眉如墨画，面如桃瓣，目若秋波。\n"NOR;
	        else if (per > 32)  str =HIY"她现在凤眼柳眉，粉面含春，丹唇贝齿，转盼多情。\n"NOR;
	        else if (per > 31)  str =HIY"她现在眉目如画，肌肤胜雪，真可谓闭月羞花。\n"NOR;
	        else if (per > 30)  str =HIY"她现在娇若春花，媚如秋月，真的能沉鱼落雁。。\n"NOR;
	        else if (per > 29)  str =HIY"她生得闲静如姣花照水，行动似弱柳扶风，体态万千。\n"NOR;
	        else if (per > 28)  str =MAG"她生得娇小玲珑，宛如飞燕再世，楚楚动人。\n"NOR;
	        else if (per > 27)  str =MAG"她生得鸭蛋秀脸，俊眼修眉，黑发如瀑，风情万种。\n"NOR;
	        else if (per > 26)  str =MAG"她生得削肩细腰，身材苗条，娇媚动人，顾盼神飞。\n"NOR;
	        else if (per > 25)  str =MAG"她生得丰胸细腰，妖娆多姿，让人一看就心跳不已。\n";
	        else if (per > 24)  str =MAG"她生得粉嫩白至，如芍药笼烟，雾里看花。\n"NOR;
	        else if (per > 23)  str =CYN"她生得腮凝新荔，目若秋水，千娇百媚。\n"NOR;
	        else if (per > 22)  str =CYN"她生得鲜艳妍媚，肌肤莹透，引人遐思。\n"NOR;
	        else if (per > 21)  str =CYN"她生得巧笑嫣然，宛约可人。\n"NOR;
	        else if (per > 20)  str =CYN"她生得如梨花带露，清新秀丽。\n"NOR;
	        else if (per > 19)  str =CYN"她生得风姿楚楚，明丽动人。\n"NOR;
	        else if (per > 18)  str =YEL"她生得肌肤微丰，雅淡温宛，清新可人。\n"NOR;
	        else if (per > 17)  str =YEL"她生得虽不标致，倒也白净，有些动人之处。\n"NOR;
	        else if (per > 16)  str =YEL"她生得身材瘦小，肌肤无光，两眼无神。\n"NOR;
	        else if (per > 15)  str =YEL"她生得干黄枯瘦，脸色腊黄，毫无女人味。\n"NOR;
	        else if (per > 14)  str =YEL"她生得满脸疙瘩，皮色粗黑，丑陋不堪。\n"NOR;
	        else if (per > 13)  str =RED"她生得一嘴大暴牙，让人一看就没好感。\n"NOR;
	        else if (per > 12)  str =RED"她生得眼小如豆，眉毛稀疏，手如猴爪，不成人样。\n"NOR;
	        else if (per > 11)  str =RED"她生得八字眉，三角眼，鸡皮黄发，让人一见就想吐。\n"NOR;
	        else if (per > 10)  str =RED"她生得歪鼻斜眼，脸色灰败，直如鬼怪一般。\n"NOR;
	        else str =RED"她生得丑如无盐，状如夜叉，女人长成这样真是人生悲剧。\n"NOR;
        }
    }
	if (obj->query("level")>=80)
	{
		pro = (obj==me) ? gender_self(gender) : gender_pronoun(gender);
		if (obj->query("level")>=120)
			str +=WHT+pro+"的周身笼罩着一层淡淡温润的光彩，正是功力已臻化境之态。\n"+NOR;
		else if (obj->query("level")>=100)
			str +=HIC+pro+"的功力逼近巅峰，挥洒之间全不着任何痕迹。\n"+NOR;
		else
			str +=HIG+pro+"的眼中神采四射，正是功力融会贯通之兆。\n"+NOR;
	}
    if(wizardp(obj)) str = HIY"他身上似乎朦朦胧胧的有一层金光，天哪，那是神！\n"NOR; //wiz保证最好看，嘿嘿 by whuan@pkuxkx
    return str;
}

void give_found_region_reward(object pl,object room)
{
    string* parts;
    string dir_name;
    int exp,pot;
    string region_name;

    parts = explode(base_name(room),"/");
    if(sizeof(parts) > 2)
    {
        dir_name = "/"+parts[0]+"/"+parts[1]+"/";
    }        

    region_name = TASK_D->place_belong(room);
    if(region_name != "不明区域" && region_name != "未知区域")
    {
		if(!pl->query("found_region/"+dir_name) && time() - pl->query("found_region/last_time") > (random(600) + 5))
        {
            tell_object(pl,HIY"你发现了"+region_name+"\n"NOR);
            pot = 1000+random(1000);
            pot = REWARD_D->add_pot(pl,pot);
            tell_object(pl,"你的潜能增加了"+chinese_number(pot)+"点！\n");
            if(random(30) == 5 && !pl->query("env/no_int_add") && pl->query("xiantian/int/map") < 3)
            {
				if (region_name!="扬州")
				{
					tell_object(pl,"你的悟性增加了！\n");
					pl->add("int",1);
					pl->add("xiantian/int/map",1); 
					log_file("user/lookint",pl->query("id")+"于:"+region_name+"地图加了悟性点。\n");				
				}
            }
            pl->set("found_region/"+dir_name,1);
            if(pl->query("antirobot/deactivity") > 1)
            {
                tell_object(pl,HIR"你该fullme了，否则奖励减少啊！\n"NOR);
            }
			pl->set("found_region/last_time",time());
        }
    }    
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



