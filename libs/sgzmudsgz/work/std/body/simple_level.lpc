// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

 // Yaynu@Lima Bean 950923


void save_me();


private int level = 0;
nomask int query_level(){ return level; }

nomask void set_level(int to){
 if(!check_previous_privilege(1)){
   //error("You can not modify that.");
   error("你无权修改它");
  }
  level = to;
  save_me();  
}
