void init()
{
        object ob;
        ::init();
            add_action("convert","convert");
        if (
                interactive(ob = this_player()) &&
            (ob->query("shenlong/antisnake")<1) && !wizardp(ob) && ob->query("family/family_name")!="神龙教")
      {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
int convert(string arg)
{
        object me = this_player();
        object ob;

        if (arg!="snake" && arg!="she") return 0;
        if (me->query("family/family_name") != "白驼山") 
                return notify_fail("你不能化蛇为杖。\n");

        return notify_fail(this_object()->name()+"不适合化为蛇杖。\n");

}
/*
void kill_ob(object ob)
{
    object me = this_object();

    if( !ob || (environment(ob) != environment()) )
        return;

    this_object()->kill_ob(ob);
}
*/
/*
void die()
{
        object ob;
        message_vision("$N慢慢缩成一团，死了。\n", this_object());
        switch(random(3))
        {
                case 0:
                        ob = new("/d/shenlongdao/obj/sherou");
                        break;
                case 1:
                        ob = new("/d/shenlongdao/obj/shepi");
                        break;
                case 2:
                        ob = new("/d/shenlongdao/obj/shedan");
                        break;
        }
        ob->move(environment(this_object()));
//        destruct(this_object());
}

*/
/*
void unconcious()
{
die();
}

*/
