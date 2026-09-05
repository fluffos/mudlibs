// caoyao.c 草药

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_dao", ({"daoyao","捣药"}));
}

void create()
{
	set_name("药性极强的草药", ({"caoyao", "yao"}));
    set("is_qiangcaoyao",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long", "这是一片药性极强的草药。\n");
		set("value", 100);
	}
	setup();
}

int daoyao(object me)
{
    object ob=this_object();
    object cy;
    if (random(100)>69)
    {
        tell_object(me,"你制成了一副药剂。\n");
        cy=new(__DIR__"caoyao4");
        cy->set("owner",me->query("id"));
        cy->move(me);
        destruct(ob);
        return 1;
    }
    else
    {
        tell_object(me,"这片草药被捣得稀烂，无法使用了。\n");
        destruct(ob);
        return 1;
    }
}

int do_dao()
{
    object me=this_player();
    object ob=this_object();
    object cy;
    if (me->query_temp("emnewbiejob/jingci/task")!=1)
    {
        tell_object(me,"你想干嘛？\n");
        return 1;
    }
    if (ob->query("owner")!=me->query("id"))
    {
        tell_object(me,"你从哪捡的草药啊？\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (base_name(environment(me))!="/d/emei/houshan/ywdong")
    {
        tell_object(me,"你只能在药王洞里捣药。\n");
        return 1;
    }
    me->add_busy(1);
    message_vision("$N开始捣药。\n",me);
    call_out("daoyao",1,me);
    return 1;
}

