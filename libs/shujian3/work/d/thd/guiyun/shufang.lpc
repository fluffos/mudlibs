// Room: /u/jpei/guiyun/shufang.c
// Modify By River@SJ 99.09
inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这里是庄主平日读书的地方。屋中琳琅满目，全是诗文典籍；几上桌上摆
着许多铜器玉器，看来尽是古物。壁上挂着一幅水墨画(hua)。 房内另有一张
竹榻，一位身材高大的中年人正坐在榻上。
LONG
        );

        set("exits", ([
                "west" : __DIR__"houting",
        ]));

        set("item_desc",([
                "hua" : "
那上面画的是一个中年书生在月明之夜中庭伫立，手按剑柄，仰天长吁，神情寂寞。
画的左下角题着一首词：\n
\t\t昨夜寒蛩不住鸣。
\t\t惊回千里梦，已三更。
\t\t起来独自绕阶行。
\t\t人悄悄，帘外月胧明。
\t\t白首为功名。
\t\t旧山松竹老，阻归程。
\t\t欲将心事付瑶筝，知音少，弦断有谁听？\n
\t\t\t\t\t下款题着“五湖废人病中涂鸦”八字。\n
"
        ]) );

        set("objects", ([
                __DIR__"npc/lucf": 1,
		MEDICINE_D("jiuhuawan") : 1,
		"/d/music/obj/flute-book" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_look","look");
        add_action("do_zhai",({"zhai", "qu"}));
}

int do_look(string arg)
{
        object me;
        me = this_player();
        if(me->query_temp("thd/bagua") || present("tie bagua",me)){
        set("long", @LONG
这里是庄主平日读书的地方。屋中琳琅满目，全是诗文典籍；几上桌上摆
着许多铜器玉器，看来尽是古物。壁上挂着一幅水墨画(hua)。 房内另有一张
竹榻，一位身材高大的中年人正坐在榻上。
LONG
);
        me->look(arg);
        }
        else {
        if (!arg) {
        set("long", @LONG
这里是庄主平日读书的地方。屋中琳琅满目，全是诗文典籍；几上桌上摆
着许多铜器玉器，看来尽是古物。壁上挂着一幅水墨画(hua)。 房内另有一张
竹榻，一位身材高大的中年人正坐在榻上。你猛一抬头，忽见书房门楣之上钉
着八片铁片，排作八卦形状，却又不似寻常的八卦(bagua)那么排得整齐，疏
疏落落，歪斜不称。
LONG
        );
        me->look(arg);
        }
        else if(arg == "bagua") {
          write("八片铁片，排作八卦形状，却又不似寻常的八卦那么排得整齐，疏疏落落，歪斜不称。\n");
          me->set_temp("thd/bagua_look", 1);
          return 1;
          }
       }                
}

int do_zhai(string arg)
{
       object me, ob,*clone ;
       int i,j;
       mapping fam;
       me = this_player();
       fam = me->query("family");
       if( !me->query_temp("thd/bagua_look")) return 0;
       if (!arg || (arg != "bagua"))
              return notify_fail("你要摘什么啊？\n");
       if (me->is_busy() || me->is_fighting())
              return notify_fail("你正忙着哪！\n");
       if(!fam || fam["family_name"] != "桃花岛")
              return notify_fail("你不是桃花岛的弟子，怎么能私自拿桃花岛的物件。\n");
        if ((me->query_skill("qimen-bagua",1)<122)&&(me->query_skill("bihao-chaosheng",1)<131))
              return notify_fail("你摘下八卦看了看，实在没什么特别之处，又放了回去。\n");
       if( me->query_temp("thd/bagua"))
              return notify_fail("你不是已经拿过八卦了么，怎么这么贪心？\n");
       if(present("tie bagua", me))
              return notify_fail("你身上不是已经有铁八卦了么？怎么还要拿？\n");
       ob = unew(__DIR__"obj/bagua");
       if(!clonep(ob)) return notify_fail("你发现铁八卦钉在门楣上取不下来。\n");
       i = ob->query("unique");
       clone = filter_array(children(base_name(ob)), (: clonep :));
          j = sizeof(clone);
          while (j--) if (!clone[j]->query("clone_by_wizard")) i--; 
       if(clonep(ob) && i < 0){
           destruct(ob);
           return notify_fail("你发现铁八卦钉在门楣上取不下来。\n");
       }
       message_vision("$N伸手到门楣上摘下一只铁八卦。\n",me);
       ob->move(me);
       me->set_temp("thd/bagua",1);
       me->delete_temp("thd/bagua_look");
       return 1;
}

