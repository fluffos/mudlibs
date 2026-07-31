inherit ITEM;


void create()
{
        set_name("石刻棋盘", ({ "qi pan", "pan" }));
        set("long","这是一块刻在巨石上的棋盘，上面放着一些棋子。\n");
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("value", 1000);              
                set("no_get","这块棋盘是直接刻在岩石上的，无法拿取。\n");
                set("qizi",2);
        }
}

void init()
{
        add_action("do_get","get");
}

int do_get(string arg)
{
        object ob;
        string qizi,qipan;
        ob = this_player();
        if(arg == "qi pan" || arg == "pan" )
        {
                tell_object(ob,"这块棋盘是直接刻在岩石上的，无法拿取。\n");
                return 1;
        }
        if(sscanf( arg, "%s from %s", qizi, qipan)!=2)return 0;
        if((qizi !="qi zi" && qizi !="zi")
        ||(qipan!="qi pan" && qipan != "pan") )return 0;
        if(present("yi zhe",environment(this_object()) ) )
        {
                tell_object(ob,"别人正在下棋，怎么能把棋子拿走呢？\n");
                return 1;
        }
        if(query("qizi") <= 0 )
        {
                tell_object(ob,"棋子已经被别人拿光了。\n");
                return 1;
        }
        message_vision("$N从棋盘上拿下一把棋子。\n",ob);
        add("qizi",-1);
        new(__DIR__"qizi")->move(ob);
        return 1;
}
