#include <ansi.h>

#include "/d/parties/public/change_name.h"
#include "/d/parties/public/building.h"

int do_write(string arg)
{
    object pl,me=this_player();
    string name,*names;
    object ct=load_object(__DIR__"biguanchu");
    int i;
    if (!owner_access(me))
    {
        tell_object(me,"你不是此间主人，无法在石碑上刻字！\n");
        return 1;
    }
    if (!sizeof(me->query("guider/old_apps")))
    {
        tell_object(me,"你一个学生也没有毕业，刻什么刻？自欺欺人吗？\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要刻上哪个毕业学生的名字？\n");
        return 1;
    }
    if (sscanf(arg, "%s", name)!=1)
    {
        tell_object(me,"你要刻上哪个毕业学生的名字(id)？\n");
        return 1;
    }
    if (member_array(name,me->query("guider/old_apps"))<0)
    {
        tell_object(me,"你并没有过这个学生！\n");
        return 1;
    }
    if (find_player(name))
    {
        pl=find_player(name);
    }
    else
    {
        tell_object(me,"你必须找"+name+"在线的时候，共同刻下他的名字！\n");
        return 1;
    }
    if (!present(pl,this_object()))
    {
        tell_object(me,"你的这个学生不在这里，必须你们都在的时候才可以在石碑上刻字！\n");
        return 1;
    }
    if (!userp(pl))
    {
        tell_object(me,name+"真是你的学生？\n");
        return 1;
    }
    ct->restore();
    for (i=0;i<sizeof(ct->query("graduate"));i++)
    {
        if (ct->query("graduate/"+i+"/id")==pl->query("id"))
        {
            tell_object(me,pl->query("name")+"已经被记录在这块石碑上了！\n");
            return 1;
        }
    }
    message_vision("$N郑重地将"+pl->query("name")+"的名字刻上了石碑！\n",me,pl);
    i=sizeof(ct->query("graduate"));
    ct->set("graduate/"+i+"/id",pl->query("id"));
    ct->set("graduate/"+i+"/name",pl->query("name"));
    ct->save();
    return 1;
}
string look_bei()
{
    object ct,me=this_player();
    string msg;
    object real=load_object("/d/parties/public/obj/real");
    int i,index=-1;
    mapping *ent;
    real->restore();
    ent=real->real_estate();
    for (i=0;i<sizeof(ent);i++)
    {
        if (ent[i]["file"]==this_object()->query("base"))
        {
            index=i;
        }
    }
    if (index<0)
    {
        return "";
    }
    ct=load_object(__DIR__"biguanchu");
    if (owner_access(me))
    {
        tell_object(me,HIR+"你是此间的主人，你可以使用write命令，增加石碑上的名录！\n"+NOR);
    }
    msg="这是一块巨大的石碑：\n";
    msg+="上书：创始者\t"+HIY+ent[index]["owner_name"]+"\n"+NOR;
    
    if (!ct)
    {
        return msg;
    }
    else
    {
        if (!sizeof(ct->query("graduate")))
        {
            return msg;
        }
        else
        {
            msg+=HIC+"----------------------------------\n"+NOR;
            msg+="此间毕业的学生名录：\n";
            for (i=0;i<sizeof(ct->query("graduate"));i++)
            {
                msg+=sprintf(WHT"%-12s"NOR,ct->query("graduate/"+i+"/name"));
				if (i%5==0&&i!=0)
				msg+="\n";
				
            }
            msg+="\n";
            return msg;
        }
    }
}
