 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "蚌普寺");
        set("long", @LONG
蚌普寺是一世噶玛巴﹒都松钦巴于一一四四年创建的。寺院依山俯水，风景如
画。寺内存有一世都松钦巴自塑雕像一尊，大师生前留下的手迹，鼻血岩画令人肃
然起敬。在秀丽的桑堆河中，游鱼成群，该寺僧人常用手抚摸鱼背，喂以糌粑。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"wild5",
                "north" : "/d/zangbei/sela",
        ]));
        set("item_desc", ([
                "鼻血岩画":     "都松钦巴生前留下的手迹。\n",
                "picture":      "都松钦巴生前留下的手迹。\n",
                "岩画":         "都松钦巴生前留下的手迹。\n",
        ]));
        
        set("objects", ([
                __DIR__"obj/statue4":   1,
                __DIR__"obj/river":     1,
                __DIR__"npc/monk4":     1,
        ]) );
         set("resource/water", 1);
        set("liquid/container", "桑堆河");  
        set("coor/x",-1070);
        set("coor/y",170);
        set("coor/z",0);
        setup(); 
}  
void reset()
{
        object statue,incense;
               
        ::reset();
        statue = present("statue", this_object());
        if (!present("incense",statue)) {
           incense=new(__DIR__"obj/incense");
                incense->move(statue);
        }
} 
void fish_notify(object obj){
        object me, room, fish, *inv, bait;
        int i;
        
        me = this_player();
        inv = all_inventory(obj);
        if(sizeof(inv) == 0){
                message("vision",me->name() + "掏出了" + obj->name() + "又放了回去。\n", environment(me), me);
                tell_object(me, obj->name() + "上没有饵怎么可以钓鱼呢 ? \n");           
                return;
        }               
        for(i=0; i<sizeof(inv); i++) {
                if(inv[i]->query("fish_bait")) {
                        bait = inv[i];
                        message_vision("$N挥动了一下," + obj->name() + "在空中划了一道漂亮的弧线, 鱼钩落入了水中. \n" , me);
                        me->start_busy(5);
                        remove_call_out("do_fishing");              
                        call_out("do_fishing", 5, me, bait);                    
                        return;
                } 
        }
        tell_object(me, "你用的饵不太对吧 ? \n");                       
        return;
} 
void do_fishing(object me, object bait){
        object  fish; 
        if(me && environment(me) == this_object()) {
                message_vision("$N很快又扯动了一下鱼杆, " , me);
                switch (random(10)) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:         message_vision("却什么都没钓上来 ! \n", me);
                                        break;
                        case 4:
                        case 5:
                           case 6:         message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
                                        destruct(bait);                         
                                        break;
                        case 7:
                        case 8:
                        case 9:         if (!bait->query("fish_bait_zanba")){        
                                                message_vision("什么都没钓上来 , 鱼饵却被鱼吃了 !!  \n", me);
                                                destruct(bait);                         
                                                break;
                                        }       
                                        if (random(5)) {                                
                                                message_vision("鱼钩上钓到了一条大鱼！！！  \n", me);
                                                fish = new(__DIR__"obj/fish");
                                                fish->move(me);
                                        } else {      
                                                message_vision("鱼线往下一沉，似乎钩到了什么重物 ！！  \n", me);
                                                message_vision("$N费劲地把鱼竿拉了上来。\n",me);
                                                fish = new(__DIR__"obj/item");
                                                fish->move(me);
                                        }
                                        destruct(bait);
                                        break;
                }
        }
        return;
}       
