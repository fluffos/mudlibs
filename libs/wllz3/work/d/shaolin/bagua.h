// Room: /d/shaolin/bagua.h
// Design By Robert 蝴蝶君 emial:stcoolman@21cn.com

string* dirs = ({
        "坎", "坤", "离", "乾",
        "艮", "震", "巽", "兑"
        });

int check_dirs(object me, string dir)
{
        int bc, count;
        if (member_array(dir, dirs) != -1)
        {
                bc = me->query_temp("bagua/count");

                switch (dir)
                {
                case "坎":
                        if (bc == 0 || bc == 13 || bc == 17) {
                                me->set_temp("bagua/count",  bc + 1);
                                me->receive_damage("jing",50); }                        
                        else
                                  me->delete_temp("bagua/cunt");
                        break;
                case "坤":
                        me->delete_temp("bagua/count");
                        break;
                case "离":
                        if (bc == 1 || bc == 12 ) {
                                me->set_temp("bagua/count",  bc + 1);
                                me->add("neili", -50); 
                                }
                        else
                                  me->delete_temp("bagua/cunt");
                        break;
                case "乾":
                        if (bc == 3 || bc == 7 || bc == 15) {
                                me->set_temp("bagua/count",  bc + 1);
                                me->receive_damage("qi", 50); }
                        else
                                  me->delete_temp("bagua/cunt");
                        break;
                case "艮":
                        if (bc == 8 ) {
                                me->set_temp("bagua/count",  bc + 1);
                                me->add("combat_exp", -50);
                                me->unconcious(); }
                        else
                                  me->delete_temp("bagua/cunt");
                        break;
                case "震":
                         if (bc == 2 || bc == 4 || bc == 9 ) {
                             me->set_temp("bagua/count",  bc + 1); }
                        else
                             me->delete_temp("bagua/cunt");
                        break;
                case "巽":
                        if (bc == 6 || bc == 11 ) {
                                me->set_temp("bagua/count",  bc + 1);
                                me->receive_damage("qi", 50); }
                        else
                                  me->delete_temp("bagua/cunt");
                        break;
                case "兑":
                        if (bc == 5 || bc == 10 || bc == 14 || bc == 16) {
                                me->set_temp("bagua/count",  bc + 1);
                                me->receive_damage("jing", 50); }
                        else
                                  me->delete_temp("bagua/cunt");
                        break;
                default:
                        me->delete_temp("bagua/count");
                        break;
                }

                if (dir == "坤")
                {
                        me->delete_temp("bagua");
                }
                else
                {
                        count =  me->query_temp("bagua/"+dir);
                        count++;
                        me->set_temp("bagua/"+dir, count);
                        if (count > 13)
                        {
                                me->delete_temp("bagua");
                                me->move(__DIR__"jianyu");
                                return (1);
                        }
                }
        }

        return (0);
}