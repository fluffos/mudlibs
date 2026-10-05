inherit ROOM;
void create()
{
            set("short","星际大酒店二楼");
            set("long",@LONG
这里就是星际大酒店的二楼了，从这里可以看到整个城市的市容。这里是许多人向往的地方
有许多人不顾一切也要来这工作，在这里工作就可以说是这一生都可以不愁了。这儿的周围有许多各式各样
的客人，有来自不同星球的不同的种族。当然，这儿的费用也是多得十分惊人的。这儿的老板据说是个
合成人，也从来没有人见过这儿的老板，究竟这儿的老板是谁，永远是个谜……
LONG);
          set("exits", ([
                         "down" : "/d/city/jiudian",
  "jana":"/d/city/playerhome/jana",
                         ]));
        setup();
}
void init()
{       
        add_action("do_quit","dazuo");
        add_action("do_quit","exercise");
        add_action("do_quit","xiuxing");
        add_action("do_quit","respirate");
        add_action("do_quit","yanjiu");

        add_action("do_quit","research");
        add_action("do_quit","practice");
        add_action("do_quit","lian");
        add_action("do_quit","du");
        add_action("do_quit","study");
        add_action("do_quit","learn");
}
int do_quit(string arg)
{
 write(this_player()->query("name")+"，干什么,当我这里练功场呀,滚出去！\n");
        return 1;
}

