// ultra.h 宗师评价玩家的公共代码
// Copyright (C) 2024 by Lu Dexiang

/**
 * @brief 计算指定技能等级
 * @param object me 玩家对象
 * @param string skill 技能名称
 * @return int 技能等级
 */
 int calc_level(object me, string skill);

 /**
  * @brief 检查是否达到大宗师条件
  * @param object me 玩家对象
  * @return void
  */
 void check_ultra(object me);
 
 // 评价等级映射表
 private mapping opinions_rank = ([
     600 : "武道宗师",
     550 : "登峰造极",
     500 : "超凡脱俗",
     450 : "臻至化境",
     400 : "炉火纯青",
     350 : "已有大成",
     300 : "非同凡响",
     250 : "出类拔萃",
     200 : "身手不凡",
     150 : "已有小成",
 ]);
 
 
 /**
  * @brief 获取下一个评价等级门槛
  */
 private int get_next_threshold(string current_rank, int *level_thresholds)
 {
     if (!stringp(current_rank)) 
         return level_thresholds[0];
         
     foreach (int threshold in level_thresholds[0..<2]) {
         if (opinions_rank[threshold] == current_rank) {
             return level_thresholds[member_array(threshold, level_thresholds) + 1];
         }
     }
     
     return level_thresholds[0];
 }
 
 /**
  * @brief 计算最高评价等级
  */
 private int calc_highest_level(object me, int next_threshold)
 {
     int highest_level = -1;
     
     foreach (string skill in my_opinions) {
         int current_level = calc_level(me, skill);
         if (current_level >= next_threshold && current_level > highest_level) {
             highest_level = current_level;
         }
     }
     
     return highest_level;
 }
 
 /**
  * @brief 显示未达标信息
  */
 private void show_no_progress_message(object me, int next_threshold, int min_threshold)
 {
     string msg;
     
     if (next_threshold == min_threshold) {
         msg = sprintf("\n$N淡淡一笑，对$n道：「你的%s不行啊！好好努力吧！」\n", 
             OPINION_TYPE);
     } else {
         msg = sprintf("\n$N对$n摇摇头道：「不怎么样，我发现你的%s比上次没什么太大的进步。」\n",
             OPINION_TYPE);
     }
     
     message_vision(msg, this_object(), me);
 }
 
 /**
  * @brief 更新评价等级
  */
 private string update_rank(object me, int highest_level, int *level_thresholds)
 {
     int rank_index;
     string new_rank;
     
     // 从高到低查找符合条件的等级
     for (int i = sizeof(level_thresholds) - 1; i >= 0; i--) {
         if (highest_level >= level_thresholds[i]) {
             rank_index = i;
             break;
         }
     }
     
     new_rank = opinions_rank[level_thresholds[rank_index]];
     me->set("opinion/" + MY_OPINION, new_rank);
     
     return new_rank;
 }
 
 /**
  * @brief 显示评价结果
  */
 private void show_result_message(object me, string new_rank, int *level_thresholds)
 {
     string msg;
     
     if (new_rank == opinions_rank[level_thresholds[<1]]) {
         msg = sprintf("\n$N对$n笑道：恭喜！%s的%s已然到了宗师境界！武道无穷，阁下自重！\n",
             RANK_D->query_respect(me), OPINION_TYPE);
         message_vision(msg, this_object(), me);
         me->set("opinion/" MY_OPINION, new_rank);
         me->set("opinions/master", 1);
         check_ultra(me);
         return;
     }
     
     msg = sprintf("\n$N沉思片刻，对$n道：就目前来看，你的%s已经可以算得上是%s了。\n",
         OPINION_TYPE, new_rank);
    me->set("opinion/" MY_OPINION, new_rank);
     message_vision(msg, this_object(), me);
 }
 
 /**
  * @brief 检查是否达到大宗师条件
  */
 void check_ultra(object me)
 {
     object *ultra;
 
     // 检查四项武功是否都达到宗师级别
     if (me->query("opinion/unarmed") != "武道宗师" ||
         me->query("opinion/weapon") != "武道宗师"  ||
         me->query("opinion/force") != "武道宗师"   ||
         me->query("opinion/dodge") != "武道宗师") {
         return;
     }
 
     // 检查经脉是否打通
     // 检查四条经脉是否全部打通
     if (!MERIDIAN_D->is_meridian_completed(me, "冲脉") ||
         !MERIDIAN_D->is_meridian_completed(me, "带脉") ||
         !MERIDIAN_D->is_meridian_completed(me, "阳跷脉") ||
         !MERIDIAN_D->is_meridian_completed(me, "阴跷脉")) {
         return;
     }

     //如果已经大宗师则返回
     if (me->query("opinion/ultra"))
     {
        tell_object(me,"你已经是大宗师了！\n");
        return;
     }

     // 设置大宗师标记
     me->set("opinion/ultra", 1);

     // 记录成就宗师时的年龄
     me->set("opinion/ultra_age", me->query("age"));

     // 获取其他宗师NPC列表
     ultra = NPC_D->query_ultra_master();
     ultra -= ({ this_object() });
     
     // 发送消息
     command("chat 叹道：江山代有才人出，武林几度新人换旧人。今日" + me->query("name") + 
         "突破武道桎梏，跻身大宗师之列，令老朽深感欣慰。");
     
     // 其他宗师祝贺
     ultra->do_congration(me);
     
     // 发送系统消息
     CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
         "听说" + me->query("name") + "成为武学大宗师。");
    me->force_me("chat 哈哈哈!哈哈哈哈哈!");
     CHANNEL_D->do_channel(find_object(MASTER_OB), "rumor",
        me->query("name") + "骤然大笑起来，笑声回荡在广阔的天地上，他忽然觉得自己是那么的了不得！区区数十载，竟能成就宗师！什么阴谋，什么血影门，突然变得像浮蚁一般不值一提了。他的胸襟然开阔起来，好似在武道前进的路上再也没有什么阻碍了。");

    // 奖励先天真炁
    me->add("tianfu_point", 10);
 }

  /**
  * @brief 检查并更新玩家的武功评价
  * @author Lu Dexiang
  * @param object me 待评价的玩家对象
  * @return void
  */
  void check_opinion(object me)
  {
      string current_rank, new_rank;
      int *level_thresholds;
      int next_threshold, highest_level;
      
      // 参数检查
      if (!objectp(me)) return;
      
      // 环境检查
      if (environment(me) != environment()) {
          command("sigh");
          return;
      }
  
      // 清理临时数据
      delete_temp("opinion");
      
      // 获取评价数据
      current_rank = me->query("opinion/" + MY_OPINION);
      level_thresholds = sort_array(keys(opinions_rank), 1);
      
      // 获取下一个评价等级门槛
      next_threshold = get_next_threshold(current_rank, level_thresholds);
      
      // 计算最高评价等级
      highest_level = calc_highest_level(me, next_threshold);
      
      // 处理未达标情况
      if (highest_level == -1) {
          show_no_progress_message(me, next_threshold, level_thresholds[0]);
          return;
      }
  
      // 更新评价等级
      new_rank = update_rank(me, highest_level, level_thresholds);
      
      // 显示评价结果
      show_result_message(me, new_rank, level_thresholds);
  }