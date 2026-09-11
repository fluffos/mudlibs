// newslady.c
// edited by xiaobai, 17th Aug. 2001 
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>
#include <sanguo.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit CHINESE_DA;
inherit M_ANSI;

#define VERSION_NUM 0123082001
#define CALLOUT_LIMIT   300

private *name_list=({ });
private int is_on;  // 是否自动发布消息
private string p_city = "";  // 用户所选定的城市 id
private string p_user = "";  // 用户
private int p_nCntCallout = 0;

// functions for unser interactive
void no_answer();
void setcity( string par_str );
void answer_warcity( object who );
void answer_begin();
void answer_end();

// functions for showing war info
void show_warinfo();
string get_pos(int t);
string get_action(int t);
string get_btype(int t);

// function for warmap
void show_warmap();

void setcity( string par_str )
{
    object o;
    
    p_city = par_str;
    
    this_object()->simple_action( "当前地区为 " + p_city + "。\n" );
    o=find_user(p_user);
    
    if(objectp(o))
            o->modal_pop();
    p_user = "";
    
    answer_begin();
}

void answer_warcity( object who )
{
    mapping p_tasks = TASK_D->query_tasks();
    int* list = keys( p_tasks );
    int i = 0;
    int p_num = 0;
    int p_taskid = 0;
    int p_cnt = 0;
    
    string p_id=who->query_id()[0];
    object o;

    p_num = sizeof(list);
    
    p_city = "";
        
    if ( p_num > 0 )
    {
	    foreach( p_taskid in list )
	    {
		    if( p_tasks[p_taskid]["type"] == TT_WAR )
		    {
		        p_cnt++;
		        
		        if ( p_city == "" )
		        {
                    this_object()->simple_action( "$N说到\n以下地区处于战争中：\n" );
		            p_city = p_tasks[list[i]]["area"];
		        }
		        		        
    	        write( "( task id: " + p_taskid + " ) " );
		        write( p_tasks[p_taskid]["area"] + "\n" );
		    }
	    }
	}
	
	if ( p_cnt > 0 )
	{
        this_object()->targetted_action("$N对$T道：$m对哪个地区感兴趣。\n",who);
        p_user = p_id;
        o=find_user(p_id);
        if(!objectp(o)) {no_answer(); return;}
        tell_user(p_id,"请输入地区的ID\n");
        o->modal_push((: setcity :),"地区：");
        call_out("no_answer",60);
    }
    else
    {
        this_object()->simple_action( "$N说到：目前没有处于战争状态的城市。\n" );
    }
    
}

void no_answer()
{
        object o;
        remove_call_out("no_answer");
        this_object()->simpl_action("$N不耐烦地道：哼！怎么不理人家了。\n");
        o=find_user(p_user);
        if(objectp(o))
                o->modal_pop();
        p_user = "";
}

string *query_channel_list() {
    return ({ "plyr_gossip" });
}

void answer_begin()
{
    if ( p_city == "" )
    {
	    this_object()->simple_action( "$N说到“请先选择一个城市。”" );
	    return;
    }
    else
    {
        if ( !is_on )
        {
            is_on = 1;
        	this_object()->simple_action( "$N说到“开始广播”" );
        	
        	write( "当前城市：" + p_city + "\n" );

            p_nCntCallout = 0;
    //        show_warinfo();
            show_warmap();
        }
        
    }
    
}

void answer_end()
{
    is_on = 0;
	this_object()->simple_action( "$N说到“停止广播”" );
    remove_call_out("show_warmap");  
}

