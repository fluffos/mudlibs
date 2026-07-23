// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{

    if(me->is_busy())
        return notify_fail("你现在正忙。\n");

/*    if(me->query("combat_exp") < 500000)
{
me->delete_temp("combat_yield");
        return notify_fail("你的武学修为不够你这样!!\n");
}*/
	if( !arg ){
             if(me->query_temp("combat_yield")){
                  me->delete_temp("combat_yield");
                  tell_object(me, "你决定打架时还手反击。\n");
me->start_busy(1);
                  }
             else{
    if(me->is_fighting()) 
    {
        return notify_fail("你已经在打了！没办法再决定打不还手了！\n");
    }
                  me->set_temp("combat_yield", 1);
                  tell_object(me, "你决定打架时打不还手。\n");
                  }
             }

        else if( arg == "yes"){ 
    if(me->is_fighting()) 
    {
        return notify_fail("你已经在打了！没办法再决定打不还手了！\n");
    }
                  me->set_temp("combat_yield", 1);
                  tell_object(me, "你决定打架时打不还手。\n");
                  }
        else if( arg == "no"){
                  me->delete_temp("combat_yield");
me->start_busy(1);
                  tell_object(me, "你决定打架时还手反击。\n");
                  }

        else return notify_fail("你决定打架还手(yield no)还是不还手(yield yes)？\n");

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : yield <yes | no>
 
这个指令可以让你决定打架时是否还手反击。
 
HELP
    );
    return 1;
}
