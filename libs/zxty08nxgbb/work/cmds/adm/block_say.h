//snow@jhfy
int block_say(object me)
{               int time,count,last_say;


                time=time();
                if(me->query("channel/say_block") &&
                  (time-me->query("channel/say_block"))<0 ) {
                   write("你的舌头正疼得厉害。\n");
                   return 0;
                }
              
                count=me->query("channel/say_count");
                count++;
                last_say=me->query("channel/last_say");
                if (count>3) {
                  count=0;
                  me->set("channel/last_say",time);
                  if (time==last_say) {
                    me->set("channel/say_block",time+180);
                    write("你一次讲话太多太快，不小心咬到了舌头，暂时没法说话了！\n");
                    return 0;
                  }
                }
                me->set("channel/say_count",count);
                return 1;
}


