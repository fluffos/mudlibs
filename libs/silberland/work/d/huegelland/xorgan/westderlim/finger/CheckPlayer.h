mapping player = ([ ]);


void reset()
{
   ::reset();
   player = ([ ]);
}


int CheckPlayer( string name );
void SetPlayer( string name, int val );
int ResetPlayer( string name );

int CheckPlayer( string name )
{
   return player[name];         // wenn nicht im mapping: 0, sonst: Wert
}

int SetPlayer( string name, int val )
{
   player[name] = val;            // Wert auf 1 setzen
}

void ResetPlayer( string name )
{
   player[name] = 0;            // Wert auf 0 setzen
}
