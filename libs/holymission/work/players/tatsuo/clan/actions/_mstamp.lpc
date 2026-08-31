#define TP this_player() 
#define cap capitalize

 int _mstamp(string arg){

 object target;
if(!arg){
say(TP->query_name()+" slaps a moron sticker on "+
    TP->query_possessive()+ " forehead.\n");

write("You slap a moron sticker on your own forehead.\n");
return 1;
}
else

target = present(arg,environment(TP) );
 if(!target) return printf(capitalize(arg) + " is not here.\n"),1;

tell_object(target, TP->query_name()+
      " slaps an official 'I am a Moron!' "+
      "sticker on your forehead!\n");

write("You slap a moron sticker on "+cap(arg)+
      "'s forehead.\n");

say(TP->query_name()+" slaps an official "+
      "'I am a Moron!' sticker on "+ target->query_name()+"'s forehead.\n", target);
return 1;
}








