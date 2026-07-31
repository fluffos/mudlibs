// 计算经验的函数，在算出正常经验，
// 但计算潜能之前调用。

int cal_exp(int exp, object me)
{
    switch(me->query("family/family_name")) {
// 等级 C
        case "少林派":
        case "峨嵋派":
        case "华山派":
        case "桃花岛":
        case "天龙寺":
        case "武当派":
              return (int)(exp*2/3);
          break;
// 等级 B 的经验倍数是 1，就不列出了。
// 等级 A
        case "明教":
        case "铁掌帮":
        case "大轮寺":
              return (int)(exp*4/3);
          break;
// 等级 A+
        case "星宿派":
        case "神龙岛":
              return (int)(exp*3/2);
          break;
    }
    return exp;
}

