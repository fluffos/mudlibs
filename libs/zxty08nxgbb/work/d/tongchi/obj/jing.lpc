inherit ITEM;

void create()
{
          set_name( "孤星剑谱",({ "guxing book","book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本记载孤星剑法的书。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name":         "guxing-sword",      //name of the skill
                        "exp_required": 1000 ,        //minimum combat experience required
                        "jing_cost":    20+random(20),// jing cost every time study this
                        "difficulty":   20,           // the base int to learn this skill
                        "min_skill":    200,           // the minimum level you can learn
                        "max_skill":    200            // the maximum level you can learn
                ]) );
        }
}
int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
       message("channel:rumor",HIY"【宝典书籍】"+ "某人：孤星剑谱被"+
        dest->query("name")+"抢到手了！\n"NOR,users());
        return 1;
}


