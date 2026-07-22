//山道:shanlu.c 
//tomcat
inherit ROOM;

void create()
{
	set("short", "倭寇岛海岸");
	set("long", @LONG
这里是倭寇小岛的海边，周围停着小船(boat)。

LONG
	);


	set("exits", ([ /* sizeof() == 3 */
	"east" : __DIR__"migong/entry",
//	"east" : "/d/changan/zhongnan",
 ]));

	//set("coor/x",10000);
	//set("coor/y",1880);
	//set("coor/z",0);
        set("indoors", "japisland");
     //   set("no_death_penalty",1);
      //  set("can_dazuo",1);
	setup();
}
/*
int remove_all_players(object maze_room,object exile_room,string remove_msg){
        
        string fname = base_name(maze_room);
        object m_room,*inv;
        int x,y,k,num,length; 
        length=maze_room->query_maze_length();
        
        tell_room(this_object(),remove_msg);
        inv=all_inventory(this_object());
        num=sizeof(inv);
        while(num--) {
                if (userp(inv[num]))
                        inv[num]->move(exile_room);     
        }
        
}   
*/
void init(){
        add_action("do_climb", "sail");
} 
int do_climb(string arg){
        object me, room;
        me = this_player();
   if(!arg || (arg != "boat")){
                return notify_fail("你要开什么？\n");
        }
    //    if (WAR_D->query_sunrise_block() && !me->query_temp("ally/honor"))
     //       return notify_fail("日出城目前战事正急，小船都被倭寇划走了。\n");
        message_vision("$N坐上小船，顺手划了出去。\n", me);
        room = find_object("/d/sunrise/eastsail");
        if(!objectp(room)){
                room = load_object("/d/sunrise/eastsail");
        }
        me->delete("jap_island_time");
        me->move(room);
        message_vision("$N坐船回到日出城。\n", me);
        return 1;
} 
