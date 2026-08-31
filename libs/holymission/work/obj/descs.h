// Moonchild 160893 declare types
// Moonchild 210893 recode some crap in here

/*HERP: 93/08/22: reverted recode some crap, it didnt load, see later */

int *conf_prompt();
int query_max_hp();
int query_hp();
int query_max_sp();
int query_sp();
object query_attack(object ob);
string query_pronoun();

string health_desc(int max, int hp) {
    if(!max) max=1;
    switch(hp*100/max) {
        case 0..5: return "at deaths door";
        case 6..15: return "barely alive";
        case 16..25: return "terribly hurt";
        case 26..35: return "in very bad shape";
        case 36..45: return "in bad shape";
        case 46..55: return "very hurt";
        case 56..65: return "feeling rather hurt";
        case 66..75: return "hurt";
        case 76..85: return "somewhat hurt";
        case 86..95: return "slightly hurt";
        case 96..100: return "feeling very well";
        default: return "in a very strange shape";
    }
}

#if 0
string tell_health(object ob) {
    if(!ob) return "";
    return sprintf("%s is %s.\n", capitalize((string)ob->query_pronoun()),
        health_desc((int)ob->query_maxhp(), (int)ob->query_hp()));
}
#else

string tell_health() {
  return sprintf("%s is %s.\n", capitalize(query_pronoun()),
	health_desc(query_max_hp(), query_hp()));
}
#endif

/* Level descriptions for: Mana */
string mana_desc(int max, int sp) {
    if(!max) max=1;
    switch(sp*100/max) {
        case 0..5 : return "in a vegetable state";
        case 6..15 : return "exhausted";
        case 16..25 : return "worn down";
        case 26..35 : return "indisposed";
        case 36..45 : return "in bad shape";
        case 46..55 : return "very degraded";
        case 56..65 : return "rather degraded";
        case 66..75 : return "degraded";
        case 76..85 : return "somewhat degraded";
        case 86..95 : return "slightly degraded";
        case 96..100 : return "in full vigour";
        default: return "in a very strange shape";
    }
}

#if 0
string show_vitals(object ob) {
    if(!ob) return "";
    return sprintf("You are physically %s and mentally %s.\n",
        health_desc((int)ob->query_maxhp(), (int)ob->query_hp()),
	mana_desc((int)ob->query_maxsp(), (int)ob->query_sp()));
}
#else

string show_vitals() {
  return sprintf("You are physically %s and mentally %s.\n",
	health_desc(query_max_hp(), query_hp()),
	mana_desc(query_max_sp(), query_sp()));
}
#endif

string get_prompt_str(int f) {
  string pr,pr2,sep,hlp,aname;
  object a,o,aa;
  int mhp,hp,msp,sp,amhp,ahp,aamhp,aahp,*cp;

#if 1			/* changed to 1. bug when loading: is_npc undeclared */
  o=this_object();
  cp=(int *)o->conf_prompt();
  if(!cp) cp=({ 1,1,1,1,1,1,1,1 });
  mhp=(int)o->query_max_hp();
  hp=(int)o->query_hp();
  msp=(int)o->query_max_sp();
  sp=(int)o->query_sp();
  a=(object)o->query_attack();
#else
  if(is_npc || !(cp=conf_prompt())) cp=({ 1,1,1,1,1,1,1,1 });
  mhp=query_max_hp();
  hp=query_hp();
  msp=query_max_sp();
  sp=query_sp();
  a=query_attack();
#endif
  
  if(a) { 
      ahp=(int)a->query_hp();
      amhp=(int)a->query_max_hp(); 
      aa=(object)a->query_attack();
      aname=(string)a->query_name();
      if(aa) { 
          aahp=(int)aa->query_hp();
          aamhp=(int)aa->query_max_hp(); 
      }
  }
  
  pr=pr2=sep="";
  if(f || ((mhp!=hp || cp[6]) && cp[0]))
	pr=sprintf("HP:%s", health_desc(mhp,hp));
  if(f || ((msp!=sp || cp[6]) && cp[1])) {
      if(pr!="") pr+=cp[4] ? " # " : " ";
      pr+=sprintf("SP:%s", mana_desc(msp,sp));
  }
  if(a && aname && (cp[2] || f)) {
      if(pr!="") pr+=cp[4] ? " # " : " ";
      pr+=sprintf("%s:%s", aname, health_desc(amhp,ahp));
      if(aa && aa!=this_player() && (cp[5] || f)) {
          if(pr!="") {
              sep+=cp[4] ? " # " : " ";
          } 
          pr2+=sprintf("%s:%s", (string)aa->query_name(),
		health_desc(aamhp,aahp));
      }
  }
  if(strlen(pr+sep+pr2)>78) pr=sprintf("%s\n%s", pr, pr2);
	else pr=sprintf("%s%s%s", pr, sep, pr2);
  return pr;
}
