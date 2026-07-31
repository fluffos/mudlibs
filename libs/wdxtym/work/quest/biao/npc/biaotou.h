void destroying(object me)
{
        destruct(me);
        return;
}
int checking(object me, object ob)
{
        if((int)time() > this_object()->query("temp_time"))
        {
                  call_out("destroying",1,me);
                  return 1;
        }
        else
        {
                 call_out("checking",120, me, ob);
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