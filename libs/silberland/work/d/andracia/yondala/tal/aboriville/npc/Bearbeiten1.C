

	AddCmd(({"stecke", "steck"}), "stecken"); 
   AddExit( "norden", "nach Norden#" + "./room2" );
 //  AddItem( "item" , REFRESH_DESTRUCT);
 }
 command(string str )
 {
   notify_fail( "Was willst Du tun?\n" );
   if( str == "finger in augenhoehle"||str=="finger in augenhoehlen" )
	 	{
	 		if (present (TO, "arasul")) //Wenn Arasul da ist
 				{
 					write("Arasul schreit Dich an: So sicher nicht!\n");
 					say("Arasul schreit "+TPN+" an: So sicher nicht!\n");
 					return 1;//beende die Funktion
 				}
 			else
 			{
 				write("Du steckst Deinen Finger in die Augenhoehle!\n"); //Oder was auch immer da passieren soll
  			say(TPN "Steckt zwei Finger in die Augenhoehle des Totenkopfs!\n"); 
  			//hier passiert dann vermutlich noch was, eien Tuer oeffnet sich oder was auch immer.
  			return 1;
  			}
  		}
  }