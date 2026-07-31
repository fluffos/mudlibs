 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "洞穴口");
        set("long", @LONG
光线透过洞口照了进来，然而你目力能及的只有洞口四周，方圆一两
丈内的景物。其余的一切皆笼罩在一片无边的黑暗之中。没有照明的东西，
再向前走，只怕会凶多吉少。     
LONG
        );
        set("exits", ([ 
                "enter" : __DIR__"darkhole",
                "out" : __DIR__"whiterock",
        ]));
        set("outdoors","fengyun");
        set("coor/x",200);
        set("coor/y",-20);
        set("coor/z",40);
        setup();
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( userp(me) && dir == "enter" ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->name() == "夜明珠") {
                                me->move(__DIR__"lighthole");
                                return notify_fail(HIY"\n你从怀里掏出夜明珠，借着夜明珠发出的光，钻进了洞！\n"NOR);
                        }
                }
        }
        return 1;
}
