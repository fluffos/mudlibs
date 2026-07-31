int init()
{
    object me, lp;
    string bh;
        
        me  = this_player();               
        lp = new("/clone/misc/lingpai");        
        bh = "《武林浩荡》第一城";                
        lp->create(bh);
        
        if( lp->query("no_use") ) { 
               destruct(lp); 
               me->move("/d/city/guangchang");
               write("《武林浩荡》第一城出现了BUG，请马上联系方舟来解决。\n"); 
               return 1;
        }        
        
        if( lp->query("tybanghui") != me->query("banghui") && !wizardp(me) && userp(me) ) {
               destruct(lp); 
               me->move("/d/city/guangchang");
               write("你以为《武林浩荡》第一城，是你随便来的地方吗？\n");
               return 1;
        }
                        
        add_action("do_nocmds", "home");
        add_action("do_nocmds", "conjure");
        add_action("do_nocmds", "qigong");        
}
int do_nocmds(string arg)
{
        write("对不起，《武林浩荡》第一城禁止使用该指令！\n");
        return 1;
}
