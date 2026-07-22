// magic_seal.c

inherit ITEM;

void create()
{
    set_name("符咒", ({"magic seal","seal"}) );
    set_weight(5);
    set("long",
        "这是一张画好的符咒，可以将它贴(attach)在某人(或某物)身上。\n");
    set("unit", "张");
    set("temp_value",10);
}

int unequip()
{
    set("equipped", 0);
    return 1;
}

void init()
{
    if (environment()==this_player())
        add_action("do_attach", "attach");
}

int do_attach(string arg)
{
    string sheet, dest,name;
    object ob,zombie,*inv;
    int i;
    if (query("is_equipped"))
        return notify_fail("这张符咒已经没有用了！\n");

    if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
        return notify_fail("指令格式：attach <符咒> to <目标>\n");
    
    if( !id(sheet) ) return 0;
    ob = present(dest, this_player());
    if( !ob ) ob = present(dest, environment(this_player()));
    if( !ob ) return notify_fail("你要对什麽东西使用这张符咒？\n");
    if (!ob->is_corpse()) return notify_fail("你只能对尸体使用这张符咒！\n");
    if (!ob->is_character() ) return notify_fail("这具尸体太腐烂了，不能使用符咒。\n");
    if( (int)this_player()->query("jingli") < 200 ) return notify_fail("你的精力不够了！\n");

    message_vision("$N拿出一张" + name() + "往$n的头上一贴。\n", this_player(), ob);
    message_vision("\n\n$N对著地上的$n喃喃地念了几句咒语，$n抽搐了几下竟站了起来！\n", this_player(), ob);
    this_player()->add("jingli",-200);
    zombie=new("/clone/npc/zombie");
    name=ob->query("name");
    name=replace_string(name,"的尸体","");
    zombie->set("victim_name",name);
    move(zombie);
    set("is_equipped", 1);
    zombie->animate(this_player(), query("temp_value"));
    inv=all_inventory(ob);
    for (i=0;i<sizeof(inv);i++){
       inv[i]->move(zombie);
       inv[i]->wear();
       inv[i]->wield();
    }
    zombie->move(environment(ob));
    destruct(ob);
    return 1;
}
