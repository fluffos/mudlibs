//Cracked by Kafei
// natured.c
// Last modification: Marz added automatically save on 08/27/96
// Cyz added time sychronizition (if it doesnt work, hmm, so be it)
// Fixed natured stuck problem also added garbage cleanup fucntion, sdong, 12/3/99
#include <ansi.h>
#define TIME_TICK (time()*60)
#define TIME_TICK1 (time()*60-890000000)
static int current_day_phase;
mapping *day_phase;

string *weather_msg = ({
	"天空中万里无云",
	"几朵淡淡的云彩妆点著清朗的天空",
	"白云在天空中飘来飘去",
	"厚厚的云层堆积在天边",
	"天空中乌云密布",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
	day_phase = read_table("/adm/etc/nature/day_phase");
	init_day_phase();
}

void init_day_phase()
{
	mixed *local;
	int i, t;

	// Get minutes of today.
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];		// hour * 60 + minutes

	// Find the day phase for now.
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else
			break;

	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

	// Since in our time scale, 1 minute == 1 second in RL, so we don't need
	// any conversion before using this number as call_out dalay, if you 
	// changed the time scale, be sure to convert it.

	call_out("update_day_phase",
		(int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	int synchronize = 0;
	
	remove_call_out("update_day_phase");
	
	if(current_day_phase==0)
	{
       		init_day_phase();
       		synchronize = 1;
   	}

	current_day_phase = (++current_day_phase) % sizeof(day_phase);

        if(! synchronize)
        call_out("update_day_phase", day_phase[current_day_phase]["length"]);

	message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
	if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
		call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

	this_object()->event_common();

}

// This is called everyday noon by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase

// save player data automatically at sunrise
void event_sunrise()
{
/*	object link_ob, *ob;
	int i;

	ob = users();
	for(i=0; i<sizeof(ob); i++) 
	if( objectp(link_ob = ob[i]->query_temp("link_ob")) )
	{
		link_ob->save();
		ob[i]->save();
	}
*/
	//"/u/ryu/mudlist"->main();
}

// check player inventory at turning points of events.
void event_common()
{
	int i, count;
	object *ob;
        object where;
        
	ob=livings();
        i = sizeof(ob);
        while (i--) {
        if(!ob[i]||!objectp(ob[i]))continue;
        where=environment(ob[i]);
        if(!where||!objectp(where)){

        /*
               write(sprintf("Delete %s(%s) for having no environment.\n",ob[i]
->query("id"),file_name(ob[i]) ) );
        */

        if(!userp(ob[i]))destruct(ob[i]);
                else ob[i]->move("/d/city/wumiao.c");
                continue;

        }

        /*
        write(sprintf("%s(%s,%s) in %s(%s)\n",ob[i]->query("name"),ob[i]->query(
"id"),file_name(ob[i]),where->query("short"),file_name(where)
        ));
        */

        }

	ob = users();
//	count = 1+random(sizeof(ob));
	count = sizeof(ob);
	i = random(sizeof(ob));
	
	while (count-- > 0) {
		if( environment(ob[i]) )
		  UPDATE_D->inventory_check(ob[i]);
		i = (i+1) % sizeof(ob);
	}
}

void event_night()
{
	object badguy;
	object room;
        if (random(6) == 1)
        {
		if(objectp(room=load_object("/d/city/guangchang")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "扬州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
    /*    if (random(8) == 2)
        {
		if(objectp(room=load_object("/d/beijing/changanjie")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "北京城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
      */  if (random(6) == 2)
        {
		if(objectp(room=load_object("/d/qilian/lanzhou")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "兰州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(6) == 3)
        {
		if(objectp(room=load_object("/d/dali/dalicheng9")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "大理城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(6) == 4)
        {
		if(objectp(room=load_object("/d/foshan/street2")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "佛山城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
 /*    　  if (random(6) == 6)
        {
		if(objectp(room=load_object("/d/hangzhou/road24")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "杭州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
   */     if (random(6) == 5)
        {
		if(objectp(room=load_object("/d/xixia/center")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "灵州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
        if (random(6) == 6)
        {
		if(objectp(room=load_object("/d/quanzhou/zhongxin")) && 
		objectp(badguy = new("/quest/feizei/feizei")))
		badguy->move(room);
  message("channel:chat", HIW"【官府通告】"HIR + "泉州城中今夜有飞贼横行，良民百姓请闭门不出，切莫自误！\n"NOR,users() );
	}
     

}

void event_dawn()
{
	object *ob_list;
	int i;
	ob_list = children("/quest/feizei/feizei");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
			message_vision("$N笑道：天亮了，东西也到手了，我闪！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}

void event_noon()
{
        object *ob;
        int i, skill,con,con1,con2,con3;
        string get_month,ill,msg;
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                case "三":
                case "四":
                case "五":
                     ill = "ill_kesou";
                     msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
                     break;
                case "六":
                case "七":
                case "八":
                     ill = "ill_zhongshu";
                     msg = HIG+"突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
                     break;
                case "九":
                case "十":
                case "十一":
                     ill = "ill_shanghan";
                     msg = HIG+"陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n"+NOR;
                     break;
                case "十二":
                case "一":
                case "二":
                     ill = "ill_dongshang";
                     msg = HIG+"你肢体末端一阵僵直，看来你被冻伤了。\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"你偶感风寒，竟而发起烧来。\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
                if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("qi");
                con2 = ob[i]->query("max_qi");
                (int)con = con1/con2*50;//形成第一个生病判断条件
                con3 = ob[i]->query("neili");
                con2 = ob[i]->query("max_neili");
		if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;//形成第二个生病判断条件
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "。\n";
}

string outdoor_room_event()
{
        return day_phase[current_day_phase]["event_fun"];
}

string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
}

// This function is to read a regular type of data table for day_phase and
// etc.
mapping *read_table(string file)
{
	string *line, *field, *format;
	mapping *data;
	int i, rn, fn;

	line = explode(read_file(file), "\n");
	data = ({});
	for(i=0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !pointerp(field) ) {
			field = explode( line[i], ":" );
			continue;
		}
		if( !pointerp(format) ) {
			format = explode( line[i], ":" );
			continue;
		}
		break;
	}

	for( rn = 0, fn = 0; i<sizeof(line); i++) {
		if( line[i]=="" || line[i][0]=='#' ) continue;
		if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
		sscanf( line[i], format[fn], data[rn][field[fn]] );
		fn = (++fn) % sizeof(field);
		if( !fn ) ++rn;
	}
	return data;
}


mapping *query_day_phase() { return day_phase; }
