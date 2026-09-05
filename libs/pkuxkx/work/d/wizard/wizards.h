int used_to_be_wiz(object me)
{
        string id = me->query("id");
        if(id == "pal" || id == "lbrei" || id == "whuan" || id == "mgjx")
                return 1;
        else
                return 0;
}
