
// By adx @ CuteRabbit 20:22 99-5-9
int do_gobj()
{
        object ob = this_player() ;
        message_vision("\n只见$N骑两腿一夹，马向前急驰而去。\n" , ob);
        ob->move("/d/city2/majiu");
        this_object()->move("/d/city2/majiu");
        message_vision("\n只见$N骑着马急奔而来。\n", ob);
        message_vision("\n奔到近前，$N身行跃下马来，姿态十分优美。\n",ob);
        delete("rider");
        ob->delete_temp("onhorse");
        command("follow none");
        return 1 ;
}

