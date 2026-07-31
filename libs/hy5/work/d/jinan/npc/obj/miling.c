#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIW"密令"NOR, ({ "secret order" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "paper");
        set("long", "一道提押犯人上堂的密令，还未盖知府大印。\n");
        }
    setup();
} 
void init()
{
        add_action("do_show", "show");
        add_action("do_look","look");
}
void del_show_order(object ob)
{
        ob->delete_temp("show_order");
        destruct(this_object());
        return;
} 
int do_look (string arg)
{
        if (arg=="secret order")
        if (this_object()->query("sealed")!=1){
                tell_object(this_player(),"一道提押犯人上堂的密令，还未盖知府大印。\n");
                return 1; 
        } else {
                tell_object(this_player(),"一道提押犯人上堂的密令，上面盖了一个知府大印。\n");
                return 1;
                }
        return 0;
}        
int do_show(string arg)
{
   object obj; 
        if (environment(this_object())!=this_player() || !arg)
                return 0;
        if (!objectp(obj=present(arg,environment(this_player()))))
                return notify_fail("你要把密令拿给谁看？\n");
        if (!living(obj))
                return notify_fail("嗯....你得先把" + obj->query("name") +"弄醒再说。\n");
        
        message_vision("$N把"+this_object()->query("name")+"出示给$n看。\n",this_player(),obj); 
        if (obj->query("prison_guard")){
                        if (this_object()->query("sealed")==1){
                        if (this_player()->query("combat_exp")<1500000) {
                                message_vision("$N用怀疑的眼光看了看$n说：就凭你这两下子，也能押解犯人？\n",obj,this_player());
                                return notify_fail("天牢守卫看来不信任你。\n");
                        }
                        message_vision("$N仔仔细细看了看密令，神色凝重道：犯人就在里面。\n",obj);
                        message_vision("$N打开铁门上的大铜锁，拱手示意道：大人，请往里走。\n",obj);
                        environment(obj)->do_open();
                        if (obj->query("prison_guard")==1)
                                this_player()->set_temp("show_order",1);
                        else{
                                this_object()->move(obj);
                                call_out("del_show_order",300 , this_player());
                        }
                }
                else{
                        message_vision("$N仔细一看，脸色陡沉：竟然妄图蒙混过关！来人啊！有歹人劫狱～～\n",obj);
                        obj->do_alert(this_player());
                }
        }
        else{
                if (!userp(obj)){
                        if (obj->query("vendetta_mark")=="authority"){
                                message_vision("$N瞪了$n一眼，说道：此是官府之物，你从何处得来？\n",obj,this_player());
                        }
                        else{
                                message_vision("$N好像对"+this_object()->query("name")+"没什么兴趣。\n",obj);
                        }
                }
        } 
   return 1;
}  
