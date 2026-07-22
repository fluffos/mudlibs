// story:xingxiu.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "天狼子：大哥，咱兄弟几个好久没出星宿海溜溜了。。",
        "摘星子：那也是，时间长了，人都快憋出毛病出来了。",
        "采花子：大哥、三哥，乘师傅还在闭关修炼，咱哥几个出去爽爽。",
        "摘星子皱皱眉：不叫上老二、老四？",
        "采花子：哎呀，多一个人多一些消费。再说也难找那么多MM给咱分啊。",
        "黯然子、狮吼子突然蹦了出来。。。",
        "狮吼子：靠！",
	"黯然子：靠！",        
        "黯然子：出去泡妞也不叫上我们。TNND。要是不带上我们，我就告诉师傅去。",
        "采花子呵呵干笑了几声。",
        "天狼子：既然大家都来了，那就同去得了。",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        return HIM "听说星宿众弟子下山来了。\n" NOR;
}
