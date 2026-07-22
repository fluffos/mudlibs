// cracked by vikee 2/09/2002   vikee@263.net
string give_reward(object me) {
  mapping skill=me->query_skills();
  string *skillnames;
  string selected;
  int level, inc=0;

  if (!skill) return "none";

  skillnames=keys(skill);
  if(!sizeof(skillnames)) return "none"; // mon 6/20/99
  selected=skillnames[random(sizeof(skillnames))];

  // mon 3/25/99
  level=skill[selected];
  // xlb 5/15/99
  if (level==0) return "none";
  if(level<70) {
      inc=1;
  } else if(level<140) {
      inc=random(2)==0;
  } else if(level<210) {
      inc=random(4)==0;
  } else {
      inc=random(6)==0;
  }

  if(inc==1) {
    string announce=to_chinese(selected);
    me->set_skill(selected,level+1);
    tell_object(me,"你得到了一级"+announce+"。\n");
    command_function("rumor "+ 
	    "听说"+me->query("name")+"的"+announce+
	    "又有所进境了！");
    return selected;
  }

  return "none";
}
