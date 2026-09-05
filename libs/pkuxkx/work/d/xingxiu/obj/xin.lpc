// jinhe Zine Oct 23 2010

inherit ITEM;

void create()
{
        set_name("信", ({"xin", "letter"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "这是一封折好的新，你可以看看(kan)信上写了什么内容。\n");
                set("unit", "封");
                set("value", 100);
        }
}

void init()
{
        add_action("do_kan", "kan");
}

int do_kan(string arg)
{
        object me=this_player();
        if (this_object()->query("read"))
        {
            return notify_fail("这封信已经被人拆过了，里面并无什么内容。\n");
        }
        else
        {
        if (this_object()->query("owner")!=me->query("id"))
        {
            return notify_fail("这不是给你的信。\n");
        }
        if (arg!="xin" && arg!="letter")  return notify_fail("你要看什么？\n");
        message_vision("$N仔细阅读了"+query("givenBy")+"的信，不禁喜不自禁。\n",this_player());
        message_vision("信上写道，行走江湖，最重要的就是一个“钱”字，师门在你账户上存了200两黄金，各大银号可以支取。\n",this_player());
        me->add("balance",2000000);
        this_object()->set("read");
        destruct(this_object());
        return 1;
        }
}