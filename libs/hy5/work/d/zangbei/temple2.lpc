 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "塔公寺");
        set("long", @LONG
塔公寺结构奇特，古朴庄重，四周分别建有白、黄、红、绿四塔，塔内长灯彻
夜不息。四方塔周围百余座造型各异的塔林环抱寺庙，寺内正殿供奉着花教创始人
薛迦班智达的塑像，右侧专殿供奉着相传文成公主入藏时所带的“塔公觉巫”。也
许是年代太旧的缘故，寺内香火稀少，建筑已经颇为破落。
LONG
        );
        set("exits", ([ 
                "northup" : __DIR__"mount2",
                "south" : "/d/xizang/grassland4",	
                
        ]));
        set("item_desc", ([
                "red tower":    "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
                "yellow tower": "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
                "white tower":  "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
                "白塔":         "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
                "黄塔":         "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
                "红塔":         "一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/monk2":     1,
                __DIR__"obj/statue2":   1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init(){
        add_action("do_look","look");
} 
int do_look(string arg) {
        object me=this_player();
        object item;
   
        if (arg== "hole" || arg == "浅穴") {
                if (!me->query_temp("zangbei/塔公寺砖塔")) 
                        return notify_fail("你要看什么？\n");
                tell_object(me,"孔不深，你伸手进去摸索了一阵，拿到一件硬硬的东西。\n");
                item = new(__DIR__"obj/item");
                item->move(me);
                return 1;
        }
        if (arg == "green tower" || arg == "绿塔") {
                tell_object(this_player(),"一座砖塔，自上向下由宝珠、七重和轮、宝装莲花式覆钵等组成。\n",);
                if (!me->query("zangbei/塔公寺施舍"))                   
                        return 1;
                tell_object(me,"仔细看去，正如老喇嘛所说，塔基的砖石已经非常松散，许多地方甚至少了几块，
露出几个浅穴（ｈｏｌｅ）。\n");
                me->set_temp("zangbei/塔公寺砖塔",1);
                return 1;
        }
        return 0;
}     
