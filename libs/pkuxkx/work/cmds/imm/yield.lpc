#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ){
             if(me->query_temp("combat_yield")){
                  me->delete_temp("combat_yield");
                  tell_object(me, "你决定打架时还手反击。\n");
                  }
             else{
                  me->set_temp("combat_yield", 1);
                  tell_object(me, "你决定打架时打不还手。\n");
                  }
             }

        else if( arg == "yes"){ 
                  me->set_temp("combat_yield", 1);
                  tell_object(me, "你决定打架时打不还手。\n");
                  }
        else if( arg == "no"){
                  me->delete_temp("combat_yield");
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

