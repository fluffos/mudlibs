inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object link_ob;
   int cur_time;

   seteuid(getuid());

   if( !objectp(link_ob = me->query_temp("link_ob")) )
     return notify_fail("你不是经由正常连线进入，不能储存。\n");
     
    cur_time = time();
    if( (cur_time-me->query("last_backup")) < 600 )     
      return notify_fail("为了节省系统负担，10分钟之内只能备份一次。\n");
   
    me->set("last_backup", cur_time);
    
   if( (int)link_ob->save() && (int)me->save() && (int)me->backup()) {

         write("档案储存并备份完毕。\n");
        
     return 1;
   } else {
       write("档案备份失败，请联系巫师！\n");
     return 1;
   }
}

int help(object me)
{
   write(@HELP
指令格式：backup

备份档案。在你的档案遭受莫名其妙的伤害后，可要求巫师恢复。
HELP
   );
   return 1;
}

