// story:shenzhao 凝血神爪

#include <ansi.h>

int give_gift();


mixed *story = ({
        "大旱，民饥。",
        "流民如潮。",
        "冬梅架起大锅，在路边舍粥。",
        "天色渐晚，眼见锅中粥将罄。",
        "只见路边摇摇晃晃走过来一人。",
        "冬梅勺起最后一碗粥，就道：“嗟...”",
        "猛然间发现那人头戴纶巾，虽然破旧，却是整整齐齐。",
        "冬梅心中暗道：可不要是一个书呆子，让我这最后一碗粥送不出去。",
        "想到这里，便将那个嗟字暗自吞下肚子，客气道：“这位先生，可能赏脸饮碗粥。”",
        "那人看了看冬梅，感激道：“一路上我为了这骨气忍饥挨饿，想不到终于遇到这位贤人。”",
        "冬梅暗道：果然是个书呆子，还好，还好。",
        "...",
        "那人喝完粥，掏出一本破破烂烂的书，递给冬梅。",
        "冬梅：...",
        "那人道：“承蒙赐粥，无以相赠，这本孟子送送给先生吧。”",
        "......",
        "眼见那人蹒跚而去，冬梅翻了翻手中的书，苦笑不止。",
        "“我大字不识一个，要这破书作甚？”想到这里，冬梅把书随手一丢，收起锅走路。",
        (: give_gift :),

});

void create()
{
        seteuid(getuid());
}



mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
         
        int i;
        object env,ob;
        object *players;
                object gob;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                                
                }
        if(!ob) return 1;
        gob = new(__DIR__"obj/mengzi");
        gob->move(ob, 1);
 if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "捡到了神书《孟子》。");
}
        STORY_D->remove_story("new11");
      }
        return 1;
}