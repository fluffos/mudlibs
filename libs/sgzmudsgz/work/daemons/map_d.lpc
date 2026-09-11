// map_d.c 
// designed by flee, fire
// this is used to handle the maps for the war
#include <ansi.h>
#include <mudlib.h>
#include <security.h>

#define SAVE_FILE "/data/daemons/warmaps"
#define MAX_LINE_NUM 1000

inherit M_MESSAGES;
inherit M_COMPLETE;
inherit M_ACCESS;
inherit M_ANSI;

int destruct_area(string p_area);
private mapping cities;
nosave private int m_modify;

int is_wall(string p_inp)
{
	switch(p_inp)
	{
	      case "│":
	      case "└":
	      case "┘":
	      case "┌":
	      case "┐":
	      case "─":
	      case "◎":
		return 1;
	      default: 
		return 0;
	}
}
void save_data()
{
        if(m_modify)
                unguarded(1, (: save_object, SAVE_FILE, 1 :));
        remove_call_out("save_data");
        call_out("save_data",240);
        m_modify=0;
        return;
}
void create()
{
        unguarded(1, (: restore_object, SAVE_FILE, 1 :));
        remove_call_out("save_data");
        call_out("save_data",240);
        if(!cities)
        cities=([]);
        return;
}
int delete_city(string city_name)
{
        map_delete(cities, city_name);
        m_modify=1;
        return 1;
}
int add_tmp_city(string name, mixed data)
{
	string *ids;

	ids = keys(cities);
	ids = filter_array(ids, (: strsrch($1, "PLAYER_")!=-1 :));
	if( sizeof(ids)>10 ) return 0;
	cities[name] = data;
	m_modify=1;
	return 1;
}
int add_city(string city_name)
{
        int x, y;
        string line;
        int width;      
        
        string file_name;
       destruct_area(city_name);
        map_delete(cities,city_name);
        
        if(!AREA_D->area_exist(city_name))
                return 0; // no such area so dont need such map at all
        cities[city_name]=({});
                
        file_name=PWARMAP+city_name+".map";
        
        if(file_size(file_name)==-1)
                file_name=PWARMAP+"default.map";
        y=0;
        line=read_file(file_name,y+1,1);
        width=(strlen(line)-1)/2;
        while(strlen(line)>(width*2))
        {
            cities[city_name]+=({ ({}) });
            for(x=0;x<width;++x)
            {
                cities[city_name][y]+=({ ([]) });
                cities[city_name][y][x]["m"]=line[(x*2)..(x*2+1)];
		if(line[(x*2)..(x*2+1)]=="◎")
			AREA_D->set_area(city_name,"center",({x,y}));
            }
            y++;
            line = read_file(file_name, y+1, 1);
        }
        m_modify=1;
        return 1;
}
int city_exist(string city_name)
{
	if(cities[city_name])
		return 1;
	if(!AREA_D->area_exist(city_name))
		return 0;
        add_city(city_name);
	return 1;
}
mixed get_city(string city_name,string para)
{
	if (!city_exist(city_name))
		return 0;
	switch(para)
	{
	case "":
		return cities[city_name];
		case "width":
			return sizeof(cities[city_name][0]);
		case "height":
			return sizeof(cities[city_name]);
	}
	return AREA_D->get_area(city_name,para);
}
string get_color(string p_type)
{
	switch(p_type)
	{
		case "～":
			return "%^H_BLUE%^";
		case "．":
			return "%^H_YELLOW%^";
		case "∧":
			return "%^YELLOW%^";
		case "＊":
			return "%^H_GREEN%^";
		case "♂":
			return "%^GREEN%^";
		case "◎":
			return "%^H_RED%^";
                case "│":
                case "└":
                case "┘":
                case "┌":
                case "┐":
                case "─":
                        return "%^RESET%^%^H_WHITE%^";
		case "※":
			return "%^H_MAGENTA%^";
		default:
			return "%^RESET%^";
	}
}
string get_brief(string p_type)
{
	switch(p_type)
	{
		case "～":
			return "河流";
		case "．":
			return "平原";
		case "∧":
			return "山地";
		case "＊":
			return "草地";
		case "♂":
			return "树林";
		case "◎":
			return "帅营";
		case "│":
		case "└":
		case "┘":
		case "┌":
		case "┐":
		case "─":
			return "城墙";
		case "※":
			return "天险";
		default:
			return "未知";
	}
}
// to preview the city map
// p_type ="a" display the attack view
// p_type ="d" display the defence view
// p_type ="m" display the map only
// p_type ="b" both view
string preview_city(string city_name,string p_type,int mytroop)
{
        int i,j,width,height;
        string disp;
        string bar;
    	mixed troops;
	    string s_tmp;
        
        string tr_strLeaderId;  // troop leader id
        string tr_strLeaderName;  // troop leader name
        int t = 0;  // troop id
        
        string p_bar="　　ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺ";
        if (!city_exist(city_name))
                return "该地区不存在，用listarea列出地区清单．\n";
        disp="";
        
        if(file_size(PWARMAP+city_name+".map")==-1)
                disp="该地区地形图尚未编写，用通用地形图代替。\n";
        height=sizeof(cities[city_name]);
        width=sizeof(cities[city_name][0]);
        bar="";
        for(i=0;i<width;++i)
                bar+="━";
    	if( !AREA_D->get_area(city_name,"name") ) 
    		disp+="地区地形图。\n";
    	else 
        	disp+=AREA_D->get_area(city_name,"name")+"地区地形图。\n";
        p_bar=p_bar[0..3+2*width]+"\n";
        disp+=p_bar;
        disp+="  ┏"+bar+"┓\n";
        for(i=0;i<height;++i)
        {  
           string l_n=sprintf("%2d",i+1);
           disp+=l_n+"┃";
           for(j=0;j<width;++j)
           {       
	      troops=cities[city_name][i][j]["t"];
	      if(sizeof(troops)&&(p_type!="m"))
	      {
        		if(member_array(mytroop,troops)!=-1)
                    s_tmp="%^RED%^Ｍ";
        		else
                {
                    // xiaobai: get the troop leader's name
                    t = troops[0];
                    tr_strLeaderId = TROOP_D->get_troops( t, "chars" )[0];
                    tr_strLeaderName = CHAR_D->get_char( tr_strLeaderId, "name" );
                    tr_strLeaderName = colour_truncate( tr_strLeaderName, 1 );
                    tr_strLeaderName = tr_strLeaderName[0..1];
                    
                    switch(p_type)
            		{
            		  case "a" :
            		     if(TROOP_D->get_troops(troops[0],"side")=="a")
            			    s_tmp="%^H_RED%^" + tr_strLeaderName;
            		     else if(TROOP_D->get_troops(troops[0],"canbeseen"))
            				s_tmp="%^H_BLUE%^" + tr_strLeaderName;
                                 else
            				s_tmp=get_color(cities[city_name][i][j]["m"])+
                                            cities[city_name][i][j]["m"];
            		     break;
            		  case "d":
            		     if(TROOP_D->get_troops(troops[0],"side")=="d")
            			s_tmp="%^H_BLUE%^" + tr_strLeaderName;
            		     else if(TROOP_D->get_troops(troops[0],"canbeseen"))
            				s_tmp="%^H_RED%^" + tr_strLeaderName;
                                 else
            				s_tmp=get_color(cities[city_name][i][j]["m"])+
                                            cities[city_name][i][j]["m"];
            		     break;
            		  default: // here means both
            		     if(TROOP_D->get_troops(troops[0],"side")=="d")
            			s_tmp="%^H_BLUE%^" + tr_strLeaderName;
            		     else 
            			s_tmp="%^H_RED%^" + tr_strLeaderName;
            		     break;
            		}
            	}
            	
            	disp+=s_tmp;

	      }
	      else
                 disp+=get_color(cities[city_name][i][j]["m"])+
                                cities[city_name][i][j]["m"];
           }
                l_n=sprintf("%d",i+1);
                disp+="%^RESET%^┃"+l_n+"\n";
        }
        disp+="  ┗"+bar+"┛\n"+p_bar;
        disp+=
"平地：．  水：～  山地：∧   草地：＊  
树林：♂  天险：※ 营帐：◎  自己：Ｍ
攻方：Ａ  守方：Ｄ 城墙：│└┘┌┐─ 
\n";
        return disp;
}
int get_attack_rate(string p_type)
{
  switch(p_type)
  {
    case "～": return 2;
    case "．": return 5;
    case "∧": return 7;
    case "＊": return 4;
    case "♂": return 3;
    default :  return 7;
  }
}
int get_defence_rate(string p_type)
{
  switch(p_type)
  {
    case "～": return 2;
    case "．": return 5;
    case "∧": return 4;
    case "＊": return 6;
    case "♂": return 7;
    default :  return 7;
  }
}
// this is get what in that cell
mixed get_map_cell(string city_name, int y, int x,string what)
{
	if (!city_exist(city_name))
                return 0;
        if( y >= sizeof( cities[city_name]) || y < 0)
                return 0;
        if( x >= sizeof( cities[city_name][0]) || x < 0)
                return 0;
        if(!what || what=="")
                return cities[city_name][y][x];
	switch(what)
	{
		case "attack_rate":
			return get_attack_rate(cities[city_name][y][x]["m"]);
		case "defence_rate":
			return get_defence_rate(cities[city_name][y][x]["m"]);
	}
        if(!cities[city_name][y][x][what])
                return 0;
        return cities[city_name][y][x][what];
}
void set_map_cell_subtroop(string p_area, int y,int x,int p_id)
{
	mixed p_t;
	p_t=get_map_cell(p_area, y,x,"t");
	if(!p_t)
		p_t=({});
	p_t-=({p_id});
	cities[p_area][y][x]["t"]=p_t;
}
void set_map_cell_addtroop(string p_area, int y,int x,int p_id)
{
	mixed p_t;
	p_t=get_map_cell(p_area,y,x,"t");
	if(!p_t)
		p_t=({});
	p_t-=({p_id});
	p_t+=({p_id});
	cities[p_area][y][x]["t"]=p_t;
}
int set_map_cell(string city_name, int y, int x,string what,mixed val)
{
	if (!city_exist(city_name))
                return 0;
        if( y >= sizeof( cities[city_name]) || y < 0)
                return 0;
        if( x >= sizeof( cities[city_name][0]) || x < 0)
                return 0;
		switch(what)
		{ case "addtroop":
				set_map_cell_addtroop(city_name, y,x,val);
				break;
		case "subtroop":
				set_map_cell_subtroop(city_name, y,x,val);
				break;
		default:
			cities[city_name][y][x][what]=val;
		}
 
        m_modify=1;
        return 1;
}
string* list_city()
{
        return keys(cities);
}
void clear_all()
{
        cities=([]);
        m_modify=1;
}
string* get_long(string p_type,string pos)
{
  int i,j;
  string *ret,*tmp;
  string f_name;
  string p_color;
  mapping m = (["│":"ns","└":"sw","┘":"se","┌":"nw","┐":"ne","─":"we","◎":"shuai"]);
  p_color=get_color(p_type);
  tmp=({"","","",""});
  switch(p_type)
  {
    case "～":
    case "．":
    case "∧":
    case "＊":
    case "♂":
    case "※":
      for(i=0;i<4;++i)
      {
          for(j=0;j<8;++j)
	    if(random(3))
		tmp[i]+="  ";
	    else
		tmp[i]+=p_type;
      }
      break;
      case "│":
      case "└":
      case "┘":
      case "┌":
      case "┐":
      case "─":
      case "◎":
        f_name=PPIC+"wall"+m[p_type]+".pic";
	for(i=0;i<4;++i)
	{
                tmp[i]=read_file(f_name,i+1,1); 
                tmp[i]=tmp[i][0..15];
	}
        break;
      default:
        f_name=PPIC+"void.pic";
        for(i=0;i<4;++i)
	{
                tmp[i]=read_file(f_name,i+1,1); 
                tmp[i]=tmp[i][0..15];
	}
    }
	switch(pos)
	{
		case "c" : ret=tmp; break;
                case "nw" : ret=({tmp[0][0..7], tmp[1][0..7]});break;
		case "n" : ret=({tmp[0],tmp[1]});break;
                case "ne" : ret=({tmp[0][8..15], tmp[1][8..15]});break;
                case "w" :
ret=({tmp[0][0..7],tmp[1][0..7],tmp[2][0..7],tmp[3][0..7]});break;
                case "e" :
ret=({tmp[0][8..15],tmp[1][8..15],tmp[2][8..15],tmp[3][8..15]});break;
                case "sw" : ret=({tmp[2][0..7],tmp[3][0..7]});break;
		case "s" : ret=({tmp[2],tmp[3]});break;
                case "se" : ret=({tmp[2][8..15],tmp[3][8..15]});break;
		default : ret=tmp; 
	}	
	for(i=0;i<sizeof(ret);++i)
		ret[i]=p_color+ret[i];
	return ret;
}
// this is the consume of energy when troop match
int get_consume(string p_type,string p_side)
{
        switch(p_type)
        {       case "～":  return 6;
                case "．":  return 2;
                case "∧":  return 5;
                case "＊":  return 3;
                case "♂":  return 5;
                default:
                        return 2;
        }
}
// this will destruct all the war room for one area
int destruct_area(string p_area)
{
	string p_baseroom;
	int i,sum;
	mixed rooms;
//	p_baseroom=AREA_D->get_area(p_area,"path")+"warroom/";
	p_baseroom="/a/warroom/"+p_area+"/";
	rooms=objects((: strsrch(file_name($1),$(p_baseroom))!=-1 :));
	sum=sizeof(rooms);
	for(i=0;i<sum;++i)
		destruct(rooms[i]);
	return sum;
}
int clean_up() {
   return 0; // means never_again
}
