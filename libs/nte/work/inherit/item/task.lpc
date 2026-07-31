inherit ITEM;

varargs int move(mixed dest, int raw)
{
        object ob;

        if (::move(dest, raw)) 
        {
                ob = environment();
                if (objectp(ob) && ! this_object()->query("geter") && userp(ob)) 
                        this_object()->set("geter", ob->name(1));
                return 1;
        }    
}

