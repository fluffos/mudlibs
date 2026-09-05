// jinhe Zine Oct 23 2010

inherit ITEM;

void create()
{
        set_name("锦盒", ({"jin he", "he"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一只锦盒，你可以打开(open)它，看看师门给你准备些什么。\n");
                set("unit", "支");
                set("value", 100);
        }
}

void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{
        object letter;
        object me=this_player();
        if (this_object()->query("open"))
        {
            return notify_fail("这只锦盒已经被人打开过了，里面并无什么内容。\n");
        }
        else
        {
            if (this_object()->query("owner")!=me->query("id"))
            {
                return notify_fail("这不是给你的锦盒。\n");
            }
            if (arg!="jin he" && arg!="he")  return 0;
            message_vision("$N打开了锦盒，里面却只有一封信。\n",this_player());
            letter=new(__DIR__"xin");
            letter->set("owner",me->query("id"));
			letter->set("givenBy",query("givenBy"));
            letter->move(this_player());
            this_object()->set("open");
            destruct(this_object());
            return 1;
        }
}