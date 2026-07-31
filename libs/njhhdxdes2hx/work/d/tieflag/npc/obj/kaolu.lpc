inherit ITEM;
//kaolu.c

void create()
{
    set_name("红泥小烤炉", ({ "kaolu" }) );
    set_weight(10000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("value", 100);
            set("material", "stone");
            set("long", "一个红泥制成的小烤炉，你似乎可以用它烤（ｆｒｙ）些什么\n");
          }
   
    setup();
}
void init()
{
 add_action("do_kao","kao");
 add_action("do_kao","fry");
}
int do_kao(string arg)
{
        object me;
        object tar;
        object meat;
        string name;
        me = this_player();
        if( !arg || arg == "")
                return notify_fail("你烤什么？\n");
        if(!objectp(tar = present(arg, me)) )
        if(!objectp(tar = present(arg, environment(me))))
                return notify_fail("你烤什么？\n");                      
        if(tar->is_character() && !tar->is_corpse())
                return notify_fail("天...啊！上天有好生之德，你还是让它安乐死吧！\n");
        if( !tar->is_character() && !tar->is_corpse())
                return notify_fail("这是你不可以烤的东西．\n");
        if( tar->is_corpse())          
        {
           name=tar->query("name");
           name=replace_string(name,"一具","");
           name=replace_string(name,"的尸体","");
           if (tar->query("decayed")<1)
               name="一串烤"+name+"肉";
           else
               name="一串腐烂的烤肉";
           meat = new("/open/t/tender/meat");
           meat->set("name",name);
           meat->set("decayed",tar->query("decayed"));
           meat->move(me);
            }
        message_vision("$N将$n切成片放到小烤炉里，$n一会儿就变成了一串香喷喷的烤肉串\n", me, tar);
        tar->move(environment(me));
        destruct(tar);
        return 1;
}