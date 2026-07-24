/* driftsand.c
 * from XO Lib
 * a room of desert
 * created by hydra 19980421
 * version: @(#) 1.0@(#)
 * last modified by hydra 19980421
 * 这里的函数主要完成流沙的功能*
 */


//在流沙中下沉的信息。
string * fall_msg = ({
    HIY"你只觉得你在慢慢下沉。。。。\n"NOR,
    HIY"你的双腿已经慢慢的被沙子埋住了。。\n"NOR,
    HIY"沙子已经盖到了你的腰部。。\n"NOR,
    HIY"你越陷越下，你的胸部以下都埋入了沙子，你感到呼吸越来越困难了。\n"NOR,
    HIY"沙子完全埋住了你的口鼻和眼。。\n"RED"你眼前一黑。。。\n"NOR,
});

//陷入流沙，在init里触发
void eventFall( object me )
{
    if (!me) return;
    if( random( me->query( "kar" ) ) > 20 )
        return;
    if( environment(me) != this_object() ) return;
    if( me->query_temp("hydra/desert/in_drift") ) return;
    message_vision( "$N突然陷入了流沙中。\n",me );
    me->disable_command( "verb","你身陷流沙之中，还是不要动弹的好。" );
    //me->set( "no_get",1 );
    //me->set( "no_get_from",1 );
    me->set_temp( "hydra/desert/in_drift",1 );
    call_out( "check_depth",5,me );
}

//在流沙中越陷越深的过程。。。
void add_depth( object me )
{
    int depth;
    if (!me) return;
    depth = me ->query_temp( "hydra/desert/depth" );
    
    if ( ! me->query_temp( "hydra/desert/in_drift" ) ) return;
    tell_object( me,fall_msg[depth] );
    me ->add_temp( "hydra/desert/depth",1 );
    if ( depth >= 4 )
    {
        me -> delete_temp( "hydra/desert/depth" );
        me -> delete_temp( "hydra/desert/in_drift" );
        me -> enable_path();
        me -> die();

    }

}

// 检查人是否完全被流沙淹没。
// 如果depth为5，则死亡
void check_depth( object me )
{
if (!me) return;
    add_depth( me );
    if (me)
{
    if( (int)me->query_temp( "hydra/desert/in_drift" ) )
        call_out( "check_depth",5,me );
}
}

// 在流沙中能做的动作
// jump: 跳出流沙，跟人的dodge有关
// drop: 丢掉身上的负重。
int do_jump( string arg )
{
    object me;
    int my_dodge_dengji,my_encum;
    me = this_player();
    my_dodge_dengji = me -> query_xiuwei_dengji( "dodge" );
    my_encum = me->query_encumbrance()*100/me->query_max_encumbrance();

    if ( arg ) return 0;
    if ( !me->query_temp( "hydra/desert/in_drift" ) ) return 0;
    if( my_encum <= my_dodge_dengji*10 )
    {
        message_vision( "$N一纵身从沙子中跳了出来。。。。。 \n",me );
        me ->enable_path();
        me ->delete_temp( "hydra/desert/in_drift" );
        me ->delete_temp( "hydra/desert/depth" );
        write( CYN"好不容易逃离了死亡，你现在还惊魂未定。。\n"NOR );
        me -> start_busy( 3 );
    }
    else
    {
        message_vision( "$N一纵身，想跳出流沙，却发现又陷入了一些。\n",me );
        add_depth( me );
    }
    return 1;
}

int do_drop(object me, object obj)
{
        mixed no_drop;

        if( no_drop = obj->query("no_drop") )
                return notify_fail( stringp(no_drop) ? no_drop : "这样东西不能随意丢弃。\n");

        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
                else
                {
                        message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")),
                                me, obj );
                        write(HIY"只见你丢下的东西，瞬间消失在流沙中！\n"NOR);
                        destruct(obj);
                }
                return 1;
        }
        return 0;
}

int ActionDrop( string arg )
{
        object obj, *inv, obj2;
        object me = this_player();
        int i, amount;
        string item;

        if(!arg) return notify_fail("你要丢弃什麽东西？\n");

        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, me)) )
                        return notify_fail("你身上没有这样东西。\n");
                if( stringp(obj->query("no_drop")) )
                        return notify_fail( (string)obj->query("no_drop") );
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开丢弃。\n");
                if( amount < 1 )
                        return notify_fail("东西的数量至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("你没有那麽多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() )
                        return do_drop(me, obj);
                else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        return do_drop(me, obj2);
                }
        }

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        do_drop(me, inv[i]);
                }
                write("Ok.\n");
                return 1;
        }

        if(!objectp(obj = present(arg, me)))
                return notify_fail("你身上没有这样东西。\n");
        return do_drop(me, obj);
}

