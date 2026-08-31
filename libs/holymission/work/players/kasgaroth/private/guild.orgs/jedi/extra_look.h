extra_look() {
  string m;
  m = CAP(TPPR)+" is a member of the famous Jedi guild.\n";
  
  switch (TP->query_al_string()) {
  case "demonic": 
         m+="You sense that "+TPPR+" is one with the Dark Side of the Force";
         break;
  case "evil":
         m+=CAP(TPPR)+" is a disciple of the Dark Side of the Force" ;
         break;
  case "nasty":
         m+=CAP(TPPR)+" is beginning to turn toward the Dark Side of the Force";
         break;
  case "neutral":
         m+="You sense balance and oneness with the Force in "+TPOB;
         break;
  case "nice":
         m+=CAP(TPPR)+" adheres to the Code of the Light Side of the Force";
         break;
  case "good":
         m+="You have a sense of goodness and great Force about "+TPOB;
         break;
  case "saintly":
      m+=CAP(TPPR)+" emanates goodness and the power of the Light Side of the Force";
      break;
  default : ;
  }
  if(preparing) m+=".\n"+CAP(TPPO)+" hands are glowing brightly"; 
  if(parrying) m+=".\n"+CAP(TPPR)+" is parrying";
  return m;
}
