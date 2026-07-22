int valid_leave(object me, string dir)
{
  if(objectp(present("ma yigun", environment(me))))
               return notify_fail("马一棍闪身拦在你面前，喝道：想逃跑？给我滚回来！\n");

  if(objectp(present("lou lou", environment(me))))
//     && ob->query("target") == me
               return notify_fail("喽喽闪身拦住你的去路，看来是想把你给废了！\n");  

      return ::valid_leave(me, dir);
} 