// ouyang.h

int permit_recruit(object ob)
{
    object me;

    me = this_object();

    if( ob->query("detach/欧阳世家") || ob->query("betrayer/欧阳世家") )
    {
            command("say 既然离开了我们欧阳家，就不要回来了");
            return 0;
    }

    if (ob->query("name") == "欧阳锋" ||
        ob->query("name") == "欧阳克")
    {
        message_vision("$N大怒：我操！你起这个名字是什么意思啊？\n",me);
        return 0;
    }

    if (ob->query("purename") == "锋" ||
        ob->query("purename") == "克")
    {
        message_vision("$N大怒：我操！你起这个名字是什么意思啊？\n",me);
        return 0;
    }

    if( (ob->query("family/family_name") &&
        ob->query("family/family_name") != "欧阳世家") ||
        (ob->query("born_family") != "欧阳世家" && 
        ob->query("can_not_change") &&
        !ob->query("tianmo_jieti/times")) )
    {
        message_vision("$N对$n道：欧阳世家乃名门望族，不收外人，你另谋生路吧？\n",
                       me, ob);
        return 0;
    }
    return 1;
}

