#include <dbase.h>
#define MARKETPLACE "/d/city/chatroom"
#define SELLOR "/d/daniel/npc/paimai"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object room,obj;
        int argg;
        int invisibility_buyer;
        int number;
        int value;
        int zjb = me->query("zjb_money");

        seteuid( geteuid(me) );

//         if( me->is_busy() ) return notify_fail("你现在没有空！\n");
         if( me->query("doing") ) return notify_fail("闭关中不能出价！\n");
        if( !arg )
                return notify_fail("指令格式：bid <数量> for <拍卖号>\n");

        if( sscanf(arg, "-i %s", arg) ) invisibility_buyer = 1;

        if( !arg )
                return notify_fail("指令格式：bid <数量>\n");

        sscanf(arg,"%d for %d",argg,number);

//拍卖师放置的路径
        if( !(room=find_object(MARKETPLACE)) )
                room= clone_object(MARKETPLACE);
        
        if( !(obj=present("paimai shi",room)) )
        {
                obj=new(SELLOR);
                obj->move(MARKETPLACE);
                return notify_fail("拍卖师现在刚来，但没有在拍卖。\n");
        }

        else
        {
                if( !(obj->query("on_paimai")) ) 
                        return notify_fail("现在没有在拍卖。\n");
        }

        if( invisibility_buyer)
                me->set_temp("invisibility_buyer",1);
        else
                me->set_temp("invisibility_buyer",0);
    
        if(!number)
                number = obj->query("number");

        if(number>obj->query("number"))
                return notify_fail("目前还没有开始这件物品拍卖。\n");
//    if(obj->query("ipaimai/"+sprintf("%d",number))=="paimai shi")
        if(number<obj->query("number"))
           return notify_fail("这样东西的拍卖已经结束了。\n");
        
        value = obj->query("vpaimai/"+sprintf("%d",number));

        if( argg <= value )
        {
                tell_object(me,"你出价太低。\n");
                return notify_fail("现在是"+chinese_number(value)+"枚星空币！\n");
        }
    if(argg < 0 )
                return notify_fail("你出的价格是非法的。\n");
        if( argg > zjb )
                return notify_fail("你没有这么多的存款！\n");
        obj->report_paimai(me,argg,number);
        tell_object(me,"你出价"+chinese_number(argg)+"枚星空币！\n");

        me->start_busy(2);
      me->set_temp("on_paimai",1);//设置bid记录，防止quit;

        return 1;

}

int help(object me)
{
   write( @HELP
指令格式: bid <数量(星空币)> 

这一指令让你可以参与投标，单位为 星空币。
HELP
   );
   return 1;
}