void show_warinfo()
{
    string disp;
    int t_id;
    int* t_task;
    string m_side;
    int *tf,*te;
	string *def_party;

    object o;
    string p_name,id;
    string tmp;
    string c_id,c_name;
    int b_num;

    int can_see;

    string strMap;  // warmap

    if ( !is_on || p_city == "" )
        return;
   
    //
    t_id = TASK_D->get_area_task_id( p_city );
    
    if ( t_id <= 0 )
    {
        write( "战争结束了。\n" );
        
        answer_end();
        
        return;
    }
        
    write( "\n" + p_city + "的战争信息：" + " ( task id " + t_id + " )\n\n" );
	def_party=TASK_D->get_task(t_id,"def_party");
    
    // friend troop    
    tf=TASK_D->get_task(t_id,"att_army");
    // enemy troop
    te=TASK_D->get_task(t_id,"def_army");

    disp=
"攻方部队　　　　　代号     主将　　 大将数　兵数　 兵种    位置　状态\n";
    disp+=
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
    if(sizeof(tf))
    {
        // loop for each troop in the att_army
    	foreach(int t in tf)
    	{
           o=TROOP_D->find_troop(t);
           if(!o || !objectp(o))
            continue;
           p_name=TROOP_D->get_troops(t,"name");
           id=o->query_id()[0];
           c_id=TROOP_D->get_troops(t,"chars")[0];  // troop leader id
           c_name=CHAR_D->get_char(c_id,"name");
           b_num=TROOP_D->get_troops(t,"total_num");
           tmp=sprintf("%-18s%-9s%-8s %-8d%-7d%-9s%-6s%s\n"
            ,p_name,id,c_name,
            sizeof(TROOP_D->get_troops(t,"chars")),
            b_num,get_btype(t),get_pos(t),
            get_action(t));
           disp+=tmp;
        }
    }
    disp+=
"守方部队　　　　　代号     主将　　 大将数　兵数　 兵种    位置　状态\n";
    disp+=
"〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n";
    if(sizeof(te))
    {
    	foreach(int t in te)
    	{
           o=TROOP_D->find_troop(t);
           if(!objectp(o)) continue;
           p_name=TROOP_D->get_troops(t,"name");
           id=o->query_id()[0];
           c_id=TROOP_D->get_troops(t,"chars")[0];
           c_name=CHAR_D->get_char(c_id,"name");
           b_num=TROOP_D->get_troops(t,"total_num");
           tmp=sprintf("%-18s%-9s%-8s %-8d%-7d%-9s%-6s%s\n"
            ,p_name,id,c_name,
            sizeof(TROOP_D->get_troops(t,"chars")),
            b_num,get_btype(t),get_pos(t),
            get_action(t));
           disp+=tmp;
        }
    }
    
    disp += "\n\n";

    write( disp );       

    ////
        
    call_out( "show_warinfo", 10 );
  
}

string get_btype(int t)
{
   mixed mtmp;
   string ret="";
   mtmp=TROOP_D->get_troops(t,"soldier");
   mtmp=keys(mtmp);
   if(!sizeof(mtmp)) return "";
   foreach(string tp in mtmp)
   {
     string bt;
     bt=WARAI_D->get_soldier(tp,"name");
     bt=colour_truncate(bt,4);
     ret+=bt[0..1];
   }
   return ret;
}

string get_action(int t)
{
   mixed cmd;
   string chars;
   chars=TROOP_D->get_troops(t,"chars");
   foreach(string c in chars)
   {
      if(CHAR_D->get_char(c,"status")==STATUS_ONLINE)
            return "人控";
   }
   cmd=TROOP_D->get_troops(t,"command");
   if(!cmd) return "待命";
   if(!cmd["action"]) return "待命";
   switch(cmd["action"])
   {
      case "match": return "行军";
      case "guard": return "防守";
      case "pursue": return "追击";
      default : return "待命";
   }

}

string get_pos(int t)
{
   int* pos;
   string ps="ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ";
   string ret="";
   pos=TROOP_D->get_troops(t,"position");
   ret=ps[pos[0]*2..pos[0]*2+1];
   ret+=sprintf("%d",pos[1]+1);
   return ret;
}

