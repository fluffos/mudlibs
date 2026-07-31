// Room: /d/new_taohua/hai2.c
#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "");
        set("long", @LONG
海浪汹涌，你耳边全是水声，浪涛向你涌来…
LONG
        );


        setup();
}

void init()
{       object ob;
        add_action("do_swim", "swim");
        if( interactive( ob = this_player()))
        {
        remove_call_out("sinking");
        call_out("sinking", 1, ob);
        }
}

int sinking(object ob)

{
        int i;
        int damage;
        if( environment(ob) == this_object())
        {
        message_vision(HIW"$N感觉越来越游不动了, 身体直往下沉。\n", ob);
        message_vision("$N不时被涌来的大浪呛了几口水！！\n"NOR, ob);
        damage = random(5)+50;
        i =  (int)ob->query("kee");
        if (i > 40) ob->improve_skill("dodge", ob->query("con"));
        ob->set("kee",(int) i - damage);
        if( environment(ob) == this_object())
        call_out("sinking",random(5)+5, ob);
        }
        else

        return 1;
}

void check_trigger()
{
        object me;
        me = this_player();
        
        if ((int)query("trigger") < 0) {
                message_vision("$N又游回岸边。\n", me);
                me->move(__DIR__"binghuo");
                delete("trigger");
                return;
        }
       if ((int)query("trigger")==200 ){
           message_vision("终于回到了桃花岛. \n",me);
           me->move(__DIR__"haitan1");
	   delete("trigger");
           return;
        }
}

int do_swim(string arg)
{
        int i;
        if (!arg || arg == "") {
                write("你往北游还是往南游？\n");
                return 1;
        }
        if (arg == "south" || arg == "s") {
                add("trigger", 1);
                write("你奋力向南游去……\n");
                check_trigger();
                return 1;
        }
        if (arg == "north" || arg == "n") {
                i = (int)query("trigger")-1;
                delete("trigger");
                add("trigger", i);
                write("你奋力向北岸游去……\n");
                check_trigger();
                return 1;
        }
}

void reset()
{
        ::reset();
        delete("trigger");
}
