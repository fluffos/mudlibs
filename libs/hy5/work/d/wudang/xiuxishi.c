// Room: xiuxishi.c 休息室
// By Marz

inherit ROOM;

void init();
void close_men();
int do_open(string arg);
int do_close(string arg);
int valid_leave(object me, string dir);

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。房里别无他物，
只有中间放着一张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG );
        set("no_clean_up", 0);
        set("sleep_room", 1);
        set("no_fight", 1);
	set("tan_count", 2);

        setup();
}

void init()
{
        add_action("do_open", "open");
        add_action("do_close", "close");
        add_action("do_zhao", "find");
        add_action("do_zhao", "zhao");

}

void close_men()
{
        object room;

        if(!( room = find_object(__DIR__"donglang2")) )
                room = load_object(__DIR__"donglang2");
        if(objectp(room))
        {
                delete("exits/south");
                        message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
                room->delete("exits/north");
                message("vision", "门吱吱呀呀地自己合上了。\n", room);
        }
}

int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("门已经是关着的了。\n");

        if (!arg || (arg != "men" && arg != "door"))
                return notify_fail("你要关什么？\n");

        message_vision("$N想把门关上。\n", this_player());

        remove_call_out("close_men");
        call_out("close_men", 2);

        return 1;
}

int do_open(string arg)
{
        object room;
        object me = this_player();
        if (query("exits/south"))
                return notify_fail("大门已经是开着了。\n");

        if (!arg || (arg != "men" && arg != "door" && arg != "south"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object(__DIR__"donglang2")) )
                room = load_object(__DIR__"donglang2");
        if(objectp(room))
        {
                set("exits/south", __DIR__"donglang2");
                message_vision("$N轻手轻脚地把门打开。\n", this_player());
                room->set("exits/north", __FILE__);

                if (me->query_temp("sleeped"))
                {
                message("vision", "吱地一声，"+me->query("name")+"精神焕发地从里
面把门打开了。\n",
                room);
                } else
                {
                message("vision", "梆地一声，"+me->query("name")+"从里面把门打开
，一脸的不耐烦。\n",
                         room);
                }

                remove_call_out("close_men");
                call_out("close_men", 10);
        }

        return 1;
}


int valid_leave(object me, string dir)
{
        object room;

        if ( !::valid_leave(me, dir) )
                return 0;

        if(!(room = find_object(__FILE__)) )
                room = load_object(__FILE__);
        if(objectp(room))
        {
                room->add_temp("person_inside", -1);
                if ((int)room->add_temp("person_inside", -1) <= 0)
                        room->delete_temp("person_inside");
        }

        return 1;
}

int do_zhao(string arg)
{       object tan;
        object me;
        me=this_player();
        if ( !arg || arg != "mao tan" )
            return notify_fail("你要找什么\n");
	if (present("mao tan", me))
	   return notify_fail("你找来找去，发现自己原来已经有了！\n");
	if (objectp(present("mao tan", environment(me))))
	   return notify_fail("地上就有，你还找什么？！\n");

        if (query("tan_count") > 0) 
          {
           message_vision("$N在床上翻来翻去找出一条毛毯。\n", me);
           add("tan_count", -1);
           tan=new(__DIR__"obj/maotan");
           tan->move(me);
          }
        else
           message_vision("$N在床上翻来翻去什么也没找着。\n", me);
     return 1;
}
