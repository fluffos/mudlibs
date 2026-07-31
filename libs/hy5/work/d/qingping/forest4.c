#include <ansi.h>
inherit ROOM;
string stone();
void create()
{
        set("short", "怪树林");
        set("long", @LONG
这里是一片奇怪的树林，林木并不是非常的密集，白天的阳光依旧透过林木
照耀进来，然而你却明显的感觉到一种阴冷的接近死亡的气息。猛然间一堵黑色
的峭壁矗立在眼前。林间没有任何可以辨认的道路，你感觉到眼前的景物随时随
地都在变化着，很难分辨什么是真什么是幻。。
LONG
        );
        set("item_desc", ([
                "stone" : (: stone :),
                "山石" : (: stone :),
        ]));
        set("outdoors","qingping");
        set("coor/x",230);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
} 
void init(){ 
    string *rooms = ({"forest1", "forest2", "forest3", "forest4", "forest5", "forest6"});
    string *direction = ({"north", "south", "east", "west", "northeast", "northwest", "southeast", "southwest"});
        if(this_object()->query("exits")){
                delete("exits");
        }
    set("exits/"+direction[random(8)], __DIR__ + rooms[random(6)]);
        set("exits/"+direction[random(8)], __DIR__+rooms[random(6)]);
        add_action("do_push", "push");
} 
string stone(){
        object me;
        me = this_player();
        if(me->query("class") == "shenshui"){
                tell_object(me, "峭壁上布满了各式各样的山石，其中一块你可以推。（ｐｕｓｈ）\n");
        } else {
                tell_object(me, "峭壁上布满了各式各样的山石。\n");
   }
        return "";
} 
int valid_leave(object me, string dir){
        object room; 
        if(me->query("class") == "shenshui" && (dir=="north" || dir=="south" || dir=="east" || dir=="west"
                        || dir=="northeast" || dir=="northwest" || dir=="southeast" || dir=="southwest")){
                tell_object(me, "你不被眼前幻像所迷惑继续往前行。\n");
                room = find_object(__DIR__"forest5");
                if(!objectp(room)){
                        room = load_object(__DIR__"forest5");
                }
                me->move(room);
                return notify_fail("");
        }
        return 1;
} 
int do_push(string arg){
        object me, room;
        
        me = this_player();
        if(!arg || (arg != "stone" && arg != "山石")){
                return notify_fail("你要触摸什么？\n");
        }
        if(me->query("class") == "shenshui"){
                tell_object(me, "你伸手在山石上运力一推。\n");
                tell_object(me, CYN"山石上裂开了一道逢，你闪身进去。山石又在你身后合拢。\n\n"NOR);
                message("vision", YEL"你隐约看到" + me->name()+"的身影在石壁旁一闪就消失不见了。\n"NOR, 
                                environment(me), me);
                room = find_object("/d/qingping/shenshui/huoyan");
                if(!objectp(room)){
                        room = load_object("/d/qingping/shenshui/huoyan");
                }
                me->move(room);
        } else {
                tell_object(me, "你左推右推也不得法，山石纹丝不动。\n");
        }
        return 1;
} 
