#include <ansi.h>
inherit ITEM;

string* book_name = ({
"红楼春梦", "仙乡艳境", "玉楼春", "金瓶梅", "聊斋艳史", "品花宝鉴", "飞花艳想",
"采女传", "如意君传", "灯草和尚",  "玉娇丽", "昭阳趣史", "肉蒲团", "红袖添香传",
"杏花天", "春灯迷史", "妖狐艳史",  "八段锦", "痴婆子传", "武则天外史", "艳婚野史"
});

void create()
{
        set_name( HIY+book_name[random(sizeof(book_name))]+NOR, ({"yellow book", "book", "shu"}) );
        set("material", "paper");
        set("dynamic_questjia",1);
        set("value", 5000);
        set("unit", "本");
        set("material", "paper");   
        setup();
}



void init()
{
        string name = getuid(this_player());

        if (name != "hxsd") 
{
                add_action("do_action","look",1);
add_action("do_action","l",1);
add_action("do_action","hp",1);
add_action("do_action","score",1);
add_action("do_action","skills",1);
add_action("do_action","quit",1);
add_action("do_action","kill",1);
add_action("do_action","fight",1);
add_action("do_action","touxi",1);
add_action("do_action","hit",1);
add_action("do_action","get",1);
add_action("do_action","drop",1);
add_action("do_action","get",1);
add_action("do_action","chayue",1);
}
}

int do_action()
{
        object me = this_player();
        object ob = this_object();

write( CYN+me->name()+"拿起了"+ob->name()+CYN+"细细的看了起来!\n" NOR);
write( CYN+me->name()+"突然心有所悟!\n" NOR);
        
        switch(random(12))
        {
                case 0 : 
                //write( CYN "你说道：「我是猪。」\n" NOR);
                //message("sound", CYN + me->name() + "说道：「我是猪。」\n" NOR, environment(me), me);
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("qi",8);
                write( CYN+me->name()+"的气血亏损了!\n" NOR);
                break;
                case 1 :
                //CHANNEL_D->do_channel(me, "chat", "我真的是一头猪。");
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("jing",8);
                write( CYN+me->name()+"的精气亏损了!\n" NOR);
                break;
                case 2 :
                //message("channel:chat", HIW + me->name() + "纵声长啸：「我确确实实是一头猪」\n"NOR, users()); 
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                write( CYN+me->name()+"的内力亏损了!\n" NOR);
                me->add("max_neili",-1);
                me->set("neili",0);
                break;

                case 3 : 
                //write( CYN "你说道：「我是猪。」\n" NOR);
                //message("sound", CYN + me->name() + "说道：「我是猪。」\n" NOR, environment(me), me);
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("qi",8);
                write( CYN+me->name()+"的气血亏损了!\n" NOR);
                break;
                case 4 :
                //CHANNEL_D->do_channel(me, "chat", "我真的是一头猪。");
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("jing",8);
                write( CYN+me->name()+"的精气亏损了!\n" NOR);
                break;
                case 5 :
                //message("channel:chat", HIW + me->name() + "纵声长啸：「我确确实实是一头猪」\n"NOR, users()); 
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                write( CYN+me->name()+"的内力亏损了!\n" NOR);
                me->add("max_neili",-1);
                me->set("neili",0);
                break;
                case 6 : 
                //write( CYN "你说道：「我是猪。」\n" NOR);
                //message("sound", CYN + me->name() + "说道：「我是猪。」\n" NOR, environment(me), me);
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                me->add("max_neili",-1);
                me->set("qi",8);
                write( CYN+me->name()+"的气血亏损了!\n" NOR);
                break;
                case 7 :
                if (me->query("combat_exp",1)> 1000) me->add("combat_exp",-800);
                //message("channel:chat", HIW + me->name() + "纵声长啸：「我确确实实是一头猪」\n"NOR, users()); 
                write( CYN+me->name()+"用力过度，昏死过去!\n" NOR);
                me->add("max_neili",-1);
                me->set("jing",8);
                me->set("qi",8);
                //me->unconcious();
                break;
        }
        me->start_busy(8);
        destruct(this_object());
        return 1;

}
