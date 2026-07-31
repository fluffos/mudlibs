// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
inherit ROOM;
  
mapping *sign=({
    ([  "name":"苏州",
        "id":"sz",
        "file":"/u/beyond/suzhou/yunhe",
        "value":10000
    ]),
    ([  "name":"扬州",
        "id":"yz",
        "file":"/u/beyond/yangzhou/matou",
        "value":5000
    ])
});

string look_sign();
int do_go(string);
    void create()
    {
        set("short", "码头");
set("long",@LONG
这里是慕容家的家仆和丫鬟出入太湖的水上码头，只见人们来来往往，
一个个风尘仆仆，码头边的老船夫见到你走过来，马上笑呵呵的迎了上去。
价格表(sign)。
LONG 
);
set("item_desc", ([
        "sign" : (: look_sign :)
    ]));
    set("outdoor", "abc");

    setup();
}

void init()
{
    add_action("do_go", "qu");
}

string look_sign()
{
    string str="";
    int i=sizeof(sign);

    while (i--) {
        str += sign[i]["name"];
        str += "(" + sign[i]["id"] + ") ";
        str += MONEY_D->price_str(sign[i]["value"]) + "\n";
    }

    return str;
}

void do_move(object ob, int i)
{
    ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
    object ob=this_player();
    int i=sizeof(sign);

    if (!arg) return 0;
    if (ob->is_busy() || ob->is_fighting())
        return notify_fail("你正忙着呢！\n");
    while(i--) {
        if (arg == sign[i]["id"]) {
            switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
                case 0:
                    return notify_fail("穷光蛋，一边呆着去！\n");
                case 2:
                    return notify_fail("有零钱吗？\n");
            }
            ob->start_busy(3);
            call_out("do_move", 3, ob, i);
            return 1;
        }
    }
    return notify_fail("你要去哪里？\n");
}
