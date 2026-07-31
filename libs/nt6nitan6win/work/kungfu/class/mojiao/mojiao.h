// mojiao.h

int permit_recruit(object ob)
{
        object me;

        me = this_object();

        if( query("detach/魔教", ob) || 
            query("betrayer/times", ob) )
        {
                message_vision("$N大怒道：我魔教岂能由你要来便来，要走便走？\n",me);
                return 0;
        }

        return 1;
}
