#include <mudlib.h>
#include <daemons.h>

inherit CMD;
inherit M_GRAMMAR;
inherit M_ANSI;

mapping vals;
mapping amap;
int x, y, x2, y2;

void resolve_data_file(string filename);
void prepare_map(mapping rooms, string cc);
void check_range();
void plot_map(mapping rooms);

private void main(string city)
{
	string name, center;
	mapping rooms;

	if( !city||!stringp(city) ) {
		write("Which city ?\n");
		return;
	}
	city = "/data/area/"+city+".o";
	if( file_size(city)==-1 ){
		write("No such data file exists!\n");
		return;
	}
	resolve_data_file(city);

	rooms = vals["rooms"];
	name  = vals["m_area"];
	center= AREA_D->get_area(name, "go");
	amap  = ([ ]);

	prepare_map(rooms, center);
	check_range();
	plot_map(rooms);

	return;
}
void resolve_data_file(string filename)
{
	string tt, key, value;

	if( !filename||file_size(filename)<=0 )
		write("Can not find the data file!\n");
	else if( !(tt=read_file(filename)) )
		write("Data file is empty!\n");
 	else {
		vals = ([ ]);
		foreach( string line in explode(tt, "\n") ){
        		if( line[0]=='#' ) continue;
        		if( sscanf(line, "%s %s", key, value)!=2 ){
				write("Data file syntax error!\n");
				return;
			};
        		vals[key] = restore_variable(value);
    		}
	}
}
void prepare_map(mapping rooms, string cc)
{
	int X, Y;
	mapping exits, tmp;
	string *checked, *cur, *curtmp;
	string *ckey;

	checked = ({ });
	cur  = ({ cc });
	tmp = rooms[cc];
	tmp["x"] = 0;
	tmp["y"] = 0;
	rooms[cc] = tmp;

	while( sizeof(cur) ){
		curtmp = ({ });
		foreach(string ss in cur){
			tmp = rooms[ss];
			if( !tmp||!mapp(tmp) ) continue;
			X = tmp["x"];
			Y = tmp["y"];
			exits = rooms[ss]["e"];
			if( !exits||!mapp(exits) ) continue;
			ckey = keys(exits);
			foreach(string rr in ckey){
				if( member_array(exits[rr], checked)!=-1 )continue;
				curtmp-=({ exits[rr] });
				curtmp+=({ exits[rr] });
				checked-=({ exits[rr] });
				checked+=({ exits[rr] });
				if( rr=="east" ){
					tmp = rooms[exits[rr]];
					tmp["x"] = X+1;
					tmp["y"] = Y;
					rooms[exits[rr]] = tmp;
					amap[(X+1)+"/"+Y] = exits[rr];
				} else if( rr=="west" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X-1;
                                        tmp["y"] = Y;
                                        rooms[exits[rr]] = tmp;
                                        amap[(X-1)+"/"+Y] = exits[rr];
                                } else if( rr=="north" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X;
                                        tmp["y"] = Y-1;
                                        rooms[exits[rr]] = tmp;
                                        amap[X+"/"+(Y-1)] = exits[rr];
                                } else if( rr=="south" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X;
                                        tmp["y"] = Y+1;
                                        rooms[exits[rr]] = tmp;
                                        amap[X+"/"+(Y+1)] = exits[rr];
                                } else if( rr=="northwest" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X-1;
                                        tmp["y"] = Y-1;
                                        rooms[exits[rr]] = tmp;
                                        amap[(X-1)+"/"+(Y-1)] = exits[rr];
                                } else if( rr=="northeast" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X+1;
                                        tmp["y"] = Y-1;
                                        rooms[exits[rr]] = tmp;
                                        amap[(X+1)+"/"+(Y-1)] = exits[rr];
                                } else if( rr=="southwest" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X-1;
                                        tmp["y"] = Y+1;
                                        rooms[exits[rr]] = tmp;
                                        amap[(X-1)+"/"+(Y+1)] = exits[rr];
                                } else if( rr=="southeast" ){
                                        tmp = rooms[exits[rr]];
                                        tmp["x"] = X+1;
                                        tmp["y"] = Y+1;
                                        rooms[exits[rr]] = tmp;
                                        amap[(X+1)+"/"+(Y+1)] = exits[rr];
                                } else {
tell_user("flee","room \""+exits[rr]+"\" not in use \n");
					checked-=({ exits[rr] });
                                	checked+=({ exits[rr] });
				}
			}
		}
		cur = ({ });
		cur = curtmp;
	}
}
void check_range()
{
	int xx, yy;
	string *nn;
	
	foreach(string ss in keys(amap)){
		nn = explode(ss, "/");
		xx = to_int(nn[0]);
		yy = to_int(nn[1]);
		if( xx < x ) x = xx;
		if( yy < y ) y = yy;
		if( xx > x2 ) x2 = xx;
		if( yy > y2 ) y2 = yy;
	}
}
void plot_map(mapping rooms)
{
	int xx, yy;
	string rr, l1, l2, ll, nn;

	for( yy=y; yy<=y2; yy++){
		for( xx=x; xx<=x2; xx++){
			if( !stringp(rr=amap[xx+"/"+yy]) ){
				if( !l1 ) l1="        ";
				else l1+="        ";
				if( !l2 ) l2="      ";
				else if( !(sizeof(l2)%8) ) l2=l2+"      ";
				else l2=l2+"        ";
			} else {
				nn = rooms[rr]["b"];
				nn = colour_truncate(nn, 6);
				if( sizeof(nn)>6 ) l1+=nn[0..5];
				else l1+=" "+nn+" ";
				if( stringp(rooms[rr]["e"]["east"]) ) l1+="--";
				else l1+="  ";
				if( !(sizeof(l2)%8)&&stringp(rooms[rr]["e"]["southwest"]) ) l2+="／  "; 
				else l2+="    ";
				if( stringp(rooms[rr]["e"]["south"]) ) l2+="│  ";
				else l2+="    ";
				if( stringp(rooms[rr]["e"]["southeast"]) ) l2+="＼";
				else l2+="     ";
			}
		}
		if( !ll ) ll = l1+"\n";
		else ll=ll+l1+"\n";
		ll=ll+l2+"\n";
		l1 = "";
		l2 = "";
	}
	write(ll+"\n");
}
