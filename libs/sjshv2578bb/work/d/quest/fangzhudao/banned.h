// 放逐岛不允许的命令及法术
// 本地巫师可以根据需要添加新的命令或法术,
// 比如在banned_cast里加上invocation,banned_action里加上eat,等等。
// 现有的banned清单是为了放逐岛特点的需要，
// 如有需要取消，务请慎重。
// 如发现bug，请及时报告，多谢合作。

string *banned_cast = ({
  "escape",
  "chuqiao",
  "qiankun",
  "jieti",
  "tudun",
  "shuidun",
  "yinshen",
  "sheqi",
  "nophase"
});
string *banned_action = ({
  "practice",
  "xiudao",
  "learn",
  "study",
  "read",
  "bian",
  "accept",
  "fly",
  "surrender",
  "move",
  "recall"
});
