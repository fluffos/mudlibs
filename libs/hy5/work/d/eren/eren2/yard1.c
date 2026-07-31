#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
一间破旧的石屋，更确切地说只是个石洞，似乎是用来储藏粮食和杂物的，几
个鼓鼓囊囊的麻袋里装满了谷子，一个钉耙，两三个破竹筐堆在角落里。像是已许
久没有人来过，所有的东西上都蒙着一层灰。
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"yongdao7",    
                "east" : __DIR__"yard2",        
        ]));
        set("objects", ([
                __DIR__"obj/pumpkin" : 2,
        ]) );
        set("item_desc", ([
                "麻袋": "一个脏兮兮的的米袋，里面装满了谷子。\n",
                "竹筐": "竹筐上积了厚厚的一层灰。\n",
                "bag": "一个脏兮兮的的米袋，里面装满了谷子。\n",
                "钉耙": "很普通的农家用具，靠在墙上。\n",
                "basket": "竹筐上积了厚厚的一层灰。\n",
                "dingba": "很普通的农家用具，靠在墙上。\n",
                "灰":"厚厚的一层灰，也许你可以试着抹去(remove)它。\n",
                "dust":"厚厚的一层灰，也许你可以试着抹去(remove)它。\n",
                "hui":"厚厚的一层灰，也许你可以试着抹去(remove)它。\n",
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}  
void init(){
        add_action("do_remove", "remove");
} 
int do_remove(string arg){
        object me, guard;    
        me = this_player();
        if(!arg || (arg != "dust" && arg != "灰")) {
                return 0;
        }
        message_vision("$N俯下身，抹去地上的尘土。\n",me);
        message_vision("地上露出几个断断续续的血字："+HIR"危险。。机关。。灯。。\n"NOR,me);
        return 1;
}
