int accept_object(object me,object ob)
{
if ( ob->query("id")=="tong xing zheng" )   //通行证
        {
        if ( !ob->query("sign") )       //签名
                {
                say(CYN+name()+"摇了摇头，没签过名的通行证等于废纸一张！\n"NOR);
                tell_object(me,"赶紧去找工会首领签名吧。\n");
                return 0;
                }
        if ( ob->query("属性")!=query("属性") )
                {
      say(CYN+name()+"摇了摇头，你这张只能去"+ob->query("属性")+"区！\n"NOR);
                return 0;
                }
        me->set_temp("guard_gived/"+query("属性"),1);
        me->save();
        return 1;
        }
say(CYN+name()+"摇了摇头：没通行证，是不得出城的。\n"NOR);
tell_object(me,"赶紧去找工会首领要通行证吧。\n");
return 0;
}

void init()
{
add_action("do_none","go");
}

int do_none(string arg)
{
object me = this_player();
if ( arg==query("back") )
   return 0;
if ( !me->query_temp("guard_gived/"+query("属性")) )
    {
    say(CYN+name()+"摇了摇头：没通行证者不得擅自出城！\n"NOR);
    return 1;
    }
return 0;
}
