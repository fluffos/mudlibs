inherit ITEM;

void create()
{
        set_name("骸骨", ({ "skeleton" }) );
        set("long", "这副骸骨已经躺在这里很久了。\n");
        set("unit", "具" );
        set("big_count", 1);
        set("small_count", 1);
}
void init()
{
        add_action("do_mai", "move");
     }
int do_mai(string arg)
{
        int n;
        object ob, me = this_player();

        n = this_player()->query("force");
        if( !arg || arg != "skeleton")
        {
                write("你要移动什么? \n");
                return 1;
        }
        if (me->query_temp("marks/yandang") == "1")
        {
                if (n > 200 && query("small_count") == 1)
                {
                        message_vision(
"$N将骸骨的头颅轻轻的摆正，发现头颅下竟然枕着一个盒子。\n", me);
                        ob = new(__DIR__"box");
                        ob->move(environment(me));
                        me->set_temp("marks/yandang", "2");
                        add("small_count", -1);

}
        return 1;

