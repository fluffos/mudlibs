// item: /d/xingxiu/npc/obj/fire.c
// Jay 3/17/96

inherit ITEM;

void create()
{
        set_name("火折", ({"fire", "huo zhe"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一支用于引火的火折，到了黑暗的地方就用(use)得着了。\n");
                set("unit", "支");
                set("value", 100);
        }
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if (arg!="huo zhe" && arg!="fire") return 0;
          this_player()->set_temp("use_fire",1);
                message_vision("$N取出火折，用火石把它点着。\n",this_player());
                destruct(this_object());
        return 1;
}
