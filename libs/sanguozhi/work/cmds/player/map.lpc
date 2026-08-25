// map.c by fire on Jec 30 1997
#include <mudlib.h>
#include <daemons.h>
#include <ansi.h>

#define MAP_HELP PHELP+"help_map.txt"
#define MAP_NORTHWEST PMAP+"northwest.map"
#define MAP_MAIN PMAP+"main.map"
#define MAP_SOUTHEAST PMAP+"southeast.map"
#define MAP_NORTHEAST PMAP+"northeast.map"
#define MAP_SOUTHWEST PMAP+"southwest.map"
#define MAP_PROVINCE  PMAP+"province.map"

inherit CHINESE_DA;
inherit CMD;
inherit M_ANSI;

void show_map(string file)
{
        string mapinfo;
                string *list,my_area="no where",dis;
                object o,env;
                int p_num,i;
                o=this_body();
                if(objectp(o)){
                        env=environment(o);
                        if(objectp(env)) my_area=env->get_area();
                }
        mapinfo=read_file(file);
        printf(mapinfo);
                list = sort_array(AREA_D->list_areas(), 1);
                p_num=sizeof(list);
                for(i=0;i<p_num;i++)
                {

                        dis=sprintf("%6s%12s",AREA_D->get_area(list[i],"name"),list[i]);
                        if(list[i]==my_area) dis="%^ORANGE%^"+dis+"%^RESET%^";
                        if((i%4)==3) dis+="\n";
                        else dis+="|";
                        write(dis);
                }
                write("\n");
}
void show_mapa(string file,string area)
{
    string mapinfo;
        object env,o;
        string p_area="",p_room;
        string *ps;

    mapinfo=read_file(file);
   if(!stringp(mapinfo)) { write("此地地图还没好\n"); return;}
        mapinfo="/daemons/cmap_d"->add_color(mapinfo,file);

        o=this_body();
        if(objectp(o)) {
                env=o->query_room();
                if(objectp(env))
                        p_area=env->get_area();
        }
        if(p_area==area) {
                p_room=env->short();
                p_room=colour_truncate(p_room,50);
                ps=explode(mapinfo,p_room);
                if(sizeof(ps)<2) {
//                        SGSYS(area+"地区地图上没有房间："+p_room);
                }
                else {
 //                       if(sizeof(ps)>2)
//                                SGSYS(area+"地区地图上有多个房间："+p_room);
                        mapinfo=implode(ps,"%^ORANGE%^"+p_room+"%^RESET%^");
                }
        }
        if(mapinfo[<1]!='\n') mapinfo+="\n";
        write(mapinfo);
}
void show_museum() {
	string ret="/daemons/museum_d"->show_map();
	write(ret);
	return;
}
void main(string arg) 
{
        string p_map;
        object env;

        string* ret;
        mapping map_list=([]);
        map_list["northwest"]= MAP_NORTHWEST ;
        map_list["northeast"]= MAP_NORTHEAST ;
        map_list["southeast"]= MAP_SOUTHEAST ;
        map_list["main"]= MAP_MAIN ;
        map_list["southwest"]= MAP_SOUTHWEST ;
        map_list["province"] = MAP_PROVINCE;
        
        if (!arg)
        {
                show_map(MAP_HELP);
                return;
        }
		if(arg=="museum") {
			show_museum();
			return;
		}
        if(arg=="here")
        {
                env=this_body()->query_room();
                arg=env->get_area();
				if(arg=="museum") { show_museum(); return;}

                                ret=AREA_D->check_area("area",arg);
                                if(sizeof(ret)==0)
                                {
                        write("没有此处的地图，用map查阅目前已有的地图。\n");
                            return;
                                }
                                arg=ret[0];
        }
        p_map=map_list[arg];
        if(!p_map)
        {
                        arg=AREA_D->get_area(arg,"map");
                        if(!stringp(arg))
                        {
                                write("没有此处的地图，用map查阅目前已有的地图。\n");
                                return;
                        }
                        p_map=PMAP+arg+".map";
        }
        show_mapa(p_map,arg);
        return;
}
