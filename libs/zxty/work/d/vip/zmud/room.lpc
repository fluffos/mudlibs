inherit ROOM;
void create()
{
    set("short", "太古虚境");
    set("long", @LONG
太古虚境! 
LONG
    );
    set("exits", ([
          "out" : "/d/taishan/fengchan",
    ]));

    set("no_new_clean_up", 0);
    set("no_magic", 1);
    set("objects",([
     "/d/vip/zmud/zmud" : 1,
     "/d/shaolin/npc/mu-ren" : 4,

    ]));

   set("no_sleep_room",1);

    setup();
}
void init()
{
        add_action("do_work", "reboot");
}
int do_work(string arg)
{
    string wiz_status;
    object *user, link_ob;
    int i;
    message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );
    user = ty_users();
    for(i=0; i<sizeof(user); i++) {
        if( !environment(user[i]) ) continue;
        user[i]->save();
        link_ob = user[i]->query_temp("link_ob");
        if( objectp(link_ob) ) link_ob->save();
    }
   NATURE_D->auto_shutdown(1);
    return 1;
}


