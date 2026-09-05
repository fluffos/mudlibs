
inherit ROOM;
void create()
{
        set("short", "玩家惩罚室");
        set("long", @LONG
这是一间用来惩罚违反玩家规则的玩家的房间。
四周黑洞洞的，隐隐约约你能看间一个木牌(mupai)。
这儿的人一个个愁眉苦脸，他们都被剥夺了政治权利。
LONG
        );
        set("item_desc",([
        "mupai"        :
 "     请仔细阅读help rules。\n"
 ]));
        set("valid_startroom",1);
        set("no_beg",1);
        set("no_steal", 1);
        set("no_fight",1);
           set("objects", ([ /* sizeof() == 1 */
          __DIR__"npc/guard" : 1,
]));
        setup();
}
void init()
{
        object ob = this_player();
 if( (int)ob->query_condition("punish") <= 0 )
        {
                message("vision",
           "只听牢房铁门匡地一响，一个家伙被摔了进来！\n\n" ,
                        environment(ob), ob);
                ob->set("startroom", "/d/wizard/punish_room");
                ob->apply_condition("punish", 30);
       }
		add_action("do_fly", "fly");
}

int do_fly(string arg)
{
return 0;
}
