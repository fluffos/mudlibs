// by fire on Jan 9 1998 barrel.c
#include <ansi.h>
inherit OBJ;
inherit M_GETTABLE;
inherit M_VALUE;
int isfill;
string short();
void setup() {
    set_adj("简陋的");
    set_id("mu tong", "木桶","barrel");
    set_unit("个");
    set_in_room_desc("一只农家浇地的木桶(mu tong)。");
    isfill=0;
    set_value(100);
    set_currency_type("coin");
}
string long()
{
    if(isfill)
    {
       return "一只农家浇地的木桶(mu tong)。\n"+
        "里面装满了水。\n";
    }
    return "一只农家浇地的木桶(mu tong)。\n";
}
mixed direct_fill_obj()
{
   return 1;
}
void fill_with(object with)
{
   string s_obj;
   if(isfill)
   {
      printf("%s已经满了。\n",short());
      return;
   }
   isfill=1;
   this_body()->simple_action("$N将"+short()+"装满了水。\n");
}
mixed direct_turn_obj()
{
        return 1;
}
int turn()
{
        object player;
        object room;
        object soil;
        int hp;
 	int stat;
        player = this_body();
        room = environment( player );
        if( !soil = present("tu di", room) )
        {
                write("你想把水浇在哪里？\n");
                return 1;
        }
 	stat=soil->query_status();
	if((stat<21)) {
		write("现在应该先锄锄地。dig soil with chu tou\n");
		return 1;
	}
	if(stat>40) {
        if(this_body()->query_job("digsoil","beg_time"))
        {
           this_body()->set_job("digsoil","status","done");
        }
		write("地已经搞好了，快去领钱吧。\n");
		return 1;
	}

        hp = player->query_cur_hp();    
        if( hp < 10 ){
                printf("你已经太累了，还是先休息一下再干吧。\n");
                return 1;
        }
        if( !isfill){
                printf("桶里的水用完了。\n");
                return 1;
        }
	if(soil->water())
	{
	        player->set_cur_hp( hp - 10);
		isfill=0;
	}
}
