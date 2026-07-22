// marry_card.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("结婚证书", ({"jiehunzheng","marrycard","jiehun zheng","zheng"}) );
        set_weight(10);
        set("no_get",1);
        set("no_steal",1);
        set("no_drop","你的结婚证不能丢弃,只能去府衙办离婚。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
		set("long","夫妻之间可以通过这本结婚证使用ct与ce指令甜言蜜语。\n");
        }
}

void init()
{
        add_action("do_coupletalk", "ct");
        add_action("do_cemote", "ce" );
}

int do_cemote(string arg)
{
        object me;
        object couple_ob;
        string target, tmpstr1, tmpstr2,str1,str2;

        me = this_player();

        target=(string)query("marry_id");
        if( !target)
		return notify_fail("你身上这张结婚证有问题，不是自己的吧。\n");

        couple_ob = find_player(target);
        if( !couple_ob )
                return
        notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");
        if( (string)couple_ob->query("marry/id")!= me->query("id"))
		return notify_fail("这个人不是你原来的配偶了，去办离婚吧。\n");

        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆"; tmpstr2 = "老公";
                str1 = "她"; str2 = "他";
        } else {
                tmpstr1 = "老公"; tmpstr2 = "老婆";
                str1 = "他"; str2 = "她";
        }

        if (!arg) {
                write( MAG "你又深情的想念你的爱侣了。\n" NOR);
                tell_room(environment(me), CYN+(string)me->name()+
                "又深情的想念"+str1+"的爱侣"+ (string)couple_ob->name()+
                "了。\n" +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s 又在深情的想你了\n"NOR, tmpstr1,me->name(1) )); 

                return 1;
        }
        if (environment(me) == environment(couple_ob ) ) {       
           if (arg == "kiss") {
              write( MAG "你拥住你的爱侣，深深的一吻，许久...许久...\n" NOR);
              tell_room(environment(me), CYN+(string)me->name()+
              "拥住"+(string)couple_ob->name()+"，深深的一吻。\n" 
                +NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(MAG "%s %s 拥住你，深深的一吻，许久...许久...\n"NOR,tmpstr1,me->name(1) 
));               }         
        }                 

        return 1;
}


int do_coupletalk(string arg)
{
        object me;
        object couple_ob;
        string target, tmpstr1, tmpstr2;

        me = this_player();
        target=(string)query("marry_id");
        if( !target)
		return notify_fail("你身上这张结婚证有问题，不是自己的吧。\n");

        couple_ob = find_player(target);
        if( !couple_ob )
                return 
        notify_fail("你的伴侣现在无法听见你，或者已经离开游戏了。\n");
        if( (string)couple_ob->query("marry/id")!= me->query("id"))
		return notify_fail("这个人不是你原来的配偶了，去办离婚吧。\n");
        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆";
                tmpstr2 = "老公";
        } else {
                tmpstr1 = "老公";
                tmpstr2 = "老婆";
        }

        write(sprintf(MAG"你对%s %s 说：%s\n"NOR,
                tmpstr2,couple_ob->name(1), arg ));
        tell_object(couple_ob, sprintf(MAG "%s %s 对你说：%s\n"NOR, 
               tmpstr1,me->name(1), arg ));

        return 1;
}

int query_autoload()
{
	return 1;
}

void autoload(string arg)
{
	object me=this_player();
	string id,name;
	name=(string)me->query("marry/name");
	id=(string)me->query("marry/id");
	if( !name || !id)	destruct(this_object());
	else	{
		set("name","你和"+name+"("+id+")的结婚证");
		set("marry_id",id);
		set("marry_name",name);
	}
	return;
}

void owner_is_killed()	{ destruct(this_object()); }