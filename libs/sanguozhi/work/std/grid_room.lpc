// GRID_ROOM
// this room just used by war field

inherit BASE_ROOM;

private string m_aid; // the area_id
private int m_x,m_y; // the grid_position
private int p_nMyTrpId;

int is_gridroom() { return 1; }

void create_chars()
{
	string m_name;
        mixed list;
	int i;
	m_name=file_name();
	list=TROOP_D->check_troop("room",m_name);
	for(i=0;i<sizeof(list);++i)
		TROOP_D->put_troop(list[i],m_name);
}

void set_pos(mixed pos)
{
        m_x=pos[0];m_y=pos[1];
}

void set_aid(string p_id)
{
        m_aid=p_id;
}

int* query_pos()
{
        return ({m_x,m_y});
}
string query_str_pos() {
        return sprintf("%c%d",m_x+'A',m_y+1);
}

string query_aid()
{
        return m_aid;
}

int is_outdoors()
{
    return 1;
}

void mudlib_setup()
{
    ::mudlib_setup();
    add_id("battlefield");
}

string* get_long(string p_type, string pos, string par_strL1, string par_strL2, string par_strL3, string par_strL4 )
{
    int i,j, has_soldier;
    string *ret,*tmp,*wri;
    string f_name;
    string p_color;
    mapping m = (["│":"ns","└":"sw","┘":"se","┌":"nw","┐":"ne","─":"we","◎":"shuai"]);
  
    tmp = ({"","","",""});
    
    if ( par_strL1 != "" )
    {  
        has_soldier = 1;
    }
    else
    {
        has_soldier = 0;
    }
    
    if ( !has_soldier )
    {

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
              for(j=0;j<4;++j)
                if(random(3))
                    tmp[i]+="　";
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
            f_name=PPIC+"wall"+m[p_type]+".8.pic";
            for(i=0;i<4;++i)
            {
                    tmp[i]=read_file(f_name,i+1,1); 
                    tmp[i]=tmp[i][0..7];
            }
            break;
        default:
            f_name=PPIC+"void.8.pic";
            for(i=0;i<4;++i)
            {
                    tmp[i]=read_file(f_name,i+1,1); 
                    tmp[i]=tmp[i][0..7];
            }         
        }
    }
    else
    {
        tmp[0] = par_strL1;
        tmp[1] = par_strL2;
        tmp[2] = par_strL3;
        tmp[3] = par_strL4;
    }

/*    switch(pos)
    {
	case "c" : ret=tmp; break;
	case "nw" : ret=({tmp[0][0..3], tmp[1][0..3]});break;
	case "n" : ret=({tmp[0],tmp[1]});break;
	case "ne" : ret=({tmp[0][4..7], tmp[1][4..7]});break;
	case "w" : ret=({tmp[0][0..3],tmp[1][0..3],tmp[2][0..3],tmp[3][0..3]});break;
	case "e" : ret=({tmp[0][4..7],tmp[1][4..7],tmp[2][4..7],tmp[3][4..7]});break;
	case "sw" : ret=({tmp[2][0..3],tmp[3][0..3]});break;
	case "s" : ret=({tmp[2],tmp[3]});break;
	case "se" : ret=({tmp[2][4..7],tmp[3][4..7]});break;
	default : ret=tmp; 
    }
*/
    ret=tmp;
    wri = allocate(sizeof(ret));
    for( i = 0; i < sizeof(wri); i++)
    	wri[i] = ret[i];

    if ( !has_soldier ) 
    {
        p_color=MAP_D->get_color(p_type);
    	for( i = 0; i < sizeof(wri); i++ )
    	    wri[i] = p_color + wri[i];
    }
/*
    else
    {
        for( i = 0; i < sizeof(wri); i++ )
        {
            wri[i] = par_color + wri[i];

	wri[i] = "";
     	for( j = 0; j < 8; j += 2 ) {
            if ( ret[i][j..(j+1)] == "Ｄ" || ret[i][j..(j+1)] == "Ａ" || 
		 ret[i][j..(j+1)] == "Ｍ" || 
                 (member_array(ret[i][j..(j+1)], CHINESE_D->s_array())+1) ) {
            wri[i] += s_color + ret[i][j..(j+1)];
	    }
	    else
		wri[i] += p_color + ret[i][j..(j+1)];
	}
        }
      }
*/
    return wri;
}

