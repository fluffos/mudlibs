// houting.c 后厅
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
        set("short", "后厅");
        set("long", @LONG
这里是古墓的后厅，密封得严严实实，没有一丝的缝隙。在昏暗
的灯光下，你发现墙上悬挂着一幅画 (picture)，似乎是一幅人物的
肖像。在厅的中央，摆放着几具棺材(coffin)，其中只有一具棺材的
棺板没有合上，棺材中好象空空如也。正前方写着一行大字（zi），
东西两壁都挂着一幅画。西首 (westpic)的画像是两个女郎，正是古
墓派的师尊林朝英和师祖婆婆的肖像，东侧（eastpic）画像中却是一
个道士。
LONG
        );

        set("exits", ([
                "north" : __DIR__"zhengting",
                "east" : __DIR__"gmqs",
        ]));

        set("item_desc", ([
               "westpic" : HIM"画中两个姑娘，一个二十五六岁，正在对镜梳妆，画中镜里映出女郎容貌极美，
秀眉入鬓，眼角却隐隐带着一层杀气，正是古墓派师尊林朝英。另一个是十五
六岁的丫鬟，手持面盆，在旁伺候，憨态可掬，满脸稚气，后来便成了小龙女
的师傅。\n"NOR,
               "eastpic" : HIC"像中道人身材甚高，腰悬长剑，右手食指指着东北角，只是背脊向外，面貌却
看不见。\n"NOR,
               "zi" : HIR"\t入我古墓，先唾重阳，欲成神功，拜我祖师。\n"NOR,
        "picture": "画中是一个中年道士的背影，看不出什么相貌，画中人一手指天，画
角题着‘"+MAG"活死人像"NOR+"’几个大字。\n",
        "coffin": "用厚厚的石板做成的棺材，棺板合上后，就没有一丝的缝隙了。\n"
        ]) );

        set("getbook",1);

        setup();
        //replace_program(ROOM);
}

void init()
{
         add_action("do_ketou", "ketou"); 
         add_action("do_tuo", "tuo");
        add_action("do_tang", "tang");
        add_action("do_niu", "niu");
}

int do_tang(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "coffin" ) {
                return notify_fail("你要躺在哪儿？\n");
        }

        if (query("getbook")>0) {
        message_vision("$N躺进棺材中，把棺板合上，顿时一片黑暗，似乎与红尘隔绝了，\n",this_player());
        message_vision("摸索中$N似乎发觉棺板内壁题着有字，细细摸来，好象一头写着\n", this_player());
        message_vision("‘"+HIW"玉女心经，技压全真；重阳一生，不输与人"NOR+"’这样十六个大字，\n", this_player());
        message_vision("另一头好象是一些图形之类的符号。$N不知所以，心想管他的先\n", this_player());
        message_vision("拓下来再说，于是脱下身上布衫，细细地将板上文字全部拓了下\n", this_player());
        message_vision("来。正在拓字之间，似乎摸到棺角上有一块凸起的机关(lock)。\n", this_player());

        if (random(21)>10)
                ob=new("/clone/book/jiuyin2");
        else
                ob=new("/clone/book/jiuyin1");
        ob->move(me);
        add("getbook",-1);
        }
        else {
        message_vision("$N躺进棺材中，把棺板合上，顿时一片黑暗，似乎与红尘隔绝，\n",this_player());
        message_vision("摸索中$N似乎发觉棺板内壁以前刻着有字，不过这字迹已经被人\n", this_player());
        message_vision("故意刮掉了。突然间，似乎摸到棺角上有一块凸起的机关(lock)。\n", this_player());
        }

        me->set_temp("tmarks/棺",1);
        return 1;
}

int do_niu(string arg)
{
        object me=this_player();

        if( !arg || arg != "lock" || me->query_temp("tmarks/棺",1)<1) {
                return notify_fail("你要扭动什么？\n");
        }

        message_vision("$N手握机关，轻轻向下扭动，忽然间棺底吱吱作响，裂开了一个
\n",this_player());
        message_vision("大洞，$N向洞中落了下去。\n", this_player());
        me->move(__DIR__"mishi2");

        me->set_temp("tmarks/棺",0);
        return 1;

}

 
int do_ketou(string arg)
{
          mapping fam;
          object me = this_player();
          object key;

        if ((!arg) || (arg != "westpic")) return 0;
          message_vision("$N向西跪倒，双膝及地，恭恭敬敬向祖师婆婆的画像磕了一个响头. \n", me);
          me->add_temp("marks/ketou", 1);
        if (me->query_temp("marks/tuo") == 2 && me->query_temp("marks/ketou") == 4
          && (!(fam = me->query("family")) || fam["family_name"] != "古墓派") && me->query("combat_exp") < 10000){
          me->set("family/family_name", "古墓派");
          me->set("title", HIW"古墓传人"NOR);
          me->create_family("古墓派", 5, "传人");
          write(HIR"恭喜你自愿成为一名古墓弟子。\n"NOR);
          me->delete_temp("marks/tuo");
          me->delete_temp("marks/ketou");
          return 1;
          }
     return 1;
}

int do_tuo(string arg)
{
           object me = this_player();
           if (me->query_temp("marks/tuo") == 2)
             return notify_fail("你唾够了没有？\n");
           if ( arg=="eastpic"){
           message_vision("$N朝王重阳的画像狠狠唾了一口. \n", me);
           me->add_temp("marks/tuo", 1);
           return 1;
           }
          return notify_fail("你不要随便乱唾口水啊！\n");
}
