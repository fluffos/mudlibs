// by paladin

inherit ROOM;

void create()
{
set("short", "善人渡");
        set("long", @LONG
四条铁索，两条在下，上铺木板，以供行走(zou)，两条在旁作为扶手。
一踏上桥，几条铁索便即幌动, 吓的你半死.
LONG
        );

        setup();
        set("no_task", 1);
        set("no_dbr_stage",1);
		set("hsz_no_task",1);
//        replace_program(ROOM);
}

void init()
{       
        object ob=this_player();
        if(!userp(ob)){
        ob->move("/d/tianlong/gu");
        return;
        }
        add_action("do_zou","zou");
}

int do_zou(string arg)
{
  object me=this_player();
  
  if ( time()-me->query_temp("wuliang/qiao_time")<=60 )
  {
  	tell_object(me, "你已经在铁索上行走！\n");
  	return 1;
  }
  else
  {
  	tell_object(me, "你通过铁索走到了一处山谷中！\n");
  	me->move("/d/tianlong/gu");
  	return 1;
  }
}
