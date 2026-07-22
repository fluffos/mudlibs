// Room: /city/dangpu.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
        set("short", "武林大会广场");
    set("long", "
                "HBRED"※※※※※※※※※※※※※※※※※"NOR"
                "HBRED"※                              ※"NOR"
                "HBRED"※  打  遍  天  下  无  敌  手  ※"NOR"
                "HBRED"※                              ※"NOR"
                "HBRED"※※※※※※※※※※※※※※※※※"NOR"

        "HBCYN"※※※※※"NOR"                              "HBCYN"※※※※※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※  脚  ※"NOR"                              "HBCYN"※  拳  ※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※  踢  ※"NOR"  这里是扬州城的竞技场休息室。"HBCYN"※  打  ※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※  北  ※"NOR"  从这里可以看到上面的大擂台。"HBCYN"※  南  ※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※  海  ※"NOR"  擂台上面挂着一幅很大的对联。"HBCYN"※  山  ※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※  蛟  ※"NOR"                              "HBCYN"※  猛  ※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※  龙  ※"NOR"                              "HBCYN"※  虎  ※"NOR"
        "HBCYN"※      ※"NOR"                              "HBCYN"※      ※"NOR"
        "HBCYN"※※※※※"NOR"                              "HBCYN"※※※※※\n\n"NOR
    );
    set("no_new_clean_up", 0);
        set("no_fight",1);
        set("no_magic",1);
    set("item_desc", ([
                "flag": @TEXT
              以武会友！
TEXT
    ]) );
    set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"fightroom1",
                "up" : __DIR__"fightroom3",
        ]));
    setup();
}
void init()
{
       object me=this_player();
    add_action("discmds",({"respitate","exert","array","duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
       if (userp(me) && me->query("no_get") )
           call_out("do_recover",15,me);
}
void do_recover(object me)
{
    if( !me || environment(me) != this_object() ) return;
       me->delete("no_get");
       if (!living(me)) me->revive();
    me->set("eff_jing",me->query("max_jing"));
    me->set("jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
    if (me->query("neili")<me->query("max_neili"))
        me->set("neili",me->query("max_neili"));
    if (me->query("jingli")<me->query("max_jingli"))
        me->set("jingli",me->query("max_jingli"));
        me->start_busy(0);
    tell_object(me,HIW "广场似乎有一种神秘的力量，你活动了一下经骨，发现并没有受伤！\n"NOR);
}
int discmds()
{
        tell_object(this_player(),"现在你还是专心看比武吧！\n");

     return 1;
}
