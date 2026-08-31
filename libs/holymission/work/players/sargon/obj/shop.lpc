inherit "room/room";  
object trashcan,spliff; 
#define item spliff()  

void reset(int arg){  
    if(!trashcan) {  
	trashcan=clone_object("/players/whisky/shops/trashcan");  
	transfer(trashcan,this_object()); 
    }  
    ::reset(arg);  

    set_light(1); 
    short_desc = "Spliff Shop";  
    long_desc =  
    ( 
      "You have entered a small building with a small counter in the back\n"+  
      "with some glass jars on it.  You notice that the jars contain some\n"+  
      "strange flowery substances in them.  The smell here is strange yet\n"+  
      "rather sweet.  You can do only one thing here, buy spliffs.\n"); 

    dest_dir= ({
      "/room/plane8","west"
    }); 
    property=({"no_fight","has_fire"}); 
} 

init() { 
    ::init();  

    add_action("buy_spliff","buy");   /* one word commands */ 
} 

buy_spliff(str) {   

    /* Exos 3-11-98, spliffs are bugged.  Temporarily out of stock. */
    write( "Sorry, we are fresh out today!  Check back later!\n" );
    return( 1 );

    /* Sargon when you do this you must check to see if the player has the  
  money to buy a spliff, if not they cannot purchase it. Also you must  
  deduct the amount of each spliff from the player. I will go thorugh all of 
  this with you when we are both on next. haplo 1-5-96 
    */ 
    if((str == "spliff") && (this_player()->query_money()>149)) { 
	transfer(clone_object("/players/sargon/obj/spliff"), this_player()); 
	/* Exos 3-11-98 need to detect money. */
	this_player()->add_money( -150 );
	write("You buy a spliff.\n"); 
	return 1; 
    } 
    else { 
	write("We only sell Spliffs for 150 coins!\n"); 
    } 
    return 1; 
} 
