//Writen by lnwm
//maowu.c
inherit ROOM;

void create()
{
        set("short", "小茅屋");
        set("long", @LONG
一间简陋的小茅屋,屋中的陈设简单而陈旧.进门右首有一口似乎早已
的不用的小灶，灶上放着一只已被烟熏得发黑的锅。房的另一个角落有一
张床,床上躺着一个老人.老人看见你进来，只微微睁了一下眼，就又闭上
了,一句话都没说.
LONG
        );
        set("exits", ([
            "southwest"     :       __DIR__ "lroad5",
                ]));
        set("objects", ([               
                 __DIR__ "npc/laoren": 1,
                ]) );
        setup();
}

void init()
{
        add_action("do_medicine",({"熬药","熬汤","make","make medicine"}));
}

int do_medicine()
{
        object ob1,ob2,ob3,ob4,ob5;
        object me;
        me = this_player();
        ob1 = present("luo bu",me);
        ob2 = present("jiang",me);
        ob3 = present("tang kuai",me);
    ob4 = present("gou qi",me);
        ob5 = present("lajiao you",me);

        if( ob1 && ob2 && ob3 && ob4 && ob5)
        {               
        message_vision("
\n$N细细地将姜快切成碎末，放进锅内。再加入萝卜块和糖，添上水，加火熬了起来。\n",me
                );
        destruct(ob1);
        destruct(ob2);
        destruct(ob3);
    destruct(ob4);
    destruct(ob5);
        call_out("give_medicine",random(5)+1,me);
        return 1;
        }
        return 0;
}

int give_medicine(object me)
{
        object medicine;
        if(me) 
        if(environment(me) == this_object())
        {
        medicine = new( __DIR__ "obj/jiangt");
        if(medicine->move(me))
        message_vision("
\n$N从锅里舀出一碗热气腾腾的姜汤\n",me);
        }
        return 1;
}

