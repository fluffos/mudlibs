// neighbor.c
// part of warai_d.c
// 0 means none
string get_troops_name(string p_id,int x,int y);
mixed get_neighbor_pos(int t_id,string direction)
{
   string a_id;
   int *pos;
   int x,y;
   pos=TROOP_D->get_troops(t_id,"position");
   a_id=TROOP_D->get_troops(t_id,"area");
   if(!a_id)
	return 0;
   x=pos[0];y=pos[1];
   switch(direction)
   {
	case "e":
	case "east": x++;break;
	case "s":
        case "south": y++;break;
	case "w":
  	case "west": x--;break;
	case "n":
 	case "north": y--;break;
	case "e 2":
	case "east 2": x+=2;break;
	case "s 2":
        case "south 2": y+=2;break;
	case "w 2":
  	case "west 2": x-=2;break;
	case "n 2":
 	case "north 2": y-=2;break;
	
	case "nw":
	case "northwest": x--; y--; break;
	case "ne":
	case "northeast": x++; y--; break;
	case "sw":
	case "southwest": x--; y++; break;
	case "se":
	case "sougheast": x++; y++; break;
	default: return 0;
   }
   if(!MAP_D->get_map_cell(a_id, y, x,"m"))
	return 0;
   return ({x,y});
}
mixed get_neighbor_side(int t_id,string direction)
{
   int *pos;
   int *troops;
   string a_id;
   string p_side;
   pos=get_neighbor_pos(t_id,direction);
   a_id=TROOP_D->get_troops(t_id,"area");
   if(!pos) return 0;
   if(!a_id) return 0;
   troops=MAP_D->get_map_cell(a_id,pos[1],pos[0],"t");
   if((!troops)||(!sizeof(troops)))
	return 0;
   p_side=TROOP_D->get_troops(troops[0],"side");
   return p_side;
}
mixed get_neighbor_defence_rate(int t_id,string direction)
{
   int *pos;
   string a_id;
   pos=get_neighbor_pos(t_id,direction);
   a_id=TROOP_D->get_troops(t_id,"area");
   return (MAP_D->get_map_cell(a_id, pos[1],pos[0],"defence_rate"));
}
int distance(int x,int y,int x1,int y1)
{
        int xd;
        int yd;
        xd=((x1 >x) ? (x1-x) : (x-x1) );
        yd=((y1 >y) ? (y1-y) : (y-y1) );
        return xd+yd;
}
int get_neighbor_distance(int t_id,string direction)
{
   string a_id;
   int *pos;
   mixed post;
   int x,y,xt,yt;
   pos=TROOP_D->get_troops(t_id,"position");
   if(!pos) return 1000; // this may mean the troop already disappeard
   a_id=TROOP_D->get_troops(t_id,"area");
   x=pos[0];y=pos[1];
   post=get_neighbor_pos(t_id,direction);
   if(!post) return 0;
   xt=post[0];yt=post[1];
   return distance(x,y,xt,yt);
}
string get_neighbor_troop_name(int t_id,string direction)
{
   int *pos;
   string a_id;
   pos=get_neighbor_pos(t_id,direction);
   a_id=TROOP_D->get_troops(t_id,"area");
   if(!pos) return "";
   if(!a_id) return "";
   return get_troops_name( a_id, pos[0],pos[1]);
}
mixed get_neighbor_troops(int t_id,string direction)
{
   int *pos;
   string a_id;
   int *t;
   pos=get_neighbor_pos(t_id,direction);
   a_id=TROOP_D->get_troops(t_id,"area");
   if(!pos) return "";
   if(!a_id) return "";
   t=MAP_D->get_map_cell(a_id,pos[1],pos[0],"t");
   return t;
}
