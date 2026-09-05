#include <ansi.h>

void init()
{
    add_action("do_enter","say");
    add_action("do_enter","'");
}

int is_guider_base()
{
    return 1;
}

int do_enter(string arg)
{
    object room,me=this_player();
    object real=load_object("/d/parties/public/obj/real");
    mapping *ent;
    int i,index=-1;
    real->restore();
    ent=real->real_estate();
    for (i=0;i<sizeof(ent);i++)
    {
        if (ent[i]["file"]==base_name(this_object()))
        {
            index=i;
        }
    }
    if (index<0)
    {
        if (me->query("id")=="zine")
        {
            tell_object(me,"index为负！\n");
        }
        return 0;
    }
    if (!room=load_object(ent[index]["entry"]))
    {
        tell_object(me,"新手基地出错，请联系ZINE解决！\n");
        return 1; 
    }
    if (arg!=ent[index]["entry_code"])
    {
        if (me->query("id")=="zine")
        {
            tell_object(me,"口令错误！正确口令为"+ent[index]["entry_code"]+"\n");
        }
        return 0;
    }
    if (me->query("id")=="zine")
    {
        tell_object(me,index+"\t"+ent[index]["entry"]+"\n");
    }
    if (time() - me->query("killer/time") < 15*60)
    {
        tell_object(me,"人在江湖，杀了人岂能一躲了之?\n");
        return 1; 
    }    
    
    if (!room->valid_access(me)&&!room->owner_access(me)&&!room->old_student(me))
    {
        if (room->deny_access(me))
        {
            message_vision(WHT+"$N"+WHT+"神道神道地念念有词：“"+HIC+"*****"+WHT+"”，大宅子里的人看了你一眼，紧紧关上了门！\n"+NOR,me);
            write("即使念出了"+arg+"，大宅子里的人却并不理你！\n");
            return 1;
        }
        message_vision(WHT+"$N"+WHT+"神道神道地念念有词：“"+HIC+"*****"+WHT+"”，大宅子里的人看了你一眼，让开了大门：原来是主人的贵客！\n"+NOR,me);
        write("你故意将"+arg+"念得含混不清，旁的人无法听去。\n");
        tell_room(room,me->query("name")+"从"+this_object()->query("short")+"走了进来！\n");
        me->move(room);
        tell_object(me,"你来到了"+room->query("short")+"。\n");
        return 1;
    }
    else
    {
        message_vision(HIC+"$N"+HIC+"吐气扬声地念道：“"+WHT+"*****"+HIC+"”，大宅子里的人打开了门，让你走了进去。\n"+NOR,me);
        write("你故意将"+arg+"念得含混不清，旁的人无法听去。\n");
        tell_room(room,me->query("name")+"从"+this_object()->query("short")+"走了进来！\n");
        me->move(room);
        tell_object(me,"你来到了"+room->query("short")+"。\n");
        return 1;
    }
}