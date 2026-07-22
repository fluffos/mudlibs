void init()
{
       call_out("destruct", 30, this_object());        
       add_action("do_tu", "tu");
}

int do_tu(string arg)
{
       string me, what;
       mapping fam; 
       object ob;
       int i;

       if (!(fam = this_player()->query("family")) || fam["family_name"] != "星宿派")
       return notify_fail("你又不是星宿弟子，怎能用这种阴险的招数！");

       if( this_player()->is_busy() )   return notify_fail("你正忙着呢！\n");
       i = (this_player()->query_skill("poison")/10)+3;
      
       if( !arg
       ||      sscanf(arg, "%s on %s", me, what)!=2
       ||      !id(me) )
               return notify_fail("命令格式: tu <药> on <武器>。\n");

       ob = present(what, this_player());
       if( !ob )
               return notify_fail("你身上没有" + what + "这样东西。\n");
       if( !ob->query("weapon_prop") )
               return notify_fail("只能涂在武器上。\n");
               
       
       ob->set("poisoned", query("poison"));
       ob->set("poison_number", ob->query("poison_number")+i);

       ob->set_temp("apply/long", ({ob->query("long")+"但看上去"+query("drug_color")+"，好象是被喂了剧毒。\n"}));
       message_vision("$N背过身去，将$n放在"+query("name")+"上慢慢熏烤。\n", this_player(),ob);
       this_player()->start_busy(2);
       add_amount(-1);
       return 1;
}

void destruct(object ob)
{
   message_vision("$N慢慢地燃烧完了。\n",ob);
   ob->add_amount(-1);
   return;
}   