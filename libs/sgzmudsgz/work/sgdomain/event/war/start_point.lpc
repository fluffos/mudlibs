//start_point 
// this is used to handle the troop to enter the start position
int distance(int x,int y,int x1,int y1)
{
	int xd;
	int yd;
	xd=((x1 >x) ? (x1-x) : (x-x1) );
	yd=((y1 >y) ? (y1-y) : (y-y1) );
	return xd+yd;
}
mixed valid_start_point(string p_area,string p_side,int x,int y)
{
	int x_c,y_c;
	int *troops;
	mixed p_c;
	int height,width;
	int p_dis;
	string p_here;
	height=MAP_D->get_city(p_area,"height");
	width=MAP_D->get_city(p_area,"width");
	if((x<0)||(x>=width)||(y<0)||(y>=height))
		return "越界。\n";
	p_c=MAP_D->get_city(p_area,"center");
	x_c=p_c[0];y_c=p_c[1];
	p_here=MAP_D->get_map_cell(p_area,y,x,"m");
	if(p_here=="※")
		return "此处无法驻兵。\n";
	p_dis=distance(x,y,x_c,y_c);
	if((p_side=="a"))
	{   if (p_dis<7)
		return "离敌帅帐太近。\n";
	    if((x!=0)&&(y!=0)&&(x!=width-1)&&(y!=height-1))
		return "进攻方只能从边界出兵。\n";
	}
	else
	{
		if(p_dis>7)
			return "离帅帐太远。\n";
	}
	troops=MAP_D->get_map_cell(p_area,y,x,"t");
	if(sizeof(troops))
	foreach(int troop in troops)
	{
		if(TROOP_D->get_troops(troop,"side")!=p_side)
			return "此地已有敌军驻兵。\n";
	}
	return 1;
}
string auto_start_point(string p_area,string p_side)
{
        int height,width;
        mixed p_res=0;
	int *p_c;
        int x,y,x_c,y_c;
        height=MAP_D->get_city(p_area,"height");
        width=MAP_D->get_city(p_area,"width");
        if(p_side=="a")
	{
	        while(p_res!=1)
        	{
                	switch(random(4))
	                {
        	                case 0: x=0; y=random(height); break;
                	        case 1: x=width-1; y=random(height); break;
                        	case 2: y=0; x=random(width); break;
	                        case 3: y=height-1; x=random(width); break;
        	        }
                	p_res=valid_start_point(p_area,p_side,x,y);
	        }
	}
	else
	{
	        p_c=MAP_D->get_city(p_area,"center");
        	x_c=p_c[0];y_c=p_c[1];
                while(p_res!=1)
 		{
			x=x_c+random(10)-5;
			y=y_c+random(10)-5;
			p_res=valid_start_point(p_area,p_side,x,y);
		}	
	}
        return WARAI_D->point_tostring(({x,y}));
}
string att_get_position(string p_area,string p_dir)
{
   mixed p_res=0;
   int x,y;
   int p_test=0;
    int height,width;
	int *p_c;
    height=MAP_D->get_city(p_area,"height");
    width=MAP_D->get_city(p_area,"width");

   p_dir=lower_case(p_dir);


   while((p_res!=1)&&(p_test<10))
  	{
       	switch(p_dir)
        {
            case "w": x=0; y=random(height); break;
            case "n": y=0; x=random(width); break;
	        case "s": y=height-1; x=random(width); break;
   	        default: x=width-1; y=random(height); break;
        }
       	p_res=valid_start_point(p_area,"a",x,y);
		p_test++;
	}
  if(p_res==1) return WARAI_D->point_tostring(({x,y}));
  return auto_start_point(p_area,"a");
}

string def_get_position(string p_area,string p_dir)
{
   int x_offset,y_offset,x_rand,y_rand;
   mixed p_res=0;
   int *p_c;
   int x,y,x_c,y_c;
   int p_test=0;
   p_c=MAP_D->get_city(p_area,"center");
   x_c=p_c[0];y_c=p_c[1];
   p_dir=lower_case(p_dir);
   switch(p_dir[0])
   {
    case 'e':
       x_offset=3;x_rand=1;
       y_offset=0;y_rand=2;
       break;
    case 'w':
       x_offset=-3;x_rand=1;
       y_offset=0;y_rand=2;
       break;
    case 'n':
       y_offset=-3;y_rand=1;
       x_offset=0;x_rand=2;
       break;
    case 's':
       y_offset=3;y_rand=1;
       x_offset=0;x_rand=2;
       break;
    default:
       y_offset=0;y_rand=2;
       x_offset=0;x_rand=2;
       break;
   }
   while((p_res!=1)&&(p_test<10))
   {
      x=x_c+x_offset+random(2*x_rand+1)-x_rand;
      y=y_c+y_offset+random(2*y_rand+1)-y_rand;
      p_res=valid_start_point(p_area,"d",x,y);
      p_test++;
  }       
  if(p_res==1) return WARAI_D->point_tostring(({x,y}));
  return auto_start_point(p_area,"d");
}
