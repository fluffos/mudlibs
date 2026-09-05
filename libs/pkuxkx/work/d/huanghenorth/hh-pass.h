//黄河过河文件 Zine 14/4/2011

#include <localtime.h>
void init()
{
    add_action("do_yell", "yell");
}




void check_trigger()
{
    object room;
    object ob=this_object();
    if(!query("exits/enter") ) {
        if( !(room = find_object(ob->query("boat"))) )//boat
            room = load_object(ob->query("boat"));//boat
        if( room = find_object(ob->query("boat")) ) //boat
            {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", ob->query("boat"));//boat
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上堤岸，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", (int)ob->query("waittime"));//wait time
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}
void on_board()
{
    object room;
    object ob=this_object();
    int time_arrive=(int)ob->query("arrivetime");
    mixed* timeinfos;
    int wday;
    timeinfos = localtime(time());
    wday = timeinfos[LT_WDAY];
    if( !query("exits/enter") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向江心驶去。\n",
        this_object() );

    if( room = find_object(ob->query("boat")) )//boat
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n江心驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    if (wday==6||wday==7)
    {
        time_arrive=time_arrive/2;
    }
    call_out("arrive", time_arrive);//time
}

void arrive()
{
    object ob=this_object();
    object room,room1;
    object* all;
    int i;
    room1=load_object(ob->query("boat"));
    all=all_inventory(room1);
    for (i=0;i<sizeof(all);i++)
        {
            all[i]->delete_temp("hhquest");
            all[i]->set_temp("riverpass",1);
        }
    if( room = find_object(ob->query("boat")) )//boat
    {
        room->set("exits/out", ob->query("destination"));//destination
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上堤岸。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 8);
}

void close_passage()
{
    object ob=this_object();
    object room;
    object* all;
    int i;
    if( room = find_object(ob->query("boat")) ) //boat
        {
        all=all_inventory(room);
        for (i=0;i<sizeof(all);i++)
        {
            if (all[i]->query_temp("riverpass"))
            {
                all[i]->move(ob->query("destination"));
                all[i]->delete_temp("riverpass");
                tell_object(all[i],"艄公要继续做生意了，所有人被赶下了渡船。\n");
            }    
            
        }
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向江心。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;
    if( !arg || arg=="" ) return 0;

    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("neili") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="船家")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
        object room;
        object ob=this_object();
        object *all;

        ::reset();

        if( room = find_object(ob->query("boat")) )
        {
            all = filter_array( all_inventory(room), (: userp :));
            if (sizeof(all)>0)
            {
                return;
            }
            room->delete("yell_trigger");
        }
}

int valid_leave(object me,string dir)
{
    object ob=this_object();
	string *dirs;
    if (ob->query("npc_forbidden_dirs"))
	{
		dirs=ob->query("npc_forbidden_dirs");
		if (member_array(dir,dirs)!=-1&&!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
		{
			return notify_fail("禁止NPC穿越区域。\n");		
		}
	}
	if (!ob->query("free") &&!me->query("is_trainee") &&!me->query_temp("rider")&& dir=="enter" && me->query_temp("hhallowed")!=(int)ob->query("ticket")&&time()>me->query("river_pass"))//ticket
    {
           return notify_fail("艄公一把拉住你，你还没付钱呢？\n");
        
    }
    me->delete_temp("hhallowed");
	return ::valid_leave(me, dir);
}