// get the troop discription of the cell
string * troop_infoa(int x,int y, string side)
{
    mixed troop;
    int n, i;
    string * troopinfo = ({ "", "", "", "" });	// line 0,1,2,3
    string mside;
    string strEmpty;
    string strZero;

    troop = MAP_D->get_map_cell(m_aid, y, x,"t");

    n = 0;

    for(i = 0; i < sizeof(troop); i++) 
    {
	    string p_strColor = "";
	    mixed mtmp;
	    string tp;
        string tr_strLeaderName;  // chinese name of the troop's first leader
        string tr_strType;  // troop type name
        string tr_strNum;  // soldier number        

    	mside=TROOP_D->get_troops(troop[i],"side");
    	if((side!="b")&&(mside!=side)&&(!TROOP_D->get_troops(troop[i],"canbeseen")))
    		continue;

        // 防守方用蓝色，进攻方用红色
        if ( mside == "a" )
        {
            p_strColor = "%^H_RED%^";
            strEmpty = "Ａ";
        }
        else
        {
            p_strColor = "%^H_BLUE%^";
            strEmpty = "Ｄ";
        }

	    // get the chinese word of the soldier type      
        mtmp = TROOP_D->get_troops(troop[i],"soldier");
        mtmp = keys(mtmp);
        tp = mtmp[0];  
        tr_strType = WARAI_D->get_soldier(tp,"name");
        tr_strType = colour_truncate( tr_strType, 2 );
        tr_strType = tr_strType[0..1];

        // get the display of the soldier number       
    	n = TROOP_D->get_soldier_total_number( troop[i] );
	    tr_strNum = TROOP_D->chinese_soldier_number( n );
        strZero = "(无)";
        
	    if ( troop[i] == p_nMyTrpId )
	    // xiaobai: 自己用 M 来表示， 
	    {
		    tr_strLeaderName = "Ｍ";
	    }
	    else
	    // 别人的部队，用第一个将领的第一个字
	    {
		    tr_strLeaderName = TROOP_D->get_troop_symbol( troop[i] );
        }
        
        // contruct the troops discription
        if ( i == 0 )
        // first troop use the first 2 lines
        {
            troopinfo[0] = p_strColor + repeat_string(tr_strType, 4);
            troopinfo[1] = p_strColor + tr_strType + "%^H_CYAN%^" + tr_strLeaderName +
                "%^H_WHITE%^" + tr_strNum + p_strColor + tr_strType;
            troopinfo[2] = p_strColor + strEmpty + "%^H_WHITE%^" + strZero +
                p_strColor + strEmpty;
            troopinfo[3] = p_strColor + repeat_string(strEmpty, 4);
        }
        else
        {   
            troopinfo[2] = p_strColor + tr_strType + "%^H_WHITE%^" + tr_strNum + 
                "%^H_CYAN%^" + tr_strLeaderName + p_strColor + tr_strType;
            troopinfo[3] = p_strColor + repeat_string(tr_strType, 4);
        }
  	}
  
    return troopinfo;

}
string * troop_info(int x, int y) {
	return troop_infoa(x,y,"b"); // both side
}


