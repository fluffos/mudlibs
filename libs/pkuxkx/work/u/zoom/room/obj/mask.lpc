//last modified by vast
//非巫师不得使用
//不要随意修改，可能引起一些意想不到的错误
//2003.5.20
inherit ITEM;
void create()
{
        set_name("面具", ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这似乎是一个由人皮制成的面具。\n");
        }
        setup();
}
void init()
{
        add_action("do_pretend", "pretend");
}
int do_pretend(string arg)
{
        object who;
        if (!arg)
                return notify_fail("你想假装谁？\n");
           if (userp(this_player()) && !wizardp(this_player()))
     return notify_fail("你不能使用面具。\n");
        if (arg == "none" || arg == "cancel") {
                this_player()->delete_temp("apply/name");
             this_player()->delete_temp("apply/id");
                this_player()->delete_temp("apply/short");
                this_player()->delete_temp("apply/long");
                 this_player()->delete_temp("apply/gender");
                 this_player()->delete_temp("apply/age");
                message_vision("$N从脸上取下了一个人皮面具。\n", this_player());
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player()))) ||
                !living(who))
                return notify_fail("你想假装谁？\n");
        write("你开使假装" + who->name() + "。\n");
         message_vision("$N戴上了一个精功制成的人皮面具。\n", this_player());
        this_player()->set_temp("apply/name", ({who->name()}));
       this_player()->set_temp("apply/id", ({who->query("id")}));
        this_player()->set_temp("apply/short", ({who->short()}));
        this_player()->set_temp("apply/long", ({who->long()}));
         this_player()->set_temp("apply/gender", ({who->query("gender")}));
         this_player()->set_temp("apply/age", ({who->query("age")}));
        return 1;
}
