#include <ansi.h>
inherit __DIR__"no_killing_place";
void create()
{
        set("short", "厨房");
        set("long", @LONG
厨房里光线很好，靠近窗口有一张很大的案板，案板上收拾得非常干净，右手
边是一个黄土胚搭成的灶台，灶台下的麦杆还闪着暗红色，灶台上放着一口铁锅。
整个屋里飘动着浓郁的葱香和淡淡的炊烟。
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"cyard",
        ]) ); 
        set("objects", ([
                __DIR__"obj/oven" : 1,
                __DIR__"obj/pot" : 1,
        ]) ); 
        set("no_magic", 1);
    set("coor/x",220);
        set("coor/y",-20);
        set("coor/z",0);
        setup();
}
void reset()
{
        object          *inv;
        object          con, item;
        int             i; 
        ::reset();
        con = present("pot", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
                item = new(__DIR__"obj/bing");
                item->move(con);
        }
        con = present("oven", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 4) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/scallion");
                item->move(con);
                item = new(__DIR__"obj/caidao");
                item->move(con);
                item = new(__DIR__"obj/lighter");
                item->move(con);
                item = new(__DIR__"obj/candle");
                item->move(con);
        }
} 
void burn_notify(object ob) {
        object me;
        
        me = this_player();
        if(me->is_fighting()|| me->is_busy()) {
                return notify_fail("你正在忙！\n");
        }
        message_vision(RED"$N把碎石放在灶台下的火上烘烤。\n"NOR, me);
//      if(me->query("宿命B/黄山_瀑布") && !me->query("stone_mark/ystone")) {  
        if(!me->query("stone_mark/ystone")) {  
                message_vision(HIY"\n石片外面象粉一样松落。露出一块晶莹明澄的黄石。\n"NOR, me);
                destruct(ob);
                if(!me->query("m_success/凝露黄石")){
                        me->set("m_success/凝露黄石",1);
                        me->add("score",1000);
                }
                me->set("stone_mark/ystone", 1);
                ob = new("/obj/specials/stone/ystone");
                ob->move(me);
        } else {
                tell_object(me, "\n石块被烤得滚烫。\n");
        }
}      
