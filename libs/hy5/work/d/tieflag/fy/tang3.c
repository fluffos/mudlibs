 inherit ROOM;
void create()
{
        set("short", "化尸堂");
        set("long", @LONG
金钱帮已经买通官府，官府对帮中的所作所为大都视而不见。但金钱帮为铲除
异己而双手血腥，结下了众多仇家。此处正是焚烧罪状和尸体的后堂。两人高的青
铜炉火焰正盛。一股焦尸的恶臭弥漫了整个大厅（ｂｕｒｎ）。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jhuang",
]));
        set("coor/x",-20);
        set("coor/y",-9);
        set("coor/z",0);
        setup();
} 
void init()
{ 
        add_action("do_burn","burn"); 
} 
int do_burn(string arg)
{
        object me;
        object tar;
        int score, pot;
        me = this_player();
        score = (int) me->query("combat_exp");
        pot = (int) me->query("potential");
        if( !arg || arg == "") 
                return notify_fail("你烧啥东西．\n");
        tar = present(arg, me);
        if( !tar) 
                return notify_fail("你身上没有这东西．\n");
        if( userp(tar))
                return notify_fail("你不可烧活的东西．\n");
        if( tar->query("owner"))
                return notify_fail("你不可烧订的东西．\n");
        if (tar->query("no_burn"))
           return notify_fail("这样东西不能烧。\n");
        if( tar->is_corpse() && !tar->query("possessed"))               
        {
                me->set("combat_exp", (int) score + 1);
                me->set("potential", (int) pot + 1);
        }
        message_vision("$N将$n投入了青铜炉，$n转眼化为灰烬．\n", me, tar);
        tar->move(environment(me));
        destruct(tar);
        return 1;
}   
