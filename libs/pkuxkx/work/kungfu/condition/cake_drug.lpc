// cake_drug.c

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration > 7 )
                tell_object(me, "你觉得腹中一阵不舒服，好像吃了什么变质的食物。\n");
        else if( duration > 4 ) {
                tell_object(me, "你只觉得心头一阵烦恶，忍不住「稀里哗啦」地吐了起来。\n");
                message("vision", me->name() + "脸色变得煞白，突然「稀里哗啦」地吐了起来。\n", environment(me), me);
                me->add("qi", - me->query("qi") / 4);
        }
        else if( duration > 1 ) {
                tell_object(me, "你忽然听得腹内「咕噜噜」一阵巨响，只想找个地方解决解决，但放眼望去\n" +
                        "却没有可以做这种事的地方，只得咬着牙拼命忍着。\n");
                message("vision", me->name() + "脸色一阵红一阵白，似乎正忍受着极大的痛苦，是生病了吧？\n", environment(me), me);
                me->add("jing", - me->query("jing") / 4);
        }
        else {
                tell_object(me, "你与巨大的痛苦作着不屈不挠的斗争，虽然付出了一定的代价，但最终获得\n" +
                        "了胜利！你的肚子不疼了！你不禁露出了胜利的微笑。\n");
                message("vision", me->name() + "的脸色看起来好多了，病魔终于退走了。\n", environment(me), me);
        }
        
        me->apply_condition("cake_drug", duration - 1);
        if( duration == 1 ) return 0;
        return 1;
}
