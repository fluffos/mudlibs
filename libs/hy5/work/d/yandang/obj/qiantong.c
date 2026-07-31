#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"签筒"NOR, ({ "qiantong","tong" }) );
        set("long", "一个竹签筒,里面装了几十根签.你可以摇(yao)着试试.\n");
        set("unit", "个");
        set("weight", 700);
        set("no_give",1);
        set("no_get",1);
}

void init()
{
        add_action("do_yao", "yao");
}
int do_yao(string arg)
{
    object me;
	if( !living(this_player()))	return 0;
    if(arg!="qiantong") return 0;
    me=this_player(); 
    if (me->query_temp("oldsix_flag/money")!=1) 
     return notify_fail("上人哈哈笑着,指了指善缘箱,道:请施主布施一二!\n");
    me->set_temp("yao",me->query_temp("yao")+1);

    if(me->query_temp("yao")==5)
    {
      me->set_temp("yao",0);
   tell_object(me,"从签筒中掉出来一根签,你仔细地把它放好!\n");
   clone_object(__DIR__"qian")->move(me);
   me->delete_temp("oldsix_flag/money");
    }
    else
      message_vision("$N虔诚地摇了下签筒。\n", me);
   
    return 1; 
}

