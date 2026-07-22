
int main(object me, string arg)
{
   object weapon;

   me = this_player();

   if( me->is_busy() )
   return notify_fail("你上一个动作还没有完成无法呼唤！\n");

   if ( arg == "weapon" ) { 
           if ( !me->query("weapon/make") )  
           return notify_fail("你没有自铸兵器，没办法呼唤。\n");

           if ( present(""+me->query("weapon/id")+"", this_player()) )
           return notify_fail("你的自铸兵器不是正在你身上吗?\n");
   
           if (me->query_temp("ty_huhuan")>time())
           return notify_fail("你离上次使用huhuan指令不到30秒,不能呼唤自己的自铸兵器。\n");
           me->set_temp("ty_huhuan",time()+30);

           weapon = "/adm/daemons/updated"->creat_weapon(me);
           weapon->move(me);

message_vision(HIG"只见"HIC"$N"HIG"眉头一皱，嘴巴飞快的念着什么咒语，四边天际变得一片"NOR WHT"天灰地暗"HIG"，\n"
  ""HIM"突然"HIG""HIW+me->query("weapon/name")+HIG"出现远方的空中，快速的飞到了"HIC"$N"HIG"的手中!!\n"NOR, me); 
           return 1;
                          }
}
   

   

