inherit "path";
int load_exits();

string banghui_name = "$banghui_name";

void create()
{
    ::create();

    if (query("exits"))
    {
        foreach (string dir, string room in query("exits"))
        {
            set("exits/"+dir,replace_string(room,"/d/bangpai/map/",__DIR__));
        }
    }

    load_exits();
}

int load_exits()
{
    mapping new_exits = BANGHUI_D->query_banghui(banghui_name+"/new_exits/" + base_name(this_object()));


    if (!new_exits || !mapp(new_exits) || !sizeof(new_exits))
    return 0;

    foreach(string dir,string room in new_exits)
    {
        set("exits/"+dir,room);
    }

    return 1;
}