void show_warmap()
{
    int i,j,k;  // counter
    int p_nTroopNum = 0;
    int width,height;  // size of the map
    string disp;  // the whole war map string
    string strInfo;  // the troop info of the map line
    string bar;  // 
    mixed troops;
    string s_tmp;
    string p_bar="　　ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ";
    
    mixed map_data;

    int t_id;  // the war task id

    // properties of a troop
    int tr_nId;
    string tr_strPos;  // troop position
    string tr_strLeaderId;  // id of the troop's first leader
    string tr_strLeaderName;  // chinese name of the troop's first leader
    string tr_strType;  // chinese type name of the troop
    int tr_nSoldierNum;  // soldier number of the troop

    string l_n;

    remove_call_out( "show_warmap" );
    
    p_nCntCallout++;
    
    if ( !is_on || p_city == "" || ( p_nCntCallout > CALLOUT_LIMIT ) )
    {
        answer_end();
        return;
    }

    t_id = TASK_D->get_area_task_id( p_city );
    
    if ( t_id <= 0 )
    {
        write( "战争结束了。\n" );
        
        answer_end();
        
        return;
    }
    
    map_data = MAP_D->get_city( p_city, "" );
   
    if( !AREA_D->area_exist(p_city) || !map_data )
        return;

    disp="";

    height = MAP_D->get_city( p_city, "height" );
    width = MAP_D->get_city( p_city, "width" );;
    bar="";   

    for(i=0;i<width;++i)
    {
        bar+="━";
    }
    
    if( !AREA_D->get_area(p_city,"name") ) 
        disp+="地区地形图。\n";
    else 
    	disp+=AREA_D->get_area(p_city,"name")+"地区地形图。\n";
    	
    p_bar=p_bar[0..3+2*width]+"\n";
    disp+=p_bar;
    disp+="  ┏"+bar+"┓\n";
        	
    for(i=0;i<height;++i)
    {
        strInfo = "";
          
        l_n=sprintf("%2d",i+1);
        disp+=l_n+"┃";

        for(j=0;j<width;++j)
        {     
            troops = map_data[i][j]["t"];
            
            if( sizeof(troops) )
            // show both sides
            {
                foreach( int t in troops )
                {
                    tr_nId = t;
                    tr_strLeaderId = TROOP_D->get_troops( t, "chars" )[0];
                    tr_strLeaderName = CHAR_D->get_char( tr_strLeaderId, "name" );
                    tr_nSoldierNum = TROOP_D->get_troops( t, "total_num" );
                    tr_strPos = get_pos( t );  // troop position
                    tr_strType = get_btype( t );  // chinese type name of the troop
                    
                    strInfo += " |(" + tr_nId + ")" + tr_strLeaderName + " " + tr_strType +
                        tr_nSoldierNum + " " + tr_strPos;
                    
                    tr_strLeaderName = colour_truncate( tr_strLeaderName, 1 );
                    
                    if( TROOP_D->get_troops( t, "side" ) == "d" )
        	            s_tmp="%^H_BLUE%^" + tr_strLeaderName[0..1];
                    else 
        	            s_tmp="%^H_RED%^" + tr_strLeaderName[0..1];
    	        }
    	        
            }
            else
                s_tmp = MAP_D->get_color(map_data[i][j]["m"])+
                                map_data[i][j]["m"];
            disp+=s_tmp;
        }

        l_n=sprintf("%2d",i+1);
        disp += "%^RESET%^┃" + l_n + strInfo + "\n";
    }

    disp+="  ┗"+bar+"┛\n"+p_bar;
    disp+=
    "平地：．  水：～  山地：∧   草地：＊  
    树林：♂  天险：※ 营帐：◎  自己：Ｍ
    攻方：Ａ  守方：Ｄ 城墙：│└┘┌┐─ 
    \n";

    disp += "\n\n";
    this_object()->simple_action( disp );       
    call_out( "show_warmap", 10 );
    
}  // end write_warmap

void setup()
{
    set_name("news lady", "女播音员");
    set_gender(2);
    set_proper_name("女播音员");
    set_in_room_desc("女播音员(news lady)");
    add_id("lady");
    set_age(20);
    set_sg_rongmao(100);
    set_long("     
      一个二十左右的女士，精明干练，
脸上堆着职业的笑容，表情亲切得有些生硬。
");
	add_question("version", "version");
	add_question("begin", "begin");
	add_question("end", "end");
	add_question("city", "city");
//        add_question("luoyang","luoyang");
    add_pattern( "说道：%s", function(string left, string right){
                 
                 respond("say 恭喜，恭喜！");
});
}

void special_answer(object who, string matt)
{
	switch(matt)
	{
   		case "version" :
        	this_object()->simple_action( "$N说到“版本号：" + VERSION_NUM + "。”" );
			return;
 		case "begin" :
			answer_begin();
			return;
 		case "end" :
            answer_end();
			return;
 		case "city" :
 		    answer_warcity( who );
			return;
			
	}
}
