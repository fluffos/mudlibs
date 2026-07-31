#include <ansi.h> 
inherit ROOM;
string light();
void create() 
{ 
    set("short", "密道"); 
    set("long", @long
这条密道四面八方都是路，也不知道到底哪条路是真的，哪条路是假的，
密道一边墙上点着一盏油灯，但是这点光亮仍然挡不住四面的杀机。
long 
    ); 
    set("exits", ([ 
    	"east" : __DIR__"midao1", 
    	"south" : __DIR__"midao",
    	"west" : __DIR__"midao2",
    	"north" : __DIR__"midao6",
        ])); 
    set("item_desc", ([
                "油灯": (: light :),
                "灯": (: light :),
        ]) );
    set("indoors","shanxi"); 
    set("coor/x",0); 
        set("coor/y",0); 
        set("coor/z",0); 
        setup(); 
} 
int valid_leave(object obj, string dir){
        int skills,i,damage;
        string  *dirc = ({ "东", "南", "西", "北" });
        skills=obj->query_skill("dodge",1);
        
        if(dir == "west" || dir == "south" || dir == "east" || dir == "north"){
        	if (random(10)>=5) {
            		message_vision(HIR"$N慢慢的摸索前行，突然「嗖嗖嗖」三声，有几道暗器从"+dirc[random(4)]+"面墙壁飞射过来！！\n"NOR, obj); 
            		if( random(skills) < 50 ){
            			message_vision(HIR"暗器疾驰而来，$N躲闪不及，被打了个正着！！\n"NOR,obj);
            			i = (int)obj->query("eff_qi");
        			damage = i/20;
        			obj->set("eff_qi",(int) i - damage );
        			i =  (int)obj->query("qi");
        			obj->set("qi",(int) i - damage);
        			return 1;
            		}
  			else{
  				message_vision(WHT"$N听风辩器，一个跨步躲过了飞射而来的暗器。\n"NOR,obj);
  				return 1;
  			}
                }
        }       
        return 1;
}

string light(){
        object me;
        me = this_player();
        tell_object(me, "一盏普通的油灯，但是看上去安放的位置和别处不一样。\n");
        tell_object(me, "你也许可以旋转(turn)一下。\n");
        add_action("do_turn", "turn");
        return "";
}

int do_turn(string arg)
{
        object room;
        object me;
        if(!arg || arg=="")
        {
                write("你要旋转什么？\n");
                return 1;
        }
        if( arg == "油灯" || arg == "灯" || arg == "light")
        {
        	me = this_player();
        	message_vision("$N发现这里的油灯和别处的油灯不一样，伸手旋转了一下。\n", me);
        	message_vision("突然“咯咯”一声，地上露出了暗道，$N躲闪不及，啪唧一声掉了进去......\n",me);
        	room = find_object(__DIR__"midao8");
        	if(!objectp(room)) room = load_object(__DIR__"midao8");
        	message("vision",me->name()+"从上面掉了下来。\n",room);
        	me->move(room);
       	return 1;
        }
}