void check_owner();
void destroy(object ob);

void init()
{
        check_owner();
}


void check_owner()
{
        object ob =this_object();
        object me =environment(ob);
if ( !me->query("12gongs/all") && !wizardp(me))
       call_out("destroy", 0, ob, me);                       
//           destroy(ob);
}
void destroy(object ob)
{
        write(ob->query("name")+"呼的不见了！ \n");
        destruct(ob);
        return;
}
