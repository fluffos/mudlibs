void reset()
{
    int i;
    mapping all_obj;
    object old_obj, new_obj;
    string *obj_list, obj_name;

    all_obj = query("objects");
    obj_list = keys(all_obj);
    for(i = 0;i < sizeof(obj_list);i++)
    {
        obj_name = obj_list[i];
        if(!objectp(old_obj = present(obj_name->query("id"), this_object())))
        {
            if(random(10) > 6)
            {
                new_obj = new(obj_name);
                new_obj->move(this_object());
            }
        }
    }
}
