// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** smell.c
**
*/

inherit VERB_OB;

mixed direct_smell_obj(object ob) {
    return 1;
}

void do_smell_obj(object ob)
{
    if ( !ob->smell() )
    {
        printf("这闻起来好象是%s.\n", ob->a_short());
    }
}


mixed * query_verb_info()
{
    return ({ ({ "OBJ" }), ({ "sniff" }) });
}
