/* Do not remove the headers from this file! see /USAGE for more info. 
   war_grid.c this is a modified version of grid_server.c
*/
#include <security.h>
inherit M_ACCESS;
nosave private mixed grid_desc_id;
nosave private string a_id;
#define GRID_HEIGHT     sizeof(grid_desc_id)
#define GRID_WIDTH      sizeof(grid_desc_id[0])
#define GRID_ROOM(x,y)  (file_name() + "/" + (x) + "/" + (y))
#define CELL(x,y)  (grid_desc_id[(y)][(x)])
string room_desc(int x,int y);
    
mixed cell(int x, int y) {
  if( x < 0 ) return "XX";
  if( y < 0 ) return "XX";
  if( x > (MAP_D->get_city(a_id,"width")-1) )  return "XX";
  if( y > (MAP_D->get_city(a_id,"height")-1) ) return "XX";
  return grid_desc_id[y][x];
}
        
void install_obj(string m_name)
{
        mixed list;
        int i;
        list=CHAR_D->check_char("room",m_name);
        for(i=0;i<sizeof(list);++i)
        {
                CHAR_D->put_char(list[i],m_name);
        }       
        list=TROOP_D->check_troop("room",m_name);
        for(i=0;i<sizeof(list);++i)
                TROOP_D->put_troop(list[i],m_name);
}
void create() {
    set_privilege(1);
}
string room_desc(int x,int y);
void use_data_file(string area_id)
{
    int i,j,width,height;
    a_id=area_id;
    width=MAP_D->get_city(a_id,"width");
    height=MAP_D->get_city(a_id,"height");
    grid_desc_id=({});
    for(i=0;i<height;++i)
    {
        grid_desc_id+=({""});
        grid_desc_id[i]=({});
        for(j=0;j<width;++j)
                grid_desc_id[i]+=({MAP_D->get_map_cell(a_id,i,j,"m")});
    }
}
void setup()
{
}
string room_brief(int x,int y)
{
        return AREA_D->get_area(a_id,"name")+"地区战场 "+
                MAP_D->get_color(grid_desc_id[y][x])+
                MAP_D->get_brief(grid_desc_id[y][x])+"%^RESET%^";
}
object virtual_create(string arg)
{
    int idx = member_array('/', arg);
    int x;
    int y;
    string exit_n;
    string exit_e;
    string exit_s;
    string exit_w;
    object room;
   setup();
    if ( idx == -1 )
        return 0;
    x = to_int(arg[0..idx-1]);
    y = to_int(arg[idx+1..]);
    if(y)
       exit_n=GRID_ROOM(x,y-1);
    if(y<GRID_HEIGHT-1)
       exit_s=GRID_ROOM(x,y+1);
    if(x)
        exit_w=GRID_ROOM(x-1,y);
    if(x<GRID_WIDTH-1)
        exit_e=GRID_ROOM(x+1,y);
    room = new(WAR_ROOM);
    room->set_aid(a_id);
    room->set_pos(({x,y}));
    room->set_brief(room_brief(x,y));
    room->set_area(AREA_D->get_area(a_id,"area"));
    room->set_long(room_desc(x, y));
    if(exit_n)
    room->add_exit("north", exit_n);
    if(exit_e)
    room->add_exit("east", exit_e);
    if(exit_s)
    room->add_exit("south", exit_s);
    if(exit_w)
    room->add_exit("west", exit_w);
    return room;
}
// Disappear if no longer needed
protected void clean_up() {
   destruct(this_object());
}
    
string room_desc(int x,int y)
{
    string* p_tmp;
    string* p_disp;
    string p_ret;
    int i, j;
    
    p_disp=({"","","","","","","","","","","","","","","",""});
        
    // column 1
    i = -2;
    p_tmp = MAP_D->get_long(cell(x+i,y-2), "se");               // 0,1   
    p_disp[0]=p_tmp[0];p_disp[1]=p_tmp[1];
    for(j = -1; j <= 1; j++) {
        p_tmp = MAP_D->get_long(cell(x+i,y+j), "e");
        p_disp[(j+1)*4+2] = p_tmp[0];                           // 2,6,10
        p_disp[(j+1)*4+3] = p_tmp[1];                           // 3,7,11
        p_disp[(j+1)*4+4] = p_tmp[2];                           // 4,8,12
        p_disp[(j+1)*4+5] = p_tmp[3];                           // 5,9,13
    }
    p_tmp = MAP_D->get_long(cell(x+i,y+2), "ne");               // 14,15
    p_disp[14]=p_tmp[0];p_disp[15]=p_tmp[1];
    
    // columns 2,3,4
    for(i = -1; i <= 1; i++) {
        p_tmp = MAP_D->get_long(cell(x+i,y-2), "s");            // 0,1   
        p_disp[0]+=p_tmp[0];p_disp[1]+=p_tmp[1];
        for(j = -1; j <= 1; j++) {
            p_tmp = MAP_D->get_long(cell(x+i,y+j), "c");
            p_disp[(j+1)*4+2] += p_tmp[0];                      // 2,6,10
            p_disp[(j+1)*4+3] += p_tmp[1];                      // 3,7,11
            p_disp[(j+1)*4+4] += p_tmp[2];                      // 4,8,12
            p_disp[(j+1)*4+5] += p_tmp[3];                      // 5,9,13
        }
        p_tmp = MAP_D->get_long(cell(x+i,y+2), "n");            // 14,15
        p_disp[14]+=p_tmp[0];p_disp[15]+=p_tmp[1];
    }
    
    // column 5
    i = 2;
    p_tmp = MAP_D->get_long(cell(x+i,y-2), "sw");               // 0,1
    p_disp[0]+=p_tmp[0];p_disp[1]+=p_tmp[1];
    for(j = -1; j <= 1; j++) {
        p_tmp = MAP_D->get_long(cell(x+i,y+j), "w");
        p_disp[(j+1)*4+2] += p_tmp[0];                          // 2,6,19
        p_disp[(j+1)*4+3] += p_tmp[1];                          // 3,7,11
        p_disp[(j+1)*4+4] += p_tmp[2];                          // 4,8,12
        p_disp[(j+1)*4+5] += p_tmp[3];                          // 5,9,13
    }
    p_tmp = MAP_D->get_long(cell(x+i,y+2), "nw");               // 14,15
    p_disp[14]+=p_tmp[0];p_disp[15]+=p_tmp[1];
        
    p_ret = p_disp[0];
    for(i = 1; i < 16; i++) {
        p_ret = p_ret + "\n" + p_disp[i];
    }
    p_ret = p_ret + "%^RESET%^\n";
    return p_ret;
}   

