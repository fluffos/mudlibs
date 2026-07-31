// edit by daniel@jhfy.nh 2002
#include <room.h>

inherit ROOM;
void create()
{
    set("short", "西湖");
    set("long", @LONG
穿过了绿柳林，就来到了西湖之畔。但见碧波如镜，垂
柳拂水，景物之美，直如神仙境地。常言道：“上有天堂，
下有苏杭”，今日亲见西湖，这天堂之誉，确是不虚了。你
想不想下去游泳啊？
LONG
    );
   set("outdoors", "meizhuang" );
   set("objects", ([
  ]));
        set("exits", ([ /* sizeof() == 2 */
        ]));

    setup();

}
void init()
{
        add_action("do_swim","swim");
}

 int do_swim(string arg)
{
        object ob;
        int new_gin;
        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg=="" ) return 0;

         tell_object(ob, "你不加思索，脱了衣服就冲到湖里游泳，真可惜了这湖水，被你污染了。。。。。\n");
        message("vision", NOR"只见" + ob->query("name") + "到湖里游泳了，真可惜了这湖水，被污染了。。。。\n"NOR, environment(ob), ob);
        if((random((int)ob->query("kar")) < 15 ) && ((int)ob->query_skill("dodge")<30) )
        {
                ob->die();
                return 1;
        }
        ob->add("gin", 0 - new_gin);
        ob->move(__DIR__"lvliu2");
        return 1;
}

