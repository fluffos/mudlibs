// marry_card.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("结婚证书", ({"jiehunzheng","marrycard","jiehun zheng","zheng"}) );
        set_weight(10);
        set("no_get",1);
        set("no_drop","你的结婚证不能丢弃,只能去府衙办离婚。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
        }
}

string query_autoload()
{
        object *list, me;
        object couple_ob;
        string target,cardname;
        int i;

        me = this_player();
        list = all_inventory(this_player());
        i = sizeof(list);
        while (i--) {
              if (((string)list[i]->query("id")) == "jiehunzheng")
                cardname = list[i]->query("name");
        }

        sscanf(cardname,"你和%s的结婚证" ,target);
        return target;
}

void autoload(string arg)
{
        int i;
        object couple_ob;
        object me;
        string tmpstr, tmpstr1;

//      me = this_player();
        couple_ob = find_player(arg);
        if (couple_ob){
                if ((string)couple_ob->query("gender") != "女性"){
                        tmpstr1 = "老公"; 
                        tmpstr = "老婆";
                } else {
                        tmpstr1 = "老婆";
                        tmpstr = "老公";
                }
                
         write(sprintf( MAG "你的%s也在这里，快去找啦...\n"NOR,tmpstr1));
                tell_object(couple_ob ,
                sprintf( MAG "你的%s来啦,快去接...\n" NOR, tmpstr));

//me->name(1)+"("+me->query("id")+")",environment(me))->query("name") ); 
                
                
        }
        set("name","你和"+arg+"的结婚证");

}
