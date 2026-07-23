// By Batman @ Freedom Studio 2001/6/6

inherit ROOM; 
#include <room.h> 
#include <ansi.h>
/*
string look_text(object me);
string look_drawing(object me);
string look_dragon(object me);
string look_tiger(object me);
string look_phoenix(object me);
string look_turtle(object me);
string look_bian(object me);
string look_door(object me);
string look_shelf(object me);

int draw, l, h, q, w, d, t, f, g; 
*/

void create() 
{ 
        set("short", HIC"天"HIR"仙"HIG"阁"NOR);
        set("long", @LONG
这是天下有敌的天仙阁，此处清新雅致，你的心境仿佛遨游于碧海蓝天

之上。墙上挂着一些字(text)画(drawing)，屋内的四根立柱上分别有着青
龙(dragon)，白虎(tiger)，朱雀(phoenix)，玄武(turtle)四盏石灯。屋子
中央的石台上有把剑没入其中，只有剑柄露在外面。屋子东面有块大匾(bian)。
西面有扇木门(door)，屋里还有好几排书架(shelf)。
LONG
        );
/*
        set("item_desc", ([sizeof() == 9 "text": (: look_text :),
        "drawing": (: look_drawing :),
        "dragon": (: look_dragon :),
        "tiger": (: look_tiger :),
        "phoenix": (: look_phoenix :),
        "turtle": (: look_turtle :),
        "bian": (: look_bian :),
        "door": (: look_door :),
        "shelf": (: look_shelf :),]));
*/
        set("exits", ([ /* sizeof() == 5 */
                "gumu" : "/d/gumu/damen",
                "taohua" : "/d/taohua/jcting2",
                "down" : "/d/wizard/wizard_room",
                "yangzhou" : "/d/city/ylting2",
                "south" : __DIR__"woshi",
        ]));
        set("objects", ([
            "/clone/money/1000-cash" : 1000,

                __DIR__"npc/maggie" : 1,
                __DIR__"npc/ada" : 1,
                __DIR__"npc/doma" : 1,
]) );

        set("no_clean_up", 1);
setup();
}
/*

void init()
{
        add_action("do_fire", "dian");
        add_action("do_putout", "xi") ;
        add_action("do_get", "ba") ;
        add_action("do_xian", "xian") ;
        add_action("do_plug", "plug") ;
        add_action("do_plug", "cha") ;
        add_action("do_plug", "insert") ;
        add_action("do_pick", "pick") ;
        add_action("do_pick", "na") ;
        add_action("go_maggie","zong");
        switch( random(6) )

        {       case 0 : draw=0;break;
                case 1 : draw=1;break;
                case 2 : draw=2;break;
                case 3 : draw=3;break;
                case 4 : draw=4;break;
                case 5 : draw=5;break;
        }
        switch( random(16) )
        {       case 0 : l=0;h=0;q=0;w=0;break;
                case 1 : l=0;h=0;q=0;w=1;break;
                case 2 : l=0;h=0;q=1;w=0;break;
                case 3 : l=0;h=0;q=1;w=1;break;
                case 4 : l=0;h=1;q=0;w=0;break;
                case 5 : l=0;h=1;q=0;w=1;break;
                case 6 : l=0;h=1;q=1;w=0;break;
                case 7 : l=0;h=1;q=1;w=1;break;
                case 8 : l=1;h=0;q=0;w=0;break;
                case 9 : l=1;h=0;q=0;w=1;break;
                case 10 : l=1;h=0;q=1;w=0;break;
                case 11 : l=1;h=0;q=1;w=1;break;
                case 12 : l=1;h=1;q=0;w=0;break;
                case 13 : l=1;h=1;q=0;w=1;break;
                case 14 : l=1;h=1;q=1;w=0;break;

                case 15 : l=1;h=1;q=1;w=1;break;
        }
        switch( draw )
        {       case 0 : f = q; g = w;
                switch (l)
                {case 0 : d = 1;break;case 1 : d = 0;break;}
                switch (h)
                {case 0 : t = 1;break;case 1 : t = 0;break;};break;
                case 1 : t = h; g = w;
                switch (l)
                {case 0 : d = 1;break;case 1 : d = 0;break;}
                switch (q)
                {case 0 : f = 1;break;case 1 : f = 0;break;};break;
                case 2 : t = h; f = q;
                switch (l)
                {case 0 : d = 1;break;case 1 : d = 0;break;}
                switch (w)
                {case 0 : g = 1;break;case 1 : g = 0;break;};break;
                case 3 : d = l; g = w;
                switch (h)
                {case 0 : t = 1;break;case 1 : t = 0;break;}
                switch (q)
                {case 0 : f = 1;break;case 1 : f = 0;break;};break;

                case 4 : d = l; f = q;
                switch (h)
                {case 0 : t = 1;break;case 1 : t = 0;break;}
                switch (w)
                {case 0 : g = 1;break;case 1 : g = 0;break;};break;
                case 5 : d = l; t = h;
                switch (q)
                {case 0 : f = 1;break;case 1 : f = 0;break;}
                switch (w)
                {case 0 : g = 1;break;case 1 : g = 0;break;};break;
        }
        
}


string look_text(object me)
{
        return HIG"        晒\n        不\n好      干\n。      的\n\n不  关  拖\n躲  于  泥\n。  你  和\n    的  带\n    记  水\n    忆  的\n\n    如\n    雨\n    直\n    下\n    |\n"NOR;
}

string look_bian(object me)
{
        return HIY"****************\n*  "HIG"阁  "HIR"仙  "HIC"天  "HIY"*\n****************\n"NOR;

}

string look_door(object me)
{
        if (!query("exits/west"))
                return "这是一扇很厚的木门，你推了推，发现根本推不开。\n";
        else return "这扇木门很厚，不知道里面是哪里。\n";       
}

string look_shelf(object me)
{
        if (!query("exits/west"))
                return "书架上摆满了书，第三层上似乎缺了一本。\n";
        else return "书架上摆满了书。\n";       
}

string look_drawing(object me)
{
       switch (draw)
        { case 0 : return HIY"这是一幅龙腾虎跃图。\n"NOR;       break;
        case 1: return HIY"这是一幅龙凤呈祥图。\n"NOR;break;
        case 2: return HIY"这是一幅龙腾四海图。\n"NOR;break;
        case 3: return HIY"这是一幅画，画的是百兽之王与百鸟之王。\n"NOR;break;

        case 4: return HIY"这是一幅画，画的是猛虎斗玄龟，奇怪的作品。\n"NOR;break;
        case 5: return HIY"这是一幅画，画的是乌龟与凤凰，有没有搞错？\n"NOR;break;}
}

string look_dragon(object me)
{
       switch (d)
        { case 0 : return HIC"这是一盏雕有青龙头的石灯，龙口里的灯芯灭了。\n"NOR; break;
        case 1: return HIC"这是一盏雕有青龙头的石灯，龙口里的灯芯燃着。\n"NOR;  break;}

}
string look_tiger(object me)
{
       switch (t)
        { case 0 : return HIW"这是一盏雕有白虎头的石灯，虎口里的灯芯灭了。\n"NOR; break;
        case 1: return HIW"这是一盏雕有白虎头的石灯，虎口里的灯芯燃着。\n"NOR;  break;}

}
string look_phoenix(object me)
{
       switch (f)
        { case 0 : return HIR"这是一盏雕有朱雀头的石灯，鸟嘴里的灯芯灭了。\n"NOR; break;
        case 1: return HIR"这是一盏雕有朱雀头的石灯，鸟嘴里的灯芯燃着。\n"NOR;  break;}


}
string look_turtle(object me)
{
       switch (g)
        { case 0 : return HIB"这是一盏雕有玄武头的石灯，龟口里的灯芯灭了。\n"NOR; break;
        case 1: return HIB"这是一盏雕有玄武头的石灯，龟口里的灯芯燃着。\n"NOR;  break;}

}

int do_fire(string arg)
{
        object me;
        me = this_player();
        if ( !arg || ( ( arg != "dragon") && ( arg != "tiger") && ( arg != "phoenix") && ( arg != "turtle") ) )
                return notify_fail ("你要点什么？\n");
        if (arg == "dragon")
        {
                if (d == 1) 
                        return notify_fail ("这盏灯原本就亮着。\n");
                else
                {
                        message_vision (HIC"$N取出火折，将青龙灯点燃。\n"NOR, me);

                        d = 1;
                        return 1;
                }
        }
        else if (arg == "tiger")
        {
                if (t == 1)
                        return notify_fail ("这盏灯原本就亮着。\n");
                else
                {
                        message_vision (HIW"$N取出火折，将白虎灯点燃。\n"NOR, me);
                        t = 1;
                        return 1;
                }
        }
        else if (arg == "phoenix")
        {
                if (f == 1)
                        return notify_fail ("这盏灯原本就亮着。\n");
                else
                {
                        message_vision (HIR"$N取出火折，将朱雀灯点燃。\n"NOR, me);
                        f = 1;

                        return 1;
                }
        }
        else if (arg == "turtle")
        {
                if (g == 1)
                        return notify_fail ("这盏灯原本就亮着。\n");
                else
                {
                        message_vision (HIB"$N取出火折，将玄武灯点燃。\n"NOR, me);
                        g = 1;
                        return 1;
                }
        }       
        return 1;
}

int do_putout(string arg)
{
        object me;
        me = this_player();
        if ( !arg || ( ( arg != "dragon") && ( arg != "tiger") && ( arg != "phoenix") && ( arg != "turtle") ) )
                return notify_fail ("你要干什么？\n");

        if (arg == "dragon")
        {
                if (d == 0)
                        return notify_fail ("这盏灯已经灭了。\n");
                else
                {
                        message_vision (HIC"$N将青龙灯熄灭了。\n"NOR, me);
                        d = 0;
                        return 1;
                }
        }
        else if (arg == "tiger")
        {
                if (t == 0)
                        return notify_fail ("这盏灯已经灭了。\n");
                else
                {
                        message_vision (HIW"$N将白虎灯熄灭了。\n"NOR, me);
                        t = 0;
                        return 1;
                }
        }
        else if (arg == "phoenix")

        {
                if (f == 0)
                        return notify_fail ("这盏灯已经灭了。\n");
                else
                {
                        message_vision (HIR"$N将朱雀灯点熄灭了。\n"NOR, me);
                        f = 0;
                        return 1;
                }
        }
        else if (arg == "turtle")
        {
                if (g == 0)
                        return notify_fail ("这盏灯已经灭了。\n");
                else
                {
                        message_vision (HIB"$N将玄武灯熄灭了。\n"NOR, me);
                        g = 0;
                        return 1;
                }
        }       
        return 1;
}


int do_get(string arg)
{
        object me, ob, room;
        me = this_player();
        if(!( room = find_object("/u/batman/woshi")) );
                room = load_object("/u/batman/woshi");
        if ( !arg || ( arg != "sword") )
                return notify_fail ("你要拔什么？\n");
        if ( ( d != l ) || ( t !=h ) || ( f != q ) || ( g != w ) )
                return notify_fail ("你使出了吃奶的力气，还是无法把剑拔出。\n");
        if((sizeof(children("/u/batman/obj/skysword"))>1) || (sizeof(children("/u/batman/obj/qksword"))>1) || (room->query("hole") == 2))
                message_vision ("$N拔出一柄生锈的铁剑来，$N叹了口气又把它插回原处。\n"NOR, me);
         else
        {
                message_vision (HIC"突然间，窗外的天空中打了个霹雳，$N已将石台上的古剑拔了出来。\n"NOR, me);
                ob=new(__DIR__"obj/skysword");
                ob->move(me);
        }
return 1;
}

int do_xian(string arg)

{
        object me, ob, room;
        me = this_player();
        if(!( room = find_object("/u/batman/woshi")) );
                room = load_object("/u/batman/woshi");
        if ( !arg || ( arg != "text") )
                return notify_fail ("你要掀什么？\n");
        if ( ( d != l ) || ( t !=h ) || ( f != q ) || ( g != w ) )
                return notify_fail ("不行，字画会弄坏的。\n");
        if((sizeof(children("/u/batman/obj/groundsword"))>1) || (sizeof(children("/u/batman/obj/qksword"))>1) || (room->query("hole") == 2))
                message_vision ("$N掀起字画，背后什么也没有，$N觉得好失望。\n"NOR, me);
        else
        {
                message_vision (MAG"突然间，大地微微地震了一下，$N在字画后面找到一把古剑。\n"NOR, me);
                ob=new(__DIR__"obj/groundsword");
                ob->move(me);
        }
return 1;
}

int go_maggie(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "bian") )
                return notify_fail ("你要干什么？\n");
        else
        {
                int mo = this_player()->query_skill("dodge");
                if ( mo >= 10 )
                {
                        message_vision ("$N轻飘飘腾身数丈，落在匾后。\n",me);
                        tell_room(__DIR__"bian", me->query("name")+"纵了上来。\n");
                        me->move(__DIR__"bian");
                }
                else message_vision ("$N使劲儿住上一蹦，结果摔了个狗吃屎。\n",me);
        }
        return 1;
}

int do_plug(string arg)
{
        object me, obj;
        string item, target;
        me = this_player();
        if (!arg || (sscanf(arg, "%s on %s", item, target)!=2 ))

                return notify_fail ("你要插什么在什么上？\n");
        if ((item != "book") || (target != "shelf"))
                return notify_fail ("你要插什么在什么上？\n");
        if (! obj = present (item, me))
                return notify_fail("你身上没有这样东西。\n");
        if (obj->query("name") != HIY"小说书"NOR)
                return notify_fail("这本书太厚了，放不进。\n");
        if (query("exits/west"))
                return notify_fail("已经放不下了。\n");
        message_vision("$N将$n放在了书架的空位上，木门竟然开了。\n", me, obj);
        set("exits/west", __DIR__"ada/workroom");
        destruct(obj);
        return 1;
}

int do_pick(string arg)
{
        object me, obj;
        me = this_player();
        if(!arg || (arg != "book"))
                return notify_fail("你要做什么？\n");
        if ((sizeof(children("/u/batman/maggie/obj/book")) > 1) || (!query("exits/west")))
                message_vision("$N从书架上取下一本书，原来是本字典，$N又放了回去。\n", me);

        else
        {
                obj = new(__DIR__"maggie/obj/book");
                message_vision("$N从书架上取下一本书，西面的木门突然合上了。\n", me);
                obj->move(me);
                delete("exits/west");
        }
        return 1;
}

*/
