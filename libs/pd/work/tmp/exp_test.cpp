#include <cstdlib>
#include <iostream>

using namespace std;

int main(void)
{
    int atk_lvl = 0;
    int tob_lvl = 0;
    int exp = 100;
    
    for(atk_lvl = 1; atk_lvl < 110; atk_lvl++)
    {
        cout << "Attacker level: " << atk_lvl << endl;
        tob_lvl = 1;
        while(tob_lvl < atk_lvl)
        {
            exp = 100;
            
            if( atk_lvl <= 5 )
            {
                if( atk_lvl > tob_lvl + 3)
                    exp = (exp * 3 / 4);
                else if( tob_lvl > atk_lvl + 2 )
                    exp = (exp / 2);
                // else, no change.
            }
            else if( atk_lvl <= 10 )
            {
                if( atk_lvl > tob_lvl + 6  )
                    exp = (exp / 3);
                else if( (tob_lvl > atk_lvl + 4) || (atk_lvl > tob_lvl + 4) )
                    exp = (exp * 2 / 3);
                // else, no change
            }
            else if( atk_lvl < 20 )
    	    {
                if( atk_lvl > tob_lvl + 9 )
                    exp = (exp / 4);
                else if( (tob_lvl > atk_lvl + 6) || (atk_lvl > tob_lvl + 6) )
                    exp = (exp / 2);
                // else, no change
            }
            else
            {
                if( atk_lvl > tob_lvl * 1.4 )
                    exp = 0;
                else if( tob_lvl > atk_lvl * 1.2 || atk_lvl > tob_lvl * 1.2 )
                    exp = (exp / 2);
                // else, no change
            }
            
            if( exp == 0 && tob_lvl < atk_lvl )
            {
                tob_lvl++;
                continue;
            }
            
            cout << "  Victim level: " << tob_lvl << ", exp: " << exp << endl;
            tob_lvl++;
        }
        system("PAUSE");
        system("CLS");
    }
    return 1;
}

