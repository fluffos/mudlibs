int is_knowledge(string sname) {
  if (sname == "qimen-bagua")
    return 0;
  if (sname == "fishing")
    return 0;
  if (SKILL_D(sname)->type() == "knowledge")
    return 1;
  return 0;
}
int is_other(string sname) {
  switch (sname) {
    case "begging":
    case "checking":
    case "stealing":
    case "qimen-bagua":
    case "fishing":
    case "trade":
    case "qimen-baguazhen": return 1;
    default: return 0;
  }
}
int is_normalskill(string sname) {
  switch (sname) {
    case "parry":
    case "dodge":
    case "axe":
    case "whip":
    case "blade":
    case "claw":
    case "club":
    case "cuff":
    case "dagger":
    case "finger":
    case "hammer":
    case "hand":
    case "hook":
    case "leg":
    case "staff":
    case "stick":
    case "strike":
    case "sword":
    case "unarmed":
    case "force":
    case "brush":
    case "throwing": return 1;
    default: return 0;
  }
}
int is_specialskill(string sname) {
  if (SKILL_D(sname)->type() == "knowledge")
    return 0;
  switch (sname) {
    case "parry":
    case "dodge":
    case "axe":
    case "whip":
    case "blade":
    case "claw":
    case "club":
    case "cuff":
    case "dagger":
    case "finger":
    case "hammer":
    case "hand":
    case "hook":
    case "leg":
    case "staff":
    case "stick":
    case "strike":
    case "sword":
    case "unarmed":
    case "force":
    case "begging":
    case "checking":
    case "stealing":
    case "qimen-bagua":
    case "qimen-baguazhen":
    case "brush":
    case "trade":
    case "throwing": return 0;
    default: return 1;
  }
}
