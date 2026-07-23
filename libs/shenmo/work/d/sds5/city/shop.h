void resets(object where) 
{
int dayphase = NATURE_D->query_current_day_phase();
if ( dayphase>5 )
        return;
else where->reset();
return;
}

void check(object where)
{
object *who;
int i,dayphase = NATURE_D->query_current_day_phase();
if ( !where ) return;
who = all_inventory(where);
if ( sizeof(who)<0 ) return;

if ( dayphase>5 )
        {
        for( i=0;i<sizeof(who);i++ )
                {
                if ( userp(who[i]) ) continue;
                tell_room(where,BLU+who[i]->name()+"一声嘶号，一股紫烟从身上冒出，消失不见了，这里果然古怪！\n"NOR);
                destruct(who[i]);
                }
        }
remove_call_out("check");
call_out("resets",300,where);
call_out("check",1,where);
}


void init()
{
remove_call_out("check");
call_out("check",1,this_object());
}