mixed long()
{
    int i, j;
    string cell_type;
    string* p_tmp;
    string* p_disp;
    string * tinfo;
    string p_ret;
	object o=this_body();
	object env;
	int troop_id;
	string p_side;
	if(!objectp(o)) return "can't find you :)";
	env = environment(o);
	//if( !env->is_troop() ) return "not in troop, can't see";

	troop_id = env->get_id();
	p_nMyTrpId = troop_id;
	p_side = TROOP_D->get_troops( troop_id, "side");		

    p_disp=({"","","","","","","","","","","","","","","","","","","",""});

  //string * disp = explode(::long(), '\n');


  // column 1
/*  i = -3;

  tinfo = troop_infoa(m_x+i, m_y-3,p_side);
  cell_type = MAP_D->get_map_cell(m_aid,m_y-3,m_x+i,"m");
  if (!cell_type) cell_type = "xx";
  p_tmp = get_long(cell_type, "se", tinfo[0], tinfo[1], tinfo[2]);
  p_disp[0]=p_tmp[0];p_disp[1]=p_tmp[1];			// 0,1
*/
for (i = -2;i<=2;i++)
{ //FBUG("xxxxxxxxxxxx");
  for(j = -2; j <= 2; j++) {
    tinfo = troop_infoa(m_x+i, m_y+j,p_side);
    cell_type = MAP_D->get_map_cell(m_aid,m_y+j,m_x+i, "m");
    if (!cell_type) cell_type = "xx";
    p_tmp = get_long( cell_type, "e", tinfo[0], tinfo[1], tinfo[2], tinfo[3] );
   // FBUG(sprintf("%O",p_tmp));
    p_disp[(j+2)*4+0] += p_tmp[0];                           	// 2,6,10,14,18
    p_disp[(j+2)*4+1] += p_tmp[1];                           	// 3,7,11,15,19
    p_disp[(j+2)*4+2] += p_tmp[2];                          	// 4,8,12,16,20
    p_disp[(j+2)*4+3] += p_tmp[3];                           	// 5,9,13,17,21
  }
}
/*  tinfo = troop_infoa(m_x+i, m_y+2,p_side);
  cell_type = MAP_D->get_map_cell(m_aid,m_y+2,m_x+i,"m");
  if (!cell_type) cell_type = "xx";
  p_tmp = get_long(cell_type, "ne", tinfo[0], tinfo[1], tinfo[2]);
  p_disp[14]=p_tmp[0];p_disp[15]=p_tmp[1];			// 14,15

  // columns 2,3,4
  for(i = -1; i <= 1; i++) {

    tinfo = troop_infoa(m_x+i, m_y-2,p_side);
    cell_type = MAP_D->get_map_cell(m_aid,m_y-2,m_x+i,"m");
    if (!cell_type) cell_type = "xx";
    p_tmp = get_long(cell_type, "s", tinfo[0], tinfo[1], tinfo[2]);
    p_disp[0]+=p_tmp[0];p_disp[1]+=p_tmp[1];			// 0,1


    for(j = -1; j <= 1; j++) {
        tinfo = troop_infoa(m_x+i, m_y+j,p_side);
        cell_type = MAP_D->get_map_cell(m_aid,m_y+j,m_x+i,"m"); 
        if (!cell_type) cell_type = "xx";
        p_tmp = get_long(cell_type, "c", tinfo[0], tinfo[1], tinfo[2]);
        p_disp[(j+1)*4+2] += p_tmp[0];                      	// 2,6,10
        p_disp[(j+1)*4+3] += p_tmp[1];                      	// 3,7,11
        p_disp[(j+1)*4+4] += p_tmp[2];                      	// 4,8,12
        p_disp[(j+1)*4+5] += p_tmp[3];                      	// 5,9,13
    }

    tinfo = troop_infoa(m_x+i, m_y+2,p_side);
    cell_type = MAP_D->get_map_cell(m_aid,m_y+2,m_x+i,"m"); 
    if (!cell_type) cell_type = "xx";
    p_tmp = get_long(cell_type, "n", tinfo[0], tinfo[1], tinfo[2]);
    p_disp[14]+=p_tmp[0];p_disp[15]+=p_tmp[1];			// 14,15
  }

  // column 5
  i = 2;

  tinfo = troop_infoa(m_x+i, m_y-2,p_side);
  cell_type = MAP_D->get_map_cell(m_aid,m_y-2,m_x+i,"m");
  if (!cell_type) cell_type = "xx";
  p_tmp = get_long(cell_type, "sw", tinfo[0], tinfo[1], tinfo[2]);
  p_disp[0]+=p_tmp[0];p_disp[1]+=p_tmp[1];                      // 0,1
 
  for(j = -1; j <= 1; j++) {
    tinfo = troop_infoa(m_x+i, m_y+j,p_side);
    cell_type = MAP_D->get_map_cell(m_aid,m_y+j,m_x+i, "m");
    if (!cell_type) cell_type = "xx";
    p_tmp = get_long(cell_type, "w", tinfo[0], tinfo[1], tinfo[2]);
    p_disp[(j+1)*4+2] += p_tmp[0];                              // 2,6,10
    p_disp[(j+1)*4+3] += p_tmp[1];                              // 3,7,11
    p_disp[(j+1)*4+4] += p_tmp[2];                              // 4,8,12
    p_disp[(j+1)*4+5] += p_tmp[3];                              // 5,9,13
  } 
  
  tinfo = troop_infoa(m_x+i, m_y+2,p_side);
  cell_type = MAP_D->get_map_cell(m_aid,m_y+2,m_x+i,"m");
  if (!cell_type) cell_type = "xx";
  p_tmp = get_long(cell_type, "nw", tinfo[0], tinfo[1], tinfo[2]);
  p_disp[14]+=p_tmp[0];p_disp[15]+=p_tmp[1];                    // 14,15
*/
  p_ret = p_disp[0];
  for(i = 1; i < 20; i++) {
      p_ret = p_ret + "\n" + p_disp[i];
  }
  p_ret = p_ret + "%^RESET%^\n";
  return p_ret;

  // return ::long();						// wiz_only
}

