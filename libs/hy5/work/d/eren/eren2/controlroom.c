#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "石洞");
        set("long",  @LONG
这屋子里却有个很古怪的地方，那就是这么大一间屋子里，竟只有一
张椅子，其余就什么都没有了。这张椅子也奇怪得很，它看来既不像普通
的太师椅，也不像女子闺阁中常见的那一种。这张椅子看来竟像是个很大
很大的箱子，只不过中间凹进去一块，人坐上去后，就好像被嵌在里面了。
洞壁上点着一盏铜灯，将屋子照得很亮。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"guardroom",
        ]));
        set("objects", ([
                __DIR__"npc/star_chick" : 1,
                __DIR__"npc/star_c1" : 1,
                __DIR__"npc/star_c2" : 1,
                __DIR__"npc/star_c3" : 1,
                __DIR__"npc/star_c4" : 1,
        ]) );
        set("item_desc", ([
        "椅子" : "椅子的扶手(arm)很宽，竟也像个箱子，可以打开来的(break)。\n",
        "chair" : "椅子的扶手(arm)很宽，竟也像个箱子，可以打开来的(break)。\n",
        "铜灯" : "这铜灯(lamp)也有些古怪，把手似乎可以转动（turn）。\n",
        "lamp" : "这铜灯(lamp)也有些古怪，把手似乎可以转动（turn）。\n",
    ])); 
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        set("elevator",1);
        set("thread",1);
        setup();
        
} 
void init(){
        add_action("do_open", "break");
        add_action("do_turn", "turn");
} 
int do_open(string arg){
        object me, guard;    
        object *inv;
        int i;
        
        me = this_player();
        if(!arg || (arg != "arm" && arg != "扶手")) {
                return 0;
        }
        inv = all_inventory(this_object());
        for (i=1;i<sizeof(inv);i++) {
                if (inv[i]->query("dungeon_npc")=="eren2")
                {
                if (me->short()!="献果神君(Xianguo)")
                        return notify_fail(inv[i]->query("name")+"喝道：“偷偷摸摸地想干什么！“\n");
                }
        }
        if(query("elevator") || query("thread")) {
                message_vision(HIW"$N小心翼翼地将椅子扶手上面的盖子掀起，伸手在里面轻轻一拨，只
听‘格”的一声，随即洞壁后传来一阵咔咔的响声，而后又静了下来。\n"NOR,this_player());
                this_object()->set("elevator",0);
                this_object()->set("thread",0);
                me->start_busy(2);
                if (me->short()=="献果神君(Xianguo)") 
                for (i=1;i<sizeof(inv);i++) {
                        if (inv[i]->query("dungeon_npc")=="eren2") {
                                message_vision(CYN"$N听到一声大叫，抓奸细！\n"NOR,me);
                                inv[i]->kill_ob(me);
                                }
                }                                                       
        } else {
                tell_object(me,HIW"你小心翼翼地碰了碰椅子扶手，什么动静也没有。\n"NOR);
                me->start_busy(2);
                }
        return 1;
} 
int do_turn(string arg){
        object me, guard, trap_room;    
        object *inv;
        int i;
        
        me = this_player();
        if(!arg || (arg != "lamp" && arg != "铜灯")) {
                return 0;
        }
        inv = all_inventory(this_object());
        for (i=1;i<sizeof(inv);i++) {
                if (inv[i]->query("dungeon_npc")=="eren2")
                return notify_fail(inv[i]->query("name")+"喝道：“偷偷摸摸地想干什么！“\n");
        }
        message_vision(HIW"$N小心翼翼地将铜灯左转右转了几下。\n"NOR,this_player());
        message_vision(HIR"地板，竟忽然裂了开来，露出了个地洞。$N一个跟斗栽进了洞里。\n"NOR,this_player());
        trap_room = find_object(__DIR__"underjail1");
        if(!objectp(trap_room))
                 trap_room = load_object(__DIR__"underjail1");
        this_player()->move(trap_room);
        this_player()->unconcious();
        return 1;
} 
void reset()
{
        ::reset();
        set("elevator",1);
        set("thread",1);
        
}     
