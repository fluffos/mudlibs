// yandong.c 岩洞dong.c
// by llin
inherit ROOM;
void create()
{
        set("short", "岩洞");
        set("long",
"这是一个又窄又暗的小山洞，隐隐约约可以看到地上有一\n"
"摊血，旁边是一把长剑，剑刃上带着血迹。一个中年人贴着洞\n"
"壁斜躺着，仿佛身上带着很重的伤，不时发出一阵痛苦的呻吟\n"
"声。\n"
        );
        set("exits", ([
                "out" : __DIR__"taizi"
        ]));
        set_temp("mo_in",1);
        setup();
}
void init()
{       object me=this_player();
        object ob;
        if (interactive(me) && query_temp("mo_in"))
    {
        ob=new(CLASS_D("wudang") +"/mo");
        ob->move(__DIR__"yandong");
        message_vision("\n\n那躺在地上的中年人看到有人进来，拼命支起身子，断断续
续的说道：\n"
                        "“青书。。。你好狠。。。”话未说完便咽了气。\n",me);
        ob->die();
          me->set_temp("witness",1);
        this_object()->delete_temp("mo_in");
    }
}
