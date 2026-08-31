#include <std.h>
#include <waterworld.h>

object payout;
void pearl_reciever(string recieved,int profit, object mon)
{
           if(interact("gives",recieved)) {
               if(interact("you",recieved)) {
                   if(interact("pearl",recieved)) {
                         if(!present("pearl", mon)) return;
                         if(interact("white",recieved)){
                            message("info","You have given me a White Pearl. Your prize is 10 gold.\n",this_player());
                              profit=10;
                                       }
                              else if(interact("black",recieved)){
                            message("info","You have given me a Black Pearl. Your prize is 50 gold.\n",this_player());
                              profit=50;
                                    }
                              else if(interact("blue",recieved)){
                            message("info","You have given me a Blue Pearl. Your prize is 1000 gold.\n",this_player());
                             profit=1000;
                                      }
                              else if(interact("PURPLE",recieved)){
                            message("info","You have given me a magnificent Purple Pearl. Your prize is 20000 gold.\n",this_player());
                                  profit=20000;
                                        }
                              else if(interact("ROSE",recieved)){
                            message("info","What a fine speciman you have found!! I'll give you 100,000 gold for it.\n",this_player());
                                 profit=100000;
                                        }
                              else if(interact("STAR",recieved)){
                            message("info","Oh by my crab ancestors!! That's a STAR pearl!! I'll give you 250,000 gold for it.\n",this_player());
                                 profit=250000;
                                        }
                              else if(interact("BLOOD",recieved)){
                            message("info","By all my crab ancestors....I never thought I would live to see the day that I would hold the legendary BLOOD pearl in my claws.... You deserve this one. Your prize is 500,000 gold!!!\n",this_player());
                                  profit=500000;
                                          }
                        } else {
                        message("info","I only give rewards for pearls. I'll take your gift anyway though, after all I AM a hermit crab.\n",this_player());
			}
                   }
             }
              payout=new("/std/obj/coins");
               payout->set_money("gold",profit);
              payout->move(this_player());
}
