void init()
{
       remove_call_out("leave");
        call_out("leave",10);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "强盗撤了出去，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",15);
}
void destroying(object me)
{
        destruct(me);
        return;
}
int checking(object me, object ob)
{
if(!me)
return 1;
if(!ob)
return 1;

        if((int)me->query("qi")* 100 / (int)me->query("max_qi") <= 10){
                if (!living(me)) return 1;
                 else {
                  message_vision(CYN"\n$N叫道：点子扎手，扯呼！\n\n$N个起纵遁入暗里不见了。\n\n"NOR,me);
                  destruct(this_object());
                  return 1;
                 }
        }

        if (me->is_fighting()) 
        {
                call_out("checking",1, me, ob);
                return 1;
        }

        if ( !present(ob->query("id"), environment()) && present("biao che",environment()) )
           {  
                command("laugh");
                command("jie biao che");
                message_vision("$N推着镖车呼啸而去。\n", me);
                call_out("destroying",1,me);
                return 1;
        }
        if (!present(ob->query("id"), environment()))
          {
              message_vision("$N悻悻的说：“算你跑的快！”\n",me);
              command("sigh");
              message_vision("$N身行几起几纵消失在暗处\n",me);
              call_out("destroying",1,me);
              return 1;
          }
             
}


void die()
{
        object ob, me, corpse;
        
        ob = this_object();
message_vision("$N「啪」地一声倒在地上，嘴角溢出几丝鲜血，痛苦的挣扎了几下就死了。\n", ob);
        destruct(ob);
        return;
}