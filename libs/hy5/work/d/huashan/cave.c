// Room: /d/huashan/cave.c
// Date: Look 99/03/25

inherit ROOM;
void create()
{
        set("short", "密洞");
        set("long",@long
你走进来，发现石壁后面，别有洞天，是个可容得千人之众的大洞，洞中
有七具骸骨，或坐，或卧，身旁均有兵刃。山洞四壁离地数丈突出一块大石，
似是一个平台，大石之下刻着十六个大字(dazi)。你举起火把更往石壁上照看
时，只见一行字刻道：范松赵鹤破恒山剑法于此。这一行之旁是无数人形，粗
略一计，少说也有五六百个。
long);
        set("exits",([
        "right" : __DIR__"rukou",
]));
        set("item_desc",([
        "dazi" : "\t五岳剑派，无耻下流，比武不胜，暗算害人。又见十六个，大
字旁更刻了无数小字，都是些“卑鄙诬赖”、“可耻之极”、“低能”、
“懦弱”等等诅咒的字眼。\n",
        ]));
        set("indoors", "华山" );
        set("book_count", 1);
        setup();
}

void init()
{
        add_action("do_lingwu", "lingwu");
        add_action("do_ketou", "ketou");
}

int do_lingwu(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if( present("sword book", me)) {
        if( me->query_skill("sword" , 1) < 100 && me->query_skill("sword", 1) > 30 ) {
        write("你对着石壁上的图形领悟，觉得对你的基本剑法启发不少。\n", me);
        me->improve_skill("sword", (int)me->query("int")*3/2);
        me->receive_damage("jing", 15 + random((int)me->query_skill("sword" , 1) / 4));
        return 1; }         
        }
        if( present("staff book", me)) {
        if( me->query_skill("staff" , 1) < 101 && me->query_skill("staff", 1) > 50) {
        write("你对着石壁上的图形领悟，觉得对你的基本杖法启发不少。\n", me);
        me->improve_skill("staff", (int)me->query("int")*3/2);
        me->receive_damage("jing", 15 + random((int)me->query_skill("staff" , 1) / 4));
        return 1; }
        }
}

int do_ketou(string arg)
{
        object me, ob;
        me = this_player();
        ob = this_object();
        if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");

        if(!arg || arg =="" || arg !="skeleton")
        return notify_fail("你要干什么？\n");

        if(arg=="skeleton") {
        if( ob->query("book_count") < 1) {
        write("你跪在地上，对着骸骨虔诚的磕头。\n", me);
        return 1;
        }

        if( me->query_temp("ketou/骸骨", 1) == 30 ) {
        ob=new(__DIR__"obj/staff_book");
        if(!clonep(ob))
        return notify_fail("你累的躺到在地，什么也没有发生。\n");
        ob->move(me);
        message_vision("突然从骸骨中掉出一本书出来。\n", me);
        me->delete_temp("ketou/骸骨");
        this_object()->add("book_count", -1);
        return 1;
        }

        write("你跪在地上，对着骸骨虔诚的磕头。\n", me);
        me->add_temp("ketou/骸骨", 1);
        return 1; 
        }
        
}
