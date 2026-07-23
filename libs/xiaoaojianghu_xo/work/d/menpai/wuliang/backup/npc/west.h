//西宗弟子应该会的标准动作，每个西宗弟子都#include
//by trill Apr 17 1997

int query_answer( object me )
{
        object ob = this_object();

        if ( (string)me->query( "family/family_name" ) == "无量剑派西宗" )
        {
                switch ( random(3) )
                {
                case 0 :
                        message_vision("$N看着$n说道：你这么有空，想和我谈天？那我就给你讲讲门规吧。\n"
                        "    本派\n"
                        "           首戒欺师灭祖，不敬尊长；  二戒同门操戈，兄弟不和。\n"
                        "           三戒心猿意马，不用心练功；四戒恃强凌弱，擅伤无辜。\n"
                        "           五戒奸淫好色，调戏妇女；  六戒口出妄言，行事不正。\n"
                        "    本派门规，每个弟子都需牢牢记住。\n", ob, me);
                        break;
                case 1 :
                        message_vision("$N对$n摇摇头说道：你要努力练剑，争取早日入主剑湖宫\n"
                        "不要整天聊天闲谈。\n", ob, me);
                        break;
                case 2 :
                        message_vision("$N对$n说道：本派本是天南第一大派，可惜近来人才零落....\n", ob, me);
                        command("sigh");
                        break;
                }
                return 1;
        }
        return 0;
}

int query_ask_answer( object me, string arg )
{
        object ob = this_object();
        
        string target, sth;

        if ( sscanf( arg, "%s about %s", target, sth ) != 2 )
                return 0;
        if ( !id( target ) ) return 0;
        switch( sth )
        {
        case "无量剑派" : case "无量剑" :
                message_vision("$N对$n说到：\n"
                "无量剑派于前朝在无量山上创派，经过数百年的发展壮大，无量剑派曾是\n"
                "天南第一大派，可惜在几十年前，本派内部不和，到如今....唉，实力已\n"
                "大不入以前，好多精妙武功已经失传... \n", ob, me);
                return 1;
                break;
        case "无量剑派西宗" : case "西宗" :
                if ( (string)me->query("family/family_name") == "无量剑派西宗" )
                {
                        message_vision("$N看着$n，长叹一口气，说道：\n"
                        "本宗已数十年未入主剑湖宫了，无量玉壁何时能得一见啊！？。。\n", ob, me);
                        return 1;
                }
                command( "look " + (string)me->query("id") );
                message_vision( "$N对$n说道：你不是本派弟子，打听这作甚？\n", ob, me);
                return 1;
                break;
        case "无量山" :
                message_vision("$N说到：\n"
                "无量山是南诏第一名山，山水清幽，本派的祖师爷当真是能选地方啊。\n", ob, me);
                return 1;
                break;
        default :
                return 0;
        }
}

