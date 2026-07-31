 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "兽穴");
        set("long", @LONG
洞穴四壁上长满了青苔，偶尔从树叶间隙里透下的天光萎萎缩缩地不敢进入，
洞里黑漆一团，越往里走，就越能闻到一股血腥和膻骚味，让人浑身不自禁地起了
鸡皮疙瘩。可以感到脚下有许多硬硬的东西，一摸，都是啃的精光的动物骨头。
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"forest1",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void reset(){
        int i;
        object bear;    
        ::reset();
        
        if (bear=present("bear",this_object()))
        if (!userp(bear) && bear->is_character() && !bear->is_fighting())
                destruct(bear);
                
        i = NATURE_D->get_season();
        
        if(i = 1 || i = 4 ) {
                bear=new(__DIR__"npc/bear_w");
                bear->move(this_object());
        } else {
                bear=new(__DIR__"npc/bear");
                bear->move(this_object());
        }
} 
