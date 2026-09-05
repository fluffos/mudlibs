//玩偶
//create by zine 29/3/2011
#include <ansi.h>

int dest();
inherit ITEM;

void create()
{	
	set_name(WHT"玩偶"NOR, ({ "toy"}));
	set_weight(50);
	set("long", "这是一个玩偶。\n");
	set("material", "wood");
	set("unit", "个");
	set("value", 0);
    set("no_give",1);
    set("no_drop",1);
    set("no_put",1);
	setup();
    call_out("dest",60);
}

int dest()
{
    if (this_object())
    {
        destruct(this_object());
        return 1;
    }
}

void init()
{
    add_action("do_look",({ "look","l" }));
}

int scene1(object me)
{
    tell_object(me,HIW"鬼门关 -\n"NOR);
    tell_object(me,"    这里就是著名的阴间入口「鬼门关」，在你面前矗立著一座高大的\n");
    tell_object(me,"黑色城楼，许多亡魂正哭哭啼啼地列队前进，因为一进鬼门关就无法再\n");
    tell_object(me,"回阳间了。抬头仰望，你竟然仿佛看到片片祥云，听到阵阵仙乐。\n");
    tell_object(me,"    这里明显的出口是 north 和 up。\n");
    tell_object(me,"    白无常(White gargoyle)\n");
    return 1;
}

int scene2(object me)
{
    tell_object(me,"迷魂阵 -\n");
    tell_object(me,"    你一旦走进了迷魂阵, 就别想容易的走出去.\n");
    tell_object(me,"这里明显的出口是 east、north、northwest、west、south 和 southeast。\n");
    return 1;
}

int scene3(object me)
{
    tell_object(me,"桃林 -\n");
    tell_object(me,"    这是桃花岛的桃林，四周都是桃花，似乎是一个桃花阵。\n");
    tell_object(me,"    「初春」: "HIW"现在是正午时分，太阳高挂在你的头顶正上方。\n"NOR);
    tell_object(me,"    这里明显的出口是 northwest、northup 和 south。\n");
    return 1;
}

int scene4(object me)
{
    tell_object(me,"悬崖 -\n");
    tell_object(me,"    只见左右上下都是陡峭的岩石，滑滑的难以着手。脚下就\n");
    tell_object(me,"是万丈悬崖，吓得人不敢下望。山风罡烈，直要把你吹了下去。\n");
    tell_object(me,"    「初春」: "HIW"现在是正午时分，太阳高挂在你的头顶正上方。\n"NOR);
    tell_object(me,"    这里唯一的出口是 down。\n");
    return 1;
}

int scene5(object me)
{
    tell_object(me,"长江天险 -\n");
    tell_object(me,"    你历尽险阻来到这里，却被一条大江(river)挡住了去路。江边停着一条破\n");
    tell_object(me,"船(chuan)。\n");
    tell_object(me,"    「初春」: "HIW"现在是正午时分，太阳高挂在你的头顶正上方。\n"NOR);
    tell_object(me,"    你可以看看(look):chuan,river\n");
    tell_object(me,"    这里没有任何明显的出路。\n");
    return 1;
}

int do_look()
{
    object me=this_player();
    int n=random(1000);
    if (n>799)
    {
        scene1(me);
        return 1;
    }
    if (n>599)
    {
        scene2(me);
        return 1;
    }
    if (n>399)
    {
        scene3(me);
        return 1;
    }
    if (n>199)
    {
        scene4(me);
        return 1;
    }
    else
    {
        scene5(me);
        return 1;
    }
}