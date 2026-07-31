// mon 9/25/97
//snowtu 2009/06/06  for no_move cant remove
int valid_move(object me)
{
        if( me->over_encumbranced() )
                return notify_fail("你的负荷过重，动弹不得。\n");
        if( me->is_busy() )
                return notify_fail("你的动作还没有完成，不能移动。\n");
        if( me->is_no_move() )                
                return notify_fail("你被定住了，哪里动得了！"+sprintf("%d秒",me->is_no_move())+"\n");       
        return 1;
}

