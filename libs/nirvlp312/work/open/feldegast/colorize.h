string colorize(string str) {
  str=implode(explode(str,"BOLD"),BOLD);
  str=implode(explode(str,"BLK"),BLK);
  str=implode(explode(str,"WHT"),WHT);
  str=implode(explode(str,"HIB"),HIB);
  str=implode(explode(str,"HIR"),HIR);
  str=implode(explode(str,"HIG"),HIG);
  str=implode(explode(str,"HIC"),HIC);
  str=implode(explode(str,"HIY"),HIY);
  str=implode(explode(str,"HIM"),HIM);
  str=implode(explode(str,"HIW"),HIW);

  str=implode(explode(str,"BLU"),BLU);
  str=implode(explode(str,"RED"),RED);
  str=implode(explode(str,"GRN"),GRN);
  str=implode(explode(str,"CYN"),CYN);
  str=implode(explode(str,"YEL"),YEL);
  str=implode(explode(str,"MAG"),MAG);
  str=implode(explode(str,"NORM"),NORM);
  return str;
}
