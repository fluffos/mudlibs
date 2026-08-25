// base.c for players by fire on 30/Jan/2000

inherit CMD;

private void main()
{
        string f_name;
        object ob;
        f_name=file_name(this_body()->query_room());
        if(f_name!="/a/huayin/vhall") {
                write("只有从草芦才能进入博物馆。\n");
                return;
        }

        this_body()->simple_action("$N到博物馆朝圣去了。\n");

     ob = load_object("/sgdomain/museum/yard");
         if(objectp(ob)) {
                        this_body()->move(ob);
                this_body()->do_game_command("look");
                        this_body()->other_action("$N进入了博物馆\n");
         }
     return;
}

